*** UID:0000RF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMainUiGraph

## Status

- Confidence: strong for address, initialized storage, main-UI-root role, login-success handoff, teardown clears, and broad consumer set; medium-high for exact concrete type and full layout.
- Address: `0x0067aba4`
- Storage: four-byte `.data` root pointer slot, initialized as `0xffffffff` bytes in the image.
- Proposed name: `g_pMainUiGraph`
- Main source owner: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- Memory storage page: [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md)

## Summary

`g_pMainUiGraph` is the global main UI graph/root object pointer used by pre-login dialogs, login-success handoff, post-login UI bootstrap, and teardown/attachment checks. The strongest current evidence is the login-success caller: `LoginDialogPane::OnServerMessage` loads the global root pointer immediately before calling [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f7d10`.

Current documentation refers to the initializer parameter as `MainUiGraph* uiGraph` and shows a provisional `loginNameCache[128]` field used by the user-status and login-name notification paths. Treat `g_pMainUiGraph` as the current working source name, but keep the full class/struct layout provisional until more fields are recovered.

## Evidence

- [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md) records the exact storage range as a reconstructable source-authored global pointer. Live IDA MCP `xrefs_to 0x0067aba4` on 2026-06-06 again reports 31 direct xrefs.
- A004 live IDA MCP on 2026-06-07 reconfirmed the exact storage child as all `0xff` image bytes and `xrefs_to 0x0067aba4` as 31 refs across 26 functions, including login/bootstrap handoff, setup, clear, dialog/control, and later screen/UI consumers.
- A004 live IDA MCP on 2026-06-07 verified `InitializeMainUiGraph_004F7D10` starts at `0x004f7d10`, has size `0xe1b`, and is followed by `sub_4F8B30` at `0x004f8b30`; its only executable caller remains `0x004fac9b` inside the login-success path.
- A004 live IDA MCP on 2026-06-07 cross-checked related MainUiGraph evidence: `MainUiLayerSlots` refs cover startup/setup/shutdown slots, `g_useEpfAssets` has broad layout-selector use, and map tile dimensions are referenced by `0x004f7d10`, keeping this global in the MainUiGraph source family.
- `get_bytes 0x0067aba4 size 4` returns `0xff 0xff 0xff 0xff`, matching image-initialized root-pointer storage.
- `0x004fac95` reads the global immediately before the direct call at `0x004fac9b` to `InitializeMainUiGraph`.
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) records the exact callee range, the single executable caller, and the root-pointer handoff into the initializer.
- `InitializeMainUiGraph_004F7D10` models the callee as taking the main UI graph/root pointer, uses the login-name cache in both new and old layout user-status paths, calls profile/input/ready helpers in the common tail, and adds the root to the pane/child registry.
- Live IDA MCP decompilation on 2026-06-06 confirms `0x004fa7a0` attaches login dialogs to the root pointer, `0x004f6490` reads it during broad UI cleanup, `0x005023d0` clears it in a compact clear helper, and `0x00502850` clears it in a scalar deleting destructor path.
- The 31 direct xrefs span login/account dialog attachment and packet handlers, main-menu/login-success handoff, cleanup and clear helpers, dialog/control consumers, and system-message/UI paths; these support a shared UI root pointer rather than ownership by a single login dialog.

## Known Role Boundaries

- Owns or points at the persistent post-login UI graph/root object.
- Carries at least the login-name cache consumed by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md).
- Is adjacent to browser/web-board dialog singleton storage in memory, but [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md) keeps it separate from that cluster.
- Should be sourced with [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), not with individual login dialog, account dialog, or browser dialog files.

## Open Questions

- Confirm the exact concrete type name for the root object stored at `0x0067aba4`.
- Separate graph/root ownership from nearby screen and UI-layer globals such as the `0x0067a7cc` ScreenPane singleton and [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md), which also appear in UI root/screen setup paths.
- Recover the field layout beyond the provisional `loginNameCache[128]` evidence consumed by `InitializeMainUiGraph` and user/status panes.
- Recover the constructor/bootstrap site that initially stores the root pointer, beyond the current attach/read/clear evidence.
- Finalize the concrete root object type and full layout before emitting reconstruction C++; current evidence supports global ownership and storage but not a 95/95 source declaration.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md)

## Changes

- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and a short summary that did not link the exact storage page.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:80`, an explicit storage-page link, expanded evidence, role boundaries, and live-IDA availability caveat.
  - Summary/evidence: exact by-memory storage page [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md), existing MainUiGraph/InitializeMainUiGraph docs, and IDA xref evidence support the address and root-object role. Score is capped because concrete type name, full field layout, and bootstrap storage site remain unresolved.
- 2026-06-05: Marked reconstructable under [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md). Evidence: live IDA MCP reports 31 xrefs to `0x0067aba4`; decompilation confirms dialog attachment reads, cleanup reads, and clear helpers at `0x005023d0` and `0x00502850` for the main UI graph root pointer.
- 2026-06-06 xref/cleanup pass:
  - What existed before: the page still carried raw storage labels and stayed at `78/80` despite exact storage, initialized bytes, broad xrefs, login-success handoff, and teardown clears being documented.
  - Changed to: completion `84`, confidence `86`, source-facing global wording, initialized storage evidence, refreshed 31-xref summary, and clearer unresolved type/layout boundaries.
  - Summary/evidence: live IDA MCP `xrefs_to`, `get_bytes`, `lookup_funcs`, and `decompile` on 2026-06-06 confirm exact storage, initialized bytes, 31 direct xrefs, login-success handoff into `InitializeMainUiGraph`, login dialog attachment reads, cleanup reads, compact clear helper, and scalar deleting destructor clear. No final C++ body was added because the concrete root type and full field layout remain below the 95/95 reconstruction gate.
- 2026-06-07 A004 Batch 036 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`, assigned to [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md).
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, retained direct parent [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md).
  - Summary/evidence: live IDA MCP reconfirmed the exact storage child [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md), 31 refs across 26 functions, sole initializer caller, `0x004f7d10`/`0x004f8b30` function boundary, and related MainUiGraph slot/layout evidence. The direct file parent was refreshed to `86/86`, satisfying the corrected child-and-parent assignment gate for the exact storage child.
