# Initialize the environment
env = Environment()

#Configure environment
env.Append(CCFLAGS='-m32')
env.Append(CPPFLAGS='-m32')
env.Append(LINKFLAGS='-m32')

# Export Environment to SConscript files
Export('env')

# Run the lower level build files
SConscript('src/SConscript', variant_dir='build')

