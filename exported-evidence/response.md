Question, does ida mcp have tools to automatically detect and export either just the provided developer code plus static included third party library code or export just the crt/msvc etc ranges? We seem to occasionally discover some of this items are actually not developer code and I was wondering if there was an easier way to automatically find this info and export it
Short answer: partially, but not perfectly automatically.

IDA can identify some non-developer code, especially CRT/MSVC/library routines, when FLIRT/Lumina/signatures match. Through IDA MCP, we can usually query/export those known ranges with IDA Python, for example functions marked as library/runtime, named CRT helpers, imports/thunks, or recognized third-party symbols.

The catch: IDA MCP does not magically know “developer code vs static third-party vs CRT” for every range. It can expose what IDA has recognized plus whatever heuristics/scripts we add.

Good automated/export candidates:

FUNC_LIB / FLIRT-recognized library functions.
Import thunks and external stubs.
MSVC CRT helpers with recognizable names/patterns.
RTTI/EH/compiler-generated ranges.
Known third-party libraries if IDA signatures match, or if we build custom signatures.
Ranges matching known source/library fingerprints, strings, tables, constants, or function hashes.
Hard cases:

Static third-party code compiled without symbols and not matched by FLIRT.
Template/STL/Dinkumware code interleaved with app code.
Compiler-generated helpers inside developer-owned functions.
Small generic helpers that look like app helpers until xrefs/decompilation prove otherwise.
The practical path would be to add an export script using IDA MCP/IDA Python that produces something like:

range | function | classification | basis
0x... | _memmove | CRT/MSVC | FLIRT/FUNC_LIB/name
0x... | png_... | third_party_lodepng | signature/string/hash
0x... | sub_... | likely_developer | no lib marker, project xrefs
Then agents could treat that as a strong lead, not absolute truth. We can also maintain an ignored/runtime ledger from the export and improve it over time. This would probably reduce repeated rediscovery of CRT/MSVC/static-library ranges, but it still needs human/B001 review for ambiguous ranges.


0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md
Document · MD

Supervisor_notes.md
Document · MD

SupervisorAssignments.md
Document · MD

Edited 3 files
+14
-3

source-3/project-documentation/by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md
+0
-1

source-3/project-documentation/tools/leaser/Agents/SupervisorAssignments.md
+12
-0

source-3/project-documentation/tools/leaser/Agents/Supervisor_notes.md
+2
-2
1:04 AM

Worked for 10m 6s
Short answer: not as a single automatic “export developer code vs CRT/MSVC” MCP tool, but yes, IDA MCP can support a good semi-automatic export through IDAPython.

I checked the live IDA MCP tool list. It exposes things like segments, list_funcs, imports, strings, lookup_funcs, decompile, disasm, xrefs_to, get_bytes, and especially py_eval. It does not expose a dedicated flirt, signature, library-range-export, or crt-range-export tool.

The useful part: IDA already has library-function marking. I probed the current IDB and it has:

total functions: 7862
IDA FUNC_LIB-marked functions: 1164
So IDA has already classified a decent amount of code as library/runtime-like.

What we can do:

Export every function with ida_funcs.FUNC_LIB.
Group nearby library functions into candidate runtime/library ranges.
Also export name-pattern candidates like _CxxThrowException, __EH, _initterm, memcpy, operator new/delete, std::, ??_, etc.
Cross-check imports and xrefs to identify CRT/MSVC support regions.
Produce a report like library_runtime_ranges.md/json.
Caveat: this will never be perfect automatically. Static CRT/MSVC and third-party code can be interleaved with developer code, optimized, inlined, or lack signatures. Broad address ranges can accidentally swallow developer functions. The safer export unit is usually function ranges plus reason, not huge contiguous blocks.

Best practical workflow:

Apply or refresh IDA FLIRT/signatures/Lumina/PDB info if available.
Use MCP py_eval to export:
FUNC_LIB functions
compiler/runtime name-pattern functions
import thunk/support functions
suspicious contiguous library clusters
Feed that into documentation as “runtime/library candidate” evidence, not absolute truth.
Have B001/agents treat those candidates as strong hints when deciding whether a by-memory item is developer code.
So yes, there is an easier way than discovering them one by one, but it would be a helper/export script built on IDA MCP, not a built-in one-click MCP command.

1:15 AM