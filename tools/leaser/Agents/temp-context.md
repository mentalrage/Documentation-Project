IDA does not “convert the EXE to C++” in one step. It gives you progressively better decompiled pseudocode as you add names, types, structures, and ownership knowledge. The final buildable C++ still has to be reconstructed manually from that evidence.
What IDA lets us do with the documentation:
Rename thingsFunctions: sub_5C5DED -> std::logic_error constructor, or project names like Socket::ConnectEndpoint.
Globals: dword_... -> meaningful singleton/table/state names.
Locals/stack variables: v4, a1, this_ -> real variable/member-style names.

Apply function prototypesReturn type.
Calling convention: __thiscall, __cdecl, __stdcall, etc.
Parameter types and names.
For class methods, define the first parameter as the class this pointer when needed.

Define typesStructs/classes in IDA local types.
Enums.
Function pointer types.
Vtable layouts.
Packet/resource/data layouts.

This is the closest thing to “uploading types.” You give IDA C/C++ declarations, and then apply them to functions, globals, stack variables, or memory addresses.
Improve decompilation
Once names and types are applied, Hex-Rays output gets much closer to source:pointer arithmetic becomes field access
raw integers become enum values
a1 + 0x24 becomes this->fieldName
indirect calls can become vtable or callback calls
function signatures become readable

Separate what not to port
Using docs and signatures, we mark or identify:CRT/STL/MSVC runtime
compiler-generated EH/SEH funclets
third-party libraries like libjpeg/jsoncpp/boost
padding/stubs/import glue

Those should usually not become NexusTK source files. They are dependencies or compiler output.
The practical workflow is:
Verify an address/range against IDA and by-memory.
Rename only verified functions/globals.
Define/apply types for the involved class/data layout.
Re-decompile and check whether the output improves or becomes misleading.
Export/use the decompiled pseudocode as evidence.
Rewrite it into clean buildable C++ in the reconstruction tree.
The important caution: you do not rename every symbol or apply every signature result. Bad names/types can make the decompiler look more confident while being wrong. For this project, the safe path is targeted IDA improvement based on already-written documentation plus fresh verification.

8:31 AM






look up ida 9.2 I think it added support for c++? Im not sure for what exactly



8:33 AM






Worked for 41s



Yes. IDA 9.2 did add more C++-related support, but it is mostly type parsing/import support, not automatic “convert binary to original C++ source.”
The main 9.2 change is a new LLVM/Clang-based type parser. Hex-Rays says it allows C++ directly in the type editor, including things like instantiated templates, and unifies type parsing across the type editor, idaclang, and tilib. It is not default in 9.2; legacy remains default unless enabled. Source: IDA 9.2 release notes.
What that means practically:
You can paste/import more real C++ declarations into IDA.
Classes, structs, namespaces, templates, function prototypes, and vtable-ish declarations are easier to parse.
IDA can then use those types to improve Hex-Rays decompiler output.
This helps turn decompiled output from raw pointer math into cleaner field/method-style pseudocode.
IDAClang also supports importing complex C/C++/Objective-C type info into the database and can handle C++20-era syntax and earlier. It can use C++ class declarations to generate useful vtable types and template-instantiated types. Source: IDAClang docs.
There is also a separate decompiler improvement: IDA 9.2 can emit try/catch blocks for x64 MSVC C++ exception handling. Source: Hex-Rays feature overview. For NexusTK, which appears to be 32-bit x86, that specific x64 MSVC exception feature probably does not help much.
For this project, the useful part would be:
define reconstructed C++ class/struct headers from our docs;
import them into IDA with the Clang parser;
apply those types to functions/globals/vtables;
re-decompile and verify the output;
use the improved pseudocode as evidence for reconstruction.
So: IDA 9.2 helps us feed C++ knowledge into IDA better. It does not automatically recover the original source tree or safely name everything by itself.

8:34 AM






would that be part of the workflow you suggested since the end goal is the most accurate possible reconstruction of the oriiginal c++ source code the developers wrote



8:35 AM






Yes. For this project, IDA 9.2’s C++ type parsing should be part of the workflow, but not as the first step and not as a blind import.
Best fit in the workflow:
Document/verify behavior first
Use by-memory, IDA decompilation, xrefs, strings, and signatures to decide what a function/range actually is.

Reconstruct likely C++ declarations
From that evidence, build small headers for classes, structs, enums, callbacks, vtables, packets, and globals.

Import/apply those types in IDA
This is where IDA 9.2 helps. The Clang parser should make real C++ declarations easier to import, especially namespaces, classes, templates, and vtable-related types.

Re-decompile and compare
If the pseudocode gets clearer and still matches behavior, keep the type. If it makes the output misleading, revert/refine it.

Write final source manually
The final output still needs human reconstruction: original-style names, file ownership, source layout, idioms, and readable early-2000s C++.

The caution is that types are powerful. A wrong class layout or prototype can make Hex-Rays produce cleaner-looking but false C++. So I’d use it incrementally: one class/subsystem at a time, with comments/docs saying exactly what type was applied and why.
For NexusTK, this is especially useful for:
class layouts and this pointer fields
vtables and virtual methods
packet structs
UI/control classes
resource/DAT structs
callback/function-pointer tables
STL/CRT boundaries, mostly to exclude them from hand reconstruction
So yes: if the goal is the most accurate reconstruction of the developers’ original C++ source, IDA 9.2’s C++ type parser belongs in the pipeline as a verification and decompiler-improvement tool.