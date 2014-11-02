# Set up scons options
AddOption(
    '--release',
    action='store_true',
    help='Perform a release build',
    default=False)

# Initialize the environment
env = Environment()

#Configure environment
#env.Append(CCFLAGS='-m32')
#env.Append(CPPFLAGS='-m32')
#env.Append(LINKFLAGS='-m32')

if GetOption('release'):
    # Use the release build directory
    variant_dir = 'build/release'
else:
    # Use the debug build directory
    variant_dir = 'build/debug'
    # Add debug flags to shared compiler flags
    env.Append(CCFLAGS='-DDEBUG')
    env.Append(CCFLAGS='-Og')
    env.Append(CCFLAGS='-g')

#Set general purpose environment variables
env.Append(CPPPATH=['#src/include'])
env.Append(CPATH=['#src/include'])
env.Append(CXXFLAGS='-std=c++11')

# Run the lower level build files
SConscript('src/SConscript',
    variant_dir=variant_dir,
    duplicate=0,
    exports="env")

