#include <algorithm>
#include "systems/rendering.hpp"
#include <SDL.h>
#include "core/logging.hpp"

namespace systems{

RenderSystem::RenderSystem(core::Config *pconfig):pwindow(nullptr), prender(nullptr), pconfig(pconfig){
    LOG(INFO) << "Initializing RenderSystem";
    pwindow = new sdlwrap::Window("Engine", 0, 0, pconfig->res_x, pconfig->res_y, 0);
    prender = new sdlwrap::Render(pwindow, -1,
            SDL_RENDERER_ACCELERATED);
}
RenderSystem::~RenderSystem(){
    LOG(INFO) << "Destroying RenderSystem";
    if (pwindow){
        delete pwindow;
    }
    if (prender){
        delete prender;
    }
}
struct RenderInfo{
    RenderInfo(components::Spacial *pspacial,
               components::RenderData *pdata,
               components::RenderTexture *ptexture):
        pspacial(pspacial), pdata(pdata), ptexture(ptexture){}

    components::Spacial *pspacial;
    components::RenderData *pdata;
    components::RenderTexture *ptexture;
};

bool renderinfo_check_layer(const RenderInfo &i1, const RenderInfo &i2){
    return (i1.pdata->layer < i2.pdata->layer);
}

//Note: dt should be the time since the last logic update!!
void RenderSystem::update(entityx::EntityManager &es,
                          entityx::EventManager &events,
                          entityx::TimeDelta dt){
    assert(prender != nullptr);
    entityx::ComponentHandle<components::RenderCamera> camera;
    entityx::ComponentHandle<components::Spacial> camera_spacial;
    for (entityx::Entity entity :es.entities_with_components(camera, camera_spacial)){
        (void) entity;
    }

    std::vector<RenderInfo> render_targets;
    entityx::ComponentHandle<components::RenderData> rdata;
    for (entityx::Entity entity : es.entities_with_components(rdata)){
        // Pretend there are checks to see if it makes sense to render the object here
        auto texture = entity.component<components::RenderTexture>();
        auto spacial = entity.component<components::Spacial>();
        if ( texture && spacial) {
            render_targets.emplace_back(spacial.get(), rdata.get(), texture.get());
        }
    }
    // Sort targets by render layer:
    std::sort(render_targets.begin(), render_targets.end(), renderinfo_check_layer);
    //TODO: Don't ignore return value
    (void)prender->RenderClear();

    for (auto it=render_targets.begin(); it!=render_targets.end(); ++it){
        auto pspacial = it->pspacial;
        auto ptexture = it->ptexture;
        components::Spacial *prender_spacial(nullptr);
        if (camera_spacial){
            prender_spacial = &calculate_spacial((camera_spacial.get()), pspacial);
        }else{
            prender_spacial = pspacial;
        }
        draw_object_interpolated(*ptexture, *prender_spacial, dt);
        delete prender_spacial;
    }

    //TODO: Don't ignore return value
    (void)prender->RenderPresent();
}
void RenderSystem::draw_object(components::RenderTexture &texture,
                               components::Spacial &spacial){
    auto pdst = sdlwrap::Rectangle(spacial.pos_x,
                                       spacial.pos_y,
                                       spacial.size_x,
                                       spacial.size_y);

    //TODO: Don't ignore return value
    (void)prender->RenderCopy(texture.get_texture().get(), nullptr, &pdst);
}

void RenderSystem::draw_object_interpolated(components::RenderTexture &texture,
                               components::Spacial &spacial, float dt){

    auto pdst = sdlwrap::Rectangle(spacial.pos_x + (spacial.vel_x * dt),
                                       spacial.pos_y + (spacial.vel_y * dt),
                                       spacial.size_x,
                                       spacial.size_y);

    //TODO: Don't ignore return value
    (void)prender->RenderCopy(texture.get_texture().get(), nullptr, &pdst);
}

std::shared_ptr<sdlwrap::Texture> RenderSystem::load_texture(std::string path){
    auto find_result = textures.find(path);
    if (find_result != textures.end()){
        LOG(INFO) << "texture " << path << " already loaded";
        return find_result->second;
    }
    LOG(INFO) << "creating surface " << path;
    auto surface = sdlwrap::Surface(path);
    LOG(INFO) << "creating texture from surface";
    auto ptexture = std::make_shared<sdlwrap::Texture>(prender, &surface);
    textures.insert({path, ptexture});
    return ptexture;
}

components::Spacial &RenderSystem::calculate_spacial(
                                    const components::Spacial *pcamera,
                                    const components::Spacial *ptarget)
{
    assert(ptarget != nullptr);
    components::Spacial *presult = nullptr;
    if (pcamera == nullptr){
        presult = new auto(*pcamera);
    }else{
        presult = new auto(*ptarget - *pcamera);
        int win_w, win_h;
        pwindow->GetSize(&win_w, &win_h);
        presult->pos_x += win_w / 4;
        presult->pos_y += win_h / 4;
    }
    return *presult;
}

void CameraSystem::update(entityx::EntityManager &es, entityx::EventManager &events, entityx::TimeDelta dt){
    entityx::ComponentHandle<components::RenderCamera>camera;
    entityx::ComponentHandle<components::Spacial>camera_spacial;
    for (entityx::Entity entity :es.entities_with_components(camera, camera_spacial)){
        (void) entity;
    }
    if (camera && camera_spacial){
        entityx::ComponentHandle<components::RenderCameraTarget>target;
        entityx::ComponentHandle<components::Spacial>target_spacial;
        for (entityx::Entity entity :es.entities_with_components(target, target_spacial)){
            (void) entity;
        }
        if (target && target_spacial){
            auto diff_x = camera_spacial->pos_x - target_spacial->pos_x;
            if (( diff_x > 100 ) || ( diff_x < -100 )){
                camera_spacial->vel_x = -diff_x / 2;
            }else{
                camera_spacial->vel_x = 0;
            }
            auto diff_y = camera_spacial->pos_y - target_spacial->pos_y;
            if (( diff_y > 100 ) || ( diff_y < -100 )){
                camera_spacial->vel_y = -diff_y / 2;
            }else{
                camera_spacial->vel_y = 0;
            }
        }
    }
}
}


