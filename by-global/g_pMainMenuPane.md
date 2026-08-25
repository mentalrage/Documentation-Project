*** UID:0000RF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern MainMenuPane *g_pMainMenuPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMainMenuPane

## 2026-08-14 B003 Header Declaration Closure

- The global keeps its existing CPP child route and now appends exact `extern MainMenuPane *g_pMainMenuPane;` to generated MainMenuPane H. UID00007O supplies the complete class declaration first.
- ChangePasswordDialogPane uses this pointer as the OnShow ordering anchor. Ownership and `92/94` metadata remain UID0000RF/UID0000L0.
- Emitter position `10` places the extern after UID00007O's complete class, avoiding a declaration-before-type generated header.

## Status

- Confidence: high for address, zero initialization, concrete `MainMenuPane *` type, external linkage, lifetime, owner, and consumers.
- Address: `0x0067aba4`
- Storage: four-byte zero-filled `.data` pointer slot (`00 00 00 00`; SHA-256 `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119`).
- Accepted source name and type: `MainMenuPane *g_pMainMenuPane`
- Main source owner/emitter: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- Position: `0`, before the class-owned method children.
- Memory storage page: [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainMenuPane](by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md)

## Summary

`g_pMainMenuPane` is the external singleton pointer for the concrete `MainMenuPane` object. `MainMenuPane::MainMenuPane` stores `this` at `0x0067aba4`, menu/dialog paths consume that object, and shutdown clears the slot. The login-success caller loads the pointer as the `this` receiver immediately before calling [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md).

The former `g_pMainUiGraph` name and `MainUiGraph` ownership were working aliases based on the initializer's breadth. Constructor assignment, receiver use, object layout, and clear behavior now resolve the concrete type and source home. The graph support module remains a dependency but does not own or emit this global.

## Evidence

- [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainMenuPane](by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md) records the exact storage range and destination-specific definition. Live IDA MCP reports 31 direct references across 26 functions.
- Current bounded byte evidence resolves the exact slot as four zero bytes. The earlier all-`0xff` statement is preserved only as superseded evidence-time history.
- A004 live IDA MCP on 2026-06-07 verified `InitializeMainUiGraph_004F7D10` starts at `0x004f7d10`, has size `0xe1b`, and is followed by `sub_4F8B30` at `0x004f8b30`; its only executable caller remains `0x004fac9b` inside the login-success path.
- A004 live IDA MCP on 2026-06-07 cross-checked related support evidence: [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) refs cover startup/setup/shutdown slots, `g_useEpfAssets` has broad layout-selector use, and map tile dimensions are referenced by `0x004f7d10`. These are method dependencies; they do not move the global out of `MainMenuPane.cpp`.
- Constructor assignment at `0x004f6751`/`0x004f6758`, clear at `0x004f6979`, and the consumer spread establish conventional null-initialized singleton lifetime and external linkage.
- `0x004fac95` reads the global immediately before the direct call at `0x004fac9b` to `InitializeMainUiGraph`.
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) records the complete `MainMenuPane::InitializeMainUiGraph` source, exact callee range, and single executable caller.
- Evidence-time B011 MCP session `80de0a67` on 2026-06-26 rechecked the same handoff under the then-current `g_pMainUiGraph` alias: `0x004fac95` loads `0x0067aba4` into `ecx`, `0x004fac9b` calls UID00019K through alias/index UID0000UV, and `xrefs_to 0x004f7d10` reports that caller as the sole executable route. Its pointer-pattern negatives still prove a direct login-success handoff rather than table dispatch.
- Historical alias/index UID0000UV originally modeled a graph/root pointer. Exact UID00019K now proves a `MainMenuPane` receiver, uses `m_serverName[128]` in both layout branches, and performs the accepted profile/input/music/session common tail.
- Live IDA MCP decompilation on 2026-06-06 confirms `0x004fa7a0` attaches login dialogs to the root pointer, `0x004f6490` reads it during broad UI cleanup, `0x005023d0` clears it in a compact clear helper, and `0x00502850` clears it in a scalar deleting destructor path.
- The 31 direct xrefs span login/account dialog attachment and packet handlers, main-menu/login-success handoff, cleanup and clear helpers, dialog/control consumers, and system-message/UI paths; these support a shared UI root pointer rather than ownership by a single login dialog.

## Known Role Boundaries

- Points at the persistent `MainMenuPane` object that coordinates post-login UI initialization and menu-owned dialogs.
- Is adjacent to browser/web-board singleton storage but is not part of that cluster.
- Is distinct from the unrelated `0x0069b36c` UI-layer/context global.
- Is defined with [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md); [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) is support only.

## Resolved Questions

- Concrete type: `MainMenuPane *`, proved by constructor assignment and method receiver use.
- Definition: external null-initialized global, emitted through its exact storage child.
- Source placement: `MainMenuPane.cpp`, before class-owned methods.
- Lifetime: constructor assignment, shared consumers, and shutdown clear; no ownership transfer to `MainUiGraph` or adjacent browser storage.

## Cross-References

- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) (support only)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainMenuPane](by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md)

## Changes

- 2026-07-14 B002 callback: UID-preserving rename from historical `g_pMainUiGraph` to `g_pMainMenuPane`; moved ownership/emission to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), set position `0`, installed `[[CHILDREN]]`, raised to `92/94`, and synchronized exact zero-fill, concrete type, linkage, lifetime, caller, boundary, and rejected-alternative evidence.
- Historical note: all older entries below describe the superseded `g_pMainUiGraph`/`MainUiGraph` route and evidence-time `0xffffffff` reading. They remain for provenance and are not current source-facing recommendations.

- 2026-06-26 B011 handoff recheck: added current MCP session `80de0a67` evidence that `0x004fac95` loads `g_pMainUiGraph` immediately before the sole `0x004fac9b` call to [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md), with pointer-route negatives for the initializer start/end/successor. Score stays `86/88` because the concrete root type, full layout, and initial storage site remain open.
- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and a short summary that did not link the exact storage page.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:80`, an explicit storage-page link, expanded evidence, role boundaries, and live-IDA availability caveat.
- Historical summary/evidence: exact storage UID0002AF, then-current MainUiGraph/InitializeMainUiGraph docs, and IDA xrefs supported the address/root role under the old name. Current storage path is [0x0067aba4-0x0067aba8.g_pMainMenuPane](by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md); concrete type and storage site are now resolved.
- 2026-06-05: Marked reconstructable under [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md). Evidence: live IDA MCP reports 31 xrefs to `0x0067aba4`; decompilation confirms dialog attachment reads, cleanup reads, and clear helpers at `0x005023d0` and `0x00502850` for the main UI graph root pointer.
- 2026-06-06 xref/cleanup pass:
  - What existed before: the page still carried raw storage labels and stayed at `78/80` despite exact storage, initialized bytes, broad xrefs, login-success handoff, and teardown clears being documented.
  - Changed to: completion `84`, confidence `86`, source-facing global wording, initialized storage evidence, refreshed 31-xref summary, and clearer unresolved type/layout boundaries.
  - Summary/evidence: live IDA MCP `xrefs_to`, `get_bytes`, `lookup_funcs`, and `decompile` on 2026-06-06 confirm exact storage, initialized bytes, 31 direct xrefs, login-success handoff into `InitializeMainUiGraph`, login dialog attachment reads, cleanup reads, compact clear helper, and scalar deleting destructor clear. No final C++ body was added because the concrete root type and full field layout remain below the 95/95 reconstruction gate.
- 2026-06-07 A004 Batch 036 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`, assigned to [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md).
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, retained direct parent [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md).
- Historical summary/evidence: live IDA MCP reconfirmed exact storage UID0002AF, 31 refs across 26 functions, sole initializer caller, `0x004f7d10`/`0x004f8b30` boundary, and related layer/layout evidence under the old route. Current storage path is [0x0067aba4-0x0067aba8.g_pMainMenuPane](by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md), and current file ownership is MainMenuPane.
