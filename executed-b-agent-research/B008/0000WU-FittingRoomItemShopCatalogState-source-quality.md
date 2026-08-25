** TARGET-REPORT-UID:0000WU **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000WU FittingRoomItemShopCatalogState Source-Quality Research


Assignment: `B008-report-0000WU-FittingRoomItemShopCatalogState-source-quality-20260627`  
Agent: `Agent-B008`  
Mode: report-only research first; no by-* edits, generated edits, coverage edits, validator state/cache edits, or IDA database edits performed.  
Current target: [UID:0000WU] `by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md`  
Required report path: `tools/leaser/Agents/Agent-B008/research/0000WU-FittingRoomItemShopCatalogState-source-quality.md`

## Executive Conclusion

[UID:0000WU] should be reclassified from an emitting reconstructable range to a non-emitting address-container/index page.

Recommended target metadata for the later implementation callback:

| Field | Current target | Recommended |
| --- | --- | --- |
| `COMPLETION` | `87` in target doc; generated tracker still shows stale `80` | `90` |
| `CONFIDENCE` | `89` in target doc; generated tracker still shows stale `86` | `92` |
| `CANONICAL_OWNER` | `0000JE` | keep `0000JE` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000JE` | clear |
| C++ body | blank | keep blank |

Reason: the target is not one source-level function, class, or data declaration. It spans exact child methods, `0xcc` alignment, a raw duplicate/no-route helper, an embedded `ItemCatalog` facade child, third-party JsonCpp handoff calls, and adjacent compiler-generated switch-table data. The source-bearing behavior belongs to the exact children and support pages, not to the aggregate range itself.

This differs from [UID:0002EA] `0x00422920-0x004229ef`: that child remains `RECONSTRUCTABLE:TRUE` with blank C++ because it is source-shaped cache-path logic with a valid item-state owner but no live standalone route. [UID:0000WU] is broader: it is a coverage/index container over many independently documented regions, so it should not emit even an empty marker.

## Evidence Read

Direct target/support docs read or rechecked:

| Item | Use |
| --- | --- |
| `goal.md` | Assignment, report-only mode, target, MCP requirement, required output path, and no-edit rules. |
| `by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md` | Current aggregate metadata, child inventory, JsonCpp handoff, B001/B005/B007 incorporation, open `ItemCatalog` split question. |
| `by-file/FittingRoom.md` | Source-file route, fitting-room item-state ownership, current `FittingRoom.cpp` placement. |
| `by-class/FittingRoomDialogItemState.md` | Item-state field model, cache path, category lookup storage, layout names, child method inventory. |
| `by-file/ItemCatalog.md` and `by-class/ItemCatalog.md` | Two-method facade evidence, current standalone-vs-embedded split blocker. |
| Exact child pages `0002E4`, `0002E5`, `0002E6`, `0002E7`, `0002E8`, `0002E9`, `0002EA`, `0002EB`, `0002EC`, `0002EF`, `0002EG`, `0002EH`, and `0000WV` | Child coverage and whether each region needs aggregate-level source emission. |
| Executed reports from B001, B005, and B007 | Applied source-quality decisions for the major item-state child methods, transform helper, cache-file helper, and raw cache-path helper. |
| Generated tracker/coverage/C++ files | Read-only stale-state evidence only; no generated files were edited. |

Generated/read-only leads show expected lag: `auto-generated/NexusTK/cashshop/FittingRoom.cpp` still contains an empty emitter marker for `UID:0000WU`, and the generated marker metadata is older than the current by-* docs. That should be fixed by validators after the later by-* implementation callback, not by manual generated-file edits.

## Current IDA MCP Session

IDA MCP was available and used. This is not a fallback-only report.

| Evidence | Result |
| --- | --- |
| MCP endpoint | `http://127.0.0.1:13337/mcp` |
| Active database | Session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module/input | `NexusTK.exe`, imagebase `0x400000`; input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Health | `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true` |
| Read-only tools used | `server_health`, `lookup_funcs`, `entity_query`, `xref_query`, `callees`, `get_bytes`, `get_string`, `search_structs`; local `tools/int_convert.py` |

No MCP pause condition occurred.

## Live Function And Range Map

Current `lookup_funcs` and `entity_query` confirm that `0x00421a40-0x00422e91` is a multi-entity address span, not one function:

| Range | UID | Live IDA status | Source disposition |
| --- | --- | --- | --- |
| `0x00421a40-0x00421fd8` | `0002E4` | `sub_421A40`, size `0x598` | Coded child: `FittingRoomCatalogEntry::LoadFromJson`. |
| `0x00421fd8-0x00421fe0` | ignored | eight `0xcc` bytes | Padding. |
| `0x00421fe0-0x0042201c` | `0002E5` | `sub_421FE0`, size `0x3c` | Reconstructable child, blank until final declaration/signature. |
| `0x0042201c-0x00422020` | ignored | four `0xcc` bytes | Padding. |
| `0x00422020-0x0042232a` | `0002E7` | `sub_422020`, size `0x30a` | Coded item-state constructor. |
| `0x0042232a-0x00422330` | ignored | six `0xcc` bytes | Padding. |
| `0x00422330-0x0042246f` | `0002EB` | `sub_422330`, size `0x13f` | Coded item-state destructor. |
| `0x0042246f-0x00422470` | ignored | one `0xcc` byte | Padding. |
| `0x00422470-0x0042259a` | `0002EC` | `sub_422470`, size `0x12a` | Reconstructable reset helper; blank pending final helper declarations. |
| `0x0042259a-0x004225a0` | ignored | six `0xcc` bytes | Padding. |
| `0x004225a0-0x0042268f` | `0002EF` | `sub_4225A0`, size `0xef` | Reconstructable save helper; blank pending final buffer/field names. |
| `0x0042268f-0x00422690` | ignored | one `0xcc` byte | Padding. |
| `0x00422690-0x004226cd` | `0000WV` part | `sub_422690`, size `0x3d` | `ItemCatalog` count facade method. |
| `0x004226cd-0x004226d0` | local padding | three `0xcc` bytes | Padding between facade methods. |
| `0x004226d0-0x0042273f` | `0000WV` part | `sub_4226D0`, size `0x6f` | `ItemCatalog` indexed lookup facade method. |
| `0x0042273f-0x00422740` | ignored | one `0xcc` byte | Padding. |
| `0x00422740-0x00422919` | `0002E9` | `sub_422740`, size `0x1d9` | Coded encoded-buffer parser. |
| `0x00422919-0x00422920` | ignored | seven `0xcc` bytes | Padding before raw helper bytes. |
| `0x00422920-0x004229f0` | `0002EA` | no IDA function at `0x00422920` | Source-shaped duplicate cache-path helper; target C++ intentionally blank. |
| `0x004229f0-0x00422b25` | `0002EG` | `sub_4229F0`, size `0x135` | Coded cache-file load helper. |
| `0x00422b25-0x00422b30` | ignored | eleven `0xcc` bytes | Padding. |
| `0x00422b30-0x00422b93` | `0002E8` | `sub_422B30`, size `0x63` | Coded reversible transform helper. |
| `0x00422b93-0x00422ba0` | ignored | thirteen `0xcc` bytes | Padding. |
| `0x00422ba0-0x00422e91` | `0002E6` | `sub_422BA0`, size `0x2f1` | Coded category loader. |

Live negative boundary checks:

- `lookup_funcs` reports no function at `0x00421fd8`, `0x0042201c`, `0x00422919`, `0x00422920`, `0x004229ef`, `0x00422e91`, or `0x00422e94`.
- `xref_query` reports no incoming xrefs to `0x00422920`, no incoming xrefs to `0x004229f0`, and no incoming xrefs to `0x00422e91`.
- The next modeled function after the switch-table child is `0x00422ec0` (`sub_422EC0`), outside the `0000WU` target range.

This range map is the strongest reason to change [UID:0000WU] to `RECONSTRUCTABLE:FALSE`: the target is a parent/index over exact child bodies and non-source spans.

## Caller And Callee Evidence

Live `xref_query` confirms source-bearing reachability belongs to exact children:

| Target | Live incoming xrefs |
| --- | --- |
| `0x00421a40` | one caller at `0x00422d0e` inside `0x00422ba0`. |
| `0x00421fe0` | two callers at `0x0041fea3` and `0x004201e7` inside fitting-room list/input code. |
| `0x00422020` | one constructor caller at `0x0041be6c` inside `0x0041bdd0`. |
| `0x00422330` | destructor-related xrefs at `0x0041c2e4`, `0x0041d527`, and `0x005f683f`; ordinary destructor route is `0x0041d527`. |
| `0x00422470` | reset callers at `0x0041cc11`, `0x00422355`, and `0x00422f9b`. |
| `0x004225a0` | one save caller at `0x0041cc57`. |
| `0x00422690` | five fitting-room count callers: `0x0041ce5d`, `0x0041ee41`, `0x0041f4eb`, `0x0041fc49`, `0x00420d1c`. |
| `0x004226d0` | five fitting-room indexed-lookup callers: `0x0041ee5e`, `0x0041f51d`, `0x0041f5f0`, `0x0041fe16`, `0x00420d2d`. |
| `0x00422740` | four callers: `0x0041cc30`, constructor call `0x004222c2`, cache-load helper call `0x00422ac5`, test-json loader call `0x00422f90`. |
| `0x00422b30` | transform callers at `0x00422292`, `0x00422618`, and `0x00422a9b`. |
| `0x00422ba0` | one parser caller at `0x0042287c`. |

Live `callees` preserves the product/third-party boundary:

- `0x00422740` calls `0x004298f0` and `0x00429b30`, now documented as `Json::Reader::Reader()` and `Json::Reader::parse(const std::string&, Json::Value&, bool)`, plus JsonCpp value/document helpers and the product category loader `0x00422ba0`.
- `0x00422ba0` calls JsonCpp value helpers `0x004278e0`, `0x00426ea0`, `0x00427500`, `0x00425010`, and product helpers `0x00421a40`, `0x00420de0`, `0x00421290`, `0x00423000`, `0x00423470`.
- `0x00422690` and `0x004226d0` are thin facade methods over category lookup support, calling `0x00423e40`; indexed lookup also calls `0x00421290` and `0x00423810`.
- `0x004229f0` owns the cache-file read/transform/parse helper behavior through `_wfopen` dispatch `0x0069be14`, `_fseek`, `_ftell`, `_fread`, `0x00422b30`, decoded string assignment, and parser `0x00422740`.

None of this evidence requires [UID:0000WU] to emit aggregate C++.

## Switch Table And Third-Party Boundary

Live `get_bytes 0x00422e91 size 47` returns:

```text
0x00422e91: 0f 1f 00
0x00422e94: de 2b 42 00 e5 2b 42 00 ec 2b 42 00 f3 2b 42 00
0x00422ea4: fa 2b 42 00 01 2c 42 00 08 2c 42 00 0f 2c 42 00
0x00422eb4: 16 2c 42 00 1d 2c 42 00 24 2c 42 00
```

This is the three-byte alignment plus 11 dword switch-target table already covered by [UID:0002EH]. Live `xref_query` reports the only data xref to `0x00422e94` is from `0x00422bd7` inside `0x00422ba0`. `lookup_funcs` reports no function at `0x00422e91` or `0x00422e94`. Keep [UID:0002EH] `RECONSTRUCTABLE:FALSE`, and do not add table bytes to the aggregate C++.

Live `get_string` / `xref_query` checks confirm the JsonCpp/product split:

- `version` at `0x0060d94c` is referenced by downloader/update code and by the product parser at `0x004227c6`.
- Encode/decode key strings `CASHEncodeDecodeByChris` and `sirhCyBedoceDedocnEHSAC` are referenced by the item-state constructor at `0x00422135` and `0x0042214c`.
- Category keys such as `main` (`0x0060df30`) and `specialty_sets` (`0x0060df8c`) each route to `0x00422ba0`.
- Cache-path strings such as `%s\NexusTK` and `%s\ItemShop.jbn` route to both constructor code and the raw duplicate bytes at `0x00422920`.

JsonCpp helpers remain under [UID:0000KI]/[UID:0000WY]/[UID:0000X0]. [UID:0000WU] should document the handoff but must not import JsonCpp code or emit JsonCpp wrappers.

## Formal Aggregate C++ No-Code Proof

The formal C++ block for [UID:0000WU] must stay blank after reclassification.

Target-specific proof:

- It covers multiple modeled functions, not one function start.
- It covers non-source `0xcc` padding between children.
- It contains [UID:0002EA], a raw duplicate/no-route body that has its own blank-C++ proof because the constructor already emits the live path-building behavior inline.
- It contains embedded [UID:0000WV] `ItemCatalog` facade methods, which are distinct count/index methods over item-state category storage.
- It ends immediately before [UID:0002EH] switch-table data; the switch table itself is already nonreconstructable generated data.
- Its JsonCpp calls are third-party dependencies and must be expressed in child source bodies as JsonCpp API calls, not copied into aggregate code.
- Major source-bearing methods already live in exact children: `0002E4`, `0002E7`, `0002EB`, `0002E9`, `0002EG`, `0002E8`, and `0002E6` have first-draft C++; `0002E5`, `0002EC`, `0002EF`, and `0000WV` remain reconstructable exact children with local blank-C++ gates, not aggregate blockers.

Emitting any aggregate C++ for [UID:0000WU] would duplicate child bodies, invent a monolithic source unit that the executable does not model, or accidentally absorb non-source padding/data.

## ItemCatalog Split Decision

Resolve the optional split as follows:

- Do not keep `cashshop/ItemCatalog.cpp` as the preferred final source file for this feature.
- Keep `ItemCatalog` as a small embedded facade class/type if needed for source readability: it has real `GetItemCount(category)` and `GetItemByIndex(category, index)` behavior.
- Route that facade through `NexusTK/cashshop/FittingRoom.cpp` with `FittingRoomDialogItemState` support, because all live callers are fitting-room list/render/input/selection paths and the backing storage is item-state-owned `m_categoryLookup` at offset `+0x220` / decimal 544 (Verified with `int_convert.py`).
- Treat `ItemCatalog` as a facade over the item-state category lookup, not as a global item database and not as owner of JSON parsing, cache file IO, category loading, or entry allocation.

Implementation consequence:

- [UID:0000WU] should not emit for `ItemCatalog`.
- [UID:0000WV] can remain the exact method-pair page, but a later support pass should prefer folded `FittingRoom.cpp` placement over standalone `ItemCatalog.cpp`.
- If the supervisor wants the metadata fully normalized in a later callback, the support docs [UID:0000KD]/[UID:00006T]/[UID:0000WV] should be updated to say "embedded/folded facade preferred" rather than "standalone-vs-embedded unresolved." That is support work, not a reason to keep [UID:0000WU] emitting.

## Layout Names And Typedef Policy

Live `search_structs` for `FittingRoomCatalog`, `CatalogPart`, and `ItemCatalog` returned no IDA UDT records. Therefore the names below are source-facing descriptive names, not recovered original symbol names.

Use these names consistently in implementation text:

| Entity | Recommended source-facing name | Notes |
| --- | --- | --- |
| 0xc0-byte entry | `FittingRoomCatalogEntry` | Best file-local/embedded type name. `0xc0` is decimal 192 (Verified with `int_convert.py`). |
| category enum/key | `FittingRoomCatalogCategory` | Prefer enum/key-table wording over raw switch-table wording. |
| packed 6-byte part record | `FittingRoomCatalogPartRecord` | Proven schema is `{ part, reserved, tile, color, gender }`; byte `+0x01` is reserved/padding. |
| category lookup storage | `FittingRoomCategoryLookup` | Backing storage belongs to `FittingRoomDialogItemState::m_categoryLookup`. |
| lookup node | `FittingRoomCategoryNode` | Descriptive support name already used by helper reports. |
| transfer record | `FittingRoomCategoryTransferRecord` | Descriptive support name for insert/finalize handoff. |

Do not use generic "unresolved 0xc0 blob" wording anymore. The exact original spelling is still unproven, but the source-facing descriptive layout is good enough for child/source reports and aggregate support text.

## Child Coverage And Stale Blockers

After the executed B001/B005/B007 work, there is no remaining child-coverage reason for [UID:0000WU] to emit:

| UID | Current disposition | Effect on aggregate |
| --- | --- | --- |
| `0002E4` | `87/90`, coded, owner/emitter `000051` | Exact parser source lives in child. |
| `0002E5` | `86/91`, reconstructable, blank | Local declaration/signature issue only; exact child owns it. |
| `0002E6` | `87/89`, coded, owner/emitter `000051` | Exact category-loader source lives in child. |
| `0002E7` | `87/90`, coded, owner/emitter `000051` | Exact constructor source lives in child. |
| `0002E8` | coded transform helper after B005 | Exact transform source lives in child. |
| `0002E9` | `87/90`, coded, owner/emitter `000051` | Exact parser source lives in child. |
| `0002EA` | `88/90`, reconstructable, blank by proof | No-code duplicate-helper proof is target-specific; not an aggregate blocker. |
| `0002EB` | `87/90`, coded, owner/emitter `000051` | Exact destructor source lives in child. |
| `0002EC` | `86/90`, reconstructable, blank | Exact reset-helper child; not aggregate source. |
| `0002EF` | `86/90`, reconstructable, blank | Exact save-helper child; not aggregate source. |
| `0002EG` | coded after B001 | Exact cache-load helper source lives in child. |
| `0002EH` | `RECONSTRUCTABLE:FALSE`, no emitter | Generated switch-table data; not aggregate source. |
| `0000WV` | `86/89`, reconstructable, blank | Exact `ItemCatalog` facade child; source placement should fold into `FittingRoom.cpp`, not into the aggregate. |

Generated coverage rows still show stale scores and empty markers for several child UIDs. Let validator/tooling refresh those generated artifacts after the by-* docs are updated.

## Recommended Target Doc Changes

For `by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md`, a later implementation callback should:

- set `COMPLETION:90`;
- set `CONFIDENCE:92`;
- keep `CANONICAL_OWNER:0000JE`;
- set `RECONSTRUCTABLE:FALSE`;
- clear `EMITTER_UIDS`;
- keep the formal C++ block blank;
- rewrite `Status` / `Range Role` to call this a non-emitting fitting-room item-shop catalog index/container, not an emitting source unit;
- replace the old "reconstructable NexusTK product code" aggregate wording with "source-bearing child methods under FittingRoomDialogItemState; aggregate is non-emitting";
- preserve the child range table, but explicitly say child source and blank-C++ proofs are handled by exact child pages;
- update the no-code proof to cover child emitters, raw duplicate/no-route helper, padding, `ItemCatalog` facade, switch-table data, and JsonCpp handoff;
- replace the remaining `ItemCatalog.cpp` split question with the folded-facade decision above;
- replace generic typedef blockers with the recommended descriptive names `FittingRoomCatalogEntry` and `FittingRoomCatalogPartRecord`;
- note that generated C++/coverage/tracker staleness is validator-owned.

No aggregate C++ block should be inserted.

## Recommended Support Doc Changes

Support changes are optional unless the supervisor callback asks for them, but the following would keep the docs consistent:

- In `by-class/FittingRoomDialogItemState.md`, keep current ownership and layout names, and add a short note that [UID:0000WU] is now a non-emitting index/container while exact children remain the source-bearing pages.
- In `by-file/FittingRoom.md`, update the item-shop catalog bullet only if needed to say [UID:0000WU] is coverage/index support and source bodies route through the exact item-state children.
- In `by-file/ItemCatalog.md` and `by-class/ItemCatalog.md`, prefer folded `FittingRoom.cpp` placement for the two-method embedded facade. Keep the `ItemCatalog` class/type if useful, but do not present standalone `ItemCatalog.cpp` as equally likely after the current caller/storage evidence.
- In `by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md`, a later dedicated pass may decide whether to move the emitter route from `0000KD` to `000051` or keep `0000KD` as a facade owner with folded file placement. Either choice should not make [UID:0000WU] emit.

Generated tracker, generated C++ output, generated reports, coverage reports, and project-level generated files should be updated only by the validator/tooling.

## Validator Results

No validators were run in this report-only pass because no by-* documentation was edited. The report file itself is inside the B008 research folder and required no lease.

## Implementation Tracking Checklist

- [x] Supervisor reviews this B008 report and accepts or adjusts the recommended [UID:0000WU] reclassification.
  - Proof: supervisor assigned implementation callback `B008-implement-0000WU-FittingRoomItemShopCatalogState-source-quality-20260627` in `tools/leaser/Agents/Agent-B008/goal.md`.
- [x] Update `by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md` metadata to `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000JE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
  - Proof: target header now has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000JE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and non-emitting Item Summary. Scoped validator `python .\tools\validator.py --mode file --file by-memory\0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md --apply --wait-generated --queue-timeout 240` returned exit `0`, `ok:1`, `command_id:000000004276`, `command_timestamp:2026-06-27T11:49:06-04:00`, generated refresh completed.
- [x] Keep [UID:0000WU] `RECONSTRUCTION_CPP CODE` blank and remove the aggregate empty-emitter route.
  - Proof: target inline C++ remains `[[[]]]`, multiline C++ block is blank, `EMITTER_UIDS` is blank, and validator `000000004276` reported `autogen_registry_update` from reconstructable/empty-emitter state to nonreconstructable `false`.
- [x] Add target wording proving that [UID:0000WU] is a non-emitting address container over exact child methods, padding, raw/no-route helper proof, embedded `ItemCatalog` facade methods, switch-table data, and JsonCpp handoff.
  - Proof: target `Status`, `Range Role`, `Covered Range`, `JsonCpp Handoff`, `Caller/Callee Reachability`, `2026-06-27 B008 Non-Emitting Index Decision`, `Formal Aggregate C++ Disposition`, `Ownership Decision`, `Score Rationale`, `Open Questions`, and `Changes` sections now carry the non-emitting aggregate proof and generated-staleness notes.
- [x] Preserve exact child source ownership: do not merge `0002E4`, `0002E5`, `0002E6`, `0002E7`, `0002E8`, `0002E9`, `0002EA`, `0002EB`, `0002EC`, `0002EF`, `0002EG`, `0002EH`, or `0000WV` into aggregate C++.
  - Proof: target `Covered Range` and B008 decision text keep those exact children separate, keep padding rows explicit, keep [UID:0002EA] as a raw duplicate/no-route blank-C++ proof, keep [UID:0002EH] as switch-table data, and keep [UID:0000WV] as embedded facade methods. No child code was copied into [UID:0000WU].
- [x] Replace the remaining aggregate-level `ItemCatalog.cpp` uncertainty with the folded embedded-facade decision, or explicitly defer only the support-page metadata normalization.
  - Proof: target `Ownership Decision` now states `ItemCatalog` is a small facade folded through `FittingRoom.cpp` / `FittingRoomDialogItemState`, not a standalone `ItemCatalog.cpp` source unit for the aggregate. Support docs updated: `by-file/FittingRoom.md`, `by-file/ItemCatalog.md`, `by-class/ItemCatalog.md`, and `by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md`. Explicit exclusion: [UID:0000WV]/[UID:0000KD]/[UID:00006T] owner/emitter metadata was not forced because the goal allowed the `0000WV` page update only if needed and said not to force route changes unless current evidence and by-structure required it; the docs now record folded placement without route metadata normalization.
- [x] Use `FittingRoomCatalogEntry`, `FittingRoomCatalogPartRecord`, `FittingRoomCatalogCategory`, and `FittingRoomCategoryLookup` as descriptive source-facing names, while noting that original UDT spellings are not recovered.
  - Proof: target and `by-class/FittingRoomDialogItemState.md` preserve the accepted names, also including `FittingRoomCategoryNode` and `FittingRoomCategoryTransferRecord`, with wording that they are descriptive source-facing names because original IDA UDT spellings were not recovered.
- [x] Keep JsonCpp helpers routed to [UID:0000KI]/[UID:0000WY]/[UID:0000X0] and document only product-owned call sites in the fitting-room children.
  - Proof: target `Range Role`, `JsonCpp Handoff`, and B008 decision text keep JsonCpp code under [UID:0000KI]/[UID:0000WY]/[UID:0000X0] and describe fitting-room product methods only as callers into JsonCpp APIs.
- [x] Run the appropriate validators after any later by-* doc edits and let validator/tooling refresh generated tracker, coverage, generated C++ files, and generated reports.
  - Proof: scoped validators were run from `source-3/project-documentation` for every changed by-* file:
    - `by-memory\0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md`: `command_id:000000004276`, `command_timestamp:2026-06-27T11:49:06-04:00`, exit `0`, `ok:1`, generated refresh completed; warning was stale registry/missing-ref state for old `0000X2` path plus broad stale registry/coverage diagnostics.
    - `by-class\FittingRoomDialogItemState.md`: first run `command_id:000000004279`, `command_timestamp:2026-06-27T11:49:49-04:00`, exit `0`, `ok:1`, generated refresh completed; validator rewrote stale UID labels for old no-route split references, so those support-only references were repaired to path-only links and final run `command_id:000000004282`, `command_timestamp:2026-06-27T11:51:48-04:00`, exit `0`, `ok:1`, generated refresh completed; remaining warnings were stale renamed-entry registry paths and broad registry/coverage diagnostics.
    - `by-file\FittingRoom.md`: `command_id:000000004301`, `command_timestamp:2026-06-27T12:23:28-04:00`, exit `0`, `ok:1`, generated refresh completed; warnings were stale renamed-entry paths, `missing_ref_uid 0003AM`, and broad stale registry/coverage diagnostics.
    - `by-file\ItemCatalog.md`: `command_id:000000004302`, `command_timestamp:2026-06-27T12:23:59-04:00`, exit `0`, `ok:1`, generated refresh completed; broad stale registry/coverage diagnostics only.
    - `by-class\ItemCatalog.md`: `command_id:000000004305`, `command_timestamp:2026-06-27T12:24:19-04:00`, exit `0`, `ok:1`, generated refresh completed; broad stale registry/coverage diagnostics only.
    - `by-memory\0x00422690-0x0042273e.ItemCatalogLookup.md`: `command_id:000000004306`, `command_timestamp:2026-06-27T12:24:37-04:00`, exit `0`, `ok:1`, generated refresh completed; broad stale registry/coverage diagnostics only.
  - Generated side effects: validator-owned generated refresh completed for each scoped run and dirtied generated coverage/C++ output, including `auto-generated/-ag-*-coverage.md` and `auto-generated/NexusTK/cashshop/FittingRoom.cpp` / `auto-generated/NexusTK/cashshop/ItemCatalog.cpp`, plus broad validator-owned generated-output churn and backup/state side effects. No generated file was manually edited.
- [x] Do not manually edit generated files, coverage reports, validator/tool state, IDA DB, or unrelated docs during the implementation callback.
  - Proof: manual edits were limited to the assigned target, required support by-* docs, and this B008 report checklist. No `auto-generated/`, `project-level/`, manual `-coverage-report.md`, validator/tool state, generated C++ output, or IDA DB file was manually edited. Leases were taken only for the immediate by-* edit/validator batch; the later unlease command reported `No active lease` for all six paths because the leases had already expired, and `tools/leaser/Agents/Agent-B008/current_leases.md` shows no active B008 rows, only expired Supervisor rows from 2026-06-18.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000WU-FittingRoomItemShopCatalogState-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000WU-FittingRoomItemShopCatalogState-source-quality.md","timestamp":"2026-06-27T12:43:15","uid":"0000WU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
