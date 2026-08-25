*** UID:00034V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for IconsPane; source is IconsPane::~IconsPane().
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Current MCP refresh confirms `sub_4CFDA0` as the exact `0x5f`-byte `IconsPane` scalar deleting destructor wrapper: vtable restores at `0x0061b448/0x0061b494/0x0061b4c4`, `g_pIconsPane` clear at `0x004cfdc0`, shared cleanup `0x00544580`, scalar-delete/free guard through `0x004f4ac0`/`0x0041b6a0`, refs only from two IconsPane adjustor thunks plus the primary vtable slot, and clean `0xcc` boundaries before sibling `TabPane` destructor; formal C++ is now comment-only so UID0002SX emits the single ordinary `IconsPane::~IconsPane(){ g_pIconsPane = NULL; }` source body while this page preserves wrapper evidence. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# 0x004cfda0-0x004cfdff IconsPane Scalar Deleting Destructor

## Status

- Entity kind: `IconsPane` scalar deleting destructor body.
- Direct owner: [UID:00006B][IconsPane](by-class/IconsPane.md).
- Source file: [UID:0000JZ][IconsPane](by-file/IconsPane.md).
- Parent aggregate: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md).
- Rebuild handling: reconstructable scalar-deleting wrapper evidence with comment-only formal marker. The source-visible ordinary destructor body is emitted by [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md); this page preserves wrapper vtable restores, delete flags, optional free, and guard behavior without emitting a duplicate `IconsPane::~IconsPane()` body.
- Current source route: keep [UID:00006B][IconsPane](by-class/IconsPane.md) as both canonical owner and emitter. The class page surfaces through [UID:0000JZ][IconsPane](by-file/IconsPane.md) / `NexusTK/ui/panels/IconsPane.cpp`.

## Behavior

The scalar deleting destructor wrapper restores the three `IconsPane` vtable views, clears [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md) / `0x0069b41c`, calls shared pane cleanup at `0x00544580`, and conditionally frees `this` through `0x004f4ac0` when scalar-delete flags allow it.

The clear at `0x004cfdc0` remains important binary lifecycle evidence, but the source-visible destructor statement is emitted once by [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md) as `IconsPane::~IconsPane(){ g_pIconsPane = NULL; }`. This wrapper's formal C++ is deliberately comment-only to avoid duplicate destructor output.

IDA decompilation shows:

```c
*this = IconsPane::vftable;
this[40] = IconsPane::vftable_0;
this[41] = IconsPane::vftable_1;
dword_69B41C = 0;
sub_544580(this);
if ((flags & 1) != 0 && (flags & 4) == 0) sub_4F4AC0(this);
```

Current MCP disassembly refines the bounded wrapper behavior:

- `0x004cfda6`, `0x004cfdac`, and `0x004cfdb6` store `IconsPane` vtables `0x0061b448`, `0x0061b494`, and `0x0061b4c4` into `this+0`, `this+0xa0`, and `this+0xa4`.
- `0x004cfdc0` stores zero to `0x0069b41c` / `g_pIconsPane`.
- `0x004cfdca` calls shared pane cleanup `sub_544580`.
- `0x004cfdd2-0x004cfdd8` tests scalar-delete flags: no ordinary free when `(flags & 1) == 0` or `(flags & 4) != 0`.
- `0x004cfddb` calls `sub_4F4AC0(this)` only on the ordinary scalar-delete path.
- `0x004cfdea-0x004cfdf5` is the `flags & 4` guard-helper path through `@_guard_check_icall_nop@4`, with pushed `0x104` and `this`. This is compiler/security wrapper glue, not ordinary destructor source.

## IDA Evidence

- `py_eval` on 2026-06-10 reports IDA function `sub_4CFDA0` at `0x004cfda0-0x004cfdff`, size `0x5f`, 29 instructions, and 5 basic blocks.
- `xrefs_to 0x004cfda0` reports code refs from the two `IconsPane` adjustor thunks and a primary vtable/data ref at `0x0061b448`.
- Callees are shared pane cleanup `0x00544580`, delete helper `0x004f4ac0`, and guard helper `0x0041b6a0`.
- Vtable refs are to `0x0061b448`, `0x0061b494`, and `0x0061b4c4`; those same vtables are installed by `IconsPane` constructor/cleanup at `0x004cf1f0` and `0x004cf260`.
- `g_pIconsPane` is written by constructor and cleanup and cleared here at `0x004cfdc0`.

## Current MCP Refresh

2026-07-02 B001 current MCP session facts:

- MCP active session: `supervisor_resume_20260629`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `14860`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `lookup_funcs` confirms `sub_4CFDA0` at `0x004cfda0`, size `0x5f`.
- Nearby function inventory from `entity_query 0x004cfd60-0x004cfe70`: `0x004cfd6c` and `0x004cfd77` are the two `IconsPane` adjustor thunks, `0x004cfd82` and `0x004cfd8d` are the two sibling `TabPane` adjustor thunks, `0x004cfda0` is this destructor, `0x004cfe00` is the sibling `TabPane` scalar deleting destructor, and `0x004cfe60` starts the successor function.
- `disasm 0x004cfda0` reports 29 total instructions; `basic_blocks 0x004cfda0` reports five blocks.
- `callees 0x004cfda0` returns exactly `0x00544580` / `sub_544580`, `0x004f4ac0` / `sub_4F4AC0`, and `0x0041b6a0` / `@_guard_check_icall_nop@4`.
- Current decompile keeps the same wrapper shape: `IconsPane` vtable restores, `unk_69B41C = 0`, shared cleanup call, no free when `(flags & 1) == 0` or `(flags & 4) != 0`, and `sub_4F4AC0(Block)` on the ordinary scalar-delete path.

Current xref inventory:

- `xrefs_to 0x004cfda0`: two code refs at `0x004cfd72` and `0x004cfd7d` from [UID:00034T][0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks](by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md), plus one data ref at the primary `IconsPane` vtable slot `0x0061b448`.
- `xrefs_to 0x0069b41c`: constructor write `0x004cf215`, cleanup clear `0x004cf27a`, this destructor clear `0x004cfdc0`, shutdown read `0x00504a07`, and option UI reads `0x0053da72` and `0x0053dec2`.
- `xrefs_to 0x0061b448`: constructor `0x004cf21a`, cleanup `0x004cf260`, and this destructor `0x004cfda6`.
- `xrefs_to 0x0061b494`: constructor `0x004cf220`, cleanup `0x004cf266`, and this destructor `0x004cfdac`.
- `xrefs_to 0x0061b4c4`: constructor `0x004cf22a`, cleanup `0x004cf270`, and this destructor `0x004cfdb6`.

Boundary and byte evidence:

- `get_bytes 0x004cfd98` shows eight `0xcc` bytes immediately before the target, followed by the `0x004cfda0` prologue.
- `get_bytes 0x004cfda0` matches the vtable stores, singleton clear, shared cleanup call, scalar-delete/free path, guard-helper path, and `retn 4` endings. The byte at `0x004cfdff` is `0xcc`.
- `0x004cfe00` starts sibling [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md), not a continuation of this target.
- `get_bytes 0x0069b41c` reports current singleton storage bytes `00 00 00 00`.

Pointer-byte search:

- VA bytes for `0x004cfda0` (`a0 fd 4c 00`) occur exactly once at `0x0061b448`, the primary `IconsPane` vtable slot.
- RVA bytes for `0x000cfda0` (`a0 fd 0c 00`) have zero matches.
- The `0x0061b448`, `0x0061b494`, and `0x0061b4c4` vtable immediate bytes occur only in constructor, cleanup, and this destructor write sites.
- The `g_pIconsPane` address bytes occur only at the six known lifecycle/consumer sites.

## Ownership And Source Placement

Keep [UID:00006B][IconsPane](by-class/IconsPane.md) as the direct owner and emitter. The evidence is class-specific: this range restores `IconsPane` vtables, clears `g_pIconsPane`, is reached by two `IconsPane` adjustor thunks, and is referenced by the primary `IconsPane` vtable slot. The same vtables and singleton appear in the `IconsPane` constructor and ordinary destructor body at UID0002SX.

Reject [UID:0000EB][TabPane](by-class/TabPane.md) ownership. [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) is the sibling `TabPane` wrapper and has the same compiler-generated shape, but it uses `TabPane` vtables and clears `g_pTabPane`. Shared wrapper shape is compiler output, not class ownership evidence.

Reject `Pane` or base-helper ownership. This destructor calls shared pane cleanup at `0x00544580`, but the class-specific vtable restores and singleton clear happen in this wrapper before base cleanup. The cleanup callee is a base-chain dependency, not the semantic owner of the derived destructor.

Reject assigning this target to [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md). The broad tail is a `RECONSTRUCTABLE:FALSE` mixed inventory after split repair; exact children carry source ownership or non-emitting compiler-artifact disposition.

Reject no-owner treatment for this exact page because the wrapper belongs to `IconsPane` and carries important vtable, singleton, adjustor-thunk, and primary-vtable-slot evidence. The ordinary source destructor effect is no longer emitted here; [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md) owns the single source body and this target stays class-owned scalar-wrapper support.

## Ownership Decision

Attach to [UID:00006B][IconsPane](by-class/IconsPane.md). The body is physically interleaved in the `TabPane` tail, but every class-specific signal is `IconsPane`: vtables, singleton clear, and adjustor-thunk refs.

## Score Rationale

Completion is raised to `87` because current schema-current MCP evidence now documents the exact function boundary, 29-instruction/five-block wrapper, direct xrefs, callee inventory, boundary bytes, sibling relation, pointer-byte search, and source-vs-wrapper separation. Confidence is raised to `91` because the owner and behavior evidence is direct and redundant: primary vtable slot, two adjustor thunks, three vtable restore refs, six singleton refs, exact bytes, decompile, disassembly, and sibling comparison all agree.

Do not raise above low-90s/final-audit range yet. Final original source grouping with `TabPane` remains not symbol-proven, exact source declaration/header shape is not finalized, and the wrapper includes compiler-generated ABI/security behavior that must stay documented rather than hand-authored.

## Reconstruction Notes

This page is scalar-wrapper support. The call to shared pane cleanup, scalar-delete flag path, optional free, and guard-helper path should be regenerated by MSVC from the virtual destructor declaration and object model. The ordinary source-visible destructor statement is emitted by UID0002SX after the B014 callback.

Keep the formal source block comment-only:

```cpp
// Compiler-generated scalar deleting destructor for IconsPane; source is IconsPane::~IconsPane().
```

Do not emit a duplicate `IconsPane::~IconsPane()` body here and do not emit raw wrapper pseudocode with `Block`, `unk_69B41C`, explicit vtable stores, `sub_544580`, flag tests, `sub_4F4AC0`, or `@_guard_check_icall_nop@4`. Those are compiler ABI/security details and are documented here only to preserve binary behavior evidence.

## 2026-07-04 B014 UID0002SX Source-Route Sync

B014's accepted UID0002SX report and MCP session `73c77998` resolved the source route conflict: the ordinary/non-deleting destructor body is [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md), while this range is the scalar deleting wrapper. UID0002SX now emits the single `IconsPane::~IconsPane()` body with only `g_pIconsPane = NULL;`. This page preserves the wrapper's vtable restores, singleton clear, shared cleanup call, scalar-delete flags, optional free, guard path, adjustor-thunk refs, primary vtable ref, and boundary evidence, but its formal C++ is comment-only so generated output does not contain a second source destructor body.

## Cross-References

- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
