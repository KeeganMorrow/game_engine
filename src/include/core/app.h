namespace core {
    class intApp {
    public:
        virtual ~intApp();
        //TODO: Do I need to block the copy constructor?

        int run(int argc, char* argv[]);
    private:
        virtual void do_run(int argc, char* argv[]) = 0;
    };
}