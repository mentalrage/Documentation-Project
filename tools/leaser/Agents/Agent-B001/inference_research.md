Q. When revense engineering code if we find a global variable does that generally mean that when the code was compiled that surrounding items had a high probability of being in the same file that contained that item? What are some other inferences we can make `in general` based on what can be revealed using tools like ida mcp. Also please including if there are additional tools needed that can help that ida mcp cannot specifically cover.

---

## Answer

Short answer: finding a global variable is useful evidence, but by itself it does **not** reliably prove that nearby functions, nearby globals, nearby strings, or nearby constants came from the same original source file. It tells you that the compiler/linker emitted a statically allocated object, or something IDA has interpreted as one. The stronger inferences come from section/segment placement, symbol/debug metadata, relocation records, cross-references, initialization code, and repeated usage patterns.

### 1. Does a global variable imply nearby items were from the same source file?

Only sometimes, and the confidence depends heavily on the build.

In a simple C/C++ build, each source file is normally compiled into a relocatable object file. The linker then combines input sections from those object files into output sections such as `.text`, `.data`, `.bss`, `.rdata`, `.rodata`, `.init_array`, `.got`, or PE/COFF equivalents. In that simple case, adjacent global data in the final `.data` or `.rdata` section may reflect the order in which object files and input sections were linked. That gives you a **weak to medium clue** that a cluster of globals could have come from the same object file.

However, "nearby in the final binary" is not the same thing as "nearby in the source tree." Linkers can merge same-named input sections from many object files. Compilers and linkers can also place each function or data object in its own section, use COMDAT/weak sections, garbage-collect unused sections, fold duplicate constants, pool strings, reorder by alignment, or optimize across source-file boundaries with link-time optimization. That means a variable adjacent to another variable in IDA might be a source neighbor, a linker-order neighbor, a deduplicated constant neighbor, or just an unrelated object that landed nearby.

The practical confidence levels look like this:

- **High confidence:** debug info, PDB/DWARF, a linker map, COFF `.file` records, source path metadata, or object-file/build artifacts explicitly identify the compilation unit or source file.
- **Medium confidence:** several nearby globals have the same naming pattern, same local/static linkage style, same section group/COMDAT association, related constructors/destructors, and are all referenced by the same small set of functions.
- **Low confidence:** the only fact is address adjacency in `.data`, `.bss`, `.rdata`, or `.rodata`.

Static/internal globals are a special case. If a source-level `static` global had internal linkage, other translation units could not directly name it before link-time optimization. So if a cluster of functions directly reads or writes a local/static global, that can increase confidence that those functions are from the same translation unit, or that code from that translation unit was inlined into them. In contrast, an `extern` global is meant to be referenced from other files, so cross-references to it do **not** imply same-file ownership.

Also watch for objects that look like globals but are compiler/runtime artifacts: jump tables, vtables, RTTI, exception-handling metadata, guard variables for local statics, TLS descriptors, import address table entries, GOT/PLT slots, switch tables, merged string literals, and constant pools. These can be highly informative, but they are often produced by ABI/toolchain rules rather than by a human placing variables together in source.

**Sources:**

- LLVM Language Reference, global variables: https://www.llvm.org/docs/LangRef.html#global-variables
- GNU `ld` section placement behavior: https://sourceware.org/binutils/docs/ld/SECTIONS.html
- GNU `ld` garbage collection of input sections: https://sourceware.org/binutils/docs/ld/Options.html
- Microsoft PE/COFF format, section and COMDAT behavior: https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
- System V ABI, ELF sections, symbol tables, relocation sections, `.rodata`, `.symtab`, `.strtab`, `.got`, `.plt`: https://refspecs.linuxfoundation.org/elf/gabi41.pdf
- DWARF 5, compilation units and relation to object files: https://dwarfstd.org/doc/DWARF5.pdf

### 2. What can you infer from a global variable and IDA/MCP-style analysis?

IDA MCP does not magically recover the original source, but it can make IDA's database easier to query and cross-check. A good workflow is to treat each inference as a confidence-rated hypothesis.

#### 2.1 Storage class, mutability, and lifetime

The section/segment tells you the first layer of meaning:

- `.data` usually means initialized writable global/static data.
- `.bss` usually means zero-initialized writable global/static data.
- `.rdata` or `.rodata` usually means read-only constants, strings, vtables, RTTI, jump tables, lookup tables, or const global data.
- `.tls` means thread-local storage.
- `.got`, `.plt`, `.idata`, and IAT-like areas usually mean dynamic linking/import plumbing rather than ordinary user-authored globals.
- `.init_array`, `.ctors`, `.CRT$XCU`, and similar areas point toward startup constructors and global initialization.

This lets you infer whether the value is persistent state, constant lookup data, a pointer table, runtime loader data, or startup/shutdown metadata.

**Sources:**

- System V ABI, ELF special sections: https://refspecs.linuxfoundation.org/elf/gabi41.pdf
- Microsoft PE/COFF format: https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
- LLVM global variables and constants: https://www.llvm.org/docs/LangRef.html#global-variables

#### 2.2 Ownership from cross-references

Cross-references are often more important than address adjacency. If only one function writes a global and many functions read it, the writer is probably an initializer, parser, configuration loader, cache updater, or state transition. If many functions write it, it may be shared state, a counter, a global mode flag, a lock, a ring buffer, or a context pointer. If the global is only referenced through an initialization routine or constructor, it may belong to a C++ object, static local guard, registration table, or plugin/module registry.

IDA and Hex-Rays can expose reads, writes, ordinary references, callers, callees, strings used by a function, stack frames, structure field references, and local/global xrefs. An MCP layer can batch those queries and let you ask for "who reads this," "who writes this," "what calls the writer," and "what strings/constants surround those uses."

**Sources:**

- Hex-Rays decompiler xref documentation: https://docs.hex-rays.com/user-guide/decompiler/interactive/cmd_jump_xref
- Hex-Rays IDA analysis options, automatic xrefs, strings, relocations, FLIRT, EH, RTTI: https://docs.hex-rays.com/user-guide/user-interface/menu-bar/common-actions-5
- mrexodia `ida-pro-mcp` README, available tools such as `list_globals`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_global_value`, `basic_blocks`, and `callgraph`: https://github.com/mrexodia/ida-pro-mcp

#### 2.3 Type and data-structure shape

Access patterns reveal shape. Repeated loads at offsets like `global + 0x10`, `global + 0x18`, and `global + 0x20` suggest a struct. Indexing by scaled values suggests an array. Reads of function pointers suggest a vtable, callback table, dispatch table, import table, or interface object. Bit tests and masks suggest flags. A small writable integer with many comparisons may be a mode, state enum, feature flag, refcount, or error/status value.

The key is to combine evidence:

- Size and alignment.
- Initial bytes and relocations.
- Whether fields are read, written, or passed by pointer.
- Whether the data contains pointers to code, pointers to strings, or numeric constants.
- Whether a decompiler-inferred type is stable across call sites.
- Whether dynamic execution confirms the values and layout.

**Sources:**

- Hex-Rays xrefs to structure fields and local variables: https://docs.hex-rays.com/user-guide/decompiler/interactive/cmd_jump_xref
- mrexodia `ida-pro-mcp` type, structure, stack-frame, and global-value tools: https://github.com/mrexodia/ida-pro-mcp
- LLVM global variables, explicit section/alignment and constants: https://www.llvm.org/docs/LangRef.html#global-variables

#### 2.4 Initialization and program lifecycle

Global variables are often easiest to understand by finding when they first get meaningful values. Look for:

- Startup constructors and registration functions.
- Lazy initialization checks.
- Calls to allocation/configuration APIs before a global pointer is stored.
- Destructors or cleanup routines that release a global resource.
- Error paths that reset a global state flag.
- Thread creation, locks, atomics, or TLS access around the variable.

For C++, global object constructors and vtables can point to class ownership. For malware or packed code, the initial static value may be fake or incomplete until the sample runs and unpacks/decrypts its real data.

**Sources:**

- System V ABI, initialization/finalization and dynamic linking sections: https://refspecs.linuxfoundation.org/elf/gabi41.pdf
- Microsoft PE/COFF format, image layout, relocations, TLS data: https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
- Hex-Rays IDA analysis options for EH/RTTI and relocations: https://docs.hex-rays.com/user-guide/user-interface/menu-bar/common-actions-5

#### 2.5 Capability and intent clues

Globals plus imports plus strings often reveal program intent. Examples:

- A global socket handle plus `connect`, `send`, `recv`, URLs, and config strings suggests network communication.
- A global key schedule plus crypto constants suggests encryption/decryption.
- A global file path buffer plus file APIs suggests persistence, logging, staging, or config storage.
- A global dispatch table plus command strings suggests a command interpreter or protocol parser.
- A global mutex/event/service name plus Windows service APIs suggests singleton behavior or persistence.

These are not proof by themselves. They are triage leads to validate with xrefs, dynamic execution, or capability tools.

**Sources:**

- mrexodia `ida-pro-mcp` search, imports, strings, decompile, xrefs, and analysis tools: https://github.com/mrexodia/ida-pro-mcp
- Mandiant capa, capability detection in executable files: https://github.com/mandiant/capa
- YARA documentation, identifying and classifying malware samples with rules: https://yara.readthedocs.io/en/stable/

### 3. What IDA MCP can and cannot cover

There are several IDA MCP implementations, but they generally expose IDA database operations to an LLM or automation client. The commonly used `ida-pro-mcp` project exposes resources and tools for IDB metadata, segments, entrypoints, imports, exports, types, structures, xrefs, decompilation, disassembly, functions, globals, stack frames, memory reads, comments, renames, pattern search, basic blocks, call graphs, and optional debugger operations.

That is powerful, but it is still bounded by the underlying IDA analysis and by what exists in the binary. Important limitations:

- It cannot prove original source names, comments, local variable names, exact custom types, or source-file ownership if that information was stripped and no debug/build metadata is available.
- It cannot guarantee decompiler pseudocode is semantically perfect. Optimized binaries can inline, split, merge, reorder, and eliminate code and variables.
- It cannot reliably resolve all indirect calls, virtual calls, callback tables, reflection, JIT output, self-modifying code, or runtime-loaded modules without extra evidence.
- It cannot see code or data that is packed, encrypted, generated, downloaded, or unpacked only at runtime unless you capture that runtime state.
- It cannot replace manual judgment. The LLM can make plausible but false inferences, especially with number conversions, pointer arithmetic, compiler artifacts, and large context windows.

So the best practice is: use IDA MCP for fast querying and annotation, but record whether each conclusion is **confirmed**, **strongly inferred**, **weakly inferred**, or **speculative**.

**Sources:**

- mrexodia `ida-pro-mcp` README and tool list: https://github.com/mrexodia/ida-pro-mcp
- Hex-Rays xref documentation: https://docs.hex-rays.com/user-guide/decompiler/interactive/cmd_jump_xref
- Hex-Rays IDA analysis options: https://docs.hex-rays.com/user-guide/user-interface/menu-bar/common-actions-5
- DIRTY paper, decompiler output cannot deterministically recover comments, variable names, and custom variable types: https://arxiv.org/abs/2108.06363
- DIRE paper, learned recovery of decompiled identifier names: https://arxiv.org/abs/1909.09029
- GCC optimization options, inlining/LTO/optimized debug caveats: https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html

### 4. How to make the best inferences possible in any reverse-engineering case

Good reverse-engineering inference is less about one clever clue and more about building a chain of independent evidence. The safest mental model is: every claim should have a confidence level, a reason, and a way it could be wrong.

#### 4.1 Use an evidence ladder

When evidence conflicts, prefer harder metadata and direct machine-code facts over visual layout or naming intuition.

| Confidence | Evidence type | How to use it |
|---|---|---|
| Highest | PDB, DWARF, linker map, build artifacts, source paths, line tables, type records | Treat as direct evidence, while still checking that the symbols match the binary and are not stale. |
| Very high | Relocations, imports/exports, dynamic symbol tables, section groups, COMDAT records, TLS directories, exception tables, RTTI metadata | Use to confirm addresses, symbol binding, startup behavior, object layout, and compiler/runtime artifacts. |
| High | Direct instruction semantics, xrefs, callers/callees, read/write sites, constant propagation, decompiler microcode/IL | Use to prove what code actually reads, writes, branches on, passes, and returns. |
| Medium | Runtime traces, debugger watchpoints, API logs, memory dumps, sandbox reports | Use to confirm which paths execute and what values exist after unpacking or initialization. Beware environment-sensitive behavior. |
| Medium-low | Section adjacency, alignment, local naming patterns, nearby strings, clustered functions | Useful for hypotheses, but weak unless supported by xrefs or metadata. |
| Lowest | Decompiler variable names, autogenerated labels, LLM guesses, "this looks like..." pattern matching | Treat as prompts for investigation, not conclusions. |

The important habit is to write conclusions like this:

- **Confirmed:** "This global belongs to `config.cpp` because DWARF/PDB says so."
- **Strongly inferred:** "This global likely belongs to the parser module because only parser functions read/write it, the writer is reached from parser initialization, and neighboring globals have matching relocation/xref clusters."
- **Weakly inferred:** "This global may be related to the following string table because they are adjacent in `.rdata`, but no xrefs tie them together yet."
- **Speculative:** "This looks like a crypto table, but no transform loop has been confirmed."

#### 4.2 Start every analysis by normalizing the binary context

Before making detailed claims, identify:

- File format: PE, ELF, Mach-O, .NET, APK/DEX, firmware blob, shellcode, packed container, installer, archive, driver, or dump.
- Architecture and mode: x86, x64, ARM, ARM64, MIPS, endianness, compiler ABI, calling convention.
- Binary quality: stripped or symbolized, debug info present or absent, relocations present or stripped, packed/encrypted or ordinary, statically or dynamically linked.
- Toolchain clues: compiler, linker, runtime library, language runtime, framework, Rich header, Go/Rust/.NET metadata, Qt/MFC/Delphi/Unity/Unreal artifacts.
- Optimization clues: LTO, inlining, function/data sections, identical code folding, string pooling, control-flow flattening, obfuscation, stack variables optimized into registers.

This prevents a lot of bad inference. For example, address adjacency means something different in a simple non-LTO debug build than in a release build using `/Gy`, `/Gw`, `/OPT:REF`, `/OPT:ICF`, `-ffunction-sections`, `-fdata-sections`, `--gc-sections`, or LTO.

#### 4.3 Use triangulation: static, metadata, and dynamic evidence

For important claims, try to confirm through at least two independent routes:

- **Static route:** decompiler, disassembly, xrefs, basic blocks, call graph, constants, strings, imports.
- **Object-format route:** headers, sections, symbols, relocations, debug info, exception metadata, resources.
- **Dynamic route:** debugger breakpoints/watchpoints, trace logs, API monitors, memory dumps, unpacked payloads.
- **Comparative route:** another version of the binary, a related open-source project, known library signatures, BinDiff/BinExport comparisons, package metadata.

If all routes agree, confidence rises. If they disagree, the disagreement is often the most valuable clue: packed code, wrong base address, bad function boundary, missed switch table, manually mapped module, stale PDB, anti-debug behavior, or decompiler type confusion.

#### 4.4 Prefer data-flow questions over naming questions

Names are often gone. Data flow remains. Instead of asking "what is this variable called?", ask:

- Who initializes it?
- Who reads it?
- Who writes it?
- Is its address passed anywhere?
- Does it escape into another object, thread, callback, or API?
- What values can reach it?
- What values are derived from it?
- What branch decisions depend on it?
- What happens if it is zero, nonzero, null, invalid, or out of range?

That style works for globals, locals, structure fields, callbacks, virtual calls, file formats, protocols, crypto routines, and malware configuration.

#### 4.5 Actively look for disconfirming evidence

Every plausible theory should be attacked once before you depend on it. Examples:

- If you think adjacent globals share a source file, check whether `-fdata-sections`, COMDAT, string pooling, or linker sorting could explain the adjacency instead.
- If you think a function is user-authored, check FLIRT/library signatures, import thunks, compiler runtime helpers, exception helpers, sanitizer code, and static CRT code.
- If you think a pointer table is a vtable, check whether the pointers point to methods with compatible `this` usage, whether RTTI exists, and whether constructors store that table address into objects.
- If you think a constant table is crypto, check for actual rounds, key schedule, rotations, S-box access, or known magic constants.
- If you think a branch is an authentication/license check, check whether it is actually error handling, feature gating, anti-debug, input validation, or a failed API call path.
- If you think a function is unused, check indirect calls, exports, callbacks, TLS callbacks, exception handlers, registration tables, reflection, scripting engines, plugin systems, and dynamic imports.

#### 4.6 Common inference recipes

| Inference needed | Strong evidence to collect | Common traps |
|---|---|---|
| Same source file or module | Debug compilation unit, PDB path, linker map, COFF file records, local/static symbol cluster, constructors, shared xrefs, section group/COMDAT | Address adjacency alone, string pooling, LTO, linker reordering |
| Function purpose | Inputs, outputs, callees, error paths, strings, constants, API calls, state changes, callers | Naming function by one imported API even though it is a wrapper or shared helper |
| Global variable role | First writer, all readers/writers, lifetime, section, initial value, thread access, reset/cleanup path | Confusing GOT/IAT/TLS/runtime metadata with user globals |
| Structure layout | Offset access patterns, size calculations, allocation size, constructor writes, field-specific xrefs, decompiler type stability | Treating unrelated arrays or packed buffers as structs too early |
| Class/object inference | Constructors, vtable stores, RTTI, virtual dispatch, destructor pattern, `this` pointer convention, allocation sites | Mistaking dispatch tables, import tables, or jump tables for C++ vtables |
| Enum or flags | Repeated comparisons, switch values, bit masks, logging strings, error strings, boundary checks | Assuming decimal constants are semantic without checking uses |
| Indirect call target | Table contents, relocation targets, callback registration, virtual call setup, runtime trace, import resolution | Missing dynamic loading, plugin callbacks, or manually resolved APIs |
| File/protocol parser | Magic constants, length checks, endian conversions, state machine, error messages, read offsets, checksum validation | Treating any byte loop as crypto or compression |
| Crypto/compression | Known constants, rotations, S-boxes, block sizes, entropy changes, key schedule, library matches, before/after buffers | Calling every XOR loop encryption; missing checksum/hash routines |
| Packer/unpacking | High entropy, few imports, abnormal entrypoint, RWX memory, self-modifying writes, VirtualAlloc/VirtualProtect, process dump after OEP | Over-trusting static IDA output before dumping the unpacked image |
| Malware capability | Imports, strings, capa matches, API traces, persistence locations, network/file/registry behavior, sandbox artifacts | Treating dormant capability as executed behavior |
| Concurrency | Thread creation, locks, atomics, TLS, callback queues, shared globals, wait objects | Missing races because static analysis shows possible access, not timing |
| Error handling | Return-value checks, logging strings, cleanup paths, last-error APIs, exception tables | Mistaking failure paths for primary behavior |

#### 4.7 Write inference notes in a repeatable format

For each important claim, use a small evidence note:

```text
Claim:
Confidence:
Evidence:
Counter-evidence checked:
Next verification:
```

Example:

```text
Claim: g_session_state is the process-wide connection/session state.
Confidence: Strongly inferred.
Evidence: Stored after successful connect/login, read before send/recv paths, reset on disconnect,
         address never passed outside session functions, adjacent counters share the same xref cluster.
Counter-evidence checked: Not IAT/GOT/TLS, no library signature, not a vtable or jump table.
Next verification: Set a write watchpoint and capture values during login/logout.
```

This keeps the analysis honest and makes it much easier for an agent or another human to continue the work later.

**Sources:**

- DWARF 5 compilation units and debug information: https://dwarfstd.org/doc/DWARF5.pdf
- Microsoft PE/COFF format, symbols, relocations, COMDAT, TLS, and file records: https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
- System V ABI, ELF sections, symbols, relocations, and dynamic linking: https://refspecs.linuxfoundation.org/elf/gabi41.pdf
- GNU `ld` section placement and garbage collection: https://sourceware.org/binutils/docs/ld/SECTIONS.html and https://sourceware.org/binutils/docs/ld/Options.html
- LLVM global variables, constants, sections, and linkage: https://www.llvm.org/docs/LangRef.html#global-variables
- Hex-Rays xref documentation: https://docs.hex-rays.com/user-guide/decompiler/interactive/cmd_jump_xref
- GCC optimization options, inlining and LTO caveats: https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
- DIRTY paper on information lost in decompilation: https://arxiv.org/abs/2108.06363

### 5. Windows-friendly tools that fit an agent or one-time-export workflow

Use these based on the question you are trying to answer.

| Need | Tools | Why they help |
|---|---|---|
| Primary interactive disassembly/decompilation with direct agent access | IDA Pro + `ida-pro-mcp`, IDAssistMCP, or another maintained IDA MCP server | Best fit when the agent should query functions, globals, xrefs, pseudocode, bytes, comments, types, and call graphs directly from an IDB on Windows. Keep MCP bound to localhost and be careful with plugins that expose arbitrary Python execution. |
| Free interactive disassembly/decompilation with MCP or export | Ghidra + GhidraMCP, or Ghidra headless scripts/export | Ghidra runs on Windows and can expose program info, functions, decompilation, imports/exports, strings, and xrefs through community MCP plugins. If no MCP is configured, the user can export decompiled text, program data, or BinExport files for the agent to analyze. |
| Commercial static analysis with MCP or export | Binary Ninja + `binary_ninja_mcp`, BinAssistMCP/BinjaLattice-style MCP plugins, Binary Ninja API scripts, or built-in BinExport | Binary Ninja runs on Windows and can export pseudocode/disassembly through MCP plugins or create `.BinExport` files from the GUI/command palette/headless quick action. |
| Agent-runnable CLI static analysis | radare2 + r2pipe/JSON commands | Runs on Windows and is very agent-friendly because many commands can return JSON. Useful for headers, sections, imports, symbols, functions, strings, xrefs, and quick second opinions without a GUI. |
| Cross-tool one-time disassembly export | Google BinExport + BinDiff | BinExport works with IDA, Binary Ninja, and Ghidra and exports disassembly data to Protocol Buffers. Good when the user can open the target once and give the agent `.BinExport`, text, stats, or `.BinDiff` outputs to inspect. |
| PE/object-format truth checks | `dumpbin`, `llvm-readobj`, `llvm-objdump`, `llvm-dwarfdump` | These are Windows-runnable command-line tools. They verify sections, symbols, relocations, imports/exports, unwind/debug records, and raw file-format facts outside the decompiler. |
| Compiler/packer/protector triage | Detect It Easy (`die.exe` / `diec.exe`) | Windows GUI and CLI. Good first-pass export/report for file type, compiler, linker, packer/protector, entropy, signatures, and container format clues. |
| Capability triage with machine-readable output | Mandiant capa | Windows CLI and standalone builds. Produces capability reports and JSON output that an agent can consume directly; useful for prioritizing functions and behavior hypotheses. |
| Obfuscated string recovery | Mandiant FLOSS | Windows standalone executable. Produces recoverable string output, including stack/decoded strings; the exported output can be fed back into IDA/Ghidra/Binary Ninja or analyzed directly by an agent. |
| Signature and family matching | YARA | Windows command-line binaries are available. Best when you have rules or want to test whether strings/byte patterns/PE metadata match known families, libraries, packers, or internal code patterns. |
| Packed or injected process dumping | PE-sieve / Hollows Hunter | Windows command-line tools that scan/dump suspicious in-memory PEs, shellcode, hooks, and patches. PE-sieve creates JSON reports and dumped artifacts the agent can analyze offline. |
| Dynamic behavior export | Sysinternals Process Monitor and ProcDump | Procmon can save PML/CSV/XML logs of file, registry, process/thread activity; ProcDump can create dumps for later analysis. These are very useful one-time exports when an agent cannot safely run the sample. |
| Debugging and execution traces | x64dbg, WinDbg/CDB | x64dbg can record trace files with instructions/registers/memory accesses. WinDbg/CDB can run scripted commands and save logs/dumps. Use these when watchpoints, runtime values, exceptions, or indirect targets matter. |
| API/runtime instrumentation | Frida | Runs on Windows and can hook APIs/functions and emit structured logs. Good when the best evidence is runtime argument values, decrypted strings, resolved imports, or callback targets. |
| .NET managed binaries | ILSpy / `ilspycmd`; dnSpy/dnSpyEx for interactive debugging | `ilspycmd` is a Windows-runnable CLI that can decompile assemblies to stdout or project files. dnSpy-style tools are useful when the user needs interactive .NET debugging and export-to-project workflows. |
| Android packages on Windows | JADX and Apktool | Both are Windows-friendly Java tools. JADX exports Java-like source; Apktool decodes resources, manifest, smali, and package structure for agent-readable review. |
| Small code-slice emulation | Unicorn Engine Python bindings | Windows wheels are available. Useful when an agent needs to emulate a small function, decoder, or shellcode slice without running the whole program. |

For this document's workflow, the best default stack is:

1. **IDA Pro + IDA MCP** if IDA is already the main workspace.
2. **GhidraMCP or Binary Ninja MCP** when those databases are the source of truth.
3. **BinExport** when the user can make a one-time GUI export from IDA/Ghidra/Binary Ninja.
4. **capa + FLOSS + Detect It Easy** for quick triage exports.
5. **PE-sieve/Hollows Hunter + Procmon/x64dbg traces** when static analysis is incomplete because the code is packed, injected, or runtime-generated.

**Sources:**

- LLVM `llvm-readobj` documentation: https://www.llvm.org/docs/CommandGuide/llvm-readobj.html
- LLVM `llvm-objdump` documentation: https://llvm.org/docs/CommandGuide/llvm-objdump.html
- Microsoft PE/COFF format and symbol/relocation records: https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
- mrexodia `ida-pro-mcp` README and tool list: https://github.com/mrexodia/ida-pro-mcp
- Ghidra official repository: https://github.com/NationalSecurityAgency/ghidra
- Ghidra headless analyzer API: https://ghidra.re/ghidra_docs/api/ghidra/app/util/headless/HeadlessAnalyzer.html
- GhidraMCP example with Windows PowerShell setup and MCP bridge: https://github.com/13bm/GhidraMCP
- Binary Ninja HLIL/decompiler documentation: https://docs.binary.ninja/dev/bnil-hlil.html
- Binary Ninja BinExport documentation: https://docs.binary.ninja/guide/binexport.html
- Binary Ninja MCP repository: https://github.com/fosdickio/binary_ninja_mcp
- BinAssistMCP repository and platform notes: https://github.com/jtang613/BinAssistMCP
- Google BinExport README: https://github.com/google/binexport
- radare2 r2pipe documentation: https://book.rada.re/scripting/r2pipe.html
- Detect It Easy official site: https://detect-it-easy.github.io/
- Mandiant capa documentation: https://mandiant.github.io/capa/
- Mandiant capa repository: https://github.com/mandiant/capa
- Mandiant FLOSS repository: https://github.com/mandiant/flare-floss
- YARA documentation: https://yara.readthedocs.io/en/stable/
- PE-sieve JSON reports: https://github.com/hasherezade/pe-sieve/wiki/3.3.-JSON-reports
- Hollows Hunter repository: https://github.com/hasherezade/hollows_hunter
- Sysinternals Process Monitor: https://learn.microsoft.com/en-us/sysinternals/downloads/procmon
- Process Monitor command-line export options: https://documentation.help/Process-Monitor/Command_Line_Options.htm
- Sysinternals ProcDump: https://learn.microsoft.com/en-us/sysinternals/downloads/procdump
- x64dbg trace documentation: https://help.x64dbg.com/en/latest/gui/views/Trace.html
- Frida JavaScript API: https://frida.re/docs/javascript-api
- x64dbg official site: https://x64dbg.com/
- Microsoft WinDbg kernel-mode getting started docs: https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/getting-started-with-windbg--kernel-mode-
- ILSpy repository and `ilspycmd`: https://github.com/icsharpcode/ILSpy
- `ilspycmd` NuGet package and CLI options: https://www.nuget.org/packages/ilspycmd/
- dnSpy repository, debugger and export-to-project workflow: https://github.com/dnSpy/dnSpy
- JADX repository: https://github.com/skylot/jadx
- Apktool decode documentation: https://apktool.org/wiki/the-basics/decoding/
- Unicorn Engine Python package with Windows wheels: https://pypi.org/pypi/unicorn/
- BinDiff manual: https://www.zynamics.com/bindiff/manual/

### 6. Suggested practical workflow for this exact question

When you find a global variable in IDA/IDA MCP:

1. Identify the section, size, alignment, initial bytes, and whether the object contains pointers or relocations.
2. List all xrefs to it. Split them into reads, writes, address-taken references, and unknown/indirect references.
3. Find the earliest writer and any startup constructor path. Rename based on behavior, not guesswork.
4. Inspect neighboring globals, but treat adjacency as weak evidence until xrefs, symbols, section groups, or debug info support it.
5. Check whether the symbol is local/static, external, weak, COMDAT, imported, exported, or compiler-generated.
6. If same-file/source ownership matters, first check whether the binary itself contains debug/source breadcrumbs, or a pointer to external debug data. If explicit metadata is absent, use IDA MCP to build a probability-based ownership hypothesis from xrefs, section grouping, constructors, and data-flow clusters.
7. Use a debugger or instrumentation to break on access if static xrefs are ambiguous.
8. Write notes with confidence levels, for example: "confirmed by DWARF CU," "likely same object file due to local symbol and shared xref cluster," or "weak adjacency-only hypothesis."

#### 6.1 Can same-file/source ownership be found by binary inspection?

Yes, sometimes. There are three cases:

1. **The binary contains the source/debug metadata.** This is the best case. ELF/Mach-O binaries may include DWARF sections such as `.debug_info`, `.debug_line`, `.debug_str`, and related sections. PE files may include debug-directory entries; modern MSVC builds usually put the detailed source/type information in an external PDB, but the PE often keeps a CodeView record that identifies the PDB path/signature. In these cases, binary inspection can directly recover compilation units, source paths, line tables, function names, type names, or at least the external symbol file identity.
2. **The binary contains only a pointer/hash to external debug metadata.** ELF files may contain `.gnu_debuglink` or `.note.gnu.build-id`, which lets tools find a separate `.debug` file. PE files may contain CodeView/PDB identity data. This proves that a matching debug file exists or existed, but the full source ownership answer requires obtaining that external file.
3. **The binary contains no explicit source/debug metadata.** Then same-file/source ownership cannot be proven from binary inspection alone. You can still make good inferences, but they must be phrased probabilistically.

This means "look for DWARF/PDB/linker-map/source-path metadata" should be read as a staged process:

- **DWARF:** may be embedded in the binary, split into `.dwo`/`.debug` files, or absent.
- **PDB:** usually external for native Windows PE, with a debug-directory CodeView record in the PE pointing to it.
- **Linker map:** normally an external build artifact, not a standard embedded binary section. If you do not have the map file, you can only reconstruct a map-like view from sections, symbols, xrefs, and ordering.
- **Source paths:** may appear in DWARF, PDBs, CodeView records, .NET portable PDBs, assert/log strings, resource metadata, or accidental strings. Strings alone are weaker evidence than debug records.

#### 6.2 IDA MCP alternatives when another tool is normally used

Some checks are usually faster with tools such as `dumpbin`, `llvm-readobj`, `llvm-dwarfdump`, or `llvm-pdbutil`, but many can still be attempted through IDA MCP if the MCP exposes IDA database queries, bytes, strings, segments, decompilation, and IDAPython.

| Question | Usual external method | IDA MCP / binary-inspection alternative | Confidence |
|---|---|---|---|
| Does this PE point to a PDB? | `dumpbin /headers`, `llvm-readobj --codeview`, PE parser | Search strings for `.pdb`, `RSDS`, or `NB10`; inspect the PE debug directory with IDAPython or raw bytes; check whether IDA loaded/applied PDB symbols. | High for identifying the PDB reference; not enough to recover full PDB contents. |
| Does this ELF contain embedded DWARF? | `llvm-dwarfdump`, `readelf`, Ghidra DWARF loader | List segments/sections and strings for `.debug_*`; if IDA imported DWARF, query names/types/line info already applied in the IDB; use IDAPython/raw bytes for deeper parsing if needed. | High if DWARF is present and parsed; medium if only section names/strings are visible. |
| Is there separate debug info? | Check `.gnu_debuglink`, `.note.gnu.build-id`, symbol server/debug package lookup | Use IDA MCP to list sections/segments and read bytes from `.gnu_debuglink` or `.note.gnu.build-id`; search strings for `.debug`; then locate/import the external debug file separately. | High for proving a link/build-id exists; full ownership requires the external file. |
| Which source file owns this function/global? | DWARF/PDB line tables, compilation units, linker map | If debug info was loaded into IDA, query function names, line/source annotations, local types, and comments. Without debug info, cluster by local/static globals, xrefs, constructors, nearby COMDAT/section groups, shared strings, shared error paths, and caller/callee locality. | Confirmed with debug/map data; otherwise probabilistic. |
| Are nearby globals from the same object/source file? | Linker map, COFF object records, DWARF CU data | Use IDA MCP to compare xref sets, first writers, constructors, section/subsection names, alignment boundaries, relocation patterns, and whether the data is address-taken by the same functions. | Medium at best without explicit debug/map metadata. |
| Is this a compiler/runtime/library artifact? | FLIRT/signature tools, object-format tools, compiler docs | Use IDA MCP to check FLIRT names, import thunks, exception tables, RTTI, vtables, TLS callbacks, CRT startup functions, and whether the function/data is referenced only by runtime scaffolding. | Medium to high depending on signature and xref evidence. |
| Can I reconstruct a linker-map-like view? | Real linker `.map` file | Use IDA MCP to export functions/globals sorted by segment/address, then group by section, naming pattern, xref cluster, constructor registration, and library signature status. | Useful for navigation, but not proof of original object-file ownership. |

Practical IDA MCP sequence for this specific ownership question:

1. Query binary metadata, segments/sections, imports/exports, and globals.
2. Search all strings for `.pdb`, `RSDS`, `NB10`, `.debug`, `.dwo`, `.gnu_debuglink`, source extensions (`.c`, `.cpp`, `.rs`, `.go`), and source-root-looking paths.
3. For the target global, collect all reads/writes/address-taken xrefs and the functions containing those xrefs.
4. For each referencing function, collect callers, callees, strings, constants, nearby globals, and initialization paths.
5. If IDA has loaded symbols/debug info, prefer IDA's applied names, types, and source/line annotations over heuristic clusters.
6. If no explicit metadata exists, label the result as "likely module/object ownership" and include the evidence cluster rather than claiming a source file as fact.

Bottom line: a global variable is a strong anchor for analysis. The best same-file inference is not "it is nearby," but "it is nearby, in the same relevant section/group, has related xrefs, matching initialization, compatible symbol linkage, and no evidence of pooling/reordering/LTO." If you can add debug info, linker maps, raw relocation data, and runtime watchpoints, the inference becomes much stronger.

**Sources:**

- Hex-Rays xref documentation: https://docs.hex-rays.com/user-guide/decompiler/interactive/cmd_jump_xref
- mrexodia `ida-pro-mcp` README and tool list: https://github.com/mrexodia/ida-pro-mcp
- DWARF 5 compilation units: https://dwarfstd.org/doc/DWARF5.pdf
- GDB separate debug files, `.gnu_debuglink`, and build-id lookup: https://www.sourceware.org/gdb/current/onlinedocs/gdb.html/Separate-Debug-Files.html
- Ghidra DWARF external debug-file lookup by `.gnu_debuglink` and `.note.gnu.build-id`: https://scrapco.de/ghidra_docs/VERSION12/Features/Base/DWARFExternalDebugFilesPlugin/DWARFExternalDebugFilesPlugin.html
- GNU `ld` section behavior and garbage collection: https://sourceware.org/binutils/docs/ld/SECTIONS.html and https://sourceware.org/binutils/docs/ld/Options.html
- Microsoft PE/COFF symbols, debug directory, CodeView records, relocations, COMDAT, and file records: https://learn.microsoft.com/en-us/windows/win32/debug/pe-format
- System V ABI, ELF symbols/sections/relocations/dynamic linking: https://refspecs.linuxfoundation.org/elf/gabi41.pdf
