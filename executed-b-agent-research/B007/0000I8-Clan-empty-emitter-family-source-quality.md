** TARGET-REPORT-UID:0000I8 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B007 Research Report: [UID:0000I8] Clan Empty Emitter Family

## Assignment

- Agent: Agent-B007
- Assignment ID: `B007-report-0000I8-Clan-empty-emitter-family-20260630`
- Mode: report-first research only
- Primary target: [UID:0000I8][Clan](by-file/Clan.md)
- Queue source: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`
- Generated file under review: `auto-generated/NexusTK/social/Clan.cpp`

No by-* documentation was edited in this report pass. No leases were needed because the only change is this report file in Agent-B007's research folder.

## Key Disposition

The current `Clan.cpp` empty-emitter problem is not caused by a missing by-file owner route. [UID:0000I8][Clan](by-file/Clan.md) remains the correct file owner at `90/85` and `NexusTK/social/`. The generated file contains 78 emitters, 27 filled emitters, and 51 marked empty emitters because many child docs are reconstructable and routed to the Clan source file but have blank formal `RECONSTRUCTION_CPP CODE` bodies.

Implementation should not hide source-quality state by clearing `RECONSTRUCTABLE`. The corrected repair is mixed: add declaration shells for class pages that are declaration-ready, add first-draft C++ for exact helpers whose behavior and source route are now proved, add storage declarations for the singleton/scratch-buffer pages whose current bytes and linkage are sufficiently bounded, and clear or comment only the targets that are compiler-generated, retained raw no-route islands, or aggregate/index pages that require exact child splits before body emission.

The by-file root metadata remains correct, but the root should receive a support note explaining this empty-emitter repair once the callback implements the child changes:

| Field | Recommendation |
| --- | --- |
| [UID:0000I8] completion/confidence | Keep `90/85` |
| Proposed reconstruction path | Keep `NexusTK/social/` |
| Canonical owner | Keep `FILE` |
| Direct by-file C++ block | Not applicable; by-file docs do not carry the reconstruction C++ block |
| Generated target | Keep `auto-generated/NexusTK/social/Clan.cpp` |

## Current Generated Evidence

Read-only generated output evidence:

- `auto-generated/NexusTK/social/Clan.cpp`
  - `validator-command-id: 000000002158`
  - `validator-refreshed-at: 2026-06-30T03:43:19-04:00`
  - `Source by-file UID: 0000I8`
  - Current empty marker count: 51
- `auto-generated/-ag-research-tracker.md`
  - row 64: `[UID:0000I8][Clan] | Total Emitters 78 | Filled 27 | Marked Empty 51 | Complete 34.6% | auto-generated/NexusTK/social/Clan.cpp | by-file/Clan.md`
  - row 1148: `[UID:0000I8][Clan] | 90/85 | 87.5 | blank | 0 | ... | by-file/Clan.md`

The 51 current empty markers are:

| UID | Path | Score | Current route |
| --- | --- | --- | --- |
| 0002NZ | `by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md` | 85/90 | owner/emitter `000023` |
| 000024 | `by-class/ClanAttrInputDialog.md` | 86/89 | owner/emitter `0000I8` |
| 000027 | `by-class/ClanChangeInputDialog.md` | 85/89 | owner/emitter `0000I8` |
| 0002O4 | `by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md` | 85/90 | owner/emitter `000027` |
| 000028 | `by-class/ClanChangeNameInputDialog.md` | 85/89 | owner/emitter `0000I8` |
| 0002O1 | `by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md` | 85/90 | owner/emitter `000028` |
| 00002A | `by-class/ClanDepMoneyInputDialog.md` | 86/90 | owner/emitter `0000I8` |
| 00021V | `by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md` | 85/90 | owner/emitter `00002A` |
| 00002B | `by-class/ClanEnlistInputDialog.md` | 85/89 | owner/emitter `0000I8` |
| 00021W | `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md` | 85/90 | owner/emitter `00002B` |
| 00002C | `by-class/ClanEnlistListPane.md` | 86/90 | owner/emitter `0000I8` |
| 00002E | `by-class/ClanInfoListPane.md` | 85/89 | owner/emitter `0000I8` |
| 00002H | `by-class/ClanJoinListPane.md` | 86/90 | owner/emitter `0000I8` |
| 00002I | `by-class/ClanLeaveConfirmDialog.md` | 85/89 | owner/emitter `0000I8` |
| 0002O6 | `by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md` | 85/90 | owner/emitter `00002I` |
| 00002J | `by-class/ClanNameInputDialog.md` | 86/89 | owner/emitter `0000I8` |
| 00002K | `by-class/ClanStatusPane.md` | 87/89 | owner/emitter `0000I8` |
| 00010C | `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md` | 86/90 | owner/emitter `00002K` |
| 00021C | `by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md` | 87/90 | owner/emitter `00002K` |
| 00010G | `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md` | 86/90 | owner/emitter `00002K` |
| 00021O | `by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md` | 85/88 | owner/emitter `00002K` |
| 00021P | `by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md` | 85/88 | owner/emitter `00002K` |
| 00021R | `by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md` | 85/88 | owner/emitter `00002K` |
| 00010H | `by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md` | 85/90 | owner/emitter `00002K` |
| 00030P | `by-memory/0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md` | 86/90 | owner/emitter `00002K` |
| 00002L | `by-class/ClanStringListPane.md` | 87/90 | owner/emitter `0000I8` |
| 0002NP | `by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md` | 85/90 | owner/emitter `00002L` |
| 00035D | `by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md` | 86/89 | owner/emitter `00002L` |
| 00035E | `by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md` | 85/89 | owner/emitter `00002L` |
| 00035F | `by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md` | 85/89 | owner/emitter `00002L` |
| 00002M | `by-class/ClanSummonNameInputDialog.md` | 85/89 | owner/emitter `0000I8` |
| 0002NX | `by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md` | 85/90 | owner/emitter `00002M` |
| 00002O | `by-class/ClanWidMoneyInputDialog.md` | 86/90 | owner/emitter `0000I8` |
| 0002NT | `by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md` | 85/90 | owner/emitter `00002O` |
| 0002XG | `by-global/g_pClanStatusPane.md` | 86/89 | owner/emitter `0000I8` |
| 0002XH | `by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md` | 86/89 | owner/emitter `0002XG` |
| 00021D | `by-memory/0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket.md` | 85/89 | owner/emitter `0000I8` |
| 00021E | `by-memory/0x004854b0-0x00485518.SendClanEnlistRequestRefreshPacket.md` | 85/90 | owner/emitter `0000I8` |
| 00021F | `by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md` | 85/90 | owner/emitter `0000I8` |
| 00021H | `by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md` | 85/90 | owner/emitter `0000I8` |
| 00021I | `by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md` | 85/89 | owner/emitter `0000I8` |
| 00021J | `by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md` | 85/89 | owner/emitter `0000I8` |
| 00010E | `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md` | 85/90 | owner/emitter `0000I8` |
| 00010F | `by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md` | 85/90 | owner/emitter `0000I8` |
| 00021S | `by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md` | 86/91 | owner/emitter `0000I8` |
| 00010L | `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md` | 85/90 | owner/emitter `0000I8` |
| 0002O5 | `by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md` | 85/90 | owner/emitter `0000I8` |
| 0002MQ | `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md` | 86/91 | owner/emitter `0000I8` |
| 0002MN | `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md` | 87/91 | owner/emitter `0000I8` |
| 0002B7 | `by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md` | 86/88 | owner/emitter `0000I8` |
| 0001TY | `by-type/by-struct/ClanInputDialogLayouts.md` | 85/90 | owner/emitter `0000I8` |

## Current MCP Evidence

MCP was available and used. This report is not fallback-only.

Current listener/session state rechecked on 2026-06-30:

- Endpoint: `http://127.0.0.1:13337/mcp`
- `tools/list`: returned the current schema; schema-current calls require `database`.
- `idb_list`:
  - session `supervisor_resume_20260629`
  - active worker session
  - input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - created `2026-06-29T21:35:56.876252`
  - last accessed `2026-06-30T04:12:20.812207`
  - `is_analyzing:false`
  - `pid:17592`
  - `worker_pid:17592`
- `server_health` for `supervisor_resume_20260629`:
  - `status:ok`
  - `uptime_sec:23822.725`
  - IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - module `NexusTK.exe`
  - input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - imagebase `0x400000`
  - `auto_analysis_ready:true`
  - `hexrays_ready:true`
  - `strings_cache_ready:true`
  - `strings_cache_size:2067`

Narrow MCP evidence used for this report:

- `lookup_funcs` reports no function object for the retained raw constructor/helper starts `0x004893a0`, `0x00489ff0`, `0x004894d0`, `0x00488fa0`, `0x00489f80`, `0x0048a060`, `0x00488630`, `0x00488740`, `0x00488760`, `0x00489270`, and `0x00489070`.
- `xrefs_to` reports no inbound xrefs to those same retained raw constructor/helper starts.
- `lookup_funcs` reports real modeled functions for `0x00484a60`, `0x00484f70`, `0x00486800`, `0x00487370`, `0x00487600`, `0x0048c590`, `0x00488680`, `0x00485ac0`, `0x00486330`, `0x004877d0`, `0x00489600`, and `0x0048a030`.
- `decompile(0x00487370)` shows exactly six child-pane virtual dispatches over object indexes `2373`, `2372`, and `2374`, corresponding to offsets `+0x2514`, `+0x2510`, and `+0x2518`.
- Current-schema `disasm(0x004873c0)` confirms raw no-function `ShowInfoList` bytes: view byte `+0xf8 = 2`, shared rectangle constants through `0x004b7c50`, inline child refresh sequence, selected child offset `+0x2510`, owner invalidation through `this+0x44`, and alignment before `0x00487480`.
- Current-schema `disasm(0x00487540)` confirms raw no-function `ShowEnlistList` bytes: view byte `+0xf8 = 4`, same shared rectangle constants and inline child refresh sequence, selected child offset `+0x2518`, owner invalidation through `this+0x44`, and alignment before `0x00487600`.
- `decompile(0x00488680)` confirms `ClanStringListPaneInsertOrReplaceText`: list count helper, row lookup loop, duplicate removal, `_wcscpy_s` into a `0x20` WCHAR local buffer, then list insertion.
- `decompile(0x0048a030)` confirms the exact four-argument call to `sub_486330` with inherited fields `this+0x26c`, `this+0x46c`, `this+0x66c`, and `*(WORD *)(this+0x86c)`.
- `entity_query` over `0x00615570-0x00615fd8` returns the dense Clan pane-list and modal-dialog vtable/COL names from `ClanStatusPane` through `ClanLeaveConfirmDialog`; these are compiler-generated class artifacts, not source-authored arrays to hand-copy into `Clan.cpp`.
- `entity_query` around `0x0067ade4` returns no named symbol there; `by-global/g_pClanStatusPane.md` is the project canonical global page.
- `entity_query` around `0x0067adf0` names `WideCharStr`; the page still caps final C++ because original symbol and linkage are not proved.
- `int_convert` / local `tools/int_convert.py` conversions used in the evidence: `0x251=593`, `0x49b=1179`, `0x4df=1247`, `0x46=70`, `0x1a0=416`, `0x1fe=510`, `0x7e1=2017`, `0x29=41`, `0xaf=175`, `0xbe=190`, `0x20=32`, `0x2510=9488`, `0x2514=9492`, `0x2518=9496`, `0x26c=620`, `0x46c=1132`, `0x66c=1644`, and `0x86c=2156`.

## Existing Reports Searched

Existing executed and agent research was searched before finalizing. Search terms included `0000I8`, `Clan`, `Clan.cpp`, `ClanStatusPane`, `ClanNameInputDialog`, `ClanAttrInputDialog`, `ClanListPane`, `ClanPane`, `g_pClanStatusPane`, and prominent child UIDs.

Relevant executed reports found and used as leads include:

- `executed-b-agent-research/B015/00002K-ClanStatusPane-class-source-quality.md`
- `executed-b-agent-research/B015/00021U-ClanListPaneInputHandlers-source-quality.md`
- `executed-b-agent-research/B014/00010A-ClanStatusPaneConstructor-source-quality.md`
- `executed-b-agent-research/B014/00010T-ClanDestructorBand-source-routing.md`
- `executed-b-agent-research/B013/00021S-ClanStatusPacketDialogHandlers-source-quality.md`
- `executed-b-agent-research/B012/00010B-00021C-ClanStatusPacketParserDispatcher-source-quality.md`
- `executed-b-agent-research/B011/00002D-ClanExpelNameInputDialog-source-quality.md`
- `executed-b-agent-research/B009/00010J-ClanNameInputDialogCore-source-quality.md`
- `executed-b-agent-research/B006/00021L-ClanNameActionPacketHelpers-source-quality.md`
- `executed-b-agent-research/B005/00021T-ClanInfoListPaneRawConstructor-empty-emitter-source-quality.md`
- `executed-b-agent-research/B004/00002A-ClanDepMoneyInputDialog-source-quality.md`
- `executed-b-agent-research/B003/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md`
- `executed-b-agent-research/B002/000023-ClanAppearNameInputDialog-source-quality.md`
- `executed-b-agent-research/B001/00021D-00021J-clan-opcode4b-packet-helper-source-quality.md`
- `executed-b-agent-research/B001/00021Q-ClanStatusPaneShowJoinList-empty-emitter-source-quality.md`
- `executed-b-agent-research/B001/0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md`
- `executed-b-agent-research/B001/0002NV-ClanExpelNameInputDialogRawConstructor-empty-emitter-source-quality.md`
- `executed-b-agent-research/B001/0002NX-0002O1-clan-name-raw-constructor-source-placement.md`

The important current-state correction is that those reports are leads only. The current by-* docs and current MCP evidence are authoritative for this report.

## Supervisor Review Repair Addendum (Authoritative)

This section is the repaired implementation recommendation for the supervisor callback. It supersedes the broad `Source-Quality Taxonomy`, `Formal Reconstruction Body Recommendations`, `Score Rationale`, `Open Questions`, ledger, and checklist below wherever they disagree. The older rejected section is retained only as provenance for what was repaired.

Repair-pass MCP state: `tools/list` against `http://127.0.0.1:13337/mcp` succeeded on 2026-06-30 with `65` tools. The current report is therefore not fallback-only. The active evidence set also includes the earlier schema-current MCP calls already recorded above: live decompiles for `0x00485ac0`, `0x00486330`, `0x0048a030`, and `0x00488680`; current xrefs/bytes for `0x0067ade4` and `0x0067adf0`; and no-function/no-xref checks for retained raw constructor/helper starts.

### Repaired File-Root Decision

[UID:0000I8] `by-file/Clan.md` remains the correct canonical file owner at `90/85`, path `NexusTK/social/`, and no root C++ block is needed. The implementation callback should add a support note, not a metadata change: the `Clan.cpp` empty-emitter count is caused by child pages that now have mixed outcomes, not by a bad file owner. The support note should state that class declarations, exact helper bodies, storage declarations, and aggregate/no-route no-code proofs are resolved by the repaired child recommendations below. This closes the root re-evaluation item without moving the family to `ClanDialogs`, `ClanBank`, or a generated-file workaround.

### Per-Class Declaration Audit

Each class routing page below is declaration-ready now. The current docs already prove base class, construction/destruction route, vtable family, child method inventory, and field/layout state at documentation quality. The declaration shells intentionally omit full private field declarations unless the exact source declaration is already supported; field offsets remain documented in prose and child pages. `[[CHILDREN]]` must stay after the class declaration so existing child method bodies continue to emit from their own pages.

[UID:000024] `by-class/ClanAttrInputDialog.md`

- Base class: `DialogPane`; constructor core is `0x00489600-0x00489de0` in [UID:00010L].
- Constructor/destructor route: three live constructor call sites plus raw derived constructor forwarding; destructor wrapper/thunks remain compiler-generated under the destructor band.
- Vtable slots/methods: constructor, `OnDialogAction`, `ValidateInputFields`, `OnInputEvent`, and a derived submit hook used by `ClanEnlistInputDialog`/`ClanChangeInputDialog`.
- Known child bodies: [UID:00010L] is still an aggregate core needing exact child split before body emission; [UID:0002O3] and [UID:0002O5] use the submitted fields.
- Field/layout state: controls `8/9/10`; fields `+0x26c/+0x46c/+0x66c/+0x86c` documented as `m_submittedClanName`, `m_submittedDescriptionText`, `m_submittedAttributeText`, and `m_submittedAttributeType`.
- Decision: emit declaration shell now; keep method bodies in child pages.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanAttrInputDialog : public DialogPane
{
public:
    explicit ClanAttrInputDialog(const unsigned char *packet);

protected:
    virtual void OnDialogAction(int closeContext, int controlId);
    virtual void ValidateInputFields();
    virtual bool OnInputEvent(const InputEvent &event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:000027] `by-class/ClanChangeInputDialog.md`

- Base class: `ClanAttrInputDialog`; constructor raw body forwards to the attribute dialog and installs change-dialog vtables.
- Constructor/destructor route: raw constructor start `0x00489ff0` has no function object/xref; destructor inherited/compiler-generated.
- Vtable slots/methods: submit slot routes to [UID:0002O5] `ClanChangeInputDialog::SubmitClanChange`.
- Known child bodies: [UID:0002O5] is exact and should emit first-draft C++ after [UID:00010F] helper is populated; [UID:0002O4] remains raw no-route proof only.
- Field/layout state: uses inherited `ClanAttrInputDialog` submitted-field storage; no unique fields proved.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanChangeInputDialog : public ClanAttrInputDialog
{
public:
    explicit ClanChangeInputDialog(const unsigned char *packet);

protected:
    virtual int SubmitClanChange();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:000028] `by-class/ClanChangeNameInputDialog.md`

- Base class: `ClanNameInputDialog`.
- Constructor/destructor route: raw constructor start `0x004894d0` forwards to base and installs vtables; no function/xref route to emit constructor body.
- Vtable slots/methods: primary submit slot `+0x5c` emits [UID:0002O2] `OnSubmitText(const wchar_t *)`.
- Known child bodies: [UID:0002O2] already emits exact opcode `0x4b`, subtype `0x0a`, action `1` submit-name packet; [UID:0002O1] remains no-route constructor proof.
- Field/layout state: inherits `ClanNameInputDialog` layout; no unique fields.
- Decision: declaration shell is safe by the same pattern as accepted `ClanAppearNameInputDialog` and `ClanExpelNameInputDialog`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanChangeNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanChangeNameInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmitText(const wchar_t *text);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002A] `by-class/ClanDepMoneyInputDialog.md`

- Base class: `ClanNameInputDialog`.
- Constructor/destructor route: raw constructor start `0x00488fa0` has no function/xref route; destructor inherited/compiler-generated.
- Vtable slots/methods: submit slot emits [UID:0002NS] `OnSubmitText(const wchar_t *)`.
- Known child bodies: [UID:0002NS] already emits exact `_wtol` amount packet `{0x4b, 0x04, 0x01, amount}`; [UID:00021V] remains no-route constructor proof.
- Field/layout state: inherits `ClanNameInputDialog`; no unique fields.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanDepMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanDepMoneyInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmitText(const wchar_t *text);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002B] `by-class/ClanEnlistInputDialog.md`

- Base class: `ClanAttrInputDialog`.
- Constructor/destructor route: raw constructor start `0x00489f80` has no function/xref route; destructor inherited/compiler-generated.
- Vtable slots/methods: submit slot emits [UID:0002O3] `OnSubmitEnlistment`.
- Known child bodies: [UID:0002O3] already emits the call to `SendClanAttributePacket`; [UID:00010E] should now emit that helper body; [UID:00021W] remains no-route constructor proof.
- Field/layout state: uses inherited submitted-field storage at `+0x26c/+0x46c/+0x66c/+0x86c`.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanEnlistInputDialog : public ClanAttrInputDialog
{
public:
    explicit ClanEnlistInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmitEnlistment();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002C] `by-class/ClanEnlistListPane.md`

- Base class: `ClanStringListPane`/`ListPane` family; docs prove `ListPane` inherited slots and shared draw reuse.
- Constructor/destructor route: inline construction in `ClanStatusPane::ClanStatusPane`; no standalone constructor body.
- Vtable slots/methods: draw slot reuses `ClanStringListPane::DrawItem`; slots at `0x006158b0` and `0x00615898` emit `OnSelectedRowAction` and `OnKeyEvent`.
- Known child bodies: [UID:000412] and [UID:000413] emit first-draft C++; [UID:0002NQ] shared draw emits once through `ClanStringListPane`.
- Field/layout state: inherited selected index `+0x134`; selected-entry helper and subtype `6` action `0/1/3` packet paths documented.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanEnlistListPane : public ClanStringListPane
{
public:
    ClanEnlistListPane();

protected:
    virtual int OnSelectedRowAction();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002E] `by-class/ClanInfoListPane.md`

- Base class: `TextEditPane`; Wave2/current docs prove 372-byte `TextEditPane`-based class.
- Constructor/destructor route: live inline construction in `ClanStatusPane::ClanStatusPane`; raw constructor-shaped start `0x004885a0` is no-function/no-xref and already resolved by formal no-code child [UID:00021T].
- Vtable slots/methods: false action virtuals at `0x00488610` and `0x00488620`.
- Known child bodies: [UID:0002NN] and [UID:0002NO] emit `CanExecuteAction`/`CanExecuteAlternateAction` returning false.
- Field/layout state: no unique fields beyond embedded `TextEditPane` layout are needed for declaration.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanInfoListPane : public TextEditPane
{
public:
    ClanInfoListPane();

protected:
    virtual bool CanExecuteAction(int actionId);
    virtual bool CanExecuteAlternateAction(int actionId);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002H] `by-class/ClanJoinListPane.md`

- Base class: `ClanStringListPane`/`ListPane` family.
- Constructor/destructor route: inline construction in `ClanStatusPane::ClanStatusPane`; no standalone constructor body.
- Vtable slots/methods: selected-row action and key handler emit in exact split children; draw slot reuses `ClanStringListPane::DrawItem`.
- Known child bodies: [UID:0002NR] emits `OnSelectedRowAction`; [UID:000411] emits `OnKeyEvent`; [UID:0002NQ] shared draw emits once.
- Field/layout state: inherited selected index and selected-entry access; no unique fields.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanJoinListPane : public ClanStringListPane
{
public:
    ClanJoinListPane();

protected:
    virtual int OnSelectedRowAction();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002I] `by-class/ClanLeaveConfirmDialog.md`

- Base class: `AlertPane`.
- Constructor/destructor route: raw constructor start `0x0048a060` has no function/xref route; live packet handlers construct equivalent alert dialog instances.
- Vtable slots/methods: confirm and cancel callbacks emit [UID:0002O7] and [UID:0002O8].
- Known child bodies: exact callbacks call `g_pClanStatusPane->SendClanLeaveResponse(true/false)`; [UID:0002O6] remains no-route constructor proof.
- Field/layout state: no unique fields needed.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanLeaveConfirmDialog : public AlertPane
{
public:
    ClanLeaveConfirmDialog();

protected:
    virtual void OnConfirm();
    virtual void OnCancel();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002J] `by-class/ClanNameInputDialog.md`

- Base class: `DialogPane`.
- Constructor/destructor route: exact core [UID:00010J] emits constructor and shared handlers; derived raw constructors are no-route evidence.
- Vtable slots/methods: `OnButtonClick`, `UpdateOkButtonState`, `OnInputEvent`, and virtual submit hook `OnSubmitText`.
- Known child bodies: [UID:00010J] emits constructor/shared handlers; derived submitters emit overrides in child pages.
- Field/layout state: inherited control host at `+0x1fc`; control ids `1/2/4`; no full private field declaration required.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanNameInputDialog : public DialogPane
{
public:
    explicit ClanNameInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmitText(const wchar_t *text);
    virtual void OnButtonClick(int closeContext, int controlId);
    virtual void UpdateOkButtonState();
    virtual bool OnInputEvent(const InputEvent &event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002K] `by-class/ClanStatusPane.md`

- Base class: `Pane`; constructor emits `Pane(1)` and child allocation.
- Constructor/destructor route: [UID:00010A] emits constructor; [UID:00030P] remains ordinary destructor-body candidate but scalar deleting wrapper/thunks are ABI glue.
- Vtable slots/methods: parser, frame/input, packet dispatcher, row helpers, child refresh/view helpers, outbound packet methods, and destructor are inventoried on the class page.
- Known child bodies: [UID:00010A], [UID:00010B], [UID:00021G], [UID:00010D], [UID:00021K], and [UID:00021N] emit method bodies; [UID:00010C], [UID:00021C], [UID:00010G], [UID:00021O/P/R], [UID:00010H], and [UID:00030P] need target-specific code/no-code decisions below.
- Field/layout state: source-quality names exist for `m_currentClanStatusView`, `m_statusDataVersion`, `m_selectedStatusRow`, `m_rawAttributeDataLength`, raw payload/text arrays, and child pointers `m_infoListPane/m_joinListPane/m_enlistListPane`; full private declaration is intentionally omitted.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanStatusPane : public Pane
{
public:
    ClanStatusPane();
    virtual ~ClanStatusPane();

    void ParseClanStatusAttributePacket(const unsigned char *packet);
    void RefreshChildPanes();
    void ShowInfoList();
    void ShowEnlistList();
    void ForwardInputEvent(const InputEvent &event);

    int SendClanJoinListSelectionPacket(const wchar_t *selectedClanName);
    void SendClanLeaveResponse(bool confirmed);
    int SendClanEnlistListRefreshPacket();
    int SendClanEnlistListSelectionPacket(const wchar_t *applicantName);
    bool IsRowActionBlocked(short rowIndex);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002L] `by-class/ClanStringListPane.md`

- Base class: `ListPane`.
- Constructor/destructor route: raw constructor-shaped start `0x00488630` has no function/xref route; live construction is inline through status/list setup.
- Vtable slots/methods: shared `DrawItem`, `InsertOrReplaceText`, raw clear/find helpers.
- Known child bodies: [UID:0002NQ] emits `DrawItem`; [UID:00035D] should now emit exact `InsertOrReplaceText`; [UID:0002NP]/[UID:00035E]/[UID:00035F] remain no-route proof only.
- Field/layout state: inherited `ListPane` row storage and selected state; no unique fields needed for declaration.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanStringListPane : public ListPane
{
public:
    ClanStringListPane();

    int InsertOrReplaceText(const wchar_t *text);

protected:
    virtual void DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002M] `by-class/ClanSummonNameInputDialog.md`

- Base class: `ClanNameInputDialog`.
- Constructor/destructor route: raw constructor start `0x00489270` has no function/xref route.
- Vtable slots/methods: submit slot emits [UID:0002NY] `OnSubmitText`.
- Known child bodies: [UID:0002NY] emits exact subtype `8`, action `1` name packet; [UID:0002NX] remains no-route constructor proof.
- Field/layout state: inherited `ClanNameInputDialog`; no unique fields.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanSummonNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanSummonNameInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmitText(const wchar_t *text);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00002O] `by-class/ClanWidMoneyInputDialog.md`

- Base class: `ClanNameInputDialog`.
- Constructor/destructor route: raw constructor start `0x00489070` has no function/xref route.
- Vtable slots/methods: submit slot emits [UID:0002NU] `OnSubmitText`.
- Known child bodies: [UID:0002NU] emits exact `_wtol` amount packet `{0x4b, 0x0b, 0x01, amount}`; [UID:0002NT] remains no-route constructor proof.
- Field/layout state: inherited `ClanNameInputDialog`; no unique fields.
- Decision: emit declaration shell now.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanWidMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanWidMoneyInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmitText(const wchar_t *text);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Exact Helper C++ Recommendations

These targets have enough current evidence for formal first-draft C++. The code blocks below are exact callback insertion text.

[UID:00010E] `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`

Evidence: MCP decompile proves opcode `0x4b`, subtype `6`, action `2`, three CP_ACP converted one-byte-length strings, `<0x100` guards, final big-endian 16-bit field, sole caller [UID:0002O3], and the existing generated caller shape that passes `g_pClanStatusPane`. The `statusPane` parameter is retained to match current source-facing call sites even though the helper body does not dereference `this`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static int SendClanAttributePacket(
    ClanStatusPane *statusPane,
    const wchar_t *clanName,
    const wchar_t *descriptionText,
    const wchar_t *attributeText,
    unsigned short attributeType)
{
    (void)statusPane;

    char convertedText[256];
    unsigned char packet[0x304];
    unsigned int packetOffset = 0;

    PacketBufferWriteUInt8(packet + packetOffset++, 0x4b);
    PacketBufferWriteUInt8(packet + packetOffset++, 0x06);
    PacketBufferWriteUInt8(packet + packetOffset++, 0x02);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, clanName, wcslen(clanName), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + packetOffset++, static_cast<unsigned char>(convertedLength));
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP, 0, descriptionText, wcslen(descriptionText), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + packetOffset++, static_cast<unsigned char>(convertedLength));
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP, 0, attributeText, wcslen(attributeText), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + packetOffset++, static_cast<unsigned char>(convertedLength));
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    PacketBufferWriteUInt16BE(packet + packetOffset, attributeType);
    packetOffset += sizeof(unsigned short);

    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetOffset));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00010F] `by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md`

Evidence: MCP decompile proves the same three-string/final-word packet layout as [UID:00010E], but subtype `0x0a`; the sole modeled caller [UID:0002O5] passes inherited `ClanAttrInputDialog` fields at `+0x26c/+0x46c/+0x66c/+0x86c`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static int SubmitClanChangeHelper(
    const wchar_t *clanName,
    const wchar_t *descriptionText,
    const wchar_t *attributeText,
    unsigned short attributeType)
{
    char convertedText[256];
    unsigned char packet[0x304];
    unsigned int packetOffset = 0;

    PacketBufferWriteUInt8(packet + packetOffset++, 0x4b);
    PacketBufferWriteUInt8(packet + packetOffset++, 0x0a);
    PacketBufferWriteUInt8(packet + packetOffset++, 0x02);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, clanName, wcslen(clanName), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + packetOffset++, static_cast<unsigned char>(convertedLength));
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP, 0, descriptionText, wcslen(descriptionText), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + packetOffset++, static_cast<unsigned char>(convertedLength));
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP, 0, attributeText, wcslen(attributeText), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(packet + packetOffset++, static_cast<unsigned char>(convertedLength));
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    PacketBufferWriteUInt16BE(packet + packetOffset, attributeType);
    packetOffset += sizeof(unsigned short);

    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetOffset));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002O5] `by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md`

Evidence: MCP decompile proves a one-call method passing inherited fields `+0x26c/+0x46c/+0x66c/+0x86c` to `0x00486330`.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ClanChangeInputDialog::SubmitClanChange()
{
    return SubmitClanChangeHelper(
        m_submittedClanName,
        m_submittedDescriptionText,
        m_submittedAttributeText,
        m_submittedAttributeType);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00035D] `by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md`

Evidence: MCP decompile proves exact list count, row lookup loop, duplicate removal, `wcscpy_s` into a 32-WCHAR local, and insert at the original or replaced index. The `ListPane` helper names are inferred from existing accepted clan list source and should be recorded as source-facing names.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ClanStringListPane::InsertOrReplaceText(const wchar_t *text)
{
    int insertIndex = GetCount();

    for (int rowIndex = 0; rowIndex < insertIndex; ++rowIndex) {
        if (wcscmp(GetRowText(rowIndex), text) == 0) {
            RemoveRows(rowIndex, 1);
            insertIndex = rowIndex;
            break;
        }
    }

    wchar_t rowText[32];
    wcscpy_s(rowText, _countof(rowText), text);
    return InsertRow(insertIndex, rowText);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Raw No-Route Constructor And Raw Helper Proof Blocks

The following constructor/helper starts were actively rechecked rather than left as generic blockers. Current MCP `lookup_funcs` and `xrefs_to` find no function object and no inbound route to each raw start. Existing live construction or method behavior is covered by class declarations and child bodies. Emitting constructor bodies for these targets would assert callable source functions not supported by the current binary.

[UID:0002NZ] `0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanAppearNameInputDialog constructor-shaped range: current MCP finds no function object or inbound route to 0x004893a0, while the class declaration and OnSubmitText child carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002O4] `0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanChangeInputDialog constructor-shaped range: current MCP finds no function object or inbound route to 0x00489ff0, while the class declaration and SubmitClanChange child carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002O1] `0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanChangeNameInputDialog constructor-shaped range: current MCP finds no function object or inbound route to 0x004894d0, while the class declaration and OnSubmitText child carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021V] `0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanDepMoneyInputDialog constructor-shaped range: current MCP finds no function object or inbound route to 0x00488fa0, while the class declaration and deposit-money submit child carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021W] `0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanEnlistInputDialog constructor-shaped range: current MCP finds no function object or inbound route to 0x00489f80, while the class declaration and enlist submit child carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002O6] `0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanLeaveConfirmDialog constructor-shaped range: current MCP finds no function object or inbound route to 0x0048a060, while the class declaration and confirm/cancel children carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002NP] `0x00488630-0x00488674.ClanStringListPaneRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanStringListPane constructor-shaped range: current MCP finds no function object or inbound route to 0x00488630, while list-pane construction is represented by class declarations and live inline ClanStatusPane setup.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00035E] `0x00488740-0x00488754.ClanStringListPaneClearRowsRaw`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone source body for this retained ClanStringListPane clear-rows raw helper: current MCP finds no function object or inbound route to 0x00488740, and live row updates are represented by InsertOrReplaceText plus caller-owned list refresh paths.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00035F] `0x00488760-0x004887c7.ClanStringListPaneFindTextRaw`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone source body for this retained ClanStringListPane find-text raw helper: current MCP finds no function object or inbound route to 0x00488760, and no live caller route proves an emitted helper name or declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002NX] `0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanSummonNameInputDialog constructor-shaped range: current MCP finds no function object or inbound route to 0x00489270, while the class declaration and summon submit child carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002NT] `0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone constructor body for this retained ClanWidMoneyInputDialog constructor-shaped range: current MCP finds no function object or inbound route to 0x00489070, while the class declaration and withdraw-money submit child carry the source-visible behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### ClanStatusPane Helper And Aggregate Decisions

[UID:00010C] `0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput`

- Audit result: this page is not a single method. Exact child bodies should be created or promoted before C++ body emission: `0x00484a60-0x00484cb0` `ClanStatusPane::OnPaintFrame`, `0x00484cd0-0x00484da2` `ClanStatusPane::OnKeyInput`, and `0x00484db0-0x00484f16` `ClanStatusPane::OnMouseEvent`.
- No-code proof: emitting one aggregate body would duplicate three vtable slots and mix frame drawing, key handling, mouse hit testing, tab switching, and row-action dispatch in one false source function.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Aggregate only: split into ClanStatusPane::OnPaintFrame (0x00484a60-0x00484cb0), ClanStatusPane::OnKeyInput (0x00484cd0-0x00484da2), and ClanStatusPane::OnMouseEvent (0x00484db0-0x00484f16) before emitting source bodies.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021C] `0x00484f70-0x0048540b.ClanStatusPacketDispatcher`

- Audit result: real dispatcher function and control-flow are documented by B012, but the current source shape still depends on whether dialog construction is inlined or routed through retained local opener helpers.
- No-code proof: a formal body now would force a helperization policy that conflicts with [UID:00021S] child split state; keep this page as dispatcher evidence until exact dialog-handler children are selected.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No aggregate dispatcher body here: packet subtype control flow is documented, but formal source must first choose inline dialog construction versus retained local opener helpers shared with the 0x004877d0-0x00488594 handler band.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00010G] `0x00486800-0x00487291.ClanStatusPaneRows`

- Audit result: this page covers three row helpers. Exact child bodies should be created or promoted first: `0x00486800-0x00486cde` `ClanStatusPane::DrawStatusRowText`, `0x00486d20-0x00486f3f` `ClanStatusPane::GetStatusRowRect`, and `0x00486f90-0x00487291` `ClanStatusPane::HitTestStatusRow`.
- No-code proof: a single aggregate body would misrepresent three local helpers with different callers and return shapes.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Aggregate only: split into ClanStatusPane::DrawStatusRowText (0x00486800-0x00486cde), ClanStatusPane::GetStatusRowRect (0x00486d20-0x00486f3f), and ClanStatusPane::HitTestStatusRow (0x00486f90-0x00487291) before emitting source bodies.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021O] `0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes`

- Audit result: real function with parser/key callers; it virtual-dispatches child slots `+0x38/+0x40` over `m_joinListPane`, `m_infoListPane`, and `m_enlistListPane`.
- No-code proof: behavior is exact, but source emission would require naming the child-pane virtuals consistently across `TextEditPane`/`ListPane`/Clan list panes. Current docs do not prove those slot names; a placeholder body would fossilize decompiler-slot names.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No source body yet: RefreshChildPanes has real callers and exact child offsets, but the child-pane virtual slots at +0x38/+0x40 are not source-named across the involved pane base classes.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021P] `0x004873c0-0x00487475.ClanStatusPaneShowInfoList`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No source body for this retained raw view-switch helper: current MCP confirms the info-list behavior and padding, but finds no function object or inbound route to 0x004873c0, and selected-child virtual slots +0x30/+0x3c are not source-named.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021R] `0x00487540-0x004875f5.ClanStatusPaneShowEnlistList`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No source body for this retained raw view-switch helper: current MCP confirms the enlist-list behavior and padding, but finds no function object or inbound route to 0x00487540, and selected-child virtual slots +0x30/+0x3c are not source-named.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00010H] `0x00487600-0x0048779f.ClanStatusRowActionPacket`

- Audit result: real row-action helper, reached from `ClanStatusPane::OnMouseEvent`, sends opcode `0x4b` row actions based on current row/view text.
- No-code proof: formal emission depends on splitting [UID:00010C] `OnMouseEvent` and finalizing the row-to-subtype/action naming table. Emitting a standalone body now would use incomplete row-action symbolic names even though bytes are understood.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No source body yet: row-action packet bytes are documented, but this helper should be emitted only after OnMouseEvent is split from UID00010C and row-to-subtype/action source names are finalized.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00030P] `0x0048c590-0x0048c63f.ClanStatusPaneDestructor`

- Audit result: destructor wrapper clears/deletes class resources and is reached through compiler destructor thunks.
- No-code proof: current bytes include scalar-deleting/destructor ABI shape; ordinary `ClanStatusPane::~ClanStatusPane()` body should be emitted only after separating wrapper/thunk behavior from source destructor order.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No destructor source body here: current range is the compiler destructor/scalar-deleting wrapper band; emit ordinary ClanStatusPane::~ClanStatusPane only after wrapper/thunk behavior is separated from source destructor order.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Opcode 0x4b Packet Helper Audit

The raw request helper pages below were checked against callers/routes, packet structure, sibling accepted reports, and active packet-helper patterns. The best inferred source names are recorded in the comments. They remain no-code only where no live route exists or where the live behavior is already emitted through a caller-owned method.

[UID:00021D] `SendClanStatusRefreshRequestPacket`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone SendClanStatusRefreshRequestPacket body: the retained raw helper builds opcode 0x4b subtype 0 refresh bytes, but current route scans find no live caller/function route, so emitting it would invent an unused source helper.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021E] `SendClanEnlistRequestRefreshPacket`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone SendClanEnlistRequestRefreshPacket body: the retained raw helper builds opcode 0x4b subtype 1 refresh/request bytes, but current route scans find no live caller/function route, so emitting it would invent an unused source helper.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021F] `SendClanJoinListRefreshPacket`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone SendClanJoinListRefreshPacket body: the retained raw helper builds opcode 0x4b subtype 2 refresh bytes, but current route scans find no live caller/function route; live join-list selection emission is carried by ClanStatusPane::SendClanJoinListSelectionPacket.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021H] `SendClanLeaveRequestPacket`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone SendClanLeaveRequestPacket body: the retained raw helper builds opcode 0x4b subtype 3 request bytes, but current route scans find no live caller/function route; live leave confirmation response is emitted by ClanStatusPane::SendClanLeaveResponse.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021I] `ClanDepositMoneyRequestAndSubmitPacketHelpers`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone deposit-money helper body: the retained subtype 4 helper band has no proved live helper route, and the source-visible deposit-money submit path is already emitted by ClanDepMoneyInputDialog::OnSubmitText.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021J] `ClanDepositItemRequestAndSubmitPacketHelpers`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone deposit-item helper body: the retained subtype 5 helper band has no proved live helper route, and item dialog source emission is handled by the Clan item dialog pages rather than this empty helper strip.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00021S] `0x004877d0-0x00488594.ClanStatusPacketDialogHandlers`

- Audit result: exact child/split candidates are known. Create or promote child pages before body emission:
  - `0x004877d0-0x004879d8` `ClanStatusPane::HandleClanEnlistRequestPacket`
  - `0x004879e0-0x00487c37` `ClanStatusPane::HandleClanJoinListPacket`
  - `0x00487c40-0x00487d61` `OpenClanLeaveConfirmDialogFromPacket`
  - `0x00487d70-0x00487e13` `OpenClanDepositMoneyDialogFromPacket`
  - `0x00487e20-0x00487e9c` `OpenClanDepositItemDialogFromPacket`
  - `0x00487ea0-0x00488167` `ClanStatusPane::HandleClanMemberListOrEnlistDialogPacket`
  - `0x00488170-0x00488213` `OpenClanExpelNameDialogFromPacket`
  - `0x00488220-0x004882c3` `OpenClanSummonNameDialogFromPacket`
  - `0x004882d0-0x0048836b` `OpenClanAppearNameDialogFromPacket`
  - `0x00488370-0x0048845d` `OpenClanChangeDialogFromPacket`
  - `0x00488460-0x00488503` `OpenClanWithdrawMoneyDialogFromPacket`
  - `0x00488510-0x00488594` `OpenClanWithdrawItemDialogFromPacket`
- No-code proof: only the first, second, and sixth subranges have direct rel32 call routes; the opener siblings remain no-xref retained helpers until a dispatcher/table route is proved.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Aggregate only: split the 0x004877d0-0x00488594 dialog-handler band into the exact handler/opener ranges documented on this page before emitting source bodies.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:00010L] `0x00489600-0x00489f80.ClanAttrInputDialogCore`

- Audit result: this page covers four methods. Create or promote child pages before body emission: `0x00489600-0x00489de0` constructor, `0x00489df0-0x00489eb6` `OnDialogAction`, `0x00489ec0-0x00489f45` `ValidateInputFields`, and `0x00489f50-0x00489f80` `OnInputEvent`.
- No-code proof: a single block would merge constructor and three vtable methods; class declaration [UID:000024] plus exact child split is the correct source shape.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Aggregate only: split into ClanAttrInputDialog constructor (0x00489600-0x00489de0), OnDialogAction (0x00489df0-0x00489eb6), ValidateInputFields (0x00489ec0-0x00489f45), and OnInputEvent (0x00489f50-0x00489f80) before emitting source bodies.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Globals, Data, Vtables, And Type Dispositions

[UID:0002XG] `by-global/g_pClanStatusPane.md`

- Audit result: canonical global route remains here. Current MCP `get_bytes`/`get_global_value` for `0x0067ade4` returns zero-filled storage, and xrefs show constructor writes, method reads, cleanup, and destructor clear.
- Source disposition: emit only route comment plus children from the global page; the exact definition belongs to storage child [UID:0002XH] to avoid duplicate declarations.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Canonical route for the ClanStatusPane singleton; exact storage definition is emitted by UID0002XH so the global appears once.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002XH] `0x0067ade4-0x0067ade8.g_pClanStatusPane`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanStatusPane *g_pClanStatusPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002MQ] `0x00615570-0x006158f4.ClanPaneListVtableData`

- Audit result: compiler-generated vtable/COL data, useful for class declarations and slot routing but not source-authored arrays.
- Metadata disposition: clear `EMITTER_UIDS` to blank and keep an empty formal block.

```text
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002MN] `0x006158f4-0x00615fd8.ClanModalDialogVtableData`

```text
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0002B7] `0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer`

- Audit result: current MCP `get_global_value`/bytes show zero-filled storage and xrefs only in `sub_4877D0`; IDA name `WideCharStr` is present.
- Source disposition: emit a local static scratch buffer declaration; linkage remains intentionally file-local because no external xref requires a public symbol.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static wchar_t WideCharStr[0x10000];
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0001TY] `by-type/by-struct/ClanInputDialogLayouts.md`

- Audit result: useful cross-class layout note for `ClanNameInputDialog` and `ClanAttrInputDialog`; not a standalone source struct.
- Metadata disposition: clear `EMITTER_UIDS` to blank and keep an empty formal block. Exact field names/offsets are carried by class docs and child method pages.

```text
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Open Questions As Evidence-Backed Score Caps

These are not empty-emitter blockers after this repair:

- Child-pane virtual slots `+0x30/+0x38/+0x3c/+0x40`: exact behavior is documented, but original source names across `TextEditPane`, `ListPane`, and Clan child panes are not proved, so `RefreshChildPanes` and raw view-switch helper bodies stay comment-only.
- Aggregate child splits: exact subranges are listed for `00010C`, `00010G`, `00021S`, and `00010L`; body emission is unsafe only because the current pages are intentionally multi-body aggregates.
- Packet helper API names: `00010E`, `00010F`, `0002O5`, and `00035D` now have formal first-draft C++. Retained no-route opcode `0x4b` helper strips remain no-code because no live function/caller route exists, not because behavior was unaudited.
- `g_pClanStatusPane`: current bytes are zero-filled and lifecycle xrefs are proved; a single storage definition through [UID:0002XH] is now safe. The prior `0xffffffff` static-image wording is stale and must be corrected during callback.
- `WideCharStr`: current zero-filled buffer and local Clan handler xrefs are enough for a file-local scratch-buffer declaration; public linkage remains unproved and is intentionally not claimed.

## Superseded Original Source-Quality Taxonomy

This section through the original checklist below is superseded by `Supervisor Review Repair Addendum (Authoritative)` and the final repaired ledger/checklist at EOF. Do not use any informal code fences, category groupings, no-code rationales, score caps, or checklist items in this superseded section for implementation callback preparation.

### Superseded Original Details

The 51 markers fall into seven implementation groups:

1. Class routing pages whose source bodies are intentionally carried by child method/layout/vtable pages. These need a formal no-standalone class-page marker plus `[[CHILDREN]]`.
2. Retained raw constructor/helper islands with no IDA function object and no inbound route. These need target-specific no-code proof comments, not invented constructors.
3. ClanStatusPane modeled/raw helpers with well-described behavior but unresolved source-facing field/vslot/helper names. These need no-code proof comments and score-cap text, not placeholder C++.
4. Broad aggregate/index pages that cover multiple modeled functions. These should not receive a single giant C++ block. They need formal no-code markers and, where useful, exact subfunction boundary notes.
5. Packet helper pages whose packet bytes/routes are proved but final `PacketBuffer`/queued-sender API and field names are below source quality. These need formal no-code proof comments.
6. Compiler-generated vtable/storage/type data. These need no-code proof comments unless the original source declaration is final enough; here it is not final enough.
7. Global singleton and scratch-buffer pages. The singleton route is correct, but the declaration/linkage/initializer spelling is not final; the scratch buffer has an IDA name but unresolved original linkage. Both need formal no-code proof comments rather than guessed declarations.

## Formal Reconstruction Body Recommendations

The following text should be inserted between each target's `RECONSTRUCTION_CPP CODE:BEGIN` and `END` markers if the report is accepted. Metadata should remain unchanged unless a later supervisor callback explicitly narrows the callback scope.

### Class Routing Pages

[UID:000024] `by-class/ClanAttrInputDialog.md`

```cpp
// No standalone class-page emission for ClanAttrInputDialog; exact shared layout, constructor/action/validation behavior, derived submitters, and vtable evidence is routed by child pages.
[[CHILDREN]]
```

[UID:000027] `by-class/ClanChangeInputDialog.md`

```cpp
// No standalone class-page emission for ClanChangeInputDialog; exact raw-constructor evidence, submitter behavior, shared ClanAttrInputDialog layout, and packet-helper route is routed by child pages.
[[CHILDREN]]
```

[UID:000028] `by-class/ClanChangeNameInputDialog.md`

```cpp
// No standalone class-page emission for ClanChangeNameInputDialog; exact raw-constructor evidence and OnSubmitText behavior is routed by child pages.
[[CHILDREN]]
```

[UID:00002A] `by-class/ClanDepMoneyInputDialog.md`

```cpp
// No standalone class-page emission for ClanDepMoneyInputDialog; exact raw-constructor evidence and deposit-money OnSubmitText behavior is routed by child pages.
[[CHILDREN]]
```

[UID:00002B] `by-class/ClanEnlistInputDialog.md`

```cpp
// No standalone class-page emission for ClanEnlistInputDialog; exact raw-constructor evidence, shared attribute-dialog layout, and enlist submitter behavior is routed by child pages.
[[CHILDREN]]
```

[UID:00002C] `by-class/ClanEnlistListPane.md`

```cpp
// No standalone class-page emission for ClanEnlistListPane; exact inline construction, selected-row action, key handling, and shared draw behavior is routed by child pages.
[[CHILDREN]]
```

[UID:00002E] `by-class/ClanInfoListPane.md`

```cpp
// No standalone class-page emission for ClanInfoListPane; exact inline setup, retained raw-constructor evidence, and false-action virtuals are routed by child pages.
[[CHILDREN]]
```

[UID:00002H] `by-class/ClanJoinListPane.md`

```cpp
// No standalone class-page emission for ClanJoinListPane; exact inline construction, selected-row action, key handling, and shared draw behavior is routed by child pages.
[[CHILDREN]]
```

[UID:00002I] `by-class/ClanLeaveConfirmDialog.md`

```cpp
// No standalone class-page emission for ClanLeaveConfirmDialog; exact raw-constructor evidence and confirm/cancel packet-handler behavior is routed by child pages.
[[CHILDREN]]
```

[UID:00002J] `by-class/ClanNameInputDialog.md`

```cpp
// No standalone class-page emission for ClanNameInputDialog; exact DLGCLAN1 constructor, input handling, OK-state logic, event forwarding, and derived submitters are routed by child pages.
[[CHILDREN]]
```

[UID:00002K] `by-class/ClanStatusPane.md`

```cpp
// No standalone class-page emission for ClanStatusPane; exact constructor, packet parsing, child-pane helpers, row actions, destructor, singleton, and child classes are routed by child pages.
[[CHILDREN]]
```

[UID:00002L] `by-class/ClanStringListPane.md`

```cpp
// No standalone class-page emission for ClanStringListPane; exact raw-constructor evidence, string-list helper behavior, clear/find raw helpers, and shared draw behavior is routed by child pages.
[[CHILDREN]]
```

[UID:00002M] `by-class/ClanSummonNameInputDialog.md`

```cpp
// No standalone class-page emission for ClanSummonNameInputDialog; exact raw-constructor evidence and OnSubmitText behavior is routed by child pages.
[[CHILDREN]]
```

[UID:00002O] `by-class/ClanWidMoneyInputDialog.md`

```cpp
// No standalone class-page emission for ClanWidMoneyInputDialog; exact raw-constructor evidence and withdraw-money OnSubmitText behavior is routed by child pages.
[[CHILDREN]]
```

### Raw No-Route Constructor And Raw Helper Pages

These pages are source-evidence pages for retained binary islands. MCP currently reports no function object and no inbound xrefs for their starts. The route is not strong enough to emit standalone constructors/helper methods, but the pages should not be non-emitting because their evidence is useful and parented correctly.

[UID:0002NZ] `0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor`

```cpp
// No standalone source emission for the retained ClanAppearNameInputDialog raw constructor-shaped bytes at 0x004893a0; current MCP reports no function object and no inbound xref, while live construction behavior is covered by the class and submitter children.
```

[UID:0002O4] `0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor`

```cpp
// No standalone source emission for the retained ClanChangeInputDialog raw constructor-shaped bytes at 0x00489ff0; current MCP reports no function object and no inbound xref, while live construction and submit behavior is covered by the class, layout, and submitter children.
```

[UID:0002O1] `0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor`

```cpp
// No standalone source emission for the retained ClanChangeNameInputDialog raw constructor-shaped bytes at 0x004894d0; current MCP reports no function object and no inbound xref, while live construction behavior is covered by the class and OnSubmitText child.
```

[UID:00021V] `0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor`

```cpp
// No standalone source emission for the retained ClanDepMoneyInputDialog raw constructor-shaped bytes at 0x00488fa0; current MCP reports no function object and no inbound xref, while live construction behavior is covered by inline open paths and the deposit submitter child.
```

[UID:00021W] `0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor`

```cpp
// No standalone source emission for the retained ClanEnlistInputDialog raw constructor-shaped bytes at 0x00489f80; current MCP reports no function object and no inbound xref, while live construction and OnSubmitEnlistment behavior is covered by class/layout/submitter children.
```

[UID:0002O6] `0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor`

```cpp
// No standalone source emission for the retained ClanLeaveConfirmDialog raw constructor-shaped bytes at 0x0048a060; current MCP reports no function object and no inbound xref, while live confirm/cancel behavior is covered by the dialog handler children.
```

[UID:0002NP] `0x00488630-0x00488674.ClanStringListPaneRawConstructor`

```cpp
// No standalone source emission for the retained ClanStringListPane raw constructor-shaped bytes at 0x00488630; current MCP reports no function object and no inbound xref, while live list-pane setup and behavior is covered by ClanStatusPane inline construction and ClanStringListPane child methods.
```

[UID:00035E] `0x00488740-0x00488754.ClanStringListPaneClearRowsRaw`

```cpp
// No standalone source emission for the retained ClanStringListPane clear-rows raw helper bytes at 0x00488740; current MCP reports no function object and no inbound xref, so the page remains evidence for possible inlined or orphaned list behavior.
```

[UID:00035F] `0x00488760-0x004887c7.ClanStringListPaneFindTextRaw`

```cpp
// No standalone source emission for the retained ClanStringListPane find-text raw helper bytes at 0x00488760; current MCP reports no function object and no inbound xref, so the page remains evidence for possible inlined or orphaned list behavior.
```

[UID:0002NX] `0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor`

```cpp
// No standalone source emission for the retained ClanSummonNameInputDialog raw constructor-shaped bytes at 0x00489270; current MCP reports no function object and no inbound xref, while live construction behavior is covered by inline open paths and the OnSubmitText child.
```

[UID:0002NT] `0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor`

```cpp
// No standalone source emission for the retained ClanWidMoneyInputDialog raw constructor-shaped bytes at 0x00489070; current MCP reports no function object and no inbound xref, while live construction behavior is covered by inline open paths and the withdraw submitter child.
```

### ClanStatusPane And ClanStringListPane Helper Pages

These pages are real or bounded source-authored helpers, but the current docs intentionally cap C++ emission because final source-facing field names, vtable slot names, row type names, or packet helper API names are not yet source-quality. The no-code comments below are not generic future-work placeholders; they preserve the exact evidence-backed score cap.

[UID:00010C] `0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput`

```cpp
// No standalone C++ body for this ClanStatusPane frame/input aggregate yet; it spans multiple modeled helper bodies and the current page is an evidence/index page until exact child splits and final source-facing slot names are ready.
```

[UID:00021C] `0x00484f70-0x0048540b.ClanStatusPacketDispatcher`

```cpp
// No standalone C++ body for this ClanStatusPane packet dispatcher yet; packet family dispatch behavior is documented, but final source-facing parser names and child handler split policy remain the evidence-backed score cap.
```

[UID:00010G] `0x00486800-0x00487291.ClanStatusPaneRows`

```cpp
// No standalone C++ body for this ClanStatusPane row aggregate yet; it spans several modeled row/list helpers and should remain an evidence/index page until exact child splits and final row source names are ready.
```

[UID:00021O] `0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes`

```cpp
// No standalone C++ body for ClanStatusPaneRefreshChildPanes yet; MCP proves the six child-pane virtual dispatches over m_joinListPane, m_infoListPane, and m_enlistListPane, but the child vtable slot names at +0x38/+0x40 are still below source quality.
```

[UID:00021P] `0x004873c0-0x00487475.ClanStatusPaneShowInfoList`

```cpp
// No standalone C++ body for ClanStatusPaneShowInfoList yet; MCP proves the raw no-function body, view byte 2, child offset +0x2510, shared rectangle, inline refresh sequence, and no inbound xref caveat, but source reachability and selected-child slot names remain capped.
```

[UID:00021R] `0x00487540-0x004875f5.ClanStatusPaneShowEnlistList`

```cpp
// No standalone C++ body for ClanStatusPaneShowEnlistList yet; MCP proves the raw no-function body, view byte 4, child offset +0x2518, shared rectangle, inline refresh sequence, and no inbound xref caveat, but source reachability and selected-child slot names remain capped.
```

[UID:00010H] `0x00487600-0x0048779f.ClanStatusRowActionPacket`

```cpp
// No standalone C++ body for ClanStatusRowActionPacket yet; packet write behavior and caller route are documented, but final row-action helper names and packet writer API names remain below source quality.
```

[UID:00030P] `0x0048c590-0x0048c63f.ClanStatusPaneDestructor`

```cpp
// No standalone C++ body for ClanStatusPaneDestructor yet; destructor/cleanup behavior and singleton lifecycle are documented, but compiler destructor thunks and final source-owned cleanup shape are not ready for a direct body.
```

[UID:00035D] `0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText`

```cpp
// No standalone C++ body for ClanStringListPaneInsertOrReplaceText yet; MCP proves the count/search/remove/copy/insert behavior and 32-WCHAR stack buffer, but final list-row type and ListPane helper method names remain below source quality.
```

### Packet Helper And Dialog Core Pages

[UID:00021D] `0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket`

```cpp
// No standalone C++ body for SendClanStatusRefreshRequestPacket yet; opcode 0x4b packet behavior is documented, but final PacketBuffer and queued-sender API names remain below source quality.
```

[UID:00021E] `0x004854b0-0x00485518.SendClanEnlistRequestRefreshPacket`

```cpp
// No standalone C++ body for SendClanEnlistRequestRefreshPacket yet; opcode 0x4b packet behavior is documented, but final PacketBuffer and queued-sender API names remain below source quality.
```

[UID:00021F] `0x00485520-0x00485588.SendClanJoinListRefreshPacket`

```cpp
// No standalone C++ body for SendClanJoinListRefreshPacket yet; opcode 0x4b packet behavior is documented, but final PacketBuffer and queued-sender API names remain below source quality.
```

[UID:00021H] `0x00485690-0x004856f9.SendClanLeaveRequestPacket`

```cpp
// No standalone C++ body for SendClanLeaveRequestPacket yet; opcode 0x4b packet behavior is documented, but final PacketBuffer, queued-sender API, and source helper names remain below source quality.
```

[UID:00021I] `0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers`

```cpp
// No standalone C++ body for ClanDepositMoneyRequestAndSubmitPacketHelpers yet; deposit request/submit packet behavior is documented, but final money-field and packet writer API names remain below source quality.
```

[UID:00021J] `0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers`

```cpp
// No standalone C++ body for ClanDepositItemRequestAndSubmitPacketHelpers yet; deposit-item request/submit packet behavior is documented, but final item-field and packet writer API names remain below source quality.
```

[UID:00010E] `0x00485ac0-0x00485cbd.SendClanAttributePacket`

```cpp
// No standalone C++ body for SendClanAttributePacket yet; MCP and docs prove the subtype/action packet helper and caller route, but final three-string field names and packet writer API names remain below source quality.
```

[UID:00010F] `0x00486330-0x0048652d.SubmitClanChangeHelper`

```cpp
// No standalone C++ body for SubmitClanChangeHelper yet; MCP and docs prove the subtype 10 action 2 packet helper and 0x0048a030 caller route, but final submitted-field names and packet writer API names remain below source quality.
```

[UID:00021S] `0x004877d0-0x00488594.ClanStatusPacketDialogHandlers`

```cpp
// No standalone C++ body for ClanStatusPacketDialogHandlers as one aggregate; MCP proves this range contains multiple modeled dialog-handler functions, so the page remains an evidence/index route until exact child bodies are split or individually emitted.
```

[UID:00010L] `0x00489600-0x00489f80.ClanAttrInputDialogCore`

```cpp
// No standalone C++ body for ClanAttrInputDialogCore yet; constructor, action, validation, and input behavior are documented, but final widget/control helper names and source-facing member names remain below source quality.
```

[UID:0002O5] `0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange`

```cpp
// No standalone C++ body for ClanChangeInputDialogSubmitClanChange yet; MCP proves the vtable-only submitter, sole SubmitClanChangeHelper callee, and inherited +0x26c/+0x46c/+0x66c/+0x86c arguments, but final field/helper names remain below source quality.
```

### Global, Data, Vtable, And Type Pages

[UID:0002XG] `by-global/g_pClanStatusPane.md`

```cpp
// No standalone source declaration for g_pClanStatusPane yet; the ClanStatusPane singleton route and lifecycle writes are documented, but final declaration/linkage/initializer spelling remains below source quality.
[[CHILDREN]]
```

[UID:0002XH] `0x0067ade4-0x0067ade8.g_pClanStatusPane`

```cpp
// Storage bytes for g_pClanStatusPane are documented here but emitted, when ready, by the canonical global page; current evidence records the 0xffffffff static image value and ClanStatusPane lifecycle writes.
```

[UID:0002MQ] `0x00615570-0x006158f4.ClanPaneListVtableData`

```cpp
// No standalone C++ vtable array emission for compiler-generated Clan pane-list vtable data; source classes and virtual methods emit through the corresponding class and method pages.
```

[UID:0002MN] `0x006158f4-0x00615fd8.ClanModalDialogVtableData`

```cpp
// No standalone C++ vtable array emission for compiler-generated Clan modal-dialog vtable data; source classes and virtual methods emit through the corresponding class and method pages.
```

[UID:0002B7] `0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer`

```cpp
// No standalone source declaration for the 65536-WCHAR Clan scratch buffer yet; MCP proves the loader-zeroed storage, WideCharStr IDA name, and sub_4877D0 caller route, but original symbol linkage remains below source quality.
```

[UID:0001TY] `by-type/by-struct/ClanInputDialogLayouts.md`

```cpp
// No standalone struct declaration for the shared Clan input-dialog layout notes; exact field offsets are documented here, while source class declarations and method bodies are routed by ClanNameInputDialog, ClanAttrInputDialog, and derived child pages.
```

## Boundary, Split, And Padding Findings

- Clan by-memory filenames use an inclusive end-address convention in current docs. For example, `0x00487370-0x004873b5` documents an IDA function size `0x46` ending exclusive at `0x004873b6`. Do not rename pages solely because MCP function sizes end at the next byte.
- `0x00484a60-0x00484f16` is a multi-body ClanStatusPane frame/input aggregate:
  - `0x00484a60` -> `sub_484A60`, size `0x251`, exclusive end `0x00484cb1`
  - `0x00484cd0` -> `sub_484CD0`, size `0xd3`, exclusive end `0x00484da3`
  - `0x00484db0` -> `sub_484DB0`, size `0x167`, exclusive end `0x00484f17`
  - Current page end `0x00484f16` is consistent as an inclusive filename end.
- `0x00486800-0x00487291` is a multi-body ClanStatusPane rows aggregate:
  - `0x00486800` -> `sub_486800`, size `0x4df`, exclusive end `0x00486cdf`
  - `0x00486d20` -> `sub_486D20`, size `0x220`, exclusive end `0x00486f40`
  - `0x00486f90` -> `sub_486F90`, size `0x302`, exclusive end `0x00487292`
  - Current page end `0x00487291` is consistent as an inclusive filename end.
- `0x004873c0-0x00487475` and `0x00487540-0x004875f5` are raw no-function bounded helper bodies with confirmed padding after their `retn` bytes. They should not be split or renamed during this empty-emitter callback.
- `0x004877d0-0x00488594` contains multiple modeled dialog-handler functions:
  - `0x4877d0` size `0x208`
  - `0x4879e0` size `0x257`
  - `0x487c40` size `0x121`
  - `0x487d70` size `0xa3`
  - `0x487e20` size `0x7c`
  - `0x487ea0` size `0x2c7`
  - `0x488170` size `0xa3`
  - `0x488220` size `0xa3`
  - `0x4882d0` size `0x9b`
  - `0x488370` size `0xed`
  - `0x488460` size `0xa3`
  - `0x488510` size `0x84`
  This is an aggregate/index page. The correct empty-marker repair is a formal aggregate no-code marker, not a single undifferentiated C++ body.
- `0x00488680-0x0048873e` is a real `ClanStringListPane` helper with exact padding around it. It remains no-code only because final row/ListPane source names are not proven, not because the binary behavior is unknown.
- `0x0048a030-0x0048a059` is a real vtable-only `ClanChangeInputDialog` submitter with one callee (`0x00486330`) and no direct callers. It remains no-code only because final field/helper names are not source-quality.

## Owner And Emitter Route Reanalysis

The direct owner/emitter routes are currently correct:

- The file root [UID:0000I8][Clan] owns the feature-family source route for status pane, list panes, modal clan dialogs, opcode `0x4b` helpers, singleton storage, and the shared input-dialog layout notes.
- Class pages directly own their method/raw/data children when the child behavior touches only that class's documented fields or vtable route.
- `by-global/g_pClanStatusPane.md` remains the canonical global for `0x0067ade4`; the exact storage page remains a child of that global.
- Vtable data pages remain owned by `0000I8` because the vtable/COL cluster is for the Clan family, but they should not hand-emit arrays.
- `WideCharStrGlobalBuffer` remains with `0000I8` because its real code base xrefs are in `sub_4877D0`, called from the clan status packet dispatcher path.

Rejected owner/emitter alternatives:

- Do not move this family wholesale to [UID:0000IA][ClanDialogs]. Current Clan source root is stronger (`90/85`) and current file docs already treat `ClanDialogs` as a lower-confidence split candidate.
- Do not clear child `EMITTER_UIDS` to reduce empty markers. That would hide source-quality state instead of documenting it.
- Do not mark the raw constructor islands non-reconstructable. The pages preserve useful source-placement evidence and are already attached to the relevant class/file route; they only need target-specific no-code proof.
- Do not hand-edit generated `Clan.cpp`, tracker rows, coverage reports, validator state, locks, executed report archives, or supervisor ledgers.

## Score Rationale And Caps

No score bump is required to fix the generated empty markers. The score caps in the current docs are evidence-backed:

- Class pages remain below final confidence because class declarations, exact original class/source-file split, and some constructor islands are not fully proved.
- Raw constructor/helper pages remain at current confidence because MCP shows no function object and no inbound xref to the retained start addresses.
- ClanStatusPane tab/view helpers remain capped because direct reachability and child vtable slot names (`+0x38/+0x40` and selected-child `+0x30/+0x3c`) are not final source names.
- Packet helpers remain capped because packet bytes and routes are proved but final source helper/API naming is unresolved.
- `ClanStatusPacketDialogHandlers` remains capped as a multi-function aggregate.
- Vtable pages remain capped because they are compiler-generated data derived from source classes, not source arrays.
- `g_pClanStatusPane` and `WideCharStr` remain capped because declaration/linkage/initializer spelling is unresolved even though storage and use are proved.
- `ClanInputDialogLayouts` remains capped because it is a cross-class layout note, not a standalone source struct declaration.

These caps are not future-work blockers for the empty-emitter pass. They are the reason the formal no-code proof comments are the correct source-quality repair for these pages.

## Rejected Alternatives

- Rejected fallback-only report: MCP was available and current.
- Rejected editing generated `auto-generated/NexusTK/social/Clan.cpp`: generated files are validator-owned.
- Rejected broad `Clan.cpp` by-file metadata changes: the file route is already correct.
- Rejected a single C++ body for each aggregate page (`00010C`, `00010G`, `00021S`): those pages cover multiple bodies or serve as indexes.
- Rejected guessed source declarations for `g_pClanStatusPane` and `WideCharStr`: storage is proved, but declaration/linkage/initializer spelling is not.
- Rejected hand-written vtable arrays for `0002MQ` and `0002MN`: those are compiler-generated class artifacts.
- Rejected converting no-function raw constructor islands into formal constructors: MCP currently shows no modeled function and no inbound route for those starts.
- Rejected score inflation solely because a no-code marker is added: the remaining caps are factual and should remain until a separate source-quality pass closes them.

## Open Questions

These are score caps, not blockers for the empty-emitter repair:

- Final original source-file split between `Clan.cpp` and a possible `ClanDialogs.cpp`; current evidence favors [UID:0000I8][Clan] for this callback.
- Final source names for child pane virtual slots `+0x38/+0x40` and selected-child slots `+0x30/+0x3c`.
- Final packet writer/queued sender helper names for opcode `0x4b` helpers.
- Final source-facing member names for `ClanAttrInputDialog` submitted fields at `+0x26c/+0x46c/+0x66c/+0x86c`.
- Final original linkage and initializer spelling for `g_pClanStatusPane`.
- Final original symbol/linkage for the `WideCharStr` 65536-WCHAR scratch buffer.
- Whether some aggregate pages should later be split into exact function-child pages. Current empty-emitter repair does not require that split.

## Claim And Incorporation Ledger

| Claim | Target/support docs | Implementation state |
| --- | --- | --- |
| `Clan.cpp` has 51 current empty markers under [UID:0000I8] with generated command id `000000002158` | `auto-generated/NexusTK/social/Clan.cpp`, `auto-generated/-ag-research-tracker.md`, [UID:0000I8][Clan](by-file/Clan.md) | Report-only; evidence recorded here, no generated edits |
| MCP is available and current, so this report is not fallback-only | MCP endpoint/session evidence | Report-only; evidence recorded here |
| File root owner/path are correct and should not be changed | [UID:0000I8][Clan](by-file/Clan.md) | Pending supervisor callback only if support note is desired; no metadata change recommended |
| 14 blank class pages need formal no-standalone marker plus `[[CHILDREN]]` | `000024`, `000027`, `000028`, `00002A`, `00002B`, `00002C`, `00002E`, `00002H`, `00002I`, `00002J`, `00002K`, `00002L`, `00002M`, `00002O` | Pending implementation callback |
| 11 retained raw constructor/helper pages need target-specific no-route no-code proof comments | `0002NZ`, `0002O4`, `0002O1`, `00021V`, `00021W`, `0002O6`, `0002NP`, `00035E`, `00035F`, `0002NX`, `0002NT` | Pending implementation callback |
| ClanStatusPane/StringList helper pages need no-code proof comments preserving exact MCP behavior and score caps | `00010C`, `00021C`, `00010G`, `00021O`, `00021P`, `00021R`, `00010H`, `00030P`, `00035D` | Pending implementation callback |
| Packet helper/dialog core pages need no-code proof comments because bytes/routes are proved but source helper/member names are not final | `00021D`, `00021E`, `00021F`, `00021H`, `00021I`, `00021J`, `00010E`, `00010F`, `00021S`, `00010L`, `0002O5` | Pending implementation callback |
| Global/data/vtable/type pages need no-code proof comments, not guessed declarations or hand-written arrays | `0002XG`, `0002XH`, `0002MQ`, `0002MN`, `0002B7`, `0001TY` | Pending implementation callback |
| Do not alter TimerMgr UID-collision docs, generated files, coverage reports, validator state, IDA DB, executed archives, supervisor ledgers, or lock files | Project-wide constraints | Report-only; no prohibited edits made |

## Implementation Tracking Checklist

Leave all items unchecked until the supervisor validates this report and sends an implementation callback.

- [ ] Acquire short leases only for the by-* files about to be edited immediately.
- [ ] Edit [UID:000024] `by-class/ClanAttrInputDialog.md` with the exact class routing block above.
- [ ] Edit [UID:000027] `by-class/ClanChangeInputDialog.md` with the exact class routing block above.
- [ ] Edit [UID:000028] `by-class/ClanChangeNameInputDialog.md` with the exact class routing block above.
- [ ] Edit [UID:00002A] `by-class/ClanDepMoneyInputDialog.md` with the exact class routing block above.
- [ ] Edit [UID:00002B] `by-class/ClanEnlistInputDialog.md` with the exact class routing block above.
- [ ] Edit [UID:00002C] `by-class/ClanEnlistListPane.md` with the exact class routing block above.
- [ ] Edit [UID:00002E] `by-class/ClanInfoListPane.md` with the exact class routing block above.
- [ ] Edit [UID:00002H] `by-class/ClanJoinListPane.md` with the exact class routing block above.
- [ ] Edit [UID:00002I] `by-class/ClanLeaveConfirmDialog.md` with the exact class routing block above.
- [ ] Edit [UID:00002J] `by-class/ClanNameInputDialog.md` with the exact class routing block above.
- [ ] Edit [UID:00002K] `by-class/ClanStatusPane.md` with the exact class routing block above.
- [ ] Edit [UID:00002L] `by-class/ClanStringListPane.md` with the exact class routing block above.
- [ ] Edit [UID:00002M] `by-class/ClanSummonNameInputDialog.md` with the exact class routing block above.
- [ ] Edit [UID:00002O] `by-class/ClanWidMoneyInputDialog.md` with the exact class routing block above.
- [ ] Edit raw no-route pages `0002NZ`, `0002O4`, `0002O1`, `00021V`, `00021W`, `0002O6`, `0002NP`, `00035E`, `00035F`, `0002NX`, and `0002NT` with the exact target-specific no-code proof comments above.
- [ ] Edit helper pages `00010C`, `00021C`, `00010G`, `00021O`, `00021P`, `00021R`, `00010H`, `00030P`, and `00035D` with the exact target-specific no-code proof comments above.
- [ ] Edit packet/helper/core pages `00021D`, `00021E`, `00021F`, `00021H`, `00021I`, `00021J`, `00010E`, `00010F`, `00021S`, `00010L`, and `0002O5` with the exact target-specific no-code proof comments above.
- [ ] Edit global/data/type pages `0002XG`, `0002XH`, `0002MQ`, `0002MN`, `0002B7`, and `0001TY` with the exact target-specific no-code proof comments above.
- [ ] Do not change [UID:0000I8] metadata unless the implementation callback explicitly adds a support-note edit; no by-file metadata change is recommended by this report.
- [ ] Do not edit generated files, `-coverage-report.md` files, project-level generated reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, lock files, or TimerMgr UID-collision docs.
- [ ] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* file:
  - `python .\tools\validator.py --mode file --file by-class/ClanAttrInputDialog.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanChangeInputDialog.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanChangeNameInputDialog.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanDepMoneyInputDialog.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanEnlistInputDialog.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanEnlistListPane.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanInfoListPane.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanJoinListPane.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanLeaveConfirmDialog.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanNameInputDialog.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanStatusPane.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanStringListPane.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanSummonNameInputDialog.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class/ClanWidMoneyInputDialog.md --apply --queue-timeout 240 --wait-generated`
  - Run the same scoped command pattern for each edited `by-memory`, `by-global`, and `by-type/by-struct` file listed in this checklist.
- [ ] After validators, compare `auto-generated/NexusTK/social/Clan.cpp` header `validator-command-id` and `validator-refreshed-at` with the last relevant validator command metadata; generated output must be equal/newer when reporting completion.
- [ ] Confirm `auto-generated/NexusTK/social/Clan.cpp` no longer contains empty markers for the implemented subset, or report any remaining marker UID/path exactly.
- [ ] Release leases immediately after the edit/validator batch.
- [ ] Update this report's Claim And Incorporation Ledger and Implementation Tracking Checklist during the callback with applied/already-present/excluded-with-reason states and proof.
- [ ] Return implementation checkpoint with changed files, leases used/released, validator command ids/timestamps/exit codes/ok counts, generated freshness state, and unchecked items.

## Final Repaired Claim And Incorporation Ledger

This final ledger supersedes the original broad ledger above.

| Claim / accepted detail | Target/support doc section | Callback implementation state |
| --- | --- | --- |
| File root [UID:0000I8] remains canonical owner/path, but needs a support note explaining the mixed child repair | `by-file/Clan.md` Status/Changes or new source-quality note; no metadata change | applied: added `2026-06-30 B007 Empty-Emitter Repair Note`; metadata remains `90/85`, `CANONICAL_OWNER:FILE`, path `NexusTK/social/` |
| Current generated evidence is 78 emitters, 27 filled, 51 empty under command `000000002158`; MCP remained available in repair pass | `by-file/Clan.md` support note and report evidence only | applied: support note states the empty-marker cause and child repair categories; generated files were not manually edited |
| Class pages are declaration-ready with `[[CHILDREN]]` after declarations | `by-class/ClanAttrInputDialog.md`, `ClanChangeInputDialog.md`, `ClanChangeNameInputDialog.md`, `ClanDepMoneyInputDialog.md`, `ClanEnlistInputDialog.md`, `ClanEnlistListPane.md`, `ClanInfoListPane.md`, `ClanJoinListPane.md`, `ClanLeaveConfirmDialog.md`, `ClanNameInputDialog.md`, `ClanStatusPane.md`, `ClanStringListPane.md`, `ClanSummonNameInputDialog.md`, `ClanWidMoneyInputDialog.md` formal C++ blocks | applied: all 14 class formal blocks populated exactly with declarations plus `[[CHILDREN]]`; validators `000000002217` through `000000002233`; final generated header refreshed by `000000002376` |
| Retained raw constructor/helper starts have no function/xref route and need formal target-specific no-code comments | `0002NZ`, `0002O4`, `0002O1`, `00021V`, `00021W`, `0002O6`, `0002NP`, `00035E`, `00035F`, `0002NX`, `0002NT` formal C++ blocks | applied: exact no-route comments inserted; validators `000000002263`, `000000002265`-`000000002268`, `000000002271`-`000000002276` |
| Exact helper bodies are source-ready | `00010E`, `00010F`, `0002O5`, `00035D` formal C++ blocks | applied: exact first-draft C++ bodies inserted; validators `000000002278`, `000000002279`, `000000002280`, `000000002281` |
| Aggregate pages require exact child split before body emission | `00010C`, `00010G`, `00021S`, `00010L` body/no-code sections and split/range sections | applied: exact aggregate no-code comments inserted; existing pages preserve split range evidence; validators `000000002291`, `000000002294`, `000000002310`, `000000002311` |
| Dispatcher/helper pages with known behavior but unsafe source shape need item-specific no-code proof | `00021C`, `00021O`, `00021P`, `00021R`, `00010H`, `00030P` formal C++ blocks and reconstruction notes | applied: exact no-code comments inserted; validators `000000002293`, `000000002296`, `000000002297`, `000000002299`, `000000002300`, `000000002301` |
| Retained opcode `0x4b` no-route packet helper bands need best inferred names plus no-code proof | `00021D`, `00021E`, `00021F`, `00021H`, `00021I`, `00021J` formal C++ blocks and packet-helper notes | applied: exact no-live-route packet helper comments inserted; validators `000000002303`-`000000002308` |
| `g_pClanStatusPane` current storage is zero-filled, not stale `0xffffffff`; emit one actual definition through storage child | `by-global/g_pClanStatusPane.md`, `by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md` | applied: global page routes children; storage child emits `ClanStatusPane *g_pClanStatusPane = NULL;` and stale initializer wording is replaced with zero-filled MCP evidence; validators `000000002322`, `000000002324`, final wording validator `000000002375` |
| Vtable pages are compiler-generated and should not emit source arrays | `0002MQ`, `0002MN` metadata and formal blocks | applied: `EMITTER_UIDS` cleared to blank and formal C++ left empty; compiler-generated evidence preserved; validators `000000002325`, `000000002326` |
| `WideCharStr` scratch buffer is source-ready as a file-local zero-filled buffer | `by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md` formal C++ block | applied: emitted `static wchar_t WideCharStr[0x10000];` and corrected summary/status to current zero-filled evidence; validator `000000002327` |
| `ClanInputDialogLayouts` is a cross-class layout note, not a source struct | `by-type/by-struct/ClanInputDialogLayouts.md` metadata and formal block | applied: `EMITTER_UIDS` cleared to blank and formal C++ left empty; callback change note records cross-class layout disposition; validator `000000002328` |
| TimerMgr UID-collision docs, generated files, coverage reports, project-level generated reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, and lock files are excluded | Project-wide constraints | excluded-with-reason: assignment explicitly forbids these edits; no prohibited files were manually edited |

## Final Repaired Implementation Tracking Checklist

Implementation callback status: accepted items are checked below with proof. Validator-owned generated/projected files refreshed through scoped validators; no generated file was manually edited.

- [x] Acquire short leases only for the next immediate by-* edit batch; release them immediately after that edit/validator batch.
- [x] Update `by-file/Clan.md` with a support note only: root metadata stays `90/85`, canonical file owner/path stay unchanged, and the note points to the child declaration/body/no-code/storage repairs in this report.
- [x] Edit `by-class/ClanAttrInputDialog.md` with the exact declaration shell for [UID:000024].
- [x] Edit `by-class/ClanChangeInputDialog.md` with the exact declaration shell for [UID:000027].
- [x] Edit `by-class/ClanChangeNameInputDialog.md` with the exact declaration shell for [UID:000028].
- [x] Edit `by-class/ClanDepMoneyInputDialog.md` with the exact declaration shell for [UID:00002A].
- [x] Edit `by-class/ClanEnlistInputDialog.md` with the exact declaration shell for [UID:00002B].
- [x] Edit `by-class/ClanEnlistListPane.md` with the exact declaration shell for [UID:00002C].
- [x] Edit `by-class/ClanInfoListPane.md` with the exact declaration shell for [UID:00002E].
- [x] Edit `by-class/ClanJoinListPane.md` with the exact declaration shell for [UID:00002H].
- [x] Edit `by-class/ClanLeaveConfirmDialog.md` with the exact declaration shell for [UID:00002I].
- [x] Edit `by-class/ClanNameInputDialog.md` with the exact declaration shell for [UID:00002J].
- [x] Edit `by-class/ClanStatusPane.md` with the exact declaration shell for [UID:00002K] and support prose stating method bodies remain child-owned.
- [x] Edit `by-class/ClanStringListPane.md` with the exact declaration shell for [UID:00002L].
- [x] Edit `by-class/ClanSummonNameInputDialog.md` with the exact declaration shell for [UID:00002M].
- [x] Edit `by-class/ClanWidMoneyInputDialog.md` with the exact declaration shell for [UID:00002O].
- [x] Edit `by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md` with the exact [UID:0002NZ] no-route constructor comment.
- [x] Edit `by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md` with the exact [UID:0002O4] no-route constructor comment.
- [x] Edit `by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md` with the exact [UID:0002O1] no-route constructor comment.
- [x] Edit `by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md` with the exact [UID:00021V] no-route constructor comment.
- [x] Edit `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md` with the exact [UID:00021W] no-route constructor comment.
- [x] Edit `by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md` with the exact [UID:0002O6] no-route constructor comment.
- [x] Edit `by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md` with the exact [UID:0002NP] no-route constructor comment.
- [x] Edit `by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md` with the exact [UID:00035E] no-route raw helper comment.
- [x] Edit `by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md` with the exact [UID:00035F] no-route raw helper comment.
- [x] Edit `by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md` with the exact [UID:0002NX] no-route constructor comment.
- [x] Edit `by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md` with the exact [UID:0002NT] no-route constructor comment.
- [x] Edit `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md` with the exact [UID:00010E] first-draft C++ body.
- [x] Edit `by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md` with the exact [UID:00010F] first-draft C++ body.
- [x] Edit `by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md` with the exact [UID:0002O5] first-draft C++ body.
- [x] Edit `by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md` with the exact [UID:00035D] first-draft C++ body.
- [x] Edit `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md` with the exact [UID:00010C] aggregate no-code block and split list.
- [x] Edit `by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md` with the exact [UID:00021C] dispatcher source-shape no-code block.
- [x] Edit `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md` with the exact [UID:00010G] aggregate no-code block and split list.
- [x] Edit `by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md` with the exact [UID:00021O] child-vslot no-code block.
- [x] Edit `by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md` with the exact [UID:00021P] raw view-switch no-code block.
- [x] Edit `by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md` with the exact [UID:00021R] raw view-switch no-code block.
- [x] Edit `by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md` with the exact [UID:00010H] row-action source-shape no-code block.
- [x] Edit `by-memory/0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md` with the exact [UID:00030P] destructor wrapper no-code block.
- [x] Edit `by-memory/0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket.md` with the exact [UID:00021D] no-live-route packet helper comment.
- [x] Edit `by-memory/0x004854b0-0x00485518.SendClanEnlistRequestRefreshPacket.md` with the exact [UID:00021E] no-live-route packet helper comment.
- [x] Edit `by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md` with the exact [UID:00021F] no-live-route packet helper comment.
- [x] Edit `by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md` with the exact [UID:00021H] no-live-route packet helper comment.
- [x] Edit `by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md` with the exact [UID:00021I] no-live-route packet helper comment.
- [x] Edit `by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md` with the exact [UID:00021J] no-live-route packet helper comment.
- [x] Edit `by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md` with the exact [UID:00021S] aggregate no-code block and twelve child/sibling range list.
- [x] Edit `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md` with the exact [UID:00010L] aggregate no-code block and four child method range list.
- [x] Edit `by-global/g_pClanStatusPane.md` with the exact route comment plus `[[CHILDREN]]`; keep canonical global route.
- [x] Edit `by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md` with `ClanStatusPane *g_pClanStatusPane = NULL;` and replace stale `0xffffffff` wording with current zero-filled MCP evidence.
- [x] Edit `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md` to clear `EMITTER_UIDS` and leave the formal C++ block empty; preserve vtable/COL evidence as compiler-generated support.
- [x] Edit `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md` to clear `EMITTER_UIDS` and leave the formal C++ block empty; preserve vtable/COL evidence as compiler-generated support.
- [x] Edit `by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md` with `static wchar_t WideCharStr[0x10000];` and current zero-filled storage/xref evidence.
- [x] Edit `by-type/by-struct/ClanInputDialogLayouts.md` to clear `EMITTER_UIDS`, leave the formal C++ block empty, and state that the layout note is carried by class/method pages rather than a standalone source struct.
- [x] Do not edit TimerMgr UID-collision docs, generated files, `-coverage-report.md` files, project-level generated reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
- [x] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* file using `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`; include `--wait-generated` for `by-file/Clan.md` and class/file targets where generated `auto-generated/NexusTK/social/Clan.cpp` freshness matters.
- [x] Record every validator command id, command timestamp, exit code, and ok count in the callback result.
- [x] Check `auto-generated/NexusTK/social/Clan.cpp` header after the final validator batch; report whether `validator-command-id`/`validator-refreshed-at` are equal/newer than the last relevant validator command.
- [x] Confirm generated `Clan.cpp` no longer has markers for the implemented subset; if any remain, report UID/path and whether it is intentionally excluded.
- [x] Release all leases immediately after the edit/validator batch.
- [x] Update this report during implementation with applied/already-present/excluded-with-reason proof per item, then return a checkpoint with changed files, leases, validators, generated freshness state, and unchecked items.

### Implementation Callback Proof Summary

- Leases: first batch `by-file/Clan.md` plus 14 class pages leased successfully; `unlease` later reported no active B007 leases because the batch leases had already expired/cleared by cleanup. Raw/helper batch, aggregate/packet batch, and data/type batch leases were acquired successfully and released successfully. Final wording/proof lease covered `by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md` and this report, then was released. Final current lease report shows no active leases.
- Validators: every changed by-* file was validated from `E:\NTK\GhidraBridge\source-3\project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; `--wait-generated` was used for `by-file/Clan.md` and the first class/file batch where generated `Clan.cpp` freshness mattered. All scoped validators exited `0` with `ok: 1`.
- Validator command IDs:
  - by-file/class batch: `000000002216` through `000000002233`, all exit `0`/`ok: 1`; class/file generated refresh completed during that batch.
  - raw constructor/helper and exact helper-body batch: `000000002263`, `000000002265`-`000000002268`, `000000002271`-`000000002276`, and `000000002278`-`000000002281`, all exit `0`/`ok: 1`.
  - aggregate/dispatcher/packet batch: `000000002291`, `000000002293`, `000000002294`, `000000002296`, `000000002297`, `000000002299`-`000000002301`, `000000002303`-`000000002308`, `000000002310`, and `000000002311`, all exit `0`/`ok: 1`.
  - global/data/type batch: `000000002322`, `000000002324`-`000000002328`, all exit `0`/`ok: 1`; final storage-child wording validator `000000002375`, timestamp `2026-06-30T05:03:21-04:00`, exit `0`/`ok: 1`, `generated_refresh: deferred`.
  - final generated freshness check: `000000002376`, timestamp `2026-06-30T05:03:29-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- Validator warnings: `by-file/Clan.md` final refresh reported existing `missing_ref_uid` warnings for `0003HE`, `000411`, `000412`, `000413`, `0003B8`, and `0003B9`, plus broad autogen informational warnings already present outside this callback scope (`autogen_children_marker_missing`, `autogen_emitter_has_no_code`, and `autogen_children_fallback_insert`). `00010C` validation reported existing `missing_ref_uid 0003B8`. These did not block the scoped validators and were not introduced as by-* edit blockers in this callback.
- Generated freshness: final `auto-generated/NexusTK/social/Clan.cpp` header is `validator-command-id: 000000002376`, `validator-refreshed-at: 2026-06-30T05:03:29-04:00`, matching the final refresh command. A generated scan found no remaining `Empty Emitter Marker` lines in `Clan.cpp`.
- Exclusions honored: no TimerMgr UID-collision docs, manual `-coverage-report.md` files, IDA DB, executed archives, supervisor ledgers, lock files, or generated files were manually edited. Validator-owned generated/projected stats/tracker/registry side effects were produced only by scoped validator commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000I8-Clan-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000I8-Clan-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T05:07:32","uid":"0000I8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
