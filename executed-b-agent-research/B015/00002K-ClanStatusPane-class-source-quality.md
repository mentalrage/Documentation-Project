** TARGET-REPORT-UID:00002K **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B015 Source-Quality Report: [UID:00002K] ClanStatusPane

Assignment: `B015` report-only correction for [UID:00002K] `by-class/ClanStatusPane.md`.

Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\ClanStatusPane.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\00002K-ClanStatusPane-class-source-quality.md`

No by-* documentation files were edited in this pass. `by-memory/-coverage-report.md` was not edited.

## Executive Recommendation

Raise [UID:00002K] `ClanStatusPane` from `85/86` to `87/89` after incorporating this report. Keep:

- `CANONICAL_OWNER:0000I8`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000I8`
- target-level `RECONSTRUCTION_CPP` blank

Best source placement is still [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp`. The class is a source-declared class and method-emitter container, not a single source function. Its child methods and helpers should emit C++ only on method pages that have stable names/types/source routes. Do not add a class-page C++ body.

The class-level open questions are now narrow and explicitly bounded:

- The full private object layout is strongly inferred for the documented clan status fields, but not final for every inherited/base subobject byte.
- Child-pane virtual slots `+0x30`, `+0x38`, `+0x3c`, and `+0x40` are behaviorally understood but not source-named across the wider `Pane`/`ListPane`/`TextEditPane` family.
- Some packet action labels are server-side semantics rather than client-source names. Use descriptive packet names where the UI meaning is not proven.
- Raw no-xref helper bodies are real source-shaped bytes, but direct reachability is negative; keep their C++ blank unless a later split/source-route pass proves how the original source referenced them.

## Evidence Checked

Primary target and source-placement docs:

- `by-class/ClanStatusPane.md`
- `by-file/Clan.md`
- `by-project-structure/proposed-source-tree.md`
- `by-global/g_pClanStatusPane.md`
- `by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md`

Direct child/support docs checked:

- [UID:00010A] `0x00484030-0x00484221.ClanStatusPaneConstructor.md`
- [UID:00021B] `0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md`
- [UID:00010B] `0x004842b0-0x00484a50.ClanAttributePacketParser.md`
- [UID:00010C] `0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md`
- [UID:00021C] `0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md`
- [UID:00021K] `0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md`
- [UID:00010G] `0x00486800-0x00487291.ClanStatusPaneRows.md`
- [UID:00021N] `0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md`
- [UID:00021O] `0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md`
- [UID:00021P] `0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md`
- [UID:00021Q] `0x00487480-0x00487535.ClanStatusPaneShowJoinList.md`
- [UID:00021R] `0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md`
- [UID:00010H] `0x00487600-0x0048779f.ClanStatusRowActionPacket.md`
- [UID:00021S] `0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md`
- [UID:00021U] `0x00488900-0x00488b3d.ClanListPaneInputHandlers.md`
- [UID:00030O] `0x0048c32b-0x0048c341.ClanStatusPaneDestructorAdjustorThunks.md`
- [UID:00030P] `0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md`
- [UID:0002MQ] `0x00615570-0x006158f4.ClanPaneListVtableData.md`
- [UID:0003B8] `0x006163dc-0x00616430.ClanStatusResourceStrings.md`

Child class docs checked:

- `by-class/ClanInfoListPane.md`
- `by-class/ClanJoinListPane.md`
- `by-class/ClanEnlistListPane.md`

Coverage/support reports checked:

- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `project-level/-auto-completion-stats.md`

Existing accepted B-agent reports used as leads and revalidated against current docs/raw scan:

- `research/executed/00021K-ClanSubtype6PacketHelpers-source-quality.md`
- `research/00021U-ClanListPaneInputHandlers-source-quality.md`

Raw PE baseline:

- PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- Sections observed: `.text` at `0x00401000`, `.rdata` at `0x0060d000`, `.data` at `0x0066d000`, `.rsrc` at `0x0069d000`

Local PE rel32/direct-pointer scan results relevant to this class:

| Target | Rel32 hits | Exact VA pointer hits | Meaning |
| --- | --- | --- | --- |
| `0x004872e0` | none | none | `IsRowActionAllowed` remains raw/no direct route. |
| `0x00487370` | `0x004848d6`, `0x00484d79` | none | `RefreshChildPanes` has exactly parser and key-input direct callers. |
| `0x004873c0` | none | none | `ShowInfoList` remains raw/no direct route. |
| `0x00487480` | none | none | `ShowJoinList` remains raw/no direct route. |
| `0x00487540` | none | none | `ShowEnlistList` remains raw/no direct route. |
| `0x00487600` | `0x00484e91` | none | row-action packet helper has one `OnMouseEvent` caller. |
| `0x004877d0` | `0x00484fdb` | none | dispatcher case 1 calls live handler. |
| `0x004879e0` | `0x00484fec` | none | dispatcher case 2 calls live handler. |
| `0x00487ea0` | `0x00485181` | none | dispatcher case 6 calls live handler. |
| `0x00485960` | `0x004876b6`, `0x00488aec` | none | subtype 6 action 0 helper has row-action and enlist key-action callers. |
| `0x004859d0` | `0x0048898a`, `0x00488b09` | none | subtype 6 action 1 helper has selected-row and Enter callers. |
| `0x00488900` | none | `0x006157d4` | join-list input handler is vtable-only. |
| `0x00488970` | none | `0x006158b0` | enlist selected-row action is vtable-only. |
| `0x004889a0` | none | `0x00615898` | enlist input handler is vtable-only. |
| `0x0048c590` | `0x0048c331`, `0x0048c33c` | `0x00615570` | scalar deleting destructor reached by adjustor thunks and primary vtable. |
| `0x0048c32b` | none | `0x006155bc` | secondary destructor thunk is vtable-only compiler glue. |
| `0x0048c336` | none | `0x006155ec` | tertiary destructor thunk is vtable-only compiler glue. |

Raw padding bytes confirmed:

| Range | Bytes |
| --- | --- |
| `0x004873b6-0x004873c0` | `cc cc cc cc cc cc cc cc cc cc` |
| `0x00487476-0x00487480` | `cc cc cc cc cc cc cc cc cc cc` |
| `0x00487536-0x00487540` | `cc cc cc cc cc cc cc cc cc cc` |
| `0x004875f6-0x00487600` | `cc cc cc cc cc cc cc cc cc cc` |
| `0x004859c9-0x004859d0` | `cc cc cc cc cc cc cc` |
| `0x00485abe-0x00485ac0` | `cc cc` |
| `0x00488968-0x00488970` | `cc cc cc cc cc cc cc cc` |
| `0x00488991-0x004889a0` | `cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc` |

Resource string bytes at `0x006163dc` decode as full UTF-16 strings `CLAN1.EPF`, `CLAN2.EPF`, `CLAN3.EPF`, and `CLANBUT.EPF`. The old `AN*` labels are interior IDA suffix labels, not source resource names.

## Exact Range And Reachability Findings

`ClanStatusPane` is not one contiguous code range. It is a class page whose executable behavior is distributed across constructor/parser/frame/input/row/packet/view/destructor children and vtable data.

Stable class anchors:

| Anchor | Evidence | Decision |
| --- | --- | --- |
| Class source file | [UID:0000I8] `Clan` is `90/85` and proposed source tree places clan status/list/dialog helpers under `NexusTK/social/Clan.cpp`. | Keep direct class owner/source route through `Clan.cpp`. |
| Singleton | `g_pClanStatusPane` at `0x0067ade4`, constructor writes `this`, destructor and cleanup clear it, list-pane handlers load it before `ClanStatusPane` packet helpers. | Field/global name is source-quality: `g_pClanStatusPane`. |
| Vtables | `ClanStatusPane` primary/secondary/tertiary vtables at `0x00615570`, `0x006155bc`, `0x006155ec`; constructor/destructor stores and slot refs match class methods. | Vtable data supports normal multiple-inheritance class declaration, not handwritten vtable arrays. |
| Resource strings | Full strings at `0x006163dc-0x00616430` used from `OnPaintFrame`. | Source-facing resources are `CLAN1.EPF`, `CLAN2.EPF`, `CLAN3.EPF`, `CLANBUT.EPF`. |
| Destructor support | `0x0048c32b` and `0x0048c336` are adjustor thunks into `0x0048c590`; `0x0048c590` restores vtables, deletes children, clears singleton. | Thunks remain non-reconstructable compiler glue; destructor body is class-owned but should later be represented as ordinary `~ClanStatusPane()`, not scalar-delete wrapper source. |

## Best Source-Facing Names And Types

### Class And Source Route

Best class name: `ClanStatusPane`.

Best source route: `NexusTK/social/Clan.cpp` under [UID:0000I8] `Clan`.

Rejected routes:

- `ClanDialogs.cpp`: rejected because the target owns the visible clan status panel, child list/info panes, opcode `0x43` dispatcher, and opcode `0x4b` status row packet helpers. Dialog classes are constructed by this path but are not the owner of the pane.
- `ClanBank.cpp`: rejected because `ClanBankPane`, item-list classes, and bank packet helpers are split separately under [UID:0000I9] `ClanBank`; this class uses status/list/enlist UI state, not bank item state.
- Generic UI source: rejected because resource strings, singleton slot, packet opcodes, and child classes are clan-specific.

### Fields

These names are best-supported and should be used consistently in the class page and child pages:

| Offset | Best name/type | Evidence |
| --- | --- | --- |
| `+0xf8` | `unsigned char m_currentClanStatusView` | Parser/frame/row/view helpers use values `0` status actions, `1` management actions, `2` info child, `3` join child, `4` enlist child. |
| `+0xf9` | `unsigned char m_statusDataVersion` | Parser writes packet version/status data version; row eligibility uses thresholds `< 1`, `!= 0`, `< 2`. |
| `+0xfa` | `short m_selectedStatusRow` or `char/short m_selectedStatusRow` | Frame/input stores hit-tested row selection. Exact storage width should remain cautious because docs mention byte offset but row inputs are signed 16-bit. Use `m_selectedStatusRow` without overcommitting in prose unless the child page proves width. |
| `+0xfe` | `wchar_t m_statusHeaderText[40]` | Parser and handlers copy a 40-wide-character heading/name; row `0` display uses it. |
| `+0x14e` | `unsigned short m_rawAttributeDataLength` | Constructor clears it; parser reads big-endian length and copies raw attribute blob. |
| `+0x150` | `unsigned char m_rawAttributeData[]` | Parser copies raw attribute payload after the length. Exact array bound should wait on full object layout. |
| `+0x2150/+0x21a0/+0x21f0/+0x2240/+0x2290` | `wchar_t m_statusActionText[5][40]` | Rows `2..6`, outbound subtypes `1..5`. |
| `+0x22e0/+0x2330/+0x2380/+0x23d0/+0x2420/+0x2470/+0x24c0` | `wchar_t m_managementActionText[7][40]` | Rows `7..13`, outbound subtypes `6..12`; parser reads order `7,8,12,13,11,9,10` then stores in address-order fields. |
| `+0x2510` | `ClanInfoListPane *m_infoListPane` | Constructor allocates info child; show/refresh/dialog handlers use it. |
| `+0x2514` | `ClanJoinListPane *m_joinListPane` | Constructor allocates join-list child; show/refresh/join-list packet handler uses it. |
| `+0x2518` | `ClanEnlistListPane *m_enlistListPane` | Constructor allocates enlist-list child; show/refresh/subtype 6 handler uses it. |

Do not use raw labels such as `byte_`, `dword_`, `sub_`, `field_2510`, or `statusDataByte` in final prose when one of the above names applies.

### Packet Helpers And Actions

Inbound opcode `0x43` is the clan status packet family handled by `ClanStatusPane::OnClanStatusPacket` / `DispatchClanStatusPacket`.

| Subtype | Best descriptive handler/action | Evidence and caveat |
| --- | --- | --- |
| `0` | `ParseClanStatusAttributePacket` | Direct parser call; fills header, raw attributes, and row labels. |
| `1` | `HandleClanEnlistRequestPacket` or `HandleClanStatusInfoRequestPacket` | Direct call to `0x004877d0`; decodes clan name/request text, fills info child, view `2`. Existing docs prefer `HandleClanEnlistRequestPacket`; retain unless future server text proves a better user-facing name. |
| `2` | `HandleClanJoinListPacket` | Direct call to `0x004879e0`; action `0` fills `m_joinListPane`, view `3`. |
| `3` | leave confirm packet branch | Dispatcher inlines equivalent dialog construction; retained helper sibling has no direct route. |
| `4` | deposit money packet branch | Inline dispatcher branch; retained helper sibling no direct route. |
| `5` | deposit item packet branch | Inline dispatcher branch; retained helper sibling no direct route. |
| `6` | `HandleClanEnlistPacket` / `HandleClanMemberListOrEnlistDialogPacket` | Direct call to `0x00487ea0`; action `0` fills `m_enlistListPane`, action `1` opens `ClanEnlistInputDialog`, action `2` returns success. Existing report name with `MemberListOrEnlistDialog` is behavior-complete; class page can use shorter `HandleClanEnlistPacket` with the action detail. |
| `7` | expel dialog packet branch | Inline dispatcher branch; retained opener no direct route. |
| `8` | summon dialog packet branch | Inline dispatcher branch; retained opener no direct route. |
| `9` | appear dialog packet branch | Inline dispatcher branch; retained opener no direct route. |
| `10` | change name/attributes packet branch | Inline dispatcher branch; retained opener no direct route. |
| `11` | withdraw money packet branch | Inline dispatcher branch; retained opener no direct route. |
| `12` | withdraw item packet branch | Inline dispatcher branch; retained opener no direct route. |

Outbound opcode `0x4b` is the clan status action/request packet family.

| UI row/path | Packet | Best name |
| --- | --- | --- |
| Row `2` | `{0x4b, 1, 0}` | status action subtype 1 request; do not invent server-side label. |
| Row `3` | `{0x4b, 2, 0}` | join-list open/request path. |
| Row `4` | `{0x4b, 3, 0}` | leave confirm request path. |
| Row `5` | `{0x4b, 4, 0}` | deposit money request path. |
| Row `6` | `{0x4b, 5, 0}` | deposit item request path. |
| Row `7` | `ClanStatusPane::SendClanEnlistListRefreshPacket()` -> `{0x4b, 6, 0}` | enlist-list request/refresh. |
| Rows `8..13` | `{0x4b, 7..12, 0}` | management action requests; specific server labels follow dispatcher subtype names. |
| Enlist selected row / Enter | `ClanStatusPane::SendClanEnlistListSelectionPacket(const wchar_t *applicantName)` -> `{0x4b, 6, 1, len, name...}` | selected applicant/list row submission. |
| Enlist key code `0x84` | inline `{0x4b, 6, 3, len, name...}`, then action `0` refresh | best descriptive name is `enlist-list action 3 selected-name packet`; do not rename to accept/approve/reject/delete without UI/server proof. |
| Enlist input dialog submit | subtype `6`, action `2` with three strings and one 16-bit value | separate `SendClanAttributePacket` / enlistment attribute submit path, not part of [UID:00021K]. |

## Method Family Reanalysis

### Constructor, Cleanup, Parser

`ClanStatusPane::ClanStatusPane()` is already first-draft C++ ready on [UID:00010A]. It establishes the key class fields:

- `Pane(1)` base initialization.
- `g_pClanStatusPane = this`.
- Allocates and installs `ClanInfoListPane`, `ClanJoinListPane`, and `ClanEnlistListPane`.
- Stores child pointers at `+0x2510`, `+0x2514`, `+0x2518`.
- Calls `Pane::SetMode(1)` on the children.
- Applies `TextEditPane` read-only/inactive setup for the info child.
- Clears `m_rawAttributeDataLength`.

[UID:00021B] is compiler cleanup/unwind support for partially constructed children. It should remain non-reconstructable and should not be represented as handwritten source.

`ParseClanStatusAttributePacket` on [UID:00010B] is already first-draft C++ ready and should remain class-owned. It is the strongest evidence for the fixed text slots and `m_statusDataVersion`.

### Frame/Input And Row Helpers

[UID:00010C] is a mixed virtual-method band:

- `0x00484a60-0x00484cb0`: `OnPaintFrame`
- `0x00484cd0-0x00484da2`: `OnKeyInput`
- `0x00484db0-0x00484f16`: `OnMouseEvent`

Keep the aggregate C++ blank. Split into child method pages before emitting source. The current blockers are exact event/control types, inherited virtual slot names, and helper names for paint/resource/rectangle APIs.

Best source names:

- `OnPaintFrame`
- `OnKeyInput`
- `OnMouseEvent`

Best resource names:

- `CLAN1.EPF`
- `CLAN2.EPF`
- `CLAN3.EPF`
- `CLANBUT.EPF`

Reject `AN1.EPF`, `AN2.EPF`, `AN3.EPF`, and `ANBUT.EPF` as source names. They are suffix labels inside full strings.

[UID:00010G] is also a mixed row-helper aggregate:

- `DrawStatusRowText`
- `GetStatusRowRect`
- `HitTestStatusRow`

Keep aggregate C++ blank until it is split or until a single source-level helper boundary is proven. The row/storage mapping is stable enough for prose and field naming, but not enough to emit a combined method cluster.

### Row Eligibility

[UID:00021N] should be promoted from file-owned `0000I8` to direct class owner/emitter `00002K` in a later implementation callback:

- Recommended `CANONICAL_OWNER:00002K`
- Recommended `EMITTER_UIDS:00002K`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep C++ blank
- Keep score `85/90`

Rationale: the body reads `m_currentClanStatusView` (`+0xf8`) and `m_statusDataVersion` (`+0xf9`) and is placed between the class row helpers and class view helpers. Raw PE scanning found no direct call or exact pointer route, so direct source reachability is still negative. That no-route fact is a C++ blocker, not a reason to leave it file-owned.

Best descriptive name: `ClanStatusPane::IsRowActionAllowed`.

Rejected names:

- `sub_4872e0`: raw placeholder.
- `CanClickRow`: too UI-specific and not proven.
- `IsManagementRowEnabled`: too narrow; the switch covers status rows, management rows, and tab rows.

### Refresh And Show Helpers

[UID:00021O] `ClanStatusPane::RefreshChildPanes` is a real modeled function with direct calls from the parser and `OnKeyInput`. It should remain direct class-owned/emitted through `00002K`, but C++ should remain blank until child virtual slots are named.

Best behavior summary:

- Calls child vtable `+0x38`, then `+0x40`, for `m_joinListPane`, `m_infoListPane`, and `m_enlistListPane`.
- Final child `+0x40` dispatch is tail-jumped.
- No direct callees appear because all work is indirect vtable dispatch.

[UID:00021P], [UID:00021Q], and [UID:00021R] are raw no-xref siblings:

| Helper | View byte | Selected child | Range |
| --- | ---: | --- | --- |
| `ShowInfoList` | `2` | `m_infoListPane` (`+0x2510`) | `0x004873c0-0x00487475` |
| `ShowJoinList` | `3` | `m_joinListPane` (`+0x2514`) | `0x00487480-0x00487535` |
| `ShowEnlistList` | `4` | `m_enlistListPane` (`+0x2518`) | `0x00487540-0x004875f5` |

All three helpers:

- Have no modeled function object and no inbound direct route in the local PE scan.
- Repeat the child refresh sequence inline rather than calling `0x00487370`.
- Use rectangle constants `0x12, 0x47, 0xae, 0x107`.
- Configure the selected child through child virtual slots `+0x30` and `+0x3c`.
- Invalidate the owner via receiver offset `+0x44` and owner vtable slot `+0x20`.

Keep direct class ownership, keep C++ blank, and update stale coverage row text for [UID:00021Q] and [UID:00021R] to match their actual `85/88` direct-class pages.

### Row-Action Packet Sender

[UID:00010H] should remain direct `ClanStatusPane` child. It is a modeled function with one direct caller from `ClanStatusPane::OnMouseEvent` at `0x00484e91`.

Best name: `ClanStatusPane::SendClanStatusRowActionPacket` or `ClanStatusPane::SendClanRowActionPacket`.

The current page title `ClanStatusRowActionPacket` is acceptable prose, but implementation should avoid treating this as a protocol-free static helper. Row `7` delegates to `ClanStatusPane::SendClanEnlistListRefreshPacket`; all other rows write `{0x4b, subtype, 0}` and send length `3`.

No first-draft C++ recommendation for this page from the class-level report because the exact original helper name/signature and row action enum names remain below source-grade. It is not a class-page C++ blocker.

### Packet Dispatcher And Dialog Handlers

[UID:00021C] is the secondary-vtable inbound opcode `0x43` handler. Keep direct `ClanStatusPane` ownership and source route through `Clan.cpp`.

Do not emit C++ for the dispatcher aggregate yet. B012/B013 evidence and this PE scan agree:

- Cases `1`, `2`, and `6` directly call `0x004877d0`, `0x004879e0`, and `0x00487ea0`.
- Cases `3`, `4`, `5`, and `7..12` inline dialog-opening behavior in the dispatcher.
- The retained sibling helper bodies in [UID:00021S] are valid function-shaped source bodies but have no direct call or exact pointer route.

[UID:00021S] should remain a no-code aggregate unless split:

- If split, live handlers `0x004877d0`, `0x004879e0`, and `0x00487ea0` should become `ClanStatusPane` method pages.
- No-xref opener siblings should remain `Clan.cpp` file-local retained helpers unless a later source route is found.
- Aggregate C++ would misrepresent the observed call graph.

### Subtype 6 Packet Helpers And List Pane Callers

[UID:00021K] is already correctly resolved and first-draft C++ is populated:

- `ClanStatusPane::SendClanEnlistListRefreshPacket()`
- `ClanStatusPane::SendClanEnlistListSelectionPacket(const wchar_t *applicantName)`

The helpers ignore `this` internally, but caller shape makes class ownership stronger than file-local ownership:

- Row-action helper calls action `0` from a `ClanStatusPane::OnMouseEvent` path.
- `ClanEnlistListPane` selected-row and Enter handlers load `g_pClanStatusPane` before calling action `1`.
- The inline action `3` path calls action `0` afterward, confirming refresh semantics.

[UID:00021U] should remain file-owned as a mixed aggregate spanning both `ClanJoinListPane` and `ClanEnlistListPane`. The class page should record the relationship, not absorb those methods:

- `0x00488900`: `ClanJoinListPane` input handler, Enter sends selected join-list row through subtype `2` action `1`.
- `0x00488970`: `ClanEnlistListPane::OnSelectedRowAction`, calls `g_pClanStatusPane->SendClanEnlistListSelectionPacket`.
- `0x004889a0`: `ClanEnlistListPane` input handler, Enter calls action `1`, key `0x84` sends inline subtype `6` action `3`, then calls refresh action `0`.

Key code `0x84` remains a negative-evidence closure, not open generic future work: current evidence proves a selected-name action `3` path, but does not prove whether the UI label is accept, reject, delete, block, or another server-side operation. Use numeric/descriptive naming until additional UI/server evidence appears.

### Destructor And Thunks

[UID:00030O] remains non-reconstructable compiler-generated adjustor thunk pair. Do not emit source for it.

[UID:00030P] remains direct class-owned but should not emit scalar-deleting wrapper C++. The source representation should eventually be ordinary:

```cpp
ClanStatusPane::~ClanStatusPane()
```

with child deletion and `g_pClanStatusPane` clearing, after child field/base destructor names are settled. The scalar-delete flag and adjustor thunk calls are compiler ABI behavior.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported inference / decision | Rejected alternatives / negative evidence | Impact |
| --- | --- | --- | --- | --- |
| Source file placement | `Clan.md`, proposed source tree, constructor/parser/packet/list/dialog docs, resource strings, `g_pClanStatusPane`, bank split docs. | `ClanStatusPane` belongs in `NexusTK/social/Clan.cpp`, emitted through [UID:0000I8] `Clan`. | Reject `ClanDialogs.cpp`: dialogs are constructed by the pane but do not own pane/list state. Reject `ClanBank.cpp`: bank item/money panes are separate. | Keep class owner/emitter `0000I8`; no source route change. |
| Class versus helper ownership for subtype 6 packet helpers | [UID:00021K], [UID:00010H], [UID:00021U], PE rel32 hits to `0x00485960`/`0x004859d0`, `g_pClanStatusPane` loads. | Direct methods on `ClanStatusPane`: `SendClanEnlistListRefreshPacket` and `SendClanEnlistListSelectionPacket`. | File-local helper shape rejected as weaker because callers pass/preserve a class receiver. `ClanEnlistListPane` owner rejected because list handlers load `g_pClanStatusPane` before calls. | Already implemented in [UID:00021K]; class page should retain details. |
| `0x004872e0` owner | [UID:00021N], target class field names, row/helper adjacency, PE scan no rel32 or exact pointer hits. | `ClanStatusPane::IsRowActionAllowed`, direct class owner/emitter recommended. | Leaving file-owned is stale. Emitting C++ is rejected because no direct route and original helper spelling are unproven. | Update [UID:00021N] metadata to `00002K`; keep blank C++. |
| `+0xf8` field | Parser/frame/row/show helpers, view values, current class page. | `m_currentClanStatusView`, values `0` status, `1` management, `2` info, `3` join, `4` enlist. | `m_currentTab` rejected because values `2..4` are child views, not tabs. Raw `byte_` labels rejected. | Use final field name in class and children. |
| `+0xf9` field | Parser packet version, row eligibility thresholds, B012 parser report. | `m_statusDataVersion`. | Generic `versionByte` is too weak; not just parser-local. | Use in row eligibility and parser notes. |
| `+0xfa` field | Frame/input row click storage and hit-test result. | `m_selectedStatusRow`; avoid overcommitting to exact width in class prose. | `m_selectedTab` rejected; value comes from row hit-testing. | Use descriptive field name but retain width caution. |
| Fixed text slots | Parser field offsets, row renderer, row-action mapping. | `m_statusHeaderText`, `m_statusActionText[5]`, `m_managementActionText[7]`. | Raw offset-only prose rejected. Management read order is not storage order. | Class page should carry both storage offsets and packet read order. |
| Child pane fields | Constructor stores, refresh/show/dialog handlers, destructor. | `m_infoListPane`, `m_joinListPane`, `m_enlistListPane`. | Generic `m_childPane1/2/3` rejected because classes are known from vtables and constructors. | Source-grade field names. |
| Child vtable slots in refresh/show helpers | [UID:00021O/P/Q/R], PE no direct callees, child class pages. | Behavior: `+0x38/+0x40` refresh/clear-like pair; `+0x30/+0x3c` selected-child setup pair. | Final names such as `Clear`, `Refresh`, `SetBounds`, `Activate` are plausible but not proven across base classes. | Keep C++ blank for refresh/show helpers; report as specific blocker, not generic unknown. |
| Raw show helper reachability | [UID:00021P/Q/R], local PE rel32/VA/RVA scans, padding bytes. | Real raw class helper bodies, no direct route found; retain class ownership based on fields and sibling pattern. | Do not claim dispatcher or vtable calls them. Do not lower to padding/compiler artifact. | Keep owner `00002K`, blank C++, coverage rows should not say unassigned. |
| Packet dispatcher helperization | [UID:00021C], [UID:00021S], PE direct-call/no-pointer scan. | Dispatcher direct-calls only cases `1`, `2`, `6`; other cases inline dialog opening. | Helperized dispatcher C++ rejected unless implementation documents retained helper convenience versus observed calls. | Keep dispatcher aggregate C++ blank. Split live helper children before code. |
| No-xref dialog opener siblings | [UID:00021S], PE zero exact-start pointers, decompile behavior. | Valid source-shaped retained `Clan.cpp` helper bodies; no direct route proven. | Padding/compiler artifact rejected because bodies allocate dialogs and install vtables. Direct class method ownership rejected for no-xref siblings unless split evidence changes. | Keep aggregate file-owned/no-code; split policy documented. |
| `ClanInfoListPane` source relation | Constructor inline setup, child class doc, false virtuals. | Passive read-only `TextEditPane` child owned by class field `m_infoListPane`; raw constructor no-route remains inactive. | Treating raw constructor as callable source anchor rejected. | Class page should use child field but not rely on raw constructor route. |
| `ClanJoinListPane` source relation | Child class doc, vtable refs, [UID:00021U], join packet helper. | Child owns join list selected-row/input virtuals; `ClanStatusPane` owns the containing pointer and status flow. | Absorbing join handlers into `ClanStatusPane` rejected; they are vtable-only child class methods. | Cross-reference only. |
| `ClanEnlistListPane` source relation | Child class doc, [UID:00021U], [UID:00021K], vtable refs. | Child supplies selected applicant/list text; packet sending remains `ClanStatusPane` method through `g_pClanStatusPane`. | Owning subtype 6 helper on `ClanEnlistListPane` rejected by receiver setup. | Class page should preserve caller/owner distinction. |
| Key code `0x84` action | [UID:00021U], [UID:00021K], PE call sequence. | Best safe name: subtype `6` action `3` selected-name packet, followed by refresh. | Accept/approve/reject/delete labels rejected. No source-quality UI label found. | Open question closed with no-safe-inference proof. |
| Resource names | [UID:0003B8], PE resource bytes, frame/input refs. | Full UTF-16 resource names `CLAN1.EPF`, `CLAN2.EPF`, `CLAN3.EPF`, `CLANBUT.EPF`. | `AN*` labels rejected as IDA interior suffixes. | Class page should keep full names. |
| Destructor shape | [UID:00030O/P], vtable data, PE pointer/rel32 hits. | Thunks compiler-generated; destructor source is normal `~ClanStatusPane()`, not scalar-deleting wrapper source. | Handwritten thunk functions rejected. Emitting scalar-delete wrapper rejected. | Target no-code; destructor child no-code until ordinary destructor source body is stable. |
| Class target C++ eligibility | Target metadata `85/86`, emitter `0000I8`, child C++ state, validator autogen output. | No target-level C++ despite gate eligibility. Class page is a container/emitter; method bodies belong on child pages and partial class declarations would be misleading. | Emitting child bodies in class page rejected. Emitting partial declaration rejected due unresolved inherited virtual/base layout and child vslot names. | Keep target `RECONSTRUCTION_CPP` blank; use child method C++ policy. |

## Open Question Closure

Closed with high-probability inference:

- Source file: `social/Clan.cpp`.
- Class owner/emitter: target remains [UID:0000I8] `Clan`; child class-owned helpers should route through [UID:00002K] when direct class state/receiver evidence supports it.
- Field names for `+0xf8`, `+0xf9`, `+0xfa`, `+0x14e`, fixed text slots, and child pointers.
- Resource names: full `CLAN*.EPF`, not `AN*.EPF`.
- Subtype 6 action 0/1 helper names and direct class ownership.
- `0x004872e0` should be class-owned despite raw no-route status.
- Destructor thunks are compiler glue only.

Closed with no-safe-inference proof:

- Key code `0x84` user-facing action label: evidence proves subtype `6` action `3` selected-name packet and refresh, but not accept/reject/delete semantics.
- Raw show helper direct reachability: local PE rel32 and exact pointer scans found no route; use class ownership from field/pattern evidence but keep C++ blank.
- Child virtual slot names `+0x30/+0x38/+0x3c/+0x40`: behavior is known, final source names are not proven across base/child families.
- Dispatcher helperization: direct calls exist only for cases `1`, `2`, `6`; helperized source output for all cases would contradict observed code unless explicitly modeled as retained/source-convenience functions.

## First-Draft C++ Decision

Target [UID:00002K] `ClanStatusPane.md`: do not emit first-draft C++ in the class page.

Exact no-code proof:

1. The target is a class/container page, not a single executable range.
2. Validator output reports `00002K by-class/ClanStatusPane.md emitting children only`.
3. Child method pages already carry or should carry method-level C++ when eligible:
   - [UID:00010A] constructor C++ is populated.
   - [UID:00010B] parser C++ is populated.
   - [UID:00021K] subtype 6 action 0/1 helper C++ is populated.
4. Adding child method bodies to the class page would duplicate method-child output and misstate ownership boundaries.
5. A partial class declaration is not yet source-quality because inherited virtual slot declarations, base subobject layout, child virtual slot names, event types, and several packet enum names are still not recovered to declaration quality.

Child C++ policy:

| Child | Recommendation |
| --- | --- |
| [UID:00010A] constructor | Keep C++ populated. |
| [UID:00010B] parser | Keep C++ populated. |
| [UID:00010C] frame/input aggregate | No aggregate C++; split into virtual children first. |
| [UID:00010G] row helper aggregate | No aggregate C++; split before code or keep prose. |
| [UID:00021N] row eligibility | No C++; raw no-route and original helper spelling unproven. |
| [UID:00021O] refresh child panes | No C++; child vslot names unresolved. |
| [UID:00021P/Q/R] show helpers | No C++; raw no-route plus child vslot names unresolved. |
| [UID:00010H] row-action packet helper | No class-level action required; method-page C++ can be reconsidered after final helper name/signature/enum names. |
| [UID:00021C] packet dispatcher | No aggregate C++; inline dialog branches versus retained helpers unresolved for source output. |
| [UID:00021S] dialog handler island | No aggregate C++; split live handlers/no-xref siblings first. |
| [UID:00021K] subtype 6 packet helpers | Keep C++ populated. |
| [UID:00021U] list pane input handlers | Mixed aggregate remains file-owned/no-code; split child methods if emitting. |
| [UID:00030O] destructor thunks | Non-reconstructable compiler glue; no C++. |
| [UID:00030P] destructor | No scalar-delete wrapper C++; later ordinary destructor only after fields/base names are final. |

## Score And Metadata Recommendations

Target [UID:00002K]:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000I8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000I8
RECONSTRUCTION_CPP: blank
```

Rationale for `87/89`:

- Completion should rise above `85` because source placement, field names, packet helper names, child ownership strategy, raw-helper no-route facts, dispatcher split policy, destructor thunk handling, and class-level no-code proof are now reanalyzed together.
- Do not raise to `90+` because full class declaration, inherited virtual slot names, child-pane slot names, event types, and some server-side packet action labels remain unresolved.

Support metadata recommendations:

| UID | Current issue | Recommendation |
| --- | --- | --- |
| [UID:00021N] | Metadata still file-owned despite class field helper. | Change owner/emitter to `00002K`; keep `85/90`, blank C++. |
| [UID:00021P] | Page metadata is current, coverage row still says unassigned/stale. | Keep page `85/88`, owner/emitter `00002K`; update coverage row. |
| [UID:00021Q] | Page metadata is current, coverage row stale at `82`. | Keep page `85/88`, owner/emitter `00002K`; update coverage row. |
| [UID:00021R] | Page metadata is current, coverage row stale at `82`. | Keep page `85/88`, owner/emitter `00002K`; update coverage row. |
| [UID:00021S] | Page now `86/91`, coverage row stale at `84`. | Update coverage row; keep aggregate owner `0000I8` unless split. |
| [UID:0002MQ] | Page now `86/91`, coverage row stale at `84`. | Update coverage row. |

## Implementation Checklist For Later Callback

Do not apply this during the report-only pass. If accepted, the implementation callback should require these exact changes.

1. Update `by-class/ClanStatusPane.md` metadata:
   - `COMPLETION:87`
   - `CONFIDENCE:89`
   - keep owner/emitter as `0000I8`
   - keep C++ blank

2. Add or expand a `## Heuristic / Inference Reanalysis And Validation` section in `by-class/ClanStatusPane.md` with the issue-by-issue decisions from this report:
   - `social/Clan.cpp` placement and rejected `ClanDialogs.cpp`/`ClanBank.cpp`
   - field names at `+0xf8`, `+0xf9`, `+0xfa`, `+0xfe`, `+0x14e`, `+0x150`, fixed text slots, and `+0x2510/+0x2514/+0x2518`
   - packet subtype/action naming and negative evidence for action `3` UI label
   - direct class owner for [UID:00021K] and recommended direct class owner for [UID:00021N]
   - raw no-route status for [UID:00021P/Q/R]
   - dispatcher/direct-call distinction for [UID:00021C]/[UID:00021S]
   - child pane caller/consumer distinction for `ClanJoinListPane` and `ClanEnlistListPane`
   - destructor thunk/compiler-wrapper policy
   - target-level no-code proof

3. Update method table and notes in `by-class/ClanStatusPane.md`:
   - Keep [UID:00010A], [UID:00010B], [UID:00021K] as method pages with first-draft C++.
   - Mark [UID:00010C] and [UID:00010G] as mixed aggregates that should split before C++.
   - For [UID:00021N], state direct class owner recommendation and source name `IsRowActionAllowed`.
   - For [UID:00021O/P/Q/R], use child field names and child-vslot blocker details.
   - For [UID:00021S], record that only three handlers are directly called by dispatcher; no-xref opener siblings are retained file-local helpers if preserved.
   - For [UID:00021U], record that join/enlist list panes own the vtable handlers, while `ClanStatusPane` owns subtype 6 packet helpers.

4. Update [UID:00021N] `by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md`:
   - `CANONICAL_OWNER:00002K`
   - `EMITTER_UIDS:00002K`
   - replace provisional field wording with `m_currentClanStatusView` and `m_statusDataVersion`
   - add local PE no-route revalidation from this report
   - keep C++ blank with the target-specific no-code proof

5. Optionally refresh [UID:00021O/P/Q/R] support docs:
   - ensure they consistently use `m_infoListPane`, `m_joinListPane`, `m_enlistListPane`, and `m_currentClanStatusView`
   - keep child virtual slots unnamed but behaviorally described
   - keep no-code proof specific to child-vslot names and raw no-route facts

6. Optionally refresh [UID:00021S] support doc:
   - ensure the class page and helper island agree on live handler names and retained no-xref sibling policy
   - keep aggregate C++ blank and split-before-C++ proof

7. Update shared coverage/report rows after supervisor acceptance:
   - `by-class/-coverage-report.md` row for [UID:00002K]
   - `by-memory/-coverage-report.md` rows listed below, if the supervisor accepts those support updates
   - do not hand-edit `auto-generated/-ag-*` reports; use validator/autogen flow after by-* changes

8. Validation commands for implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [00002K-ClanStatusPane-class-source-quality-removed.md](00002K-ClanStatusPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:00021O/P/Q/R] or [UID:00021S] support docs are edited, validate each edited file in file mode too.

## Exact Coverage Row Text

### `by-class/-coverage-report.md` replacement row

```text
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) : reconstructable : 87% : strong : B015 2026-06-19 source-quality reanalysis validates `ClanStatusPane` as the `NexusTK/social/Clan.cpp` owner/emitter for the main clan status panel; reconciles constructor/parser/frame/input/row/refresh/view/packet/destructor families; resolves source-facing field names for view/version/selection, raw attributes, fixed status/management text slots, and child panes; preserves full `CLAN1.EPF`/`CLAN2.EPF`/`CLAN3.EPF`/`CLANBUT.EPF` resources; class-owns subtype `6` refresh/selection packet helpers; recommends direct class ownership for the row-eligibility helper; closes raw view-helper reachability and key `0x84` action-label questions with negative evidence; and keeps target-level C++ blank because this class page emits children only and unresolved child vslot/event/declaration names block source-quality class C++.
```

### `by-memory/-coverage-report.md` replacement rows

[UID:00021N]

```text
    - [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) 0x004872e0-0x00487335 | raw class method | ClanStatusPane::IsRowActionAllowed : reconstructable : 85% : strong : B015 2026-06-19 reanalysis recommends direct [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) owner/emitter after raw PE scanning found no direct call or exact pointer route but confirmed the helper reads class state fields `m_currentClanStatusView` (`+0xf8`) and `m_statusDataVersion` (`+0xf9`), uses a signed row-index switch through `0x00487338`, belongs between the row helpers and child-view helpers, and remains no-code because direct reachability and final original helper spelling are unproven.
```

[UID:00021P]

```text
    - [UID:00021P][0x004873c0-0x00487475.ClanStatusPaneShowInfoList](by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md) 0x004873c0-0x00487475 | raw class method | ClanStatusPane::ShowInfoList : reconstructable : 85% : strong : Direct [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) raw view-switch helper; live IDA and B015 PE revalidation confirm raw no-function/no-inbound-route status, view byte `m_currentClanStatusView = 2`, shared child bounds `0x12/0x47/0xae/0x107`, inline child refresh over `m_joinListPane`/`m_infoListPane`/`m_enlistListPane`, selected `m_infoListPane` setup through unresolved child vslots `+0x30/+0x3c`, owner invalidation, exact `0xcc` padding, and blank C++ pending child vslot names plus source reachability proof.
```

[UID:00021Q]

```text
    - [UID:00021Q][0x00487480-0x00487535.ClanStatusPaneShowJoinList](by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md) 0x00487480-0x00487535 | raw class method | ClanStatusPane::ShowJoinList : reconstructable : 85% : strong : Direct [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) raw view-switch helper; live IDA and B015 PE revalidation confirm raw no-function/no-inbound-route status, view byte `m_currentClanStatusView = 3`, shared child bounds `0x12/0x47/0xae/0x107`, inline child refresh over `m_joinListPane`/`m_infoListPane`/`m_enlistListPane`, selected `m_joinListPane` setup through unresolved child vslots `+0x30/+0x3c`, owner invalidation, exact `0xcc` padding, and blank C++ pending child vslot names plus source reachability proof.
```

[UID:00021R]

```text
    - [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md) 0x00487540-0x004875f5 | raw class method | ClanStatusPane::ShowEnlistList : reconstructable : 85% : strong : Direct [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) raw view-switch helper; live IDA and B015 PE revalidation confirm raw no-function/no-inbound-route status, view byte `m_currentClanStatusView = 4`, shared child bounds `0x12/0x47/0xae/0x107`, inline child refresh over `m_joinListPane`/`m_infoListPane`/`m_enlistListPane`, selected `m_enlistListPane` setup through unresolved child vslots `+0x30/+0x3c`, owner invalidation, exact `0xcc` padding before row-action helper, and blank C++ pending child vslot names plus source reachability proof.
```

[UID:00021S]

```text
    - [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) 0x004877d0-0x00488594 | packet-handler cluster | ClanStatusPacketDialogHandlers : reconstructable : 86% : strong : B013/B015 source-quality evidence records the exact packet/dialog helper island, three dispatcher-called `ClanStatusPane` handlers for opcode `0x43` subtypes `1`, `2`, and `6`, nine retained no-xref `Clan.cpp` dialog opener siblings mirrored by inline dispatcher branches, local PE direct-call/no-pointer scans, child-pane state offsets, wide scratch-buffer use, dialog allocation/vtable evidence, split-before-C++ policy, and aggregate no-code proof.
```

[UID:0002MQ]

```text
        - [UID:0002MQ][0x00615570-0x006158f4.ClanPaneListVtableData](by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md) 0x00615570-0x006158f4 | vtable-data | ClanPaneListVtableData : reconstructable : 86% : strong : Exact clan status/list pane RTTI/vtable data from `ClanStatusPane` through `ClanEnlistListPane` with live IDA-verified COL pointers, primary/secondary/tertiary slot spans and counts, first-slot anchors including `ClanStatusPane` destructor/thunks, constructor/destructor store xrefs, modal-dialog successor boundary at `0x006158f4`, and [UID:0000I8][Clan](by-file/Clan.md) parent-gate routing.
```

No `by-file/-coverage-report.md` replacement is required; [UID:0000I8] `Clan` already has a strong `90%` row consistent with this source placement.

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R002 was removed from this report and preserved verbatim in [00002K-ClanStatusPane-class-source-quality-removed.md](00002K-ClanStatusPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `apply: False`
- `scanned markdown files: 1`
- `ok: 1`
- Key ok row: `ok           00002K by-class/ClanStatusPane.md UID header exists`
- Validator ended with `dry run only; pass --apply to write changes`

The output also reported existing repository-wide autogen messages such as `autogen_emitter_has_no_code` and `autogen_cpp_noop`; no target validation error was reported for `ClanStatusPane.md`.

## Files Edited In This Report Pass

Only this research report and `Agent-B015/notes.md` are intended to be edited by this pass. No by-* documentation file was edited. `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00002K-ClanStatusPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00002K"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00002K-ClanStatusPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00002K-ClanStatusPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00002K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
