** TARGET-REPORT-UID:0002E6 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002E6 FittingRoomDialogItemState LoadCategoryFromJson Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0002E6] as a reconstructable `FittingRoomDialogItemState` method emitted through [UID:000051] and [UID:0000JE] at implemented metadata `90/91`. The complete accepted C2E6-001 through C2E6-100 documentation package and all 20 managed formals are now incorporated and scoped-validated; UID000051/UID000050/UID000053 emit at positions `0/5/10`.
- Final disposition: the former indexed key table, const/reference Json values, whole-object `memset`, behavior-divergent cleanup, custom `Insert` facade, generated globals, fabricated selection helpers, stale member names, and compiler-helper source ownership are preserved only as rejected or historical interpretations. The current formals preserve the observed behavior and use human source-facing C++03 vocabulary.
- Raw-page closure: validator-owned allocation produced UID0004WI for `[0x004219f0,0x00421a22)`; the canonical predecessor/parent/adjustor identities are UID0004WJ/UID0004WL/UID0004WK. Stale UID00042D and old-range FittingRoom references were removed without editing validator state.
- Validation/readback: final foreground command `000000016927` at `2026-07-23T22:35:04-04:00` completed with `ok: 1`. Its accepted semantic `NexusTK/cashshop/FittingRoom.cpp` payload is SHA256 `6642C30C5A2FA3B15EF25CA239552F6B7D539BB9528242C2EB65F212E7044A2D`, 99,511 bytes, 2,818 physical lines, with zero stale parser facades, IDA `Locale`, fake padding members, `m_equipmentEntries`, `previewPartMode`, generated globals, or fabricated selection helpers. The current physical validator-header checkpoint is command17009 and is recorded under Validator Results.
- Supervisor coverage closure: all 43 exact manual coverage actions are present and were independently validated by commands16953 (`by-memory`), 16954 (`by-class`), 16955 (`by-file`), 16956 (`by-type/by-struct`), and 16957 (`by-global`), each exiting `0` with `ok: 1`. B004 supplied the handoffs and did not edit any coverage report.
- Confidence: strong for behavior, ownership, layout, source placement, dependency closure, and current generated source. Remaining lexical uncertainty concerns only lost original local/typedef/access-specifier/capacity-constant spellings; it does not justify raw compiler/IDA names or lower the implemented target below `90/91`.
- Lifecycle/status: ordinary repair is complete, all 43 manual coverage actions are already supervisor-applied/validated under commands16953 through16957, exact active-artifact Gate 1 and fresh Gate 2A passed report SHA `E64983DE492480E142E10A179AAC1179FD3C1491F3B21F198A7C3D6C50026846`, and Supervisor Gate 2B is `APPLIED_VERIFIED` through the detailed IDA action/readback under the exact IDA heading. Supervisor-only `execute_report`/archive is authorized. B004 did not run, probe, dry-run, or invoke any report lifecycle command; the validator-owned history footer and executed-report registry are authoritative for lifecycle truth whether this report body is read from the active path before execution or from the archive afterward.

## Supporting Research

- Healthy live IDA MCP was mandatory and remained available throughout the pass. MCP transport session `f871e369-77aa-420e-aedd-de8d622dda47` used open IDB session `9b0396a3` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; server health, auto-analysis, Hex-Rays, and strings were ready.
- Fresh MCP work covered function lookup, decompilation, disassembly, exact bytes, SHA-256 computation from returned bytes, xrefs, literal VA/RVA scans, caller/callee analysis, adjacent ranges, switch-table data, and the raw retained constructor-shaped range.
- Current target SHA-256 over exact `[0x00422ba0,0x00422e91)` bytes is `A67857467CC82D78BFFA6B42CCB93A2A484544E67706856F36A57357604E79E1` for 753 bytes.
- The staged JsonCpp source was checked rather than treating wrapper names as sufficient. `third_party_embeds/jsoncpp` is the accepted official commit `b299d3581f4dc670734f1fe1a34fce1282337802`, between tags `1.7.4` and `1.7.5`.
- Historical B001/B003/B004/B005/B007 reports were used only as leads. Their custom `FittingRoomCategoryLookup` method bodies and source-hygienic failure cleanup are superseded by the fresh binary/container analysis in this report.
- Wave2/Wave3 mentions in older FittingRoom/JsonCpp pages were treated as stale historical leads and were not used as current evidence.

## Target

- Target UID: `0002E6`.
- Additional target UIDs: none. Support pages are reconciliation destinations, not additional fully covered report targets.
- Declared-target inventory:

| UID | Path | Role |
| --- | --- | --- |
| `0002E6` | `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md` | Exact source-bearing method body under investigation. |

- Target path: `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md`.
- Assignment-time tracker checkpoint: `auto-generated/-ag-research-tracker.md` command `000000016821`, refreshed `2026-07-23T05:23:11-04:00`, SHA `CDEAD87AEB6EA445E93351880F0CE149B80CA6CEE7AB44DA478683276DC34F82`, showed UID0002E6 at `87/89` with zero reports. This is a timestamped historical queue snapshot, not current lifecycle truth.
- Post-callback generated checkpoint: `NexusTK/cashshop/FittingRoom.cpp` command `000000016927`, refreshed `2026-07-23T22:35:04-04:00`, SHA `6642C30C5A2FA3B15EF25CA239552F6B7D539BB9528242C2EB65F212E7044A2D`, 99,511 bytes/2,818 physical lines.
- Current scores and parent state: target `90/91`, `CANONICAL_OWNER:000051`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000051`; class [UID:000051] is `90/91` under file [UID:0000JE] `88/90`.
- Current lifecycle authority: assignment-time tracker/report counts are historical checkpoints. Only the validator-owned report-history footer and executed-report registry determine current lifecycle/count state.

## Current Target State

- Current metadata is structurally and semantically validated: `90/91`, owner/emitter `000051`, reconstructable true.
- Existing owner/emitter state is correct: the sole caller is the item-state document loader, the receiver is the item-state object, the category store is at item-state offset `+0x220`, and the source file remains `NexusTK/cashshop/FittingRoom.cpp`.
- Historical pre-callback C++ defects, now corrected in the implemented formal, were:
  - separate range check plus `kFittingRoomCategoryJsonKeys[category]` does not match the observed method-local switch and direct case string loads;
  - `const Json::Value categoryValue` selects the const index overload, while the executable calls the non-const `Json::Value::operator[](int)`;
  - `const Json::Value& itemValue` omits the observed `Json::Value` copy constructor/destructor pair;
  - `new FittingRoomCatalogEntry; memset(entry, 0, sizeof(*entry));` would clear all 192 bytes, while the executable initializes only category `+0x00` and vector triplet `+0xb4/+0xb8/+0xbc`;
  - `delete entry` and `ReleaseCatalogEntryVector(pendingEntries)` do not occur on parse failure and change malformed-input behavior;
  - `m_categoryLookup.Insert(...)` and the emitted custom helper family are unsupported source APIs; the exact lowering is an MSVC hash-container `insert` path.
- Current generated source is declaration-ordered and source-closed for this package: UID000051/UID000050/UID000053 appear at positions `0/5/10`; UID0002E5 emits its signed accessor; UID0000D9 supplies `MutableData()`; and every accepted direct dependency route is present.
- Current selected-entry source consistently uses one `FittingRoomDialogItemState::m_selectedFittingItems` vector and exact `FittingRoomSelectionEntry { category, name, catalogIndex, partTypes }` fields across reset, paint, input, construction, and destruction. Older `m_equipmentEntries`, flattened-dialog, and opaque-record interpretations remain dated history only.
- Compiler-generated list/hash/vector pages retain their detailed binary evidence but are non-reconstructable, non-emitting implementation artifacts rather than hand-authored FittingRoom APIs.
- Raw initializer integrity is resolved: UID0004WI owns exact `[0x004219f0,0x00421a22)`; UID0004WJ/UID0004WL/UID0004WK own the related predecessor/parent/adjustor pages. UID00042D remains solely the unrelated MapPane identity.
- Related docs checked include UID0002E4, UID0002E7, UID0002EB, UID0002EC, UID0000WV, UID0002U4, UID0002U8, UID0002U9, UID0002UB, UID0002UH, UID0002UI, UID0000WW, UID000051, UID0000JE, UID0000KI, UID0000WY, UID0002EH, UID0002EE, and the historical B-agent FittingRoom reports.
- Gate/lifecycle record: ordinary callback repair is implemented and scoped-validated; all 43 manual coverage actions are supervisor-applied/validated with no remaining coverage action; exact active-artifact Gate 1 and fresh Gate 2A passed SHA `E64983DE492480E142E10A179AAC1179FD3C1491F3B21F198A7C3D6C50026846`; and Supervisor Gate 2B is `APPLIED_VERIFIED` by the existing detailed action/readback section. Supervisor-only `execute_report`/archive is authorized, while its resulting state is recorded solely by the validator-owned footer/registry and remains durable whether this body is read before execution or after archival. B004 made no IDA mutation and ran/probed no report lifecycle command.

## Executive Recommendation

Implementation status: every recommendation in this section was accepted and applied during the callback, including the complete declaration/formal package, raw UID/range repair, dependency closure, compiler-helper historicalization, and generated readback. Imperative wording below is retained as the exact accepted design record, not as currently pending work.

- Keep direct owner [UID:000051] `FittingRoomDialogItemState` and source file [UID:0000JE] `FittingRoom`.
- Keep the exact target range unsplit. The three-byte NOP and 11-entry jump table beginning at `0x00422e91` stay in [UID:0002EH] as compiler-generated output of this method's switch.
- Use a method-local `switch` to select the eleven JSON member names. Reject the current indexed static table as a source-shape claim.
- Use `Json::Value categoryValue` and `Json::Value itemValue`, preserving the observed by-value `get`, non-const indexing, copy construction, and destruction.
- Treat the constructor-shaped initialization as the inlined source constructor call `new FittingRoomCatalogEntry(category)`. Reject whole-object `memset`.
- Preserve the executable's malformed-input behavior exactly: return `false` without deleting the failed entry or previously accepted entry pointers. The local vector destructor frees only its pointer buffer.
- Express category insertion as normal hash-container source:
  `m_categoryLookup.insert(std::make_pair(static_cast<unsigned char>(category), entries));`
- Emit the UID000051 declaration package at position `0`: direct C++03, Win32, Shell, CRT, and complete `json/json.h` headers; exact category enum values `0..10` plus count `11`; naturally aligned six-byte part record with signed part code and without a fake padding member; exact `0xc0` catalog entry with an inferred 85-wide-character backing buffer and no synthetic reserved fields; pointer-vector/map aliases; the exact `0xb4` selection-entry layout proved by the list-pane insertion path; and the complete item-state declaration with natural compiler padding after `m_cacheLoaded`. Close the class before namespace-scope `[[CHILDREN]]`; no PCH or undeclared project facade is assumed.
- Emit the complete UID000050 dialog declaration at position `5`, after UID000051 and before UID000053 position `10`: evidence-backed project-relative headers `../ui/core/DialogPane.h`, `../map/ObjectStatusBlob.h`, and same-directory `CashShopRequest.h`; exact method inventory; the `+0x47c..+0x7ac` field layout; size guard; singleton declaration; and narrow `FittingRoomListPane` friendship. Apply each selected-entry support change as a complete exact managed destination formal, never as a body-only excerpt.
- Replace UID0002E4's unsupported parser `SimpleUString::AssignAnsi` plus parser-side `SimpleUString::c_str` facade with the directly evidenced C++03 `std::wstring` iterator-range construction and preserve the explicit `wcscpy_s(..., 0x50, wideName.c_str())` bound. The remaining `wideName.c_str()` is the valid `std::wstring::c_str()` call. Retain UID0002DL's independently valid `SimpleUString itemName`, `Assign`, and inline SSO-buffer access through the exact UID0000D9 formal. Replace the packed/value-initialized part local with the naturally aligned record and assign only its four semantic fields.
- Emit UID0002E5 as the exact signed-index part accessor now that its record and entry declarations are visible.
- Emit UID000053 with the complete existing list-pane declaration plus direct `../ui/core/ControlPane.h`, `../ui/core/Event.h`, `../ui/core/Region.h`, `../render/EPFTileContext.h`, `../render/ImageLib.h`, `../render/ItemObjImageLib.h`, `../render/Surface.h`, `../ui/panels/UserPane.h`, and `../util/StringUtil.h` routes, and exact `kFittingRoomGridColumns = 6` / `kFittingRoomGridVisibleCells = 18` declarations. Emit UID0000D9 with the complete SSO-7 declaration plus inline `MutableData()` selecting heap storage only when `m_capacity > 7`.
- Reconcile UID0002DL to the accepted APIs rather than preserving reverse-engineering aliases: `EPFTileContext::Initialize`, `EPFTileContext::bounds`, automatic `Region` lifetime, `GrafPort::GetClipRegion`, `SetClipRect`, `SetClipRegion`, inherited `m_visibleBounds`, `ResourceLayoutTable::LookupLayoutEntry` through `g_pEPFLib`, `ItemObjImageLib::GetItemGlyphBounds` through `g_pItemObjImageLib`, `InitPointPair`, `InitRectBounds`, `g_pfnFillRect`, `SetTextColor`, and `GetTextWidth`.
- Reconcile UID0002DN to complete Event/UserPane declarations: use `Event::m_type`, `EventPayload::m_pointer`, `kEventLeftButtonUp`, `kEventMouseWheel`, correct `PointInRect(y, x, bounds)` order, and source-facing `g_pUserPane->m_nameVisible`. Add narrow `FittingRoomListPane` friendship to the existing complete UID00007B declaration rather than inventing `g_pGlobalState`, `fittingRoomInputLocked`, or a getter absent from the executable.
- Inline UID0002DN's exact standard-vector construction, exact-match erase, overlap erase, append, automatic temporary destruction, and part-record switch. Do not declare `ConstructSelectionEntry`, `RemoveSelectionEntry`, `RemoveEntriesWithOverlappingParts`, `DestroyTemporarySelectionEntry`, or `ApplyFittingRoomPartRecord`: live target disassembly proves those operations are in-body/container lowering and no direct helper route exists.
- Reclassify the low-level custom lookup helper source claims as compiler-generated MSVC list/hash/vector machinery. Preserve every binary detail as historical/implementation evidence, but do not emit hand-authored custom helper bodies.
- The accepted callback repaired the orphan constructor page through the specified validator-owned sequence. The resulting identities are UID0004WI raw constructor, UID0004WJ predecessor, UID0004WL parent, and UID0004WK adjustor; MapPane UID00042D was neither reused nor altered.

## Supervisor Active Recheck

- Gate record: supervisor accepted initial Gate 1 artifact SHA `F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26` and issued the implementation callback for the exact C2E6 package; after implementation and focused repairs, exact active-artifact Gate 1 and fresh Gate 2A passed SHA `E64983DE492480E142E10A179AAC1179FD3C1491F3B21F198A7C3D6C50026846`, with Gate 2B continuity retained as `APPLIED_VERIFIED`.
- Split repair: the target itself remains unsplit. The adjacent raw constructor boundary/UID repair is complete as UID0004WI, and the adjacent switch data remains a separate compiler-generated page.
- Every source-bearing element and direct dependency in the accepted package is resolved, applied, scoped-validated, and generated-read-back:
  - method source body: exact formal replacement supplied;
  - entry initialization: resolved as constructor semantics;
  - JsonCpp calls: resolved against staged source;
  - vector behavior and failure ownership: resolved;
  - category map insertion: resolved as standard MSVC hash-container lowering;
  - jump table: resolved as generated switch data;
  - class/type closure: exact direct header routes, natural padding, source order, formals, score effects, and destinations are implemented; command16927 generated readback proves the expected declaration order and source vocabulary;
  - parser string route: the observed 24-byte SSO-7 temporary and range helper resolve to a normal `std::wstring(itemName.begin(), itemName.end())`; no nonexistent parser-side `SimpleUString::AssignAnsi` or parser-side `SimpleUString::c_str` declaration is required. The implemented `std::wstring::c_str()` is valid and required by `wcscpy_s`, while UID0002DL retains its separate valid SSO-7 `SimpleUString::Assign` plus inline `MutableData()` route;
  - constructor empty-string route: IDA `Locale` resolves to the zero-valued runtime storage immediately preceding `"string too long"`, so source uses `m_catalogVersion("")`;
  - selection-entry layout and lexical route: the live list-pane paint/input paths prove category, `wchar_t name[0x50]`, signed `catalogIndex`, and `std::vector<int> partTypes` at exact offsets `0/+4/+0xa4/+0xa8`; prior `displayName`/`itemIndex` spellings are weaker synonyms and are historicalized;
  - selected-entry member identity: UID0002DI/UID0002DL/UID0002DN reach dialog `+0x744/+0x748/+0x74c`, which is item-state `+0x240/+0x244/+0x248`; the strongest source member is `m_selectedFittingItems`, while lifecycle-only `m_equipmentEntries` is historicalized;
  - legal access route: UID0002DI/UID0002DL/UID0002DN directly read dialog and embedded item-state internals with no accessor call. The narrow, source-plausible route is `friend class FittingRoomListPane;` in both `FittingRoomDialog` and `FittingRoomDialogItemState`, followed by direct `itemState->m_selectedFittingItems` use. No convenience accessor or raw-offset API is invented;
  - part accessor: exact declaration and formal body supplied;
  - special-mode field: dialog `+0x49e` is `m_baseAppearance + 0x22`, exactly the existing `ObjectStatusBlob` union member `m_compositionMode`; no new ObjectStatusBlob field is introduced;
  - grid constants: OnPaint multiplies rows by six and caps the visible loop at immediate `0x12`, proving six columns and eighteen visible cells; UID000053 now declares both constants;
  - input helpers: all five prior source-facing helper names are removed from the formal and replaced by the observed inline C++03 vector and switch operations;
  - project headers: FittingRoom's `NexusTK/cashshop/` source route resolves `DialogPane`, `ObjectStatusBlob`, `CashShopRequest`, `ControlPane`, `Event`, `Region`, `EPFTileContext`, ImageLib/resource-layout lookup, `ItemObjImageLib`, `Surface`, `UserPane`, and `SimpleUString` through direct project-relative headers and exact owner pages. Existing complete Event, EPFTileContext, ItemObjImageLib, UserPane, geometry, and Surface declarations are consumed rather than duplicated; Region, ImageLib/resource-layout visibility, and the LivingObjectPane friend route receive exact callback destinations below;
  - raw constructor page: behavior, correct boundary, affected references, validator allocation, and post-allocation handoff are terminalized with UID0004WI; related split identities are UID0004WJ/UID0004WL/UID0004WK.

## Inference Research Guidance Check

- `by-structure.md` requires emitted C++ to preserve runtime behavior and resemble plausible original human source, while compiler-generated helper bodies should not be copied into source as custom APIs.
- Existing documentation assumptions treated as uncertain included the indexed key table, source-hygienic failure cleanup, `FittingRoomCategoryLookup::Insert`, `CreateFittingRoomCategoryLookupNode`, `FinalizeInsert`, `EraseNode`, `AllocateFittingRoomCategoryNode`, and `DestroyFittingRoomCategoryNode`.
- Direct IDA fact: exact instructions, calls, object offsets, strings, xrefs, function boundaries, cleanup paths, and helper layouts.
- Documentation evidence: accepted class/file ownership, JsonCpp source snapshot, category/entry vocabulary, and current manual/generated states.
- Inference: human spellings such as `categoryKey`, `entries`, `FittingRoomCatalogCategory`, and the likely `stdext::hash_map`/project-alias declaration.
- The chosen body avoids depending on the unresolved typedef spelling: both a direct `stdext::hash_map` member and a project alias expose `.insert`.
- Wave2/Wave3 references were ignored as stale and are not part of the evidence chain.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution |
| --- | --- | --- |
| Category mapping shape | `cmp eax,0Ah; ja default; jmp ds:jpt_422BD7[eax*4]`, then each case loads one literal address and joins. No indexed pointer-table load exists. | Use a method-local switch. Preserve direct case strings. Reject `kFittingRoomCategoryJsonKeys[]` for this method. |
| Category type | Caller loops integer 0 through 10; semantic domain is stable and existing class docs use `FittingRoomCatalogCategory`. Unsigned switch lowering also rejects negative values through the default branch. | Keep the descriptive enum parameter. Names remain inferred but source-quality. |
| Json member lookup | Target constructs `Json::Value()` default, calls staged `Json::Value::get(const char*, const Value&) const`, receives by-value result, and destroys default. | `Json::Value categoryValue = root.get(categoryKey, Json::Value());`. |
| Category constness | Index call is `0x00427500`, matching staged non-const `Json::Value::operator[](int)`, not the const overload. | Category local must be non-const. |
| Item lifetime | Each indexed element is copied through `Json::Value` copy constructor `0x00425010` and destroyed on success/failure. | Use `Json::Value itemValue = categoryValue[index];`, not a reference. |
| Entry construction | Allocation is 0xc0. Only category and the vector triplet are initialized before parser call. The retained raw body performs exactly those stores. | Infer `new FittingRoomCatalogEntry(category)` with a constructor that initializes category and default-constructs `parts`; reject `memset`. |
| Entry failure | No scalar destructor/delete call occurs. Current item temp, local pointer-vector storage, and category temp are destroyed; pointed-to entries remain allocated. | Preserve leak behavior. Reject "hygienic" cleanup because exact execution replication has priority. |
| Pointer vector | Three-pointer local; direct append or shared four-byte element grow helper; vector copy at `0x00421290` allocates/memmoves pointers. | `std::vector<FittingRoomCatalogEntry*> entries; entries.push_back(entry);`. |
| Category key width | Stack transfer record stores only low byte of category before insertion. Accessor pages also use byte keys. | Use `static_cast<unsigned char>(category)` for map insertion. |
| Map/storage type | `this+0x220` layout is float max-load factor, list sentinel/count, bucket vector, mask, bucket count. Node is two links plus byte key and vector payload. Hash is one-byte FNV-1a. Duplicate insert, bucket repair, and rehash match MSVC `_Hash`. | Source is a standard-library hash container, best historical spelling `stdext::hash_map<unsigned char, std::vector<FittingRoomCatalogEntry*> >` or an equivalent project alias. |
| `Insert` API | No standalone source wrapper call exists; the target directly contains pair construction/list insertion/hash finalization. | Use `.insert(std::make_pair(...))`; historicalize custom `Insert`. |
| Helper names | No original symbols or UDTs support custom FittingRoom node/finalize/erase allocator APIs. Their bodies are exact STL internals and diagnostics include `list<T> too long`. | Reclassify source claims as compiler-generated container machinery; preserve disassembly facts but clear hand-written helper C++. |
| Constructor page liveness | Raw bytes form an out-of-line `thiscall` constructor, but no xref, VA/RVA pointer, or function model exists; active target inlines the same semantics. | Retain as exact duplicate/compiler evidence covered by target/class source, after range and UID repair. |
| Catalog enum/constants | Caller and target use a four-byte category value and cover exactly `0..10`; the eleven direct case literals provide stable semantic names and order. | Declare `FittingRoomCatalogCategory` with `kFittingRoomCategoryMain` through `kFittingRoomCategorySpecialtySets` and `kFittingRoomCategoryCount = 11`. These spellings are inferred source names, while values/order are direct facts. |
| Catalog-entry declaration | Allocation is `0xc0`; parser and consumers prove category `+0x00`, enabled `+0x04`, tile `+0x06`, color `+0x08`, name at `+0x0a`, and part vector `+0xb4`. The explicit copy bound is 80 wide characters, while the exact field-to-vector span is 170 bytes. Audited parser, list-input, lookup, reset, and destruction consumers reveal no independent field in `+0xaa..+0xb3`. | Declare `wchar_t name[0x55]`, the only ordinary wide-array extent that spans exactly `+0x0a..+0xb3`; keep the observed `wcscpy_s` bound at `0x50`. Do not invent `reserved05`, `reserved09`, or `reservedAA`; alignment before `tile` and `name` is natural compiler padding. The constructor initializes only `category` and `parts`. |
| Part-record/accessor closure | Parser/grow/destroy/accessor all use six-byte stride. Stores occur at `+0`, `+2`, `+4`, and `+5`; byte `+1` is never read or written. OnInputEvent sign-extends `part` and excludes sentinel `-1`; default x86 alignment naturally inserts one byte before the word at `+2` and still produces size six. | Declare normal `{signed char part; unsigned short tile; unsigned char color; unsigned char gender;}` order without `#pragma pack` or a source member for byte `+1`. Emit UID0002E5 as `GetPart(signed char) const` with the same upper-bound-only behavior and inline `GetPartCount()`. |
| Category-map declaration | `+0x220` has the Visual C++ hash-map layout and the methods in this report require a single compile-visible member type. | Define `FittingRoomCatalogEntryList` and `FittingRoomCategoryMap` as C++03 aliases over `std::vector<FittingRoomCatalogEntry*>` and `stdext::hash_map<unsigned char,...>`. This is the strongest era/compiler inference and removes all custom reverse-engineered lookup classes. |
| Selection-entry declaration | Live UID0002DL and UID0002DN consumers use a four-byte category at `+0`, `wchar_t name[0x50]` at `+4`, signed two-byte `catalogIndex` at `+0xa4`, natural two-byte alignment at `+0xa6`, and `std::vector<int> partTypes` at `+0xa8`. The binary proves field roles; current emitted source independently converges on `name` and `catalogIndex`. | Declare `FittingRoomSelectionEntry { category; name[0x50]; catalogIndex; partTypes; }`. Historicalize the report's weaker `displayName`/`itemIndex` spellings and the opaque `reservedState[0xa8]`/byte-vector fiction. |
| Selected-entry member identity | UID0002DI reads dialog `+0x744/+0x748`; UID0002DL and UID0002DN calculate item-state base `dialog+0x504` and read item-state `+0x240/+0x244/+0x248`. Constructor `0x00422020`, reset `0x0041d5e0`, destructor `0x00422330`, and storage release `0x00423870` use that same vector triple and `0xb4` stride. | The single source member is `m_selectedFittingItems`. Historicalize `m_equipmentEntries` as the earlier lifecycle-only role name; do not model two vectors or flatten the member onto `FittingRoomDialog`. |
| Selected-entry visibility/access | List-pane methods directly access dialog active-category/preview fields, `m_itemState`, and item-state selected entries; no non-inline accessor call occurs. A public field would be possible but broadens visibility without evidence, while a new accessor would be invented. | Use a narrow `friend class FittingRoomListPane;` declaration in both `FittingRoomDialog` and `FittingRoomDialogItemState`. UID0002DI/UID0002DN use a local `itemState` pointer and `itemState->m_selectedFittingItems`; UID0002DL already has that source shape. |
| Item-state declaration/order | Exact offsets prove 24-byte string at `+0x00`, 520-byte path at `+0x18`, 32-byte map at `+0x220`, 12-byte selected-entry vector at `+0x240`, cache flag `+0x24c`, and two 24-byte strings at `+0x250/+0x268`. The three bytes after the flag are compiler alignment before the next 24-byte string, not a source field. | Give UID000051 the complete class declaration at emitter position `0`, forward-declare/friend `FittingRoomListPane`, omit `m_reserved24D`, close it before `[[CHILDREN]]`, and declare every emitted item-state method. Natural 32-bit MSVC alignment yields exact size `0x280`. |
| Parser wide-string dependency | UID0002E4 constructs a 24-byte SSO-7-shaped wide string from the narrow name range and then passes its buffer to `wcscpy_s`. Helper `0x00423060` has the exact iterator-range append/grow shape and the same compiler string diagnostic family. Current UID0000D9 `SimpleUString` formal has neither `AssignAnsi` nor `c_str`, so the existing project-type parser facade is not declaration-closed or source-proven. | Use `std::wstring wideName(itemName.begin(), itemName.end())`; include `<string>`. Historicalize only the unsupported parser `SimpleUString::AssignAnsi` and parser-side `SimpleUString::c_str` facade. Preserve `wideName.c_str()` as the valid `std::wstring::c_str()` call. This does not reject UID0002DL's separate valid SSO-7 use. |
| Paint `SimpleUString` route | UID0002DL calls the proven UID0000D9 `Assign(const wchar_t*, unsigned int)` endpoint, then the binary selects the heap pointer only when capacity exceeds the SSO-7 threshold and otherwise uses the inline buffer before `_wcstok`. The current 24-byte UID0000D9 layout already exposes that union and capacity. | Retain `SimpleUString itemName` in UID0002DL. Add inline `wchar_t* MutableData()` to the complete UID0000D9 formal and include documented `../util/StringUtil.h` from UID000053. Do not reintroduce parser-only `AssignAnsi`/`c_str`. |
| Grid constants | UID0002DL computes the visible start as `m_scrollPosition * 6`, wraps columns modulo six, and terminates after immediate `0x12` cells. Sibling key/scroll docs independently establish a three-row grid page. | Declare `kFittingRoomGridColumns = 6` and `kFittingRoomGridVisibleCells = 18` in the complete UID000053 formal. These are list-pane source constants, not undeclared report conveniences. |
| Appearance-mode field | Dialog base appearance begins at `+0x47c`; target accesses `+0x49e`, exactly `ObjectStatusBlob +0x22`. Current UID00009S declares that byte as union `m_compositionMode` / `m_posture`, and NewHuman consumers prefer composition semantics. | Use `dialog->m_baseAppearance.m_compositionMode`. Reject invented `previewPartMode`; no ObjectStatusBlob layout or formal change is required. |
| UID0002DN source shape | Target disassembly contains exact-match erase, overlap erase, append, temporary vector destruction, and the part-code switch inline. The callee set has no route to the five report helper names; matching helper-island functions are compiler vector grow/erase/release lowerings. | Express all operations inline with C++03 iterators, `std::vector::erase`, nested overlap scans, `push_back`, automatic local destruction, and a numeric part switch. Do not declare or emit the five fabricated helpers. |
| Project header routes | FittingRoom is documented at `NexusTK/cashshop/`; DialogPane at `NexusTK/ui/core/`; ObjectStatusBlob at `NexusTK/map/`; CashShopRequest at `NexusTK/cashshop/`; ControlPane at `NexusTK/ui/core/`; StringUtil at `NexusTK/util/`. UID00003T/UID00009S/UID00001H/UID000038/UID0000D9 already carry the complete class declarations. UID0000I0 already documents `cashshop/CashShopRequest.h`, and UID0000OB already documents `util/StringUtil.h`; UID0000IT, UID0000M6, and UID0000IG currently name only their `.cpp` modules. | Use `../ui/core/DialogPane.h`, `../map/ObjectStatusBlob.h`, `CashShopRequest.h`, `../ui/core/ControlPane.h`, and `../util/StringUtil.h`. The accepted callback must add exact companion-header paths to UID0000IT, UID0000M6, and UID0000IG, linking each to its existing complete class declaration, while preserving the already-explicit UID0000I0/UID0000OB header routes. This creates exact documentation/header destinations instead of asserting that current autogen already materializes those files. |
| Constructor `Locale` label | `0x0060d780` has 38 runtime data refs. Exact bytes are four zero bytes followed by `"string too long"`; constructor call receives the address of the leading zero storage as an empty C string. The label is IDA/runtime-data vocabulary, not a source locale object. | Emit `m_catalogVersion("")`; require no `Locale` declaration. Preserve the rdata finding as the reason the old label is rejected. |
| Win32/Shell/CRT declarations | UID0002E7 directly uses `MAX_PATH`, `SHGetFolderPathW`, `CSIDL_PERSONAL`, `S_OK`, `CreateDirectoryW`, `GetLastError`, `ERROR_ALREADY_EXISTS`, `swprintf_s`, `FILE`, `_wfopen`, `fseek`, `ftell`, `fread`, `fclose`, `SEEK_*`, `malloc`, and `free`; existing UID0002EF calls `strcpy_s`. Import dispatch slots in the executable are compiler/linker lowering, not source declarations. | UID000051 directly includes `<windows.h>`, `<shlobj.h>`, `<stdio.h>`, `<stdlib.h>`, `<string.h>`, and `<wchar.h>` in addition to the C++03/container/JsonCpp headers. `<string.h>` is required for the existing `SaveEncodedStateBuffer` formal. No PCH is assumed; Shell32 linkage remains an existing build/import dependency rather than an invented wrapper. |
| Raw-page UID collision workflow | UID00042D is validator-owned by live MapPane; the raw FittingRoom copy has an invalid duplicate header and a truncated filename/range. Validator docs assign a UID to a Markdown file with no UID and resolve canonical `[TMP:"..."]` references. | Rename to `0x004219f0-0x00421a22...`, remove only the invalid duplicate UID line, validate the corrected missing-UID target first, then edit and validate each of five referring ordinary pages one at a time through the corrected TMP path. The corrected target is the sixth changed ordinary file but does not self-reference. Never edit `validator.ini` or UID00042D. |
| Source placement | Sole caller and receiver are item-state-owned; all literals and storage are within the FittingRoom catalog subsystem. | Keep `NexusTK/cashshop/FittingRoom.cpp`. |
| Exact original local names | No PDB/debug symbols survive. | Use concise project-consistent names `categoryKey`, `categoryValue`, `itemValue`, `entries`, `entry`, `itemCount`, and `index`; never preserve IDA labels. |

Rejected alternatives:

- Indexed `kFittingRoomCategoryJsonKeys`: rejected by direct switch case loads and jump-table xref.
- `const Json::Value categoryValue`: rejected by the non-const index overload.
- `const Json::Value& itemValue`: rejected by explicit copy construction and destruction.
- Whole-object `memset`: rejected because only four dword stores occur and parser-owned fields remain untouched before parse.
- `delete entry` plus vector release on failure: rejected because no such calls occur and it changes malformed-input behavior.
- Custom `FittingRoomCategoryLookup` node/finalizer APIs: rejected as reverse-engineered names for MSVC template internals.
- Leaving class/type/API declarations to an unspecified future header or PCH pass: rejected. UID000051 supplies direct standard/platform/JsonCpp routes; UID000050/UID000053 use explicit project includes; and every additional Event/render/region/image/user/surface/geometry dependency has an exact owner/header/destination below. Complete class formals, exact source order, the complete `0x7ac` dialog declaration, and narrow list-pane friendship define the callback plan, but current score remains capped until that plan validates.
- Keeping the parser-side `SimpleUString::AssignAnsi`/parser-side `SimpleUString::c_str` facade, IDA `Locale`, packed `reserved`, `reservedAA`, `reservedState`, `m_reserved24D`, `displayName`, `itemIndex`, or `m_equipmentEntries`: rejected because live helper/rdata/consumer/layout research resolves each as an unsupported facade, IDA label, natural padding, an inferred backing-array extent, weaker lexical alias, or historical lifecycle-only name for `m_selectedFittingItems`. This rejection does not apply to UID0002DL's independently valid paint-time SSO-7 `SimpleUString` use and does not reject the proposed standard-library `std::wstring::c_str()` call.
- Inventing `GetSelectedFittingItems()` or using dialog/item-state raw offsets in authored C++: rejected because live list-pane methods compile to direct member access and the narrow friend route resolves legality without introducing an unobserved API.
- Reusing UID00042D or hand-editing `validator.ini`: rejected because UID00042D belongs to MapPane and UID allocation/state are validator-owned.
- Default-initializing all catalog-entry scalar fields: rejected because the retained constructor and live inline sequence initialize only category and the vector object.
- `operator[]` assignment into the map: rejected because the executable performs insert-with-duplicate-result behavior and candidate-node destruction, not find/default-construct/assign.
- Source-owned switch table bytes: rejected because [UID:0002EH] is generated dispatch data.

Research closes the selected-entry layout, lexical field names, storage identity, appearance-mode byte, grid constants, UID0002DN inline operations, UID0002DL SSO-buffer access, Event layout/enums, EPFTileContext layout, Region lifetime, resource/image singleton names, UserPane source global, Surface callback, and geometry/GrafPort signatures. The callback implemented this source declaration/reconciliation plan: UID000051 declares the catalog/item-state types, UID000050 declares the dialog at position `5`, UID000053 declares the list pane and direct dependencies at position `10`, and UID0000D9 supplies the inline SSO-buffer accessor. Exact typedef, local, access-specifier, category-list-state, final ImageLib/resource-layout alias, and capacity-constant spellings remain confidence caps. Current target metadata is validated at `90/91`.

## Evidence Standards Used

- Primary evidence: live IDA MCP exact function models, decompilation, disassembly, raw bytes, SHA-256, xrefs, literal pointer scans, caller/callee edges, strings, and adjacent boundaries.
- Secondary evidence: staged official JsonCpp source and headers, current by-* pages, generated source, generated tracker, manual coverage roots, validator cache only as evidence of current emitted text, and historical B-agent reports.
- Negative evidence: no VA/RVA pointer to target or retained constructor start, no xref to retained constructor, no whole-object zeroing, no failure delete/destructor, no source-level custom lookup wrapper call, no direct callee for any of the five former UID0002DN helper names, no ObjectStatusBlob `previewPartMode` field, and no original helper/type symbols.
- The evidence and completed callback justify `90/91`, but not `92/93`. Exact original typedef/local/capacity-constant spellings and the final ImageLib/resource-layout alias remain confidence caps.

## Evidence Checked

- IDA MCP/manual checks:
  - `lookup_funcs` for `0x00422ba0`, `0x00422e91`, `0x00422ec0`, `0x004219f0`, `0x00421a20`, and `0x00421a40`;
  - `decompile` for target `0x00422ba0`, caller `0x00422740`, catalog parser `0x00421a40`, list-pane reset/paint/input consumers `0x0041f100`/`0x0041f2b0`/`0x0041fcd0`, selected-entry reset `0x0041d5e0`, vector copy `0x00421290`, narrow-range-to-wide SSO helper `0x00423060` and its second caller `0x00581cf0`, node construction `0x00423000`, hash finalize `0x00423470`, container-bearing constructor `0x00422020`, item-state destructor `0x00422330`, selected-entry storage release `0x00423870`, bucket-vector resize `0x00423b00`, list clear `0x00423d70`, and byte-key lookup `0x00423e40`;
  - `disasm` for raw constructor `0x004219f0`;
  - `xrefs_to` for target, target end, switch table, raw constructor, raw end, and helper-family addresses;
  - `find_bytes` for target VA/RVA, switch-table VA/RVA, and raw-constructor VA/RVA;
  - `get_bytes` for target, adjacent bytes, raw constructor, and `0x0060d780`; the latter is four zero bytes followed by ASCII `"string too long"`, proving IDA `Locale` is shared empty/runtime storage rather than a source locale declaration.
  - current IDB session `9b0396a3` remained active and healthy during B004's report-only research; B004 requested and performed no IDA mutation. The supervisor later completed the accepted Gate 2B changes and independent readback recorded below.
  - current-session selected-entry proof: `0x0041f100` reads dialog `+0x744/+0x748` with `0xb4` stride; `0x0041f2b0` reads item-state `+0x240/+0x244` and compares entry `+0x00` plus `+0xa4`; `0x0041fcd0` builds/copies entry `+0x00`, `+0x04..+0xa3`, `+0xa4`, and vector `+0xa8/+0xac/+0xb0` into that same item-state vector; `0x0041d5e0`, `0x00422020`, `0x00422330`, and `0x00423870` clear/construct/destroy the identical `+0x240` vector. No second equipment vector or accessor-call route exists.
  - UID0002DN's current target body contains its exact-match erase, overlapping-part erase, append, local temporary teardown, and part-code switch inline. Its direct callees contain only the previously documented container/runtime/member support; there is no direct helper route for `ConstructSelectionEntry`, `RemoveSelectionEntry`, `RemoveEntriesWithOverlappingParts`, `DestroyTemporarySelectionEntry`, or `ApplyFittingRoomPartRecord`.
  - UID0002DN sign-extends the part byte, excludes `-1`, and dispatches numeric part codes `1,2,3,4,6,13,14,16,22,23,24,30,31,32,33`; exact writes map to current UID00009S fields, including `m_compositionMode` at ObjectStatusBlob `+0x22`.
  - UID0002DL multiplies grid rows by immediate `6`, wraps columns modulo six, and caps the visible loop at immediate `0x12`; these prove `kFittingRoomGridColumns = 6` and `kFittingRoomGridVisibleCells = 18`.
  - UID0002DL calls the proven `SimpleUString::Assign(const wchar_t*, unsigned int)` endpoint and then chooses inline versus heap storage by the SSO-7 capacity gate before `_wcstok`, supporting an inline `MutableData()` accessor on UID0000D9 rather than a family-wide SimpleUString rejection.
- Staged JsonCpp:
  - `json_value.cpp` SHA `F2C47295CC3FD59AA2D725074958E8F7A21EACB7E0A9889AB2B1B7DB7D11980E`;
  - `value.h` SHA `361960D4C8401FF995D3CA6F2DCAF912FBD1401D46413C04AAF2ABB2F0585274`;
  - `version.h` SHA `3D995A29400D0EF889026D279EBA66CA8172086709E4842F86D12F84A3717F1F`;
  - exact staged methods: `Value::size`, non-const and const `operator[](int)`, `Value::get`, and `Value::isNull`.
- Historical assignment-time ordinary-document checkpoint: every hash and every present-tense destination-state description in this entire indented block was captured before the implementation callback, before post-callback repairs, and before focused Gate 2A repairs. None is asserted as a current destination hash or current destination state.
  - target `0BC352A5504082E557EE04A2908D69274A65B61D235D82269DFBEF2988246F72`;
  - raw initializer `FDF63501DBAE2C64B401D0258848BD39D23140F6CB2A867DC3C0F9EE44452CC2`;
  - parser UID0002E4 `C6B5619B9AB751CBD6415D3D9DCFCB54D18B08BCC7B55D6580B3A2288EEDB4C4`;
  - part accessor UID0002E5 `9B56A16934663DD44954D54BECEED61D012F6FA1AA3A280FE2147E1049411A19`;
  - constructor UID0002E7 `9A91A3AF0109A52916BBA220879A28D7CC9A4B54814952603CF5BA97B3E42DFF`;
  - destructor UID0002EB `4798DAAA2F34A8B31992104C27DF46E6648B7667A7606F020EC3170CDDF2C9DC`;
  - reset UID0002EC `222E627D0C5DF91844C7E2CA24043F0F55256255A67B6250EDE1078EA96CDBCA`;
  - accessor range UID0000WV `20E58C225B79EB26042DEE22A1B403C109F3053257B9F6E636873D6AE1E90E92`;
  - class UID000051 `ADD6EBC9BB228DAA33A82C1A8C250AE8F1F994DA7198A084B003CDEAAA911917`;
  - file UID0000JE `0FB4E694BA6A62079403D2A7001227BA978BE95438B3EF1724EFFF3FBBC0F9DC`;
  - list-pane class UID000053 `4E8898647C2C46A0818C550C2DCE7C83A49078C2BA68B2825708D1B4458D2E2A`, 64,113 bytes/239 lines; its emitter position `10`, `m_selectedFittingItems`, `FittingRoomSelectionEntry`, and `partTypes` evidence support UID000051 position-0 shared declaration placement;
  - list reset UID0002DI `8784FC883BFDFC69AE5AB730B0778312715779BB110722B6D19299983DB480DE`, 17,974 bytes/149 lines; current formal flattens item-state vector storage onto `dialog->m_selectedFittingItems` and requires `itemState->m_selectedFittingItems` reconciliation;
  - list paint UID0002DL `4CBA59071CE97E2402BE7AAEE02A164C82A2FFDB1B986D3D859668D17F26C86C`, 28,050 bytes/317 lines; current formal already uses `itemState->m_selectedFittingItems`, `name`-compatible catalog fields, and `catalogIndex`;
  - list input UID0002DN `1642A41692D412E98079CE7AA937A61347294C3E56397B761A8577ABBC8F21DA`, 35,047 bytes/256 lines; current formal proves `name`/`catalogIndex` but incorrectly flattens the vector onto the dialog;
  - selected-entry reset UID0000WS `70F3DDA166842FA42EE61F5623B0D504CDA79E6C93D0D40C67737588C7876D04`, 17,183 bytes/185 lines; the source operation remains vector `clear()`, but the lifecycle-only `m_equipmentEntries` spelling must be replaced by `m_selectedFittingItems`;
  - selected-entry storage release UID0002UE `3805E5D79A6ED00029EADC6EE74262F655EDCDF00369E3851FA2F2DF1DBA366F`, 23,962 bytes/105 lines; retained covered-by/no-code evidence must use the same selected-entry member identity;
  - save helper UID0002EF `B82F9F83B0ADA26C96B049345E6F5BA8B6AF35F976335768C832D7B6BFEA196B`, 16,363 bytes/129 lines; its existing formal calls `strcpy_s`, proving `<string.h>` is a direct declaration dependency of the UID000051 header package;
  - dialog class UID000050 `6D7D3891674B9B724F07F2D055144D5ACE8E6DF5632EC87F07BF20D3872DCB0E`, 27,080 bytes/152 lines; its current formal is incomplete, and the exact replacement in this report supplies the complete `0x7ac` declaration at emitter position `5`, direct project-header routes, and narrow `friend class FittingRoomListPane;` before UID000053 position `10`;
  - ObjectStatusBlob class UID00009S supplies the exact 68-byte declaration and existing `m_compositionMode`/`m_posture` union at `+0x22`; FittingRoom dialog base appearance at `+0x47c` therefore maps dialog `+0x49e` to `m_baseAppearance.m_compositionMode` without an ObjectStatusBlob edit;
  - SimpleUString class UID0000D9 `1A5B079579C3981E55336D21DAC28077D84E56CEB67A2DC2C693E24A0BFA6458`, 31,529 bytes/179 lines, and StringUtil file UID0000OB `2856DCA8D1026CD8C3091C9F37EDEAF9CE093B97F7C173610C5CE084276B5736`, 65,440 bytes/266 lines; the complete replacement formal in this report preserves their current constructor/destructor/Clear/Assign/layout and adds only the inline evidence-backed `MutableData()` route required by UID0002DL;
  - project-header owner docs and declarations: UID0000IT `by-file/DialogPane.md` SHA `D584F93EE7238EC989EFE820DEBE2595DE76D132EC0DB680936CF77BEE1E0CBD` (28,345 bytes/163 lines) owns `NexusTK/ui/core/`, while UID00003T `by-class/DialogPane.md` SHA `7101A93A4EF53CFA1F11529AEF111AA94B13EBC76222ADE546D7B59D6D521DBE` (38,969/333) carries the complete declaration; UID0000M6 `by-file/ObjectStatusBlob.md` SHA `9D242B99758A2F339D3FC5E46D024528031E3A17C6EF04977DE1F3A0D6B3C3B4` (8,220/72) owns `NexusTK/map/`, while UID00009S `by-class/ObjectStatusBlob.md` SHA `B9A89DB15F633BB2F43C25F83680884135E9705905D24DCF18014EBCB23D3EC4` (13,323/191) carries the exact 68-byte declaration; UID0000I0 `by-file/CashShopRequest.md` SHA `C7CE3575B71B84303E3210E81DE5F6A84A328B1A13EA56D9006C4EE4FA2A0C56` (30,213/188) already documents `cashshop/CashShopRequest.h`, while UID00001H `by-class/CashShopRequest.md` SHA `E3B7ACE071474756FE766E5C008B32165D0DF80DCEF3397F9965434849F3E91F` (33,023/209) carries the declaration; UID0000IG `by-file/ControlPane.md` SHA `7746E55AB73563FE9ED9DBADB47476F016FFA69DCF8ABB78E6B91008DAA0C5D9` (25,222/139) owns `NexusTK/ui/core/`, while UID000038 `by-class/ControlPane.md` SHA `BAB29EA5E3DD9054110A96AB535A9D8CA1563F5681474EF47EA06AA8110B3F75` (33,683/230) carries the complete declaration;
  - direct Event/EPF/Region routes: UID00004L `by-class/Event.md` SHA `990F3E969A8A697868C29DE05FD57140502D78B1373C1F3BA0D9056BD2DFB97A` (23,566/318) and UID0000J6 `by-file/Event.md` SHA `032A30AEEE73730E6ED09515A8B60651C7E97491F07506F5510159B9E348E96C` (23,299/150); UID00004I `by-class/EPFTileContext.md` SHA `7EC740D8A5B1FBA0A74EF46A75FBD6B684408E3EC42A939E4A20ABE7D9347F28` (24,540/226) and UID0000J4 `by-file/EPFTileContext.md` SHA `7C8B6EC5EA9F62E7A1E05C500D17AAAE430FA0E6FA2EC392795E8AFE6F27147D` (18,298/172); UID0000BV `by-class/Region.md` SHA `450F72D3B2BAA9EC5849A53446D05A44D1CFE0BF22D9C039FC41916073A35F6E` (16,612/134) and UID0000N3 `by-file/Region.md` SHA `8BAFB4114E8D7CB1CFEED4E6DA0DEFA9EE4354FFD2FD0A5F843880566FE54CBF` (16,592/126);
  - direct image/global routes: UID00006E `by-class/ImageLib.md` SHA `DBBF3822D33BA02CB6C58B6964D4A940301265E54253FA23A71DD6DAD5F23F38` (18,794/140), UID0000K2 `by-file/ImageLib.md` SHA `DA57B255A4BB5E380C535FBEE0DA79C287C16BD7D44F4C7E773EC3AD4EF70918` (26,978/179), and UID0000QU `by-global/g_pEPFLib.md` SHA `F45C0FFE72AD6B69388817E05E677F8BAA00327A2C34090E2BFA0CB140A542F7` (13,482/123); UID0001UU `by-type/by-struct/ItemObjImageLibLayout.md` SHA `53691404E9E41257E62956B7E82DC59F987E31BAFD2C1A7ABE8A3F84C7BB40A2` (19,005/156) and UID0000KH `by-file/ItemObjImageLib.md` SHA `51B29C88CC7E8F3DC0696081CA5C3BCA5290BCFA3187BE7A7E3B67F411A5BC2A` (39,373/219);
  - direct user/access routes: UID00007B `by-class/LivingObjectPane.md` SHA `098D288A9C64DA19DC77C871F738247A473CD4D7A23D4B046B045DC7F669B30E` (130,776/672), UID0000KU `by-file/LivingObjectPane.md` SHA `C871439222FE9317DCD4BECA2F75E1781D711ABF83F7B5272EE07D659E456841` (121,239/440), UID0000FQ `by-class/UserPane.md` SHA `F14644F980487F915D6EB0AC5CD00D8BA5A0D42583EFACFD6F90BF148F692F4B` (97,693/719), and UID0000P1 `by-file/UserPane.md` SHA `4650C9DB50AAB98A97F39B0CC7B6F025F74F0278FF44293D8AE070E9B2442109` (111,943/457);
  - direct Surface/GrafPort/geometry routes: UID0000TN `by-global/SurfaceRenderCallbackTable.md` SHA `4D260C9144DA2880066BEAF14DB52486D12881F59272692DBB13D0C5A92EC92E` (63,421/338), UID0000OC `by-file/Surface.md` SHA `3FD6BB870F3259ED8149CDC43B7CD762A22904EE02C2D42247AF532481D3ED57` (110,848/467), UID00015S `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` SHA `94449DADA6F3BF1278A7581214ADAA3026C6D71C62AD494C54B48E132A9A40EE` (29,320/294), UID0000N2 `by-file/RectBounds.md` SHA `0BCD3DDB41C7991D24511BE87F6A81FFF9092E4C5BC741431D1491042BF42829` (27,908/146), UID00005V `by-class/GrafPort.md` SHA `F1AD63407DAD2CCE4891E755A9F6271F259D3BEB40E9780A74A250A52B16053C` (61,379/308), and UID0000JR `by-file/GrafPort.md` SHA `F1BC7F4AB313CA6CD07C66D75210C619BA9E382D4AF19ADE422EBE6DDD4F7E56` (56,202/278).
  - equipment support class UID00004Z `F8C12AE13348628FE4D1E594D855D574ACDF22A4E04A42D4F72CFE02BF2B6A2C`, 12,927 bytes/107 lines; this remains a historical support view and must not preserve a second `m_equipmentEntries` source member;
  - equipment layout UID0001UH `865322D5997C1F1D9507DF843B5FD03AB0F33B3C939509884D72EC2C4626879C`;
  - pre-callback raw parent artifact, now validator-allocated UID0004WL, `B4F611B64DB439C44A98FF1977889B7EA58D2A232E430BAF2821F879B4CC0FB5`;
  - pre-callback raw part-record predecessor artifact, now validator-allocated UID0004WJ, `6564D0B687F57A47637EF69BCB25001CA081BDD450C94D13FB142944D391D68C`;
  - U4 `2B3BFE39650BF39F78F7D269D3478DD6E52B7A9303B191A842511ACB59EF2F13`;
  - U8 `D820783CC9FF52DA3B3496CDBBF53C962EA1574AB0449B1BC836F159ECCC45EA`;
  - U9 `4C1AB7D090D5DE6E88519740E33EDD18B90E1FEAF209F64BFAE3F416C87FD052`;
  - UH `3F6FB39708A3396C6DF0D5E5A63FB7ECDA45ECAD48C313ACA25A8C9D2E569774`;
  - UI `00B611E845305B420910E2CE3D81B9DFE37F36AB5C9E00C0B78BE18C881AFD40`.
  - UB `79E38453DE48E1D24D08B6C020BEB87CCA2434FBAAAF27F02BC4C395D30CA2F7`;
  - shared UID0000WW `F895C8E219E8BE0BB3F924C3240C261C1EBEC2F15D2B7FCE289B118A55B4E3F7`.
- Assignment-time generated state, read-only and time-scoped (superseded by command16927 for FittingRoom.cpp):
  - `FittingRoom.cpp` command `000000016807`, refreshed `2026-07-23T04:53:01-04:00`, source `foreground-generated-refresh`, SHA `B0E6CEE6AB3AFF148AB981E93AEFF953151F740C15800131E703080BDEBEC813`, 89,333 bytes, 2,568 lines;
  - target UID occurs once; `LoadCategoryFromJson` occurs three times; target still emits the stale indexed-table/cleanup/custom-lookup body;
  - file contains two total `SimpleUString` occurrences: one valid UID0002DL `SimpleUString itemName` use and one unsupported UID0002E4 parser `SimpleUString wideName` use; `AssignAnsi` occurs once, `wideName.c_str()` occurs once, constructor `Locale` once, `previewPartMode` once, `m_compositionMode` zero times, 16 total empty-emitter markers, zero `sub_`, zero `dword_`, three `m_equipmentEntries` references, nine `m_selectedFittingItems` references, zero `displayName`, seven `catalogIndex`, one `g_pResourceMan`, one `g_pGlobalState`, one `EventType_LeftButtonRelease`, and one `EventType_MouseWheel`. These generated defects and contradictions are callback inputs, not evidence that the proposed declarations/formals have already been compiled.
  - `third_party/jsoncpp/JsonCpp.cpp` was checked at command16807, refreshed `2026-07-23T04:53:01-04:00`, source `foreground-generated-refresh`, SHA `91BCB344E1FBADECED49425B680880C27EF10A9FB81553CA13F5354CF6D41B85`, 1,489,625 bytes, 47,737 lines. Command16802/SHA `8A168AA065E9C55890560A63D4C729EAA3354616DEC521A817AFD7F1CC96FEBC`, command16789/SHA `E68CFA9EC3FE484E690D73BB6D9F4AA85A25DFF6985B6A3F19E52418906E41E5`, command16780/SHA `2FBF372C42A3A05FE925CF7D89F9A28E7917C978DC854B9D3F9D9E7038DC552A`, command16765/SHA `B5EC8AA5F1B73FB0F1AEA43063485ED6FCDBBEB28706B44CC999DCC140F71B17`, and the supervisor-supplied command16762/SHA `895EB09414CB520F84C3D90F92ED2AC82D26D01505796373299280A762714EDC` are historical foreground checkpoints. The imported official source supports the wrapper-to-API mapping used here and requires no product-code edit.
  - command16699 is the historical report-research generated checkpoint: `FittingRoom.cpp` SHA `FB86CE4488047FAD0BB5F008C2DD135BA6BBF405FACEEC5FCAE2559B4D260F53` and `JsonCpp.cpp` SHA `8691FC9D987B0842296D4D62C365767E00A0350A106772E2745DF5784369992F`; UID0002E6 semantics/counts remain unchanged, while later unrelated FittingRoom work and generated command/header/hash identity supersede its whole-file size/hash.
  - command16712 is the historical prior `FittingRoom.cpp` checkpoint at SHA `BA7C36BAF2DCEE4A48D408258A4E77113CB4F223582DAF3204FF16B71FD22C8D`, 84,722 bytes, 2,406 lines, with the same UID0002E6 and method counts.
  - command16715 is the historical prior `FittingRoom.cpp` checkpoint at SHA `F5B51D00C7A1543AC41D7AC2E0DCEDBDBC01F3D42BAD99209138A4275F01C0B7`, 89,288 bytes, 2,560 lines, with the same UID0002E6 and method counts.
  - command16717 is the historical prior `FittingRoom.cpp` checkpoint at SHA `3AF0C00E889F3DE70560B0568B9DA872DBCC41F21E3EADB1C6D7E599BE3B616A`, 89,491 bytes, 2,568 lines, with the same UID0002E6 and method counts.
  - command16718 (`FittingRoom.cpp` SHA `3BB80E82639B0D42FE20F8F97D4ACEDAF3F925F2059BA3DA66676361BB23042E`), the supervisor-observed command16722 checkpoint (`987A19...`), commands through16780, command16789/SHA `B56AD1C1A8052DDE7FBCC719FD606F9863300E521BC03FA9732462DD392A347D`, command16802/SHA `DF7AA2DA770BC50FC4175E3BCC248BE5E2874020492C217DFAE35438F3C2C639`, and command16807 are historical whole-file checkpoints. Accepted semantic command16927 readback supersedes them for the FittingRoom.cpp payload.
- Source declaration-route checks:
  - current UID0000D9 `by-class/SimpleUString.md` SHA `1A5B079579C3981E55336D21DAC28077D84E56CEB67A2DC2C693E24A0BFA6458` (31,529 bytes/179 lines) and UID0000OB `by-file/StringUtil.md` SHA `2856DCA8D1026CD8C3091C9F37EDEAF9CE093B97F7C173610C5CE084276B5736` (65,440/266) declare constructor, destructor, `Clear`, wide `Assign`, and exact SSO-7 union/length/capacity storage. They do not declare parser-only `AssignAnsi` or `c_str`; those are rejected, while the same layout directly supports the inline `MutableData()` used by UID0002DL.
  - `by-memory/0x0060d670-0x0060d794.MsvcRdataStartupTables.md` SHA `7994D00F52FD5CCBD28EFD17F374B022D189A90AF4CFD67AFA8FA2A7DD04EC05` (7,625/77) independently places `0x0060d780` in runtime rdata beside the `"string too long"` literal, consistent with the live empty-string byte proof;
  - standard `std::wstring` range construction supplies the observed SSO-7 narrow-iterator conversion through `<string>`;
  - `<windows.h>` supplies `MAX_PATH`, `S_OK`, `CreateDirectoryW`, `GetLastError`, and `ERROR_ALREADY_EXISTS`; `<shlobj.h>` supplies `SHGetFolderPathW` and `CSIDL_PERSONAL`;
  - `<stdio.h>`, `<stdlib.h>`, `<string.h>`, and `<wchar.h>` supply the direct CRT declarations used by UID0002E7 and existing UID0002EF; `<hash_map>`, `<string>`, `<utility>`, `<vector>`, and `"json/json.h"` supply every remaining external type/API in the UID000051 package;
  - documented source roots and complete class formals prove the declaration homes. UID0000I0 and UID0000OB already named `cashshop/CashShopRequest.h` and `util/StringUtil.h`; the callback added exact routes for `NexusTK/ui/core/DialogPane.h`, `NexusTK/map/ObjectStatusBlob.h`, and `NexusTK/ui/core/ControlPane.h`. The direct dependency matrix includes `NexusTK/ui/core/Event.h`, `NexusTK/ui/core/Region.h`, `NexusTK/render/EPFTileContext.h`, `NexusTK/render/ImageLib.h`, `NexusTK/render/ItemObjImageLib.h`, `NexusTK/render/Surface.h`, and `NexusTK/ui/panels/UserPane.h`.
  - no PCH, reverse-engineered import-slot name, or undeclared custom wrapper is required by the implemented blocks. UID000051/UID000050/UID000053/UID0000D9/UID0000BV/UID00006E/UID0001UU/UID00007B and their source roots now carry the accepted fields/methods/constants/accessors/source positions/friend access; command16927 verifies the generated routes.
- Validator workflow evidence:
  - `tools/validator_README.txt` lines 728-746: a Markdown file with no UID receives the next validator-owned UID, while a copied live UID produces `duplicate_path_conflict`;
  - `tools/validator_README.txt` lines 852-879: canonical temporary references use `[TMP:"by-memory/...md"]`; the validator allocates the target UID first and replaces TMP with a generated UID link;
  - `by-structure.md` lines 215-243 and 298-307: never guess UIDs, validate a new target before normal UID references or use TMP, then run scoped file validation.
- Negative/failed/skipped checks:
  - no MCP outage occurred;
  - one final `server_health` probe omitted the mandatory `database` argument and returned only the MCP argument error; the immediate corrected probe with `database=9b0396a3` returned `status:ok`, uptime 282,766.599 seconds, auto-analysis/Hex-Rays/strings ready, so no evidence call was lost;
  - no IDA mutation was requested or performed by B004 during report-only research; the later supervisor-owned Gate 2B mutation is recorded under the exact IDA heading;
  - no validator was permitted during the original report-only phase; scoped validators ran only after the accepted implementation callback;
  - no execute-report/lifecycle operation was probed.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-001 | 0002E6 | Exact range is `[0x00422ba0,0x00422e91)`, size `0x2f1`/753, SHA `A678...79E1`. | Certain | MCP lookup/get_bytes/hash. | Target metadata/status/bounds. | incorporate | implemented-verified |
| C2E6-002 | 0002E6 | Predecessor ends in `retn 8` plus CC padding; successor begins with 3-byte NOP then 11-entry table and next function at 0x422ec0. | Certain | MCP bytes/disasm/lookup. | Target boundary section. | incorporate | implemented-verified |
| C2E6-003 | 0002E6 | Switch accepts category values 0..10 and default returns false. | Certain | Target disassembly/decompile. | Target behavior/formal C++. | incorporate | implemented-verified |
| C2E6-004 | 0002E6 | Key order is main, usable_items, weapons, mounts, face, head, mantle, necklaces, coats, shoes, specialty_sets. | Certain | Eleven direct string refs. | Target behavior/formal C++. | incorporate | implemented-verified |
| C2E6-005 | 0002E6 | Keys are direct method-local case loads, not an indexed source table. | Strong | Switch instruction shape and no pointer-table load. | Target historicalization/formal. | reject-stale | implemented-verified |
| C2E6-006 | 0002E6 | Sole direct caller is 0x42287c in UID0002E9; caller loops categories 0..10. | Certain | MCP xrefs/decompile. | Target caller inventory. | incorporate | implemented-verified |
| C2E6-007 | 0002E6 | No target-start VA/RVA pointer pattern exists. | Strong | MCP find_bytes. | Target negative evidence. | incorporate | implemented-verified |
| C2E6-008 | 0002E6 | `root.get(categoryKey, Json::Value())` returns category value by value and destroys default temp. | Certain | Target calls plus staged JsonCpp. | Target JsonCpp/formal. | incorporate | implemented-verified |
| C2E6-009 | 0002E6 | Category local is mutable because the binary calls non-const `Value::operator[](int)`. | Certain | 0x427500 and staged source. | Target formal/historicalization. | reject-stale | implemented-verified |
| C2E6-010 | 0002E6 | Null/missing category returns false through `Value::isNull`. | Certain | 0x4269d0 and staged source. | Target behavior/formal. | incorporate | implemented-verified |
| C2E6-011 | 0002E6 | Loop bound is category value `size()` converted to signed int. | Strong | 0x426ea0 and compare. | Target behavior/formal. | incorporate | implemented-verified |
| C2E6-012 | 0002E6 | Each array element is indexed through non-const operator[]. | Certain | 0x427500. | Target JsonCpp/formal. | incorporate | implemented-verified |
| C2E6-013 | 0002E6 | Each item is copied into a local Json::Value and destroyed. | Certain | 0x425010/0x425200. | Target formal/historicalization. | reject-stale | implemented-verified |
| C2E6-014 | 0002E6 | Each entry allocation is exactly 0xc0 bytes. | Certain | operator new immediate. | Target layout/behavior. | incorporate | implemented-verified |
| C2E6-015 | 0002E6 | Pre-parse initialization is category +0 and zero vector triplet +b4/+b8/+bc only. | Certain | Target stores/raw constructor. | Target layout/formal. | incorporate | implemented-verified |
| C2E6-016 | 0002E6 | Whole-object memset is false and would change uninitialized/parser-owned state. | Certain | No memset; only four stores. | Target formal/history. | reject-invalid | implemented-verified |
| C2E6-017 | 0002E6 | Best human source is `new FittingRoomCatalogEntry(category)` with inlined constructor semantics. | Strong | Target store sequence plus raw retained constructor. | Target formal; parser/class support. | incorporate | implemented-verified |
| C2E6-018 | 0002E6 | Parser handoff is UID0002E4 `FittingRoomCatalogEntry::LoadFromJson(itemValue)`. | Certain | Direct call 0x421a40. | Target behavior/formal; UID0002E4 support. | incorporate | implemented-verified |
| C2E6-019 | 0002E6 | Local collection is `std::vector<FittingRoomCatalogEntry*>`. | Certain | 4-byte stride, three-pointer layout, pointer append/copy. | Target formal/class support. | incorporate | implemented-verified |
| C2E6-020 | 0002E6 | Accepted entries use normal `push_back`; 0x420de0 is shared vector grow lowering. | Strong | Direct append and grow call. | Target behavior/formal. | incorporate | implemented-verified |
| C2E6-021 | 0002E6 | Parse failure leaks failed/prior entry objects while vector/category/item temporaries clean their storage. | Certain | Exact failure branch/callee absence. | Target behavior/negative evidence/formal. | incorporate | implemented-verified |
| C2E6-022 | 0002E6 | Current delete and ReleaseCatalogEntryVector failure cleanup is behavior-divergent. | Certain | No calls on failure. | Target formal/history. | reject-invalid | implemented-verified |
| C2E6-023 | 0002E6 | Category insertion key is one unsigned byte. | Certain | Low-byte stack store/node key/hash. | Target formal/class support. | incorporate | implemented-verified |
| C2E6-024 | 0002E6 | Pending vector is copied into insertion pair via UID 0x421290 vector copy. | Certain | Direct call/decompile. | Target insertion notes. | incorporate | implemented-verified |
| C2E6-025 | 0002E6 | +0x220 object is MSVC hash-container layout backed by list and bucket vector. | Strong | Constructor/finalize/destructor layouts. | Target/class/file support. | incorporate | implemented-verified |
| C2E6-026 | 0002E6 | 0x423000 is compiler-generated list-node/value construction, not source `CreateFittingRoomCategoryLookupNode`. | Strong | Transfer/move body, allocator, STL diagnostics. | UID0002U4/class/file. | historicalize | implemented-verified |
| C2E6-027 | 0002E6 | 0x423470 is compiler-generated hash insert/finalize with one-byte FNV-1a, duplicate handling, bucket repair, and rehash. | Strong | Full decompile/callees/layout. | UID0002U8/class/file. | historicalize | implemented-verified |
| C2E6-028 | 0002E6 | U9/UH/UI/UB and 0WW are compiler/container lifecycle/template helpers, not hand-authored FittingRoom APIs. | Strong | Caller sets, layouts, standard diagnostics, shared callers. | Support pages/class/file. | historicalize | implemented-verified |
| C2E6-029 | 0002E6 | Source insertion is `.insert(std::make_pair(static_cast<unsigned char>(category), entries))`. | Strong | Pair/vector construction and insert lowering. | Target formal. | incorporate | implemented-verified |
| C2E6-030 | 0002E6 | Best historical container declaration is `stdext::hash_map<unsigned char, std::vector<FittingRoomCatalogEntry*> >` or project alias. | Medium-high | MSVC `_Hash` layout, FNV, source age. | Class/file type notes. | incorporate | implemented-verified |
| C2E6-031 | 0002E6 | Canonical owner remains UID000051. | Certain | Receiver/storage/caller/class context. | Target metadata. | already-present | implemented-verified |
| C2E6-032 | 0002E6 | Emitter remains UID000051 through UID0000JE. | Certain | Current source route/generated file. | Target metadata. | already-present | implemented-verified |
| C2E6-033 | 0002E6 | Source placement remains NexusTK/cashshop/FittingRoom.cpp. | Strong | Sole subsystem, class/file docs. | Target/class/file. | already-present | implemented-verified |
| C2E6-034 | 0002E6 | UID0002EH remains generated switch data and must not hand-emit. | Certain | Table data xref and boundaries. | Target/UID0002EH support. | already-present | implemented-verified |
| C2E6-035 | 0002E6 | Raw constructor exact body is `[0x4219f0,0x421a22)`, 50 bytes, SHA `FBC2...B91E`; existing path end is invalid. | Certain | MCP disasm/get_bytes/hash. | Raw constructor support page. | incorporate | implemented-verified |
| C2E6-036 | 0002E6 | Raw constructor page UID00042D is a collision with MapPane and must receive a valid allocated UID rather than linking MapPane. | Certain | Current page/registry/search state. | Raw page and target/class/file links. | reject-invalid | implemented-verified |
| C2E6-037 | 0002E6 | UID0002E7/UID0002EC/UID0000WV plus class/file docs must preserve prior custom-helper assumptions as historical and adopt standard-container construction, iteration, find, clear/rehash, and member vocabulary. | Strong | Fresh reanalysis vs current docs and 0x422020/0x423d70/0x423e40. | UID0002E7, UID0002EC, UID0000WV, UID000051, UID0000JE. | historicalize | implemented-verified |
| C2E6-038 | 0002E6 | Target formal replacement below is behavior-exact and human source-shaped. | Strong | Claims C2E6-003..029. | Target formal header. | incorporate | implemented-verified |
| C2E6-039 | 0002E6 | Target is validated at `90/91`; owner/emitter/reconstructable state remains unchanged after the full dependency callback, raw-page repair, ordinary validators, and generated readback. | Strong | Target behavior and declaration/API changes are applied and validated. | Target metadata/manual coverage. | incorporate | implemented-verified |
| C2E6-040 | 0002E6 | Manual coverage rows for every changed target/support page remain supervisor-owned and require no-loss replacements. | Certain | Current manual roots read directly. | Manual handoff section. | incorporate | implemented-verified |
| C2E6-041 | 000051 | UID000051 must emit the declaration package at position 0 with direct C++03, Win32, Shell, CRT, and JsonCpp headers, then close the class before namespace-scope `[[CHILDREN]]`; no PCH is assumed. | Strong | Current empty marker occurs after methods; every external symbol was mapped to a direct header. | UID000051 formal/metadata. | incorporate | implemented-verified |
| C2E6-042 | 000051 | `FittingRoomCatalogCategory` is a four-byte enum with exact values 0..10 in observed switch/string order and count 11. | Strong | Target switch and UID0002E9 caller loop. | UID000051 enum declaration. | incorporate | implemented-verified |
| C2E6-043 | 000051 | `FittingRoomCatalogPartRecord` is naturally aligned six-byte `{signed char part; unsigned short tile; unsigned char color; unsigned char gender;}` with compiler padding at byte +1, not a packed struct or a fake `reserved` source field. | Certain | Parser stores +0/+2/+4/+5, six-byte stride, no +1 access, and UID0002DN sign-extends part and excludes `-1`. | UID000051 record declaration. | incorporate | implemented-verified |
| C2E6-044 | 000051 | `FittingRoomCatalogEntry` is exactly 0xc0 with category +0, enabled +4, natural padding, tile +6, color +8, natural padding, `wchar_t name[0x55]` at +0xa, and `parts` +0xb4; `wcscpy_s` retains its observed 0x50 bound. | Strong | Parser/consumer offsets, allocation, exact vector offset, audited absence of an interior tail field. | UID000051 entry declaration. | incorporate | implemented-verified |
| C2E6-045 | 000051 | The category-taking constructor initializes only `category` and default-constructs `parts`; it must not initialize/zero the remaining POD fields. | Certain | Live inline stores and retained raw body. | UID000051 inline constructor/raw-page covered-by disposition. | incorporate | implemented-verified |
| C2E6-046 | 0002E5 | UID0002E5 is source-authored `GetPart(signed char) const` with upper-bound-only behavior; class provides inline `GetPartCount`. | Strong | Exact 0x3c body and two nonnegative callers. | UID0002E5 formal/prose/score. | incorporate | implemented-verified |
| C2E6-047 | 000051 | `FittingRoomCatalogEntryList` and `FittingRoomCategoryMap` are C++03 aliases over vector-of-pointers and `stdext::hash_map<unsigned char,...>`. | Strong | Exact MSVC `_Hash` layout/lowering and source era. | UID000051 alias declaration. | incorporate | implemented-verified |
| C2E6-048 | 0001UH | The exact 0xb4 element is `FittingRoomSelectionEntry`: category +0, `wchar_t name[0x50]` +4, signed `catalogIndex` +0xa4, natural alignment, and `std::vector<int> partTypes` +0xa8. Prior `displayName`/`itemIndex` are weaker report spellings superseded by current emitters. | Certain for layout, strong for lexical names | Live UID0002DL/UID0002DN consumers plus existing selection-entry/vector docs. | UID000051 declaration, UID0002DL/UID0002DN, and UID0001UH support. | historicalize | implemented-verified |
| C2E6-049 | 000051 | Item-state fields at +0/+0x18/+0x220/+0x240/+0x24c/+0x250/+0x268 produce exact 0x280 layout; +0x240 is the single `m_selectedFittingItems` vector and three bytes after `m_cacheLoaded` are natural alignment, not `m_reserved24D`. | Certain for offsets, strong for names | UID0002DI/UID0002DL/UID0002DN plus constructor/destructor/reset/storage-release evidence. | UID000051 class declaration and lifecycle support pages. | incorporate | implemented-verified |
| C2E6-050 | 0002E4 | Parser formal replaces unsupported parser-side `SimpleUString::AssignAnsi`/parser-side `SimpleUString::c_str` with `std::wstring` range construction and valid `std::wstring::c_str()`, copies each nested Json value, avoids value-initializing natural padding, and is validated at 90/91; this does not reject UID0002DL's valid paint-time SimpleUString use. | Strong | Live parser/helper decompilation, current UID0000D9 formal, C++03 string route. | UID0002E4 formal/prose/metadata. | reject-stale | implemented-verified |
| C2E6-051 | 0002E7 | Constructor formal uses `m_catalogVersion("")`, direct header-provided Win32/Shell/CRT APIs, and standard map/vector member construction; validated score is 90/91. | Strong | Exact constructor, `0x0060d780` bytes/xrefs, and declaration-route audit. | UID0002E7 formal/prose/metadata. | reject-stale | implemented-verified |
| C2E6-052 | 0002EC | Reset formal uses `FittingRoomCategoryMap` iteration/delete/clear/rehash; validated score is 91/92. | Strong | Exact reset lowering and declared alias. | UID0002EC formal/prose/metadata. | incorporate | implemented-verified |
| C2E6-053 | 0000WV | Accessors use `FittingRoomCategoryMap::iterator`, find/end, and copied vector; scoped validation retains 90/92 without unsupported promotion to 92/93. | Strong | Exact lookup/accessor lowering and declared alias. | UID0000WV formal/prose/metadata. | incorporate | implemented-verified |
| C2E6-054 | 0002E6 | The stale raw page was renamed to corrected `[0x004219f0,0x00421a22)`, lost only its invalid duplicate UID header, and received validator-owned UID0004WI through scoped validation. | Certain | Exact bytes, validator allocation rules, UID0004WI readback, and focused scoped validators command17002 for the separate fourteen-byte padding correction plus command17003 for the target copy. | Corrected raw page path/header/metadata and target C2E6-054 copy. | reject-invalid | implemented-verified |
| C2E6-055 | 0002E6 | Target-first missing-UID validation allocated UID0004WI; all five referring ordinary pages were serially edited/validated so TMP references became the canonical UID0004WI link. | Certain | Validator commands 16828/16838 and serial TMP/reference validation. | UID0004WJ/0004WL/0002E6/000051/0000JE; corrected raw page is the sixth changed ordinary file but does not self-reference. | incorporate | implemented-verified |
| C2E6-056 | 0002E6 | Manual rows for UID0002E5, UID0001UH, UID0004WJ, UID0004WL, and UID0004WI are terminalized with their validator-owned identities; all 43 exact manual coverage actions are present and supervisor-validated by commands16953 through16957. B004 supplied the handoffs and did not edit coverage reports. | Certain | Current manual roots, allocated UID readback, supervisor coverage commands16953/16954/16955/16956/16957, and callback actor boundary. | Manual handoff/checklist. | incorporate | implemented-verified |
| C2E6-057 | 0002E4 | Helper 0x00423060 is compiler/container range-construction lowering for the 24-byte SSO-7 wide temporary; the source expression is `std::wstring(itemName.begin(), itemName.end())`, not an invented project API. | Strong | Helper body, two callers, runtime diagnostics, and missing UID0000D9 methods. | UID0002E4 formal/history; UID000051 includes. | reject-stale | implemented-verified |
| C2E6-058 | 0002E7 | IDA `Locale` at 0x0060d780 is shared zero/empty runtime storage immediately before `"string too long"`; source uses `m_catalogVersion("")`. | Certain | Exact bytes, 38 data refs, constructor call. | UID0002E7 formal/history. | reject-stale | implemented-verified |
| C2E6-059 | 000051 | Direct includes `<windows.h>`, `<shlobj.h>`, `<stdio.h>`, `<stdlib.h>`, `<string.h>`, and `<wchar.h>` close Win32/Shell/CRT declarations used by UID0002E7 and existing UID0002EF, including `strcpy_s`. | Strong | API/header contract, exact constructor call inventory, and UID0002EF formal. | UID000051 formal/dependency notes. | incorporate | implemented-verified |
| C2E6-060 | 0001UH | `reservedState[0xa8]` and `vector<unsigned char> payload` are rejected; live selection insertion identifies every semantic field and a `vector<int>` payload. | Certain | UID000053 OnInputEvent construction and exact offsets/stride. | UID000051/UID0001UH history/formal. | reject-invalid | implemented-verified |
| C2E6-061 | 000051 | `reserved05`, `reserved09`, packed byte `reserved`, and `m_reserved24D` are natural compiler padding and must not appear as source members. | Certain | Exact field accesses and 32-bit alignment. | UID000051 formal/history. | reject-invalid | implemented-verified |
| C2E6-062 | 000051 | The best human declaration for the catalog name backing region is `wchar_t name[0x55]`; 0x50 remains the operational safe-copy bound, and no direct consumer identifies a separate +0xaa tail field. | Strong | Exact +0xa/+0xb4 span and complete target-family consumer audit. | UID000051/UID0002E4 layout notes. | incorporate | implemented-verified |
| C2E6-063 | 000051 | The callback maps every standard/platform/JsonCpp identifier in UID000051 and every direct project identifier used by UID000050/UID000053 to an evidence-backed declaration owner plus an explicit companion-header or already-complete readback destination, including Event, Region, EPFTileContext, ImageLib/resource lookup, ItemObjImageLib, Surface, UserPane, and geometry/GrafPort APIs; executable import-dispatch slots remain linker lowering. | Strong | Full identifier inventory, assignment-time owner-hash checkpoint, exact dependency formals, API-child evidence, source-root audit, and command16927 readback. | UID000051/UID000050/UID000053 formals plus all dependency owner/source-placement destinations. | incorporate | implemented-verified |
| C2E6-064 | 0002E6 | The expanded declaration/reconciliation route is implemented; command16927 replaces the stale command16807 aliases and verifies current declaration order/source vocabulary. | Certain | Exact declaration order/dependency formals, scoped validators, and final generated artifact. | Final recommendation/score/checklist. | incorporate | implemented-verified |
| C2E6-065 | 0002DN | UID0002DN proves `FittingRoomSelectionEntry::name` and `catalogIndex`; the implemented formal reconciles every former `dialog->m_selectedFittingItems` expression to the already-computed `itemState->m_selectedFittingItems` storage and standard-vector iterator syntax. | Certain for storage/fields, strong for source syntax | Live 0x0041fcd0 decompile stores +0/+4/+0xa4/+0xa8 and reads item-state +0x240; implemented formal and command16927 readback; focused destination-copy validators commands17004 and17006. | UID0002DN formal/prose and UID000053/UID0000JE support. | reject-stale | implemented-verified |
| C2E6-066 | 0002DL | UID0002DL already uses the correct item-state member route and compares `catalogIndex`; retain its body while adding the cross-page decision that `name`/`catalogIndex` supersede `displayName`/`itemIndex`. | Certain | Live 0x0041f2b0 decompile and current formal. | UID0002DL prose; UID000053/UID0000JE support. | already-present | implemented-verified |
| C2E6-067 | 0002DI | UID0002DI reads the same vector at dialog +0x744/+0x748 and must use a local item-state pointer plus `itemState->m_selectedFittingItems`, not a flattened dialog field. | Certain | Live 0x0041f100 decompile, 0xb4 stride, item-state base +0x504. | UID0002DI formal/prose and UID000053/UID0000JE support. | reject-stale | implemented-verified |
| C2E6-068 | 0000WS | UID0000WS clears the same selected-entry vector; retain `ResetEquipmentEntries()` as the observed command-role method name but change its body/prose from `m_equipmentEntries.clear()` to `m_selectedFittingItems.clear()`. | Certain for storage/body, strong for method/member spelling | Live 0x0041d5e0 decompile, sole OnCommand caller, shared +0x240 vector and 0xb4 stride. | UID0000WS formal/prose; UID000051/UID00004Z/UID0001UH/UID0000JE support. | historicalize | implemented-verified |
| C2E6-069 | 0002UE | UID0002UE remains covered-by/no-code vector-storage release evidence, but its covered source member is `m_selectedFittingItems`, not a second equipment-entry vector. | Certain | Live 0x00423870 decompile and item-state destructor call at 0x0042240a. | UID0002UE prose/formal comment; UID000051/UID0001UH/UID0000JE. | historicalize | implemented-verified |
| C2E6-070 | 000051 | The legal private access route is a narrow `friend class FittingRoomListPane;` inside UID000051; no accessor call is present and no public/raw-offset API should be invented. | Strong | Direct list-pane access to item-state +0x240 in UID0002DL/UID0002DN and no accessor call. | UID000051 formal/prose and UID000053 support. | incorporate | implemented-verified |
| C2E6-071 | 000050 | UID000050 now carries the exact position-5 `0x7ac` declaration from this report: direct project headers, complete method inventory, two 68-byte appearance blocks, embedded 0x280 item state, category/list fields, version string, request pointer, size guard, singleton declaration, and narrow `FittingRoomListPane` friendship before UID000053 position 10. | Strong | Exact base boundary and field offsets/sizes, constructor/sibling consumers, UID0002DI/UID0002DL/UID0002DN direct access, scoped validation, command16927 class/source ordering, and focused destination-copy validators commands17004/17006/17007/17008/17009. | UID000050 formal/prose/metadata, UID000053/UID0000JE source-order notes. | incorporate | implemented-verified |
| C2E6-072 | 000051 | Constructor/destructor/layout/support pages that call the +0x240 vector `m_equipmentEntries` must preserve their binary facts but historicalize that lifecycle-only name in favor of `m_selectedFittingItems`. | Certain for identity, strong for spelling | Same dialog-relative/item-state-relative storage across 0x0041f100/0x0041f2b0/0x0041fcd0/0x0041d5e0/0x00422020/0x00422330/0x00423870. | UID0002E7, UID0002EB, UID0000WS, UID0002UE, UID000051, UID00004Z, UID0001UH, UID0000JE. | historicalize | implemented-verified |
| C2E6-073 | 0002EF | `<string.h>` is mandatory in the direct UID000051 header set because existing UID0002EF emits `strcpy_s`; the prior include list is incomplete. | Certain | UID0002EF formal line 16 and CRT declaration contract. | UID000051 formal/dependency notes; UID0002EF already-present evidence. | incorporate | implemented-verified |
| C2E6-074 | 0002E6 | Generated/tracker evidence is time-scoped: FittingRoom.cpp command16807 and tracker command16821 are historical pre-callback checkpoints. The current semantic `FittingRoom.cpp` payload remains exactly the validator command16927 artifact, SHA256 `6642C30C5A2FA3B15EF25CA239552F6B7D539BB9528242C2EB65F212E7044A2D`; later Gate 2 scoped validators refresh only validator-owned header metadata, not that payload. Validator-owned tracker/lifecycle outputs remain authoritative when refreshed. | Certain | Historical generated/tracker headers, command16927 generated payload/hash/readback, and post-Gate 2 header-only reconstruction check. | Target/current state/evidence/validator/checklist. | incorporate | implemented-verified |
| C2E6-075 | 00009S | Dialog `+0x49e` is base appearance `+0x22`, the already-declared ObjectStatusBlob union member `m_compositionMode`/`m_posture`; fitting-room preview semantics use `m_compositionMode`, not invented `previewPartMode`. | Certain | UID000050 layout, UID00009S exact 68-byte formal, UID0002DI/UID0002DN offsets, NewHuman composition consumers. | UID0002DI/UID0002DN formals and FittingRoom/ObjectStatusBlob cross-reference prose; no UID00009S formal change. | reject-invalid | implemented-verified |
| C2E6-076 | 0002DN | Exact-match erase, overlapping-part erase, append, temporary destruction, and the part-record switch are inline target/container operations; the five former helper names have no direct callee route and must not be declared. | Certain for inline machine shape, strong for C++03 source shape | UID0002DN disassembly/callee set and compiler vector helper children. | UID0002DN complete formal/prose; UID000053/UID0000JE support. | reject-invalid | implemented-verified |
| C2E6-077 | 000053 | List-pane source constants are `kFittingRoomGridColumns = 6` and `kFittingRoomGridVisibleCells = 18`; UID000053 must declare them with its complete position-10 formal and include `ControlPane`/`StringUtil` header counterparts. | Certain for values, strong for lexical names/routes | UID0002DL immediates/loop, sibling grid-page evidence, documented ControlPane/StringUtil roots. | UID000053 formal/prose/metadata and UID0002DL/UID0002DN support. | incorporate | implemented-verified |
| C2E6-078 | 0000D9 | UID0002DL's SSO-7 `SimpleUString itemName` and wide `Assign` are valid; inline `MutableData()` selects heap storage when capacity exceeds seven and otherwise the inline buffer. Parser-only `AssignAnsi`/`c_str` remain rejected. | Strong | UID0002DL call/storage selection, UID0000D9 exact 24-byte layout and Assign endpoint. | UID0000D9 complete formal/prose/metadata; UID0000OB/UID0002DL support. | incorporate | implemented-verified |
| C2E6-079 | 000050 | The complete dialog formal uses `../ui/core/DialogPane.h`, `../map/ObjectStatusBlob.h`, and same-directory `CashShopRequest.h`; UID0000IT/UID0000M6 are explicit callback destinations for the first two companion-header paths, while UID0000I0 already documents the third. Current autogen is not misrepresented as having materialized them. | Strong | Current by-file/class source roots, exact complete class declaration owners, and UID0000I0 Proposed Placement. | UID000050 formal/dependency prose; UID0000IT/UID0000M6/UID0000I0 source-package support. | incorporate | implemented-verified |
| C2E6-080 | 0002DL | UID0002DL retains `SimpleUString` and exact text wrapping while consuming UID000053 grid constants and UID0000D9 `MutableData`; generated postcondition is zero unsupported parser facade, not zero SimpleUString. | Strong | Existing full paint formal and live generated/source evidence. | UID0002DL formal/prose/manual row/checklist. | incorporate | implemented-verified |
| C2E6-081 | 0002E6 | Current manual coverage roots contain all 43 no-loss actions, including UID0000D9/UID0000OB, three explicit companion-header routes, and ten direct-dependency destination rows; supervisor commands16953 through16957 independently validated every affected coverage family. | Certain | Current manual-root hashes/anchors and supervisor coverage validator results. | Exact Manual Supervisor-Owned Coverage Or Tracker Text. | incorporate | implemented-verified |
| C2E6-082 | 0002E6 | The repaired post-callback report contains ASCII only and exactly one lifecycle-appropriate `READY_FOR_SUPERVISOR_EXECUTE` marker; no Gate 1 marker or mojibake quote sequence remains. | Certain | Whole-report character/marker scan. | Report artifact/checklist. | reject-invalid | implemented-verified |
| C2E6-083 | 0000IT | `NexusTK/ui/core/DialogPane.h` is the exact companion-header destination for complete declaration UID00003T; UID0000IT currently records only the `.cpp` module and must add the header route for derived consumers such as FittingRoom. | Strong | UID0000IT source root, complete UID00003T formal, and FittingRoom inheritance dependency. | UID0000IT proposed-header/source-placement prose and manual by-file row. | incorporate | implemented-verified |
| C2E6-084 | 0000M6 | `NexusTK/map/ObjectStatusBlob.h` is the exact companion-header destination for complete declaration UID00009S; UID0000M6 currently records only the `.cpp` module and must add the header route for FittingRoom's two embedded values. | Strong | UID0000M6 source root, complete UID00009S formal, and exact FittingRoom ObjectStatusBlob members. | UID0000M6 proposed-header/source-placement prose and manual by-file row. | incorporate | implemented-verified |
| C2E6-085 | 0000I0 | `NexusTK/cashshop/CashShopRequest.h` is already explicitly documented by UID0000I0 and backed by complete UID00001H; FittingRoom's same-directory include consumes that route without another declaration. | Strong | UID0000I0 Proposed Placement and UID00001H complete formal. | UID000050 dependency evidence; no ordinary UID0000I0 change. | already-present | implemented-verified |
| C2E6-086 | 0000IG | `NexusTK/ui/core/ControlPane.h` is the exact companion-header destination for complete declaration UID000038; UID0000IG currently records only the `.cpp` module and must add the header route for FittingRoomListPane inheritance. | Strong | UID0000IG source root, complete UID000038 formal, and FittingRoomListPane inheritance dependency. | UID0000IG proposed-header/source-placement prose and manual by-file row. | incorporate | implemented-verified |
| C2E6-087 | 0000OB | `NexusTK/util/StringUtil.h` is already explicitly documented by UID0000OB and is the exact home for complete UID0000D9; FittingRoomListPane consumes that route without another header declaration. | Strong | UID0000OB Status/Proposed header and UID0000D9 formal. | UID000053/UID0000D9 dependency evidence; no duplicate ordinary header change. | already-present | implemented-verified |
| C2E6-088 | 00004L | UID0002DN must consume the complete Event declaration: `m_type`, `m_payload.m_pointer.m_y/m_x/m_detail`, `kEventLeftButtonUp`, and `kEventMouseWheel`; the emitted `event->type/x/y/wheelDelta` and `EventType_*` aliases are stale. | Certain | UID00004L complete formal and direct Event producer/consumer ABI. | UID0002DN formal; UID000053 include route; UID00004L/UID0000J6 cross-reference prose. | reject-stale | implemented-verified |
| C2E6-089 | 00004I | UID0002DL must use automatic `EPFTileContext`, `Initialize()`, and `bounds`; `EPFTileContext::Construct` and `.source` are stale aliases. | Certain | UID00004I complete formal and UID0002DL exact call/offset use. | UID0002DL formal; UID000053 include route; UID00004I/UID0000J4 support. | reject-stale | implemented-verified |
| C2E6-090 | 0000BV | `Region` is a complete `LObject`-derived 0x14-byte type with `RectBounds m_bounds`; automatic construction/destruction is source-real and static `Region::Construct/Destroy` is not. | Strong | Constructor/destructor/vtable/layout evidence and exact GrafPort clip callers. | UID0000BV complete formal; UID0000N3 header/source placement; UID0002DL. | reject-stale | implemented-verified |
| C2E6-091 | 00006E | `g_pResourceMan` is rejected. Storage 0x0067a744 is ImageLib-owned `g_pEPFLib`; the strongest complete source route is `ImageLib` with `typedef ImageLib ResourceLayoutTable`, exact non-virtual lookup methods, and one `extern ImageLib *g_pEPFLib`. | Strong | ImageLib RTTI/lifecycle, sole global writes/clears, shared +0xc List, and ResourceLayout method family. | UID00006E complete formal; UID0000K2/UID0000BY/UID0000QU support; UID0002DL. | reject-invalid | implemented-verified |
| C2E6-092 | 0001UU | UID0002DL's two draw calls use `g_pItemObjImageLib`, while `GetItemGlyphBounds` is a no-receiver file helper. The complete ItemObjImageLib declaration must preserve that distinction and the one extern global. | Certain | Direct UID0002DL callsite receiver setup and current ItemObjImageLib layout/draw evidence. | UID0001UU complete formal; UID0000KH header/source placement; UID0002DL. | reject-stale | implemented-verified |
| C2E6-093 | 00007B | `g_pGlobalState->fittingRoomInputLocked` is rejected. Storage 0x0067a748 is `UserPane *g_pUserPane`, and the byte tested at inherited +0x1d1 is `LivingObjectPane::m_nameVisible`; exact source is `!g_pUserPane->m_nameVisible`. | Certain for address/type/field, strong for lexical condition | UID0001OR/UID0000QK singleton evidence, UID0000FQ complete UserPane, UID00007B exact field layout, direct compare. | UID0002DN formal; UID00007B complete friend formal; UID0000KU/UID0000P1/UID0000QK support. | reject-invalid | implemented-verified |
| C2E6-094 | 00007B | `friend class FittingRoomListPane` is the narrow legal access route for inherited protected `m_nameVisible`; no getter, public field, duplicate global-state struct, or raw offset is supported. | Strong | Existing MapPane/Motion/BowGauge friend pattern and direct no-callee field read. | UID00007B complete formal; UID0000KU source/header prose. | incorporate | implemented-verified |
| C2E6-095 | 00005V | UID0002DL uses accepted GrafPort source APIs `GetClipRegion`, `SetClipRect`, `SetClipRegion`, `RenderTileFrame`, `SetTextColor`, `GetTextWidth`, inherited `m_visibleBounds`, and `m_drawMode`; stale Save/Restore/Intersect/SetBkColor/Measure aliases are rejected. | Certain | Exact child UIDs 0004LS/0004LT/0004LU/0004H6/000162/00016C and GrafPort layout. | UID0002DL formal; UID00005V/UID0000JR cross-reference prose. | reject-stale | implemented-verified |
| C2E6-096 | 00015S | UID0002DL/UID0002DN must use exact geometry contracts: `InitPointPair(Point *, y, x)`, `InitRectBounds(left, top, right, bottom)`, and `PointInRect(y, x, bounds)`. | Certain | UID00015S complete formal and Event point ABI. | UID0002DL/UID0002DN formals; UID0000N2 support. | reject-stale | implemented-verified |
| C2E6-097 | 0000TN | The UID0002DL highlight fill is the slot-7 Surface callback `g_pfnFillRect(this, &highlight)`, not an undeclared member `FillRect`. | Strong | Direct callback address/calling shape and UID0000TN formal. | UID0002DL formal; UID0000TN/UID0000OC support. | reject-stale | implemented-verified |
| C2E6-098 | 0002E4 | Generated postcondition must require zero parser-side `SimpleUString::AssignAnsi` and zero parser-side `SimpleUString::c_str` facade while explicitly allowing and requiring the proposed `std::wstring::c_str()` call. | Certain | UID0002E4 proposed standard string object and UID0000D9 API inventory. | Validator Results/checklist/generated readback. | incorporate | implemented-verified |
| C2E6-099 | 0002E6 | Callback validation supports the `90/91` target ceiling but not 92/93; lost lexical spellings remain explicit confidence caps. | Certain | Completed callback, scoped validators, and command16927 generated readback. | Final/score/confidence/checklist/manual target row. | reject-invalid | implemented-verified |
| C2E6-100 | 0002E6 | Command16807 FittingRoom output and tracker command16821 are historical pre-callback checkpoints. The current semantic `FittingRoom.cpp` payload is the validator command16927 artifact, SHA256 `6642C30C5A2FA3B15EF25CA239552F6B7D539BB9528242C2EB65F212E7044A2D`, 99,511 bytes and 2,818 lines; later scoped validators alter only the validator-owned command/timestamp/source header. Current lifecycle truth remains validator-owned. | Certain | Direct command16927 payload/hash/metrics readback, post-Gate 2 header-only reconstruction check, and timestamped historical checkpoint comparison. | Target/evidence/validator/changed-files/checklist. | incorporate | implemented-verified |

## Positive Evidence Summary

- The exact 753-byte body, caller, category switch, all eleven strings, JsonCpp calls, entry stores, vector operations, failure path, insertion pair, and hash-container helpers are directly observed.
- Staged JsonCpp source exactly explains the return-by-value `get`, mutable category value, non-const integer index, item copy, size, null test, and destructor calls.
- The raw retained constructor-shaped bytes independently corroborate constructor initialization of category plus the `parts` vector and disprove whole-object `memset`.
- The hash object and helper cluster match MSVC standard-container structure at every level: list sentinel/count, vector buckets, mask/count, FNV-1a hash, duplicate insertion result, load factor, rehash, list-node allocation, and compiler diagnostic.
- Class/file ownership is not heuristic-only: the sole caller, `this+0x220` receiver, and generated route all converge on `FittingRoomDialogItemState` in `FittingRoom.cpp`.
- Live parser/helper analysis identifies ordinary `std::wstring` range construction; current `SimpleUString` declarations independently prove the old facade was not a valid compile route.
- Exact rdata bytes resolve `Locale` to an empty C string, and direct header mapping resolves every Win32/Shell/CRT identifier without relying on a PCH.
- Live list-pane insertion resolves the full `0xb4` selection entry, while x86 alignment resolves every formerly named padding byte.

## IDA MCP Facts

- Function: `sub_422BA0`, start `0x00422ba0`, size `0x2f1`, 57 basic blocks, cyclomatic complexity 18, 289 instructions.
- Target byte SHA: `A67857467CC82D78BFFA6B42CCB93A2A484544E67706856F36A57357604E79E1`.
- Caller: one code xref at `0x0042287c` in `sub_422740`/UID0002E9.
- Target-start literal scans: zero VA `A0 2B 42 00`, zero RVA `A0 2B 02 00`.
- Switch table: one data xref from `0x00422bd7` to `0x00422e94`; exact table is 11 dwords through exclusive `0x00422ec0`.
- Category string xrefs:

| Category | String address | Target load |
| ---: | --- | --- |
| 0 | `0x0060df30` `main` | `0x00422bde` |
| 1 | `0x0060df38` `usable_items` | `0x00422be5` |
| 2 | `0x0060df48` `weapons` | `0x00422bec` |
| 3 | `0x0060df50` `mounts` | `0x00422bf3` |
| 4 | `0x0060df58` `face` | `0x00422bfa` |
| 5 | `0x0060df60` `head` | `0x00422c01` |
| 6 | `0x0060df68` `mantle` | `0x00422c08` |
| 7 | `0x0060df70` `necklaces` | `0x00422c0f` |
| 8 | `0x0060df7c` `coats` | `0x00422c16` |
| 9 | `0x0060df84` `shoes` | `0x00422c1d` |
| 10 | `0x0060df8c` `specialty_sets` | `0x00422c24` |

- JsonCpp calls: default `0x424d80`, get `0x4278e0`, destructor `0x425200`, isNull `0x4269d0`, size `0x426ea0`, non-const index `0x427500`, copy constructor `0x425010`.
- Entry path: `operator new(0xc0)` at `0x422cd2`; vector zeros at `0x422ce1/ceb/cf5`; category store `0x422cff`; parser `0x421a40` at `0x422d15`.
- Vector path: direct append `0x422d1f-0x422d24`; grow helper `0x420de0` at `0x422d31`; vector copy `0x421290` at `0x422d65`.
- Hash insertion: low-byte key `0x422d58`; node construction `0x423000` at `0x422d8b`; list count/link; hash finalize `0x423470` at `0x422dd3`.
- Hash support: `0x423d70` resets the sentinel/count and destroys every list node/vector payload; `0x423e40` applies the same one-byte FNV-1a hash and returns the sentinel on miss. These are standard-container clear/find lowering behind the stale custom `Clear`/`FindNode` source names.
- Failure path: item destruction, local vector buffer free if allocated, category destruction, false return; no entry delete/destructor.
- Raw constructor: no modeled function/xref/pointer hit; disassembly stores category and zeroes vector; exact `[0x4219f0,0x421a22)`, SHA `FBC2EE41D0B082CDCCFC0598B2586F6CFAA20CEA4A03B499AD9D28A2D50DB91E`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| class declaration | UID000051 | Enum/records/aliases/catalog entry/category constructor/selection entry/item-state declaration, narrow list-pane friend, and direct header dependencies including `<string.h>` | true | UID0000JE | 90/91 | Exact position-0 formal implemented; class closes before `[[CHILDREN]]`. |
| class declaration support | UID000050 | Complete position-5 `FittingRoomDialog` declaration, direct project headers, 0x7ac layout guard, and narrow list-pane friendship | true | UID0000JE | 87/89 -> 91/92 | Apply the exact complete managed formal; historicalize the prior incomplete-shell disposition. |
| class declaration support | UID000053 | Complete position-10 `FittingRoomListPane` declaration, ControlPane/StringUtil header routes, and exact row/grid constants | true | UID0000JE | 88/90 -> 91/92 | Apply the exact complete managed formal; declare columns 6 and visible cells 18 before child methods. |
| class declaration support | UID0000D9 | Complete SSO-7 `SimpleUString` declaration and inline writable-buffer selector | true | UID0000OB | 88/88 -> 89/90 | Apply exact formal with `MutableData()`; preserve parser-only `AssignAnsi`/`c_str` rejection and pointer-backed-family caveat. |
| `0x0041d5e0-0x0041d671` | UID0000WS | Selected-entry vector clear under existing reset role | true | UID000051 | retain 88/91 | Apply complete managed formal with `m_selectedFittingItems`; historicalize `m_equipmentEntries`. |
| `0x0041f100-0x0041f219` | UID0002DI | List reset and category-3 selected-entry scan | true | UID000053 | 88/91 -> 90/92 | Apply complete managed formal using local item-state pointer, legal C++03 iterator, and existing `m_baseAppearance.m_compositionMode`. |
| `0x0041f2b0-0x0041fb9b` | UID0002DL | Paint/highlight consumer of selected entries | true | UID000053 | 88/91 -> 90/92 | Apply the complete paint formal with legal C++03 iterator, declared grid constants, and valid `SimpleUString::MutableData`; preserve every paint operation. |
| `0x0041fcd0-0x004207ce` | UID0002DN | Input construction/removal/append of selected entries and appearance-part application | true | UID000053 | 90/91 | Complete Event/UserPane-aware formal uses inline C++03 vector operations and direct ObjectStatusBlob switch; five fabricated helper APIs and stale Event/global aliases are rejected. |
| `0x004219f0-0x00421a22` | UID0004WI at corrected raw path | Retained out-of-line constructor-shaped body | true, covered-by comment | UID000051 | 90/91 | Target-first allocation/TMP sequence completed; no independent call route and no UID00042D reuse. |
| `0x00421a40-0x00421fd8` | UID0002E4 | Entry JSON parser | true | UID000051 | 90/91 | Unsupported SimpleUString facade/value-initialized part replaced by exact standard-string/natural-layout formal. |
| `0x00421fe0-0x0042201c` | UID0002E5 | Signed part-record accessor | true | UID000051 | 90/91 | Exact upper-bound-only formal replaces the empty emitter. |
| `0x00422020-0x0042232a` | UID0002E7 | Item-state constructor | true | UID000051 | 90/91 | Uses empty literal instead of IDA Locale and direct Win32/Shell/CRT declarations. |
| `0x00422330-0x0042246f` | UID0002EB | Item-state destructor/member teardown | true | UID000051 | retain 87/90 | Preserve authored reset call and identify generated +0x240 teardown as `m_selectedFittingItems` lifecycle. |
| `0x00422470-0x0042259a` | UID0002EC | Category reset | true | UID000051 | 91/92 | Map iterator/delete/clear/rehash formal implemented. |
| `0x004225a0-0x0042268f` | UID0002EF | Encoded-state save method | true | UID000051 | retain 89/91 | Existing `strcpy_s` body is unchanged; it proves `<string.h>` must be in the shared declaration header set. |
| `0x00422690-0x0042273f` | UID0000WV | Count/index accessor pair | true | UID000051 | 90/92 | Map find/end/value access formal implemented without unsupported promotion. |
| `0x00422ba0-0x00422e91` | UID0002E6 | Category loader | true | UID000051 | 90/91 | Formal and stale prose replaced after complete callback validation. |
| class declaration support | UID0000BV | Complete automatic-lifetime `Region : LObject` declaration | true | UID0000N3 | keep 85/86 | Apply exact position-0 formal and `NexusTK/ui/core/Region.h` route. |
| class/global declaration support | UID00006E/UID0000QU | Complete ImageLib/resource-layout method surface, source typedef, and one `g_pEPFLib` extern | true | UID0000K2 | 89/90; global unchanged | Exact ImageLib formal and ResourceLayoutTable alias/facet/global caveat synchronized without a second object/global. |
| type/file declaration support | UID0001UU/UID0000KH | Complete ItemObjImageLib singleton plus file-local glyph-bounds helper | true | UID00006W | keep 92/94 | Replace only the stale member placement of `GetItemGlyphBounds`; preserve draw/global/layout facts. |
| access declaration support | UID00007B | Complete LivingObjectPane declaration plus narrow FittingRoomListPane friendship | true | UID0000KU | keep 92/93 | Add one forward declaration/friend; preserve the complete existing layout/formal. |
| already-complete dependency support | UID00004L/UID00004I/UID0000FQ/UID00015S/UID00005V/UID0000TN | Event, EPFTileContext, UserPane, geometry, GrafPort, and Surface callback declarations | true | existing owners | unchanged | Consume exact existing formals/APIs and add source-route/cross-reference prose only where absent. |
| `0x00422e91-0x00422ec0` | UID0002EH | NOP + switch table | false/generated | UID0002E6 context | current | Keep non-emitting generated-data disposition. |
| `0x00423000-0x0042305c` | UID0002U4 | MSVC list-node/value construction specialization | false/generated | semantic context UID000051 | 88/91 | Historicalize custom helper/source body; clear emitter/C++. |
| `0x00423470-0x0042365d` | UID0002U8 | MSVC hash insert/finalize specialization | false/generated | semantic context UID000051 | 88/90 | Historicalize custom helper/source body; clear emitter/C++. |
| `0x00423660-0x004236d7` | UID0002U9 | MSVC hash erase-node specialization | false/generated | semantic context UID000051 | 88/90 | Historicalize custom helper/source body; clear emitter/C++. |
| `0x00423710-0x00423777` | UID0002UB | MSVC hash-container destructor lowering | false/generated | semantic context UID000051 | 88/91 | Keep binary lifecycle evidence; clear source emitter. |
| `0x00423870-0x004238e3` | UID0002UE | Selected-entry vector-storage release lowering | true, covered by member lifecycle | UID000051 | retain 88/90 | Apply the complete managed covered-by formal and synchronize member identity to `m_selectedFittingItems`. |
| `0x00423a60-0x00423a8d` | UID0002UH | MSVC list-node allocator specialization | false/generated | semantic context UID000051 | 88/90 | Historicalize custom allocator C++. |
| `0x00423a90-0x00423af4` | UID0002UI | MSVC list-node/vector-payload destruction specialization | false/generated | semantic context UID000051 | 88/90 | Historicalize custom destroy C++. |
| `0x00423b00-0x00423c3d` | UID0000WW | Shared MSVC paired-iterator bucket-vector resize lowering | false/generated | shared compiler context | 85/current row | Historical DATIndexVector ownership is contradicted by 14 unrelated hash-container callers. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0042287c` | caller UID0002E9 -> UID0002E6 | Sole normal source call, once per category. |
| `0x00422bd7` | data xref -> `0x00422e94` | Compiler switch table. |
| `0x00422c46` | call `Json::Value::get` | Category object member lookup by value. |
| `0x00422cb6` | call non-const `Json::Value::operator[](int)` | Mutable category local requirement. |
| `0x00422cbf` | call Json::Value copy constructor | Item local is copied, not referenced. |
| `0x00422d15` | call UID0002E4 | Entry parser handoff. |
| `0x00422d31` | call shared vector grow | `entries.push_back(entry)` slow path. |
| `0x00422d65` | call vector copy constructor | Value copy into insertion pair. |
| `0x00422d8b` | call 0x423000 | Compiler list-node/value construction. |
| `0x00422dd3` | call 0x423470 | Compiler hash insertion/finalization. |
| `0x004219f0` | zero xrefs | Retained constructor-shaped body, not a live separate source call. |
| `0x00423a60` | callers constructor and node insertion | Shared list-node allocation within the same container specialization. |
| `0x00423b00` | fourteen callers across unrelated systems | Shared compiler vector/bucket lowering, not DATIndexVector source ownership. |
| `0x00423060` | callers UID0002E4 and `0x00581cf0` | Compiler/container narrow-iterator to SSO-7 wide-string range construction; source is `std::wstring` range construction. |
| `0x0060d780` | 38 data refs; exact zero bytes before `"string too long"` | Shared empty/runtime storage behind IDA label `Locale`; source constructor argument is `""`. |
| `0x0041f100` | UID0002DI reads dialog +0x744/+0x748 with 0xb4 stride | Proves dialog-relative selected-entry storage is item-state-relative +0x240/+0x244, not a second dialog member. |
| `0x0041f2b0` | UID0002DL reads item-state +0x240/+0x244 and compares entry +0/+0xa4 | Proves current `m_selectedFittingItems` and `catalogIndex` consumer route. |
| `0x0041fcd0` | UID0002DN constructs and inserts 0xb4 record into item-state +0x240 | Proves `FittingRoomSelectionEntry` category/name/catalogIndex/vector<int> fields and natural alignment. |
| `0x0041d5e0` | sole OnCommand caller; clears this[144..145] with 0xb4 stride | Same selected-entry vector lifecycle; historical `m_equipmentEntries` is not separate storage. |
| `0x00422020` / `0x00422330` / `0x00423870` | construct/destroy item-state +0x240 vector | Confirms one member across UI use and lifecycle use. |

## Documentation Evidence And IDA Status

- Supporting current docs:
  - UID000051 and UID0000JE correctly own the item-state/FittingRoom route.
  - UID0002E4 correctly models the 0xc0 entry parser.
  - UID0002DL already establishes the strongest selected-entry spellings `name`/`catalogIndex` and the correct `itemState->m_selectedFittingItems` storage route.
  - UID0002EF already emits `strcpy_s`, establishing the missing direct `<string.h>` dependency without requiring a body change.
  - UID0002EH correctly keeps dispatch data non-source.
  - UID0000KI correctly identifies the JsonCpp snapshot.
- Stale/contradicted docs:
  - UID0002E6 indexed key table, const/reference JsonCpp values, whole-object memset, cleanup, and custom Insert.
  - UID000051 empty emitter after child definitions, undefined catalog enum/entry/part/map/equipment/item-state declarations, and no category-taking constructor declaration.
  - UID0002E5 empty emitter despite a now-resolved naturally aligned six-byte record and signed-index body;
  - UID0002E4 generated use of undeclared `SimpleUString::AssignAnsi`/`c_str`;
  - UID0002E7 generated use of IDA label `Locale`;
  - prior proposed fake padding/opaque members that direct alignment and selection-insertion evidence now reject.
  - UID0000WS/UID0002E7/UID0002EB/UID0002UE/UID000051/UID00004Z/UID0001UH/UID0000JE lifecycle-only `m_equipmentEntries` wording for the same storage now proved as `m_selectedFittingItems`.
  - UID0002DI and UID0002DN flattening that item-state vector onto `FittingRoomDialog`; UID0002DL and live relative offsets disprove the flattened route.
  - pointer-typed `std::vector::begin()` loops in current UID0002DI/UID0002DL/UID0002DN formals; C++03 iterator declarations are required.
  - UID0002DI/UID0002DN use of undeclared appearance names rather than existing `ObjectStatusBlob::m_compositionMode`.
  - UID0002DN calls to five report-only helper facades despite the target body containing the vector and part-switch operations inline.
  - UID000053 omission of grid columns `6`, visible cells `18`, and direct ControlPane/StringUtil header counterparts.
  - UID0000D9 omission of the inline writable SSO-7 buffer selector used by UID0002DL.
  - historical pre-callback UID000050/UID000051 omission of the narrow friend route needed by observed direct `FittingRoomListPane` field access; the accepted callback installed the exact replacements for both declarations.
  - UID000051 direct-header list omission of `<string.h>` despite existing UID0002EF `strcpy_s`.
  - UID000051/UID0000JE custom category-node/finalizer APIs.
  - UID0002U4/U8/U9/UH/UI emitted custom helper bodies.
  - UID0000WW DATIndexVector source ownership despite unrelated shared callers.
  - raw initializer path's duplicate UID and truncated range.
- Historical pre-callback generated `FittingRoom.cpp` command16807 reproduced the then-current ordinary documentation rather than the repaired report: it captured the indexed-table/cleanup/custom-lookup, unsupported parser facade, IDA `Locale`, empty-emitter, missing grid/accessor declarations, stale render/Event/global aliases, fabricated UID0002DN helpers, and appearance-field contradiction before implementation. Command16802 and earlier listed generated checkpoints are also historical. Command16927 remains the accepted semantic FittingRoom.cpp payload checkpoint, while command17009 is the current physical validator-header checkpoint; `JsonCpp.cpp` command16807 remains dependency evidence rather than product-code validation.
- Assignment-time deferred tracker command16821 superseded tracker command16819 and earlier snapshots while showing UID0002E6 at row 1674, `87/89`, reconstructable true, and zero reports. That row is a timestamped historical queue checkpoint. FittingRoom.cpp command16927 is the accepted semantic generated checkpoint; later Gate 2 validators changed only validator-owned header metadata. Lifecycle counts remain validator-owned.
- At the pre-callback boundary, manual coverage was stale in score and source-quality wording for the target and several support pages. The exact no-loss actions remain recorded below, and all 43 are now present and supervisor-validated by commands16953 through16957; B004 did not edit coverage reports.

## Ranked Ownership Analysis

### 1. FittingRoomDialogItemState in FittingRoom.cpp

- Evidence for: sole caller UID0002E9, `this+0x220` storage, class constructor/destructor/reset/accessors, category strings, parser, and current generated route.
- Evidence against: none material.
- Decision: retain canonical owner/emitter UID000051 and file UID0000JE.

### 2. JsonCpp

- Evidence for: target consumes Json::Value APIs.
- Evidence against: product-owned switch, entry allocation/parser, vector, and category storage surround those calls; JsonCpp owns only callee implementations.
- Decision: dependency only, not owner.

### 3. ItemCatalog or custom FittingRoomCategoryLookup module

- Evidence for: historical generated/source-facing vocabulary.
- Evidence against: receiver is embedded item state, no separate object lifetime, and low-level "custom" methods match compiler STL internals.
- Decision: reject as canonical owner and reject standalone custom lookup source.

### Proposed new file/grouping, if applicable

- No new source file. Keep `NexusTK/cashshop/FittingRoom.cpp`.
- A project alias for the category map may live in the FittingRoom class/header declaration, but that declaration is support synchronization rather than a new source module.

## Source Placement

- Recommended placement: `FittingRoomDialogItemState::LoadCategoryFromJson` in `NexusTK/cashshop/FittingRoom.cpp`.
- UID000051 is the declaration owner and must emit at position `0` before by-memory child definitions. Its formal contains direct dependency headers, category enum/constants, naturally aligned part record, catalog entry/category constructor, entry-list/map aliases, exact selection entry, complete item-state declaration without fake padding members, and namespace-scope `[[CHILDREN]]` after the closed class.
- UID000050 must emit its complete `FittingRoomDialog` declaration at position `5`, after the UID000051 item-state types and before UID000053 position `10`. Its exact formal includes direct project headers, complete dialog methods/fields, the `0x7ac` size guard, singleton declaration, and narrow list-pane friendship. This ordering makes every type and private-access route used by UID0002DI/UID0002DL/UID0002DN visible before their full destination formals.
- UID0002E5 remains a method child after UID0002E4; the raw constructor page is covered by the UID000051 inline constructor and emits only a covered-by comment after validator allocation.
- The category enum and map typedef belong in FittingRoom class/header declaration context, not in a separate runtime helper source.
- The eleven JSON literals belong in this method's switch because the machine code loads each literal directly in a case block.
- Rejected placements: JsonCpp, ItemCatalog.cpp, generic VectorHelpers, DATIndexVector, mixed aggregate UID0002EE, and standalone CategoryLookup.cpp.

## Range / Split / Padding / Reclassification Analysis

- Target exact range remains `[0x00422ba0,0x00422e91)`.
- `0x00422e91-0x00422e94` is a 3-byte NOP; `0x00422e94-0x00422ec0` is the 11-dword switch table. Keep both in UID0002EH, not target formal C++.
- Raw constructor exact source-shaped body is `[0x004219f0,0x00421a22)`. The existing filename ending at `0x00421a20` cuts through `retn 4`.
- Corrected raw page is followed by alignment `[0x00421a22,0x00421a30)`; a separate vector-destruction thunk begins there, then alignment precedes parser UID0002E4 at `0x00421a40`.
- UID0004WJ, UID0004WL, UID0002E6, UID000051, and UID0000JE are the five allocated/current referring pages whose TMP links were replaced and validated as UID0004WI. Corrected raw page UID0004WI was the sixth ordinary file in the completed rename/allocation batch and does not self-reference.
- U4/U8/U9/UB/UH/UI are exact binary ranges but should be reclassified as compiler-generated specialization bodies, preserving documentation while clearing direct source emission.
- UID0000WW is shared compiler vector machinery and should not remain owned/emitted as a DATIndexVector method.

## Negative Evidence Summary

- No target-start pointer/data registration route exists beyond the ordinary direct caller.
- No raw-constructor xref or pointer route exists.
- No indexed category-key pointer-table load exists.
- No const Json index call exists in the target.
- No item-reference-only path exists; copy constructor/destructor are explicit.
- No whole-entry memset exists.
- No failed-entry destructor, operator delete, or pointer-vector element cleanup exists.
- No standalone custom lookup wrapper call exists.
- No original symbols/UDTs support the custom helper names currently emitted.
- No evidence supports DATIndexVector ownership for the shared bucket-vector resize helper.
- No declared `SimpleUString::AssignAnsi` or `SimpleUString::c_str` exists in the current source route.
- No source `Locale` object is supported; the exact referenced storage begins with a zero byte.
- No code reads or writes part-record byte `+1`, catalog-entry alignment bytes `+5/+9`, item-state bytes `+0x24d..+0x24f`, or an independent catalog field in `+0xaa..+0xb3`.
- No evidence supports an opaque `reservedState` prefix or byte-vector payload after the live selection insertion identifies all fields and `vector<int>`.

## IDA Rename / Type / Comment Recommendations

- Supervisor action classification: `APPLIED_VERIFIED`; detailed catalog record `0302` is in `tools/leaser/Agents/ida-recommendation-implementation-catalog.md`.
- Exact entity and pre-state: `0x00422ba0` was a generic/raw function identity for the complete category-loader body. Related list/hash/vector specialization ranges still carried compiler-generated `sub_*` identities, and the item-state/category/entry layouts were not represented with the report's recovered semantic types.
- Applied method identity/type:
  - renamed `0x00422ba0` to `FittingRoomDialogItemState__LoadCategoryFromJson`;
  - applied an exact `bool __thiscall` method prototype with `FittingRoomDialogItemState *this`, `const JsonValue *root`, and `FittingRoomCatalogCategory category`.
- Applied semantic types/layouts:
  - `FittingRoomCatalogCategory` for the category domain;
  - naturally aligned `FittingRoomCatalogPartRecord`, size `0x6`, without a fabricated source padding member;
  - `FittingRoomCatalogEntry`, size `0xc0`;
  - `FittingRoomSelectionEntry`, size `0xb4`;
  - `FittingRoomDialogItemState`, size `0x280`, including the recovered live members at `+0x220`, `+0x240`, and `+0x24c`.
- Applied safe local names where the decompiler variables had unambiguous roles: `categoryKey`, `categoryValue`, `itemValue`, `entries`, `itemCount`, `index`, and `entry`.
- Intentionally preserved compiler-generated identities: the analyzed MSVC hash/list/vector specialization ranges remain `sub_*` with classification comments. The supervisor rejected fabricated project symbols such as `CreateFittingRoomCategoryLookupNode`, `FinalizeInsert`, `EraseNode`, `AllocateFittingRoomCategoryNode`, `DestroyFittingRoomCategoryNode`, and `DATIndexVectorResizeAndFill`. `Locale`, `reservedAA`, `reservedState`, `m_reserved24D`, and packed `reserved` remain rejected source labels.
- Safety constraints: do not convert the compiler-specialization bodies into project helpers; do not invent a second selected-entry vector; do not change exact structure sizes/offsets; preserve naturally aligned source shape, malformed-input leak behavior, signed category/part semantics, and the observed JsonCpp/container calls.
- Post-state/readback: clean-restart MCP session `ced65025` reports `FittingRoomDialogItemState__LoadCategoryFromJson` at `0x00422ba0` with the applied method signature, semantic UDTs/layouts, safe local names, and compiler-helper comments. The raw specialization identities remain intentionally unchanged. The supervisor saved the IDB and verified database SHA-256 `0C2F8BDA0866B42EA14EB3E89088013FA6E73BAE7D470D8691E3795F7C0EC53A`.

## First-Draft C++ Recommendation

Implementation status: all 20 complete managed formals in this section were applied exactly and verified against their destination blocks before final command16927 readback. The repeated word "proposed" is preserved as report provenance for the pre-callback design, not as a current pending state.

- Draft C++ implementation status: complete; owner/emitter route, exact behavior, boundaries, and direct declaration/header plan are resolved and command16927 generated readback confirms the textual package.
- Required source order:
  1. UID000051 at emitter position `0` supplies direct C++03/Win32/Shell/CRT/JsonCpp headers, enum/constants, naturally aligned part record, catalog entry and inline category constructor, vector/map aliases, exact selection-entry layout, complete item-state class declaration, and then closes the class before namespace-scope `[[CHILDREN]]`.
  2. UID000050 at emitter position `5` supplies the complete dialog declaration and narrow friendship; UID000053 remains at position `10`, so the list class and its by-memory methods see the item-state, dialog, selection-entry, and access declarations in dependency order.
  3. Existing and repaired by-memory children emit method definitions in address/emitter order. UID0000WS/UID0002DI/UID0002DL/UID0002DN/UID0002UE use the complete exact formals below; UID0002E4 parses an entry with `std::wstring` range construction, UID0002E5 emits the part accessor, UID0002E7 constructs the item state with an ordinary empty string, UID0002EC resets the map, UID0000WV emits accessors, and UID0002E6 emits the repaired category loader.
  4. Compiler-generated container-specialization pages remain non-emitting evidence. The corrected raw constructor page carries only a formal covered-by comment after validator UID allocation; the source constructor is the inline UID000051 declaration.
- Exact proposed UID000051 compile-visible declaration formal:

```text
*** UID:000051 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <hash_map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <utility>
#include <vector>
#include <wchar.h>
#include <windows.h>
#include <shlobj.h>
#include "json/json.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../render/ItemObjImageLib.h"
#include "../render/Surface.h"
#include "../ui/core/Event.h"
#include "../ui/core/Region.h"
#include "../ui/panels/UserPane.h"

enum FittingRoomCatalogCategory
{
    kFittingRoomCategoryMain = 0,
    kFittingRoomCategoryUsableItems = 1,
    kFittingRoomCategoryWeapons = 2,
    kFittingRoomCategoryMounts = 3,
    kFittingRoomCategoryFace = 4,
    kFittingRoomCategoryHead = 5,
    kFittingRoomCategoryMantle = 6,
    kFittingRoomCategoryNecklaces = 7,
    kFittingRoomCategoryCoats = 8,
    kFittingRoomCategoryShoes = 9,
    kFittingRoomCategorySpecialtySets = 10,
    kFittingRoomCategoryCount = 11
};

struct FittingRoomCatalogPartRecord
{
    signed char part;
    unsigned short tile;
    unsigned char color;
    unsigned char gender;
};

struct FittingRoomCatalogEntry
{
    explicit FittingRoomCatalogEntry(FittingRoomCatalogCategory categoryValue)
        : category(categoryValue),
          parts()
    {
    }

    bool LoadFromJson(const Json::Value& value);
    int GetPartCount() const
    {
        return static_cast<int>(parts.size());
    }
    const FittingRoomCatalogPartRecord* GetPart(signed char partIndex) const;

    FittingRoomCatalogCategory category;
    bool enabled;
    short tile;
    unsigned char color;
    wchar_t name[0x55];
    std::vector<FittingRoomCatalogPartRecord> parts;
};

typedef std::vector<FittingRoomCatalogEntry*> FittingRoomCatalogEntryList;
typedef stdext::hash_map<unsigned char, FittingRoomCatalogEntryList>
    FittingRoomCategoryMap;

class FittingRoomListPane;

struct FittingRoomSelectionEntry
{
    FittingRoomCatalogCategory category;
    wchar_t name[0x50];
    short catalogIndex;
    std::vector<int> partTypes;
};

class FittingRoomDialogItemState
{
    friend class FittingRoomListPane;

public:
    FittingRoomDialogItemState();
    ~FittingRoomDialogItemState();

    void ResetEquipmentEntries();
    void ResetCategoryEntryLists();
    void SaveEncodedStateBuffer(std::string source);
    short GetItemCount(unsigned char category);
    FittingRoomCatalogEntry* GetItemByIndex(
        unsigned char category,
        short itemIndex);
    bool LoadEncodedStateBuffer(std::string source);

private:
    void LoadEncodedCacheFile();
    void TransformPersistedBuffer(char* buffer, int byteCount);
    bool LoadCategoryFromJson(
        const Json::Value& root,
        FittingRoomCatalogCategory category);
    void LoadItemShopTestJson();

    std::string m_catalogVersion;
    wchar_t m_cacheFilePath[260];
    FittingRoomCategoryMap m_categoryLookup;
    std::vector<FittingRoomSelectionEntry> m_selectedFittingItems;
    bool m_cacheLoaded;
    std::string m_encodeKey;
    std::string m_decodeKey;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Declaration proof and score effect:
  - enum storage/order follows direct four-byte stores and exact `0..10` switch/caller loop; lexical `kFittingRoomCategory*` names are inferred from the eleven literal meanings and existing project convention;
  - default x86 alignment places the part-record word at `+2` and yields exact stride six without `#pragma pack` or a fake byte member;
  - the catalog entry offsets total exactly `0xc0`; `name[0x55]` spans the exact region from `+0x0a` to the `parts` vector at `+0xb4`, while UID0002E4 preserves the observed 0x50 copy bound; the inline constructor intentionally omits scalar/name initialization and constructs only `category` plus `parts`;
  - `FittingRoomCategoryMap` is the strongest Visual C++ 2005-era source declaration for the observed `_Hash` implementation; a project typedef with identical underlying type remains historically possible, but this declaration is compile-visible and source-quality;
  - live list-pane paint and input consumers prove `FittingRoomSelectionEntry` fields at `+0/+4/+0xa4/+0xa8`, natural alignment at `+0xa6`, `vector<int>` payload, exact size `0xb4`, and the established source spellings `name` and `catalogIndex`; no opaque byte array or competing `displayName`/`itemIndex` record remains;
  - the item-state fields produce exact offsets `+0x00/+0x18/+0x220/+0x240/+0x24c/+0x250/+0x268` and total `0x280`; the three bytes after `m_cacheLoaded` are natural alignment, not a source field;
  - the same item-state `+0x240` vector is reached by reset, paint, input, constructor, destructor, and release paths; `m_selectedFittingItems` is the strongest current source name and the older lifecycle-only `m_equipmentEntries` spelling is historicalized;
  - `FittingRoomListPane` is granted narrow friendship by both `FittingRoomDialogItemState` and the complete UID000050 `FittingRoomDialog` declaration, matching the observed private item-state/vector/category/appearance reads without inventing an accessor or raw-offset API;
  - direct headers supply the standard, Win32, Shell, CRT, and JsonCpp identifiers used by this package, including `<string.h>` for existing `strcpy_s`; documented source roots supply the project counterparts `../ui/core/DialogPane.h`, `../map/ObjectStatusBlob.h`, same-directory `CashShopRequest.h`, `../ui/core/ControlPane.h`, and `../util/StringUtil.h`. This removes the package-level header omission. At the pre-callback report boundary, no proposed block had yet been compiled or validator-applied. Current post-callback truth is that all 20 managed formal blocks were applied, scoped-validated, and textually generated by validator command16927; no full product compile is claimed;
  - UID000051 emitter position `0` precedes existing UID000053 position `10`, making the shared `FittingRoomSelectionEntry` declaration visible to list-pane definitions as well as item-state children;
  - UID000051 validated at `90/91`, emitter position `0`, and is no longer an empty emitter. No `92/93` readiness is claimed.

- Exact proposed UID000053 list-pane declaration formal. It preserves the current complete `0x12c` declaration, adds only the documented project header routes and the two constants directly proved by UID0002DL, and retains the previously established row/grid/scroll constants in the same source-level scope:

```text
*** UID:000053 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/ControlPane.h"
#include "../ui/core/Event.h"
#include "../ui/core/Region.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../render/ItemObjImageLib.h"
#include "../render/Surface.h"
#include "../ui/panels/UserPane.h"
#include "../util/StringUtil.h"

class FittingRoomScrollPane;
class Layer;
struct PaneKeyEvent;
struct Point;
struct RectBounds;

typedef short FittingRoomSlotIndex;

enum FittingRoomListDisplayMode
{
    FittingRoomListDisplayMode_Rows = 0,
    FittingRoomListDisplayMode_Grid = 1
};

static const int kFittingRoomRowPageSize = 26;
static const int kFittingRoomGridPageRows = 3;
static const int kFittingRoomGridColumns = 6;
static const int kFittingRoomGridVisibleCells = 18;
static const int kFittingRoomMaxScroll = 30000;
static const FittingRoomSlotIndex kInvalidFittingRoomSlot = -1;

class FittingRoomListPane : public ControlPane
{
public:
    explicit FittingRoomListPane(const RectBounds *bounds);
    virtual ~FittingRoomListPane();

    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition,
                                 short newPosition);

protected:
    virtual void OnResize(const RectBounds *bounds);
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *oldBounds);
    virtual void OnInsertPane(const RectBounds *bounds,
                              int order,
                              Pane *previousPane,
                              Layer *layerOrContext);
    virtual void OnDetachPane();
    virtual void OnPaint();
    virtual bool OnKeyScroll(PaneKeyEvent *event);
    virtual bool OnInputEvent(Event *event);
    virtual bool OnScrollStep(int direction, int arg0, int arg1);

private:
    void UpdateScrollBar();
    void ResetScrollPosition();
    void GetItemSlotRect(FittingRoomSlotIndex slotIndex,
                         RectBounds *rect);
    FittingRoomSlotIndex HitTestSlot(int localX, int localY);
    FittingRoomSlotIndex ValidateFittingSelectionIndex(
        FittingRoomSlotIndex candidate) const;
    void GetItemSlotOrigin(Point *point,
                           FittingRoomSlotIndex slotIndex);
    void CancelPendingSlotTimer();

    short m_scrollPosition;
    short m_enabledItemCount;
    FittingRoomListDisplayMode m_displayMode;
    int m_listState0;
    int m_listState1;
    int m_listState2;
    FittingRoomScrollPane *m_scrollPane;

#pragma pack(push, 1)
    struct
    {
        unsigned char m_selectionState;
        short m_selectedItemIndex;
        unsigned char m_selectionFlags;
    };
#pragma pack(pop)

    unsigned int m_pendingSlotTimer;
    unsigned char m_stateFlags;
};

typedef char FittingRoomListPaneSizeMustBe300[
    sizeof(FittingRoomListPane) == 0x12c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID000053 proof and score effect: UID0002DL computes the visible start and cell advance with immediate `6`, wraps the cell index modulo `6`, and stops at immediate `0x12`; UID0002DM and sibling scroll evidence independently establish page sizes `26` and `3`, while the existing list declaration already records the `30000` scroll cap. The exact project source roots are [UID:0000IG][ControlPane](by-file/ControlPane.md) at `NexusTK/ui/core/` and [UID:0000OB][StringUtil](by-file/StringUtil.md) at `NexusTK/util/`, yielding `../ui/core/ControlPane.h` and `../util/StringUtil.h` from `NexusTK/cashshop/FittingRoom.cpp`. UID000053 rises `88/90 -> 91/92`.

- Exact proposed UID0000D9 SSO-7 declaration formal. It preserves the current constructor/destructor/Clear/Assign API and exact 24-byte storage and adds only the inline mutable-buffer selector directly observed in UID0002DL:

```text
*** UID:0000D9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SimpleUString
{
public:
    SimpleUString();
    ~SimpleUString();

    void Clear();
    SimpleUString& Assign(const wchar_t *source, unsigned int length);
    wchar_t *MutableData()
    {
        return m_capacity > 7 ? m_heapBuffer : m_inlineBuffer;
    }

private:
    union
    {
        wchar_t m_inlineBuffer[8];
        wchar_t *m_heapBuffer;
    };
    unsigned int m_length;
    unsigned int m_capacity;

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0000D9 proof and score effect: UID0002DL calls the already proved counted `Assign`, reads capacity at `+0x14`, selects the heap pointer only above the SSO-7 threshold, otherwise uses the inline buffer at `+0x00`, and passes that writable buffer to `_wcstok`. `MutableData()` is the narrow human-source expression of those exact inlined operations; it neither invents parser-only `AssignAnsi`/`c_str` methods nor collapses the separate pointer-backed `StringBase` family. UID0000D9 rises `88/88 -> 89/90`; [UID:0000OB][StringUtil](by-file/StringUtil.md) remains its source owner and receives the corresponding no-loss synchronization.

### Exact direct-dependency declaration closure

- Existing complete declarations are consumed without replacement: UID00004L/UID0000J6 supplies `Event`, `EventType`, `kEventLeftButtonUp`, `kEventMouseWheel`, and `EventPayload::m_pointer`; UID00004I/UID0000J4 supplies `EPFTileContext`, `Initialize`, and `bounds`; UID0000FQ/UID0000P1 supplies `UserPane` and `g_pUserPane`; UID00015S/UID0000N2 supplies `Point`, `RectBounds`, `InitPointPair`, `InitRectBounds`, and `PointInRect(y, x, bounds)`; UID00005V/UID0000JR and exact children UID0004LS/UID0004LT/UID0004LU/UID000162/UID00016C/UID0004H6 supply the inherited GrafPort fields and APIs; UID0000TN/UID0000OC supplies `g_pfnFillRect`. UID0001UU/UID0000KH supplies the ItemObjImageLib layout/global/draw APIs but requires the exact member-versus-file-helper reconciliation below.
- The callback must install the following four complete declarations rather than relying on a forward declaration, decompiler facade, raw offset, or unnamed PCH. These are additive to the preserved sixteen target-family formals.

- Exact proposed UID0001UU ItemObjImageLib declaration formal. UID0002DL's `0x004df460` call has no `g_pItemObjImageLib` receiver, while its two draw calls do. The source therefore keeps the singleton for draw methods and declares glyph bounds as a file-local/free ItemObjImageLib API:

```text
*** UID:0001UU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ItemObjImageLib : public LObject, public Singleton<ItemObjImageLib>
{
public:
    ItemObjImageLib();
    virtual ~ItemObjImageLib();

    int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageIn43x43Slot(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageUnscaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);

private:
    friend class MapPane;

    void RefreshItemFrameAvailability();

    ProtectedArray<ItemInfo> m_itemInfos;
};

void GetItemGlyphBounds(short itemId, RectBounds *outBounds);

extern ItemObjImageLib *g_pItemObjImageLib;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- ItemObjImageLib proof: direct UID0002DL callsite setup distinguishes the no-receiver glyph helper from the two `g_pItemObjImageLib` receiver calls. This supersedes only the current class-member placement of `GetItemGlyphBounds`; it preserves every method, singleton, field, and global fact in UID0001UU/UID0000KH and keeps the helper in `NexusTK/render/ItemObjImageLib.h/.cpp`.

- Exact proposed UID0000BV `Region` declaration formal:

```text
*** UID:0000BV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../../util/LObject.h"
#include "RectBounds.h"

class Region : public LObject
{
public:
    Region();
    virtual ~Region();

    bool IntersectsRect(const RectBounds *bounds) const;

private:
    RectBounds m_bounds;
};

typedef char RegionSizeMustBe20[
    sizeof(Region) == 0x14 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Region proof: constructor `0x00554680`, source destructor route `0x00554b00`, vtable `0x00622f58`, exact `LObject` header at `+0x00`, `RectBounds m_bounds` at `+0x04`, and size `0x14` make this a complete direct type for automatic `Region savedClip;`. Existing dirty-region Motion helpers remain exact child/source-island evidence and are not copied into this class merely to make FittingRoom compile.

- Exact proposed UID00006E ImageLib/resource-layout declaration formal. `ResourceLayoutTable` remains a source typedef/facet spelling over the RTTI-proven `ImageLib` object, not a second object, base, allocation, vtable, or global. This is the strongest human source choice that keeps the accepted existing `ResourceLayoutTable::` child definitions legal while matching the ImageLib constructor/destructor storage and sole `g_pEPFLib` lifetime:

```text
*** UID:00006E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../util/LObject.h"

class List;
struct ArchiveMetadataTable;
struct EPFTileContext;
struct FrameDrawRecord;
struct RectBounds;
struct ResourceLayoutEntry;

class ImageLib : public LObject
{
public:
    ImageLib(int cacheLimit, int);
    virtual ~ImageLib();

    int LoadResourceIndex(const wchar_t *resourceName);
    ResourceLayoutEntry *LookupLayoutEntry(
        const wchar_t *resourceName,
        int frameIndex,
        EPFTileContext *tileContext);
    void CopyEntryTileContext(
        const wchar_t *resourceName,
        int frameIndex,
        EPFTileContext *destination);
    RectBounds *GetEntryRect(
        const wchar_t *resourceName,
        int frameIndex,
        RectBounds *bounds);
    void LoadFrameDrawRecord(
        const ArchiveMetadataTable *table,
        int frameIndex,
        FrameDrawRecord *outRecord);
    void GetFrameSize(
        const wchar_t *resourceName,
        unsigned short *width,
        unsigned short *height);
    unsigned short GetEntryCount(const wchar_t *resourceName);

private:
    int FindResourceIndex(const wchar_t *resourceName);

    int m_refCount;
    int m_cacheLimit;
    List *m_pEntryList;
    int m_maxCacheSize;
};

typedef ImageLib ResourceLayoutTable;

extern ImageLib *g_pEPFLib;

typedef char ImageLibSizeMustBe20[
    sizeof(ImageLib) == 0x14 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- ImageLib/resource-layout proof: ImageLib RTTI/vtable and constructor/destructor prove the concrete object and sole global lifetime; all resource-layout methods consume the same `+0x0c` list and no independent ResourceLayoutTable constructor, allocation, vtable, or storage exists. The typedef records the historical/recovered semantic family without inventing a second class layout. UID0002KP proves the exact `LookupLayoutEntry(const wchar_t *, int, EPFTileContext *)` contract and returns `ResourceLayoutEntry *`. UID0000QU must historicalize its blank/final-type caveat and point to this one `extern ImageLib *g_pEPFLib` declaration; it must not emit a second definition.

- Exact proposed UID00007B complete declaration formal. It preserves every current declaration and adds only the forward declaration and narrow friend needed by UID0002DN:

```text
*** UID:00007B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Motion;
class List;
class AttachedObjectPane;
class BalloonObjectPane;
class EffectObjectPane;
class HitBarObjectPane;
class DamageNumberObjectPane;
class ObjectInfoObjectPane;
class BowGaugeObjectPane;
class FittingRoomListPane;
class GrafPort;
struct NxRect;

class LivingObjectPane : public ObjectPane
{
public:
    enum TimerMessage
    {
        kLivingTimerForwardStep = 0x41645746,
        kLivingTimerBoxStep = 0x41534246,
        kLivingTimerDirectionDelay = 0x43684469,
        kLivingTimerFrameAnimation = 0x446e4146,
        kLivingTimerRefresh = 0x52654461
    };

    class BoxRotator : public FrameHandler
    {
    public:
        explicit BoxRotator(LivingObjectPane *owner) : m_owner(owner) {}
        virtual ~BoxRotator() {}

        virtual void Advance(int frame);
        void Start();
        void Stop();

    private:
        friend class LivingObjectPane;
        LivingObjectPane *m_owner;
    };

    LivingObjectPane(
        int objectId,
        int mapX,
        int mapY,
        const ObjectStatusBlob &objectStatus,
        unsigned char facing);
    LivingObjectPane(int objectId, int mapX, int mapY, unsigned char facing);
    virtual ~LivingObjectPane();

    void GetSpriteConfig(ObjectStatusBlob *out) const;
    bool SetSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    void InitializeSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    bool HasGMNameSuffix() const;

    void SetMovingState(bool moving);
    void DestroyAllLinkedObjects();
    void DestroyAttachedObjects();
    void SetBalloonObjectPane(BalloonObjectPane *pane);
    void AddPrimaryEffectObjectPane(EffectObjectPane *pane);
    void AddSecondaryEffectObjectPane(EffectObjectPane *pane);
    void SetHitBarObjectPane(HitBarObjectPane *pane);
    void SetDamageNumberObjectPane(DamageNumberObjectPane *pane);
    void SetObjectInfoObjectPane(ObjectInfoObjectPane *pane);
    void UnregisterAttachedObjectPane(AttachedObjectPane *pane);

    void AddMotion(Motion *effect);
    void RemoveMotion(Motion *effect);
    void ClearAllEffects();
    void SetCurrentMotion(Motion *effect);
    void SetHighlightState(bool highlighted);
    void ShowDamageEffect(int value, short soundId);
    bool BeginMoveTo(int x, int y, unsigned char facing, short stepDelay);
    void SetFacing(unsigned char facing);
    void PlayAnimation(unsigned int animationGroup);
    void PlayFacingAnimation();
    void PlayDeathAnimation();
    void RequestNameplateEffect();
    void RemoveSpecialEffect();
    void ScheduleBoxRotationStep();
    void CancelBoxRotationStep();
    void ApplyLinkedObjectMode(int mode);
    void SyncPositionToLinkedObjects();
    void RefreshAllLinkedObjects();

    virtual void GetRenderBounds(NxRect *imageRect, NxRect *screenRect) const;
    virtual void RenderFrame(GrafPort *target, const RectBounds *bounds);
    virtual RectBounds *ComputeRenderBounds(RectBounds *outBounds);
    virtual void DrawSpriteFrame(GrafPort *target, const RectBounds *bounds);
    virtual void SetMapPosition(int x, int y);
    virtual void SetSpriteAttribute(unsigned char value);
    virtual void PlayActionAnimationOrEffect(
        unsigned action,
        int value,
        unsigned char facing);
    virtual void ShowName();
    virtual void HideName();
    virtual void PropagateLinkedObjectMode(int mode);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    friend class MapPane;
    friend class Motion;
    friend class BowGaugeObjectPane;
    friend class FittingRoomListPane;

    bool TryStepForward();

protected:
    unsigned char m_nameState;
    wchar_t m_nameBuffer[33];
    unsigned int m_objectInfoType;
    List *m_primaryEffectObjectPanes;
    List *m_secondaryEffectObjectPanes;
    ObjectStatusBlob m_objectStatus;
    List *m_activeEffects;
    Motion *m_currentEffect;
    bool m_isMoving;
    unsigned char m_facing;
    signed char m_moveFrame;
    unsigned int m_animationFrame;
    unsigned int m_animationGroup;
    bool m_terminalAnimation;
    bool m_nameVisible;
    unsigned int m_boxRotationStep;
    BalloonObjectPane *m_balloonObjectPane;
    HitBarObjectPane *m_hitBarObjectPane;
    DamageNumberObjectPane *m_damageNumberObjectPane;
    ObjectInfoObjectPane *m_objectInfoObjectPane;
    bool m_highlighted;
    unsigned int m_boxRotationPhase;
    BoxRotator m_boxRotator;
    unsigned int m_renderEffectState;
    RectBounds m_bounds;
};

typedef char LivingObjectPaneSizeMustBe524[
    sizeof(LivingObjectPane) == 0x20c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- LivingObjectPane/UserPane proof: storage `0x0067a748` is the sole source-facing `UserPane *g_pUserPane`; the tested byte is inherited `LivingObjectPane::m_nameVisible` at complete-object `+0x1d1`. The exact comparison is zero/nonzero, so UID0002DN uses `!g_pUserPane->m_nameVisible`. Existing MapPane, Motion, and BowGauge friendships establish the project pattern for direct cross-pane reads. Adding only `friend class FittingRoomListPane` preserves encapsulation and exact generated access without a fabricated global-state struct, public raw field, getter, or offset cast.

### Exact selected-entry support C++ reconciliations

- UID000050 receives the complete dialog declaration required before UID000053 and its list-pane children. The exact `0x47c` inherited boundary, two 68-byte `ObjectStatusBlob` snapshots, embedded `0x280` item state, three category/list dwords, 24-byte MSVC string, and final request pointer produce the observed `0x7ac` object without opaque storage or fake source padding. Position `5` places this declaration after UID000051 position `0` and before UID000053 position `10`. Relative `../ui/core/DialogPane.h`, `../map/ObjectStatusBlob.h`, and same-directory `CashShopRequest.h` are the evidence-backed project declaration counterparts; the declaration does not rely on an unnamed PCH or claim those headers already exist in current autogen. `friend class FittingRoomListPane;` is the narrow legal route for UID0002DI/UID0002DL/UID0002DN to read `m_itemState`, `m_activeCategory`, and `m_baseAppearance.m_compositionMode`.

```text
*** UID:000050 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../map/ObjectStatusBlob.h"
#include "../ui/core/DialogPane.h"
#include "CashShopRequest.h"

class FittingRoomListPane;

enum FittingRoomDialogCommand
{
    kFittingRoomCommandClose = 0,
    kFittingRoomCommandRotateRight = 3,
    kFittingRoomCommandRotateLeft = 4,
    kFittingRoomCommandBasic = 5,
    kFittingRoomCommandCurrent = 6,
    kFittingRoomCommandUsableItems = 7,
    kFittingRoomCommandWeapons = 8,
    kFittingRoomCommandMounts = 9,
    kFittingRoomCommandFace = 10,
    kFittingRoomCommandHead = 11,
    kFittingRoomCommandMantle = 12,
    kFittingRoomCommandNecklaces = 13,
    kFittingRoomCommandCoats = 14,
    kFittingRoomCommandShoes = 15,
    kFittingRoomCommandSpecialtySets = 16
};

struct FittingRoomCategoryButtonDef
{
    int commandId;
    const wchar_t* label;
};

class FittingRoomDialog : public DialogPane
{
    friend class FittingRoomListPane;

public:
    FittingRoomDialog();
    virtual ~FittingRoomDialog();

protected:
    virtual void OnCommand(int commandId);
    virtual void DrawBackground();
    virtual bool HandleFittingAction(int action, int arg0, int arg1);

private:
    int ShowPreview();
    void RebuildCategoryButtons();
    void SelectButton(int commandId);

    ObjectStatusBlob m_baseAppearance;
    ObjectStatusBlob m_previewAppearance;
    FittingRoomDialogItemState m_itemState;
    int m_activeCategory;
    int m_selectedCategoryCommandId;
    int m_categoryListState;
    std::string m_itemShopVersion;
    CashShopRequest* m_activeCatalogRequest;
};

typedef char FittingRoomDialogSizeMustBe1964[
    sizeof(FittingRoomDialog) == 0x7ac ? 1 : -1];

extern FittingRoomDialog* g_pFittingRoomDialog;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0000WS retains the complete existing method and replaces only the stale second-vector spelling with the single resolved field:

```text
*** UID:0000WS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomDialogItemState::ResetEquipmentEntries()
{
    m_selectedFittingItems.clear();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0002DI retains its complete scroll/reset behavior. The selected vector is reached through the item-state object; the special-mode byte at dialog `+0x49e` is exactly `m_baseAppearance + 0x22`, the already-declared `ObjectStatusBlob::m_compositionMode` union member, not an undeclared flattened dialog member.

```text
*** UID:0002DI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomListPane::ResetScrollPosition()
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;

    if (dialog->m_activeCategory == 3) {
        for (std::vector<FittingRoomSelectionEntry>::iterator it =
                 itemState->m_selectedFittingItems.begin();
             it != itemState->m_selectedFittingItems.end();
             ++it) {
            if (it->category == 3) {
                dialog->m_baseAppearance.m_compositionMode = 3;
            }
        }
    } else {
        dialog->m_baseAppearance.m_compositionMode = 0;
    }

    m_scrollPosition = 0;

    FittingRoomScrollPane* scrollPane = m_scrollPane;
    if (scrollPane->m_scrollPosition != 0) {
        scrollPane->m_scrollPosition = 0;
        scrollPane->Invalidate();
    }

    UpdateScrollBar();
    Invalidate();
    Invalidate();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0002DL receives its full exact destination formal. The complete paint behavior stays intact; only the selected-entry iterator declaration is reconciled to legal C++03 syntax.

```text
*** UID:0002DL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomListPane::OnPaint()
{
    EPFTileContext boardFrame;
    Region savedClip;

    boardFrame.Initialize();

    if (g_pEPFLib->LookupLayoutEntry(L"WBOARDBK.EPF", 0, &boardFrame) != 0) {
        RectBounds visible = m_visibleBounds;
        m_drawMode = 1;

        GetClipRegion(&savedClip);
        SetClipRect(&visible);

        const int tileWidth = boardFrame.bounds.right - boardFrame.bounds.left;
        const int tileHeight = boardFrame.bounds.bottom - boardFrame.bounds.top;
        if (tileWidth > 0 && tileHeight > 0) {
            for (int y = visible.top; y < visible.bottom; y += tileHeight) {
                for (int x = visible.left; x < visible.right; x += tileWidth) {
                    RectBounds destination;
                    InitRectBounds(&destination,
                                   x,
                                   y,
                                   x + tileWidth,
                                   y + tileHeight);
                    RenderTileFrame(&boardFrame,
                                    &boardFrame.bounds,
                                    &destination,
                                    m_drawMode,
                                    L"WBOARDBK.PAL",
                                    0);
                }
            }
        }

        SetClipRegion(&savedClip);
    }

    FittingRoomDialog *dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState *itemState = &dialog->m_itemState;
    const int activeCategory = dialog->m_activeCategory;
    const unsigned char catalogCategory = static_cast<unsigned char>(activeCategory);

    EPFTileContext itemScratch;
    EPFTileContext glyphScratch;
    itemScratch.Initialize();
    glyphScratch.Initialize();

    UpdateScrollBar();

    const short totalItems = itemState->GetItemCount(catalogCategory);

    short enabledBeforeVisibleStart = 0;
    for (short scanIndex = 1; scanIndex <= totalItems; ++scanIndex) {
        FittingRoomCatalogEntry *scanEntry =
            itemState->GetItemByIndex(catalogCategory, scanIndex);
        if (scanEntry != 0 && scanEntry->enabled != 0) {
            ++enabledBeforeVisibleStart;
            if (m_scrollPosition * kFittingRoomGridColumns < enabledBeforeVisibleStart) {
                break;
            }
        }
    }

    Point cell;
    InitPointPair(&cell, 31, 17);
    m_drawMode = 1;

    unsigned char cellIndex = 0;
    short drawnCells = 0;
    short catalogIndex = static_cast<short>(m_scrollPosition * kFittingRoomGridColumns);
    if (m_enabledItemCount == 0 ||
        m_scrollPosition + kFittingRoomGridVisibleCells > totalItems) {
        catalogIndex = 0;
    }

    while (catalogIndex < totalItems && drawnCells < kFittingRoomGridVisibleCells) {
        FittingRoomCatalogEntry *entry =
            itemState->GetItemByIndex(catalogCategory, catalogIndex);

        if (entry != 0) {
            for (std::vector<FittingRoomSelectionEntry>::iterator selected =
                     itemState->m_selectedFittingItems.begin();
                 selected != itemState->m_selectedFittingItems.end();
                 ++selected) {
                if (selected->category == activeCategory &&
                    selected->catalogIndex == catalogIndex) {
                    RectBounds highlight;
                    InitRectBounds(&highlight,
                                   cell.x,
                                   cell.y,
                                   cell.x + 50,
                                   cell.y + 50);
                    SetDrawColor(0x8a);
                    g_pfnFillRect(this, &highlight);
                    break;
                }
            }

            if (entry->enabled != 0) {
                RectBounds &glyphBounds = glyphScratch.bounds;
                GetItemGlyphBounds(entry->tile, &glyphBounds);

                RectBounds iconRect;
                const int glyphWidth = glyphBounds.right - glyphBounds.left;
                const int glyphHeight = glyphBounds.bottom - glyphBounds.top;
                if (glyphWidth <= 50 && glyphHeight <= 50) {
                    InitRectBounds(&iconRect,
                                   cell.x,
                                   cell.y,
                                   cell.x + 50,
                                   cell.y + 50);
                    g_pItemObjImageLib->DrawItemImageIn43x43Slot(
                        this, &iconRect, entry->tile, entry->color, 0, 0.0f);
                } else {
                    const int centeredLeft = cell.x + ((50 - glyphWidth) / 2);
                    const int centeredTop = cell.y + ((50 - glyphHeight) / 2);
                    InitRectBounds(&iconRect,
                                   centeredLeft,
                                   centeredTop,
                                   centeredLeft + glyphWidth,
                                   centeredTop + glyphHeight);
                    g_pItemObjImageLib->DrawItemImageUnscaled(
                        this, &iconRect, entry->tile, entry->color);
                }

                SetTextColor(0x8f);

                wchar_t formattedName[128];
                swprintf_s(formattedName, _countof(formattedName), L"%s", entry->name);

                SimpleUString itemName;
                itemName.Assign(formattedName, wcslen(formattedName));

                wchar_t line[32];
                memset(line, 0, sizeof(line));

                wchar_t *nextToken = 0;
                wchar_t *token = wcstok(itemName.MutableData(), L" ", &nextToken);
                int lineLength = 0;
                int textY = cell.y + 0x42;
                const int textX = cell.x - 6;

                while (token != 0) {
                    if (lineLength > 0) {
                        const int tokenLength = static_cast<int>(wcslen(token));
                        if (lineLength + tokenLength >= 14) {
                            const short width = GetTextWidth(line, lineLength);
                            MoveTo(textX - width / 2 + 31, textY);
                            DrawWideText(line, lineLength);
                            textY += 16;
                            line[0] = 0;
                            lineLength = 0;
                        }
                    }

                    if (lineLength != 0) {
                        swprintf_s(line, _countof(line), L"%s %s", line, token);
                    } else {
                        swprintf_s(line, _countof(line), L"%s", token);
                    }

                    lineLength = static_cast<int>(wcslen(line));
                    token = wcstok(0, L" ", &nextToken);
                }

                if (lineLength > 0) {
                    const short width = GetTextWidth(line, lineLength);
                    MoveTo(textX - width / 2 + 31, textY);
                    DrawWideText(line, lineLength);
                }
            }

            ++drawnCells;
            cellIndex = static_cast<unsigned char>((cellIndex + 1) % kFittingRoomGridColumns);
            cell.x = cellIndex * 0x60 + 0x11;
            if (cellIndex == 0) {
                cell.y += 0x70;
            }
        }

        ++catalogIndex;
    }

    SetDrawColor(0x8f);
    m_drawMode = 2;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0002DN receives its full exact destination formal. Every selected-vector operation uses the declared item-state receiver, all construction/erase/overlap/append/destruction operations are expressed as ordinary C++03 container source, and the part switch writes the current ObjectStatusBlob fields directly. The five former report helper names are not declarations or callees and do not appear in the formal.

```text
*** UID:0002DN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000053 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool FittingRoomListPane::OnInputEvent(Event* event)
{
    FittingRoomDialog* dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState* itemState = &dialog->m_itemState;
    const unsigned char category = static_cast<unsigned char>(dialog->m_activeCategory);

    if (event->m_type == kEventLeftButtonUp) {
        FittingRoomSlotIndex slot =
            HitTestSlot(event->m_payload.m_pointer.m_x,
                        event->m_payload.m_pointer.m_y);
        if (static_cast<unsigned short>(slot) <= 0x1a) {
            FittingRoomSlotIndex candidate;
            if (m_displayMode == FittingRoomListDisplayMode_Rows) {
                candidate = static_cast<FittingRoomSlotIndex>(m_scrollPosition + slot);
            } else {
                candidate = static_cast<FittingRoomSlotIndex>(
                    m_scrollPosition * kFittingRoomGridColumns + slot);
            }

            candidate = ValidateFittingSelectionIndex(candidate);
            if (candidate != kInvalidFittingRoomSlot &&
                !g_pUserPane->m_nameVisible) {
                FittingRoomCatalogEntry* catalogEntry =
                    itemState->GetItemByIndex(category, candidate);
                bool removing = false;

                FittingRoomSelectionEntry newEntry;
                newEntry.category =
                    static_cast<FittingRoomCatalogCategory>(category);
                newEntry.catalogIndex = candidate;

                for (int partIndex = 0;
                     partIndex < catalogEntry->GetPartCount();
                     ++partIndex) {
                    const FittingRoomCatalogPartRecord* part =
                        catalogEntry->GetPart(
                            static_cast<signed char>(partIndex));
                    if (part != 0 && part->part != -1) {
                        newEntry.partTypes.push_back(
                            static_cast<int>(part->part));
                    }
                }

                for (std::vector<FittingRoomSelectionEntry>::iterator it =
                         itemState->m_selectedFittingItems.begin();
                     it != itemState->m_selectedFittingItems.end();
                     ++it) {
                    if (it->category == newEntry.category &&
                        it->catalogIndex == newEntry.catalogIndex) {
                        itemState->m_selectedFittingItems.erase(it);
                        removing = true;
                        break;
                    }
                }

                if (!removing && !newEntry.partTypes.empty()) {
                    wcscpy_s(newEntry.name, 0x50, catalogEntry->name);

                    std::vector<FittingRoomSelectionEntry>::iterator existing =
                        itemState->m_selectedFittingItems.begin();
                    while (existing != itemState->m_selectedFittingItems.end()) {
                        bool overlaps = false;
                        for (std::vector<int>::const_iterator oldPart =
                                 existing->partTypes.begin();
                             oldPart != existing->partTypes.end() && !overlaps;
                             ++oldPart) {
                            for (std::vector<int>::const_iterator newPart =
                                     newEntry.partTypes.begin();
                                 newPart != newEntry.partTypes.end();
                                 ++newPart) {
                                if (*oldPart == *newPart) {
                                    overlaps = true;
                                    break;
                                }
                            }
                        }

                        if (overlaps) {
                            existing =
                                itemState->m_selectedFittingItems.erase(existing);
                        } else {
                            ++existing;
                        }
                    }

                    itemState->m_selectedFittingItems.push_back(newEntry);
                }

                dialog->m_baseAppearance.m_compositionMode = 0;

                for (int partIndex = 0;
                     partIndex < catalogEntry->GetPartCount();
                     ++partIndex) {
                    const FittingRoomCatalogPartRecord* part =
                        catalogEntry->GetPart(static_cast<signed char>(partIndex));
                    if (part == 0 || part->tile == 0xffff) {
                        continue;
                    }

                    ObjectStatusBlob& appearance = dialog->m_baseAppearance;
                    const ObjectStatusBlob& original =
                        dialog->m_previewAppearance;

                    switch (part->part) {
                    case 1:
                        appearance.m_weaponId =
                            removing ? original.m_weaponId : part->tile;
                        appearance.m_weaponColor =
                            removing ? original.m_weaponColor : part->color;
                        break;
                    case 2:
                        appearance.m_bodyId =
                            removing ? original.m_bodyId : part->tile;
                        appearance.m_bodyColor =
                            removing ? original.m_bodyColor : part->color;
                        break;
                    case 3:
                        appearance.m_shieldOrArrowId =
                            removing ? original.m_shieldOrArrowId : part->tile;
                        appearance.m_shieldOrArrowColor =
                            removing ? original.m_shieldOrArrowColor : part->color;
                        break;
                    case 4:
                        appearance.m_helmetId = static_cast<unsigned char>(
                            removing ? original.m_helmetId : part->tile);
                        appearance.m_helmetColor =
                            removing ? original.m_helmetColor : part->color;
                        appearance.m_headgearMode = 1;
                        break;
                    case 6:
                        appearance.m_neckId =
                            removing ? original.m_neckId : part->tile;
                        appearance.m_neckColor =
                            removing ? original.m_neckColor : part->color;
                        break;
                    case 13:
                        appearance.m_shoesId =
                            removing ? original.m_shoesId : part->tile;
                        appearance.m_shoesColor =
                            removing ? original.m_shoesColor : part->color;
                        break;
                    case 14:
                        appearance.m_mantleId =
                            removing ? original.m_mantleId : part->tile;
                        appearance.m_mantleColor =
                            removing ? original.m_mantleColor : part->color;
                        break;
                    case 16:
                        if (removing) {
                            appearance.m_coatId = original.m_coatId;
                            appearance.m_bodyId = original.m_bodyId;
                            appearance.m_bodyColor = original.m_bodyColor;
                            appearance.m_shoesId = original.m_shoesId;
                        } else {
                            appearance.m_coatId =
                                part->tile > 9999
                                    ? static_cast<unsigned short>(
                                          part->tile % 10000)
                                    : 0xffff;
                            appearance.m_bodyId =
                                part->tile <= 9999 ? part->tile : 0xffff;
                            appearance.m_bodyColor = part->color;

                            if (appearance.m_coatId != 0xffff &&
                                appearance.m_shoesId == 0xffff) {
                                appearance.m_shoesId =
                                    part->gender != 0 ? 1 : 0;
                            } else if (appearance.m_coatId == 0xffff &&
                                       appearance.m_bodyId != 0 &&
                                       appearance.m_bodyId != 1 &&
                                       appearance.m_bodyId != 0x39 &&
                                       appearance.m_bodyId != 0x3a &&
                                       appearance.m_bodyId != 0xa0 &&
                                       appearance.m_bodyId != 0xa1) {
                                appearance.m_shoesId = 0xffff;
                            }
                        }
                        break;
                    case 22:
                        appearance.m_faceDecorationId =
                            removing ? original.m_faceDecorationId : part->tile;
                        appearance.m_faceDecorationColor =
                            removing
                                ? original.m_faceDecorationColor
                                : part->color;
                        break;
                    case 23:
                        appearance.m_hairDecorationId =
                            removing ? original.m_hairDecorationId : part->tile;
                        appearance.m_hairDecorationColor =
                            removing
                                ? original.m_hairDecorationColor
                                : part->color;
                        if (!removing && part->tile >= 10000) {
                            appearance.m_helmetId = 0xff;
                            if (part->tile > 19999) {
                                appearance.m_hairColor = part->color;
                                appearance.m_hairId =
                                    static_cast<unsigned char>(
                                        part->tile % 20000);
                            } else {
                                appearance.m_hairId =
                                    static_cast<unsigned char>(
                                        part->tile % 10000);
                            }
                            appearance.m_hairDecorationId = 0xffff;
                        }
                        break;
                    case 24:
                        appearance.m_secondFaceDecorationId =
                            removing
                                ? original.m_secondFaceDecorationId
                                : part->tile;
                        appearance.m_secondFaceDecorationColor =
                            removing
                                ? original.m_secondFaceDecorationColor
                                : part->color;
                        break;
                    case 30:
                        appearance.m_appearanceId =
                            removing ? original.m_appearanceId : part->tile;
                        appearance.m_faceColor =
                            removing ? original.m_faceColor : part->color;
                        break;
                    case 31:
                        appearance.m_hairId = static_cast<unsigned char>(
                            removing ? original.m_hairId : part->tile);
                        break;
                    case 32:
                        appearance.m_hairColor =
                            removing ? original.m_hairColor : part->color;
                        break;
                    case 33:
                        if (removing) {
                            appearance.m_compositionMode = 0;
                            appearance.m_ridingDefinitionIndex =
                                original.m_ridingDefinitionIndex;
                            appearance.m_ridingPaletteFlags =
                                original.m_ridingPaletteFlags;
                            appearance.m_ridingYOffset =
                                original.m_ridingYOffset;
                        } else {
                            appearance.m_compositionMode = 3;
                            appearance.m_ridingDefinitionIndex = part->tile;
                            appearance.m_ridingPaletteFlags = part->color;
                            appearance.m_ridingYOffset = 0;
                        }
                        break;
                    }
                }
            }
        }
    } else if (event->m_type == kEventMouseWheel) {
        if (PointInRect(event->m_payload.m_pointer.m_y,
                        event->m_payload.m_pointer.m_x,
                        &m_visibleBounds)) {
            const short oldPosition = m_scrollPane->m_scrollPosition;
            short newPosition = static_cast<short>(
                oldPosition - event->m_payload.m_pointer.m_detail);
            if (newPosition < 0) {
                newPosition = 0;
            }
            if (newPosition > m_scrollPane->m_scrollRange) {
                newPosition = m_scrollPane->m_scrollRange;
            }
            OnScrollPositionChanged(0, oldPosition, newPosition);
        }
    }

    Point childOrigin;
    m_scrollPane->GetOrigin(&childOrigin);
    event->m_payload.m_pointer.m_x -= childOrigin.x;
    event->m_payload.m_pointer.m_y -= childOrigin.y;
    const bool handled = m_scrollPane->OnInputEvent(event);
    event->m_payload.m_pointer.m_x += childOrigin.x;
    event->m_payload.m_pointer.m_y += childOrigin.y;
    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0002UE retains its covered-by/no-code disposition, but this is the complete exact destination formal rather than a comment excerpt or placeholder.

```text
*** UID:0002UE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this range is covered by [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) FittingRoomDialogItemState::~FittingRoomDialogItemState() and the [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) field lifecycle.
// Retain this page as vector-storage cleanup evidence for FittingRoomDialogItemState::m_selectedFittingItems.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- These six exact blocks form one callback unit. UID000051 position `0` defines catalog/selection/item-state types; UID000050 position `5` defines the dialog and its narrow friendship; UID000053 position `10` defines the list pane; the complete method formals then compile against declarations that precede them. No callback may substitute only the changed loop/body lines.

- Exact proposed UID0002E4 parser formal replacement:

```text
*** UID:0002E4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool FittingRoomCatalogEntry::LoadFromJson(const Json::Value& value)
{
    enabled = true;

    const std::string itemName = value.get("name", "None").asString();
    if (itemName == "None") {
        return false;
    }

    const std::wstring wideName(itemName.begin(), itemName.end());
    wcscpy_s(name, 0x50, wideName.c_str());

    tile = static_cast<short>(value.get("tile", -1).asInt());
    tile = static_cast<short>(tile - 0x4000);
    color = static_cast<unsigned char>(value.get("color", -1).asInt());

    Json::Value items = value.get("items", Json::Value());
    const int itemCount = static_cast<int>(items.size());
    for (int index = 0; index < itemCount; ++index) {
        Json::Value partValue = items[index];

        FittingRoomCatalogPartRecord part;
        part.part = static_cast<signed char>(
            partValue.get("part", -11).asInt());
        if (part.part == -11) {
            return false;
        }

        part.tile = static_cast<unsigned short>(partValue.get("tile", -11).asInt());
        part.color = static_cast<unsigned char>(partValue.get("color", -1).asInt());
        part.gender = static_cast<unsigned char>(partValue.get("gender", -1).asInt());
        if (part.gender == 0xff) {
            return false;
        }

        parts.push_back(part);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0002E4 proof and score effect: the live helper at `0x00423060` is the 24-byte SSO-7 range-construction lowering used by this parser and one independent caller; UID0000D9 does not declare the rejected parser-side `AssignAnsi`/`c_str` facade. `std::wstring` supplies the source operation directly, and its `c_str()` is valid. The nested Json value is copied, and the part local is not value-initialized, so natural padding remains untouched. UID0002E4 is validated at `90/91`.

- Exact proposed UID0002E5 part-accessor formal:

```text
*** UID:0002E5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
const FittingRoomCatalogPartRecord* FittingRoomCatalogEntry::GetPart(
    signed char partIndex) const
{
    const int index = static_cast<int>(partIndex);
    if (index >= static_cast<int>(parts.size())) {
        return NULL;
    }

    return &parts[0] + index;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0002E5 proof and score effect: the binary sign-extends the byte index, compares only `index >= count`, and otherwise returns `begin + index * 6`; it does not add a lower-bound test. Both callers pass nonnegative loop indexes. The naturally aligned record and signedness blockers are resolved; UID0002E5 is validated at `90/91`.
- Exact proposed target formal block:

```text
*** UID:0002E6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool FittingRoomDialogItemState::LoadCategoryFromJson(
    const Json::Value& root,
    FittingRoomCatalogCategory category)
{
    const char* categoryKey;

    switch (category) {
    case kFittingRoomCategoryMain:
        categoryKey = "main";
        break;
    case kFittingRoomCategoryUsableItems:
        categoryKey = "usable_items";
        break;
    case kFittingRoomCategoryWeapons:
        categoryKey = "weapons";
        break;
    case kFittingRoomCategoryMounts:
        categoryKey = "mounts";
        break;
    case kFittingRoomCategoryFace:
        categoryKey = "face";
        break;
    case kFittingRoomCategoryHead:
        categoryKey = "head";
        break;
    case kFittingRoomCategoryMantle:
        categoryKey = "mantle";
        break;
    case kFittingRoomCategoryNecklaces:
        categoryKey = "necklaces";
        break;
    case kFittingRoomCategoryCoats:
        categoryKey = "coats";
        break;
    case kFittingRoomCategoryShoes:
        categoryKey = "shoes";
        break;
    case kFittingRoomCategorySpecialtySets:
        categoryKey = "specialty_sets";
        break;
    default:
        return false;
    }

    Json::Value categoryValue = root.get(categoryKey, Json::Value());
    if (categoryValue.isNull()) {
        return false;
    }

    std::vector<FittingRoomCatalogEntry*> entries;
    const int itemCount = static_cast<int>(categoryValue.size());

    for (int index = 0; index < itemCount; ++index) {
        Json::Value itemValue = categoryValue[index];
        FittingRoomCatalogEntry* entry =
            new FittingRoomCatalogEntry(category);

        if (!entry->LoadFromJson(itemValue)) {
            return false;
        }

        entries.push_back(entry);
    }

    m_categoryLookup.insert(
        std::make_pair(static_cast<unsigned char>(category), entries));
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact support formal replacement for UID0002E7. The two stale body calls
  `m_categoryLookup.Initialize(8)` and `m_equipmentEntries.clear()` are removed
  because the observed initialization is compiler-emitted default member
  construction:

```text
*** UID:0002E7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FittingRoomDialogItemState::FittingRoomDialogItemState()
    : m_catalogVersion(""),
      m_cacheLoaded(false),
      m_encodeKey("CASHEncodeDecodeByChris"),
      m_decodeKey("sirhCyBedoceDedocnEHSAC")
{
    m_cacheFilePath[0] = L'\0';

    wchar_t documentsPath[MAX_PATH];
    wchar_t directoryPath[MAX_PATH];

    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) == S_OK) {
        swprintf_s(directoryPath, MAX_PATH, L"%s\\NexusTK", documentsPath);
        if (CreateDirectoryW(directoryPath, NULL) ||
            GetLastError() == ERROR_ALREADY_EXISTS) {
            swprintf_s(
                directoryPath,
                MAX_PATH,
                L"%s\\NexusTK\\ItemShop",
                documentsPath);
            if (CreateDirectoryW(directoryPath, NULL) ||
                GetLastError() == ERROR_ALREADY_EXISTS) {
                swprintf_s(
                    m_cacheFilePath,
                    MAX_PATH,
                    L"%s\\ItemShop.jbn",
                    directoryPath);
            }
        }
    }

    FILE* cacheFile = _wfopen(m_cacheFilePath, L"rb");
    if (cacheFile == NULL) {
        return;
    }

    fseek(cacheFile, 0, SEEK_END);
    const long fileLength = ftell(cacheFile);
    fseek(cacheFile, 0, SEEK_SET);

    std::string decoded;
    if (fileLength >= 0) {
        char* fileBytes =
            static_cast<char*>(malloc(static_cast<size_t>(fileLength) + 1));
        if (fileBytes != NULL) {
            fileBytes[fileLength] = '\0';
            if (fread(
                    fileBytes,
                    1,
                    static_cast<size_t>(fileLength),
                    cacheFile) == static_cast<size_t>(fileLength)) {
                TransformPersistedBuffer(
                    fileBytes,
                    static_cast<int>(fileLength));
                decoded.assign(fileBytes, static_cast<size_t>(fileLength));
            }
            free(fileBytes);
        }
    }

    fclose(cacheFile);

    if (LoadEncodedStateBuffer(decoded)) {
        m_cacheLoaded = true;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- UID0002E7 dependency proof and score effect: exact bytes at `0x0060d780` reduce IDA `Locale` to an empty C string, so `m_catalogVersion("")` removes an IDA label without inventing a project symbol. The UID000051 block directly includes the headers for every Win32/Shell/CRT call in this body. The route is implemented and validated; UID0002E7 is `90/91`.

- Exact support formal replacement for UID0002EC. `FittingRoomCategoryMap` is
  the class/header alias for the byte-keyed hash-container member:

```text
*** UID:0002EC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomDialogItemState::ResetCategoryEntryLists()
{
    for (FittingRoomCategoryMap::iterator category =
             m_categoryLookup.begin();
         category != m_categoryLookup.end();
         ++category) {
        std::vector<FittingRoomCatalogEntry*> entries = category->second;

        for (std::vector<FittingRoomCatalogEntry*>::iterator entry =
                 entries.begin();
             entry != entries.end();
             ++entry) {
            delete *entry;
        }
    }

    m_categoryLookup.clear();
    m_categoryLookup.rehash(8);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact support formal replacement for UID0000WV:

```text
*** UID:0000WV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
short FittingRoomDialogItemState::GetItemCount(unsigned char category)
{
    FittingRoomCategoryMap::iterator position =
        m_categoryLookup.find(category);
    if (position == m_categoryLookup.end()) {
        return 0;
    }

    return static_cast<short>(position->second.size());
}

FittingRoomCatalogEntry* FittingRoomDialogItemState::GetItemByIndex(
    unsigned char category,
    short itemIndex)
{
    FittingRoomCategoryMap::iterator position =
        m_categoryLookup.find(category);
    if (position == m_categoryLookup.end()) {
        return NULL;
    }

    std::vector<FittingRoomCatalogEntry*> entries = position->second;
    if (static_cast<short>(entries.size()) <= itemIndex) {
        return NULL;
    }

    return entries[itemIndex];
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior:
  - switch/default matches category dispatch;
  - mutable/category and copied/item Json values match exact API calls;
  - constructor call matches four observed stores;
  - failure return deliberately preserves pointer leaks;
  - vector push/copy and map insert reproduce the compiler container paths.
- Reason it matches plausible original source shape: it is ordinary C++03-era game code using enum, JsonCpp, `std::string`/`std::wstring`, `std::vector`, direct platform/CRT APIs, and a hash-map member. It contains no IDA labels, fake padding fields, raw offsets, custom decompiler structs, or hand-authored compiler internals.
- Naming convention: existing PascalCase class/method/type names, `m_` member prefix, lower camel locals, and `k` enum constants.
- Third-party import directive: not applicable. This is NexusTK-owned consumer code, not a JsonCpp source embed.

Support formal/metadata disposition after accepted callback:

- UID0002U4, UID0002U8, UID0002U9, UID0002UB, UID0002UH, UID0002UI, and UID0000WW should not retain hand-authored helper bodies. Set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, and leave the formal block blank while preserving binary evidence. These bodies are regenerated from source container declarations and operations. Preserve current completion/confidence and semantic `CANONICAL_OWNER` for the FittingRoom-specialized pages; clear UID0000WW's incorrect DATIndexVector owner.

| UID | Completion | Confidence | Canonical owner | Reconstructable | Emitter UIDs | Formal block |
| --- | ---: | ---: | --- | --- | --- | --- |
| `0002U4` | 88 | 91 | `000051` semantic context | `FALSE` | blank | empty |
| `0002U8` | 88 | 90 | `000051` semantic context | `FALSE` | blank | empty |
| `0002U9` | 88 | 90 | `000051` semantic context | `FALSE` | blank | empty |
| `0002UB` | 88 | 91 | `000051` semantic context | `FALSE` | blank | empty |
| `0002UH` | 88 | 90 | `000051` semantic context | `FALSE` | blank | empty |
| `0002UI` | 88 | 90 | `000051` semantic context | `FALSE` | blank | empty |
| `0000WW` | 88 | 91 | blank | `FALSE` | blank | empty |
- Implemented scores are UID0002E4 `90/91`, UID0002E7 `90/91`, UID0002EC `91/92`, UID0000WV `90/92`, and UID0001UH `91/92`. UID0000JE remains `88/90` because this work does not final-audit the entire broad FittingRoom module.

### Exact validator-owned raw-constructor repair (implemented record)

The numbered procedure below is retained as the exact accepted execution record. It completed successfully; references to actions that "must" occur describe the pre-execution plan, not current pending work.

- Stale path: `by-memory/0x004219f0-0x00421a20.FittingRoomCatalogEntryNoRouteInitializer.md`.
- Corrected path: `by-memory/0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer.md`.
- Exact corrected range: `[0x004219f0,0x00421a22)`, 50 bytes, SHA-256 `FBC2EE41D0B082CDCCFC0598B2586F6CFAA20CEA4A03B499AD9D28A2D50DB91E`.
- Collision disposition: UID00042D remains the live MapPane UID and is never edited, removed, remapped, or referenced as FittingRoom evidence. The stale FittingRoom page's first UID line is invalid duplicate content, not an identity to preserve.
- Five ordinary referring pages used the corrected canonical temporary token before reference validation:
  - UID0004WJ `by-memory/0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md`;
  - UID0004WL `by-memory/0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md`;
  - UID0002E6 target;
  - UID000051 class;
  - UID0000JE file.
- Exact temporary token in each referring page:
  `[TMP:"by-memory/0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer.md"]`
- Exact accepted-callback order:
  1. Lease only the stale raw page; rename it to the corrected path, remove only the invalid first-line `*** UID:00042D ... ***`, change all own title/range/boundary text from exclusive end `0x00421a20` to `0x00421a22`, preserve all evidence/history, conditionally set `90/91`, owner/emitter `000051`, reconstructable true, and place the covered-by formal comment below. Keep this one lease only through the immediately following scoped validation.
  2. From `source-3/project-documentation`, run only:
     `python .\tools\validator.py --mode file --file by-memory\0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer.md --apply --queue-timeout 240`
     The corrected page has no UID at command start, so the validator allocates the next UID from `validator.ini`, inserts it, and records the corrected path. Record the exact assigned UID, command ID, timestamp, exit/ok, and effects; read back the first-line UID and corrected page, then immediately release the raw-page lease. A duplicate-path conflict is a stop/reconcile condition, not permission to edit validator state.
  3. The first four referring pages were processed serially in the exact order below, with source owner UID0000JE deferred to the final `--wait-generated` command. Each page was leased alone, its stale raw-path or false MapPane UID00042D link was replaced through `[TMP:"by-memory/0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer.md"]`, UID0004WL following padding was corrected from `[0x00421a20,0x00421a30)` to `[0x00421a22,0x00421a30)`, the listed validator resolved the TMP to UID0004WI, and the lease was released immediately. Final readback found no unresolved TMP, duplicate conflict, wrong MapPane link, or old-path residue:

     _Executable command block removed from the research report; preserved in [0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality-removed.md](0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality-removed.md)._

  4. Run the additional callback-destination validators serially using these exact commands and order, keeping only each edited destination's lease through its immediately following validator and then releasing it. Record every command ID, command timestamp, exit/ok result, and validator-owned effect. UID0002EF is read-only dependency evidence and is not validated unless callback drift requires an ordinary edit:

     _Executable command block removed from the research report; preserved in [0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality-removed.md](0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality-removed.md)._
  5. Read back all six raw-page/path destinations. Required postcondition: corrected raw page has exactly one newly allocated UID; five generated references use that same UID/path; zero FittingRoom contexts use UID00042D for the raw constructor; zero old `0x004219f0-0x00421a20...` links remain; parent padding starts at `0x00421a22`.
   6. Read back UID0000WS/UID0002DI/UID0002DL/UID0002DN/UID0002UE, UID00004Z/UID000050/UID000051/UID000053/UID0000D9, UID0001UH, UID0000OB, UID0000BV/UID0000N3, UID00006E/UID0000K2/UID0000QU, UID0001UU/UID0000KH, UID00007B/UID0000KU, and UID0000JE. Also read back the already-complete Event/EPFTileContext/UserPane/GrafPort/Surface/geometry declaration owners without editing them unless drift is discovered. Required postconditions: one `m_selectedFittingItems` item-state field; no current source claim for `m_equipmentEntries`; selection fields `name`/`catalogIndex`; legal C++03 iterator expressions; narrow friend declarations documented on the exact owning classes; `<string.h>` present in UID000051; exact grid constants; one valid paint-side SSO-7 `SimpleUString::MutableData()` route; zero parser-side `SimpleUString::AssignAnsi`; zero parser-side `SimpleUString::c_str` facade; exactly the allowed `std::wstring::c_str()` parser call; direct `m_compositionMode`; exact `Event::m_type`/`m_payload.m_pointer`, `EPFTileContext::Initialize`/`bounds`, stack `Region`, `g_pEPFLib` ImageLib/resource-layout route, `g_pItemObjImageLib` member draw route plus free glyph-bounds helper, `g_pUserPane->m_nameVisible`, GrafPort/Surface/geometry APIs, and no fabricated UID0002DN helper API, invented accessor, raw-offset source, `g_pResourceMan`, or `g_pGlobalState`.
  7. Completed reconciliation: this report records UID0004WI, exact command history, accepted semantic command16927 hash/metrics, current physical command17009 header/hash/metrics, and terminal no-loss manual rows. B004 did not edit `validator.ini`, manual coverage, generated files, or report lifecycle state and did not run/probe `execute_report`.

- Exact corrected raw-page formal terminalized with validator-allocated UID0004WI:

```text
*** UID:0004WI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted source for this retained constructor body is covered by
// [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) FittingRoomCatalogEntry(FittingRoomCatalogCategory) and
// [UID:0002E6][0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson](by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md) new FittingRoomCatalogEntry(category).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- Current implementation disposition: accepted package applied and validated; target metadata is `90/91`, owner/emitter remain `000051`, reconstructable true.
- Replace indexed table, const/reference Json values, memset, behavior-divergent cleanup, and custom Insert claims.
- Preserve malformed-input leaks as exact behavior, explicitly documented rather than normalized away.
- Historicalize old B-agent custom helper interpretations; keep their useful low-level observations.
- Reclassify exact compiler helper pages as non-source/generated support, clear emitters/formals, and retain semantic class/file context in prose.
- Install UID000051's direct-header/natural-layout declaration formal at emitter position `0` and UID000050's complete dialog declaration at position `5`, before the complete UID000053 position-`10` declaration. Apply UID0000D9's complete SSO-7 formal, the corrected UID0002E4 parser, UID0002E5 accessor, and all five complete selected-entry support destination formals exactly; body-only excerpts are not valid callback artifacts. Add explicit companion-header paths to UID0000IT (`NexusTK/ui/core/DialogPane.h`), UID0000M6 (`NexusTK/map/ObjectStatusBlob.h`), and UID0000IG (`NexusTK/ui/core/ControlPane.h`); preserve the already-documented UID0000I0 `cashshop/CashShopRequest.h` and UID0000OB `util/StringUtil.h` routes. Add the complete direct-dependency destination package: existing Event/EPFTileContext/UserPane/GrafPort/Surface/geometry declarations are readback dependencies; UID0000BV/UID0000N3 receive the complete Region declaration/source route; UID00006E/UID0000K2/UID0000QU receive the ImageLib/ResourceLayoutTable-facet plus `g_pEPFLib` route; UID0001UU/UID0000KH receive the complete ItemObjImageLib/member-draw/free-glyph route; and UID00007B/UID0000KU receive the narrow `FittingRoomListPane` friend needed for `g_pUserPane->m_nameVisible`.
- Reconcile the selected-entry family to one exact `FittingRoomSelectionEntry { category, name, catalogIndex, partTypes }` declaration and one item-state `m_selectedFittingItems` vector. UID0002DI/UID0002DL/UID0002DN must reach it through `dialog->m_itemState`; UID0000WS/UID0002UE and lifecycle support use the same member. UID000050 and UID000051 grant only the observed narrow `FittingRoomListPane` friendship. UID0002DI/UID0002DN reach the special-mode byte through existing `m_baseAppearance.m_compositionMode`.
- Emit UID0002DN as direct human C++03 source: construct the temporary selected entry, erase exact and overlapping selections with vector iterators, append normally, rely on automatic temporary destruction, and apply the observed numeric part switch directly to ObjectStatusBlob. Reject the five report helper facades because the target contains those operations inline and has no such call route.
- Declare `kFittingRoomGridColumns = 6` and `kFittingRoomGridVisibleCells = 18` in UID000053 and declare `SimpleUString::MutableData()` in UID0000D9. These close UID0002DL without deleting its valid SimpleUString use.
- The implemented atomic package assigns every researched target-family and direct UID000053/UID0002DL/UID0002DN dependency to an exact declaration owner and verified generated destination. It rejects fake padding, IDA labels, opaque placeholders, partial formals, competing selected-entry declarations, and unsupported globals.
- Raw constructor repair is complete through the target-first validator/TMP sequence and is terminalized as UID0004WI.
- Keep UID0002EH as non-emitting generated switch data.
- Keep JsonCpp as external dependency and UID0002E4 as the entry parser.

## Recommended Target Doc Changes

Implementation status: all target changes below are incorporated and validated in the named target. The wording is retained as the accepted no-loss change specification.

- Target path: `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md`.
- Incorporate all C2E6 facts at report detail, including exact byte hash, current MCP provenance, category-case table, staged JsonCpp method mapping, entry constructor/lifetime, vector behavior, leak behavior, map lowering, rejected alternatives, and support implications.
- Metadata: applied `90/91`; owner `000051`, reconstructable true, emitter `000051` unchanged.
- Replace formal block exactly as above.
- Historicalize rather than delete:
  - prior indexed-key-table inference;
  - source-hygienic cleanup rationale;
  - custom lookup API/helper split;
  - wrong MapPane UID00042D crosslinks.
- Item Summary replacement:
  `Fresh B004 live-MCP/source audit resolves the exact switch, eleven key strings, by-value JsonCpp get and item-copy lifetimes, 0xc0 entry constructor semantics, pointer-vector append/copy, exact malformed-input leak behavior, and MSVC hash-container insert lowering; formal C++ now preserves binary behavior without indexed-table, memset, cleanup, or custom lookup API inventions.`

## Recommended Support Doc Changes

Implementation status: all accepted ordinary support changes below are incorporated and scoped-validated. Manual `-coverage-report.md` rows remain the complete supervisor-owned handoff, were not edited by B004, and are now present and supervisor-validated by commands16953 through16957.

- Stale `by-memory/0x004219f0-0x00421a20.FittingRoomCatalogEntryNoRouteInitializer.md`:
  - follow the exact rename/missing-UID/TMP/validation/readback sequence above; corrected path ends `0x00421a22`;
  - current validated state is `90/91`, owner/emitter UID000051, reconstructable true, with the exact covered-by formal and validator-owned UID0004WI;
  - preserve zero-xref/no-pointer evidence, 50-byte range, raw SHA, retained constructor role, negative evidence, and historical no-route conclusion;
  - remove every false MapPane UID00042D link without changing the real UID00042D page or validator mapping.
- UID0004WJ predecessor and UID0004WL parent:
  - preserve the validator-resolved UID0004WI raw-page link;
  - keep UID0004WL child range `[0x004219f0,0x00421a22)` and following padding `[0x00421a22,0x00421a30)`;
  - preserve the mixed-container/no-code disposition and all predecessor/parser/thunk facts.
- UID0002E4 parser:
  - add that caller passes a copied mutable Json value;
  - add constructor-established category and default-constructed `parts`;
  - replace the unsupported `SimpleUString::AssignAnsi`/`c_str` facade with exact `std::wstring` iterator-range construction;
  - copy each nested Json value and leave natural record padding untouched rather than value-initializing it;
  - parser field/layout evidence is preserved and the current scoped-validated score is `90/91` rather than the historical `87/90`.
- UID0002E5 part accessor:
  - replace the empty formal with the exact signed-index body above;
  - document upper-bound-only behavior, two nonnegative callers, inline `GetPartCount`, and naturally aligned six-byte record;
  - current scoped-validated score is `90/91` rather than the historical `86/91`.
- UID0002E7 constructor, UID0002EC reset, and UID0000WV accessors:
  - historicalize custom `Initialize`, `Clear`, `InitializeBuckets`, `FindNode`, sentinel/node API language;
  - replace IDA `Locale` with `""` and document the exact zero-storage/rdata proof;
  - apply the exact formals above using normal hash-container construction, iteration, `clear`/`rehash`, `find`, and iterator/value access;
  - preserve all exact behavior and address facts;
  - current scoped-validated scores are UID0002E7 `90/91`, UID0002EC `91/92`, and UID0000WV retained at `90/92`.
- UID0000WS selected-entry reset:
  - retain `FittingRoomDialogItemState::ResetEquipmentEntries()` and its exact vector-clear lowering, but replace the historical lifecycle-only `m_equipmentEntries.clear()` formal/body/prose with `m_selectedFittingItems.clear()`;
  - preserve the sole OnCommand caller, `+0x240/+0x244/+0x248` vector triple, `0xb4` stride, entry-tail cleanup, allocation guard, and `88/91` metadata.
- UID0002DI reset-scroll method:
  - retain all category-3 scan, special-preview, scroll child, invalidation, and `UpdateScrollBar()` behavior;
  - replace the invalid flattened `dialog->m_selectedFittingItems.begin/end` route with `FittingRoomDialogItemState* itemState = &dialog->m_itemState;` followed by `itemState->m_selectedFittingItems.begin()/end()`;
  - replace undeclared `m_specialSetPreviewMode` with the exact dialog `+0x49e` route `m_baseAppearance.m_compositionMode`;
  - apply the complete exact managed metadata/header/formal block above, not only these changed lines;
  - raise `88/91 -> 90/92`; the access is legal through the narrow item-state/list-pane friendship and the field already exists in UID00009S.
- UID0002DL paint:
  - retain its existing `itemState->m_selectedFittingItems`, `selected->catalogIndex`, and full paint body; these are the strongest current source spellings and the control against which the other pages are reconciled;
  - apply the complete exact managed metadata/header/formal block above; partial iterator/highlight excerpts are forbidden;
  - consume UID000053's proved `6`/`18` constants and UID0000D9's inline SSO-7 `MutableData()` route;
  - add the cross-page decision that the exact record fields are `name` and `catalogIndex`, not report-only `displayName`/`itemIndex`, and raise `88/91 -> 90/92`.
- UID0002DN input:
  - retain the exact event, hit-test, preview/equipment, child-delegation, and selected-entry behavior;
  - keep `newEntry.name` and `catalogIndex`, but replace every `dialog->m_selectedFittingItems` operation with `itemState->m_selectedFittingItems`;
  - replace undeclared `m_specialSetPreviewMode` with `m_baseAppearance.m_compositionMode`, preserve the signed-byte `GetPart` argument, and apply the complete exact managed metadata/header/formal block above rather than a selected-loop excerpt;
  - express selection construction, exact erase, overlapping-part erase, append, automatic temporary destruction, and all 15 part-code effects inline; do not declare the five former report helper names;
  - current scoped-validated score is `90/91` rather than the historical `88/90`; the direct item-state access is legal through the same narrow friendship and does not require an invented accessor.
- UID0002EB destructor:
  - preserve source-authored `ResetCategoryEntryLists()` body;
  - state trailing lookup destruction is compiler-generated member teardown and selected-vector destruction is the lifecycle of `m_selectedFittingItems`.
- UID0002UE selected-vector release:
  - preserve exact bounds, destructor caller, unwind metadata xref, `0xb4` range cleanup, allocation guard, triple clear, covered-by no-code formal, and `88/90`;
  - apply the complete exact metadata/header/covered-by formal above rather than a shortened comment placeholder;
  - change only the stale `m_equipmentEntries` source-facing role to `m_selectedFittingItems`, preserving the former name as a dated lifecycle-only assumption.
- UID0002U4/U8/U9/UB/UH/UI:
  - preserve detailed binary behavior;
  - reclassify as MSVC container specialization output;
  - set `RECONSTRUCTABLE:FALSE`, clear emitter/formal, and historicalize invented helper/type names.
- UID0000WW:
  - preserve exact resize/fill behavior and all callers;
  - reject DATIndexVector ownership based on fourteen unrelated callers;
  - reclassify as shared compiler vector/bucket machinery, no direct source emitter.
- UID000051:
  - the exact formal declaration is installed at emitter position `0`, with current scoped-validated score `90/91` rather than the historical `88/90`;
  - include direct Win32/Shell/CRT/C++03/JsonCpp headers rather than assuming a PCH, including `<string.h>` required by existing UID0002EF `strcpy_s`;
  - declare category enum/constants, naturally aligned part record, exact catalog entry with `name[0x55]`, category-taking inline constructor, part methods, vector/map aliases, exact selection entry fields `category/name/catalogIndex/partTypes`, all item-state methods, and exact field order;
  - name the item-state `+0x240` vector `m_selectedFittingItems`, historicalize `m_equipmentEntries`, and add only `friend class FittingRoomListPane;` so current direct list-pane operations are legal;
  - omit natural alignment bytes instead of emitting `reserved05`, `reserved09`, packed `reserved`, or `m_reserved24D`;
  - close the class before namespace-scope `[[CHILDREN]]`;
  - replace custom category lookup helper model with a byte-keyed standard hash-map member whose value is `std::vector<FittingRoomCatalogEntry*>`;
  - retain `m_categoryLookup` as the inferred project-consistent member name;
  - preserve all historical custom-helper work under a superseded-assumption section.
- UID0001UH:
  - replace the opaque `FittingRoomEquipmentEntry` placeholder with the live-proved `FittingRoomSelectionEntry` declaration route through UID000051;
  - preserve `0xb4` stride, category/`name`/`catalogIndex`/`vector<int>` offsets, reset/destructor evidence, same-storage `m_selectedFittingItems` identity, and historicalize the old opaque-prefix and `m_equipmentEntries` interpretations;
  - current scoped-validated score is `91/92` rather than the historical `86/89`; owner/emitter remain UID000051 and the formal remains blank/covered by UID000051 rather than duplicating the declaration.
- UID00004Z:
  - preserve the useful embedded-layout/reset support facts and its support-view status;
  - explicitly historicalize any implication of a standalone `FittingEquipmentState` object or second `m_equipmentEntries` vector; the live storage belongs to UID000051 as `m_selectedFittingItems`;
  - keep `85/89` ordinary metadata.
- UID000050:
  - replace the incomplete shared-declaration shell with the exact managed position-5 formal in this report;
  - preserve the established command enum/category-button declaration and add exact relative routes `CashShopRequest.h`, `../ui/core/DialogPane.h`, and `../map/ObjectStatusBlob.h`;
  - declare the full method inventory and exact field order: two 68-byte `ObjectStatusBlob` snapshots at `+0x47c/+0x4c0`, embedded UID000051 state at `+0x504`, active category/selected command/category-list state at `+0x784/+0x788/+0x78c`, `m_itemShopVersion` at `+0x790`, and `m_activeCatalogRequest` at `+0x7a8`;
  - add the exact `0x7ac` size guard, `g_pFittingRoomDialog` declaration, and narrow `friend class FittingRoomListPane;`;
  - historicalize the former "full class layout remains pending" conclusion; public-field promotion, convenience accessors, raw offsets, and synthetic padding remain rejected;
  - raise `87/89 -> 91/92`; exact original `m_categoryListState` lexical spelling remains a confidence cap rather than an undeclared-layout blocker.
- UID000053:
  - apply the complete position-10 formal with exact `../ui/core/ControlPane.h` and `../util/StringUtil.h` routes;
  - declare row page size `26`, grid page rows `3`, grid columns `6`, visible cells `18`, maximum scroll `30000`, and invalid slot `-1`;
  - synchronize the method inventory with the exact item-state route in UID0002DI/UID0002DL/UID0002DN and the `name`/`catalogIndex` selected-entry fields;
  - raise `88/90 -> 91/92`; narrow friendship is supplied by UID000050 and UID000051, not by an invented convenience API.
- UID0000D9:
  - preserve the complete SSO-7 constructor/destructor/Clear/Assign declaration and exact 24-byte union/length/capacity storage;
  - add only inline `MutableData()` selecting `m_heapBuffer` when `m_capacity > 7` and otherwise `m_inlineBuffer`, exactly matching UID0002DL's inlined storage gate;
  - retain the parser-only `AssignAnsi`/`c_str` rejection and the pointer-backed `StringBase` split caveat;
  - raise `88/88 -> 89/90`, owner/emitter UID0000OB unchanged.
- UID0000OB:
  - synchronize the StringUtil source root with the complete UID0000D9 formal and its UID0002DL consumer;
  - preserve the already-explicit `util/StringUtil.h` companion-header route, all current string-family ownership/split evidence, and `89/89`.
- UID0000IT DialogPane source root:
  - preserve `NexusTK/ui/core/`, complete class UID00003T, all existing file inventory/behavior evidence, and `92/94`;
  - add exact companion header `NexusTK/ui/core/DialogPane.h` as the compile-visible home for the existing UID00003T declaration consumed by UID000050.
- UID0000M6 ObjectStatusBlob source root:
  - preserve `NexusTK/map/`, complete class UID00009S, all exact 68-byte layout/parser/consumer evidence, and `90/91`;
  - add exact companion header `NexusTK/map/ObjectStatusBlob.h` as the compile-visible home for UID00009S consumed by UID000050.
- UID0000I0 CashShopRequest source root:
  - no ordinary edit; its Proposed Placement already names `cashshop/CashShopRequest.h`, and UID00001H already carries the complete declaration consumed by UID000050.
- UID0000IG ControlPane source root:
  - preserve `NexusTK/ui/core/`, complete class UID000038, all existing control-family evidence, and `90/92`;
  - add exact companion header `NexusTK/ui/core/ControlPane.h` as the compile-visible home for UID000038 consumed by UID000053.
- UID00004L/UID0000J6 Event:
  - no ordinary edit unless callback readback finds drift; the current complete Event/EventPayload/EventType formal and `NexusTK/ui/core/Event.cpp` route already supply `m_type`, `m_payload.m_pointer.m_y/m_x/m_detail`, `kEventLeftButtonUp`, and `kEventMouseWheel`;
  - UID000053 includes the existing Event header route and UID0002DN uses those exact names, never generated `EventType_LeftButtonRelease`/`EventType_MouseWheel` aliases.
- UID00004I/UID0000J4 EPFTileContext:
  - no ordinary edit unless drift is found; preserve the complete 0x28 class and source route;
  - UID0002DL uses automatic `EPFTileContext boardFrame`, `boardFrame.Initialize()`, and `boardFrame.bounds`, not an invented static `Construct`, `.source`, or duplicate frame record.
- UID0000BV/UID0000N3 Region:
  - replace UID0000BV's blank formal with the complete LObject-derived `Region` declaration from this report, including `RectBounds m_bounds`, constructor/destructor, and exact 0x14 size guard;
  - synchronize Region.cpp ownership in UID0000N3 without pruning Motion split/history evidence; UID0002DL uses a normal stack `Region savedClip`.
- UID00006E/UID0000K2/UID0000BY/UID0000QU ImageLib/resource-layout:
  - replace UID00006E's blank/incomplete singleton formal with the complete ImageLib declaration and evidence-backed `typedef ImageLib ResourceLayoutTable` facet route from this report;
  - synchronize ImageLib.cpp, ResourceLayoutTable class support, and `g_pEPFLib` global so UID0002DL calls `g_pEPFLib->LookupLayoutEntry(...)`; historicalize generated `g_pResourceMan` and unsupported independent-object interpretations while preserving raw no-this helper exclusions.
- UID0001UU/UID0000KH ItemObjImageLib:
  - apply the complete ItemObjImageLib declaration/formal from this report, retain direct LObject plus singleton base/layout evidence, member draw methods, typed `g_pItemObjImageLib`, and source-root one-definition policy;
  - retain `GetItemGlyphBounds` as the evidenced free/file-local helper because the binary does not pass an ItemObjImageLib receiver to that call; do not force every related operation into a member.
- UID00007B/UID0000KU LivingObjectPane:
  - preserve the complete 0x20c declaration and all existing fields/methods/history, adding only `class FittingRoomListPane;` plus narrow `friend class FittingRoomListPane;`;
  - synchronize LivingObjectPane.cpp source explanation so UID0002DN can legally read inherited `m_nameVisible` through `g_pUserPane`; reject generated `g_pGlobalState->fittingRoomInputLocked`.
- UID0000FQ/UID0000P1/UID0000QK/UID0001OR UserPane:
  - no ordinary edit unless drift is found; current complete UserPane declaration/source/global route already proves storage `0x0067a748` is `UserPane *g_pUserPane` and that inherited `m_nameVisible` occupies the tested byte.
- UID00005V/UID0000JR GrafPort, UID0000TN/UID0000OC Surface callbacks, and UID00015S/UID0000N2 geometry:
  - no ordinary edit unless drift is found; current docs already prove `m_visibleBounds`, `m_drawMode`, clip/text/tile methods, `g_pfnFillRect`, `Point { y, x }`, `InitPointPair`, `InitRectBounds`, and `PointInRect(y, x, bounds)`;
  - UID0002DL/UID0002DN must consume those exact declarations and reject generated aliases such as `SetBkColor`, `MeasureTextWidth`, static point/rect constructors, and reordered hit-test arguments.
- UID0000JE:
  - synchronize the same source model, declaration order, and exact validator-owned raw-page repair;
  - identify low-level helper bodies as compiler-generated, not separate FittingRoom functions; historicalize file-level `m_equipmentEntries` language and record the single `m_selectedFittingItems` item-state route plus narrow friendship;
  - keep `88/90` because the broad file includes unrelated incomplete FittingRoom classes.
- UID0002EF:
  - body and `89/91` metadata remain unchanged;
  - add only dependency evidence that its existing `strcpy_s` requires `<string.h>` in UID000051's direct declaration package.
- UID0000KI/UID0000WY: no metadata or source change; add only a consumer cross-reference if useful.
- UID0002EH: no change beyond confirming switch-source coverage.

## Score And Metadata Recommendation

- Current implemented result: completion 90, confidence 91, owner/emitter 000051, reconstructable true.
- The accepted `90/91` ceiling was applied only after all ordinary dependency destinations, raw UID/range repair, serial validators, and generated readback succeeded.
- Evidence supporting the implemented rise:
  - every named target behavior/source blocker was actively investigated;
  - current formal's six material defects are resolved;
  - exact hash/bounds and JsonCpp source snapshot are recorded;
  - entry constructor and failure ownership are resolved;
  - custom lookup helpers are correctly identified as compiler internals;
  - complete category/entry/map/selection/item-state declarations, direct external-header routes, and source order are implemented at exact destinations;
  - project include closure now maps UID0000I0/UID0000OB, UID0000IT/UID0000M6/UID0000IG, Event, EPFTileContext, Region, ImageLib/resource-layout, ItemObjImageLib, UserPane/LivingObjectPane, GrafPort, Surface callbacks, and geometry to concrete declaration/source owners;
  - selected-entry field names are reconciled to current consumer evidence as `name`/`catalogIndex`, and all reset/paint/input/lifecycle pages now have one `m_selectedFittingItems` storage interpretation;
  - narrow `FittingRoomListPane` friendship on the exact complete UID000051 and UID000050 declarations supplies a legal C++ access route without public fields, convenience accessors, or raw offsets;
  - `<string.h>` closes the direct declaration route for existing UID0002EF `strcpy_s`;
  - the unsupported parser `SimpleUString::AssignAnsi`/`c_str` facade and IDA `Locale` label are replaced by source-level standard/empty-string expressions, while the independently valid UID0002DL `SimpleUString` use is declaration-closed;
  - every fake padding/opaque storage placeholder is removed or resolved to concrete fields;
  - UID0002E5's former empty-emitter declaration/signedness blocker is closed;
  - the raw constructor has an exact target-first validator-owned allocation followed by one-page-at-a-time TMP replacement plan;
  - behavior-exact human source is implemented and generated-read-back.
- Reason current metadata does not exceed 90/91:
  - original local and typedef spellings are not recoverable;
  - `stdext::hash_map` versus equivalent project alias cannot be proven from symbols;
  - the raw-constructor identity/range is resolved, but it remains no-route covered-by evidence rather than independently called source;
  - `name[0x55]` is the strongest exact-layout human declaration, but the lost original capacity constant/name cannot be proven;
  - the exact original access-specifier spelling is lost, although narrow friendship is the strongest legal route for the observed direct private-member access;
  - textual generation and scoped validation confirm the accepted package, but no claim of recovered original symbol spelling or full product build is made;
  - the ImageLib/ResourceLayoutTable typedef spelling is a strong evidence-backed source-shape inference, not an original symbol recovery;
  - retained no-code compiler/container and covered-by pages intentionally remain empty emitters where source is represented by higher-level declarations/lifetimes.
- The behavioral, ownership, layout, source-placement, and direct-dependency investigations have explicit best-supported resolutions; the callback boundary and all 43 supervisor-owned manual coverage actions are complete; exact active-artifact Gate 1 and fresh Gate 2A passed SHA `E64983DE492480E142E10A179AAC1179FD3C1491F3B21F198A7C3D6C50026846`; and supervisor Gate 2B is `APPLIED_VERIFIED`. Supervisor-only `execute_report`/archive is authorized and remains outside B004's actor scope; validator-owned footer/registry state is the authoritative lifecycle record before and after archival.

## Open Questions With Attempted Resolution

Current status: every named source-quality question below has a documented resolution and the accepted implementation applies it. Remaining uncertainty is limited to lost original lexical spellings and is represented by the confidence score, not by unresolved compiler/IDA names or deferred investigation.

- Is the category mapping a table?
  - Checked target disassembly, table xref, case loads, and pointer accesses.
  - Resolution: no; source switch is best and directly supported.
- Are Json values const/referenced?
  - Checked exact wrapper targets and staged source.
  - Resolution: category is mutable and item is copied by value.
- Is whole-object zeroing source-real?
  - Checked every instruction from allocation to parser and raw constructor.
  - Resolution: no; source constructor initializes category and vector only.
- Should failure clean up entries?
  - Checked complete false branch and all callees/destructors.
  - Resolution: no. Exact executable leaks; source reconstruction must preserve it.
- Is `ReleaseCatalogEntryVector` called here?
  - Checked callee set and generated symbol use.
  - Resolution: no; remove from this method.
- Is `FittingRoomCategoryLookup::Insert` a source API?
  - Checked target lowering, object layout, helper bodies, diagnostic, hash, and caller spread.
  - Resolution: no direct evidence; normal standard hash-container insert is stronger.
- `stdext::hash_map` or `std::unordered_map`?
  - Checked `_Hash` object layout, source age, FNV, list/bucket implementation, and project history.
  - Resolution: best historical inference is `stdext::hash_map`, declared through source-quality alias `FittingRoomCategoryMap`; `std::unordered_map` is anachronistic for the target compiler/source era. A lost project typedef spelling remains possible but does not justify leaving the actual type undefined.
- Which enum/type/field declarations make the proposed bodies compile together?
  - Checked all current FittingRoom.cpp item-state method definitions, parser/accessor/list-input field use, exact object offsets, class-emitter conventions, generated source order, and every non-project API identifier.
  - Resolution: UID000051 supplies direct C++03/Win32/Shell/CRT/JsonCpp headers, 0..10 category enum/count, naturally aligned part record, 0xc0 catalog entry with category constructor, pointer-vector/map aliases, exact 0xb4 selection entry, complete 0x280 item-state fields/methods, and class closure before `[[CHILDREN]]` at emitter position 0.
- Is `SimpleUString` the source type used by UID0002E4?
  - Checked live helper `0x00423060`, its two callers, exact 24-byte SSO-7 layout, compiler diagnostic family, current UID0000D9 formal, and the generated parser expression.
  - Resolution: no source-quality evidence supports `AssignAnsi` or `c_str` on the project type, and those methods are undeclared. The UID0002E4 operation is represented exactly by C++03 `std::wstring(itemName.begin(), itemName.end())`; UID0002DL's separate counted-wide assignment remains valid and is closed by UID0000D9 `MutableData()`.
- What is constructor label `Locale`, and where is it declared?
  - Checked 38 xrefs and exact bytes at `0x0060d780`.
  - Resolution: it is IDA's name for leading zero/empty runtime storage immediately before `"string too long"`, not a source object. Emit `m_catalogVersion("")`; no declaration is needed.
- Which headers supply the platform and CRT calls?
  - Audited every identifier in UID0002E7 and the full proposed package.
  - Resolution: `<windows.h>` supplies core Win32 constants/functions, `<shlobj.h>` supplies Shell folder APIs/constants, `<stdio.h>` supplies FILE/file I/O, `<stdlib.h>` supplies allocation, `<string.h>` supplies existing `strcpy_s`, `<wchar.h>` supplies secure wide functions, and the listed C++03/JsonCpp headers supply all remaining types. No PCH assumption remains for the UID000051 package.
- Which project headers make UID000050/UID000053 compile-visible?
  - Audited source roots UID0000IT/UID0000M6/UID0000I0/UID0000IG/UID0000OB and complete declaration owners UID00003T/UID00009S/UID00001H/UID000038/UID0000D9, including assignment-time checkpoint hashes and then-existing Proposed Placement/Status text.
  - Resolution: UID0000I0 already records `cashshop/CashShopRequest.h`, and UID0000OB already records `util/StringUtil.h`. The callback adds exact companion-header paths `NexusTK/ui/core/DialogPane.h` to UID0000IT, `NexusTK/map/ObjectStatusBlob.h` to UID0000M6, and `NexusTK/ui/core/ControlPane.h` to UID0000IG, each linked to its existing complete class formal. FittingRoom then uses the exact relative include spellings in UID000050/UID000053. This is an explicit ordinary-document source route, not a claim that current generated `.cpp` artifacts already created headers.
- Is `Event` complete enough for UID0002DN?
  - Checked UID00004L/UID0000J6 formal/source, event constructors/producers, UID0002DN field reads, exact type values `3` and `7`, and payload coordinate/detail offsets.
  - Resolution: yes. Use `Event::m_type`, `Event::m_payload.m_pointer.m_y/m_x/m_detail`, `kEventLeftButtonUp`, and `kEventMouseWheel` from the existing complete Event header route. Generated `EventType_LeftButtonRelease` and `EventType_MouseWheel` are unsupported aliases.
- Is the UID0002DL frame local `EPFTileContext`, and how is it initialized?
  - Checked UID00004I/UID0000J4 size/layout, initializer body/callers, `bounds` consumers, and the live paint call sequence.
  - Resolution: automatic `EPFTileContext boardFrame; boardFrame.Initialize();` followed by `boardFrame.bounds` is the declaration-closed route. An invented static `EPFTileContext::Construct`, `.source`, or duplicate frame-record type is rejected.
- Is `Region` a complete stack type?
  - Checked Region vtable/lifecycle, LObject base, exact `RectBounds` storage at `+0x04`, 0x14 object size, GrafPort clip APIs, and UID0002DL stack construction/destruction.
  - Resolution: UID0000BV receives the complete `class Region : public LObject` formal and UID0000N3 owns the source. UID0002DL uses `Region savedClip`; an opaque forward declaration is insufficient for stack allocation.
- What is `g_pResourceMan`, and what type supplies the layout lookup?
  - Checked every write/clear/xref to `0x0067a744`, ImageLib RTTI/vtable/lifecycle, the shared `List` at `+0x0c`, ResourceLayout method receivers, UID0002P6, and raw no-this helper exclusions.
  - Resolution: generated `g_pResourceMan` is invalid. The storage is `ImageLib *g_pEPFLib`; the strongest source closure is a complete ImageLib declaration exposing the non-virtual resource-layout methods plus `typedef ImageLib ResourceLayoutTable`. UID00006E/UID0000K2/UID0000BY/UID0000QU are the implemented destinations. The typedef spelling remains an inference cap, but no compiler/IDA label remains in current generated source.
- Which `ItemObjImageLib` APIs are members?
  - Checked the receiver register at each UID0002DL call, UID0001UU layout/formal evidence, UID0000KH source route, global lifetime, and the glyph-bounds helper call ABI.
  - Resolution: draw calls carrying `g_pItemObjImageLib` as receiver remain ItemObjImageLib members. `GetItemGlyphBounds` receives no ItemObjImageLib object and remains a free/file-local helper. UID0001UU/UID0000KH receive the complete mixed member/free declaration route rather than a convenience all-member API.
- What is generated `g_pGlobalState`, and how can UID0002DN legally test the byte?
  - Checked `0x0067a748` global identity, UID0000FQ/UID0000P1 UserPane lifecycle, UID00007B inherited layout at `+0x1d1`, every direct `m_nameVisible` consumer, and legal access alternatives.
  - Resolution: use `g_pUserPane->m_nameVisible`; the global is `UserPane *`, and the byte is inherited `LivingObjectPane::m_nameVisible`. Add only narrow `FittingRoomListPane` friendship to UID00007B/UID0000KU. Reject `g_pGlobalState`, `fittingRoomInputLocked`, invented getters, and raw offsets.
- Which rendering/geometry APIs close UID0002DL/UID0002DN?
  - Checked GrafPort exact fields/methods, Surface callback slot 7, Point/Rect helper ABIs, and the paint/input call sites.
  - Resolution: use `m_visibleBounds`, `m_drawMode`, `GetClipRegion`, `SetClipRect`, `SetClipRegion`, `SetTextColor`, `GetTextWidth`, `RenderTileFrame`, `g_pfnFillRect`, `Point { y, x }`, `InitPointPair`, `InitRectBounds`, and `PointInRect(y, x, bounds)`. UID00005V/UID0000JR, UID0000TN/UID0000OC, and UID00015S/UID0000N2 already carry the declaration evidence and are mandatory callback readbacks.
- Are the `reserved*` members source-real?
  - Checked every parser/list-input/constructor/reset/destructor access and 32-bit alignment boundary.
  - Resolution: no. Part byte +1, catalog bytes +5/+9, item-state bytes +0x24d..+0x24f, and selection bytes +0xa6..+0xa7 are natural alignment. The former opaque +0..+0xa7 selection prefix resolves to category/`name`/`catalogIndex`, and its trailing vector is `vector<int>`.
- Which selected-entry field names should the source declaration use?
  - Checked current UID0002DL and UID0002DN formals, live `0x0041f2b0` and `0x0041fcd0` consumers, bounded copy at entry `+4`, signed comparison at `+0xa4`, and all report aliases.
  - Resolution: use `name` and `catalogIndex`. They are already the convergent emitted spellings and directly describe the copied display text and catalog lookup index. `displayName` and `itemIndex` remain historical weaker report aliases only.
- Are `m_equipmentEntries` and `m_selectedFittingItems` different vectors?
  - Checked dialog-relative `+0x744/+0x748/+0x74c`, item-state-relative `+0x240/+0x244/+0x248`, constructor `0x00422020`, reset `0x0041d5e0`, paint `0x0041f2b0`, input `0x0041fcd0`, destructor `0x00422330`, and release helper `0x00423870`.
  - Resolution: no. Every route reaches the same `0xb4`-stride selected-entry vector. Use `FittingRoomDialogItemState::m_selectedFittingItems`; preserve `m_equipmentEntries` only as the earlier lifecycle-role assumption.
- How may `FittingRoomListPane` legally reach the selected vector and dialog fields?
  - Checked the current direct field expressions, class ownership, exact dialog/item-state offsets, source-emitter positions, UID000050/UID000051/UID000053 formals, and alternatives that would alter source shape.
  - Resolution: UID000051 position `0` and complete UID000050 position `5` each declare narrow `friend class FittingRoomListPane;` before UID000053 position `10`. UID0002DI/UID0002DN use existing `m_baseAppearance.m_compositionMode` and all three list methods use `m_itemState`/`m_activeCategory` through that friendship. Publicizing fields, adding convenience getters, or expressing raw offsets would be unsupported inventions.
- Where are the grid constants declared?
  - Checked UID0002DL/UID0002DM instructions, sibling scroll docs, current UID000053 formal, and file/source ownership.
  - Resolution: UID000053 receives the complete formal with columns `6`, visible cells `18`, row page size `26`, grid page rows `3`, and maximum scroll `30000`; the first two values are exact UID0002DL immediates rather than report conveniences.
- Are the five UID0002DN helper names source-real?
  - Checked the full target body, direct callee set, vector helper lowerings, temporary lifetime, overlap loops, part switch, and pointer/xref evidence.
  - Resolution: no. The observed operations are inline C++03 source/container lowering. The complete UID0002DN formal now performs them directly and applies all observed part cases to current UID00009S fields.
- How does UID0002DL obtain writable SimpleUString storage?
  - Checked the proven UID0000D9 SSO-7 layout, counted Assign endpoint, UID0002DL capacity gate, and inline/heap pointer selection.
  - Resolution: inline `SimpleUString::MutableData()` exactly expresses that inlined gate without adding parser-only methods or altering the 24-byte layout.
- Is UID000050 still an unresolved declaration dependency?
  - Checked the `DialogPane` inherited boundary, exact `+0x47c..+0x7ac` field map, constructor/method consumers, two 68-byte appearance copies, UID000051 size, MSVC string size, final request pointer, and emitter order.
  - Resolution: no. The exact managed formal in this report supplies direct project headers, complete method declarations, exact field order, `0x7ac` guard, singleton declaration, and position `5`. The only remaining uncertainty is the source spelling `m_categoryListState`, which is a confidence cap and does not leave storage unnamed or the class incomplete.
- Are the five selected-entry support C++ changes callback-ready?
  - Checked every current managed block in UID0000WS, UID0002DI, UID0002DL, UID0002DN, and UID0002UE against the proposed field/declaration route.
  - Resolution: yes. This report contains each destination's complete metadata header and complete formal body/comment. No excerpt, ellipsis, "preserve body" placeholder, or prose-only substitution remains.
- What occupies catalog-entry `+0xaa..+0xb3`?
  - Checked the exact +0x0a name start, +0xb4 vector start, 0x50 operational safe-copy bound, and every direct target-family consumer.
  - Resolution: no separate semantic field is observed. `wchar_t name[0x55]` is the ordinary human declaration that exactly fills the backing region; 0x50 remains the explicit copy limit. This inferred lost capacity constant caps confidence at 93.
- Is the catalog-entry constructor allowed to initialize missing scalar fields for safety?
  - Checked both the live inlined sequence and retained raw constructor.
  - Resolution: no. Only category and `parts` construction are source-real. Initializing `enabled`, `tile`, `color`, name, or natural padding would alter exact uninitialized-state behavior before parser assignment.
- Can UID0002E5 remain blank after the declarations are supplied?
  - Checked the exact 0x3c body, sign extension, upper-bound comparison, and two callers.
  - Resolution: no. Its former blockers are closed; the report supplies exact `GetPart(signed char) const` C++ and inline `GetPartCount`.
- What is the raw constructor's exact range/role?
  - Checked disassembly, bytes, xrefs, and pointer patterns.
  - Resolution: `[0x4219f0,0x421a22)`, retained no-route out-of-line constructor-shaped body covered by UID000051/UID0002E6 source. The exact rename, duplicate-header removal, target-first UID allocation, one-page-at-a-time five TMP reference validations, readback postconditions, and manual-row terminalization are specified above.
- Which UID replaces the invalid duplicate UID00042D?
  - Checked current registry/ordinary references and validator UID/TMP documentation.
  - Resolution: validator target-first allocation assigned UID0004WI to the corrected raw page. UID0004WJ/UID0004WL/UID0004WK are the canonical predecessor/parent/adjustor identities; UID00042D remains MapPane-only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Timestamped pre-callback roots inspected (`2026-07-23T05:23:11-04:00` tracker epoch unless a row-specific hash is shown). These hashes/line anchors are historical comparison checkpoints; the exact replacement text remains the supervisor-owned manual handoff. Validator-owned footer/registry state is authoritative for lifecycle whenever present.

- `by-memory/-coverage-report.md`: SHA `84FE8E12DAE83256F8E73A7DE73EFEFF16365F6D54773F1A4B92496F32235BF0`, 1,997,357 bytes, 4,580 lines; current affected anchors are UID0000WS line 162, UID0002DI line 195, UID0002DL line 201, UID0002DN line 205, UID0002E4 line 250, UID0002E5 line 252, UID0002E6 line 271, and UID0002UE line 299.
- `by-class/-coverage-report.md`: SHA `1ABA81ABD9D25F28C0F43052724927A61D58339CD7672622F6FF54AB100B070B`, 258,407 bytes, 624 lines; current affected anchors are UID00004Z line 204, UID000050 line 205, UID000051 line 206, UID000053 line 208, UID00006E line 255, UID00007B line 287, UID0000BV line 450, UID0000BY line 453, and UID0000D9 line 499.
- `by-file/-coverage-report.md`: SHA `FA46E74105C0E81FD14E3B3FD56745E2C05F654F78B48F906E2107C65020D612`, 155,316 bytes, 317 lines; current affected anchors are UID0000I0 line 44, UID0000IG line 60, UID0000IT line 74, UID0000JE line 95, UID0000K2 line 119, UID0000KH line 134, UID0000KU line 147, UID0000M6 line 195, UID0000N3 line 228, and UID0000OB line 273. UID0000I0 is inspected evidence with an already-explicit header route and needs no replacement; UID0000IG/UID0000IT/UID0000M6 receive exact companion-header handoffs and the added dependency source roots receive exact no-loss handoffs below.
- `by-type/by-struct/-coverage-report.md`: SHA `EBA8BEFBA2A51A97B2091D16B4043C43A08B1446B5684D22B25AA080EFCC7B07`, 58,525 bytes, 137 lines; UID0001UH row line 49 and UID0001UU row line 62.
- `by-global/-coverage-report.md`: SHA `A8089C99BEAC6A154F3FDA437E0AAA70A6188EDD6AC5BC4CC98E953ADBF5FA9A`, 99,613 bytes, 217 lines; UID0000QU row line 84.
- `auto-generated/-ag-research-tracker.md`: assignment-time command `000000016821`, refreshed `2026-07-23T05:23:11-04:00`, source `deferred-generated-refresh`, SHA `CDEAD87AEB6EA445E93351880F0CE149B80CA6CEE7AB44DA478683276DC34F82`, 1,637,932 bytes, 6,514 lines; UID0002E6 was line 1674 at `87/89`, combined `88.0`, reconstructable true, and zero report counts. This is a historical queue snapshot. B004 did not edit the tracker; the validator-owned registry/footer and regenerated tracker are authoritative.

Supervisor-only no-loss replacements:

1. Replace current by-memory UID0002E6 line 271 with:

```text
            - [UID:0002E6][0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson](by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md) 0x00422ba0-0x00422e91 | method | FittingRoomDialogItemStateLoadCategoryFromJson : reconstructable : 90% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); fresh B004 live-MCP/source audit confirms exact 0x2f1 bounds and SHA A67857467CC82D78BFFA6B42CCB93A2A484544E67706856F36A57357604E79E1, sole UID0002E9 caller, direct eleven-case category switch/string loads, by-value JsonCpp get and item-copy lifetimes, 0xc0 source-constructor setup, pointer-vector append/copy, exact malformed-input leak behavior, byte-keyed MSVC hash-container insert lowering, generated switch-table boundary, direct dependency/header closure, natural data layouts, and behavior-exact formal C++ without indexed-table, memset, cleanup, custom lookup APIs, fake padding members, or IDA labels; command16927 generated readback confirms the callback package.
```

2. Replace UID0002E4 line 250 with:

```text
            - [UID:0002E4][0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson](by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md) 0x00421a40-0x00421fd8 | parser helper | FittingRoomCatalogEntryFromJson : reconstructable : 90% : strong : Parses one copied mutable JsonCpp item value into a compile-visible 0xc0-byte FittingRoomCatalogEntry after the source constructor establishes category +0x00 and default-constructs the naturally aligned part vector at +0xb4/+0xb8/+0xbc; exact range, sole UID0002E6 caller, `std::wstring` narrow-range conversion, 0x50 bounded name copy into the 0x55 backing array, nested copied Json values, six-byte part appends with natural byte +1 padding left untouched, reject sentinels, and the direct UID000051 header/declaration route remain documented.
```

3. Replace UID0002E7 line 254 with:

```text
            - [UID:0002E7][0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor](by-memory/0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md) 0x00422020-0x0042232a | constructor | FittingRoomDialogItemStateConstructor : reconstructable : 90% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); exact 0x30a bounds, embedded-dialog caller at +0x504, strings/cache path, file read/transform/parse, success flag, cleanup, and padding remain preserved. Fresh B004 declaration/container audit resolves IDA `Locale` as the empty-string storage used by `m_catalogVersion("")`, supplies direct Win32/Shell/CRT headers including `<string.h>` for sibling UID0002EF `strcpy_s`, makes the body compile against exact 0x280 item-state fields, identifies the +0x240 vector as `m_selectedFittingItems`, and historicalizes body-level Initialize(8) and selected-vector clear calls because the observed map/vector setup is compiler-emitted default member construction; former `m_equipmentEntries` wording remains dated lifecycle history only.
```

4. Replace UID0002EB line 256 with:

```text
            - [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) 0x00422330-0x0042246f | destructor | FittingRoomDialogItemStateDestructor : reconstructable : 87% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); exact 0x13f bounds, scalar-deleting caller, source-authored ResetCategoryEntryLists call, encode/decode/catalog string teardown, selected-entry vector teardown at +0x240, and padding remain preserved. Fresh B004 audit identifies that vector as `m_selectedFittingItems`, preserves `m_equipmentEntries` as historical lifecycle-only wording, and classifies the following +0x220 hash-storage destructor/free sequence as compiler-generated standard-container member teardown rather than a custom hand-authored lookup helper.
```

5. Replace UID0002EC line 258 with:

```text
            - [UID:0002EC][0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries](by-memory/0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries.md) 0x00422470-0x0042259a | method | FittingRoomDialogItemStateResetCategoryEntries : reconstructable : 91% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); exact 0x12a bounds, destructor/action/test-loader callers, copied category vectors, per-entry parts destruction and 0xc0 delete, aligned temporary-buffer cleanup, container clear, eight-bucket rehash, and padding remain preserved. Fresh B004 source audit replaces reverse-engineered sentinel/Clear/InitializeBuckets APIs with compile-visible FittingRoomCategoryMap iteration, clear, and rehash source.
```

6. Replace UID0000WV line 262 with:

```text
            - [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md) 0x00422690-0x0042273f | method pair | FittingRoomDialogItemStateCategoryLookupAccessors : reconstructable : 90% : strong : Live IDA-backed item-state count/index methods retain exact split boundaries/padding, ten fitting-room callers, +0x504 receiver proof, byte-keyed category lookup, copied entry-vector behavior, signed index comparison, and historical ItemCatalog facade provenance. Fresh B004 source audit replaces inferred custom FindNode/sentinel APIs with compile-visible FittingRoomCategoryMap find/end and iterator-value access; scoped validation confirms retained `90/92` metadata.
```

7. Replace UID0002U4 line 276 with:

```text
            - [UID:0002U4][0x00423000-0x0042305c.FittingRoomCategoryLookupInsertNode](by-memory/0x00423000-0x0042305c.FittingRoomCategoryLookupInsertNode.md) 0x00423000-0x0042305c | compiler-generated container helper | MSVC hash/list node value construction specialization : non-reconstructable : 88% : strong : Semantically attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) and retained under mixed address aggregate [UID:0002EE][0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers](by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md); exact 0x5c body, sole UID0002E6 insertion caller, 24-byte list-node allocation, byte-key plus vector-payload transfer, source-triplet clear, retn 0x0c, and padding remain preserved as binary evidence. Fresh B004 source audit supersedes the former hand-authored CreateFittingRoomCategoryLookupNode API and routes source through UID0002E6 standard hash-container insert plus UID000051 member declaration, with no direct helper emitter.
```

8. Replace UID0002U8 line 284 with:

```text
            - [UID:0002U8][0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize](by-memory/0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize.md) 0x00423470-0x0042365d | compiler-generated container helper | MSVC hash insert/finalize specialization : non-reconstructable : 88% : strong : Exact 0x1ed body, UID0002E6 and recursive rehash callers, one-byte FNV-1a duplicate handling, list/bucket endpoint repair, load-factor growth, rehash, exception cleanup, and padding remain preserved; fresh B004 source audit supersedes the custom FittingRoomCategoryLookup::FinalizeInsert source API and leaves regeneration to UID0002E6 standard-container insertion.
```

9. Replace UID0002U9 line 286 with:

```text
            - [UID:0002U9][0x00423660-0x004236d7.FittingRoomCategoryLookupEraseNode](by-memory/0x00423660-0x004236d7.FittingRoomCategoryLookupEraseNode.md) 0x00423660-0x004236d7 | compiler-generated container helper | MSVC hash erase-node specialization : non-reconstructable : 88% : strong : Exact 0x77 body, hash-bucket endpoint repair, intrusive-list unlink, node-count decrement, successor result, payload/node destruction, caller, and padding remain preserved; fresh B004 source audit supersedes the custom FittingRoomCategoryLookup::EraseNode source API and clears direct source emission.
```

10. Replace UID0002UB line 289 with:

```text
            - [UID:0002UB][0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper](by-memory/0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md) 0x00423710-0x00423777 | compiler-generated container helper | MSVC hash-container destructor specialization : non-reconstructable : 88% : strong : Item-state destructor caller, thunk xref, aligned bucket-vector free guard, triple clear, list/node destruction, 24-byte sentinel release, exact boundaries, and padding remain preserved as UID000051 member-lifecycle evidence; no standalone hand-authored source emitter is required.
```

11. Replace UID0002UH line 305 with:

```text
              - [UID:0002UH][0x00423a60-0x00423a8d.CategoryTreeSentinelAllocator](by-memory/0x00423a60-0x00423a8d.CategoryTreeSentinelAllocator.md) 0x00423a60-0x00423a8d | compiler-generated container helper | MSVC list-node allocator specialization : non-reconstructable : 88% : strong : Exact 0x2d body, item-state-container constructor and insertion callers, operator-new dependency, 24-byte sentinel/ordinary-node link setup, no source-name symbols, and padding remain preserved; fresh B004 source audit supersedes AllocateFittingRoomCategoryNode as a hand-authored FittingRoom helper.
```

12. Replace UID0002UI line 307 with:

```text
              - [UID:0002UI][0x00423a90-0x00423af4.CategoryTreeNodeCleanupFree](by-memory/0x00423a90-0x00423af4.CategoryTreeNodeCleanupFree.md) 0x00423a90-0x00423af4 | compiler-generated container helper | MSVC list-node/vector-payload destroy specialization : non-reconstructable : 88% : strong : Exact 0x64 body, hash insert/erase callers, payload-vector aligned free/clear contract, fixed 24-byte node release, and padding remain preserved; fresh B004 source audit supersedes DestroyFittingRoomCategoryNode as a hand-authored FittingRoom helper.
```

13. Replace by-class UID000051 line 206 with:

```text
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) : reconstructable : 90% : strong : Embedded 0x280 item-shop cache/catalog state owned by [UID:0000JE][FittingRoom](by-file/FittingRoom.md); position-0 formal declares direct C++03/Win32/Shell/CRT/JsonCpp headers including `<string.h>` for existing UID0002EF `strcpy_s`, exact 0..10 category enum/count, naturally aligned six-byte part record with signed part code and no fake padding member, 0xc0 catalog entry with 0x55-wide backing name and category-taking constructor, vector/map aliases, exact 0xb4 FittingRoomSelectionEntry fields `category/name/catalogIndex/partTypes`, complete item-state methods/fields without synthetic alignment members, narrow `FittingRoomListPane` friendship, and class closure before namespace-scope children. Exact constructor/destructor/reset/load/accessor children, standard UID0002E4 wide-string parser route, valid UID0002DL SSO-7 SimpleUString route, empty catalog-version literal, JsonCpp consumption, persistence keys/path, byte-keyed category storage, and the single +0x240 `m_selectedFittingItems` reset/paint/input/destructor lifecycle remain documented; former `m_equipmentEntries` wording is historicalized. Mixed aggregate [UID:0002EE][0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers](by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md) stays non-emitting; prior custom node/finalize/erase/allocator APIs are historical compiler-generated member machinery. Full direct-dependency callback validation confirms the retained 90/91 ceiling.
```

14. Replace by-file UID0000JE line 95 with:

```text
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md) : reconstructable : 88% : strong : NexusTK/cashshop/FittingRoom.cpp owns the dialog, list/scroll panes, embedded item-state cache/catalog, download controls, fitting equipment, and exact source-bearing children. Exact vector children [UID:00030R][0x00420ef0-0x00421143.FittingRoomSelectionEntryVectorGrowInsert](by-memory/0x00420ef0-0x00421143.FittingRoomSelectionEntryVectorGrowInsert.md) and [UID:00030T][0x00421150-0x0042122b.FittingRoomSelectionEntryMoveConstructRange](by-memory/0x00421150-0x0042122b.FittingRoomSelectionEntryMoveConstructRange.md) remain routed through [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), while [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md) and [UID:0002EE][0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers](by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md) remain unassigned/non-emitting mixed address aggregates. Fresh B004 UID0002E6 audit adds behavior-exact category loading with a direct eleven-case JSON-key switch, copied JsonCpp item values, FittingRoomCatalogEntry(category) construction, exact malformed-input leak behavior, standard byte-keyed hash-container insertion, direct platform/CRT/JsonCpp header closure including `<string.h>`, standard UID0002E4 wide-string name conversion, valid UID0002DL SimpleUString SSO-7 text wrapping, empty catalog-version literal, natural signed part/catalog/item-state layout, exact grid constants, and exact FittingRoomSelectionEntry `category/name/catalogIndex/partTypes` fields. UID000051 position 0, complete 0x7ac FittingRoomDialog UID000050 position 5, and complete UID000053 position 10 establish dependency-safe declaration order with direct project headers and narrow list-pane friendship; UID0002DI/UID0002DN use existing `m_baseAppearance.m_compositionMode`, and UID0002DN expresses vector and 15-code part-switch operations inline rather than through fabricated helpers. The five affected reset/paint/input/release pages receive complete destination formals rather than excerpts. The same +0x240 item-state vector is `m_selectedFittingItems` across reset/paint/input/destructor support; former `m_equipmentEntries`, parser-only SimpleUString facade, IDA Locale, reserved placeholders, and custom category-node/finalize/erase/allocator helper source are preserved only as historical rejected/compiler-generated evidence.
```

15. UID0000WW line 309 needs a supervisor replacement after its own ordinary metadata is changed:

```text
        - [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) 0x00423b00-0x00423c3d | compiler-generated vector helper | MSVC paired-iterator bucket-vector resize/fill specialization : non-reconstructable : 88% : strong : Exact bounds, fourteen fitting-room/minimap/DAT/monster-image callers, paired-DWORD resize/fill behavior, allocator/length-error paths, and final mask/count writes remain preserved; the cross-subsystem caller set and UID0002E6 hash-container use reject former DATIndexVector source ownership and direct emission.
```

16. Replace by-memory UID0002E5 line 252 with:

```text
            - [UID:0002E5][0x00421fe0-0x0042201c.FittingRoomCatalogEntryPartLookup](by-memory/0x00421fe0-0x0042201c.FittingRoomCatalogEntryPartLookup.md) 0x00421fe0-0x0042201c | helper method | FittingRoomCatalogEntryPartLookup : reconstructable : 90% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); live IDA confirms exact 0x3c boundary, no callees, two list-input call sites, naturally aligned six-byte part-record count/stride, signed-byte index extension, upper-bound-only comparison, and direct begin-plus-index result. Fresh B004 declaration closure supplies the compile-visible FittingRoomCatalogPartRecord without a fake byte +1 member and exact GetPart(signed char) const formal without adding a behavior-changing lower-bound test.
```

17. Replace by-type/by-struct UID0001UH line 49 with:

```text
- [UID:0001UH][FittingEquipmentStateLayout](by-type/by-struct/FittingEquipmentStateLayout.md) : reconstructable : 91% : strong : Embedded layout evidence attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md): exact item-state selected-entry vector offsets +0x240/+0x244/+0x248 and 0xb4 entry stride remain preserved. Fresh live paint/input/reset/lifecycle analysis resolves the entry as FittingRoomSelectionEntry with category +0, wchar_t `name[0x50]` +4, signed `catalogIndex` +0xa4, natural alignment +0xa6, and std::vector<int> `partTypes` +0xa8/+0xac/+0xb0; constructor initialization, command-time reset, destructor-time range/storage release, complete 0x280 item-state order, and historical rejection of the opaque-byte-prefix and separate `m_equipmentEntries` interpretations remain documented. The single source member is `m_selectedFittingItems`.
```

18. Immediately before current by-memory line 249 (`UID0000WU`), insert the currently absent UID0004WJ predecessor row:

```text
        - [UID:0004WJ][0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute](by-memory/0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md) 0x00421860-0x004219e1 | retained no-route parser | FittingRoomCatalogPartRecordLoadFromJsonNoRoute : reconstructable : 88% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); exact 0x181 body, SHA D3648D01BE4EF864A9083851938380C93F5698954AD8143F3F09EE983CA641E1, JsonCpp part/tile/color/gender extraction, naturally aligned six-byte record offsets +0/+2/+4/+5 with untouched byte +1 padding, reject sentinels, zero inbound code/data/pointer/immediate routes, and no-code disposition remain preserved. Fresh B004 closure supplies the source-visible FittingRoomCatalogPartRecord through UID000051 and corrects the following raw-constructor child reference to UID0004WI without inventing a call edge or duplicate parser body.
```

19. Immediately after the new UID0004WJ row and before current UID0000WU, insert the currently absent UID0004WL parent row:

```text
        - [UID:0004WL][0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail](by-memory/0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md) 0x004219e1-0x00421a40 | split/container aggregate | FittingRoomCatalogEntryNoFunctionTail : reconstructable : 88% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); exact 0x5f mixed tail and SHA CCCD81280EC943785D4B516C0AEAD8EF14F6E9935FED25707CC6ACDCAFF94928 retain leading/following padding, the corrected [0x004219f0,0x00421a22) UID0004WI no-route category-entry constructor body, the UID0004WK adjustor thunk at 0x00421a30, and the active UID0002E4 parser boundary at 0x00421a40. Fresh B004 closure corrects the constructor child end and following padding start to 0x00421a22, rejects the false UID00042D identity, and preserves blank aggregate C++ because exact source is emitted by UID000051 declarations and UID0002E6 construction.
```

20. Insert the raw constructor row directly beneath the canonical parent row using validator-allocated UID0004WI:

```text
            - [UID:0004WI][0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer](by-memory/0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer.md) 0x004219f0-0x00421a22 | retained no-route constructor | FittingRoomCatalogEntryNoRouteInitializer : reconstructable : 90% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); exact 50-byte body and SHA FBC2EE41D0B082CDCCFC0598B2586F6CFAA20CEA4A03B499AD9D28A2D50DB91 initialize only category +0x00 and default-construct the naturally aligned part vector at +0xb4/+0xb8/+0xbc, matching UID0002E6's live inlined new-expression setup. Zero modeled-function/xref/code/data/immediate/VA/RVA pointer routes preserve retained covered-by/no-route status; source is emitted by the UID000051 FittingRoomCatalogEntry(FittingRoomCatalogCategory) constructor declaration and UID0002E6 new-expression, not as a duplicate standalone body. Historical duplicate UID00042D belonged to MapPane and is rejected; corrected range and following padding begin at 0x00421a22.
```

21. Replace current by-memory UID0000WS line 162 with:

```text
        - [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) 0x0041d5e0-0x0041d671 | method | FittingRoomDialogItemStateResetEquipmentEntries : reconstructable : 88% : strong : Source-ready FittingRoomDialogItemState::ResetEquipmentEntries() attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); exact 0x92 body, sole OnCommand caller with dialog item-state receiver +0x504, vector fields +0x240/+0x244/+0x248, 0xb4 entry stride, per-entry tail cleanup +0xa8/+0xac/+0xb0, MSVC large-allocation guard, and end=begin reset remain preserved. Fresh B004 cross-consumer audit identifies the same storage used by list reset/paint/input as `m_selectedFittingItems`; formal source is `m_selectedFittingItems.clear()`, while former `m_equipmentEntries` and standalone FittingEquipmentState interpretations remain historical support labels rather than a second vector or source owner.
```

22. Replace current by-memory UID0002DI line 195 with:

```text
        - [UID:0002DI][0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition](by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md) 0x0041f100-0x0041f219 | method | FittingRoomListPaneResetScrollPosition : reconstructable : 90% : very strong : Exact source-ready FittingRoomListPane::ResetScrollPosition method with modeled 0x119 bounds, sole FittingRoomDialogOnCommand caller, category-3 selected-entry scan at 0xb4 stride, special-preview byte handling, list and owned-child m_scrollPosition reset, conditional child invalidation, UpdateScrollBar, preserved duplicate list invalidation, vector-subscript throw support, no pointer route, adjacent padding, FittingRoomListPane/FittingRoom source route, and formal C++. Fresh B004 storage audit corrects the flattened dialog vector expression to `FittingRoomDialogItemState* itemState = &dialog->m_itemState` followed by `itemState->m_selectedFittingItems`; dialog +0x49e resolves to the existing `m_baseAppearance.m_compositionMode` union field; narrow FittingRoomDialog/FittingRoomDialogItemState friendship permits the observed direct accesses without an invented accessor, field, or raw offset.
```

23. Replace current by-memory UID0002DL line 201 with:

```text
        - [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md) 0x0041f2b0-0x0041fb9b | method | FittingRoomListPaneOnPaint : reconstructable : 90% : strong : Exact source-ready virtual paint handler with modeled bounds, vtable reachability and no ordinary direct callers, adjacent padding, tiled board background, clip save/intersection/restore, enabled-item scan, visible cells, selected/cart highlights, item icons, wrapped names, resource/global dependencies, callee set, and FittingRoomListPane/FittingRoom source route remain preserved. Fresh B004 live-consumer audit confirms the item-state `m_selectedFittingItems` route, exact 0xb4 FittingRoomSelectionEntry fields `category`, `name[0x50]`, signed `catalogIndex`, natural alignment, and `vector<int> partTypes`, a legal C++03 vector iterator, exact six-column/eighteen-cell constants declared by UID000053, and the valid UID0000D9 counted-wide `SimpleUString` plus inline SSO-7 `MutableData()` route; former `displayName`/`itemIndex` and parser-only `AssignAnsi`/`c_str` aliases are historicalized without rejecting the paint-time SimpleUString use.
```

24. Replace current by-memory UID0002DN line 205 with:

```text
        - [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md) 0x0041fcd0-0x004207ce | method | FittingRoomListPaneOnInputEvent : reconstructable : 90% : very strong : Exact source-ready virtual FittingRoomListPane::OnInputEvent method with 0xafe boundary, vtable-only reachability and no ordinary direct callers, event type 3 selection/cart flow, event type 7 mouse-wheel flow, singleton/global dependencies, visible-slot and catalog-index validation, exact 0xb4 selected-entry layout, item-part preview/equipment side effects, current m_scrollPosition/m_scrollRange callback path, delegated child handling, adjacent compiler jump-table tail UID0002DO, FittingRoomListPane/FittingRoom source route, and complete formal C++ remain preserved. Fresh B004 live audit retains `name`/`catalogIndex`, routes all selected-vector operations through `itemState->m_selectedFittingItems`, resolves dialog +0x49e to `m_baseAppearance.m_compositionMode`, reconstructs the exact-match erase, overlapping-part erase, append, automatic temporary destruction, and 15-code ObjectStatusBlob part switch inline as plausible C++03, and closes Event/UserPane/ImageLib/ItemObjImageLib/GrafPort/Surface/geometry declaration routes; five former report helper names and generated global/API aliases are historicalized because no direct callee/declaration route exists.
```

25. Replace current by-memory UID0002UE line 299 with:

```text
            - [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md) 0x00423870-0x004238e3 | helper-function | FittingRoomDialogItemStateSelectedEntriesRelease : reconstructable : 88% : strong : Attached to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); exact 0x73 body, item-state destructor caller, constructor-unwind metadata xref, thiscall vector-header contract, nested 0xb4 range release, allocation-header validation, backing-store free, triple clear, zero data/immediate/pointer route, and covered-by no-code disposition through UID0002EB/field lifecycle remain preserved. Fresh B004 cross-consumer audit identifies the +0x240/+0x244/+0x248 source field as `m_selectedFittingItems`; historical `FittingRoomEntryStringDestroyHelper` filename and `m_equipmentEntries` wording remain dated search/lifecycle evidence, not a standalone source helper or second field.
```

26. Replace current by-class UID00004Z line 204 with:

```text
- [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md) : reconstructable : 85% : strong : Embedded fitting-room selected-entry reset/layout support view only; exact reset bounds, sole OnCommand caller, dialog item-state embedding at +0x504, vector fields +0x240/+0x244/+0x248, 0xb4 entry stride, tail cleanup +0xa8/+0xac/+0xb0, constructor/destructor lifecycle, and absence of a standalone constructor/vtable/lifetime owner remain preserved. Fresh B004 paint/input/reset/lifecycle convergence identifies the storage as [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)::m_selectedFittingItems; former `FittingEquipmentState`/`m_equipmentEntries` wording is retained as historical role evidence, not a standalone class emitter or second vector.
```

27. Replace current by-class UID000050 line 205 with:

```text
- [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md) : reconstructable : 91% : strong : Fitting-room dialog class assigned to [UID:0000JE][FittingRoom](by-file/FittingRoom.md); exact constructor, command, draw, fitting-action, show-preview, category-button, control-bounds, selection, helper, singleton-clear, scalar-destructor ranges, three vtable store groups, g_pFittingRoomDialog lifetime refs, and historical incomplete-layout caveats remain documented. Fresh B004 closure replaces the declaration shell with a complete position-5 0x7ac FittingRoomDialog formal: direct CashShopRequest/DialogPane/ObjectStatusBlob project headers, exact method inventory, 68-byte base/preview appearances at +0x47c/+0x4c0, embedded 0x280 UID000051 item state at +0x504, active-category/selected-command/category-list dwords at +0x784/+0x788/+0x78c, m_itemShopVersion at +0x790, m_activeCatalogRequest at +0x7a8, size guard, singleton declaration, and narrow `friend class FittingRoomListPane;`. This precedes UID000053 position 10 and legally supports complete UID0002DI/UID0002DL/UID0002DN formals; public-field promotion, convenience accessors, raw offsets, opaque storage, and fake padding remain rejected. Exact original category-list-state spelling remains a confidence cap.
```

28. Replace current by-class UID000053 line 208 with:

```text
- [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md) : reconstructable : 91% : very strong : Fitting-room ControlPane-derived list owner with complete compile-visible 0x12c declaration, exact constructor and owned 0x110 FittingRoomScrollPane child at +0x11c, resize/move/scroll-management/callback/reset/layer/paint/keyboard/input/timer/slot-geometry/hit-test/selection-index/timer-cleanup/destructor inventory, orientation/old/new OnScrollPositionChanged contract, dependency-safe UID000054-first child emission, selected-entry vector children UID00030R/UID00030T and 0xb4 entry evidence, raw cleanup and compiler-wrapper exclusions, and preserved source-name caps. Fresh B004 closure adds exact `../ui/core/ControlPane.h` and `../util/StringUtil.h` routes, declares row page 26, grid rows 3, grid columns 6, visible cells 18, maximum scroll 30000, and invalid slot -1, standardizes ResetScrollPosition/OnPaint/OnInputEvent on UID000051 itemState->m_selectedFittingItems and exact FittingRoomSelectionEntry fields `category/name/catalogIndex/partTypes`, and supplies legal C++03 iterators plus narrow UID000050/UID000051 friendship without an invented accessor or raw-offset API.
```

29. Replace current by-class UID0000D9 line 499 with:

```text
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md) : reconstructable : 89% : strong : Shared UTF-16/string coordination/facade page attached to [UID:0000OB][StringUtil](by-file/StringUtil.md); Batch140 and later live IDA evidence preserve the 24-byte SSO-7 class side, exact Clear/Assign endpoint sizes and behavior, pointer-backed child inventory, sentinels, and explicit `StringBase` exclusion for the separate ref-counted layout. Fresh B004 UID0002DL consumer closure preserves the complete constructor/destructor/Clear/Assign declaration and exact inline/heap union plus length/capacity storage, adds only inline `MutableData()` selecting heap storage when capacity exceeds seven and otherwise the inline buffer, and explicitly rejects only parser-side `AssignAnsi`/`c_str`; the wider pointer-backed API split remains a documented confidence cap rather than a blocker for this exact SSO accessor.
```

30. Replace current by-file UID0000OB line 273 with:

```text
- [UID:0000OB][StringUtil](by-file/StringUtil.md) : reconstructable : 89% : strong : Shared utility-string module projected to `NexusTK/util/`, with live IDA-backed SSO endpoint helpers, class-mediated [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md) ownership including B001-016 exact destructor child [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md), `StringIter`, coordination with `StringBase`, historical fixed-capacity wrapper evidence and current compiler/UCRT exclusions, shared wide-string support, and documented scope boundaries. Fresh B004 FittingRoom paint closure keeps [UID:0000D9][SimpleUString](by-class/SimpleUString.md) as the 24-byte SSO-7 owner, adds its evidence-backed inline writable-buffer selector for UID0002DL, preserves counted wide Assign/Clear semantics, and rejects only the unsupported parser `AssignAnsi`/`c_str` facade without collapsing the separate pointer-backed `StringBase` family.
```

31. Replace current by-file UID0000IT line 74 with:

```text
- [UID:0000IT][DialogPane](by-file/DialogPane.md) : reconstructable : 92% : very-strong : Base dialog source module with complete 0x26c class declaration, exact SetBackgroundResource/DrawBackground/DrawBorder/SetHoverControl bodies, lifecycle/control/list/input/animation families, dialog-frame resource and pooling contract, BrowserDialog fallback boundary, derived consumers, active-dialog state, and compiler/source separation. Fresh B004 FittingRoom source-closure audit records `NexusTK/ui/core/DialogPane.h` as the exact companion header for the complete [UID:00003T][DialogPane](by-class/DialogPane.md) declaration consumed by `NexusTK/cashshop/FittingRoom.cpp`; the existing `NexusTK/ui/core/DialogPane.cpp` ownership and all prior class/method evidence remain unchanged.
```

32. Replace current by-file UID0000M6 line 195 with:

```text
- [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md) : reconstructable : 90% : very-strong : NexusTK/map/ObjectStatusBlob.cpp source root with complete 68-byte class, tagged/full/partial parser children, exact layout/normalization/resource/global/caller evidence, broad map/object/look/image consumers, non-emitting parent split, and historical alias rejection. Fresh B004 FittingRoom source-closure audit records `NexusTK/map/ObjectStatusBlob.h` as the exact companion header for the complete [UID:00009S][ObjectStatusBlob](by-class/ObjectStatusBlob.md) declaration, including the `m_compositionMode`/`m_posture` union consumed by UID000050/UID0002DI/UID0002DN; existing source ownership and every prior parser/layout/consumer fact remain unchanged.
```

33. Replace current by-file UID0000IG line 60 with:

```text
- [UID:0000IG][ControlPane](by-file/ControlPane.md) : reconstructable : 90% : very-strong : Base UI control module under NexusTK/ui/core/ with the complete 0x108 ControlPane declaration before qualified definitions, exact RectBounds constructor, protected +0xf8..+0x104 state band, exact primary virtual order through byte-return HitTestPart, enable/disable/hit-testing methods, inline IsEnabled accessor for direct inherited +0x101 reads including NewUserDialogPane2 shape-edge gating, broad derived-control caller fanout, and compiler vtable/adjustor/deleting-wrapper exclusions. Fresh B004 FittingRoom source-closure audit records `NexusTK/ui/core/ControlPane.h` as the exact companion header for the complete [UID:000038][ControlPane](by-class/ControlPane.md) declaration consumed by [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md); existing `ControlPane.cpp` ownership and all prior control-family evidence remain unchanged.
```

34. Replace current by-class UID0000BV line 450 with:

```text
- [UID:0000BV][Region](by-class/Region.md) : reconstructable : 84% : strong : UI region class attached to `Region.cpp` (`AUTOGEN_PARENT_UID:0000N3`), with exact Region/Motion rectangle aggregate evidence, exact Region vtable-data child and boundary before RightButtonMenuPane, generated `class_Region.cpp` pollution guarded out, Motion split-owner caveat, and historical blank-C++ state below the final-source gate. Fresh B004 UID0002DL stack-consumer closure supplies the complete source-legal `class Region : public LObject` declaration with constructor/destructor, `RectBounds m_bounds` at +0x04, and `sizeof(Region)==0x14`; FittingRoom paint uses an automatic `Region savedClip`, preserving every prior boundary/pollution/history fact while closing the complete-type dependency.
```

35. Replace current by-file UID0000N3 line 228 with:

```text
- [UID:0000N3][Region](by-file/Region.md) : reconstructable : 86% : strong : Region/dirty-rectangle support with contents, IDA evidence, boundary rules, generated-owner pollution, range correction, and refs documented. Fresh B004 FittingRoom paint closure records `NexusTK/ui/core/Region.h` as the companion declaration route for complete [UID:0000BV][Region](by-class/Region.md), including its LObject base, RectBounds member, 0x14 size, and automatic UID0002DL clip-save consumer; Motion split ownership and all historical evidence remain preserved.
```

36. Replace current by-class UID00006E line 255 with:

```text
- [UID:00006E][ImageLib](by-class/ImageLib.md) : reconstructable : 82% : strong : EPF image-library singleton with IDA-confirmed constructor, ordinary destructor, scalar deleting destructor, vtable/global anchors, list-backed registry layout, and historical ResourceLayoutTable-boundary uncertainty documented. Fresh B004 UID0002DL dependency closure identifies `0x0067a744` as `ImageLib *g_pEPFLib`, supplies the complete ImageLib declaration with the shared +0x0c registry and evidence-backed non-virtual lookup surface, and represents the inseparable source facet as `typedef ImageLib ResourceLayoutTable`; generated `g_pResourceMan` and an unsupported independent ResourceLayoutTable object are rejected while raw no-this helper exclusions and the unresolved exact original typedef spelling remain preserved confidence caps.
```

37. Replace current by-file UID0000K2 line 119 with:

```text
- [UID:0000K2][ImageLib](by-file/ImageLib.md) : reconstructable : 91% : very-strong : NexusTK/render/ImageLib.cpp EPF image-library manager and source route for the non-virtual ResourceLayoutTable facet, with corrected IDA method bounds, constructor/destructor, g_pEPFLib, vtable/layout anchors, cache-list lifecycle, signature correction, registry/list methods, and UID0002P6 ResourceLayoutTable::LoadFrameDrawRecord sharing the singleton receiver route. B001-023 raw-buffer UID0002KQ and raw-record UID0002KT remain no-this helpers routed to file-level UID0000N5 ResourceLayoutTable rather than ImageLib class-method ownership. Fresh B004 UID0002DL closure adds the complete header-facing ImageLib declaration and evidence-backed `typedef ImageLib ResourceLayoutTable` facet consumed through `g_pEPFLib->LookupLayoutEntry(...)`; the prior declaration-boundary uncertainty is historicalized without claiming recovery of the exact original typedef spelling or moving the raw no-this helpers.
```

38. Replace current by-class UID0000BY line 453 with:

```text
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) : reconstructable : 90% : very-strong : Non-virtual ImageLib singleton/facet method family over g_pEPFLib with live method boundaries, exact lazy EPF/EPD registry behavior, row-layout evidence, ImageLib singleton ownership, and shared ResourceLayoutTable::LoadFrameDrawRecord projection; caller-side singleton receiver proof routes UID0002P6 here, while B001-023's raw-buffer UID0002KQ and raw-record UID0002KT remain no-this helpers owned by file-level UID0000N5 ResourceLayoutTable, preserving the established class/facet split without introducing an unsupported independent object declaration. Fresh B004 UID0002DL dependency closure uses the evidence-backed header alias `typedef ImageLib ResourceLayoutTable` and `ImageLib *g_pEPFLib` so the non-virtual lookup surface is compile-visible without inventing second object storage; exact lost alias spelling remains a confidence cap.
```

39. Replace current by-global UID0000QU line 84 with:

```text
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) : reconstructable : 89% : strong : Process-wide EPF/EPD layout and image-resource singleton storage at `0x0067a744`, owned by ImageLib and exposed through the ResourceLayoutTable non-virtual facet. The 2026-06-16 live IDA recheck preserves exact constructor/destructor writes and clears, ImageLib vtable/lifecycle refs, broad UI/render consumers, aliases and layout references, saved `g_pEPFLib` / `ImageLib_vftable` labels, the final `ImageLib*` versus `ResourceLayoutTable*` base/header question, and the contrasting UID0002KQ raw-buffer caller-preload caveat where loading this global does not prove helper ownership. The formal no-standalone-definition marker remains correct. Accepted UID0002P6 `ResourceLayoutTable::LoadFrameDrawRecord` is an explicit direct receiver consumer: its 81-xref cross-caller family systematically loads or preserves `g_pEPFLib` in `ecx` before the projection call, routing that canonical body through ResourceLayoutTable/ImageLib rather than a free ImageFrameTable helper even though the callee later reuses the incoming register. Fresh B004 UID0002DL closure adds a second direct paint consumer of the same storage through `g_pEPFLib->LookupLayoutEntry(...)`, rejects generated `g_pResourceMan`, and uses the complete ImageLib plus evidence-backed ResourceLayoutTable typedef route without adding duplicate global storage.
```

40. Replace current by-type/by-struct UID0001UU line 62 with:

```text
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) : reconstructable : 92% : very-strong : Complete ItemObjImageLib declaration with direct LObject plus Singleton<ItemObjImageLib> bases, direct-base PMD +0x04 EBO overlapping ProtectedArray<ItemInfo>, exact 0x28 size, complete constructor/destructor/draw/glyph/refresh/member/access union, MapPane friendship, one external g_pItemObjImageLib header declaration, and child-owned definitions/compiler exclusions. Fresh B004 UID0002DL closure preserves receiver-backed item draw methods on `g_pItemObjImageLib`, identifies `GetItemGlyphBounds` as a free/file-local helper because that call has no ItemObjImageLib receiver, and adds the exact paint-consumer declaration route without converting unrelated helpers into convenience members.
```

41. Replace current by-file UID0000KH line 134 with:

```text
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) : reconstructable : 92% : very-strong : NexusTK/render/ItemObjImageLib.cpp owns one position-0 typed g_pItemObjImageLib definition with local forward declaration, while the complete class/header block carries the matching extern and direct LObject plus Singleton<ItemObjImageLib> hierarchy. Exact constructor/empty-destructor source, implicit singleton/member/base lifetime, compiler-only EH/scalar/vtable artifacts, complete 65-ref consumer inventory, layout, resources, draw/glyph/refresh methods, aliases, and one-definition policy are documented without by-file reconstruction metadata. Fresh B004 UID0002DL closure adds the complete paint dependency route: member draws retain the typed singleton receiver, `GetItemGlyphBounds` remains a free/file-local helper under the same source root, and no duplicate global or invented all-member API is introduced.
```

42. Replace current by-class UID00007B line 287 with:

```text
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) : reconstructable : 92% : very-strong : Complete source-legal ObjectPane-derived 0x20c LivingObjectPane declaration with typed primary/secondary EffectObjectPane Lists, Balloon/HitBar/DamageNumber/ObjectInfo panes, exact linked-object lifecycle, ObjectStatusBlob/Motion state, protected derived-use fields, MapPane/Motion/BowGaugeObjectPane friendship, nested BoxRotator, 33-wide name storage, source-facing m_objectInfoType at +0x16c, size guard, and child insertion point; BowGauge friendship preserves observed direct m_nameVisible access without layout change or invented getter. Fresh B004 UID0002DN closure adds only `class FittingRoomListPane;` and narrow `friend class FittingRoomListPane;`, allowing the proved `g_pUserPane->m_nameVisible` inherited-field test while preserving the complete layout and rejecting generated `g_pGlobalState->fittingRoomInputLocked`, raw offsets, and a new getter.
```

43. Replace current by-file UID0000KU line 147 with:

```text
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) : reconstructable : 90% : very-strong : NexusTK/map LivingObjectPane.cpp source root with one complete 0x20c declaration, ten exact linked-object setup/lifetime children, adjacent unregister method, typed effect Lists and singleton overlay panes, 33-wide name plus m_objectInfoType field, exact active-map/List/ObjectStatus/Motion integration, nested BoxRotator, exact children, and explicit exclusion of UserPane-only large-offset functions. Fresh B004 UID0002DN closure synchronizes the narrow FittingRoomListPane friendship on the complete class declaration and records inherited `m_nameVisible` as the source of the `g_pUserPane` input gate; all existing source ownership, field, child, split, and exclusion evidence remains unchanged.
```

Item 20 is terminalized with validator-owned UID0004WI. B004 did not guess/reuse an identity or edit `validator.ini`; manual coverage application remains supervisor-owned.

Reason B agent must not apply manual rows: every `-coverage-report.md` is supervisor-owned to prevent concurrent collisions.

## Follow-Up Actions

- B004 implementation work is complete. No accepted ordinary-document, raw-range, formal, claim-ledger, or generated-readback item remains outstanding.
- The 43 exact manual `-coverage-report.md` handoffs are terminalized, present, and independently validated by supervisor commands16953 through16957; no further B004 coverage callback is required, and B004 did not edit coverage reports.
- No manual coverage action remains now or after execution for this report.
- Supervisor Gate 2B is already `APPLIED_VERIFIED` through the existing detailed IDA action/readback section.
- Exact active-artifact Gate 1 and fresh supervisor Gate 2A passed report SHA `E64983DE492480E142E10A179AAC1179FD3C1491F3B21F198A7C3D6C50026846` against the current destination documents, report ledger, managed formals, manual coverage closure, generated evidence, and Gate 2B continuity.
- Supervisor-only `execute_report`/archive is authorized. The validator-owned history footer and executed-report registry are authoritative for whether the artifact is at the active path before execution or archived afterward; this body does not assert a separate pending or active lifecycle state.
- B004 did not edit manual coverage, generated/tracker files, validator state, IDA, supervisor/audit files, goal.md, or lifecycle/archive state.
- Current/future lifecycle state must be read from the validator-owned footer and executed-report registry, not inferred from this report path or an old tracker count.

## Confidence

- Recommendation confidence: 91/100.
- Score confidence: strong.
- Remaining lexical uncertainty, already reflected in the `90/91` ceiling:
  - exact original typedef/alias spelling for the MSVC hash container;
  - exact original local names;
  - exact lost source constant/name for the 85-wide-character catalog backing array;
  - exact original spelling of the ImageLib/ResourceLayoutTable source alias, while the shared object/global/method route is strongly proved.
- The report preserves all original 16 managed formals and four complete direct-dependency formals, for 20 exact implemented destination blocks. It supplies explicit declaration/source routes for the UID000051/UID000050/UID000053 target package, UID0000D9, Event, EPFTileContext, Region, ImageLib/resource-layout, ItemObjImageLib, UserPane/LivingObjectPane, GrafPort, Surface callbacks, and geometry. Scoped validators and command16927 generated readback confirm the accepted textual source package. Remaining lexical uncertainty does not justify leaving compiler/IDA labels in emitted C++.

## Validator Results

- Raw allocation/terminalization commands `16828`, `16831`, `16834`, `16836`, `16838`, `16840`, and `16841` completed successfully and established UID0004WI/UID0004WJ/UID0004WK/UID0004WL without hand-editing validator state.
- Main target/support commands `16843` through `16894` listed in `tools/leaser/Agents/Agent-B004/0002E6-implementation-validator.log` all exited `0`; UID0002E6 returned `ok: 8`, UID000051 returned `ok: 19`, and each remaining scoped document returned `ok: 1`.
- Consistency commands `16905`, `16908`, `16910`-`16912`, `16914`, `16916`-`16927` all exited `0` with `ok: 1`. Exact timestamps/results are appended to the B004 validator log.
- Final command `000000016927` at `2026-07-23T22:35:04-04:00` validated `by-file\FittingRoom.md` with `--wait-generated`, returned `ok: 1`, and completed generated refresh. Its four UID0003AM missing-reference messages are pre-existing file-level references, not defects introduced by this package.
- Accepted command16927 semantic generated artifact: `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, SHA256 `6642C30C5A2FA3B15EF25CA239552F6B7D539BB9528242C2EB65F212E7044A2D`, 99,511 bytes, 2,818 physical lines.
- Historical physical-header checkpoint: deferred command16971 at `2026-07-23T23:31:01-04:00` produced SHA256 `70274C0BCDDA345DB3AF2FA8CC6C66CFDF6905E400CD6B6DBD65EBEC4D1383B9`, 99,509 bytes and 2,818 lines; it is not the current physical artifact.
- Current physical `auto-generated/NexusTK/cashshop/FittingRoom.cpp` is deferred command17009 at `2026-07-24T00:36:01-04:00`, SHA256 `1C819E2BA6F26E2F30D783766102169B7B52135AED9051FCFE21846E9660AB76`, 99,509 bytes and 2,818 lines. Replacing only its three validator-owned command/timestamp/source header lines with the command16927 values reconstructs semantic SHA256 `6642C30C5A2FA3B15EF25CA239552F6B7D539BB9528242C2EB65F212E7044A2D`, proving the semantic payload is unchanged.
- Generated postconditions: `m_selectedFittingItems` 14; `catalogIndex` 11; `m_compositionMode` 6; `std::wstring`, `MutableData`, `g_pEPFLib`, `g_pItemObjImageLib`, and `g_pUserPane->m_nameVisible` present; zero `m_equipmentEntries`, parser `SimpleUString::AssignAnsi`/`SimpleUString::c_str`, `Locale`, fake reserved members, `m_specialSetPreviewMode`, `previewPartMode`, `g_pResourceMan`, `g_pGlobalState`, or fabricated selection helpers.
- Supervisor coverage commands16953 (`by-memory`), 16954 (`by-class`), 16955 (`by-file`), 16956 (`by-type/by-struct`), and 16957 (`by-global`) each exited `0` with `ok: 1`, confirming all 43 exact manual rows are present. B004 did not edit or validate coverage reports.
- Post-repair destination repairs were validated individually under short B004 leases: commands16958 through16971 each exited `0` with `ok: 1`; command16964 also repeated one pre-existing UID0003GZ missing-reference warning in UID0000D9, command16970 verified the target C2E6-082 marker-state row, and command16971 verified the durable command16927 semantic-payload wording. Fresh supervisor Gate 2A accepted these validator results as supporting evidence.
- Focused Gate 2A claim-copy repairs were validated serially under short B004 leases. Command17002 validated the UID0004WI raw page after both retained-padding counts were corrected to fourteen; command17003 validated the target C2E6-054 completed UID0004WI wording; commands17004 and17006 validated the C2E6-065 owner/access reconciliation copies; commands17004,17006,17007,17008, and17009 validated all five C2E6-071 exact position-5 declaration copies. Every command exited `0` with `ok: 1`, every lease was released immediately afterward, and fresh supervisor Gate 2A passed the resulting exact artifact.
- B004 ran no report lifecycle command. Scoped ordinary-file validation and supervisor-owned coverage validation are complete; supervisor-only report execution/archive is authorized but remains outside B004 actor scope, with validator-owned footer/registry state authoritative.

## Changed Files

- Target and source owners: `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md`, `by-class/FittingRoomDialogItemState.md`, `by-class/FittingRoomDialog.md`, `by-class/FittingRoomListPane.md`, and `by-file/FittingRoom.md`.
- Exact target-family methods/support: `by-memory/0x0041c310-0x0041c596.FittingRoomDialogOnCommand.md`, `by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md`, `by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md`, `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`, `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`, `by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md`, `by-memory/0x00421fe0-0x0042201c.FittingRoomCatalogEntryPartLookup.md`, `by-memory/0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md`, `by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md`, `by-memory/0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries.md`, `by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md`, and `by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md`.
- Raw-range repair: old `by-memory/0x004219f0-0x00421a20.FittingRoomCatalogEntryNoRouteInitializer.md` was renamed/corrected to `by-memory/0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer.md` (UID0004WI); `by-memory/0x00421860-0x004219e1.FittingRoomCatalogPartRecordLoadFromJsonNoRoute.md` (UID0004WJ), `by-memory/0x004219e1-0x00421a40.FittingRoomCatalogEntryNoFunctionTail.md` (UID0004WL), `by-memory/0x00421a30-0x00421a3b.FittingRoomCatalogEntryPartVectorDestroyAdjustorThunk.md` (UID0004WK), `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`, and `by-memory/-ignored.md` were synchronized.
- Layout/string/region dependencies: `by-class/FittingEquipmentState.md`, `by-type/by-struct/FittingEquipmentStateLayout.md`, `by-class/SimpleUString.md`, `by-file/StringUtil.md`, `by-class/Region.md`, and `by-file/Region.md`.
- Image/render/user dependencies: `by-class/ImageLib.md`, `by-class/ResourceLayoutTable.md`, `by-file/ImageLib.md`, `by-global/g_pEPFLib.md`, `by-type/by-struct/ItemObjImageLibLayout.md`, `by-file/ItemObjImageLib.md`, `by-class/LivingObjectPane.md`, and `by-file/LivingObjectPane.md`.
- Companion-header source roots: `by-file/DialogPane.md`, `by-file/ObjectStatusBlob.md`, and `by-file/ControlPane.md`.
- Compiler/container support: `by-memory/0x00423000-0x0042305c.FittingRoomCategoryLookupInsertNode.md`, `by-memory/0x00423470-0x0042365d.FittingRoomCategoryLookupFinalize.md`, `by-memory/0x00423660-0x004236d7.FittingRoomCategoryLookupEraseNode.md`, `by-memory/0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md`, `by-memory/0x00423a60-0x00423a8d.CategoryTreeSentinelAllocator.md`, `by-memory/0x00423a90-0x00423af4.CategoryTreeNodeCleanupFree.md`, and `by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md`.
- B004-owned records: this report and `tools/leaser/Agents/Agent-B004/0002E6-implementation-validator.log`.
- Read-only/generated effects: scoped validators refreshed validator-owned generated metadata and `auto-generated/NexusTK/cashshop/FittingRoom.cpp`; B004 did not edit generated/tracker files manually.
- Manual coverage files modified by B004: none. Exact handoff text remains under the required manual-coverage section.
- IDA changes by B004: none. The supervisor-owned accepted Gate 2B action/readback remains preserved verbatim under the exact IDA heading.
- Report lifecycle commands by B004: none run or probed. No report was moved or archived by B004.
- Leases: each ordinary file was leased only for its immediate edit/validator batch and released immediately; the final lease report shows no active leases.
- Focused Gate 2A repair destinations: `by-memory/0x004219f0-0x00421a22.FittingRoomCatalogEntryNoRouteInitializer.md`, `by-memory/0x00422ba0-0x00422e91.FittingRoomDialogItemStateLoadCategoryFromJson.md`, `by-class/FittingRoomListPane.md`, `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`, `by-class/FittingRoomDialog.md`, `by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md`, and `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`. No other ordinary destination was changed in this focused callback.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact pre-callback artifact SHA `F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26` before implementation; exact active-artifact Gate 1 and fresh Gate 2A later passed SHA `E64983DE492480E142E10A179AAC1179FD3C1491F3B21F198A7C3D6C50026846` after all focused repairs.
- [x] Target UID0002E6 formal/prose update applied and validated at `90/91`; owner/emitter/reconstructable state remains `000051`/`000051`/true.
- [x] UID000051 position-0 class declaration formal installed with direct C++03/Win32/Shell/CRT/JsonCpp headers including `<string.h>`, category enum/constants, naturally aligned part record, 0xc0 catalog entry/category constructor and `name[0x55]`, pointer-vector/map aliases, exact 0xb4 `FittingRoomSelectionEntry { category, name, catalogIndex, partTypes }`, one `m_selectedFittingItems` item-state vector, narrow `FittingRoomListPane` friendship, 0x280 item-state fields without fake padding members, class closure, and `[[CHILDREN]]`.
- [x] UID0002E4 parser formal replaces unsupported parser-side `SimpleUString::AssignAnsi`/`SimpleUString::c_str` with `std::wstring` range construction, explicitly preserves valid `std::wstring::c_str()`, copies nested Json values, leaves natural padding untouched, and is validated at `90/91`.
- [x] UID0002E7 formal replaces IDA `Locale` with `""` and is checked against the direct Win32/Shell/CRT header matrix.
- [x] UID0002E5 exact signed-byte/upper-bound-only part accessor formal installed and validated at `90/91`.
- [x] UID0000WS receives the complete exact metadata/header/formal block with `m_selectedFittingItems.clear()` and preserves all reset/lifecycle evidence at `88/91`.
- [x] UID0002DI receives the complete exact metadata/header/formal block, reaches selected entries through local `itemState`, uses a legal C++03 vector iterator and existing `m_baseAppearance.m_compositionMode`, and raises `88/91 -> 90/92`.
- [x] UID0002DL receives the complete exact metadata/header/formal block, retains its full paint body/item-state route/`catalogIndex`, uses a legal C++03 iterator, UID000053 grid constants, and UID0000D9 `MutableData()`, historicalizes `displayName`/`itemIndex`, and raises `88/91 -> 90/92`.
- [x] UID0002DN receives the complete exact metadata/header/formal block, retains its full event body and `name`/`catalogIndex`, routes every selected-vector operation through `itemState->m_selectedFittingItems`, inlines construction/exact erase/overlap erase/append/automatic destruction and all 15 part cases, uses `m_compositionMode`, closes Event/UserPane/ImageLib/ItemObjImageLib/GrafPort/Surface/geometry declarations, rejects five fabricated helpers plus generated globals/API aliases, and is validated at `90/91`.
- [x] Directly related UID0002CQ Current-button formal also uses the accepted `m_baseAppearance.m_compositionMode` identity; command16926 validates the fix and final generated output contains zero `previewPartMode`.
- [x] UID0002UE receives its complete exact metadata/header/covered-by formal, uses `m_selectedFittingItems`, and preserves exact no-code lifecycle evidence at `88/90`.
- [x] UID00004Z support view historicalizes a standalone class/second-vector interpretation and remains `85/89`.
- [x] UID000050 installs the exact complete position-5 managed formal with direct project headers, complete method/field order, two appearance blocks, embedded UID000051 state, category/list/version/request fields, `0x7ac` guard, singleton declaration, and narrow `FittingRoomListPane` friendship; raise `87/89 -> 91/92`.
- [x] UID000053 installs the complete exact position-10 formal with ControlPane/StringUtil relative headers, row/grid/scroll constants including columns `6` and visible cells `18`, synchronizes ResetScrollPosition/OnPaint/OnInputEvent routes, and raises `88/90 -> 91/92`.
- [x] UID0000D9 installs the complete exact SSO-7 formal with inline `MutableData()`, preserves parser-facade rejection and StringBase caveats, and raises `88/88 -> 89/90`.
- [x] UID0000OB synchronizes the complete UID0000D9/UID0002DL source route at `89/89` without pruning unrelated string-family evidence.
- [x] UID0000IT, UID0000M6, and UID0000IG add exact companion-header routes `NexusTK/ui/core/DialogPane.h`, `NexusTK/map/ObjectStatusBlob.h`, and `NexusTK/ui/core/ControlPane.h`, each linked to its existing complete class formal and validated serially without changing source ownership/scores; UID0000I0 `cashshop/CashShopRequest.h` and UID0000OB `util/StringUtil.h` remain already-present routes.
- [x] UID00004L/UID0000J6 and UID00004I/UID0000J4 are read back as already-complete Event and EPFTileContext declaration/source routes; UID0002DN/UID0002DL use exact fields/enums/Initialize/bounds and no generated aliases.
- [x] UID0000BV/UID0000N3 receive the complete 0x14 Region declaration/source route and UID0002DL stack consumer, preserving all split/history evidence.
- [x] UID00006E/UID0000K2/UID0000BY/UID0000QU receive the complete ImageLib/resource-layout-facet plus typed `g_pEPFLib` route; generated `g_pResourceMan` and independent-object invention are rejected.
- [x] UID0001UU/UID0000KH receive the complete ItemObjImageLib route with receiver-backed draw members, typed `g_pItemObjImageLib`, and free/file-local `GetItemGlyphBounds`.
- [x] UID00007B/UID0000KU add only narrow FittingRoomListPane friendship; UID0000FQ/UID0000P1/UID0000QK/UID0001OR are read back for exact `g_pUserPane` and inherited `m_nameVisible`; generated `g_pGlobalState` is rejected.
- [x] UID00005V/UID0000JR, UID0000TN/UID0000OC, and UID00015S/UID0000N2 are read back for exact GrafPort/Surface/Point/Rect APIs and source-facing argument order.
- [x] UID0001UH records exact `name`/`catalogIndex`/`partTypes` layout and single `m_selectedFittingItems` identity at validated `91/92`.
- [x] UID0002EF body remains unchanged; existing `strcpy_s` is recorded as direct `<string.h>` dependency evidence.
- [x] Raw constructor stale page renamed to exact `[0x004219f0,0x00421a22)` path, invalid duplicate UID00042D header removed, evidence preserved, and covered-by formal terminalized as validator-allocated UID0004WI.
- [x] Corrected raw page validated first with no UID so validator allocates identity; exact UID/command/timestamp/effects read back and recorded.
- [x] UID0004WJ, UID0004WL, UID0002E6, and UID000051 each leased/edited/validated/released one at a time through the corrected-path TMP token; UID0000JE received the fifth reference in the final `--wait-generated` sequence.
- [x] UID0004WL child end/following padding corrected to `0x00421a22`; zero stale old-path and zero false FittingRoom UID00042D references verified.
- [x] UID0002E7/UID0002EB/UID0002EC/UID0000WV category-container source reconciliation.
- [x] UID0002E7/UID0002EC/UID0000WV formals and scores synchronized to `90/91`, `91/92`, and `90/92`; UID0001UH exact selection layout validated at `91/92`.
- [x] UID0002U4/U8/U9/UB/UH/UI compiler-generated reclassification and formal/emitter cleanup.
- [x] UID0000WW shared compiler-vector reclassification.
- [x] UID000051/UID000050/UID000053/UID0000D9/UID0000OB/UID0000IT/UID0000M6/UID0000I0/UID0000IG/UID0000BV/UID0000N3/UID00006E/UID0000K2/UID0000BY/UID0000QU/UID0001UU/UID0000KH/UID00007B/UID0000KU/UID0000JE no-loss source-model synchronization includes selected-entry/member/friend/header/grid/SSO/direct-dependency decisions, explicit companion-header destinations, exact FittingRoom emitter order `0/5/10`, and complete destination formals.
- [x] Assignment-time command16821 tracker and command16807 generated identities are timestamped as historical; command16927 is the accepted semantic generated checkpoint and later scoped commands refreshed only validator-owned header metadata; all 43 exact manual actions are recorded as supervisor-owned handoffs.
- [x] All 100 ledger claims are `implemented-verified`.
- [x] Target validated at `90/91`; owner/emitter/reconstructable state remains unchanged.
- [x] Resolve source placement, target/switch/raw-constructor range, selected-entry naming/storage/access, and direct-header decisions.
- [x] Apply exact target first-draft C++ formal block.
- [x] Apply all 20 complete managed formals exactly; verify generated target package has one valid UID0002DL paint-side `SimpleUString` route, zero parser-side `SimpleUString::AssignAnsi`, zero parser-side `SimpleUString::c_str` facade, the allowed `std::wstring::c_str()` call, zero IDA `Locale`, zero `reservedAA`/`reservedState`/`m_reserved24D`, no packed fake padding member, no current `m_equipmentEntries`, one item-state `m_selectedFittingItems` route, selected fields `name`/`catalogIndex`, exact Event/EPFTileContext/Region/ImageLib/ItemObjImageLib/UserPane/GrafPort/Surface/geometry declarations, zero `g_pResourceMan`/`g_pGlobalState`, existing `m_baseAppearance.m_compositionMode`, exact grid constants, zero fabricated UID0002DN helper calls, exact `0/5/10` FittingRoom declaration order, and no partial/comment-placeholder substitution.
- [x] Third-party import directive confirmed not applicable.
- [x] Preserve all exact low-level helper facts while historicalizing custom source APIs.
- [x] Preserve exact malformed-input leak behavior.
- [x] Ignore Wave2/Wave3 artifacts as stale.
- [x] Close all target open questions, including SimpleUString/Locale/API-header/companion-header/padding/selection/name-capacity/field-name/member-identity/friend-access and Event/EPFTileContext/Region/ImageLib/global/ItemObjImageLib/UserPane/render/geometry investigation, as documented above.
- [x] Ordinary scoped validators ran only after the accepted callback.
- [x] All 43 exact manual coverage handoffs are terminalized with UID0004WI and supplied to the supervisor; B004 did not edit coverage reports.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted C2E6-001 through C2E6-100 target/support details incorporated at report-level detail.
- [x] Target UID independently verified against ledger and destination.
- [x] Ledger states transitioned from proposed only after actual verification.
- [x] Metadata/score/owner/emitter/range/C++ changes applied as accepted.
- [x] Historical/stale assumptions and negative evidence preserved.
- [x] Raw constructor UID/range repair completed through target-first validator allocation without reusing UID00042D or editing validator state.
- [x] Every actor-bound raw-UID placeholder in this report/manual handoff was replaced with UID0004WI.
- [x] Ordinary validators run in the exact target-first/TMP/reference/support sequence, ending with `by-file\FittingRoom.md --wait-generated`, and exact command IDs/timestamps/results/effects recorded.
- [x] Generated FittingRoom.cpp read back for target semantic counts, no stale target body, no old selected-entry/member names, legal source routes, accepted semantic command16927 hash/metrics, and current physical command17009 header/hash/metrics.
- [x] Generated declaration/parser/constructor/list-method readback confirms every UID000051/UID000050/UID000053/UID0000D9 and direct Event/EPFTileContext/Region/ImageLib/ItemObjImageLib/UserPane/GrafPort/Surface/geometry identifier is declared, every platform/CRT/project identifier is supplied by the accepted direct include route, all 20 destination formals are complete, and compilation readiness is confirmed only by callback validation rather than inferred from textual generation.
- [x] Manual coverage left untouched by B004 and supplied to supervisor.
- [x] No execute_report/lifecycle command run or probed by B004.
- [x] Supervisor applied and validated all 43 exact manual coverage actions through commands16953/16954/16955/16956/16957, each `exit 0`, `ok: 1`; B004 supplied the handoffs and did not edit coverage reports.
- [x] Supervisor Gate 2B applied and independently read back the accepted method identity/type, semantic UDTs/layouts, safe local names, and compiler-helper comments; the exact supervisor-owned section is preserved for final execution review.
- [x] Corrected both UID0004WI retained-padding statements to exactly fourteen `0xcc` bytes in `[0x00421a22,0x00421a30)` and scoped-validated the raw page with command17002.
- [x] Repaired the target C2E6-054 copy to current completed UID0004WI state and scoped-validated it with command17003.
- [x] Repaired both C2E6-065 destination copies to the implemented `itemState->m_selectedFittingItems` owner/access reconciliation and scoped-validated them with commands17004 and17006.
- [x] Repaired all five C2E6-071 destination copies to the current exact UID000050 position-5 declaration state and scoped-validated them with commands17004,17006,17007,17008, and17009.
- [x] Fresh post-repair supervisor Gate 2A passed exact report SHA `E64983DE492480E142E10A179AAC1179FD3C1491F3B21F198A7C3D6C50026846`, independently verifying all 100 claims, 20 managed destination blocks, ordinary repair state, all 43 applied manual coverage actions, validator evidence, current report wording, and Gate 2B continuity.
- [x] Supervisor-only `execute_report`/archive is authorized; the validator-owned history footer and executed-report registry record the authoritative lifecycle state whether this body is read from the active path before execution or from the archive afterward. B004 did not run, probe, or dry-run any report lifecycle command.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000017017","destination_path":"executed-b-agent-research/B004/0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality.md","timestamp":"2026-07-24T00:56:56-04:00","uid":"0002E6"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002E6-FittingRoomDialogItemStateLoadCategoryFromJson-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002E6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
