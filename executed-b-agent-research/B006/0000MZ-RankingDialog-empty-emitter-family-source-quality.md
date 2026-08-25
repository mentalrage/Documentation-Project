** TARGET-REPORT-UID:0000MZ **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B006 Research Report: [UID:0000MZ] RankingDialog Empty-Emitter Family Source Quality

Report-only assignment: `B006-revise-0000MZ-RankingDialog-empty-emitter-family-20260629`

Assigned target: [UID:0000MZ] `by-file/RankingDialog.md`

Generated source under review: `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`

Report status: revised implementation-ready after supervisor rejection. Do not execute or archive this report during report-only phase.

## Operating Constraints Observed

- Used the project-level `ntk-b-agent-workflow` skill and the referenced report/template/review standards.
- Did not spawn subagents.
- Did not lease files.
- Did not edit by-* docs, generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
- Only this report file was created/revised.
- MCP was required and available. No fallback-only evidence is used.

## Current MCP Session Evidence

Active MCP listener: `http://127.0.0.1:13337/mcp`

Database requested: `supervisor_resume_20260629`

Current health check:

- Request id `1001`, tool `server_health`, database `supervisor_resume_20260629`, HTTP `200`.
- Status `ok`.
- Uptime at check: `1326.532` seconds.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Module: `NexusTK.exe`.
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Imagebase: `0x400000`.
- `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.

Schema caveat: this MCP build does not expose historical `idb_meta`; `server_health` is the current session provenance source.

Representative current MCP facts checked during this report:

- Request id `1003`, `lookup_funcs`: `0x00459cd0 -> sub_459CD0 size 0x5`; `0x0045c1e0 -> sub_45C1E0 size 0x59`; `0x0045ddd0 -> sub_45DDD0 size 0x1bc`.
- Request id `1004`, `xrefs_to 0x00459cd0`: exactly one xref, data xref from `0x00610aa0`, no code callers.
- Request id `1005`, `decompile 0x00459cd0`: `char __stdcall sub_459CD0(int a1) { return 0; }`.
- Request id `1006`, `lookup_funcs`: raw/helper/data starts `0x004598b0`, `0x0045a990`, `0x0045add0`, `0x0045d790`, `0x0045db60`, `0x00610980`, `0x0067a7e4`, and `0x0067a7e8` all return `Not a function`.
- Request id `1007`, `xrefs_to`: raw starts `0x004598b0`, `0x0045a990`, `0x0045add0`, `0x0045d790`, and `0x0045db60` each have no cross-references to the raw start.
- Request id `1007`, `xrefs_to 0x0067a7e4`: 17 data xrefs, including constructor publish/clear in `sub_458610`, clear helper `sub_459810`, scalar deleting destructor `sub_459840`, ranking child/reward/user-list consumers, and dispatcher test at `0x005bd27d`.
- Request id `1007`, `xrefs_to 0x0067a7e8`: 6 data xrefs, including duplicate-modal guard `0x00458a97`, constructor publish/clear in `sub_45DBA0`, raw clear `0x0045dd8a`, clear helper `sub_45EFE0`, and scalar deleting destructor `sub_45F0C0`.
- Request id `1008`, `xrefs_to`: `0x0045ddd0` has one data xref from vtable slot `0x00610c34`; `0x0045d7e0` has one code xref from `0x0045debf` inside `sub_45DDD0`; `0x0045c260` has one constructor call from `0x00458695`; `0x0045c2a0` and `0x0045cb10` have packet-handler dispatch xrefs from `sub_459210`; `0x0045ce70` has 12 code xrefs; `0x0045f020` has modeled, raw, and exception-helper xrefs.
- Request id `1010`, `get_bytes`: raw helper starts begin with normal code bytes at `0x004598b0`, `0x0045a990`, and `0x0045d790`, matching current docs' raw-body/no-function caveat.
- Request id `1011`, `decompile 0x0045c1e0`: copies `0x4c` / 76 bytes on fast path, calls `sub_45D1B0` on full path, and returns the copied trailing dword/growth artifact.

These current facts agree with the existing by-* evidence and with the generator's 49-total / 13-filled / 36-empty state.

### Revision MCP Refresh

The rejection revision rechecked the disputed rows with the same active listener/database rather than relying on the previous report text:

- Request id `2004`, `tools/call server_health`, database `supervisor_resume_20260629`: status `ok`, uptime `2102.787` seconds, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- Request id `2005`, `lookup_funcs`: `0x00459cd0 -> sub_459CD0 size 0x5`; accepted comparator `0x0041da60 -> sub_41DA60 size 0x5`; `0x0045c1e0 -> sub_45C1E0 size 0x59`; `0x0045ddd0 -> sub_45DDD0 size 0x1bc`; `0x0045d7e0 -> sub_45D7E0 size 0x326`.
- Request id `2006`, `xrefs_to`: `0x00459cd0` has exactly one data xref at `0x00610aa0`; accepted FittingRoom comparator `0x0041da60` has exactly one data xref at `0x0060dcdc`; `0x0045c1e0` has one code xref at `0x0045cd5d`; `0x0045ddd0` has one data xref at `0x00610c34`; `0x0045d7e0` has one code xref at `0x0045debf`; `0x0067a7e4` has 17 data xrefs; `0x0067a7e8` has 6 data xrefs.
- Request ids `2007` and `2008`, `decompile`: both `0x00459cd0` and accepted comparator `0x0041da60` decompile to `char __stdcall ...(int) { return 0; }`.
- Request id `2010`, `get_bytes`: both `0x00459cd0` and accepted comparator `0x0041da60` begin with identical bytes `32 c0 c2 04 00 cc cc cc`; `0x00610a98` contains `0x004213f8, 0x00459a60, 0x00459cd0, 0x00544dd0`; accepted comparator vtable neighborhood `0x0060dcd4` contains `0x004213f8, 0x0041d870, 0x0041da60, 0x00544dd0`; `0x0067a7e4-0x0067a7eb` is zero-filled.
- Request ids `2011` and `2012`, `disasm`: both `0x00459cd0` and accepted comparator `0x0041da60` are exactly two instructions, `xor al, al` and `retn 4`.
- Request id `2013`, `analyze_function 0x0045c1e0`: prototype artifact `int __thiscall(int *this, int)`, one caller `sub_45CB10`, one callee `sub_45D1B0`, vector triplet at `+0x258/+0x25c/+0x260`, fast path copies `16+16+16+16+8+4 = 0x4c` bytes, and the binary return is the copied trailing dword/helper artifact.
- Request id `2015`, `analyze_function 0x0045ddd0`: secondary-vtable packet handler, opcode `0x7d`/subcommand `5`, selected-category validation through `dword_67A7E4 + 0x26c`, calls `0x0045d7e0`, appends/copies 560-byte entries through reward-vector helpers, destroys temporary nested item vectors, and returns `0` for nonmatching packet or `1` after accepting the packet.
- Request id `2016`, `decompile 0x0045d7e0`: parser consumes three length-prefixed multibyte strings into `rankStartText[8]`, `rankEndText[8]`, and `symbolText[256]`, reads bytes at `+0x220/+0x221`, loops over reward items, appends `0x208` item rows, returns the consumed byte count, and uses range-check failure only on wide-string overflow.

## Pre-Callback Generated State

Tracker/generated state captured during the revised report:

- `auto-generated/-ag-research-tracker.md` row for [UID:0000MZ]: total `49`, filled `13`, empty `36`, filled `26.5%`.
- Generated file: `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`.
- Pre-callback generated header: validator command id `000000001256`, refreshed `2026-06-29T21:40:04-04:00`.
- Existing generated source already emits declarations for:
  - [UID:0000BK] `RankingCategoryCollection`;
  - [UID:0000BL] `RankingDateTimeParts`, `RankingUserEntry`, `RankingCategoryRecord`;
  - [UID:0000BQ] `RankingUserListPane`;
  - method bodies for [UID:0002K0]-[UID:0002K8] and [UID:0002KA].
- Empty emitter markers remain for 36 pages listed below.

Important stale state:

- `by-file/RankingDialog.md` still has a direct report count of `0` in generated tracker context, even though older central executed support exists for [UID:0000XZ]. That executed report is not a direct [UID:0000MZ] report and should remain support/provenance only.
- The existing [UID:0000XZ] broad aggregate report/page is useful for duplicate avoidance but is not the owner for generated C++ output.
- Some by-file and support prose still carries stale MapPane-labeled UID/path pollution for the raw setter children [UID:000428]-[UID:00042C]. Those children are ranking category-record setter evidence, not MapPane source ownership.
- Existing docs correctly corrected the historical `localPlayerName[32]` claim: [UID:0000BL]/[UID:0001VN] now keep record offset `+0x26c-+0x2ab` as copied/reserved footer tail storage because `RankingUserListPane::OnPaint` gets the displayed footer name through `word_69BEE0` / `0x005a2dc0`.

## Source Placement Decision

Keep the file-level owner/source route as [UID:0000MZ] `RankingDialog.md` / `NexusTK/ui/dialogs/RankingDialog.cpp`.

The source module owns:

- the `RankingDialog` main dialog and private panes;
- `RankingCategoryCollection`;
- `RankingCategoryRecord` and user-entry/date-time support types;
- `RankingRewardInfoDialog` and reward-entry/reward-item parsing semantics;
- ranking singleton globals `g_pRankingDialog` and `g_pRankingRewardInfoDialog`;
- ranking vtable/read-only data as source-declared/generated-binary evidence.

Rejected source-placement alternatives:

- Do not split broad `RankingRewardInfoDialog.cpp`: the reward-info dialog is constructed, gated, and consumed inside ranking dialog flow, and current pages route it through `RankingDialog.cpp`.
- Do not emit a monolithic source body from [UID:0000XZ]. That page is a full executable island index and would duplicate child/class pages.
- Do not route raw setter UIDs [UID:000428]-[UID:00042C] through MapPane despite their stale filenames. Current ranking docs show they are `RankingCategoryRecord` raw setters at `0x0045c020`, `0x0045c030`, `0x0045c040`, `0x0045c1b0`, and `0x0045c1d0`.
- Do not route scroll-pane helpers to a generic scrollbar file yet. Current call sets and vtables keep them private to RankingEventScrollPane/RankingDialog unless later reuse evidence appears.
- Do not route packet parsing to a generic network/protocol module. The handlers are ranking opcode `0x7d` subcommand logic and consume ranking-local state.

## Empty Marker Disposition Summary

The rejected report was too broad. This revision withdraws the old full-family 36-row cleanup and provides an immediate implementation subset for the rows that are now evidence-ready under the score-blocker audit standard.

Accepted immediate subset:

- [UID:0001Z9] now matches the accepted FittingRoom default-false virtual pattern and should emit a first-draft body.
- [UID:0000S2] and [UID:0000S3] should emit concrete singleton declarations with forward declarations; the prior global type-placement blocker is resolved.
- [UID:00028U] and [UID:00028V] should be non-emitting duplicate storage pages once the by-global pages emit.
- [UID:0000BP] should emit only the reward support record declarations, not the dialog class.
- [UID:0002K9], [UID:0001ZF], and [UID:0001ZH] should get exact formal no-code comments because the remaining blockers are now concrete interface/container gaps, not vague provisional naming.

Deferred/out-of-scope for this callback:

- The old broad non-emitting rows for aggregate/index/vtable/read-only-data/container pages are plausible, but this report no longer asks implementation to clear them all in the same callback.
- The many scroll-pane bodies besides [UID:0001Z9] remain follow-up work because their event/geometry/invalidation/member interfaces are not accepted in formal C++.
- Large parser/handler bodies remain follow-up even after support declarations because packet reader/listener and source-level vector APIs are not yet formalized.

## Cross-Report Search Results

Supervisor requested a current/central/archived search by UID/address/name/source family. Relevant prior reports:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0000JE-FittingRoom-empty-emitter-family-source-quality.md`: accepted [UID:0002D3] as `bool FittingRoomScrollPane::DefaultVirtualFalse(int) { return false; }` despite unrecovered original virtual spelling. Evidence was exact `xor al, al; retn 4`, one vtable data xref, no callers/callees. Current MCP request ids `2005-2012` prove [UID:0001Z9] has the same body bytes, same `retn 4` signature, same single-vtable-xref shape, and same vtable-neighborhood pattern. There is no defensible project-rule difference; this report adopts the FittingRoom pattern.
- `source-3/project-documentation/executed-b-agent-research/B002/0002K9-ranking-user-entry-append-source-quality.md`: accepted [UID:0002K9] at `86/90`, owner/emitter [UID:0000BL], final C++ blank until a record-owned user-entry vector abstraction is emitted. The best source abstraction was `void RankingCategoryRecord::AppendUserEntry(const RankingUserEntry& entry)` with `m_userEntries.push_back(entry)`. Current MCP request id `2013` reconfirms the `0x4c` append and growth-helper path, so this revision preserves that source abstraction and narrows the blocker to the missing formal vector/container member, not the already-known row fields.
- `source-3/project-documentation/executed-b-agent-research/B001/0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality.md`: accepted the reward-entry/reward-item layout and kept parser/handler C++ blank pending declarations. Current MCP request ids `2015-2016` reconfirm the parser and handler; this revision now makes the record declarations implementation-ready on [UID:0000BP] while still deferring the large bodies for packet/vector interface reasons.

## Recommended Metadata / Formal Block Changes

Use short leases only during implementation. Validate one file at a time or by a clean simple loop. Do not edit generated reports, generated C++ under `auto-generated/`, project-level generated reports, manual `-coverage-report.md` files, validator state, or supervisor ledgers.

### C01 [UID:0000MZ] `by-file/RankingDialog.md`

Recommended edit:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:FILE`, `RECONSTRUCTABLE:TRUE`, and source path `NexusTK/ui/dialogs/`.
- Incorporate current MCP database/session `supervisor_resume_20260629` facts from request ids `2004-2016`.
- Replace the stale "full family empty-marker cleanup" wording with the immediate-subset/follow-up split above.
- Historicalize [UID:0000XZ] as support/duplicate-avoidance, not a direct [UID:0000MZ] source-quality closeout.
- Correct by-file context for stale MapPane-labeled [UID:000428]-[UID:00042C] references if touched: they are ranking category-record raw setters, not MapPane ownership.
- State that remaining generated empty markers are expected until follow-up rows are accepted; they should not be described as uninvestigated ownership gaps.

### C02 [UID:0001Z9] `by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md`

Recommended edit:

- Update to `COMPLETION:91`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000BO`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000BO`.
- Replace the formal empty block with this exact first-draft C++:

```cpp
bool RankingEventScrollPane::DefaultVirtualFalse(int)
{
    return false;
}
```

Rationale:

- Current MCP request id `2010` proves bytes `32 c0 c2 04 00` at [UID:0001Z9], identical to the accepted FittingRoom comparator.
- Request ids `2011-2012` prove both methods are exactly `xor al, al; retn 4`; request ids `2007-2008` prove both decompile to `return 0`.
- Request id `2006` proves both are vtable-only data-xref methods with no code callers.
- The prior "final inherited interface name unknown" caveat is real but no longer blocks first-draft source under the accepted FittingRoom `DefaultVirtualFalse(int)` pattern. Use the descriptive method name and keep the caveat in prose.

### C03 [UID:0000BP] `by-class/RankingRewardInfoDialog.md`

Recommended edit:

- Keep owner/emitter route through [UID:0000MZ].
- Do not emit the `RankingRewardInfoDialog` class declaration yet.
- Insert only the following reward support declarations in the formal C++ block:

```cpp
struct RankingRewardItem
{
    wchar_t name[256];
    int quantity;
    unsigned short iconId;
    unsigned char paletteIndex;
    unsigned char reserved_207;
};

struct RankingRewardEntry
{
    wchar_t rankStartText[8];
    wchar_t rankEndText[8];
    wchar_t symbolText[256];
    char symbolFrameIndex;
    unsigned char symbolAttribute;
    unsigned char reserved_222[2];
    RankingRewardItem *itemsBegin;
    RankingRewardItem *itemsEnd;
    RankingRewardItem *itemsCapacity;
};
```

Rationale:

- Request id `2016` proves `rankStartText[8]`, `rankEndText[8]`, `symbolText[256]`, bytes at `+0x220/+0x221`, and item-vector append of `0x208` rows.
- `RankingRewardItem` size is exactly `0x208`: `wchar_t name[256]` at `+0x000`, `int quantity` at `+0x200`, `unsigned short iconId` at `+0x204`, `paletteIndex` at `+0x206`, and one reserved byte at `+0x207`.
- `RankingRewardEntry` size is exactly `0x230`: text fields through `+0x220`, two payload bytes, two padding bytes, then a begin/end/capacity triplet at `+0x224/+0x228/+0x22c`.
- `symbolAttribute` remains an inferred descriptive name, but B001 already rejected treating `+0x221` as padding because the parser writes it from packet data.

### C04 [UID:0002K9] `by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md`

Recommended edit:

- Keep metadata `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000BL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BL`.
- Insert this exact formal no-code comment:

```cpp
// [UID:0002K9] Source body intentionally deferred.
// Current MCP request 2013 proves a 0x4c-byte RankingUserEntry append through
// RankingCategoryRecord offsets +0x258/+0x25c/+0x260 and calls sub_45D1B0 only
// when the user-entry storage is full.
// The best source body is void RankingCategoryRecord::AppendUserEntry(const RankingUserEntry& entry)
// with m_userEntries.push_back(entry), but [UID:0000BL] still emits raw begin/end/capacity
// pointers instead of an accepted source-level user-entry vector/container member.
// Emitting a body now would either hand-port compiler OWORD/QWORD/DWORD copies or invent
// an unaccepted helper API, so no formal body is source-safe in this callback.
```

Resolved blocker statement:

- `RankingUserEntry` row fields are not the remaining blocker; [UID:0000BL] already emits `categoryId`, `rank`, `wchar_t name[32]`, and `score`.
- The exact remaining blocker is the source-level vector/member abstraction for the `+0x258/+0x25c/+0x260` triplet and its growth helper, not generic owner/range uncertainty.

### C05 [UID:0001ZF] `by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md`

Recommended edit:

- Keep metadata `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000BP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BP`.
- Insert this exact formal no-code comment:

```cpp
// [UID:0001ZF] Source body intentionally deferred.
// Current MCP request 2016 proves ParseFromPacket-style behavior: three length-prefixed
// strings become rankStartText[8], rankEndText[8], and symbolText[256], bytes at +0x220/+0x221
// become symbolFrameIndex/symbolAttribute, and a variable item loop appends 0x208-byte
// RankingRewardItem rows.
// [UID:0000BP] now carries the support record declarations, but the parser body still depends on
// unaccepted packet-reader/string-conversion interfaces and a source-level nested item-vector API.
// Emitting the current decompile would expose compiler temporaries, byte offsets, and helper calls
// instead of the original packet/parser source shape.
```

Resolved blocker statement:

- Reward entry/item type layout is now implementation-ready through C03.
- Remaining blockers are the packet-reader/string-conversion interface and nested item-vector abstraction, plus whether the no-caller tiny accessors should be out-of-line methods or inlined field access.

### C06 [UID:0001ZH] `by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md`

Recommended edit:

- Update metadata to `COMPLETION:87`, `CONFIDENCE:91`.
- Repair metadata to `CANONICAL_OWNER:0000BP` and `EMITTER_UIDS:0000BP`; current prose already says owner is [UID:0000BP], while metadata still routes through [UID:0000MZ].
- Insert this exact formal no-code comment:

```cpp
// [UID:0001ZH] Source body intentionally deferred.
// Current MCP request 2015 proves the secondary-vtable reward-info packet handler:
// accept opcode 0x7d/subcommand 5, validate the category through g_pRankingDialog,
// parse the reward-entry count, append/copy 0x230-byte RankingRewardEntry records,
// destroy the temporary nested item vector, invalidate/redraw, and return handled status.
// The body belongs to RankingRewardInfoDialog, but the packet-context/listener interface,
// selected-category accessor surface, reward-entry vector member, and invalidation call shape
// are not accepted in formal C++ yet.
// Emitting the decompile now would preserve compiler stack temporaries and raw helper calls,
// not the original listener method source.
```

Resolved blocker statement:

- Reward entry/item type layout is now handled by C03.
- The exact remaining blockers are the packet-context/listener interface and reward-entry vector member/API. The owner/range and opcode/subcommand behavior are no longer open questions.

### C07 [UID:0000S2] `by-global/g_pRankingDialog.md`

Recommended edit:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000MZ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000MZ`.
- Insert this exact formal C++:

```cpp
class RankingDialog;

RankingDialog *g_pRankingDialog = 0;
```

Rationale:

- Current MCP request id `2006` reconfirms the 17-xref lifecycle set.
- Request id `2010` reconfirms zero-filled storage at `0x0067a7e4`.
- The type blocker is resolved by source-visible forward declaration; the global is a pointer and does not require the full `RankingDialog` class definition in the same formal block.

### C08 [UID:0000S3] `by-global/g_pRankingRewardInfoDialog.md`

Recommended edit:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000MZ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000MZ`.
- Insert this exact formal C++:

```cpp
class RankingRewardInfoDialog;

RankingRewardInfoDialog *g_pRankingRewardInfoDialog = 0;
```

Rationale:

- Current MCP request id `2006` reconfirms the 6-xref lifecycle set.
- Request id `2010` reconfirms the zero-filled neighboring singleton storage.
- The type blocker is resolved by source-visible forward declaration; the unmodeled constructor-adjacent clear at `0x0045dd8a` remains evidence prose, not a blocker for the global declaration.

### C09 [UID:00028U] `by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md`

Recommended edit:

- Reclassify as non-emitting exact storage support: `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS:`, blank formal C++.
- Preserve the exact storage address, zero bytes, and 17-xref evidence.
- State that source output belongs to [UID:0000S2], not this by-memory storage row.

### C10 [UID:00028V] `by-memory/0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md`

Recommended edit:

- Reclassify as non-emitting exact storage support: `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS:`, blank formal C++.
- Preserve the exact storage address, zero bytes, and 6-xref evidence.
- State that source output belongs to [UID:0000S3], not this by-memory storage row.

### C11 Generated Output Check

After implementation validation, confirm whether `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` no longer contains empty markers for accepted rows C02-C10. Remaining markers for non-accepted follow-up rows are expected and must be recorded as remaining, not silently treated as callback failures.

## Follow-Up Rows Not Accepted In This Callback

| UID | Disposition for this revision | Concrete remaining blocker |
| --- | --- | --- |
| 0000BM | Follow-up. Do not add a broad no-code row in this callback. | Full `RankingDialog` class declaration still requires accepted `DialogPane`/packet-listener/control member surface. Globals can use forward declarations without this. |
| 0000BO | Follow-up. Keep class formal block blank. | [UID:0001Z9] can emit under the FittingRoom default-false pattern, but the class declaration still lacks stable pane/control interfaces and member names. |
| 0000Y2, 0000Y5, 0000Y7, 000202, 000204 | Follow-up raw-helper rows. | Raw starts have no IDA function objects/no incoming raw-start xrefs; they need target-specific raw-helper source placement, not a blanket formal no-code pass. |
| 0000Y3, 0001ZA, 0000Y4, 0001ZB, 0000Y6 | Follow-up modeled scroll-pane bodies. | Event type names, geometry types, scroll-part enum, invalidation/effect APIs, and member names must be accepted before bodies are source-safe. |
| 0001ZC, 0000Y9, 0001ZG, 0000XZ | Follow-up aggregate/index rows. | Likely non-emitting by-structure pages, but the old report's broad sweep is withdrawn. Apply only after a separate page-by-page callback or supervisor acceptance. |
| 0001ZE, 0001ZK, 0001ZJ, 0002ON, 0001YJ, 0001YK, 0001VN, 0001VO | Follow-up support/generated-binary rows. | Likely non-emitting support, but not accepted in this immediate subset. Preserve evidence until separately accepted. |

## Evidence Notes By Family

### Category Record

- [UID:0002K9] is not blocked by row layout names anymore. `RankingUserEntry` fields are already documented and emitted through [UID:0000BL].
- The best source abstraction is exactly a record-owned vector append: `void RankingCategoryRecord::AppendUserEntry(const RankingUserEntry& entry)` with `m_userEntries.push_back(entry)`.
- The unsafe alternatives are now explicit: do not hand-port the four OWORD copies plus QWORD/DWORD tail; do not invent a `sub_45D1B0` authored helper API; do not change the return type to `int` because the only caller ignores the binary artifact return.

### Ranking Event Scroll Pane

- [UID:0001Z9] is now treated like accepted FittingRoom. It is exact behavior-ready and source-output-ready as a descriptive `DefaultVirtualFalse(int)` first draft.
- The fact that [UID:0000BO] has no full class declaration is not a blocker for [UID:0001Z9] under the accepted pattern; it remains a blocker for the larger scroll-pane bodies.

### Reward Info / Reward Entry

- C03 resolves the reward record declaration blocker at report-level detail without pretending the dialog class itself is ready.
- [UID:0001ZF] body remains blocked by packet/string/vector interfaces, not by entry/item layout.
- [UID:0001ZH] owner metadata should match the prose owner [UID:0000BP]. The body remains blocked by listener/context and vector-member APIs, not by opcode, selected-category validation, parser calls, or range ownership.

### Globals / Storage

- [UID:0000S2] and [UID:0000S3] should emit source-level pointer definitions. The class names exist and pointer definitions only need forward declarations.
- [UID:00028U] and [UID:00028V] are exact storage evidence rows. Reclassifying them as non-emitting is a by-structure duplicate fix because source output belongs to the by-global concept pages.

## Score Rationale

Recommended [UID:0000MZ] score after implementation: `COMPLETION:88`, `CONFIDENCE:91`.

Rationale:

- The source route through `NexusTK/ui/dialogs/RankingDialog.cpp` remains strong.
- The revision fixes the highest-confidence emitted source opportunities: one default-false virtual, two singleton globals, duplicate storage rows, and reward support declarations.
- Confidence stays above 90 because MCP evidence, prior accepted reports, and current by-* docs agree on the disputed facts.
- Completion stays below 90 because this report intentionally leaves many scroll-pane, aggregate/index, and packet/vector rows for follow-up rather than clearing all 36 markers.

## Claim And Incorporation Ledger

Implementation callback must mark every accepted row below as applied, already-present, or explicitly excluded with a concrete reason. No row should be silently skipped.

| Claim | Target | Required incorporation | Callback verification |
| --- | --- | --- | --- |
| C01 | [UID:0000MZ] | Update by-file score/prose/source-placement to `88/91`; incorporate current MCP ids `2004-2016`; replace broad full-family cleanup with immediate-subset/follow-up wording. | Applied in `by-file/RankingDialog.md`; header is `COMPLETION:88`, `CONFIDENCE:91`, active database/request ids `2004-2016` and the narrowed immediate-subset/follow-up disposition are documented, and stale [UID:0000XZ] wording is historicalized. Validated by final by-file command `000000001369`. |
| C02 | [UID:0001Z9] | Emit exact first-draft `RankingEventScrollPane::DefaultVirtualFalse(int)` body; preserve FittingRoom comparison, vtable-only xref, bytes, and no-caller evidence. | Applied in `by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md`; formal block emits `bool RankingEventScrollPane::DefaultVirtualFalse(int) { return false; }` with FittingRoom comparison, vtable-only xref, identical bytes, and no-caller evidence. Validated by command `000000001316`; generated at `RankingDialog.cpp:192-197`. |
| C03 | [UID:0000BP] | Emit only `RankingRewardItem` and `RankingRewardEntry` support declarations; do not emit full `RankingRewardInfoDialog` class or methods. | Applied in `by-class/RankingRewardInfoDialog.md`; formal block emits only the two support records and preserves the no-full-dialog-class decision. Validated by command `000000001317`; generated at `RankingDialog.cpp:206-227`. |
| C04 | [UID:0002K9] | Insert exact formal no-code comment; preserve best source abstraction `AppendUserEntry(...){ m_userEntries.push_back(entry); }` and the vector-member blocker. | Applied in `by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md`; formal block is the accepted no-code comment and preserves the `m_userEntries.push_back(entry)` abstraction plus source-level vector/member blocker. Validated by command `000000001318`; generated at `RankingDialog.cpp:167-177` as a comment block, not an empty marker. |
| C05 | [UID:0001ZF] | Insert exact formal no-code comment; preserve parser/layout evidence and note that C03 resolves type layout while packet/string/vector APIs remain blockers. | Applied in `by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md`; formal block is the accepted no-code comment, preserving parser/layout evidence and the remaining packet/string/vector API blockers after C03. Validated by command `000000001319`; generated at `RankingDialog.cpp:229-239` as a comment block, not an empty marker. |
| C06 | [UID:0001ZH] | Repair owner/emitter to [UID:0000BP], update score to `87/91`, and insert exact formal no-code comment preserving handler evidence and exact blockers. | Applied in `by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md`; header is `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000BP`, `EMITTER_UIDS:0000BP`, and the formal block is the accepted no-code comment. Validated by command `000000001320`; generated at `RankingDialog.cpp:241-253` as a comment block, not an empty marker. |
| C07 | [UID:0000S2] | Emit exact `RankingDialog` forward declaration and `g_pRankingDialog = 0` definition; preserve 17-xref lifecycle evidence. | Applied in `by-global/g_pRankingDialog.md`; formal block emits `class RankingDialog;` and `RankingDialog *g_pRankingDialog = 0;` with 17-xref lifecycle evidence. Validated by command `000000001321`; generated at `RankingDialog.cpp:272-275`. |
| C08 | [UID:0000S3] | Emit exact `RankingRewardInfoDialog` forward declaration and `g_pRankingRewardInfoDialog = 0` definition; preserve 6-xref lifecycle evidence. | Applied in `by-global/g_pRankingRewardInfoDialog.md`; formal block emits `class RankingRewardInfoDialog;` and `RankingRewardInfoDialog *g_pRankingRewardInfoDialog = 0;` with 6-xref lifecycle evidence. Validated by command `000000001322`; generated at `RankingDialog.cpp:277-280`. |
| C09 | [UID:00028U] | Reclassify exact `g_pRankingDialog` storage row as non-emitting duplicate support; preserve zero-storage and 17-xref evidence. | Applied in `by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md`; `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, zero-storage and 17-xref evidence preserved, and source output routed to [UID:0000S2]. Validated by command `000000001323`; [UID:00028U] is absent from generated `RankingDialog.cpp` as expected. |
| C10 | [UID:00028V] | Reclassify exact `g_pRankingRewardInfoDialog` storage row as non-emitting duplicate support; preserve zero-storage and 6-xref evidence. | Applied in `by-memory/0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md`; `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, zero-storage and 6-xref evidence preserved, and source output routed to [UID:0000S3]. Validated by command `000000001324`; [UID:00028V] is absent from generated `RankingDialog.cpp` as expected. |
| C11 | Generated output | After validation, record generated freshness and whether accepted rows C02-C10 no longer produce empty markers; record remaining non-accepted markers as follow-up. | Applied. Final B006 by-file validation command `000000001369` refreshed `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp` with header `validator-command-id: 000000001369`, `validator-refreshed-at: 2026-06-29T22:39:02-04:00`; after B006 released its lease, a later workspace validator refresh was observed at header `000000001373` / `2026-06-29T22:40:00-04:00` with the accepted blocks still present. C02-C08 generate source/comment blocks, C09-C10 do not emit duplicate storage rows, and remaining empty markers are only non-accepted follow-up UIDs. |

## Implementation Tracking Checklist

- [x] Take short leases only for the immediate edit/validator batch; release them immediately afterward. Initial B006 lease batch covered the ten edited by-* docs from `2026-06-30T02:25:22Z` to `2026-06-30T02:30:22Z`; renewed only `by-file/RankingDialog.md` from `2026-06-30T02:33:18Z` to `2026-06-30T02:38:18Z`; took one final by-file-only lease immediately before command `000000001369`; released with `python .\leaser.py B006 unlease`, and `Agents/current_leases.md` then showed other agents only and no B006 rows.
- [x] Update `by-file/RankingDialog.md` to `COMPLETION:88`, `CONFIDENCE:91` and incorporate current MCP session facts. Applied and validated by final by-file command `000000001369`.
- [x] Apply C02 first-draft C++ for [UID:0001Z9] and preserve the FittingRoom comparison in prose. Applied and validated by command `000000001316`.
- [x] Apply C03 reward support declarations on [UID:0000BP] without adding a full dialog class. Applied and validated by command `000000001317`.
- [x] Apply C04-C06 exact formal no-code comments for [UID:0002K9], [UID:0001ZF], and [UID:0001ZH]; do not summarize away their concrete blockers. Applied and validated by commands `000000001318`, `000000001319`, and `000000001320`.
- [x] Apply C07-C08 global definitions and C09-C10 duplicate storage reclassification. Applied and validated by commands `000000001321`, `000000001322`, `000000001323`, and `000000001324`.
- [x] Preserve exact evidence detail: ranges, bytes, vtable slots, xrefs, caller/callee facts, row strides, padding, opcode/subcommand facts, rejected alternatives, and prior accepted report provenance. Applied in the edited by-* docs; no accepted evidence was summarized away.
- [x] Do not apply the withdrawn broad 36-row cleanup from the rejected report. Only accepted C01-C11 rows were applied; remaining empty markers outside the subset remain follow-up rows.
- [x] Run scoped validators from `source-3/project-documentation`, one target file at a time or with a clean simple loop. Commands `000000001316` through `000000001325`, plus by-file freshness reruns `000000001327` and `000000001369`, completed with exit code `0`.
- [x] Include `--wait-generated` when validating `by-file/RankingDialog.md`. Applied in commands `000000001325`, `000000001327`, and final command `000000001369`.
- [x] Record exact validator command, command id, timestamp, exit code, ok count, warnings, side effects, and generated freshness for `auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`. Recorded below.
- [x] Confirm generated empty-marker status for accepted rows and record any remaining marker with exact blocker/follow-up disposition. Accepted C02-C08 no longer emit empty markers, C09-C10 are non-emitting and absent from generated C++, and remaining markers are non-accepted follow-up rows.
- [x] Update this report's ledger/checklist during callback only after edits are verified; do not execute/archive the report manually. Completed here; report was not executed or archived.

## Callback Validator Record

Implementation MCP precheck:

- Request id `3001`, database `supervisor_resume_20260629`, tool `server_health`, HTTP `200`; status `ok`; uptime `2919.38`; IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; module `NexusTK.exe`; input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; `auto_analysis_ready:true`; `hexrays_ready:true`; `strings_cache_ready:true`; `strings_cache_size:2067`.

Validator commands run from `source-3/project-documentation`:

| Command id | Timestamp | Exact command | Exit | Ok | Warnings and side effects |
| --- | --- | --- | --- | --- | --- |
| `000000001316` | `2026-06-29T22:32:07-04:00` | `python .\tools\validator.py --mode file --file "by-memory\0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md" --apply --queue-timeout 240` | `0` | `1` | `completion_update 0001Z9 91`; autogen registry hash and `blank -> block`; projected stats update; generated refresh deferred. |
| `000000001317` | `2026-06-29T22:32:09-04:00` | `python .\tools\validator.py --mode file --file "by-class\RankingRewardInfoDialog.md" --apply --queue-timeout 240` | `0` | `1` | 14 `missing_ref_uid` warnings for unresolved registry refs `0003X6`, `0003X7`, `0003X8`, `0003X9`; autogen registry hash and `blank -> block`; projected stats update; generated refresh deferred. |
| `000000001318` | `2026-06-29T22:32:11-04:00` | `python .\tools\validator.py --mode file --file "by-memory\0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md" --apply --queue-timeout 240` | `0` | `1` | 15 `missing_ref_uid` warnings for unresolved registry refs `0003X1`, `0003WT`, `0003X2`, `0003X3`; `uid_link_insert 0000BL`; autogen registry hash and `blank -> block`; projected stats update; generated refresh deferred. |
| `000000001319` | `2026-06-29T22:32:13-04:00` | `python .\tools\validator.py --mode file --file "by-memory\0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md" --apply --queue-timeout 240` | `0` | `1` | `uid_link_insert 0000BP` twice; autogen registry hash and `blank -> block`; projected stats update; generated refresh deferred. |
| `000000001320` | `2026-06-29T22:32:15-04:00` | `python .\tools\validator.py --mode file --file "by-memory\0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md" --apply --queue-timeout 240` | `0` | `1` | Completion/confidence set to `87/91`; owner/emitter moved `0000MZ -> 0000BP`; `uid_link_insert 0000BP`; autogen registry hash and `blank -> block`; projected stats update; generated refresh deferred. |
| `000000001321` | `2026-06-29T22:32:16-04:00` | `python .\tools\validator.py --mode file --file "by-global\g_pRankingDialog.md" --apply --queue-timeout 240` | `0` | `1` | Completion/confidence set to `88/92`; autogen registry hash and `blank -> block`; `uid_link_insert 0000MZ`; stats row removal/rescore recommendation; projected stats update; generated refresh deferred. |
| `000000001322` | `2026-06-29T22:32:18-04:00` | `python .\tools\validator.py --mode file --file "by-global\g_pRankingRewardInfoDialog.md" --apply --queue-timeout 240` | `0` | `1` | Completion/confidence set to `88/92`; autogen registry hash and `blank -> block`; `uid_link_insert 0000MZ`; `reference_index_add 00028V`; projected stats update; generated refresh deferred. |
| `000000001323` | `2026-06-29T22:32:20-04:00` | `python .\tools\validator.py --mode file --file "by-memory\0x0067a7e4-0x0067a7e8.g_pRankingDialog.md" --apply --queue-timeout 240` | `0` | `1` | Autogen registry set [UID:00028U] `true -> false`, blank emitter, `uid_link_insert 0000S2` twice; projected stats update; generated refresh deferred. |
| `000000001324` | `2026-06-29T22:32:22-04:00` | `python .\tools\validator.py --mode file --file "by-memory\0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md" --apply --queue-timeout 240` | `0` | `1` | Autogen registry set [UID:00028V] `true -> false`, blank emitter, `uid_link_insert 0000S3` twice; projected stats update; generated refresh deferred. |
| `000000001325` | `2026-06-29T22:32:23-04:00` | `python .\tools\validator.py --mode file --file "by-file\RankingDialog.md" --apply --queue-timeout 240 --wait-generated` | `0` | `1` | `autogen_cpp_update 0000MZ auto-generated/NexusTK/ui/dialogs/RankingDialog.cpp`; research tracker update; memory auto-coverage update; generated metadata refreshes; generated refresh completed. The generated source content was correct, but a later by-file rerun was used to refresh the visible generated header. |
| `000000001327` | `2026-06-29T22:33:26-04:00` | `python .\tools\validator.py --mode file --file "by-file\RankingDialog.md" --apply --queue-timeout 240 --wait-generated` | `0` | `1` | 14 `missing_ref_uid` warnings for unresolved refs `0003X6`, `0003X7`, `0003X8`, `0003X9`; `autogen_children_fallback_insert:8`; `autogen_children_marker_missing:19`; broad existing `autogen_emitter_has_no_code:441`; `autogen_registry_rebuild:1`; `generated_metadata_refresh:283`; `projected_stats_update:1`; `stats_incremental_noop:1`; `autogen_backup_create:3`; generated report metadata refreshed by validator; generated C++ metadata refreshed; generated refresh completed. |
| `000000001369` | `2026-06-29T22:39:02-04:00` | `python .\tools\validator.py --mode file --file "by-file\RankingDialog.md" --apply --queue-timeout 240 --wait-generated` | `0` | `1` | 14 `missing_ref_uid` warnings for unresolved refs `0003X6`, `0003X7`, `0003X8`, `0003X9`; `autogen_children_fallback_insert:8`; `autogen_children_marker_missing:19`; broad existing `autogen_emitter_has_no_code:441`; `autogen_registry_rebuild:1`; `generated_metadata_refresh:282`; `projected_stats_update:1`; `research_tracker_update:1`; `stats_incremental_noop:1`; `autogen_backup_create:3`; generated report metadata refreshed by validator; generated C++ metadata refreshed; generated refresh completed. |

Generated freshness:

- B006-owned generated refresh completed with `validator-command-id: 000000001369`, `validator-refreshed-at: 2026-06-29T22:39:02-04:00`, `validator-refresh-source: foreground-generated-refresh`.
- Post-release concurrency note: a later workspace validator refresh was observed with header `validator-command-id: 000000001373`, `validator-refreshed-at: 2026-06-29T22:40:00-04:00`, `validator-refresh-source: foreground-generated-refresh`; the accepted C02-C10 marker status below remained unchanged.
- Accepted rows present as source/comment blocks: [UID:0002K9] at generated lines `167-177`, [UID:0001Z9] at `192-197`, [UID:0000BP] at `206-227`, [UID:0001ZF] at `229-239`, [UID:0001ZH] at `241-253`, [UID:0000S2] at `272-275`, and [UID:0000S3] at `277-280`.
- [UID:00028U] and [UID:00028V] are absent from generated source as expected because they are now non-emitting duplicate storage support rows.
- Remaining empty markers are non-accepted follow-up rows: [UID:0001ZC], [UID:0001ZE], [UID:0000Y9], [UID:0001VN], [UID:0000BM], [UID:0000Y0], [UID:0000BN], [UID:0000BO], [UID:0000Y2], [UID:0000Y3], [UID:0001ZA], [UID:0000Y4], [UID:0001ZB], [UID:0000Y5], [UID:0000Y6], [UID:0000Y7], [UID:0001VO], [UID:0001YK], [UID:000202], [UID:000204], [UID:0000YA], [UID:0001ZK], [UID:0001ZJ], [UID:0000XZ], [UID:0001ZG], [UID:0002ON], and [UID:0001YJ].

## Final Recommendation

Implementation callback C01-C11 is complete. Do not apply the withdrawn broad 36-row cleanup from the rejected report.

This revision fixes the rejected report's overreach: it adopts the accepted FittingRoom default-false pattern where evidence is identical, emits singleton globals now that forward declarations resolve the type blocker, adds reward support declarations, and gives the remaining disputed parser/vector rows exact target-specific no-code proofs instead of broad provisional wording.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0000MZ-RankingDialog-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0000MZ-RankingDialog-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T22:43:48","uid":"0000MZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
