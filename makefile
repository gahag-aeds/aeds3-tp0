SrcDir = src
LibDir = $(SrcDir)/libaeds


Lib-CompilationUnits = $(shell find $(LibDir) -name '*.c')

Mat-OutputFile = matriz
Mat-CompilationUnits = $(Lib-CompilationUnits) $(SrcDir)/main-mat.c

Tree-OutputFile = arvore
Tree-CompilationUnits = $(Lib-CompilationUnits) $(SrcDir)/main-mat.c


Build    = gcc
Standard = c99 -pedantic
Warnings = -Wall -Wextra -Werror
Optimize = -O2 -flto

BuildFlags  = $(Warnings)       \
              -std=$(Standard)  \
              $(Optimize)       \
              -I $(SrcDir)      \
              -o $(1)

ReleaseFlags = -DNDEBUG -s



build-mat: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Mat-OutputFile)) $(Mat-CompilationUnits)

build-tree: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Tree-OutputFile)) $(Tree-CompilationUnits)


release-mat: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Mat-OutputFile)) $(ReleaseFlags) $(Mat-CompilationUnits)

release-tree: $(SrcDir)
	@$(Build) $(call BuildFlags,$(Tree-OutputFile)) $(ReleaseFlags) $(Tree-CompilationUnits)


clean:
	rm $(Mat-OutputFile)
	rm $(Tree-OutputFile)
