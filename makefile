SrcDir = src
LibDir = $(SrcDir)/lib*


Lib-CompilationUnits = $(shell find $(LibDir) -name '*.c')

Mat-OutputFile = matriz
Mat-CompilationUnits = $(Lib-CompilationUnits) $(SrcDir)/main-mat.c

Tree-OutputFile = arvore
Tree-CompilationUnits = $(Lib-CompilationUnits) $(SrcDir)/main-tree.c


Build    = gcc
Standard = c99 -pedantic
Libs     = -lm
Warnings = -Wall -Wextra #-Werror
Optimize = -O2 -flto

BuildFlags  = $(Warnings)       \
              -std=$(Standard)  \
							$(Libs)						\
              $(Optimize)       \
              -I $(SrcDir)      \
              -o $(1)

DebugFlags = -g

ReleaseFlags = -DNDEBUG -s



build-mat: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Mat-OutputFile)) $(DebugFlags) $(Mat-CompilationUnits)

build-tree: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Tree-OutputFile)) $(DebugFlags) $(Tree-CompilationUnits)


release-mat: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Mat-OutputFile)) $(ReleaseFlags) $(Mat-CompilationUnits)

release-tree: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Tree-OutputFile)) $(ReleaseFlags) $(Tree-CompilationUnits)


clean:
	rm $(Mat-OutputFile)
	rm $(Tree-OutputFile)
