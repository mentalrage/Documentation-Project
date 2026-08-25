*** UID:00002I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanLeaveConfirmDialog : public AlertPane
{
public:
    ClanLeaveConfirmDialog(const wchar_t *messageText,
                           Pane *layoutReference,
                           const wchar_t *primaryButtonText,
                           const wchar_t *secondaryButtonText);

protected:
    virtual void OnConfirm();
    virtual void OnCancel();
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanLeaveConfirmDialog

## Status

- Confidence: very strong for the exact four-argument constructor, void confirm/cancel behavior, vtable identity, child pages, and Clan source placement; absent raw-entry reachability remains a bounded confidence caveat.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Reconstruction parent: [UID:0000I8][Clan](by-file/Clan.md)

## Score Rationale

- Completion is `92` because the class has a complete formal H declaration, an exact emitted constructor child, both virtual callback definitions, live packet-helper behavior, vtable slot evidence, current local PE no-reference scans, and a verified Clan source/emitter route.
- Confidence is `93` because current IDA-backed evidence and local PE evidence agree on callback functions, vtable slots, helper constants, packet bytes, constructor byte stores, and the absent raw-entry route. The remaining entry-reachability and lexical uncertainty is a confidence cap, not a reason to omit the accepted declaration or constructor body.

## Class Purpose

`ClanLeaveConfirmDialog` is an `AlertPane`-derived confirmation dialog for leaving a clan. Its confirm and cancel callbacks send the corresponding accept/cancel byte through `g_pClanStatusPane->SendClanLeaveResponse(true/false)`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanLeaveConfirmDialog(const wchar_t *, Pane *, const wchar_t *, const wchar_t *)` | [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md) | Exact out-of-line constructor forwards four arguments to `AlertPane`, installs three derived vtables, returns `this`, and uses `retn 0x10`; absent raw-entry refs do not suppress its CPP definition. |

## 2026-08-14 Callback Resolution

- Metadata is `92/93`; owner/emitter remain UID0000I8.
- The corrected four-argument class declaration moved from CPP to H; CPP now contains only `[[CHILDREN]]`.
- UID0002O6 emits the AlertPane-forwarding constructor definition. UID0002O7 and UID0002O8 retain formal `void OnConfirm()` / `void OnCancel()` definitions because both call the decompiled void `SendClanLeaveResponse` method and have no source return contract.
- Historical default-constructor and no-body statements below are superseded but retained as the earlier assumption trail.
| `OnConfirm` | [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md) | Calls [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) as `g_pClanStatusPane->SendClanLeaveResponse(true)`. |
| `OnCancel` | [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md) | Calls [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) as `g_pClanStatusPane->SendClanLeaveResponse(false)`. |

## Evidence Notes

- IDA confirms `OnConfirm` and `OnCancel`.
- IDA confirms `SendClanLeaveResponse` at `0x00485700`, with callers from both callbacks.
- 2026-06-05 IDA MCP executable identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- 2026-06-05 IDA MCP recheck confirms [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) sends exactly four bytes `{0x4b, 3, 1, response}` through the shared packet sender at `0x0067a7ec`; `OnConfirm` passes `1` and `OnCancel` passes `0`.
- 2026-06-05 IDA MCP lookup reports no function at `0x0048a060`, functions at `0x0048a0a0` and `0x0048a0b0` sized `0x0e`, [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) size `0x79`, and the [UID:00000B][AlertPane](by-class/AlertPane.md) constructor at `0x0049feb0` size `0x6c5`.
- 2026-06-05 bounded disassembly reconfirms seven `0xcc` bytes before the constructor-shaped range, two `0xcc` bytes between each child range, and two `0xcc` bytes before the following `ClanItemDialog` body.
- 2026-06-05 IDA MCP xref search reports no inbound code/data refs and no raw pointer hits to `0x0048a060`; the constructor-shaped body still calls `0x0049feb0` and stores vtables `0x00615f38`, `0x00615fa0`, and `0x00615fd0` into the primary object and `+0xa0`/`+0xa4` subobjects.
- 2026-06-05 vtable evidence places confirm/cancel at slots `0x00615f94` and `0x00615f98`; those slots point to `0x0048a0a0` and `0x0048a0b0`, while vtable base refs come from clan status packet setup sites and the raw constructor stores.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x0048a060`. Disassembly at the projected start calls `AlertPane` constructor `0x0049feb0` and stores `0x00615f38` at `0x0048a07b`, `0x00615fa0` at `0x0048a083`, and `0x00615fd0` at `0x0048a08d`, so keep it as constructor-shaped bytes pending boundary cleanup.
- 2026-05-31 IDA MCP split the constructor-shaped body and callbacks into exact child pages. `lookup_funcs` reports no function at `0x0048a060`, callback functions at `0x0048a0a0` and `0x0048a0b0` sized `0x0e`, vtable data xrefs at `0x00615f94` and `0x00615f98`, both callbacks calling `0x00485700`, constants `1` and `0` in decompilation, and padding around the child ranges.
- 2026-06-15 A002 refresh: Wave2 `method/decomp/xrefs` reports an included zero-caller `ClanLeaveConfirmDialog` constructor record at `0x0048a060`, size `62`, with one callee `0x0049feb0`, no data refs, and grade `93.5`; the method-name control-character caveat keeps Wave2 below final naming authority.
- Wave2 `filter --class ClanLeaveConfirmDialog --all-methods` lists `OnConfirm`, `OnCancel`, and the constructor; Wave2 `struct ClanLeaveConfirmDialog` shows only an `AlertPane` base at offset `0`.
- 2026-06-15 live IDA reconfirmed no function at `0x0048a060`/`0x0048a09e`, no raw-start xrefs, confirm/cancel vtable cells `0x00615f94`/`0x00615f98`, exact constructor/callback bytes, and vtable-store refs. Local PE scans found no VA/RVA pointer bytes or relative branch/call targets to `0x0048a060`.
- 2026-06-17 B002 source-quality pass confirms [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md) and [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md) are first-draft C++ ready as `OnConfirm()` and `OnCancel()`: the raw bytes load `g_pClanStatusPane`, push response byte `1` or `0`, call `SendClanLeaveResponse`, and return. The callbacks reject base `AlertPane`, ClanBank/item-dialog ownership, and pure local close/no-packet interpretations.
- 2026-06-19 B014 source-quality reanalysis updates the callback call shape to `g_pClanStatusPane->SendClanLeaveResponse(true/false)`: the raw bytes still load `g_pClanStatusPane`, push `1` or `0`, call [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md), and return, but the callee is now documented as [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)-owned because both callsites use the receiver register.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md)
- [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md)
- [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md)

## Changes

The entries below are dated historical changes. Older scores, blank-C++ statements, and no-route-comment-only conclusions are superseded by the current `92/93` metadata and the 2026-08-14 formal H/CPP route above.

- 2026-06-15 A002 parent-gate refresh:
  - What existed before: metadata was `82/88`; the class already had exact child pages but lacked current Wave2/local no-reference evidence.
  - Changed to: metadata is `85/89`; owner/emitter remain [UID:0000I8][Clan](by-file/Clan.md); final C++ remains blank.
  - Summary/evidence: added Wave2 included zero-caller constructor support, Wave2 callback/base-layout confirmation, and the refreshed [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md) IDA/local PE no-reference pass. The class now clears the direct-parent gate for the raw constructor, but final source declaration/code remains blocked by constructor reachability and source-name quality.
- 2026-06-17 B002 source-quality pass: class score unchanged, but the vtable-backed callback children now carry first-draft C++ at `88/93`; the remaining class-level cap is the no-function/no-xref raw constructor path, not the confirm/cancel callback behavior.
- 2026-06-19 B014 Rule 26 support sync: class score unchanged, but callback wording and child C++ now call `g_pClanStatusPane->SendClanLeaveResponse(true/false)` after [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) was promoted from a loose Clan helper to [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)-owned packet helper.
- What existed before: the page documented confirm/cancel behavior, leave-response helper linkage, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were initially set to `66/76`.
- Summary and evidence: confirm/cancel callbacks and vtable identity are clear; constructor reachability, full alert layout, and final source form remain unresolved.
- 2026-05-31: Replaced raw address/projection entries with exact child pages and marked the class reconstructable but unassigned.
  - Before: the method table listed projected constructor `0x0048a060`, confirm `0x0048a0a0-0x0048a0ad`, and cancel `0x0048a0b0-0x0048a0bd` without exact child-page links.
  - After: the page links [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md), [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md), and [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md), with scores raised to `74/84`.
  - Summary and evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, decompilation, raw constructor disassembly, and byte audit confirm exact child boundaries, vtable ownership, leave-response constants, and surrounding padding.
- 2026-06-05: Added exact leave-response packet evidence.
  - Before: the page recorded only that confirm/cancel call `SendClanLeaveResponse` with constants `1` and `0`.
  - After: the evidence notes record the helper's exact four-byte packet body and shared sender call.
  - Evidence: live IDA MCP decompilation of `0x00485700`, `0x0048a0a0`, and `0x0048a0b0`.
- 2026-06-05: Raised class coverage and attached the class to the Clan source parent.
  - Before: metadata was `74/84` with a blank parent and a stale source-lead path listed as if it were current recovery evidence.
  - After: metadata is `82/88`, `AUTOGEN_PARENT_UID` is [UID:0000I8][Clan](by-file/Clan.md), the stale source-lead path is removed, and the evidence now records executable identity, child sizes, vtable slots, constructor no-xref status, and packet bytes from live IDA MCP.
  - Evidence: IDA MCP `idb_meta`, `lookup_funcs`, `callers`, `callees`, `xrefs_to`, decompilation, and bounded disassembly/pointer search on `0x0048a059-0x0048a0c0`, `0x00485700`, and `0x0049feb0`.
