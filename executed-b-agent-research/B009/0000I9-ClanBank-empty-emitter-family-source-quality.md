** TARGET-REPORT-UID:0000I9 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0000I9] ClanBank Empty-Emitter Family Source-Quality Report

## Executive Disposition

Same-report revision recommendation: implement the full immediate batch of all 15 current empty emitters in `auto-generated/NexusTK/social/ClanBank.cpp`, but do not resolve source-authored method clusters with marker-only aggregate comments. The revised implementation plan is:

- Add declaration-level class shells with `[[CHILDREN]]` for [UID:000025], [UID:000026], [UID:000029], [UID:00002F], and [UID:00002G]. Current class docs, vtable stores, direct constructors, and accepted sibling Clan class-shell patterns are strong enough for declaration shells. The shells are intentionally declaration-only; exact method bodies stay on by-memory pages.
- Add first-draft formal C++ for executable source-authored method clusters [UID:00010O], [UID:00010Q], [UID:00010R], and [UID:00010S]. The code uses best-current source-facing names and records inferred helper names instead of leaving field/control/ListPane-name blockers as final deferrals.
- Preserve accepted marker/no-code dispositions for true raw/helper/storage/compiler-layout pages [UID:00021X], [UID:0002OC], [UID:0002XK], [UID:00021Y], and [UID:0002MO].
- Emit the real singleton declaration from [UID:0002XJ]: `ClanBankPane *g_pClanBankPane;`.

Recommended target metadata for [UID:0000I9]:

| Field | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `COMPLETION` | `87` | `90` | Resolves all 15 current generated empty markers, replaces the rejected method-aggregate deferral with first-draft source C++, and upgrades class routes to declaration-shell emitters. |
| `CONFIDENCE` | `87` | `89` | Current docs, executed reports, generated output, and current MCP evidence agree on owner/emitter routes, function boundaries, vtable slots, singleton state, and raw/no-code exclusions. Confidence remains below final because several names are best-current inferred source names rather than recovered symbols. |
| `PROPOSED_RECONSTRUCTION_PATH` | `"NexusTK/social/"` | unchanged | Correct generated folder for the current `ClanBank.cpp` bucket. |
| `CANONICAL_OWNER` | `FILE` | unchanged | This is the by-file generated source root. |

Support-page metadata recommendation: raise the five class shells and four method-cluster pages enough to match the revised formal code, leave true no-code support scores unchanged, set class-shell `EMITTER_POSITION_OPTIONAL:0`, and keep owner/emitter routes unchanged. [UID:0002XK] still needs the accepted stale initializer correction from `0xffffffff` to zero-filled virtual `.data`.

No by-* docs, generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files were edited during this report-only pass. No leases were taken. No subagents were spawned.

## Assignment And Scope

Target: [UID:0000I9] `by-file/ClanBank.md`

Report path: `E:/NTK/GhidraBridge/source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0000I9-ClanBank-empty-emitter-family-source-quality.md`

Queue source: `auto-generated/-ag-research-tracker.md`, `## Files With Empty Emitters`.

Current queue row:

| UID | Total | Filled | Empty | Filled % | Generated file |
| --- | ---: | ---: | ---: | ---: | --- |
| `0000I9` | `17` | `2` | `15` | `11.8%` | `auto-generated/NexusTK/social/ClanBank.cpp` |

Current generated file header inspected in this pass:

| Generated output | Current state |
| --- | --- |
| Path | `auto-generated/NexusTK/social/ClanBank.cpp` |
| `validator-command-id` | `000000002948` |
| `validator-refreshed-at` | `2026-06-30T14:41:03-04:00` |
| Filled emitters | `0002OB`, `00010P` |
| Empty emitters | `000025`, `000026`, `000029`, `00002F`, `00021X`, `0002OC`, `00002G`, `00010Q`, `0002XJ`, `0002XK`, `00010O`, `00010R`, `00021Y`, `00010S`, `0002MO` |

Immediate batch: all 15 current empty markers are in scope. A bounded subset is not needed because each item has an implementation-ready formal disposition and no item requires a new split page before callback implementation.

Explicit out of scope for this report-only pass:

- No implementation edits before supervisor validation.
- No edit to [UID:00010P] `ClanWidItemDialog` or [UID:0002OB] `ClanItemDialogConfirmValidation`, because they are already filled emitters in current generated output.
- No edit to generated files, `-coverage-report.md` files, project-level generated reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue/lock files, or unrelated docs.
- No source split into `ClanItemDialogs.cpp` in this assignment.

## Evidence Used

### Current Documentation Evidence

- [UID:0000I9] `by-file/ClanBank.md` records `COMPLETION:87`, `CONFIDENCE:87`, path `"NexusTK/social/"`, and `CANONICAL_OWNER:FILE`. It already documents the ClanBank item-dialog source cluster, possible `ClanItemDialogs.cpp` split, exact boundary corrections, `g_pClanBankPane` lifecycle, resource-string and vtable ownership, B001 [UID:00010Q] placement, and B010 [UID:00021Y] raw-helper no-code proof.
- The 15 generated-empty support docs all have valid owner/emitter routes and blank formal C++ blocks:

| UID | Current score | Owner/emitter | File |
| --- | --- | --- | --- |
| `000025` | `86/89` | `0000I9` / `0000I9` | `by-class/ClanBankItemListPane.md` |
| `000026` | `86/89` | `0000I9` / `0000I9` | `by-class/ClanBankPane.md` |
| `000029` | `86/89` | `0000I9` / `0000I9` | `by-class/ClanDepItemDialog.md` |
| `00002F` | `85/89` | `0000I9` / `0000I9` | `by-class/ClanItemDialog.md` |
| `00021X` | `85/90` | `00002F` / `00002F` | `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md` |
| `0002OC` | `85/91` | `00002F` / `00002F` | `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md` |
| `00002G` | `86/89` | `0000I9` / `0000I9` | `by-class/ClanItemListPane.md` |
| `00010Q` | `85/90` | `00002G` / `00002G` | `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md` |
| `0002XJ` | `86/89` | `0000I9` / `0000I9` | `by-global/g_pClanBankPane.md` |
| `0002XK` | `86/89` | `0002XJ` / `0002XJ` | `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md` |
| `00010O` | `85/90` | `0000I9` / `0000I9` | `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md` |
| `00010R` | `85/90` | `0000I9` / `0000I9` | `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md` |
| `00021Y` | `88/90` | `0000I9` / `0000I9` | `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md` |
| `00010S` | `85/90` | `0000I9` / `0000I9` | `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md` |
| `0002MO` | `87/91` | `0000I9` / `0000I9` | `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md` |

### Current IDA MCP Evidence

MCP was available and current-session evidence was gathered. This report is not fallback-only.

Session state:

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Active database: `supervisor_resume_20260629`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`, imagebase `0x400000`
- `server_health`: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, `strings_cache_size: 2067`

Focused calls and conclusions:

| MCP call | Key result | Use in this report |
| --- | --- | --- |
| `lookup_funcs` on ClanBank starts | Raw starts `0x0048a0c0`, `0x0048b090`, `0x0048b7e0`, and `0x0048b870` are not functions; modeled starts include `0x0048a100` size `0x1f`, `0x0048a120` size `0x9e`, `0x0048a1c0` size `0x4ca`, `0x0048ae70` size `0x21c`, `0x0048b1c0` size `0x433`, `0x0048b630` size `0x1ac`, `0x0048b8c0` size `0x774`, and `0x0048c040` size `0x211`. | Confirms current boundaries and the raw/no-function split. |
| `entity_query functions 0x0048a0b0-0x0048c270` | Returned 20 local function starts; notably no modeled functions at raw constructor `0x0048a0c0`, selected-slot raw helper `0x0048b090`, or raw packet helpers `0x0048b7e0`/`0x0048b870`. | Negative evidence against inventing callable helper bodies for raw starts. |
| `xrefs_to` for active bodies | Constructor callers: `0x0048a1c0` from `0x0048516e` and `0x00487e83`; `0x0048ae70` from `0x0048ab68`; `0x0048b1c0` from `0x00508739` and `0x00513b2f`; `0x0048b8c0` from `0x0048b45b`. Vtable-only anchors: `0x0048a6b0`, `0x0048a790`, `0x0048b0a0`, `0x0048b630`, and `0x0048c040`. | Supports current ClanBank source placement and first-draft method emission for modeled source-authored bodies. |
| `xrefs_to` for raw starts | `0x0048a0c0`, `0x0048b090`, `0x0048b7e0`, and `0x0048b870` each have zero xrefs. | Required no-code/marker evidence for raw start items. |
| `get_bytes 0x0048a0c0 size 64` | Complete constructor-shaped bytes call `0x0049d8a0`, store vtables `0x00615fdc`, `0x00616040`, `0x00616070`, return with `retn 4`, then padding. | Confirms [UID:00021X] identity but not live constructor route. |
| `get_bytes 0x0048b090 size 16` | Raw selected-slot helper bytes `FF B1 34 01 00 00 E8 25 8D 06 00 8A 00 C3` followed by padding. | Supports the [UID:00010Q] in-block no-code comment for the raw selected-slot island while allowing constructor/draw C++ to emit. |
| `get_bytes 0x0048b7dc size 224` | Four `0xcc` padding bytes, raw submit helper at `0x0048b7e0`, raw close helper at `0x0048b870`, both with opcode `0x36` packet construction. | Reconfirms B010 [UID:00021Y] retained raw helper island. |
| `analyze_function 0x0048a1c0` | `ClanDepItemDialog` constructor decodes two MBCS strings, creates `DL_15` UI, buttons, title/detail controls, `MyItemListPane`, amount edit, and slide-open path; caller set is the clan status/packet dialog opener pair. | Supports source-family behavior and the revised first-draft constructor C++ block. |
| `analyze_function 0x0048ae70` | `ClanItemListPane` constructor initializes 256-slot cache, parses count/slot/item-id/name rows, converts names to UTF-16, and republishes rows; sole caller is `ClanWidItemDialog` at `0x0048ab68`. | Reconfirms B001 [UID:00010Q] placement, row layout, and the separate raw-island no-code proof. |
| `analyze_function 0x0048b1c0` and `0x0048b630` | `ClanBankPane` constructor writes `g_pClanBankPane`, mode `10 -> 0` and `16 -> 1`, creates `cl` resource UI, child `ClanBankItemListPane`, and action handler sends close `0x36/0x0b` or submit `0x36` subtype `0x0d/0x0c`, selected slot UInt16BE, multi-count flag, UInt32BE amount. | Confirms current target file ownership and B010 packet correction. |
| `analyze_function 0x0048b8c0` and `0x0048c040` | `ClanBankItemListPane` constructor clears 255 records, parses cases `10`, `15`, `16`, sorts/rebuilds list rows; draw method renders selected background, item icon, optional count suffix, text fitting, and text draw. | Confirms behavior and supports best-current first-draft constructor/parser/draw C++. |
| `xrefs_to 0x0067ade8` | Seven refs: constructor write/clear at `0x0048b224`/`0x0048b22b`, clears at `0x0048b61a`, `0x0048c260`, `0x0048c430`, reads at `0x00508706`, `0x00513b07`. | Confirms `g_pClanBankPane` type/ownership and supports real global declaration. |
| `get_bytes 0x0067ade8 size 4` | Current IDB bytes are `00 00 00 00`. | Contradicts stale [UID:0002XK] child-page `0xffffffff` wording. |
| PE mapping for `0x0067ade8` | `0x0067ade8` lies beyond raw-backed `.data` payload end; local file offset calculation lands outside raw data for that VA, matching aggregate doc's loader-supplied zero-filled virtual `.data` note. | Supports correcting [UID:0002XK] to zero-initialized storage and emitting `ClanBankPane *g_pClanBankPane;` from [UID:0002XJ]. |
| `entity_query names 0x00615fd8-0x006163dc` | 18 decorated vtable names from `??_7ClanItemDialog@@6B@` through `??_7ClanBankItemListPane@@6B@_1`. | Supports [UID:0002MO] compiler-layout marker, not raw array source. |
| `xrefs_to` representative vtable bases | `0x00615fdc` has five `ClanItemDialog` store refs; `0x0061607c` from `0x0048a21a`; `0x006161bc` from `0x0048aedb`; `0x00616280` from `0x0048b239`, `0x0048b600`, `0x0048c416`; `0x0061631c` from `0x0048b92b`. | Confirms class/vtable ownership and compiler-regenerated vtable disposition. |
| `get_bytes 0x00615fd8` and `0x006163d4` | Start bytes `64 52 64 00 70 c4 48 00`; final bytes include `b2 c2 48 00 90 4e 54 00` followed by UTF-16 `CLAN`. | Confirms exact vtable-data boundary and resource-string successor. |
| `find_bytes` pointer patterns | No matches for raw starts `0x0048a0c0`, `0x0048b090`, `0x0048b7e0`, `0x0048b870`; expected hits for singleton and representative vtable bases. | Negative route evidence for raw helpers, positive sanity check for known data refs. |
| Revision `idb_list` / `server_health` on 2026-06-30 | Active session `supervisor_resume_20260629`, worker PID `24256`, `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`. | Confirms same-report revision uses current MCP and is not fallback-only. |
| Revision `lookup_funcs` on contested ranges | Confirms modeled functions inside method clusters: `0x0048a1c0`, `0x0048a690`, `0x0048a6b0`, `0x0048a790`, `0x0048ae70`, `0x0048b0a0`, `0x0048b1c0`, `0x0048b600`, `0x0048b630`, `0x0048b8c0`, `0x0048c040`; raw `0x0048b090` remains `Not a function`. | Supports emitting C++ for modeled source functions while preserving no-code proof for raw/helper spans. |
| Revision `xrefs_to` on contested starts | Constructor callers: `0x0048a1c0` from `0x0048516e`/`0x00487e83`, `0x0048ae70` from `0x0048ab68`, `0x0048b1c0` from `0x00508739`/`0x00513b2f`, `0x0048b8c0` from `0x0048b45b`; vtable-only method anchors: `0x0048a6b0`, `0x0048a790`, `0x0048b0a0`, `0x0048b630`, `0x0048c040`; zero xrefs to reset/raw starts `0x0048a690`, `0x0048b090`, `0x0048b600`. | Resolves class-shell and method-body readiness while keeping target-specific no-code comments for raw/generated helpers. |
| Revision `analyze_component` over 11 modeled functions | Confirms source-authored constructor/action/draw/parser callees and complexity; only internal edge is `ClanBankPane` constructor calling `ClanBankItemListPane` constructor; shared globals include blank title string, ellipsis literal, `g_packetSender`, `g_pDisplayContext`, `g_pItemObjImageLib`, and ClanBankPane vtables. | Direct evidence that the four aggregates are function inventories, not one opaque body; supports formal first-draft C++ per modeled behavior without new child-page creation. |

### Old Report Leads Opened

Search scope: old/current B reports for exact ClanBank empty-emitter family terms and the assigned UIDs. Relevant executed reports found and opened:

- `executed-b-agent-research/B001/00010Q-clan-item-list-pane-source-quality.md`
- `executed-b-agent-research/B010/00021Y-ClanBankPaneRawPacketHelpers-source-quality.md`

Lead conclusions validated against current docs/MCP:

- B001 [UID:00010Q] remains current for ownership, row layout, raw selected-slot helper semantics, and GrafPort text-fit dependency ownership. Its blank-C++ disposition is superseded by this revision: the raw selected-slot island remains no-code/no-route, but the modeled constructor and draw method can carry first-draft source C++ using best-current inferred ListPane API names.
- B010 [UID:00021Y] remains current: raw opcode `0x36` helper island stays in `ClanBank.cpp`, no split, no callable helper body, selected slot is zero-extended UInt16BE, and active `ClanBankPane::OnDialogAction` already emits equivalent submit/close packets inline.

No direct prior report for [UID:0000I9] `ClanBank` itself was found before this assignment. The previously accepted B009 BoardDialogs empty-emitter report was reviewed only as a generated-empty-emitter workflow pattern, not as source evidence for ClanBank; its route-marker policy is not reused for these source-authored method clusters.

## Immediate Batch Inventory And Disposition

Expected generated result after implementation and validators with `--wait-generated`: `auto-generated/NexusTK/social/ClanBank.cpp` should move from `17 total / 2 filled / 15 empty / 11.8%` to `17 total / 17 filled / 0 empty / 100.0%`. Existing filled emitters [UID:0002OB] and [UID:00010P] should remain unchanged.

| UID | Destination | Current reason empty | Implementation disposition |
| --- | --- | --- | --- |
| `000025` | `by-class/ClanBankItemListPane.md` formal block | Current evidence resolves enough declaration shape: `ListPane`-derived bank item row parser/drawer with exact row fields inferred from parser/draw offsets. | Declaration-level class shell with `ClanBankItemEntry` and `[[CHILDREN]]`; set position `0`, raise to `87/90`. |
| `000026` | `by-class/ClanBankPane.md` formal block | Current evidence resolves enough declaration shape: `DialogPane`-derived main clan-bank dialog, singleton, mode field `+0x26c`, action handler, and child list pane. | Declaration-level class shell with `g_pClanBankPane` extern and `[[CHILDREN]]`; set position `0`, raise to `87/90`. |
| `000029` | `by-class/ClanDepItemDialog.md` formal block | Current evidence resolves enough declaration shape: `ClanItemDialog`-derived deposit dialog with constructor, button action, and deposit packet sender. | Declaration-level class shell with `[[CHILDREN]]`; set position `0`, raise to `87/90`. |
| `00002F` | `by-class/ClanItemDialog.md` formal block | Raw constructor remains no-route, but the class base and confirmed child method support a declaration-only shell as in nearby accepted Clan raw-constructor classes. | Declaration-level `ClanItemDialog : public DialogPane` shell with `[[CHILDREN]]`; set position `0`, raise to `86/90`. |
| `00021X` | `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md` formal block | Source-shaped raw constructor but no IDA function object, no inbound xrefs, and no pointer hits. | Marker-only no-route raw-constructor proof. |
| `0002OC` | `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md` formal block | Destructor-tail/vtable reset function with EH-only refs and mis-typed base cleanup target. | Marker-only destructor-tail no-standalone-body proof. |
| `00002G` | `by-class/ClanItemListPane.md` formal block | Current evidence resolves enough declaration shape: `ListPane`-derived compact item list, source-facing `ClanItemListEntry`, constructor, draw method, raw selected-slot caveat. | Declaration-level class shell with `ClanItemListEntry` and `[[CHILDREN]]`; set position `0`, raise to `87/90`. |
| `00010Q` | `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md` formal block | Constructor and draw method are source-authored with stable row layout; raw selected-slot helper remains no-route and is documented as no standalone callable body. | First-draft C++ for constructor and `DrawListItem`; in-block no-code comment for raw `0x0048b090` island; raise to `88/90`. |
| `0002XJ` | `by-global/g_pClanBankPane.md` formal block | Source-owned singleton currently has blank formal C++. | Emit real global declaration `ClanBankPane *g_pClanBankPane;`. |
| `0002XK` | `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md` formal block and stale initializer prose | Storage child duplicates [UID:0002XJ] and has stale `0xffffffff` wording. | Marker-only storage-covered proof plus zero-filled virtual `.data` correction. |
| `00010O` | `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md` formal block | Constructor, action handler, and sender are source-authored and current evidence supports inferred control names and packet helper names. | First-draft C++ for constructor, `OnButtonClick`, and `SendDepositItemPacket`; in-block no-code comment for vtable-reset/destructor tail; raise to `88/90`. |
| `00010R` | `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md` formal block | Constructor and action handler are source-authored; raw helper callability remains excluded but does not block first-draft inline action C++. | First-draft C++ for constructor and `OnDialogAction`; in-block no-code comment for vtable-reset/destructor tail; raise to `88/90`. |
| `00021Y` | `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md` formal block | B010 accepted no-code proof: raw helpers mirror inline action handler but have no function/xref/data-flow/pointer/rel32 route. | Marker-only retained raw-helper proof. |
| `00010S` | `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md` formal block | Constructor/parser and draw method are source-authored; parser/draw offsets resolve the source-facing `ClanBankItemEntry` fields well enough for first draft. | First-draft C++ for constructor/parser and `DrawListEntry`; raise to `88/90`. |
| `0002MO` | `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md` formal block | Compiler-emitted RTTI/vtable data, not handwritten source arrays. | Marker-only compiler-layout proof. |

## Formal RECONSTRUCTION_CPP CODE Insertions

These blocks are exact insertion text recommended for the implementation callback. They should replace the currently blank formal block for each listed support page. Do not add illustrative C++ outside these blocks.

### [UID:000025] `by-class/ClanBankItemListPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct Rect;

struct ClanBankItemEntry
{
    unsigned char slotIndex;
    unsigned char reserved;
    unsigned short itemId;
    wchar_t displayName[256];
    unsigned int count;
    unsigned int flags;
};

class ClanBankItemListPane : public ListPane
{
public:
    explicit ClanBankItemListPane(const unsigned char *packet);
    virtual ~ClanBankItemListPane();

protected:
    virtual void DrawListEntry(int rowIndex, const ClanBankItemEntry *entry, const Rect *bounds);

private:
    void ClearSlotCache();
    void RebuildVisibleRows();
    ClanBankItemEntry m_entries[256];
    int m_visibleRowCount;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000026] `by-class/ClanBankPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanBankItemListPane;

class ClanBankPane : public DialogPane
{
public:
    ClanBankPane(const unsigned char *packet, int action);
    virtual ~ClanBankPane();

protected:
    virtual void OnDialogAction(int controlId, int action, int value);

private:
    void SendClosePacket();
    unsigned char m_bankMode;     // +0x26c, 0 for item bank action 10, 1 for gold bank action 16.
};

extern ClanBankPane *g_pClanBankPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000029] `by-class/ClanDepItemDialog.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanDepItemDialog : public ClanItemDialog
{
public:
    explicit ClanDepItemDialog(const unsigned char *packet);
    virtual ~ClanDepItemDialog();

protected:
    virtual void OnButtonClick(int controlId, int action, int value);
    virtual void SendDepositItemPacket(unsigned char slotIndex, unsigned short amount);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00002F] `by-class/ClanItemDialog.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanItemDialog : public DialogPane
{
public:
    ClanItemDialog();
    virtual ~ClanItemDialog();

protected:
    virtual void UpdateConfirmButtonState();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00021X] `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID00021X is the source-shaped ClanItemDialog raw constructor, but current IDA/MCP reports no function object, no inbound xrefs, and no pointer/immediate hits at 0x0048a0c0. No standalone constructor body is emitted here until a live constructor route or synchronized class declaration policy is proven.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002OC] `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0002OC is a ClanItemDialog destructor-tail/vtable-reset body reached through constructor EH cleanup, not a standalone source method. No C++ body is emitted here because the base-cleanup target is still compiler-shaped and mis-typed in IDA; final class destructors should regenerate this behavior.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00002G] `by-class/ClanItemListPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct Rect;

struct ClanItemListEntry
{
    unsigned char slotIndex;
    unsigned char reserved;
    unsigned short itemId;
    wchar_t displayName[256];
};

class ClanItemListPane : public ListPane
{
public:
    explicit ClanItemListPane(const unsigned char *packet);
    virtual ~ClanItemListPane();

protected:
    virtual void DrawListItem(int rowIndex, const ClanItemListEntry *entry, const Rect *bounds);

private:
    ClanItemListEntry m_entries[256];
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00010Q] `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanItemListPane::ClanItemListPane(const unsigned char *packet)
    : ListPane(516, 8, 205, 24, 0, true, true)
{
    memset(m_entries, 0, sizeof(m_entries));

    const unsigned int count = ReadPacketByte(packet);
    const unsigned char *cursor = packet + 1;

    for (unsigned int i = 0; i < count; ++i)
    {
        const unsigned char slotIndex = ReadPacketByte(cursor++);
        ClanItemListEntry &entry = m_entries[slotIndex];

        entry.slotIndex = slotIndex;
        entry.reserved = 0;
        entry.itemId = ReadPacketUInt16BE(cursor);
        cursor += 2;

        const unsigned int nameLength = ReadPacketByte(cursor++);
        char nameBytes[256];
        memmove(nameBytes, cursor, nameLength);
        nameBytes[nameLength] = '\0';
        cursor += nameLength;

        const int wideLength = MultiByteToWideChar(
            CP_ACP,
            0,
            nameBytes,
            nameLength,
            entry.displayName,
            256);

        if (static_cast<unsigned int>(wideLength) >= 256)
            __report_rangecheckfailure();

        entry.displayName[wideLength] = L'\0';
    }

    for (unsigned int slotIndex = 1; slotIndex < 256; ++slotIndex)
    {
        const ClanItemListEntry &entry = m_entries[slotIndex];
        if (entry.displayName[0] != L'\0')
            AddRow(&entry);
    }
}

// The raw selected-entry byte helper at 0x0048b090-0x0048b09e is source-shaped
// but has no IDA function, xref, VA/RVA pointer, or direct branch route. Its
// behavior is represented by callers using ListPane selection state; do not emit
// a standalone callable body for that raw island in this pass.

void ClanItemListPane::DrawListItem(int rowIndex, const ClanItemListEntry *entry, const Rect *bounds)
{
    int scratch[4];
    BeginListRowDraw(scratch);

    if (IsRowSelected(rowIndex))
    {
        SetTextColor(37);
        DrawSelectedRowBackground(bounds);
        SetTextColor(128);
    }
    else
    {
        SetTextColor(37);
    }

    Rect imageBounds;
    GetItemImageBounds(entry->itemId, &imageBounds);
    m_drawImage = true;
    SetTextBackgroundMode(0);

    wchar_t label[256];
    wcscpy_s(label, 256, entry->displayName);
    FitTextWithEllipsis(label, 256, L"...", bounds->right - 50);

    const int textY = ((bounds->top + bounds->bottom) / 2) + 6;
    MoveTextCursor(50, textY);
    DrawWideText(label, wcslen(label));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002XJ] `by-global/g_pClanBankPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanBankPane *g_pClanBankPane;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002XK] `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0002XK is the exact storage slot for g_pClanBankPane and is emitted by UID0002XJ. Current MCP bytes and PE mapping show zero-filled virtual .data storage, not a separate handwritten initializer or duplicate global definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00010O] `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanDepItemDialog::ClanDepItemDialog(const unsigned char *packet)
    : ClanItemDialog()
{
    char textBytes[256];
    wchar_t titleText[256];
    wchar_t detailText[256];

    const unsigned int titleLength = packet[3];
    memmove(textBytes, packet + 4, titleLength);
    textBytes[titleLength] = '\0';

    int wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        textBytes,
        titleLength,
        titleText,
        256);

    if (static_cast<unsigned int>(wideLength) >= 256)
        __report_rangecheckfailure();

    titleText[wideLength] = L'\0';

    const unsigned char *detailPacket = packet + 4 + titleLength;
    const unsigned int detailLength = detailPacket[0];
    memmove(textBytes, detailPacket + 1, detailLength);
    textBytes[detailLength] = '\0';

    wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        textBytes,
        detailLength,
        detailText,
        256);

    if (static_cast<unsigned int>(wideLength) >= 256)
        __report_rangecheckfailure();

    detailText[wideLength] = L'\0';

    AddControl(new EPFImageControlPane(L"DLGCLAN3.EPF", Rect(0, 0, 221, 288), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(36, 230, 108, 246)));
    AddControl(new ImageButtonControlPane(22, Rect(113, 230, 185, 246)));
    AddControl(new StaticTextControlPane(titleText, true, 128, Rect(27, 50, 195, 70)));
    AddControl(new StaticTextControlPane(detailText, true, 128, Rect(27, 174, 195, 194)));

    MyItemListPane *itemList = new MyItemListPane();
    AddControl(new ScrollControlPane(Rect(27, 72, 195, 168), itemList, 0, 0, 0));
    AddControl(new TextEditControlPane(L"", true, 128, 0, Rect(27, 196, 195, 209), 0, 0, 0, 0, 1.0f, 0));

    SetDefaultControl(5);
    RegisterButtonAction(1);
    RegisterButtonAction(2);
    SetDialogResourceName(L"DLGCLAN3.EPF");
    AttachToDesktop(Rect(212, 12, 433, 300), g_pBackPane);
    OpenOnDisplay(g_pDisplayContext);
    SlideOpen(false);
}

// The vtable-reset/destructor-tail helper at 0x0048a690-0x0048a6af is generated
// cleanup shape and has no direct xrefs. It is covered by the class destructor
// declaration and should not be emitted as a handwritten source method.

void ClanDepItemDialog::OnButtonClick(int controlId, int action, int)
{
    if (action == 1)
    {
        MyItemListPane *itemList =
            static_cast<MyItemListPane *>(FindControl(5)->control->m_embeddedListPane);
        TextEditControlPane *amountEdit =
            static_cast<TextEditControlPane *>(FindControl(6)->control);

        wchar_t amountText[128];
        amountEdit->ReadText(amountText, 127);

        const int selectedIndex = itemList->GetSelectedIndex();
        if (selectedIndex >= 0 && selectedIndex < itemList->GetRowCount())
        {
            const unsigned char slotIndex = itemList->GetSelectedSlotIndex();
            const unsigned short amount =
                static_cast<unsigned short>(_wtol(amountText));

            SendDepositItemPacket(slotIndex, amount);
        }
    }

    if (action == 1 || action == 2)
    {
        SlideClose(controlId);
        CloseDialog();
    }
}

void ClanDepItemDialog::SendDepositItemPacket(unsigned char slotIndex, unsigned short amount)
{
    unsigned char packet[7];
    PacketBufferWriteByte(packet + 0, 0x4b);
    PacketBufferWriteByte(packet + 1, 5);
    PacketBufferWriteByte(packet + 2, 1);
    PacketBufferWriteByte(packet + 3, slotIndex);
    PacketBufferWriteUInt16BE(packet + 4, amount);
    packet[6] = 0;

    g_packetSender->QueueAndSendPacket(packet, 6);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00010R] `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanBankPane::ClanBankPane(const unsigned char *packet, int action)
    : DialogPane(L"", -1, true)
{
    g_pClanBankPane = this;

    if (action == 10)
        m_bankMode = 0;
    else if (action == 16)
        m_bankMode = 1;
    else
        return;

    AddControl(new EPFImageControlPane(L"CLANBAN1.EPF", Rect(0, 0, 448, 475), 0, true));
    AddControl(new ImageButtonControlPane(30, Rect(190, 438, 253, 462)));

    if (m_bankMode != 0)
        AddControl(new ImageButtonControlPane(23, Rect(340, 397, 403, 421)));
    else
        AddControl(new ImageButtonControlPane(53, Rect(340, 397, 403, 421)));

    AddControl(new TextEditControlPane(L"1", true, 143, 134, Rect(300, 402, 324, 414), 0, 0, 0, 0, 1.0f, 0));

    ClanBankItemListPane *itemList = new ClanBankItemListPane(packet + 1);
    AddControl(new ScrollControlPane(Rect(15, 95, 415, 375), itemList, 0, 0, 0));

    wchar_t countText[128];
    if (m_bankMode != 0)
        swprintf_s(countText, 128, L"     %d", itemList->GetVisibleRowCount());
    else
        swprintf_s(countText, 128, L"%d / %d", itemList->GetVisibleRowCount(), 255);

    AddControl(new StaticTextControlPane(countText, true, 143, Rect(328, 62, 388, 74)));

    SetDefaultControl(4);
    RegisterButtonAction(1);
    SetDialogResourceName(L"CLANBAN1.EPF");
    AttachToDesktop(Rect(50, 50, 498, 525), g_pBackPane);
    OpenOnDisplay(g_pDisplayContext);
}

// The vtable-reset/destructor-tail helper at 0x0048b600-0x0048b629 is generated
// cleanup shape: it restores ClanBankPane vtables, clears g_pClanBankPane, and
// tail-calls base teardown. It is not emitted as a handwritten source method.

void ClanBankPane::SendClosePacket()
{
    unsigned char packet[3];
    PacketBufferWriteByte(packet + 0, 0x36);
    PacketBufferWriteByte(packet + 1, 0x0b);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}

void ClanBankPane::OnDialogAction(int controlId, int action, int)
{
    if (action == 1)
    {
        SendClosePacket();
        SlideClose(controlId);
        CloseDialog();
        return;
    }

    if (action == 2)
    {
        ClanBankItemListPane *itemList =
            static_cast<ClanBankItemListPane *>(FindControl(4)->control->m_embeddedListPane);
        TextEditControlPane *quantityEdit =
            static_cast<TextEditControlPane *>(FindControl(3)->control);

        wchar_t quantityText[128];
        quantityEdit->ReadText(quantityText, 127);

        const int selectedIndex = itemList->GetSelectedIndex();
        if (selectedIndex >= 0 && selectedIndex < itemList->GetRowCount())
        {
            const unsigned short selectedSlot =
                static_cast<unsigned short>(itemList->GetSelectedSlotIndex());
            unsigned int quantity = static_cast<unsigned int>(_wtol(quantityText));
            if (quantity == 0)
                quantity = 1;

            unsigned char packet[10];
            PacketBufferWriteByte(packet + 0, 0x36);
            PacketBufferWriteByte(packet + 1, static_cast<unsigned char>(13 - (m_bankMode != 0)));
            PacketBufferWriteUInt16BE(packet + 2, selectedSlot);
            PacketBufferWriteByte(packet + 4, quantity > 1);
            PacketBufferWriteUInt32BE(packet + 5, quantity);
            packet[9] = 0;

            g_packetSender->QueueAndSendPacket(packet, 9);
        }

        SendClosePacket();
        SlideClose(controlId);
        CloseDialog();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00021Y] `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID00021Y is the retained ClanBankPane raw opcode-0x36 helper island. It emits no callable helper body because current MCP and PE evidence show no function objects, no inbound xrefs, no incoming data-flow, and no pointer or rel32 route, while ClanBankPane::OnDialogAction already emits the equivalent submit/close packets inline.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00010S] `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanBankItemListPane::ClanBankItemListPane(const unsigned char *packet)
    : ListPane(524, 8, 400, 40, 0, true, true),
      m_visibleRowCount(0)
{
    ClearSlotCache();

    const unsigned char opcode = ReadPacketByte(packet);
    if (opcode == 10)
    {
        const unsigned int count = ReadPacketByte(packet + 1);
        const unsigned char *cursor = packet + 2;

        for (unsigned int row = 1; row <= count; ++row)
        {
            const unsigned char slotIndex = ReadPacketByte(cursor++);
            ClanBankItemEntry &entry = m_entries[row];
            entry.slotIndex = slotIndex;
            entry.itemId = ReadPacketUInt16BE(cursor);
            cursor += 2;

            const unsigned int nameLength = ReadPacketByte(cursor++);
            char nameBytes[256];
            memmove(nameBytes, cursor, nameLength);
            nameBytes[nameLength] = '\0';
            cursor += nameLength;

            const int wideLength = MultiByteToWideChar(
                CP_ACP,
                0,
                nameBytes,
                nameLength,
                entry.displayName,
                256);

            if (static_cast<unsigned int>(wideLength) >= 256)
                __report_rangecheckfailure();

            entry.displayName[wideLength] = L'\0';

            const unsigned int detailLength = ReadPacketByte(cursor++);
            cursor += detailLength;
            entry.count = ReadPacketUInt32BE(cursor);
            cursor += 4;

            cursor += 3;
            if (ReadPacketByte(cursor++) != 0)
            {
                const unsigned int extraLength = ReadPacketByte(cursor++);
                cursor += extraLength;
            }

            entry.flags = ReadPacketByte(cursor++);
        }

        std::sort(
            m_entries + 1,
            m_entries + count + 1,
            [](const ClanBankItemEntry &left, const ClanBankItemEntry &right) {
                return right.displayName[0] != L'\0' &&
                       wcscmp(left.displayName, right.displayName) > 0;
            });
    }
    else if (opcode == 15)
    {
        const unsigned char slotIndex = ReadPacketByte(packet + 1);
        m_entries[slotIndex] = ClanBankItemEntry();
    }
    else if (opcode == 16)
    {
        const unsigned int count = ReadPacketUInt16BE(packet + 1);
        const unsigned char *cursor = packet + 3;

        for (unsigned int i = 0; i < count; ++i)
        {
            const unsigned char slotIndex = ReadPacketByte(cursor++);
            ClanBankItemEntry &entry = m_entries[slotIndex];
            entry.slotIndex = slotIndex;
            entry.itemId = ReadPacketUInt16BE(cursor);
            cursor += 2;

            cursor += 1;
            entry.count = ReadPacketUInt32BE(cursor);
            cursor += 4;

            cursor += 1;
            const unsigned int nameLength = ReadPacketByte(cursor++);
            char nameBytes[256];
            memmove(nameBytes, cursor, nameLength);
            nameBytes[nameLength] = '\0';
            cursor += nameLength;

            const int wideLength = MultiByteToWideChar(
                CP_ACP,
                0,
                nameBytes,
                nameLength,
                entry.displayName,
                256);

            if (static_cast<unsigned int>(wideLength) >= 256)
                __report_rangecheckfailure();

            entry.displayName[wideLength] = L'\0';

            const unsigned int detailLength = ReadPacketByte(cursor++);
            cursor += detailLength;
            entry.flags = 0;
        }
    }

    RebuildVisibleRows();
}

void ClanBankItemListPane::ClearSlotCache()
{
    memset(m_entries, 0, sizeof(m_entries));
    m_visibleRowCount = 0;
}

void ClanBankItemListPane::RebuildVisibleRows()
{
    m_visibleRowCount = 0;

    for (unsigned int slotIndex = 1; slotIndex < 256; ++slotIndex)
    {
        ClanBankItemEntry &entry = m_entries[slotIndex];
        if (entry.displayName[0] != L'\0')
        {
            AddRow(&entry);
            ++m_visibleRowCount;
        }
    }
}

void ClanBankItemListPane::DrawListEntry(int rowIndex, const ClanBankItemEntry *entry, const Rect *bounds)
{
    int scratch[4];
    BeginListRowDraw(scratch);

    if (IsRowSelected(rowIndex))
    {
        Rect selectedBounds(bounds->left, bounds->top, bounds->right - 13, bounds->bottom);
        SetTextColor(128);
        DrawSelectedRowBackground(&selectedBounds);
    }

    SetFontColor(143);

    Rect imageBounds;
    GetItemImageBounds(entry->itemId, &imageBounds);
    const int imageLeft = 30 - ((imageBounds.right - imageBounds.left) / 2);
    const int imageTop = ((bounds->top + bounds->bottom) / 2) -
                         ((imageBounds.bottom - imageBounds.top) / 2);

    DrawItemImage(
        g_pItemObjImageLib,
        Rect(imageLeft, imageTop, imageLeft + imageBounds.Width(), imageTop + imageBounds.Height()),
        entry->itemId,
        0,
        0,
        0.0f);

    m_drawImage = true;
    SetTextBackgroundMode(0);

    wchar_t label[256];
    if (entry->count <= 1)
        wcscpy_s(label, 256, entry->displayName);
    else
        swprintf_s(label, 256, L"%s (%d)", entry->displayName, entry->count);

    FitTextWithEllipsis(label, 256, L"...", bounds->right - 70);
    MoveTextCursor(70, ((bounds->top + bounds->bottom) / 2) + 6);
    DrawWideText(label, wcslen(label));
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002MO] `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0002MO ClanBank vtable data is compiler-emitted layout evidence for the ClanItemDialog, ClanDepItemDialog, ClanWidItemDialog, ClanItemListPane, ClanBankPane, and ClanBankItemListPane class family. Do not hand-write raw RTTI or vtable dword arrays; final class declarations should regenerate equivalent tables.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Support Doc Plan With Destinations

Implement the accepted details only after supervisor validation:

| Destination | Required edit class | Required content |
| --- | --- | --- |
| `by-file/ClanBank.md` | Metadata | Change `COMPLETION` to `90` and `CONFIDENCE` to `89`; leave path and `CANONICAL_OWNER:FILE` unchanged. |
| `by-file/ClanBank.md` | Empty-emitter family note | Add a source-quality note that pre-callback generated output was `17 total / 2 filled / 15 empty`, that the accepted implementation resolves all 15 empty emitters with declaration shells, first-draft method C++, no-code proof markers, or the singleton declaration, and that generated output should become `17/17/0` after validators. |
| `by-file/ClanBank.md` | Evidence/rationale | Preserve MCP session state, function/raw split, singleton seven-xref evidence, vtable evidence, B001 [UID:00010Q] evidence-with-superseded-blank-C++ disposition, B010 [UID:00021Y] lead reconciliation, zero-filled `g_pClanBankPane` storage correction, and rejected alternatives. |
| Five class pages `000025`, `000026`, `000029`, `00002F`, `00002G` | Formal block and metadata | Insert exact declaration-level class shell with `[[CHILDREN]]`, set `EMITTER_POSITION_OPTIONAL:0`, and update scores to `87/90` except [UID:00002F] to `86/90`. |
| `by-global/g_pClanBankPane.md` | Formal block | Insert `ClanBankPane *g_pClanBankPane;`. No header metadata change. Add a short source note only if needed to state zero-initialized global declaration is emitted here and storage child is marker-only. |
| `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md` | Formal block and stale prose correction | Insert storage-covered marker; correct `Item Summary` and `Static image value` from `0xffffffff` to zero-filled virtual `.data`, citing current MCP bytes and existing aggregate page [UID:0002B5] supersession. No header metadata change. |
| `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md` | Formal block | Insert raw-constructor no-route marker. Existing detailed no-route prose is already at same-or-greater detail. |
| `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md` | Formal block | Insert destructor-tail marker. Existing EH-only/base-cleanup proof is already at same-or-greater detail. |
| `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md` | Formal first-draft C++ and metadata | Insert constructor/draw C++ with raw selected-slot no-route comment; raise to `88/90`. Preserve B001 row layout and text-helper ownership. |
| `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md` | Formal first-draft C++ and metadata | Insert constructor/action/sender C++ with vtable-reset no-code comment; raise to `88/90`. Preserve constructor caller, packet, and MyItemListPane evidence. |
| `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md` | Formal first-draft C++ and metadata | Insert constructor/action/close-packet C++ with vtable-reset no-code comment; raise to `88/90`. Preserve B010 selected-slot UInt16BE correction and raw helper proof. |
| `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md` | Formal block | Insert B010-compatible retained raw-helper marker. No owner/emitter/split change. |
| `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md` | Formal first-draft C++ and metadata | Insert constructor/parser/draw C++; raise to `88/90`. Preserve packet cases `10/15/16`, sort/rebuild, and text/image helper evidence. |
| `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md` | Formal block and wording cleanup | Insert compiler-layout marker. Replace stale "95+ source-emission gate" wording with current combined-score gate plus target-specific no-raw-vtable-array proof. |
| `auto-generated/NexusTK/social/ClanBank.cpp` | No manual edit | Generated file must refresh only through validators. |
| `auto-generated/-ag-research-tracker.md` and coverage reports | No manual edit | Generated/report state is out of scope for B009; observe freshness after validator refresh only. |

Conditional/optional support:

- No support sync to [UID:00010P] `ClanWidItemDialog` or [UID:0002OB] `ClanItemDialogConfirmValidation` is required because both are already filled emitters and their generated bodies should remain unchanged.
- No support sync to [UID:0000I8] `Clan`, raw opcode `0x4b` helper reports, Socket, PacketBuffer, `g_packetSender`, or text-helper pages is required in this callback. They are dependency/rejected-owner evidence already recorded in current ClanBank/B001/B010 docs; this empty-emitter pass does not change their ownership.
- No new child pages are required for this callback because the existing by-memory ranges can carry first-draft source for their own covered ranges while explicitly excluding raw/compiler helper islands in comments. A future exact-child split remains optional final-audit polish, not a current implementation blocker.

## Rejected Alternatives

| Alternative | Decision | Evidence |
| --- | --- | --- |
| Populate broad `ClanBank.md` with monolithic C++ | Rejected | The by-file page is a source bucket, not an emitter item, and the final `ClanBank.cpp` / `ClanItemDialogs.cpp` split remains unresolved. |
| Keep class pages as route-comment-only markers | Rejected by this revision | Current class docs, vtable slots, method inventories, accepted nearby Clan declaration-shell patterns, and source-facing row/mode fields are strong enough for declaration-level shells with `[[CHILDREN]]`. |
| Keep `00010O`, `00010Q`, `00010R`, or `00010S` as marker-only/no-partial aggregate pages | Rejected by this revision | The supervisor made these blockers in scope. Current MCP and docs support first-draft source C++ for modeled methods; raw/destructor helper islands can be excluded with target-specific comments instead of blocking the source-authored bodies. |
| Split the four method aggregates into new child pages before this callback | Rejected for this callback | Current by-memory pages already cover exact half-open ranges and can emit source for their own range. Creating twelve new child pages would require new UID allocation and by-structure split execution not authorized in this report-only revision, while the current pages can safely carry first-draft code and no-code comments for raw/generated subranges. |
| Emit callable C++ for raw starts `00021X` or `00021Y` | Rejected | Current MCP reports no function object and no inbound xrefs to `0x0048a0c0`, `0x0048b7e0`, or `0x0048b870`; `find_bytes` finds no pointer/immediate hits for those starts. |
| Emit [UID:0002OC] as a destructor method body | Rejected | It is a compiler-shaped destructor tail reached through EH cleanup, with a misleading shared base-cleanup name in IDA. Final class destructors should regenerate this behavior. |
| Emit duplicate global definitions from [UID:0002XJ] and [UID:0002XK] | Rejected | [UID:0002XJ] is the canonical global source declaration; [UID:0002XK] is the exact storage child and should be marker-only. |
| Keep stale `0xffffffff` initializer text for [UID:0002XK] | Rejected | Current MCP bytes at `0x0067ade8` are zero, and aggregate [UID:0002B5] already supersedes older `0xffffffff` wording as loader-supplied zero-filled virtual `.data`. |
| Hand-write raw RTTI/vtable arrays for [UID:0002MO] | Rejected | MCP vtable names/xrefs prove compiler-emitted layout data that should be regenerated from final class declarations. |
| Leave the 15 generated markers blank because they are no-code | Rejected | The assignment is the Files With Empty Emitters queue. Formal comments and the singleton declaration are the correct way to make generated output non-empty while preserving no-code proof. |
| Edit generated files or tracker rows directly | Rejected | Generated and report state are validator/supervisor-owned. |
| Claim rare no-improvement exception | Rejected | A clear safe improvement exists: formal source-disposition blocks for all 15 empty emitters plus the `g_pClanBankPane` declaration and stale initializer correction. |

## Claim And Incorporation Ledger

Callback state: accepted claims were implemented in the listed target/support docs. Verification states below are callback states with proof from the changed docs, scoped validators, and generated-output inspection.

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0000I9-001 | MCP was available and current evidence was used; this is not fallback-only. | High | Applied in `by-file/ClanBank.md` 2026-06-30 note preserving `supervisor_resume_20260629`, modeled/raw starts, singleton xrefs, and vtable evidence. | `by-file/ClanBank.md` evidence note; report evidence section. | incorporate | applied |
| C-0000I9-002 | Current generated `ClanBank.cpp` had `17` emitters, `2` filled, and `15` empty markers before callback. | High | Applied in `by-file/ClanBank.md` 2026-06-30 note with the exact pre-callback filled/empty UID list. | `by-file/ClanBank.md` empty-emitter family note. | incorporate | applied |
| C-0000I9-003 | The immediate implementation batch is all 15 current empty UIDs. | High | Applied across the 15 support formal blocks and target note; generated output now has zero `Empty Emitter Marker` rows. | `by-file/ClanBank.md`; 15 support formal blocks. | incorporate | applied |
| C-0000I9-004 | [UID:0000I9] should move to `90/89`; path and file owner unchanged. | Medium-high | Applied in target header: `COMPLETION:90`, `CONFIDENCE:89`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/"`, `CANONICAL_OWNER:FILE`. | `by-file/ClanBank.md` metadata and score rationale. | incorporate | applied |
| C-0000I9-005 | Existing filled emitters [UID:0002OB] and [UID:00010P] must remain unchanged. | High | Already present; callback did not edit those docs, and generated `ClanBank.cpp` still includes both filled UID sections. | Support plan and generated-output note. | already-present | already-present |
| C-0000I9-006 | Class pages [UID:000025], [UID:000026], [UID:000029], [UID:00002F], and [UID:00002G] should emit declaration-level class shells with `[[CHILDREN]]`, not route comments only. | High | Applied in five class formal blocks with scores/positions and 2026-06-30 change notes. | Five class formal blocks, metadata, score rationale. | incorporate | applied |
| C-0000I9-007 | [UID:00021X] is source-shaped raw constructor evidence but should emit no constructor body in this pass. | High | Applied as formal no-route marker in `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md`. | `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md` formal block. | incorporate | applied |
| C-0000I9-008 | [UID:0002OC] should emit no standalone destructor C++ body. | High | Applied as formal destructor-tail/vtable-reset marker in `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md`. | `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md` formal block. | incorporate | applied |
| C-0000I9-009 | [UID:00010Q] should emit first-draft constructor/draw C++ while keeping the raw selected-slot island as no-code/no-route inside the same formal block. | High | Applied in [UID:00010Q] formal block; score now `88/90`; raw `0x0048b090-0x0048b09e` no-route comment preserved in block. | `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md` formal block and score rationale. | incorporate | applied |
| C-0000I9-010 | [UID:0002XJ] should emit the real zero-initialized source global declaration `ClanBankPane *g_pClanBankPane;`. | High | Applied in `by-global/g_pClanBankPane.md` formal block; generated output includes the declaration. | `by-global/g_pClanBankPane.md` formal block. | incorporate | applied |
| C-0000I9-011 | [UID:0002XK] should be marker-only and its stale `0xffffffff` initializer wording should be corrected to zero-filled virtual `.data`. | High | Applied in storage child formal block, item summary, status, and change note; current wording records `00 00 00 00` zero-filled virtual `.data`. | `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md` formal block, Item Summary, Status. | incorporate | applied |
| C-0000I9-012 | [UID:00010O] should emit first-draft constructor/action/sender C++ and keep only the vtable-reset/destructor-tail helper as no-code inside the formal block. | Medium-high | Applied in [UID:00010O] formal block; score now `88/90`; `0x0048a690-0x0048a6af` no-code comment preserved. | `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md` formal block and score rationale. | incorporate | applied |
| C-0000I9-013 | [UID:00010R] should emit first-draft constructor/action/close-packet C++ and keep only the vtable-reset/destructor-tail helper as no-code inside the formal block. | Medium-high | Applied in [UID:00010R] formal block; score now `88/90`; selected-slot UInt16BE and mode/subtype mapping preserved. | `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md` formal block and score rationale. | incorporate | applied |
| C-0000I9-014 | [UID:00021Y] should emit a B010-compatible retained raw-helper marker, not callable C++. | High | Applied in [UID:00021Y] formal block; owner/emitter/split unchanged. | `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md` formal block. | incorporate | applied |
| C-0000I9-015 | [UID:00010S] should emit first-draft constructor/parser/draw C++ using source-facing `ClanBankItemEntry` fields inferred from parser and draw offsets. | Medium-high | Applied in [UID:00010S] formal block; score now `88/90`; packet cases `10/15/16`, sort/rebuild, and draw behavior preserved. | `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md` formal block and score rationale. | incorporate | applied |
| C-0000I9-016 | [UID:0002MO] should emit compiler-layout marker, not raw RTTI/vtable arrays. | High | Applied in [UID:0002MO] formal block and wording cleanup; stale unassigned/autogen wording corrected to current owner/emitter language. | `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md` formal block and wording cleanup. | incorporate | applied |
| C-0000I9-017 | No support sync to Clan, Socket, PacketBuffer, `g_packetSender`, text helpers, or [UID:00010P]/[UID:0002OB] is required. | Medium-high | Excluded with reason: no callback edit changes those ownership decisions; existing dependency/rejected-owner facts remain in current ClanBank/B001/B010 docs. | Support plan. | not-applicable | excluded-with-reason |
| C-0000I9-018 | Do not edit generated files, coverage reports, tracker rows, IDA DB, lock files, or supervisor ledgers manually. | High | Applied: no manual edits were made to generated files, coverage reports, validator/tool state, queue/lock files, IDA DB, executed archives, or supervisor ledgers; generated changes were validator-owned. | Callback checkpoint. | incorporate | applied |
| C-0000I9-019 | Validators should be scoped to every changed by-* file and use `--wait-generated`. | High | Applied: 16 scoped file validators ran with `--apply --wait-generated --queue-timeout 240`; all exited `0` with `ok:1`. | Implementation checklist validator section. | incorporate | applied |
| C-0000I9-020 | Generated `ClanBank.cpp` should refresh by validator and contain no `Empty Emitter Marker` rows for this file. | High | Applied: latest observed generated header `validator-command-id: 000000003112`, refreshed `2026-06-30T15:34:11-04:00`; `Empty Emitter Marker` count is `0`. | `by-file/ClanBank.md`; generated inspection after callback. | incorporate | applied |
| C-0000I9-021 | No in-scope blocker remains for implementation. | Medium-high | Applied: all accepted target/support doc edits were incorporated or explicitly excluded as not-applicable; validators passed; no unchecked blocker remains. | Report checklist and final recommendation. | incorporate | applied |
| C-0000I9-022 | Same-pass source-quality blockers for field/control/ListPane/helper names are resolved by best-current inferred names, not deferred. | Medium-high | Applied in target note, five class shells, and four method C++ blocks; remaining uncertainty is documented as a confidence cap rather than a blocker. | `by-file/ClanBank.md`; four method pages; five class pages. | incorporate | applied |
| C-0000I9-023 | No new split/child pages are required for implementation callback. | Medium | Excluded with reason: existing by-memory ranges carry accepted formal C++/markers; new child UID allocation was not authorized and is not needed for zero empty markers. | Support plan and rejected alternatives. | not-applicable | excluded-with-reason |

## Ranked Ownership And Source Placement Analysis

### 1. Keep [UID:0000I9] `ClanBank` as current generated source root

Evidence for:

- Current by-file page has valid path `"NexusTK/social/"` and `CANONICAL_OWNER:FILE`.
- MCP confirms local cluster from raw constructor `0x0048a0c0`, modeled item dialog methods, ClanBankPane methods, raw packet helpers, ClanBankItemListPane methods, singleton storage, and vtable data.
- Existing docs route the class pages and most exact method pages through ClanBank, with [UID:00021X]/[UID:0002OC]/[UID:00010Q] flowing through their direct class pages to the same file root.
- Resource and vtable evidence remains ClanBank/item-dialog local.

Evidence against:

- Original source split could still separate item dialogs into `ClanItemDialogs.cpp`.
- Several exact method pages now use best-current inferred field/helper declarations rather than recovered original names, so they remain first-draft rather than final-audit C++.

Decision: keep `ClanBank.cpp` as current generated bucket; do not split in this report.

### 2. Split into `ClanItemDialogs.cpp`

Evidence for:

- `ClanItemDialog`, `ClanDepItemDialog`, `ClanWidItemDialog`, and `ClanItemListPane` form a coherent item-dialog subcluster.
- Current `by-file/ClanBank.md` already lists `social/ClanItemDialogs.cpp` as a possible split.

Evidence against:

- Current generated route and file docs still place the family under `ClanBank.cpp`.
- Splitting would require coordinated source-tree/file ownership work beyond the empty-emitter callback.
- Empty markers can be resolved without a source split by formal class shells, first-draft method C++, retained raw/helper no-code markers, and the singleton declaration.

Decision: do not split now. Preserve as future source-layout candidate.

### 3. Move some items to `Clan`, Socket/PacketBuffer, TextFit, or MyItemListPane owners

Evidence for:

- Some raw opcode `0x4b` helper strips mirror deposit/withdraw behavior in `Clan`.
- Packet helpers and sender globals are dependencies.
- `ClanItemListPane` and `ClanBankItemListPane` use shared text/image/ListPane helpers.

Evidence against:

- Current source-family docs reject those moves: raw opcode strips remain Clan-owned retained/no-route helpers; PacketBuffer/Socket are infrastructure only; text-fit helpers are shared GrafPort/text support; `MyItemListPane` is a dependency with broader caller fanout.

Decision: rejected for this callback.

## Score And Metadata Recommendation

Target [UID:0000I9] should move from `87/87` to `90/89`.

Reason not higher:

- The final `ClanBank.cpp` versus `ClanItemDialogs.cpp` source split remains unresolved.
- Several class/method helper names are best-current inferred source names rather than recovered original symbols.
- Raw constructor/helper route questions remain real and are preserved as target-specific no-code proof.
- The generated source still depends on broader project declarations for UI controls, packet-buffer helpers, ListPane APIs, and shared slide/text helpers.

Reason not lower:

- All current empty emitters have direct implementation-ready formal blocks.
- The rejected marker-only aggregate treatment has been replaced by first-draft C++ for all four source-authored method clusters.
- The five class pages now carry declaration-level shells with `[[CHILDREN]]`, matching accepted project patterns.
- Current MCP confirms current function/raw/data boundaries, vtable anchors, and no-route negative evidence.
- The singleton global has a safe source declaration and the storage child has a clear stale-initializer correction.

Support-page score changes:

- [UID:000025], [UID:000026], [UID:000029], and [UID:00002G]: raise `86/89 -> 87/90`, set `EMITTER_POSITION_OPTIONAL:0`, keep owner/emitter `0000I9`.
- [UID:00002F]: raise `85/89 -> 86/90`, set `EMITTER_POSITION_OPTIONAL:0`, keep owner/emitter `0000I9`; raw constructor still caps confidence.
- [UID:00010O], [UID:00010Q], [UID:00010R], and [UID:00010S]: raise `85/90 -> 88/90` after first-draft formal C++ insertion; keep owner/emitter unchanged.
- [UID:00021X], [UID:0002OC], [UID:0002XJ], [UID:0002XK], [UID:00021Y], and [UID:0002MO]: leave support headers unchanged except [UID:0002XK] prose correction, because their accepted disposition is no-code/storage/compiler-layout or already-safe global declaration.

## Validator And Generated Freshness Expectations

During implementation callback, run scoped validators from `E:/NTK/GhidraBridge/source-3/project-documentation` for every changed by-* doc with `--apply --queue-timeout 240 --wait-generated`. At minimum:

- `by-file/ClanBank.md`
- `by-class/ClanBankItemListPane.md`
- `by-class/ClanBankPane.md`
- `by-class/ClanDepItemDialog.md`
- `by-class/ClanItemDialog.md`
- `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md`
- `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md`
- `by-class/ClanItemListPane.md`
- `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md`
- `by-global/g_pClanBankPane.md`
- `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md`
- `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md`
- `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md`
- `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md`
- `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md`
- `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md`

Generated freshness target: `auto-generated/NexusTK/social/ClanBank.cpp` header should be equal to or newer than the final changed-file validator command metadata and should contain zero `Empty Emitter Marker` rows for this file. Generated files must not be manually edited. Callback inspection notes that [UID:0002XK] is applied in its storage by-memory doc but does not appear as a separate generated UID section under the accepted declaration-only [UID:0002XJ] global block; this does not leave an empty marker.

## Changed Files

Report-only pass:

- Created: `tools/leaser/Agents/Agent-B009/research/0000I9-ClanBank-empty-emitter-family-source-quality.md`
- Modified by-* docs: none
- Leases: none
- Validators: not run during report-only pass

Implementation callback pass:

- Changed by-* docs:
  - `by-file/ClanBank.md`
  - `by-class/ClanBankItemListPane.md`
  - `by-class/ClanBankPane.md`
  - `by-class/ClanDepItemDialog.md`
  - `by-class/ClanItemDialog.md`
  - `by-class/ClanItemListPane.md`
  - `by-global/g_pClanBankPane.md`
  - `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md`
  - `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md`
  - `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md`
  - `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md`
  - `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md`
  - `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md`
  - `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md`
  - `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md`
  - `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md`
- Preserved without edits: [UID:0002OB] `by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md` and [UID:00010P] `by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md`.
- Generated output inspected but not manually edited: `auto-generated/NexusTK/social/ClanBank.cpp`.
- No generated reports, generated C++ files, manual coverage reports, project-level reports, validator/tool state, queue files, lock files, IDA DB, executed archives, or supervisor ledgers were manually edited.

Leases:

- Initial B009 lease command succeeded for all 16 changed by-* docs; that five-minute lease expired during the edit batch.
- Second B009 lease command succeeded for all 16 changed by-* docs before continuing edits.
- A later renewal attempt returned `Rejected[Already has lease]` for all 16 docs, confirming B009 still held the active lease set at that point.
- Final release command after validators: `python .\tools\leaser\leaser.py B009 unlease` returned `B009: No active leases`; the active lease set had expired during the long validator batch, and no B009 leases remained.

Validator batch:

| File | command_id | command_timestamp | exit | ok | generated_refresh | Notes |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-file/ClanBank.md` | `000000003033` | `2026-06-30T15:20:43-04:00` | `0` | `1` | completed | `missing_ref_uid` warnings for pre-existing `0003HF`, `0003BB`, `0003BA` references. |
| `by-class/ClanBankItemListPane.md` | `000000003035` | `2026-06-30T15:20:54-04:00` | `0` | `1` | completed | none |
| `by-class/ClanBankPane.md` | `000000003037` | `2026-06-30T15:21:14-04:00` | `0` | `1` | completed | none |
| `by-class/ClanDepItemDialog.md` | `000000003039` | `2026-06-30T15:21:34-04:00` | `0` | `1` | completed | none |
| `by-class/ClanItemDialog.md` | `000000003041` | `2026-06-30T15:21:56-04:00` | `0` | `1` | completed | none |
| `by-class/ClanItemListPane.md` | `000000003043` | `2026-06-30T15:22:14-04:00` | `0` | `1` | completed | none |
| `by-global/g_pClanBankPane.md` | `000000003045` | `2026-06-30T15:22:34-04:00` | `0` | `1` | completed | none |
| `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md` | `000000003048` | `2026-06-30T15:22:53-04:00` | `0` | `1` | completed | none |
| `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md` | `000000003051` | `2026-06-30T15:23:22-04:00` | `0` | `1` | completed | none |
| `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md` | `000000003055` | `2026-06-30T15:23:51-04:00` | `0` | `1` | completed | none |
| `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md` | `000000003059` | `2026-06-30T15:24:31-04:00` | `0` | `1` | completed | none |
| `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md` | `000000003063` | `2026-06-30T15:25:11-04:00` | `0` | `1` | completed | `missing_ref_uid` warning for pre-existing `0003BB` reference. |
| `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md` | `000000003067` | `2026-06-30T15:25:50-04:00` | `0` | `1` | completed | none |
| `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md` | `000000003071` | `2026-06-30T15:26:30-04:00` | `0` | `1` | completed | none |
| `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md` | `000000003075` | `2026-06-30T15:27:11-04:00` | `0` | `1` | completed | `missing_ref_uid` warning for pre-existing `0003BA` reference. |
| `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md` | `000000003079` | `2026-06-30T15:27:50-04:00` | `0` | `1` | completed | none |

Generated freshness:

- `auto-generated/NexusTK/social/ClanBank.cpp` header: latest observed `validator-command-id: 000000003112`, `validator-refreshed-at: 2026-06-30T15:34:11-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- The generated header is newer than the final changed-file validator command (`000000003079`, `2026-06-30T15:27:50-04:00`).
- `Empty Emitter Marker` count in generated `ClanBank.cpp`: `0`.
- Generated output includes [UID:0002OB] and [UID:00010P] unchanged. [UID:0002XK] is applied in its by-memory formal marker/storage doc but does not appear as a separate generated UID section under the current accepted declaration-only [UID:0002XJ] global block; no empty marker remains.

## Implementation Tracking Checklist

Callback-complete checklist:

- [x] Supervisor validation accepted the report for implementation callback.
- [x] Target metadata updated: `by-file/ClanBank.md` is `COMPLETION:90`, `CONFIDENCE:89`; path `"NexusTK/social/"` and `CANONICAL_OWNER:FILE` unchanged.
- [x] Target source-quality note added with pre-callback `17 total / 2 filled / 15 empty`, all-15 accepted disposition, MCP provenance, generated refresh expectation, score rationale, rejected alternatives, and no manual generated edits.
- [x] `by-class/ClanBankItemListPane.md` [UID:000025]: declaration shell with `ClanBankItemEntry`, `[[CHILDREN]]`, `EMITTER_POSITION_OPTIONAL:0`, score `87/90`.
- [x] `by-class/ClanBankPane.md` [UID:000026]: declaration shell with `m_bankMode`, `g_pClanBankPane` extern, `[[CHILDREN]]`, `EMITTER_POSITION_OPTIONAL:0`, score `87/90`.
- [x] `by-class/ClanDepItemDialog.md` [UID:000029]: declaration shell with constructor/action/sender prototypes, `[[CHILDREN]]`, `EMITTER_POSITION_OPTIONAL:0`, score `87/90`.
- [x] `by-class/ClanItemDialog.md` [UID:00002F]: declaration shell with constructor/destructor/update method, `[[CHILDREN]]`, `EMITTER_POSITION_OPTIONAL:0`, score `86/90`.
- [x] `by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md` [UID:00021X]: raw-constructor no-route formal marker applied.
- [x] `by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md` [UID:0002OC]: destructor-tail no-standalone-body formal marker applied.
- [x] `by-class/ClanItemListPane.md` [UID:00002G]: declaration shell with `ClanItemListEntry`, `[[CHILDREN]]`, `EMITTER_POSITION_OPTIONAL:0`, score `87/90`.
- [x] `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md` [UID:00010Q]: first-draft constructor/draw C++ plus raw selected-slot no-code comment, score `88/90`.
- [x] `by-global/g_pClanBankPane.md` [UID:0002XJ]: declaration `ClanBankPane *g_pClanBankPane;` applied.
- [x] `by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md` [UID:0002XK]: marker-only storage child applied and stale `0xffffffff` corrected to zero-filled virtual `.data`.
- [x] `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md` [UID:00010O]: first-draft constructor/action/sender C++ plus vtable-reset no-code comment, score `88/90`.
- [x] `by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md` [UID:00010R]: first-draft constructor/action/close-packet C++ plus vtable-reset no-code comment, score `88/90`; B010 UInt16BE selected-slot correction preserved.
- [x] `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md` [UID:00021Y]: B010-compatible retained raw-helper formal marker applied.
- [x] `by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md` [UID:00010S]: first-draft constructor/parser/draw C++, score `88/90`.
- [x] `by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md` [UID:0002MO]: compiler-layout marker applied and current no-raw-vtable-array wording added.
- [x] Already-filled emitters [UID:0002OB] and [UID:00010P] preserved without edits.
- [x] Rejected alternatives preserved in target note and report: broad file-level C++, route-comment-only class pages, marker-only method aggregate deferral, new child-page split in this callback, raw helper C++, duplicate global definitions, raw vtable arrays, generated/manual coverage edits, and source split work.
- [x] Score-blocker audit closure recorded: field/control/ListPane/helper names are best-current inferred source names and now confidence caps, not final deferrals.
- [x] Claim And Incorporation Ledger updated with callback verification states and proof.
- [x] Leases used only for immediate edit/validator work; final release found no active B009 leases because the long validator batch outlived the short lease window.
- [x] Scoped validators ran for every changed by-* file with `--apply --queue-timeout 240 --wait-generated`; command metadata recorded above.
- [x] Generated `auto-generated/NexusTK/social/ClanBank.cpp` inspected: latest observed header `000000003112`, refreshed `2026-06-30T15:34:11-04:00`, empty marker count `0`.
- [x] No generated files, coverage reports, project-level generated reports, validator/tool state, queue/lock files, IDA DB, executed archives, supervisor ledgers, or unrelated docs were manually edited.
- [x] Remaining unapplied accepted items: none. Exact blockers: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000I9-ClanBank-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000I9-ClanBank-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T15:41:07","uid":"0000I9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
