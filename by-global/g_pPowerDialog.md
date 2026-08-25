*** UID:0000S0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:160 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
PowerDialogPane *g_pPowerDialog = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pPowerDialog

## Status

- Confidence: very strong for address, owner, `PowerDialogPane *` type, source-facing name, external declaration route, zero initialization, and one-definition placement.
- Address: `0x0069ba34`
- IDA storage name: not exposed through the current MCP names/globals index; older decompiler output used `dword_69BA34`.
- Alias candidates observed: `g_pPowerDialog`, `g_activePowerListPane`
- Primary memory doc: [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md)
- Likely owner: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- Source placement: sole definition in `NexusTK/ui/dialogs/PowerDialogPane.cpp` at direct-emitter position `160`, after the exact class/method child sequence; compile-visible `extern` declaration is supplied before the complete class by [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md).

## Purpose

This semantic global stores the active `PowerDialogPane` singleton and owns the sole source definition `PowerDialogPane *g_pPowerDialog = NULL;`. Physical loader-created storage is documented by [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md), which is non-emitting so the source has exactly one definition.

Do not treat `g_activePowerListPane` as a separate list-control singleton. That alias is attached to the same storage address, but the observed consumers use it as the owner dialog pointer so embedded `PowerListPane` instances can reach sibling list controls through the dialog's control collection.

## Evidence Notes

- B002 UID0001PZ research on healthy MCP database `9b0396a3` independently returned four zero bytes at `0x0069ba34`, exactly five refs with no continuation, and no distinct data/global entity. Read-only PE arithmetic proves the address lies in `.data` virtual tail beyond raw bytes, so `NULL` expresses loader-zero source semantics without inventing an `0xffffffff` initializer.
- The five-reference lifecycle is complete: constructor publish `0x0054a44c`, ordinary destructor clear `0x0054a49a`, getter read `0x0054a4b0`, `PowerListPane::OnMouseEvent` read `0x0054b010`, and scalar-wrapper clear `0x0054b540`. No sixth xref or second storage definition was found.
- `g_pPowerDialog` is typed `PowerDialogPane *`: the constructor publishes the complete dialog object, all teardown paths install PowerDialogPane vtable views, the getter returns the same pointer, and the private list handler follows it to the containing dialog's control collection. Integer, `void *`, and `PowerListPane *` alternatives are rejected.
- Current source-family comparison with `DescPane` and adjacent accepted dialog singleton routes supports external declaration plus one module definition. Exact binary linkage cannot distinguish external from file-static, but the complete UID0000AP declaration makes the external route compile-visible and project-consistent; this uncertainty caps lexical confidence rather than blocking source.
- IDA xrefs to `0x0069ba34` are confined to the power-dialog/list block: `0x0054a44c`, `0x0054a49a`, `0x0054a4b0`, `0x0054b010`, and `0x0054b540`.
- The constructor/packet initializer at `0x00549c20` stores `this` into `dword_69BA34` at `0x0054a44c` after installing `PowerDialogPane` vtables and attaching the dialog.
- The clear helper at `0x0054a480` and the scalar deleting destructor at `0x0054b520` both reinstall `PowerDialogPane` vtables and clear `dword_69BA34`.
- The tiny helper at `0x0054a4b0` returns `dword_69BA34`.
- `PowerListPane::OnMouseEvent` at `0x0054b000` reads `dword_69BA34` at `0x0054b010`, then dereferences the dialog control collection at `+0x1fc` to clear sibling list selections for controls `7-10`.
- Exact constructor and singleton-helper coverage now lives in [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md) and [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md).
- 2026-06-16 C001 live MCP refresh used session `c001_midiplayer_rdata_20260615`; `get_bytes 0x0069ba30` returns a zeroed singleton-adjacent window, superseding older `0xffffffff` byte notes in the support page/report. `xrefs_to 0x0069ba34` reconfirmed the five references: constructor publish `0x0054a44c`, clear helper `0x0054a49a`, singleton getter `0x0054a4b0`, embedded list mouse-handler read `0x0054b010`, and scalar destructor clear `0x0054b540`.
- 2026-06-26 B007 session `80de0a67` confirms [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) now emits formal first-draft C++ using this global: `PowerDialogPane::~PowerDialogPane()` assigns `g_pPowerDialog = 0`, and `PowerDialogPane::GetSingleton()` returns `g_pPowerDialog`. This reinforces `g_pPowerDialog` as the source-facing singleton name and keeps `g_activePowerListPane` rejected as a generated/owner-polluted alias.
- C001 saved the IDA function names `PowerDialogPane_Constructor`, `PowerDialogPane_ClearSingletonHelper`, `PowerDialogPane_GetSingleton`, and `PowerDialogPane_ScalarDeletingDestructor`. The data-slot rename to `g_pPowerDialog` was skipped because the current MCP rename data path requires an existing global-name key and the slot is not exposed in the names/globals index.
- `xrefs_to 0x00549c20` still reports the real MapPane packet-case caller at `0x0050876a` plus the retained wrapper at `0x00513b93`; `xrefs_to 0x00513b50` reports no inbound refs to that wrapper. This keeps the second-caller/source-shape question documented without weakening the singleton ownership.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069ba34` is `dword_69BA34`, size `4`, in `.data`, with 5 data xrefs.
- Live IDA xrefs confirm constructor write at `0x0054a44c` in `sub_549C20`, singleton clear helper at `0x0054a49a` in `sub_54A480`, tiny accessor at `0x0054a4b0` in `sub_54A4B0`, `PowerListPane` use at `0x0054b010` in `sub_54B000`, and scalar deleting destructor clear at `0x0054b540` in `sub_54B520`.
- The xref set is confined to the power-dialog/list block, supporting the owner decision and the rejection of a separate list-control singleton interpretation.
- Live IDA decompilation on 2026-06-05 confirms `0x00549c20` stores `this` into `dword_69BA34` and installs the `PowerDialogPane` vtables; `0x0054a480` and `0x0054b520` clear the singleton, and `0x0054a4b0` returns it.
- Historical evidence-time conclusion: completion then remained below full because final source-level spelling had not been resolved. Current UID0001PZ research supersedes that blocker with the accepted `PowerDialogPane *g_pPowerDialog` one-definition route.

## Config And Style Caveats

- The `g_powerThresholdConfig` alias is not a distinct power-owned global. IDA decompilation of the constructor shows a read of `dword_67A7C8` / `g_pConfig` at `0x00549cb0`, then uses config shorts at offsets `0x28de94`, `0x28de96`, `0x28de98`, and `0x28de9a`.
- The `g_defaultPaneStyle` alias corresponds to broad UI style/global storage at `dword_69B36C`; it is not owned by the power dialog.

## One-Definition And Compiler Disposition

- UID0000S0 is the only source emitter for this global. UID0001PZ is physical/non-emitting, UID0003CF is compiler RTTI/vtable data, and UID0004B9 is a compiler scalar deleting wrapper.
- UID0000AP provides `class PowerDialogPane;` and `extern PowerDialogPane *g_pPowerDialog;` before its class body and `[[CHILDREN]]`, making constructor/destructor/getter/list uses compile-visible before this trailing definition.
- Direct emitter order remains UID0000AQ at 10; PowerDialogPane and PowerListPane method children at 20 through 150; this definition at 160. No separate global source file, class static member, Singleton-template base, raw address marker, or duplicate definition is supported.
- Constructor publication and ordinary destructor clear are authored class semantics. The compiler regenerates vptr stores, base teardown, adjustor thunks, scalar flags/free behavior, RTTI, and vtables; none belongs in this definition.

## Cross-References

- [UID:0001PZ][0x0069ba34-0x0069ba38.g_pPowerDialog](by-memory/0x0069ba34-0x0069ba38.g_pPowerDialog.md)
- [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)
- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md)
- [UID:0001F5][0x00549c20-0x0054a472.PowerDialogPaneConstructor](by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md)
- [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md)
- [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md)
- [UID:0000IE][Config](by-file/Config.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)

## Changes

- 2026-07-21 B002 UID0001PZ accepted callback:
  - Raised `85/90 -> 92/94`, retained owner/emitter UID0000MO and reconstructable true, set position `160`, and installed the exact sole definition `PowerDialogPane *g_pPowerDialog = NULL;`.
  - Added exact loader-zero physical backing, PE virtual-tail and payload-hash evidence, all five refs, `PowerDialogPane *` type/name, external declaration route, source order, compiler split, negative evidence, and one-definition policy.
  - Historical `0xffffffff`, `g_activePowerListPane`, blank-formal, unresolved declaration/linkage, private-list/config, and retained-wrapper blocker statements are preserved above with explicit supersession; none now blocks source emission.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `88`.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, and all 5 xrefs inside the power-dialog/list block; existing memory docs cover constructor, singleton helper, and list-control consumer behavior. Completion remains below full because final source-level global spelling is not proven.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000MO`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069ba34` and decompilation of `0x00549c20`, `0x0054a480`, `0x0054a4b0`, `0x0054b000`, and `0x0054b520` prove NexusTK-owned `PowerDialogPane` singleton storage owned by [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). No global-page C++ body was added because final declaration/linkage spelling is still a support-page cap; exact destructor/getter code now belongs on [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md), not this global page.
- 2026-06-16 C001 Goal 2 global/source-quality refresh:
  - Before: `84/88`, with exact singleton xrefs but stale generated-storage/byte wording and generated IDA lifecycle names.
  - Changed to: `85/90`; owner/emitter remain [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md), and reconstruction C++ remains blank.
  - Summary/evidence: live MCP reconfirmed current zeroed bytes, the five singleton refs, wrapper no-inbound-xref state, and power-dialog/list confinement; C001 saved four source-quality PowerDialogPane lifecycle/accessor function names. Remaining blockers are final global declaration spelling, packet-row/config field names, private list/control source split, and final treatment of the retained wrapper.
- 2026-06-26 B007 accepted [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) support sync:
  - Added that exact child [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md) now formally emits `PowerDialogPane::~PowerDialogPane()` and `PowerDialogPane::GetSingleton()` using `g_pPowerDialog`.
  - Summary/evidence: B007 MCP session `80de0a67` reconfirmed current zero bytes, five singleton references, confined PowerDialogPane/ListPane usage, and the rejection of `g_activePowerListPane`. The global page keeps blank C++ pending separate declaration/linkage policy.
