** TARGET-REPORT-UID:0001NH **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B004 Source-Quality Report: UID 0001NH

Assignment: `B004-goal2-spell-string-input-pane-scalar-deleting-destructor-source-quality-0001NH-20260618`

Target: `by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md`

Required scope: report-only. No `by-memory`, coverage, generated, or project-level files were edited.

## Executive Recommendation

`0x005b7e90-0x005b7f54` is exactly the `SpellStringInputPane` scalar deleting destructor compiler wrapper. The raw executable bytes independently prove the function boundary, the twelve-byte `0xcc` post-padding, the three `SpellStringInputPane` vtable restores, the `g_useEpfAssets` / `g_pGeneralPurposePanel` state-helper branch, the shared `LineInputPane` cleanup call, and the bit `1` / bit `4` delete-flag paths.

The target should remain documented under `SpellStringInputPane`, but its `RECONSTRUCTION_CPP CODE` block should stay blank. This is target-specific compiler output for `SpellStringInputPane::~SpellStringInputPane()` and its vtable slots, not a hand-authored C++ method body.

Recommended target metadata after incorporating this report:

- `COMPLETION: 86`
- `CONFIDENCE: 90`
- `CANONICAL_OWNER: 0000DU`
- `RECONSTRUCTABLE: TRUE` may remain for current by-memory accounting if the supervisor keeps scalar deleting destructor wrappers in the reconstructable set.
- Emission guidance: no handwritten source for this page. If the project later applies a family-wide policy that marks scalar deleting destructor wrappers non-emitting, this target is a candidate, but it should not be changed alone.

## Evidence Inputs And Tool Status

Primary local binary inputs now checked:

- Executable: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - Exists: yes.
  - Size: 2,679,296 bytes.
  - Timestamp from filesystem: `2025-12-11 11:24:42`.
- IDA database: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
  - Exists: yes.
  - Size: 84,005,194 bytes.
  - Timestamp from filesystem: `2026-06-17 05:04:39`.

IDA MCP status:

- `Test-NetConnection 127.0.0.1 -Port 13337`: `TcpTestSucceeded : False`.
- Direct MCP tools-list endpoint request: failed to connect.
- Because MCP was offline, this pass compensated with direct PE header parsing, raw byte extraction from `NexusTK.exe`, Capstone disassembly of those bytes, local prewave/export data, and existing IDA-backed by-* documentation.

PE mapping used for raw bytes:

- PE optional-header magic: `0x010b` (32-bit PE).
- Image base: `0x00400000`.
- Target VA range: `0x005b7e90-0x005b7f54`.
- Target RVA range: `0x001b7e90-0x001b7f54`.
- Section: `.text`.
- `.text` RVA: `0x00001000`.
- `.text` raw pointer: `0x00000400`.
- VA-to-file-offset formula: `file_offset = section_raw_pointer + (target_rva - section_rva)`.
- Target file-offset range: `0x001b7290-0x001b7354`.
- Post-padding VA range: `0x005b7f54-0x005b7f60`.
- Post-padding file-offset range: `0x001b7354-0x001b7360`.

Raw byte signatures:

- Body length: `0xc4` bytes, 196 decimal.
- Padding length: `0x0c` bytes, 12 decimal.
- Body SHA-256: `525bfc855e5b7012d7ba9f5087ee805c9f107e57d25169fd27200f9ac73a0f0d`.
- Padding SHA-256: `a0d08a155aa4e9aadd5da959565de99acc8dc9dbda96ec3852dde76c97330902`.
- Body plus padding SHA-256: `84f3317cf4199b53a33718e5adfdd032f6baebbeedb1c630243d58b9d293ad7b`.

## Exact Boundary, Padding, And Bytes

Boundary and padding are now raw-byte proven from `NexusTK.exe`:

- Function: `0x005b7e90-0x005b7f54`.
- Size: `0xc4` bytes.
- Padding: `0x005b7f54-0x005b7f60`.
- Padding bytes: `cc cc cc cc cc cc cc cc cc cc cc cc`.
- Next function starts at `0x005b7f60`, matching the sibling `SpellThreeArgsInputPaneScalarDeletingDestructor` documentation.

Raw body plus padding bytes:

```text
005b7e90: 55 8b ec 6a ff 68 00 68 5f 00 64 a1 00 00 00 00
005b7ea0: 50 56 a1 24 2f 67 00 33 c5 50 8d 45 f4 64 a3 00
005b7eb0: 00 00 00 8b f1 c7 06 84 f1 62 00 c7 86 a0 00 00
005b7ec0: 00 d4 f1 62 00 c7 86 a4 00 00 00 04 f2 62 00 80
005b7ed0: 3d 97 da 66 00 01 8b 0d 74 a8 67 00 6a 00 c7 45
005b7ee0: fc 00 00 00 00 6a 03 75 0e e8 02 07 f0 ff 8b c8
005b7ef0: e8 ab 51 fc ff eb 0c e8 f4 06 f0 ff 8b c8 e8 2d
005b7f00: 45 fc ff 8b ce e8 06 a1 f3 ff 8b 45 08 a8 01 74
005b7f10: 2f a8 04 75 1d 56 e8 a5 cb f3 ff 83 c4 04 8b c6
005b7f20: 8b 4d f4 64 89 0d 00 00 00 00 59 5e 8b e5 5d c2
005b7f30: 04 00 68 0c 01 00 00 56 e8 63 37 e6 ff 83 c4 08
005b7f40: 8b c6 8b 4d f4 64 89 0d 00 00 00 00 59 5e 8b e5
005b7f50: 5d c2 04 00 cc cc cc cc cc cc cc cc cc cc cc cc
```

Capstone disassembly from these exact bytes proves the current body shape:

```text
005b7eb5: c7 06 84 f1 62 00                 mov dword ptr [esi], 0x62f184
005b7ebb: c7 86 a0 00 00 00 d4 f1 62 00     mov dword ptr [esi + 0xa0], 0x62f1d4
005b7ec5: c7 86 a4 00 00 00 04 f2 62 00     mov dword ptr [esi + 0xa4], 0x62f204
005b7ecf: 80 3d 97 da 66 00 01              cmp byte ptr [0x66da97], 1
005b7ed6: 8b 0d 74 a8 67 00                 mov ecx, dword ptr [0x67a874]
005b7edc: 6a 00                             push 0
005b7ee5: 6a 03                             push 3
005b7ee7: 75 0e                             jne 0x5b7ef7
005b7ee9: e8 02 07 f0 ff                    call 0x4b85f0
005b7ef0: e8 ab 51 fc ff                    call 0x57d0a0
005b7ef7: e8 f4 06 f0 ff                    call 0x4b85f0
005b7efe: e8 2d 45 fc ff                    call 0x57c430
005b7f05: e8 06 a1 f3 ff                    call 0x4f2010
005b7f0d: a8 01                             test al, 1
005b7f11: a8 04                             test al, 4
005b7f16: e8 a5 cb f3 ff                    call 0x4f4ac0
005b7f32: 68 0c 01 00 00                    push 0x10c
005b7f37: 56                                push esi
005b7f38: e8 63 37 e6 ff                    call 0x41b6a0
```

The `int_convert.py` checks used for source-quality numeric references:

- `0xc4` = 196.
- `0x10c` = 268.
- `0xa0` = 160.
- `0xa4` = 164.
- `0xfa` = 250.

## Vtable And Adjustor-Thunk Route

The vtable and thunk route is raw-byte proven where the bytes are in the executable, and cross-validated against existing IDA-backed docs.

Raw adjustor thunk bytes:

```text
0x005b78ba-0x005b78c5, file offset 0x001b6cba, SHA-256 93a7ffdcbe8b0ff20b566df5bb362afe03b5dbf4070c63d76c9ca39467f94ca8
005b78ba: 81 e9 a0 00 00 00   sub ecx, 0xa0
005b78c0: e9 cb 05 00 00      jmp 0x5b7e90

0x005b78c5-0x005b78d0, file offset 0x001b6cc5, SHA-256 a8a75c41b221a2cbc104c5a3aba5907bacbfb7dddbede25037473704174e0e18
005b78c5: 81 e9 a4 00 00 00   sub ecx, 0xa4
005b78cb: e9 c0 05 00 00      jmp 0x5b7e90
```

Raw vtable cell bytes:

```text
0x0062f184, file offset 0x0022db84, .rdata:
0062f184: 90 7e 5b 00 10 4b 4f 00 c0 b6 41 00 20 23 4f 00
dwords: 0x005b7e90, 0x004f4b10, 0x0041b6c0, 0x004f2320

0x0062f1d4, file offset 0x0022dbd4, .rdata:
0062f1d4: ba 78 5b 00 f0 24 4f 00 a0 25 4f 00 80 25 4f 00
dwords: 0x005b78ba, 0x004f24f0, 0x004f25a0, 0x004f2580

0x0062f204, file offset 0x0022dc04, .rdata:
0062f204: c5 78 5b 00 90 4e 54 00 a0 23 65 00 00 81 5b 00
dwords: 0x005b78c5, 0x00544e90, 0x006523a0, 0x005b8100
```

Conclusions:

- The primary vtable at `0x0062f184` points directly to `0x005b7e90`.
- The secondary vtable at `0x0062f1d4` points to the `this - 0xa0` adjustor thunk.
- The tertiary vtable at `0x0062f204` points to the `this - 0xa4` adjustor thunk.
- The two thunks tail-jump to `0x005b7e90`.
- Existing `UID:0001N9` docs report no ordinary source-owner role for these adjustor thunks and no direct/static caller route to the target beyond thunk/vtable dispatch.
- This is a compiler vtable/deleting-destructor route, not an application-authored static helper.

## Scalar Deleting Destructor Flag Semantics

The raw bytes prove both delete-flag tests and both release paths:

```text
005b7f0a: 8b 45 08        mov eax, dword ptr [ebp + 8]
005b7f0d: a8 01           test al, 1
005b7f0f: 74 2f           je 0x5b7f40
005b7f11: a8 04           test al, 4
005b7f13: 75 1d           jne 0x5b7f32
005b7f15: 56              push esi
005b7f16: e8 a5 cb f3 ff call 0x4f4ac0
...
005b7f32: 68 0c 01 00 00 push 0x10c
005b7f37: 56              push esi
005b7f38: e8 63 37 e6 ff call 0x41b6a0
```

Interpretation:

- Bit `1` (`flags & 1`) controls storage release after the destructor body has run.
- If bit `1` is clear, the wrapper returns the original object pointer without freeing storage.
- If bit `1` is set and bit `4` is clear, the ordinary free path calls `sub_4F4AC0(this)`.
- If bit `4` is set, the wrapper calls `0x0041b6a0` after pushing object size `0x10c` and the object pointer.
- Existing target/sibling docs identify `0x0041b6a0` as the guard-check/helper path. The raw bytes prove the call and arguments; the semantic label for the helper remains from existing IDA-backed docs and project convention.
- The function returns the original object pointer (`mov eax, esi`) after both release decisions.

This is MSVC deleting destructor wrapper behavior. It should not be represented as a source-authored `SpellStringInputPane::ScalarDeletingDestructor` method.

## Heuristic / Inference Reanalysis And Validation

Raw-byte-proven facts from `NexusTK.exe`:

- Exact body boundary `0x005b7e90-0x005b7f54`.
- Exact body size `0xc4`.
- Exact post-padding `0x005b7f54-0x005b7f60`.
- Post-padding bytes are twelve `0xcc` bytes.
- Three vtable writes restore `0x0062f184`, `0x0062f1d4`, and `0x0062f204` at `this+0x00`, `this+0xa0`, and `this+0xa4`.
- The branch compares byte global `0x0066da97` against `1`.
- The branch loads dword global `0x0067a874`.
- Both branch arms pass child index `3` to `0x004b85f0`.
- The `== 1` branch calls `0x0057d0a0` with pushed value `0`.
- The other branch calls `0x0057c430` with pushed value `0`.
- The wrapper calls `0x004f2010(this)`.
- Bit `1` and bit `4` are tested in the delete flag.
- The ordinary release path calls `0x004f4ac0(this)`.
- The bit `4` path pushes `0x10c`, pushes `this`, and calls `0x0041b6a0`.
- Primary, secondary, and tertiary vtable cells route to the target directly or through `0xa0`/`0xa4` adjustor thunks.

Existing IDA-backed docs / prewave-export facts:

- IDA names the target `sub_5B7E90` with a deleting-destructor-shaped `__thiscall` signature.
- OOAnalyzer/Ghidra classify the function as a virtual deleting destructor for `SpellStringInputPane`.
- `UID:0003AG` is the split direct destructor at `0x005adfd0-0x005ae053`, and its body mirrors the target's destruction work before delete-flag handling.
- `UID:0001N9` is the adjustor thunk island, with the two `SpellStringInputPane` thunks targeting `0x005b7e90`.
- Existing xref docs report no direct/static source callers, only thunk jumps and vtable data refs.
- `0x004f2010` is `LineInputPaneCleanupBody`, not a feature-specific pane destructor.
- `0x004b85f0` is `GeneralPurposePanel::GetChildPaneByIndex`.
- `0x0057d0a0` is `ItemWhoInputPaneStateSetFlag`.
- `0x0057c430` is `SpellInputPaneStateSetFlag`.
- `0x0041b6a0` is the guarded/object-size delete helper path used by sibling scalar deleting destructors.

Source-facing inferences validated by the raw bytes plus docs:

- `byte_66DA97` should be described as `g_useEpfAssets` in source-facing prose. The raw byte proves the address and comparison; `by-global/g_useEpfAssets.md` supplies the alias and process-wide mode role.
- `dword_67A874` should be described as `g_pGeneralPurposePanel`. The raw byte proves the address load; global docs and `GeneralPurposePanelChildAccessors` supply the singleton/child-accessor role.
- Child index `3` is the GeneralPurposePanel spell inventory/spell side-panel child. The raw byte proves `push 3`; the child-order interpretation comes from `0x004b85f0` support docs.
- State byte offset `+0xfa` is not in this target body; it belongs to the two state setter callees. The raw target proves calls with value `0`; the setter docs prove those callees write `this+0xfa`.
- `this+0x108` is not read by this target body; it belongs to the constructor/confirm-input layout. It still corroborates the `0x10c` object extent because the constructor writes a spell-slot byte near the end of the object.
- The target is a compiler wrapper because the raw route is vtable cell -> deleting destructor or vtable cell -> adjustor thunk -> deleting destructor, and the raw body contains standard delete-flag logic after the destructor body.

Rejected alternatives:

- "No local executable available": rejected. `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` and `.i64` both exist and were checked.
- "Raw bytes unavailable": rejected. The PE bytes were dumped by VA-to-file-offset mapping.
- Handwritten `SpellStringInputPane::ScalarDeletingDestructor(unsigned int flags)`: rejected by vtable/thunk routing and compiler delete-flag shape.
- Treat `byte_66DA97` as a local destructor flag: rejected by raw global address use and global alias docs.
- Treat `dword_67A874` as class-local SpellString state: rejected by raw global address use and GeneralPurposePanel docs.
- Treat pushed `3` as the state byte offset: rejected because it is passed to `GeneralPurposePanel::GetChildPaneByIndex`; state offset `+0xfa` is inside the callee docs.
- Treat `0x004f2010` as `TakeOffInputPane::~TakeOffInputPane`: rejected by `LineInputPaneCleanupBody` docs and base cleanup behavior.
- Assign direct source ownership to TargetSelectionInputPanes, ItemActionInputPanes, or GeneralPurposePanel: rejected because those are dependency/helper owners, while the vtable and method family identify `SpellStringInputPane` under `SpellInputPanes`.

Score sufficiency:

- The new raw-byte evidence is sufficient to remove the "bytes unavailable" and "direct destructor split pending" blockers.
- I still do not recommend `95+` completion because original source spelling for state-helper classes and class declarations remains inferential, and the target should remain no-code rather than a final source method.
- Recommended score remains `86/90`: high confidence in boundary/behavior/ownership, with no-code compiler-wrapper treatment as the correct source-quality outcome.

## Ranked Owner And Source Alternatives

1. `SpellStringInputPane` class, `UID:0000DU` - best canonical owner.
   Evidence: raw vtable writes use `0x0062f184`, `0x0062f1d4`, and `0x0062f204`; raw vtable cells route to `0x005b7e90` or adjustor thunks; constructor, direct destructor, confirm handler, and scalar wrapper all form the same class family. Layout evidence agrees with secondary views at `this+0xa0` and `this+0xa4`, stored spell slot at `this+0x108`, and object size `0x10c`.

2. `SpellInputPanes.cpp`, `UID:0000O0` - best source-file owner/emitter family.
   Evidence: the file doc groups `SpellStringInputPane` with sibling spell argument panes, spell slot/change-slot panes, `SpellSpellInputPane`, and the adjustor thunk island. Sibling scalar deleting destructors share the same state-branch and `0x10c` delete-wrapper pattern.

3. `LineInputPane` / InputPane base owners - dependency only.
   Evidence: raw call `0x005b7f05 -> 0x004f2010` proves the base cleanup dependency, but the wrapper restores `SpellStringInputPane` vtables and is reached through `SpellStringInputPane` vtable cells.

4. `TargetSelectionInputPanes.cpp`, `UID:0000OH` - state-helper owner, not this target's source owner.
   Evidence: it owns `SpellInputPaneState`, `ItemWhoInputPaneState`, `SpellWhoInputPane`, and target-selection state helpers. This target consumes those helpers but is not a target-selection pane.

5. `GeneralPurposePanel` / `g_pGeneralPurposePanel` - global/helper owner only.
   Evidence: raw load from `0x0067a874` and calls to `0x004b85f0` explain the child lookup, but they do not own the deleting destructor wrapper.

6. `ItemActionInputPanes.cpp` - rejected.
   Evidence: related to item/action prompt families and `ItemWhoInputPane`, but the target class and sibling panes are in `SpellInputPanes`.

7. New one-class source file such as `SpellStringInputPane.cpp` - rejected.
   Evidence: project file docs and sibling layout favor `SpellInputPanes.cpp`; one-class generated files are wave/prewave artifacts, not source-quality ownership evidence.

## Descriptive / Source-Facing Interpretations

- `byte_66DA97`: source-facing alias `g_useEpfAssets`; raw address `0x0066da97`; IDA alias `byte_66DA97`; process-wide EPF/current-layout mode selector.
- `dword_67A874`: source-facing alias `g_pGeneralPurposePanel`; raw address `0x0067a874`; IDA alias `dword_67A874`; active GeneralPurposePanel singleton pointer.
- `state slot 3`: raw pushed value `3`; interpreted as GeneralPurposePanel child index `3`, the spell inventory/spell side-panel child returned by `GeneralPurposePanel::GetChildPaneByIndex`.
- `this+0xa0`: raw vtable store and thunk adjustment; secondary subobject/vtable view, 160 decimal.
- `this+0xa4`: raw vtable store and thunk adjustment; tertiary subobject/vtable view, 164 decimal.
- `this+0x108`: stored spell slot/index byte written by the constructor and used by confirm-input packet construction; not read in the scalar deleting destructor, but it corroborates the `0x10c` object size.
- `0x004f2010`: raw cleanup call target; source-facing `LineInputPane` cleanup/base destructor body.
- `ItemWhoInputPaneStateSetFlag` (`0x0057d0a0`): raw call target in the `g_useEpfAssets == 1` branch; support docs prove it writes `this+0xfa = value`; value is `0` here.
- `SpellInputPaneStateSetFlag` (`0x0057c430`): raw call target in the non-EPF branch; support docs prove it writes `this+0xfa = value`; value is `0` here.

## Support Docs Rechecked

Rechecked documents and their bearing on this target:

- `by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md`: target page; boundary, padding, state branch, delete flags, xrefs, and no-code status were cross-checked against raw bytes.
- `by-class/SpellStringInputPane.md`: confirms class owner, method inventory, constructor/direct destructor/confirm/scalar wrapper grouping, and source family.
- `by-file/SpellInputPanes.md`: confirms best source file family and rejects cross-family pollution.
- `by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md`: confirms two `SpellStringInputPane` adjustor thunks targeting `0x005b7e90`; raw bytes now independently confirm both thunk bodies.
- `by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md`: confirms aggregate method ranges and padding around constructor/direct destructor/confirm handler.
- `by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md`: confirms vtables, `this+0x108`, and class layout compatible with `0x10c`.
- `by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md`: confirms the direct destructor split is already done and mirrors the scalar wrapper body before delete flags.
- `by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md`: confirms `this+0x108` spell slot usage; remaining packet-local questions do not block this target.
- `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md`: confirms the non-EPF state setter writes `this+0xfa`.
- `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`: confirms the EPF/current-mode state setter writes `this+0xfa`.
- `by-class/SpellInputPaneState.md` and `by-class/ItemWhoInputPaneState.md`: confirm state-helper ownership and active-state clear interpretation.
- `by-memory/0x004f2010-0x004f2092.LineInputPaneCleanupBody.md`: confirms shared `LineInputPane` cleanup/base cleanup and rejects generated `TakeOffInputPane` naming.
- `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`: confirms child index `3` means spell inventory/spell side-panel child.
- `by-global/g_useEpfAssets.md`: confirms `byte_66DA97` source-facing alias and process-wide EPF/current-layout mode.
- `by-global/g_pGeneralPurposePanel.md` and `by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md`: confirm `dword_67A874` alias and singleton role.
- Sibling scalar deleting destructor pages for SpellFourArgs, SpellSlot, SpellThreeArgs, SpellWho, and ItemWho: confirm the repeated compiler-wrapper/delete-flag pattern and the `0x10c` object-size helper path.

Resolved open questions:

- Direct destructor split: resolved by `UID:0003AG`.
- `byte_66DA97`: resolved to `g_useEpfAssets` / process-wide EPF-current layout selector.
- `dword_67A874`: resolved to `g_pGeneralPurposePanel`.
- State slot `3`: resolved as GeneralPurposePanel child index for spell inventory/spell side-panel child.
- Shared cleanup owner: resolved as `LineInputPane` cleanup/body at `0x004f2010`.
- Source emission: resolved as no handwritten C++ for this scalar deleting destructor wrapper.
- Raw bytes: resolved by direct PE dump and Capstone decode from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Remaining non-blocking evidence limits:

- IDA MCP was still unavailable, so the `.i64` database could not be queried live through MCP in this pass.
- Original source spelling for the two state-helper classes is still not proven beyond current documentation names, but their behavior and ownership are sufficient for this target.
- Packet-buffer/local-name questions in `SpellStringInputPaneConfirmInput` remain outside this target and do not block the scalar deleting destructor source-quality decision.

## Rejected Alternatives

- Handwrite `SpellStringInputPane::ScalarDeletingDestructor(unsigned int flags)`: rejected because the target is compiler-emitted deleting destructor glue reached through vtables/thunks and contains compiler delete-flag handling.
- Emit the generated Wave3-style body: rejected because it misnames state helper behavior and the base cleanup owner.
- Treat `byte_66DA97` as a local destructor flag: rejected by raw global address use and `g_useEpfAssets` docs.
- Treat `dword_67A874` as SpellString-owned state: rejected by raw global address use and `g_pGeneralPurposePanel` docs.
- Treat child index `3` as the state byte offset: rejected because raw bytes pass it to `0x004b85f0`; the state byte offset `+0xfa` is inside the two state-helper callees.
- Assign the target to TargetSelectionInputPanes or ItemActionInputPanes: rejected because those own related helper/sibling families, not `SpellStringInputPane`.
- Rename `0x004f2010` as `TakeOffInputPane::~TakeOffInputPane`: rejected by `LineInputPaneCleanupBody` docs and base cleanup behavior.

## First-Draft C++ Recommendation

Do not populate the target page's `RECONSTRUCTION_CPP CODE` block.

The source-level representation should be the normal class destructor declaration/definition for `SpellStringInputPane` in the class/source owner, with the direct destructor body represented by `UID:0003AG` as appropriate. The scalar deleting destructor at `UID:0001NH` and its adjustor routes should be emitted by the compiler from class layout/vtables and destructor declarations.

If a placeholder is ever needed in a non-source note, use this interpretation only as documentation, not as emitted C++:

```cpp
// No source body for UID:0001NH.
// MSVC emits this scalar deleting destructor wrapper for SpellStringInputPane::~SpellStringInputPane().
```

## Coverage Row Recommendation

Do not edit `by-memory/-coverage-report.md` directly from this assignment. If the supervisor accepts this pass, replace the current row near the sibling spell scalar deleting destructor rows, after `UID:0001NG` and before `UID:0001NI`, with:

```text
    - [UID:0001NH][0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor](by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md) 0x005b7e90-0x005b7f54 | scalar deleting destructor | SpellStringInputPaneScalarDeletingDestructor : reconstructable : 86% : strong : raw-byte-confirmed `SpellStringInputPane` scalar deleting destructor compiler wrapper attached to parent `0000DU`: exact 0xc4-byte body, twelve-byte 0xcc post-padding, three vtable restores, state-helper branch through `g_useEpfAssets` / `byte_66DA97`, `g_pGeneralPurposePanel` / `dword_67A874` child slot `3`, shared `LineInputPane` cleanup, scalar-delete bit 1 ordinary free and bit 4 guarded 0x10c object-size path, thunk/vtable refs, and final C++ intentionally blank as compiler wrapper/destructor emission should come from normal C++ destructor declaration rather than handwritten source body.
```

The important coverage text changes are:

- Remove stale "final C++ pending direct-destructor split".
- Add the raw-byte confirmation.
- Add the resolved aliases for `byte_66DA97` and `dword_67A874`.
- Add the explicit no-code compiler-wrapper conclusion.
- Raise completion from `82%` to `86%` only if this evidence is incorporated into the target/support documentation.

## Validator And Research Commands

Validator:

- No project validator was run because this was a report-only pass and no by-memory/generated source file was edited.

Commands/results used during the revised pass:

- `Test-Path E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: `True`.
- `Test-Path E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`: `True`.
- `Get-Item` confirmed executable size `2679296` and IDA database size `84005194`.
- `Test-NetConnection 127.0.0.1 -Port 13337`: `TcpTestSucceeded : False`.
- Direct MCP tools-list endpoint request: failed; unable to connect to the remote server.

> The two removed literal PowerShell commands are preserved only in [0001NH-SpellStringInputPaneScalarDeletingDestructor-source-quality-removed.md](0001NH-SpellStringInputPaneScalarDeletingDestructor-source-quality-removed.md). The archive is non-authoritative and must not be executed.
- Inline Python PE parser over `NexusTK.exe`: produced image base, `.text` mapping, file offsets, byte listing, and SHA-256 values recorded above.
- Capstone 5.0.7 was available and used to disassemble the dumped PE bytes.
- Inline Python/Capstone thunk and vtable dump: produced raw adjustor thunk disassembly and `.rdata` vtable dwords recorded above.
- `python source-3/project-documentation/tools/int_convert.py 0xc4`: `0xc4` = 196 decimal.
- `python source-3/project-documentation/tools/int_convert.py 0x10c`: `0x10c` = 268 decimal.
- `python source-3/project-documentation/tools/int_convert.py 0xa0`: `0xa0` = 160 decimal.
- `python source-3/project-documentation/tools/int_convert.py 0xa4`: `0xa4` = 164 decimal.
- `python source-3/project-documentation/tools/int_convert.py 0xfa`: `0xfa` = 250 decimal.
- Targeted `rg`/file reads over the target, class/file owner docs, state helper docs, globals, sibling scalar destructors, coverage rows, prewave JSON, and generated class file completed and are reflected above.

## Changed Files

Revised:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0001NH-SpellStringInputPaneScalarDeletingDestructor-source-quality.md`

No target, coverage, generated, or project-level documentation files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001NH-SpellStringInputPaneScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0001NH"} -->
<!-- {"agent":"B004","command_id":"000000023047","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001NH-SpellStringInputPaneScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0001NH-SpellStringInputPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T02:36:38-04:00","uid":"0001NH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
