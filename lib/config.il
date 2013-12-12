Compiled Ruleset @602 
Compiled Rule 
	--atommatch:
		spec           [2, 2]
	--memmatch:
		spec           [1, 1]
		jump           [L260, [0], [], []]
	--guard:L260:
		spec           [1, 1]
		jump           [L253, [0], [], []]
	--body:L253:
		spec           [1, 6]
		commit         ["_init", 0]
		newmem      [1, 0, 0]
		loadruleset    [1, @601]
		newatom     [2, 1, 'config'_1]
		newatom     [3, 1, 'module'_1]
		alloclink   [4, 2, 0]
		alloclink   [5, 3, 0]
		unifylinks     [4, 5, 1]
		enqueueatom    [3]
		enqueueatom    [2]
		proceed        []


Compiled Ruleset @601      
Compiled Rule 
	--atommatch:
		spec           [2, 3]
	--memmatch:
		spec           [1, 3]
		findatom    [1, 0, 'config'.'version'_1]
		commit         ["_Rcon", 0]
		dequeueatom    [1]
		removeatom     [1, 0, 'config'.'version'_1]
		newatom     [2, 0, "2.2.2"_1]
		relink         [2, 0, 1, 0, 0]
		freeatom       [1]
		proceed        []

Compiled Rule 
	--atommatch:
		spec           [2, 3]
	--memmatch:
		spec           [1, 3]
		findatom    [1, 0, 'config'.'prefix'_1]
		commit         ["_Rcon", 0]
		dequeueatom    [1]
		removeatom     [1, 0, 'config'.'prefix'_1]
		newatom     [2, 0, "/usr/local"_1]
		relink         [2, 0, 1, 0, 0]
		freeatom       [1]
		proceed        []

Compiled Rule 
	--atommatch:
		spec           [2, 3]
	--memmatch:
		spec           [1, 3]
		findatom    [1, 0, 'config'.'mandir'_1]
		commit         ["_Rcon", 0]
		dequeueatom    [1]
		removeatom     [1, 0, 'config'.'mandir'_1]
		newatom     [2, 0, ""_1]
		relink         [2, 0, 1, 0, 0]
		freeatom       [1]
		proceed        []

Compiled Rule 
	--atommatch:
		spec           [2, 3]
	--memmatch:
		spec           [1, 3]
		findatom    [1, 0, 'config'.'sysdatadir'_1]
		commit         ["_Rcon", 0]
		dequeueatom    [1]
		removeatom     [1, 0, 'config'.'sysdatadir'_1]
		newatom     [2, 0, "/usr/local/share/slim"_1]
		relink         [2, 0, 1, 0, 0]
		freeatom       [1]
		proceed        []

Compiled Rule 
	--atommatch:
		spec           [2, 3]
	--memmatch:
		spec           [1, 3]
		findatom    [1, 0, 'config'.'syslibdir'_1]
		commit         ["_Rcon", 0]
		dequeueatom    [1]
		removeatom     [1, 0, 'config'.'syslibdir'_1]
		newatom     [2, 0, "/usr/local/share/slim/lib"_1]
		relink         [2, 0, 1, 0, 0]
		freeatom       [1]
		proceed        []

Compiled Rule 
	--atommatch:
		spec           [2, 3]
	--memmatch:
		spec           [1, 3]
		findatom    [1, 0, 'config'.'sysextdir'_1]
		commit         ["_Rcon", 0]
		dequeueatom    [1]
		removeatom     [1, 0, 'config'.'sysextdir'_1]
		newatom     [2, 0, "/usr/local/share/slim/ext"_1]
		relink         [2, 0, 1, 0, 0]
		freeatom       [1]
		proceed        []


Module
'config' {@601}
Inline
