** TARGET-REPORT-UID:00039M **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID00039M SelfLookPane2 Look Update Raw Helpers Source-Quality Research

## Finalized Report / Current Recommendation

- Implemented recommendation: [UID:00039M] `0x00572b60-0x00572f25` is a non-emitting exact-range index over five serially registered source-bearing `SelfLookPane2` method children. Compiler jump tables, selector maps, and alignment spans are recorded in `by-memory/-ignored.md`; the two source switches regenerate the compiler data.
- Final disposition: UID00039M is `92/94`, `RECONSTRUCTABLE:FALSE`, retains canonical semantic owner UID0000CV, and has blank emitters, position, and formal C++. Registered children UID0004Q0-UID0004Q4 are reconstructable, owned/emitted by UID0000CV, and contain the complete formal method bodies.
- Completed support closure: UID0003RE now contains `SelfLookPane2::OnPacketEvent`; UID00039N contains `SelfLookPane2::DispatchSpelledText`; UID0000CV and UID0003QZ use the established `ObjectStatusBlob m_objectStatus` contract; UID00009R exposes inherited object id through inline `GetObjectId()` and UID0000M5 documents it; UID0000NL and UID00023X are synchronized; UID00039N is `Nested:-4` after the new child subtree.
- Confidence: very strong for boundaries, bytes, behavior, owner/emitter, split, packet offsets, object-status type, field writes, switch selectors, returns, invalidation, and inline-copy liveness; strong for the descriptive method/member spellings and original physical source grouping.

## Supporting Research

- Mandatory MCP evidence was refreshed on 2026-07-14 through `http://127.0.0.1:13337/mcp`. Fresh `idb_list` returned active NexusTK database `4836cd9f`; `server_health` returned `status:ok`, image base `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache with 2067 entries. A bounded `get_bytes` at `0x00572b60` returned real target bytes beginning `55 8b ec 83 ec 44 56 8b 75 08 57 8b f9 8d 46 01`. These are evidence-time facts, not an assertion of indefinite session availability.
- Two local client-request mistakes were corrected without changing evidence: an initial PowerShell `Invoke-WebRequest` omitted `-UseBasicParsing`, and an earlier schema attempt used obsolete `address`/`size` names instead of `regions`. The corrected JSON-RPC calls succeeded; neither event was a listener, worker, or IDB outage.
- Exact binary identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, MD5 `4247E04E20B65D6414C7238AA8FF5515`. PE sections were parsed directly: `.text` RVA `0x1000`, raw `0x400`, size `0x20b600`.
- Exact old-report search terms were `UID00039M`, `00039M`, `0x00572b60`, `0x00572f25`, `0x00572c20`, `0x00572ca0`, `0x00572dd0`, `0x00572ec0`, `SelfLookPane2LookUpdateRawHelpers`, `SelfLookPane2`, `ApplySelfLookRectRecord`, `ApplySelfLookRectStateRecord`, `ApplyEquipmentSlotRecord`, `ClearEquipmentSlotRecord`, `ApplySelfLookSummaryRecord`, `ObjectStatusBlob`, `UID000179`, `UID0000CV`, and `UID0000NL`.
- Active roots searched: B001 had one matching report, `tools/leaser/Agents/Agent-B001/research/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`, SHA256 `2CE3EE16F6E01906EDF5B124C1A5C30E7EA068D6A4C0E2C4EC5FD05E6B3E6FC1`. It was active when searched and is lead-only; its relevant provisional support observation is that `LivingSpriteConfig` is stale beside the current `ObjectStatusBlob` parser contract. B002 had zero Markdown reports; B003 had one report with no direct match; B004 had no prior report; B005 had no active report.
- Central executed root contained 2,193 Markdown reports. Relevant matches opened and classified were:
  - `executed-b-agent-research/B001/0001HK-selflookpane2-source-split-audit.md`, SHA256 `C57C00E4E3E942A88062FF1EB6B29E60F46D6EAC0C8BAE52628B6172970D2FB1`: establishes the broad SelfLookPane2 split and UID00039M owner continuity but explicitly left this five-body child unchanged.
  - `executed-b-agent-research/B005/000179-ObjectStatusBlobParsers-source-quality.md`, SHA256 `157E38B6F911C803660B9F7F39E9107B8F4F6D018922504FF12C8AA4CD2B3D9D`: establishes the exact 68-byte `ObjectStatusBlob` and full/partial parser contracts; it did not close UID00039M.
  - `executed-b-agent-research/B011/0000NL-SelfLookPane-empty-emitter-family-source-quality.md`, SHA256 `367F8861FFC4DF8536BDEFB8832EC61BD218B94060D67B11F258FBF839636DCF`: supplies accepted sibling naming and source-file context but not these SelfLookPane2 bodies.
  - `executed-b-agent-research/B003/0003QZ-SelfLookPane2OnDraw-source-quality.md`, SHA256 `69DA958CD0DB4651F30859E0662E21B51493BDF2E09FDB396ECC5494A532FC4E`: establishes the 0xd90 class layout and `OnActivate`; its `LivingSpriteConfig` token is now stale against current ordinary parser/helper docs.
  - `executed-b-agent-research/B006/0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md`, SHA256 `C6360222F03B567244E6D3084C192FE97A3A1C372A47EA1DC1C70D40CA1B3988`: supplies accepted sibling equipment method/selector naming.
  - `executed-b-agent-research/B006/0002RF-SelfLookPaneSpelledTextDispatch-source-quality.md`, SHA256 `F86D170EB8910A6AD6F1BB06AC78DBB1AC8F9306EC96DDA733BA46949258D3F3`: supplies the accepted sibling `DispatchSpelledText` shape.
  - `executed-b-agent-research/B007/0002RE-SelfLookPaneSummaryStatUpdate-source-quality.md`, SHA256 `CE951521BC9046C86051A99000FDDE94FAF913C37812B3765A020BBAE672F3B4`: supplies the accepted sibling summary-mask naming direction while the exact SelfLookPane2 body proves its narrower behavior.
- `source-3/project-documentation/archived` was explicitly searched and contained zero Markdown reports and zero matches. `tools/leaser/Agents/Older-Research` contained three Markdown files and no matches. `tools/leaser/Agents/SpecialReports` contained five Markdown files and no matches. Therefore there is no direct archived/older/special UID00039M report to reconcile.
- Historical pre-callback generated readback: `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` was 37,198 bytes, SHA256 `84CD30B7F12D046A8C7A31F209205F4718660732542BF8F6D30135585EC5C6C7`, validator command `000000011961`, refreshed `2026-07-14T17:53:29-04:00`; it contained stale `LivingSpriteConfig m_spriteConfig`, no UID0003RE/UID00039N body, and one UID00039M Empty Emitter Marker. This remains historical lead evidence, not source authority.
- Post-callback generated readback after waited validator command `000000012037` at `2026-07-14T18:45:31-04:00`: `SelfLookPane.cpp` is 43,070 bytes, SHA256 `CB77313642F0178017A0A7758275ABB7880BE058E9D332934BF12FC96E7FDFBE`, with one SelfLookPane2 class, one definition each for UID0003RE, UID0004Q0-UID0004Q4, and UID00039N, zero UID00039M item/marker, zero target Empty Emitter Marker, and no handwritten jump-table, selector-map, or padding body.
- Gate 2 narrow-repair readback: independent audit at `2026-07-14T19:05:15-04:00` found one current-facing stale type phrase in UID0000NL despite all ten formal blocks passing. B004 replaced only that phrase with exact `ObjectStatusBlob`/`m_objectStatus`, scoped-validated UID0000NL as command `000000012091`, and ran waited command `000000012096` at `2026-07-14T19:04:11-04:00`. The settled `SelfLookPane.cpp` artifact is 43,070 bytes, last-write `2026-07-14T19:04:55-04:00`, SHA256 `E7EEC46F70B361B9D6F27209ED08383966F05CF6AECA7B837501AD7D81652E59`, with the same seven unique source definitions, zero UID00039M item/marker, zero stale type token, and no handwritten compiler data.

## Target

- Target UID: `00039M`.
- Target path: `by-memory/0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers.md`.
- Source queue row at assignment time: `auto-generated/-ag-research-tracker.md` Not-Covered/Reconstructable, `86/90`, reports `0`. Tracker/count state after callback is external and is not asserted here.
- Current classification: `92/94` non-reconstructable, non-emitting exact split/index over five source-method children plus two jump tables, two selector maps, and exact alignment spans.
- Current owner/emitter: canonical owner UID0000CV, blank emitters and position, `Nested:0`.
- Current formal C++ is deliberately blank. Current Item Summary records the exact five-child split, hashes, live OnPacketEvent mirrors, ObjectStatusBlob/equipment/display behavior, compiler data, padding, source ownership, and child-only emission.
- Exact target bytes: 965 bytes over `[0x00572b60,0x00572f25)`, SHA256 `3A50CCEF50F963CCBB3E9C8E8C2F6D0A3DBEDE29A8E1338A8C77F9560AB71298`.

## Current Target State

- Historical pre-callback metadata was internally inconsistent: `RECONSTRUCTABLE:TRUE` and emitter UID0000CV caused an empty marker for a mixed range that cannot have one correct source body. UID00039M is now false/non-emitting, and generated command `000000012037` emits no UID00039M item or marker.
- Historical prose had a stale first-body endpoint `0x00572c1b` and five-byte pad. The corrected target and child docs preserve that `retn 4` occupies `0x00572c1b-0x00572c1e` and only `[0x00572c1e,0x00572c20)` is padding.
- Historical broad body-3/body-4 ranges included local jump tables and selector maps. Registered source children now end at `0x00572da4` and `0x00572e88`; all table/map spans are source-excluded in `by-memory/-ignored.md` and absent as handwritten generated C++.
- All five starts are raw/no-function and have zero direct IDA xrefs, but this is not dead-code proof: modeled vtable method UID0003RE inlines exact corresponding logic for opcodes `0x33`, `0x1d`, `0x37`, `0x38`, and `0x08`.
- UID0000CV now uses `ObjectStatusBlob m_objectStatus` at `+0x108`; UID0003QZ prose/formal C++ and UID0000NL's active split summary use the same contract while UID00009S, UID0004LL/UID0004LM, and UID0003Z3 remain unchanged support anchors. A complete scan of all fifteen B004 destinations found zero other current-facing stale `LivingSpriteConfig`/`m_spriteConfig` token; remaining occurrences are explicitly historical, rejected, or superseded and paired with the accepted type.
- UID0003RE and UID00039N now contain their complete owner-routed formal bodies at `91/94` and `90/93`. UID00039N is `Nested:-4`, returning the address-sorted sequence from UID00039M's child subtree to UID00023X's sibling level.
- Implementation and scoped validation are complete. B004 edited only the accepted ordinary destinations and this report, used/released short leases, and invoked the authorized waited generated refresh. B004 performed no IDA mutation, manual-coverage edit, report execution, probe, count, move, archive, invalidation, or revalidation command. Report validation/execution/count/path/archive state remains external supervisor/validator-owned and is not asserted here.

## Executive Recommendation

- Retain direct semantic ownership and emission through `SelfLookPane2` UID0000CV and source route `NexusTK/ui/panels/SelfLookPane.cpp` UID0000NL.
- Reclassify UID00039M as the exact non-emitting split/index; do not emit a wrapper, covered-by comment, aggregate body, or compiler-data array from it.
- Serial child registration completed in ascending address order: UID0004Q0, UID0004Q1, UID0004Q2, UID0004Q3, and UID0004Q4. Every pre-registration token has been replaced before dependent cross-references were added.
- Emit complete human C++ for the five methods, UID0003RE dispatcher, and UID00039N Spelled dispatcher. The live inline mirror establishes retained source liveness despite zero surviving calls to the out-of-line copies.
- Preserve the compiler tables and alignment only as ignored binary evidence. Source `switch` statements regenerate the maps/tables; hand-authored arrays would duplicate compiler output.

## Supervisor Active Recheck

- The accepted supervisor callback covered split-first implementation of all five raw source bodies, internal tables/padding, names/types/routes, source-quality C++, and improvement beyond `86/90`.
- The broad page is no longer an emitter because no single source function owns all five bodies and embedded compiler data.
- Every source-bearing interval has a registered child and complete body. Every non-source byte is classified, and no accepted implementation item is deferred.

## Inference Research Guidance Check

- `by-structure.md` requires exact source items to receive separate pages and forbids one by-memory formal block from covering child ranges. Validator commands `000000012022`-`000000012026` assigned UID0004Q0-UID0004Q4 serially before dependent links; no UID was guessed.
- `tools/validator_README.txt` defines `Nested` as a relative delta from the previous address-sorted row, not a child count. The applied sequence keeps UID00039M at `0`, indents UID0004Q0 by `+4`, keeps UID0004Q1-UID0004Q4 at `0`, and lifts UID00039N by `-4`.
- Existing generated names and old report names were treated as leads. Direct IDA bytes/decompilation, current ordinary docs, and sibling accepted contracts control the conclusion.
- IDA fact, documentation evidence, and inference are labeled separately. Exact bytes/ranges/calls/fields are facts; `ObjectStatusBlob` is current documentation plus binary-layout evidence; helper spellings are source-facing inference aligned to accepted sibling methods.
- No Wave2/Wave3 artifact was used as authority. Historical Wave3 references in ordinary prose were treated as stale discovery history only.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and result | Classification |
| --- | --- | --- |
| One broad emitter | Five independent prologues/epilogues and one-argument `__thiscall` returns prove five source methods; tables/padding interrupt the interval. Split accepted. | Direct fact plus structural rule. |
| Raw-helper liveness | Zero start xrefs and zero PE pointer/rel32 routes are outweighed by exact inline copies in vtable-routed UID0003RE. Retained out-of-line source copy is highest probability; blank/no-code rejected. | Direct fact and bounded inference. |
| Body 1 name | Packet shape and accepted SelfLook sibling name support `ApplySelfLookRectRecord`; it copies a decoded 68-byte object-status record. | Strong inferred source name. |
| Body 2 name | Direct parse into the same field from a compact packet supports `ApplySelfLookRectStateRecord`. | Strong inferred source name. |
| Bodies 3/4 names | Selector/item/palette writes and id-only clears match sibling `ApplyEquipmentSlotRecord` / `ClearEquipmentSlotRecord`. | Strong inferred source names. |
| Body 5 name | Mask `0x40`, cached comparison fields, redraw-only behavior, and sibling contract support `ApplySelfLookSummaryRecord`. Exact semantic meaning of the two values is not recovered, so `m_displayValueA/B` remains deliberately descriptive. | Strong role, descriptive fields. |
| `+0x108` type | Current 68-byte parser type and helper signature prove `ObjectStatusBlob`; `LivingSpriteConfig` is stale. | Direct size/call contract plus current docs. |
| Object-id source access | Raw load is `dword_67A748 + 0xfc`; current docs type the global as source-facing `g_pUserPane`, with `+0xfc` inherited `ObjectPane::m_objectId`. Existing project C++ repeatedly uses `GetObjectId()`. The callback applied the small inline accessor to the complete ObjectPane declaration. | Strong source-shape inference from exact field. |
| Selector values | Only 4, 7, 8, 20, and 21 are live. Use local enum names Head, LeftAccessory, RightAccessory, LeftSubAccessory, RightSubAccessory. Do not import the larger SelfLookPane slot array. | Direct table/control-flow fact. |
| Palette clearing | Clear helper zeros only IDs; palettes remain unchanged. The C++ preserves that asymmetry. | Direct fact. |
| Body 1 discarded reads | The binary calls BE16 readers for packet `+1/+3` and performs a discarded byte lowering at `+5`. Preserve the two explicit reader calls because they survive as calls; record the byte read as historical machine behavior but do not invent a source helper or field for it. | Direct fact with source-shape judgment. |
| Invalidation | Every accepted update path calls virtual slot `+0x20` with `this+0x44`; current class conventions establish `InvalidateRect(&m_bounds)`. | Direct dispatch plus accepted source contract. |
| Return types | Each raw body ends `retn 4` and writes AL. Bodies 1/2/5 return false; bodies 3/4 return true, including unknown-selector paths after invalidation. | Direct ABI fact. |
| Dispatcher signature | UID0003RE is vtable-routed from cell `0x00624758`, reads packet pointer at event `+0x0c`, and current class/sibling contract is `bool OnPacketEvent(const PanelPacketEvent *)`. | Direct vtable/event evidence plus current contract. |
| Spelled signature | UID00039N reads an ANSI string and BE32 with cursor, updates/removes `m_spelledPane`, cleans StringBase, and returns true. `DispatchSpelledText(const unsigned char *)` matches accepted sibling source. | Direct modeled body plus sibling contract. |
| Physical source | Class and all related methods already route through UID0000NL `NexusTK/ui/panels/SelfLookPane.cpp`. Separate synthetic RawHelpers.cpp rejected. | Strong documentation/source-family evidence. |

Rejected alternatives:

- Keep UID00039M emitting one aggregate body: rejected because the interval has five source functions and compiler data.
- Leave all C++ blank because starts have no xrefs: rejected because UID0003RE contains exact live inline copies and raw retained helper policy already exists in this source family.
- Hand-emit the two 24-byte jump tables or two 18-byte maps: rejected as compiler-generated switch lowering.
- Type `+0x108` as `LivingSpriteConfig`, a byte array, or a new duplicate struct: rejected by current `ObjectStatusBlob` parser declarations, exact size, and `GetSpriteConfig(ObjectStatusBlob *)` helper.
- Use `g_pCollectionData->m_selectedObjectKey`: retained only as a historical sibling alias; current global/class docs identify the storage as `g_pUserPane` and the exact field as inherited object id.
- Access `m_objectId` directly from SelfLookPane2, cast UserPane, add friendship, or invent another global: rejected as unnecessary and less source-like than the established inline accessor.
- Assign bodies to ObjectStatusBlob, UserPane, PacketBuffer, or SpelledPane: those are dependencies; `this` writes, invalidation, vtable route, and class fields prove SelfLookPane2 ownership. UID00039N alone calls SpelledPane but remains SelfLookPane2 dispatch glue.

## Evidence Standards Used

- Highest-weight evidence: live MCP bytes, lookup results, decompilation, xrefs, vtable cells, callees, exact PE-section parsing, and whole-file pointer/branch scans.
- Strong corroboration: current by-class/by-file/by-memory declarations, exact parser pages, generated output readback, and accepted sibling method contracts.
- Lead-only evidence: active or historical reports and generated C++. Claims were rechecked before use.
- Negative evidence was used to cap liveness/name confidence, not to erase source-shaped methods when the live dispatcher proves inline copies.
- Confidence remains below 95 because original symbols, exact private method access, and the two display-value lexical names do not survive.

## Evidence Checked

- MCP: fresh `idb_list`, `server_health`, bounded target `get_bytes`, `lookup_funcs` for all five starts/dispatcher/successor/parsers/readers, `xrefs_to` for starts/tables/modeled handler, `callees` for UID0003RE, table/vtable `get_bytes`, and `decompile(0x00572120)` with addresses.
- Raw binary: exact SHA256 for the full target and every source/data/padding interval; PE section mapping; whole-file little-endian VA/RVA/raw-offset scans; executable-section E8/E9 rel32 destination scans.
- Current docs: target UID00039M; UID0000CV class; UID0000NL file; UID00023X broad parent; UID0003RE dispatcher; UID00039N Spelled helper; UID0003QZ OnActivate; UID00009S ObjectStatusBlob; UID0004LL/UID0004LM parsers; UID0003Z3 LivingObjectPane sprite-config helpers; UID00009R/UID0000M5 ObjectPane; UID0000QK/UID0001OR UserPane global/storage; SpelledPane methods; `by-memory/-ignored.md`; `by-structure.md`; validator Nested/UID registration guidance.
- Generated/manual state: historical pre-callback and post-callback waited-refresh `SelfLookPane.cpp` readbacks, plus read-only current manual `by-memory`, `by-class`, and `by-file` coverage rows for every applied score/title/type/split/support change. Manual coverage files were not edited.
- Old-report roots: active B001-B005 roots, central executed root, actual `project-documentation/archived`, Older-Research, and SpecialReports using the concrete terms listed under Supporting Research.
- Failed/skipped checks: one first PowerShell web call required `-UseBasicParsing`; one obsolete MCP request shape was corrected; one slow PowerShell whole-file scan was terminated and replaced by an equivalent bounded compiled in-memory scanner that completed. No evidence conclusion relies on a failed call. IDA mutation and function creation were intentionally prohibited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | MCP database `4836cd9f` was healthy when evidence was collected. | Very strong | idb_list, health, target bytes | Target evidence/history; retained as evidence-time fact | incorporate | applied |
| C02 | Binary identity is SHA256 `9AEC...632`, MD5 `4247...5515`. | Exact | PE file hash | UID00039M and UID0004Q0-UID0004Q4; validated 12022-12027 | incorporate | applied |
| C03 | UID00039M exact bytes are 965 bytes/SHA256 `3A50...1298`. | Exact | PE slice | UID00039M exact index; validator 12027 | incorporate | applied |
| C04 | All five starts are raw/not modeled functions. | Exact | lookup_funcs | UID00039M and five child histories; validators 12022-12027 | incorporate | applied |
| C05 | `[572b60,572c1e)` is body 1 with object-id gate, full/partial temp parse, 68-byte copy, invalidation, false. | Very strong | bytes, inline mirror | UID0004Q0; registered/validated 12022; emitted once 12037 | incorporate | applied |
| C06 | `[572c20,572ca0)` is body 2 with object-id gate, direct full/partial member parse, invalidation, false. | Very strong | bytes, inline mirror | UID0004Q1; registered/validated 12023; emitted once 12037 | incorporate | applied |
| C07 | `[572ca0,572da4)` writes five equipment id/palette pairs, always invalidates, returns true. | Very strong | bytes, table, inline mirror | UID0004Q2; registered/validated 12024; emitted once 12037 | incorporate | applied |
| C08 | `[572dd0,572e88)` clears only five equipment ids, always invalidates, returns true. | Very strong | bytes, table, inline mirror | UID0004Q3; registered/validated 12025; emitted once 12037 | incorporate | applied |
| C09 | `[572ec0,572f25)` compares optional mask-0x40 BE32 values with `+960/+964`, invalidates only on difference, stores nothing, returns false. | Very strong | bytes, inline mirror | UID0004Q4; registered/validated 12026; emitted once 12037 | incorporate | applied |
| C10 | `572da4/572dbc` and `572e88/572ea0` are compiler jump tables/maps. | Exact | bytes, local xrefs | `by-memory/-ignored.md`; validator 12034; zero generated hand-table bodies 12037 | incorporate | applied |
| C11 | Exact padding is c1e-c20, dce-dd0, eb2-ec0, and f25-f30. | Exact | bytes/hashes | `by-memory/-ignored.md`; validator 12034; zero generated padding bodies 12037 | incorporate | applied |
| C12 | Five starts have zero IDA xrefs and zero VA/RVA/raw/rel32 PE routes. | Exact | xrefs and PE scan | UID00039M and UID0004Q0-UID0004Q4 negative-evidence sections | incorporate | applied |
| C13 | UID0003RE contains exact live inline mirrors for all five bodies. | Very strong | decompile 572120 | UID0003RE/target/children; validator 12028 and generated dispatch 12037 | incorporate | applied |
| C14 | Vtable cell `0x624758 -> 0x572120` proves live dispatcher routing. | Exact | xref and vtable bytes | UID0003RE and UID0000CV; validators 12028/12030 | incorporate | applied |
| C15 | No-code/dead-helper conclusion from zero xrefs is invalid. | Strong | C12 plus C13/C14 | Rejected in UID00039M/children histories; seven source definitions verified 12037 | reject-invalid | excluded-with-reason |
| C16 | Retained out-of-line source copies are the highest-probability liveness explanation. | Strong | exact inline duplicate/source family | UID00039M, five children, UID0000NL histories | incorporate | applied |
| C17 | UID0000CV remains the direct owner/emitter for source children. | Very strong | `this` fields, invalidation, vtable | UID0004Q0-UID0004Q4/UID3RE/UID39N metadata; validators 12022-12030 | incorporate | applied |
| C18 | UID0000NL remains the source-file route. | Very strong | class/file family | UID0000NL plus all source children; validator 12032 | incorporate | applied |
| C19 | UID00023X remains a non-emitting mixed-parent index at 88/91. | Very strong | current parent and exact split | UID00023X synchronized without score/formal change; validator 12033 | incorporate | applied |
| C20 | UID00039M is 92/94 false/non-emitting with blank formal. | Very strong | exact split | UID00039M; validator 12027; blank block exact-match and zero generated marker 12037 | incorporate | applied |
| C21 | Exact body-1 child at b60-c1e is registered as UID0004Q0 at 91/93. | Very strong | C05 | UID0004Q0 assigned by validator 12022 | incorporate | applied |
| C22 | Exact body-2 child at c20-ca0 is registered as UID0004Q1 at 91/93. | Very strong | C06 | UID0004Q1 assigned by validator 12023 | incorporate | applied |
| C23 | Exact body-3 child at ca0-da4 is registered as UID0004Q2 at 92/94. | Very strong | C07 | UID0004Q2 assigned by validator 12024 | incorporate | applied |
| C24 | Exact body-4 child at dd0-e88 is registered as UID0004Q3 at 92/94. | Very strong | C08 | UID0004Q3 assigned by validator 12025 | incorporate | applied |
| C25 | Exact body-5 child at ec0-f25 is registered as UID0004Q4 at 91/93. | Very strong | C09 | UID0004Q4 assigned by validator 12026 | incorporate | applied |
| C26 | UID0003RE is 91/94 with complete OnPacketEvent C++. | Very strong | modeled/vtable body | UID0003RE; validator 12028; exact one generated definition 12037 | incorporate | applied |
| C27 | UID00039N is 90/93 with complete DispatchSpelledText C++. | Very strong | modeled body and sibling | UID00039N; validator 12029; exact one generated definition 12037 | incorporate | applied |
| C28 | `ObjectStatusBlob` is the exact 68-byte `+108` type. | Very strong | UID09S/parsers/helper | UID0000CV/UID0003QZ plus repaired UID0000NL; validators 12030-12032/12091; zero unclassified stale-token hits | incorporate | applied |
| C29 | Class field is `ObjectStatusBlob m_objectStatus`. | Strong | type/role/sibling | UID0000CV complete block; validator 12030; generated class has one ObjectStatusBlob field 12037 | incorporate | applied |
| C30 | UID0003QZ formal/prose uses `m_objectStatus`/`ObjectStatusBlob`; behavior/score are unchanged. | Strong | same field contract | UID0003QZ bounded edit; validator 12031 | incorporate | applied |
| C31 | Inline `ObjectPane::GetObjectId() const` returns `m_objectId`; scores are unchanged. | Strong | exact +fc field and broad source use | UID00009R/UID0000M5; validators 12035/12036; ObjectPane.cpp readback exact | incorporate | applied |
| C32 | Use source-facing `g_pUserPane`, not stale collection-private identity. | Very strong | current UserPane/global docs | UID0004Q0/UID0004Q1 and class/file history; stale identity excluded | reject-stale | excluded-with-reason |
| C33 | Selector names/values are Head 4, LeftAccessory 7, RightAccessory 8, LeftSubAccessory 20, RightSubAccessory 21. | Very strong | switch tables/body | UID0004Q2/UID0004Q3 and UID0000CV; validators 12024/12025/12030 | incorporate | applied |
| C34 | Preserve descriptive `m_displayValueA/B`; do not invent stat semantics. | Strong | field consumers/insufficient symbols | UID0004Q4/UID0000CV; validators 12026/12030 | incorporate | applied |
| C35 | `std::to_char_type` is byte-load lowering; do not expose it as source API. | Very strong | helper body/call pattern | Excluded from all seven formal bodies; generated readback 12037 | reject-invalid | excluded-with-reason |
| C36 | Current generated marker/type omissions are pre-callback output facts, not source authority. | Exact | before/after generated readback | Historicalized hashes 84CD...C6C7/CB77...FBE; repaired settled hash E7EE...2E59 | historicalize | applied |
| C37 | Nested sequence is target 0, UID0004Q0 +4, UID0004Q1-UID0004Q4 0, UID39N -4. | Very strong | validator README and address order | UID39M/UID4Q0-4Q4/UID39N metadata; validators 12022-12029 | incorporate | applied |
| C38 | All eight internal/following ignored spans have exact classifications/hashes. | Exact | bytes | `by-memory/-ignored.md`; validator 12034 | incorporate | applied |
| C39 | UID23X carries the synchronized child inventory without score/formal change. | Very strong | exact split | UID00023X; validator 12033 | incorporate | applied |
| C40 | Class UID0CV is 94/94 with complete helper/type closure. | Strong | complete declaration/support | UID0000CV; validator 12030; one generated class 12037 | incorporate | applied |
| C41 | File UID0NL is 92/94 with the complete source route and current ObjectStatusBlob split summary. | Strong | complete family closure | UID0000NL validators 12032 and narrow repair 12091; SHA256 `0F29235112C053EEB3F504AC3B3257D77E1DAF13CB5D3A543CE9CF7431F0DB0A` | incorporate | applied |
| C42 | Keep ObjectStatusBlob, parsers, UserPane/global, SpelledPane, UID39L/39O and vtable pages verify-only unless validator reverse links change. | Very strong | ownership boundaries | Read-only verification retained; no listed support page edited | not-applicable | excluded-with-reason |
| C43 | Manual coverage rows are stale/absent; exact supervisor-owned text must use real UIDs after registration. | Exact | manual rows read plus UID registration | Report coverage section now uses UID0004Q0-UID0004Q4; manual files untouched | incorporate | applied |
| C44 | Prior reports are corroborating leads; none directly closes UID39M. | Strong | per-root search/open results | Historical provenance retained in Supporting Research | historicalize | applied |
| C45 | Preserve rejected aggregate/no-code/hand-table/stale-type/foreign-owner alternatives. | Strong | complete evidence matrix | Target/support history and report negative evidence preserved | incorporate | applied |
| C46 | Callback and Gate 2 repair validated every changed ordinary page, replaced every temporary UID after serial registration, and completed waited SelfLookPane readbacks. | Very strong | workflow/generated route | Scoped 12022-12036 plus repair 12091; waited 12037/12096; zero stale-current tokens and all generated assertions pass | incorporate | applied |

## Positive Evidence Summary

- Five exact conventional prologue/body/`retn 4` intervals establish five independent `bool __thiscall` methods with one packet pointer argument.
- The live vtable-routed UID0003RE method contains exact semantic copies for all five opcodes, proving runtime liveness through inlining even though the retained out-of-line starts have no surviving references.
- Every write is to the complete `SelfLookPane2` object, every redraw uses its inherited bounds, and dispatcher case `0x39` calls its primary `+0x48` virtual. This is direct class ownership evidence.
- The 68-byte field size, exact parser callees, current ObjectStatusBlob declaration, and current LivingObjectPane helper signature converge on one type without a raw array or duplicate struct.
- Existing SelfLookPane sibling methods provide a coherent source-facing name family. The SelfLookPane2 variants differ only where binary behavior differs: object-id source, supported equipment selectors, return values, field set, and summary-tail behavior.
- The compiler-data bytes decode into two six-entry jump tables and identical 18-byte selector maps for selector range 4..21. This is exactly the lowering expected from the applied source switches.

## IDA MCP Facts

- Session at evidence time: active database `4836cd9f`; health `ok`; module `NexusTK.exe`; image base `0x00400000`; analysis/Hex-Rays/strings ready.
- `lookup_funcs` results: `0x572b60`, `0x572c20`, `0x572ca0`, `0x572dd0`, and `0x572ec0` are not functions. `0x572120` is `sub_572120`, size `0x4cd`; `0x572f30` is `sub_572F30`, size `0x9f`.
- Callee identities: `0x575480` is the BE16 reader; `0x5754c0` is the BE32 reader; `0x575470` is compiler/runtime narrow-byte lowering; `0x4d1fa0` is full ObjectStatusBlob parse; `0x4d2640` is partial parse. UID0003RE also calls ANSI-string/cursor/StringBase/SpelledPane helpers at `0x575a10`, `0x575790`, `0x584540`, `0x56bca0`, `0x56be20`, and `0x582b70`.
- Exact range hashes:

| Interval | Length | SHA256 | Classification |
| --- | ---: | --- | --- |
| `572b60-572c1e` | 190 | `F4BC106573BFFF23BCD0BA80CF7DC7C93876E1B963A0C32507031A182766D41B` | source body 1 |
| `572c1e-572c20` | 2 | `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2` | `cc` padding |
| `572c20-572ca0` | 128 | `D62EBD3A95C7F93F5541139CD9DC0A94DA2EBA99CEDC9899C6F5238420C3DB84` | source body 2 |
| `572ca0-572da4` | 260 | `9085D3B93F45E3B55FA028C16A3E8B0425CD055EF74E070E5EDAECF7FFA2FB36` | source body 3 |
| `572da4-572dbc` | 24 | `CC865EAD3DF805A24323ECEE7C55CAC401CECF40D615A0FDA91EF8C51FF4669D` | jump table |
| `572dbc-572dce` | 18 | `66D86680FB7B74D686E6C41CD49343254F6EF2F929FC10128045E10085C668F9` | selector map |
| `572dce-572dd0` | 2 | `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2` | `cc` padding |
| `572dd0-572e88` | 184 | `9611B33B1D59CE4C4CA41B80C3A16CDC37E6D0F0D34E47DFCB38C9A01BD463A9` | source body 4 |
| `572e88-572ea0` | 24 | `C9A7D2FB073B77EEC0F49944DD2475953D4C41EBEF5DA2F369C306E1853852CE` | jump table |
| `572ea0-572eb2` | 18 | `66D86680FB7B74D686E6C41CD49343254F6EF2F929FC10128045E10085C668F9` | selector map |
| `572eb2-572ec0` | 14 | `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356` | `cc` padding |
| `572ec0-572f25` | 101 | `6A6A1C457E0C88836FAF018655E9B1350CCE4BEB87C21BD76EE6E02FA4FC531F` | source body 5 |
| `572f25-572f30` | 11 | `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943` | following `cc` padding |

- Table `0x572da4` contains destinations `572cf0, 572d14, 572d38, 572d5c, 572d80, 572d90`; table `0x572e88` contains `572e00, 572e1b, 572e36, 572e51, 572e6c, 572e75`. Both selector maps are bytes `00 05 05 01 02 05 05 05 05 05 05 05 05 05 05 05 03 04`.
- Xrefs: all five starts have zero xrefs. `0x572da4` has one local data xref from `0x572ce9`; `0x572dbc` from `0x572ce2`; `0x572e88` from `0x572df9`; `0x572ea0` from `0x572df2`. UID0003RE has one data xref from vtable cell `0x624758`.
- Vtable bytes at `0x624740` include `0x572120` at cell `0x624758`, consistent with the current `OnPacketEvent` declaration.
- Whole-PE negative scan results:

| Start | Raw offset | VA hits | RVA hits | Raw-offset hits | E8/E9 rel32 destinations |
| --- | ---: | ---: | ---: | ---: | ---: |
| `0x572b60` | `0x171f60` | 0 | 0 | 0 | 0 |
| `0x572c20` | `0x172020` | 0 | 0 | 0 | 0 |
| `0x572ca0` | `0x1720a0` | 0 | 0 | 0 | 0 |
| `0x572dd0` | `0x1721d0` | 0 | 0 | 0 | 0 |
| `0x572ec0` | `0x1722c0` | 0 | 0 | 0 | 0 |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `5729e0-573232` | UID00023X | mixed neighborhood index | false | none | 88/91 unchanged | keep |
| `5729e0-572b54` | UID00039L | packet-send raw helpers | true | UID0000CV | 85/89 unchanged | verify-only |
| `572b60-572f25` | UID00039M | exact five-method/data split index | false | UID0000CV | 92/94 | reclassify |
| `572b60-572c1e` | UID0004Q0 | `ApplySelfLookRectRecord` | true | UID0000CV | 91/93 | registered first; implementation validation `000000012022` |
| `572c20-572ca0` | UID0004Q1 | `ApplySelfLookRectStateRecord` | true | UID0000CV | 91/93 | registered second; implementation validation `000000012023` |
| `572ca0-572da4` | UID0004Q2 | `ApplyEquipmentSlotRecord` | true | UID0000CV | 92/94 | registered third; implementation validation `000000012024` |
| `572dd0-572e88` | UID0004Q3 | `ClearEquipmentSlotRecord` | true | UID0000CV | 92/94 | registered fourth; implementation validation `000000012025` |
| `572ec0-572f25` | UID0004Q4 | `ApplySelfLookSummaryRecord` | true | UID0000CV | 91/93 | registered fifth; implementation validation `000000012026` |
| `572f30-572fcf` | UID00039N | `DispatchSpelledText` | true | UID0000CV | 90/93 | complete formal/Nested -4 |
| `572fd0-573232` | UID00039O | SpelledPane vector insert | true | UID0000DK | 87/91 unchanged | verify-only |
| `572120-5725ed` | UID0003RE | vtable-routed `OnPacketEvent` | true | UID0000CV | 91/94 | complete formal |

The five pre-registration tokens have been replaced everywhere in this report and its supervisor-owned coverage text with validator-assigned UIDs 0004Q0-0004Q4. These are now exact registered references.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x624758` | data cell -> `0x572120` | live `SelfLookPane2` packet virtual route |
| `0x572120` case `0x33` | inline mirror of body 1 | retained `ApplySelfLookRectRecord` source liveness |
| `0x572120` case `0x1d` | inline mirror of body 2 | retained `ApplySelfLookRectStateRecord` source liveness |
| `0x572120` case `0x37` | inline mirror of body 3 | retained equipment apply source liveness |
| `0x572120` case `0x38` | inline mirror of body 4 | retained equipment clear source liveness |
| `0x572120` case `0x08` | inline mirror of body 5 | retained summary compare source liveness |
| `0x572120` case `0x39` | primary virtual `+0x48` | `SelfLookPane2::OnActivate(packet)` |
| `0x572120` case `0x3a` | inline StringBase/Spelled dispatch | source equivalent of UID00039N |
| five raw starts | no IDA xref or PE route | inlined retained copies, not live call targets |
| four table starts | one local data xref each | compiler-local switch lowering only |

## Documentation Evidence And IDA Status

- Current UID00009S documents an exact naturally aligned 68-byte ObjectStatusBlob and all offsets copied by body 1. UID0004LL/UID0004LM own full/partial parsing.
- Current UID0003Z3 formal declaration is `void LivingObjectPane::GetSpriteConfig(ObjectStatusBlob *out) const`, directly contradicting the stale SelfLookPane2 `LivingSpriteConfig` spelling while preserving the historical helper method name.
- UID0000CV maps equipment id/palette fields at `+14c..+15d` and display fields at `+960/+964`; the callback supplied the corrected status field and six missing method declarations while preserving those established offsets.
- Current UserPane docs establish source-facing global name `g_pUserPane`; constructor/destructor are the only global writers, and `+0xfc` is inherited ObjectPane object id.
- UID00009R now defines inline `GetObjectId() const` over `m_objectId`; this makes existing emitted sources and UID0004Q0/UID0004Q1 coherent without creating an out-of-line binary function requirement. UID0000M5 records the separate ObjectList friendship/direct-access route.
- Historical pre-callback generated output had one UID00039M empty marker, no UID0003RE/UID00039N definitions, and a stale class field type. Waited command `000000012037` removed all target closure defects; unrelated generated empty markers remain outside scope.
- Current manual by-memory coverage has a stale UID00023X `76%` broad row and omits UID00039L/M/N/O, UID0003RE, all five new children, and internal ignored spans. Current class/file rows still say LivingSpriteConfig and omit this closure.

## Ranked Ownership Analysis

### 1. UID0000CV SelfLookPane2 through UID0000NL SelfLookPane

- Evidence for: every body receives `SelfLookPane2 *this`, updates exact class fields, invalidates inherited class bounds, matches the class's live packet virtual, and sits in the SelfLookPane2-local address family. Existing class/file route is valid and above gate.
- Evidence against: exact original physical filename and private/public helper access do not survive.
- Decision: accepted direct semantic owner/emitter and source route.

### 2. File-local free helpers in SelfLookPane.cpp

- Evidence for: raw starts have no `this` type records in IDA and no callers.
- Evidence against: ECX is used as `SelfLookPane2 *`, bodies access private fields, and live inline copies are inside a class virtual. Free helpers would require friendship or raw offsets absent from plausible source.
- Decision: rejected.

### 3. ObjectStatusBlob, UserPane, PacketBuffer, or SpelledPane ownership

- Evidence for: methods consume these dependencies.
- Evidence against: none receives ownership-defining `this`; only SelfLookPane2 state is mutated. UID00039N's child call is dispatch glue, not SpelledPane implementation ownership.
- Decision: rejected as dependency-only.

### Proposed new file/grouping, if applicable

- No new source file was required. The five registered by-memory method pages remain under existing `SelfLookPane2`/`SelfLookPane.cpp` ownership.
- A synthetic `SelfLookPane2RawHelpers.cpp`, table module, or ObjectStatusBlob consumer module would model reverse-engineering boundaries rather than likely source.

## Source Placement

- Applied placement: declarations are in the complete UID0000CV `SelfLookPane2` class block; method definitions emit through UID0000NL to `NexusTK/ui/panels/SelfLookPane.cpp`.
- This matches constructor/destructor, activation, paint/input, packet, geometry, and sibling SelfLookPane placement already documented and generated.
- ObjectStatusBlob remains declared/emitted by UID00009S/UID0000M6. ObjectPane's inline accessor remains in its own class/header route. UserPane and SpelledPane remain dependencies.
- Remaining uncertainty is lexical/physical only and caps scores; it does not block the coherent existing source route.

## Range / Split / Padding / Reclassification Analysis

- UID00039M is an audit/index after splitting; it is not itself a source-level declaration or body, so `RECONSTRUCTABLE:FALSE` is required even though all five exact children are reconstructable.
- Exact source children are `[572b60,572c1e)`, `[572c20,572ca0)`, `[572ca0,572da4)`, `[572dd0,572e88)`, and `[572ec0,572f25)`.
- Exact compiler/ignored ranges are `[572c1e,572c20)`, `[572da4,572dbc)`, `[572dbc,572dce)`, `[572dce,572dd0)`, `[572e88,572ea0)`, `[572ea0,572eb2)`, `[572eb2,572ec0)`, and following `[572f25,572f30)`.
- Body 2 ends exactly at `0x572ca0`; there is no `0x572c9d-0x572ca0` pad. Body 4 includes a final NOP at `0x572e87`; its table begins at `0x572e88`.
- Existing UID00023X stays false/non-emitting and gains the precise split inventory. Existing UID00039O remains under SpelledPane.

## Negative Evidence Summary

- No function records exist at the five starts; no direct/data xrefs, encoded VA/RVA/raw pointers, or executable E8/E9 routes target them.
- No vtable cell targets the five starts. The only live vtable route is UID0003RE.
- No code outside the two switch bodies references their local tables/maps.
- No field evidence supports new stats-specific names for `+960/+964`; descriptive names are retained.
- No evidence supports a source array for the compiler tables, a second ObjectStatusBlob type, direct protected-member access, a cast/friend workaround, a new file, or foreign ownership.
- No direct prior report closes this target. Prior reports are family/type/name evidence only.

## IDA Rename / Type / Comment Recommendations

- If a future supervisor separately authorizes IDA edits, rename the five raw starts to `SelfLookPane2__ApplySelfLookRectRecord`, `SelfLookPane2__ApplySelfLookRectStateRecord`, `SelfLookPane2__ApplyEquipmentSlotRecord`, `SelfLookPane2__ClearEquipmentSlotRecord`, and `SelfLookPane2__ApplySelfLookSummaryRecord`; type each as `bool __thiscall(SelfLookPane2 *, const unsigned char *)`.
- Rename `sub_572120` to `SelfLookPane2__OnPacketEvent` with `bool __thiscall(SelfLookPane2::EventHandlerFacet *, const PanelPacketEvent *)` or the IDA-compatible complete-object adjusted equivalent; preserve the `-0xa0` facet adjustment in comments.
- Rename `sub_572F30` to `SelfLookPane2__DispatchSpelledText`.
- Apply `ObjectStatusBlob` to `SelfLookPane2+0x108`, equipment id/palette names to `+14c..+15d`, and descriptive display-value names to `+960/+964`.
- Comment the two jump-table/map pairs as compiler-generated selector-4..21 switch data. Do not create source globals for them.
- IDA edits were not requested and none were performed.

## First-Draft C++ Recommendation

- Eligible: five exact new source children, UID0003RE, UID00039N, complete UID0000CV declaration, and bounded UID00009R inline accessor support.
- UID00039M itself is not eligible after split and must use the exact blank managed block below.
- UID0003QZ already had a complete formal body. The callback preserved that managed body byte-for-byte except for its one formal `m_spriteConfig` to `m_objectStatus` replacement and the matching prose/summary `LivingSpriteConfig` to `ObjectStatusBlob` correction; it did not otherwise rewrite, reorder, or compress the accepted body.
- Third-party import directives are not applicable; all code is NexusTK-owned source.

### UID00039M exact blank managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0000CV complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfLookPane2 : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    SelfLookPane2();
    virtual ~SelfLookPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual bool OnPaint();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleEvent(const PanelMouseEvent *event);
    virtual bool OnPacketEvent(const PanelPacketEvent *event);

    void ShowDefaultView();
    void ShowSpelledView();
    void ShowProfileView();
    void ShowLegendView();
    void DrawStatText();
    void GetButtonRect(int buttonId, RectBounds *bounds) const;
    unsigned short HitTestButton(int x, int y) const;

    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_objectStatus;

    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_displayValueA;
    unsigned int m_displayValueB;
    unsigned char m_activationState0;
    unsigned char m_activationState1;
    unsigned char m_activationState2;
    unsigned int m_activationValue;
    unsigned int m_lastToggleTick;
    unsigned int m_toggleRepeatDelay;
    unsigned char m_equipmentToggleState;
    unsigned char m_lookToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_viewMode;
    int m_profileState;
    int m_reservedViewState;
    int m_buttonFrameA;
    int m_buttonFrameB;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00009R complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum ObjectPaneType
{
    kObjectPaneTypeItem = 0,
    kObjectPaneTypeFlying = 1,
    kObjectPaneTypePrimaryEffect = 2,
    kObjectPaneTypeLiving = 3,
    kObjectPaneTypeSecondaryEffect = 4,
    kObjectPaneTypeStatic = 5,
    kObjectPaneTypeBalloon = 6,
    kObjectPaneTypeHitBar = 7,
    kObjectPaneTypeDamageNumber = 8,
    kObjectPaneTypeObjectInfo = 9,
    kObjectPaneTypeLighting = 10,
    kObjectPaneTypeSound = 11
};

class ObjectList;
class SoundObjectPane;
class GrafPort;
struct MapPoint;

class ObjectPane : public Pane
{
    friend class ObjectList;

public:
    ObjectPane(unsigned char objectType,
               int objectId,
               int mapX,
               int mapY);
    virtual ~ObjectPane() = 0;

    MapPoint *GetMapPosition(MapPoint *outPosition) const;
    int GetObjectId() const
    {
        return m_objectId;
    }
    ObjectPane *GetAttachedObject() const;
    void SetSoundObjectPane(SoundObjectPane *soundObjectPane);
    void ClearSoundObjectPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *clipBounds);
    virtual void AttachObject(ObjectPane *attachedObject);
    virtual void DetachObject();
    virtual void ClearOutputRects(RectBounds *firstBounds,
                                  RectBounds *secondBounds);
    virtual void SetObjectData(const RectBounds *objectData);
    virtual RectBounds *GetObjectData(RectBounds *outObjectData) const;
    virtual void RenderFrame(GrafPort *target,
                             const RectBounds *bounds)
    {
    }
    virtual RectBounds *GetEmptyRect(RectBounds *outBounds) const;
    virtual void DrawSpriteFrame(GrafPort *target,
                                 const RectBounds *bounds)
    {
    }
    virtual void SetMapPosition(int mapX, int mapY);

protected:
    unsigned char m_objectType;
    int m_objectId;
    int m_mapX;
    int m_mapY;
    RectBounds m_objectDataRect;
    ObjectPane *m_attachedObject;
    float m_attachmentHeightOffset;
    SoundObjectPane *m_soundObjectPane;
    unsigned char m_transientObjectFlag;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavioral exactness: the C++ preserves all packet offsets, parser modes, return values, writes/non-writes, selector default behavior, palette retention, and invalidation. Compiler SEH/register allocation/jump tables/narrow-char lowering are intentionally not handwritten.
- Source-shape rationale: simple class methods, local enums, typed value objects, inline base accessor, and existing sibling naming fit the established late-1990s/2000s codebase better than raw offsets, decompiler temporaries, or table arrays.
- Name confidence: method names are descriptive but family-consistent; `m_displayValueA/B` remains intentionally generic. No unresolved naming issue blocks exact behavior.

### UID0004Q0 registered child managed block

Destination: `by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane2::ApplySelfLookRectRecord(const unsigned char *packet)
{
    PacketBufferReadUInt16BE(packet + 1);
    PacketBufferReadUInt16BE(packet + 3);

    if (PacketBufferReadUInt32BE(packet + 6) != g_pUserPane->GetObjectId())
        return false;

    const unsigned char mode = packet[10];
    ObjectStatusBlob decoded;
    if (mode == 0)
        decoded.ParseFullStatus(packet + 11);
    else if (mode == 1)
        decoded.ParsePartialStatus(packet + 11);
    else
        return false;

    m_objectStatus = decoded;
    InvalidateRect(&m_bounds);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0004Q1 registered child managed block

Destination: `by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane2::ApplySelfLookRectStateRecord(const unsigned char *packet)
{
    if (PacketBufferReadUInt32BE(packet + 1) != g_pUserPane->GetObjectId())
        return false;

    const unsigned char mode = packet[5];
    if (mode == 0)
        m_objectStatus.ParseFullStatus(packet + 6);
    else if (mode == 1)
        m_objectStatus.ParsePartialStatus(packet + 6);
    else
        return false;

    InvalidateRect(&m_bounds);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0004Q2 registered child managed block

Destination: `by-memory/0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane2::ApplyEquipmentSlotRecord(const unsigned char *packet)
{
    enum EquipmentSelector
    {
        EquipmentSelector_Head = 4,
        EquipmentSelector_LeftAccessory = 7,
        EquipmentSelector_RightAccessory = 8,
        EquipmentSelector_LeftSubAccessory = 20,
        EquipmentSelector_RightSubAccessory = 21
    };

    const unsigned char selector = packet[1];
    const unsigned short itemId = PacketBufferReadUInt16BE(packet + 2);
    const unsigned char palette = packet[4];

    switch (selector)
    {
    case EquipmentSelector_Head:
        m_headId = itemId;
        m_headPalette = palette;
        break;

    case EquipmentSelector_LeftAccessory:
        m_leftAccessoryId = itemId;
        m_leftAccessoryPalette = palette;
        break;

    case EquipmentSelector_RightAccessory:
        m_rightAccessoryId = itemId;
        m_rightAccessoryPalette = palette;
        break;

    case EquipmentSelector_LeftSubAccessory:
        m_leftSubAccessoryId = itemId;
        m_leftSubAccessoryPalette = palette;
        break;

    case EquipmentSelector_RightSubAccessory:
        m_rightSubAccessoryId = itemId;
        m_rightSubAccessoryPalette = palette;
        break;

    default:
        break;
    }

    InvalidateRect(&m_bounds);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0004Q3 registered child managed block

Destination: `by-memory/0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane2::ClearEquipmentSlotRecord(const unsigned char *packet)
{
    enum EquipmentSelector
    {
        EquipmentSelector_Head = 4,
        EquipmentSelector_LeftAccessory = 7,
        EquipmentSelector_RightAccessory = 8,
        EquipmentSelector_LeftSubAccessory = 20,
        EquipmentSelector_RightSubAccessory = 21
    };

    switch (packet[1])
    {
    case EquipmentSelector_Head:
        m_headId = 0;
        break;

    case EquipmentSelector_LeftAccessory:
        m_leftAccessoryId = 0;
        break;

    case EquipmentSelector_RightAccessory:
        m_rightAccessoryId = 0;
        break;

    case EquipmentSelector_LeftSubAccessory:
        m_leftSubAccessoryId = 0;
        break;

    case EquipmentSelector_RightSubAccessory:
        m_rightSubAccessoryId = 0;
        break;

    default:
        break;
    }

    InvalidateRect(&m_bounds);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0004Q4 registered child managed block

Destination: `by-memory/0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane2::ApplySelfLookSummaryRecord(const unsigned char *packet)
{
    unsigned int displayValueA = m_displayValueA;
    unsigned int displayValueB = m_displayValueB;

    if ((packet[1] & 0x40) != 0)
    {
        displayValueA = PacketBufferReadUInt32BE(packet + 7);
        displayValueB = PacketBufferReadUInt32BE(packet + 11);
    }

    if (displayValueA != m_displayValueA ||
        displayValueB != m_displayValueB)
    {
        InvalidateRect(&m_bounds);
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID0003RE complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane2::OnPacketEvent(const PanelPacketEvent *event)
{
    const unsigned char *packet = event->packet;

    switch (packet[0])
    {
    case 0x08:
        return ApplySelfLookSummaryRecord(packet);

    case 0x1d:
        return ApplySelfLookRectStateRecord(packet);

    case 0x33:
        return ApplySelfLookRectRecord(packet);

    case 0x37:
        return ApplyEquipmentSlotRecord(packet);

    case 0x38:
        return ClearEquipmentSlotRecord(packet);

    case 0x39:
        OnActivate(packet);
        return true;

    case 0x3a:
        return DispatchSpelledText(packet);

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00039N complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane2::DispatchSpelledText(const unsigned char *packet)
{
    int cursor = 1;

    StringBase text;
    PacketBufferReadAnsiString8(&text, packet, &cursor);

    const int value = PacketBufferReadUInt32BE(packet, &cursor);
    if (value == 0)
        m_spelledPane->RemoveEntry(text.c_str(), 0);
    else
        m_spelledPane->AddOrUpdateEntry(text.c_str(), value, 0);

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```
## Final Recommendation

- The five-child serial split is complete. UID0004Q0-UID0004Q4 were assigned in ascending address order and all temporary UID tokens were replaced before dependent links.
- UID00039M is a false/non-emitting 92/94 split index with exact evidence and blank C++.
- UID0003RE and UID00039N source C++ is complete; UID0000CV, UID0003QZ, UID0000NL, UID00023X, UID00009R, UID0000M5, and `by-memory/-ignored.md` are synchronized at report-level detail.
- ObjectStatusBlob/parsers, UserPane/global storage, SpelledPane methods, UID00039L, UID00039O, vtables, and unrelated siblings remained verify-only.
- There is no in-scope future research item. Remaining original lexical/physical-file uncertainty is documented as a score cap, not deferred work.

## Recommended Target Doc Changes

- Path: `by-memory/0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers.md`.
- Metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000CV`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, exact blank managed block, `Nested:0`.
- Item Summary: `Non-emitting exact split/index for five SelfLookPane2 packet-update methods; records exact raw boundaries and hashes, live OnPacketEvent inline mirrors, ObjectStatusBlob/equipment/display-field behavior, compiler switch tables/maps, padding, source ownership, and child-only emission.`
- Applied detail: stale boundary prose is historicalized, all exact intervals/hashes and real child UIDs are recorded, and full/partial parser details, owner/file route, negative-route evidence, inline-copy liveness, historical boundaries, and rejected aggregate/no-code/table alternatives are preserved.
- The parent formal block remains exactly blank; no child body, covered-by marker, or table declaration was inserted.

## Recommended Support Doc Changes

| Support path | Applied change | Score/metadata disposition |
| --- | --- | --- |
| UID0004Q0-UID0004Q4 child paths listed above | Registered serially by 12022-12026 before links; exact metadata, summary, bytes/hash/ABI/behavior/evidence and managed bodies applied | 91/93, 91/93, 92/94, 92/94, 91/93; owner/emitter UID0CV; true; first Nested +4, rest 0 |
| `by-memory/0x00572120-0x005725ed.SelfLookPane2PacketEventHelper.md` UID3RE | Complete opcode dispatch, event+0x0c/vtable/facet/callee evidence and formal body applied | 86/90 -> 91/94; owner/emitter unchanged; Nested0 |
| `by-memory/0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch.md` UID39N | Exact StringBase/cursor/BE32/Spelled add-remove/true-return body, summary, and evidence applied | 86/90 -> 90/93; owner/emitter unchanged; Nested -4 |
| `by-class/SelfLookPane2.md` UID0CV | Complete block, six helper declarations, ObjectStatusBlob/m_objectStatus field, and method/layout/split/history applied | 93/94 -> 94/94 |
| `by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md` UID3QZ | Existing complete body/prose changed only from stale `m_spriteConfig`/`LivingSpriteConfig` to `m_objectStatus`/`ObjectStatusBlob` | score/metadata/Nested unchanged 92/94/0 |
| `by-file/SelfLookPane.md` UID0NL | Five children, dispatcher/Spelled closure, ObjectStatusBlob correction, compiler-data exclusions, and generated result applied; Gate 2 repair corrected the active UID0003QZ split sentence to exact 68-byte `ObjectStatusBlob m_objectStatus` truth | 91/93 -> 92/94 |
| `by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md` UID23X | Exact non-emitting parent/five-child/internal-data inventory applied; mixed ownership and UID39O route preserved | 88/91 false/Nested0/formal unchanged |
| `by-memory/-ignored.md` | Eight exact rows with bytes/hashes and compiler/padding disposition applied | control page; no reconstruction metadata |
| `by-class/ObjectPane.md` UID09R | Complete block rebased with inline `GetObjectId`; exact +fc return and consumer consistency documented | score/metadata unchanged 92/94 |
| `by-file/ObjectPane.md` UID0M5 | Inline accessor/header contract and UID0004Q0/UID0004Q1 consumers documented; source path and unrelated content preserved | score unchanged 91/92 |

Verify-only paths remained unchanged: UID00009S ObjectStatusBlob, UID0004LL/UID0004LM parsers, UID0003Z3 LivingObjectPane sprite helpers, UID0000QK/UID0001OR UserPane global/storage, UID0000DK SpelledPane, UID00039L packet send, UID00039O vector insert, UID0001HK main split, and SelfLookPane2 vtable pages. Validator-managed reverse-link side effects were limited to accepted UID0000NL/`by-memory/-ignored.md` pages and are recorded under Validator Results.

## Score And Metadata Recommendation

| Item | Historical pre-callback | Applied current state | Rationale |
| --- | --- | --- | --- |
| UID00039M | 86/90, true, emits UID0CV | 92/94, false, no emitter | exact split/data/padding/liveness/source disposition complete |
| UID0004Q0 body 1 | absent | 91/93, true, UID0CV | exact bytes/body/inline mirror; names inferred |
| UID0004Q1 body 2 | absent | 91/93, true, UID0CV | exact bytes/body/inline mirror; names inferred |
| UID0004Q2 body 3 | absent | 92/94, true, UID0CV | exact selectors/fields/table/mirror |
| UID0004Q3 body 4 | absent | 92/94, true, UID0CV | exact selectors/id-only clears/table/mirror |
| UID0004Q4 body 5 | absent | 91/93, true, UID0CV | exact comparison behavior; value semantics remain descriptive |
| UID0003RE | 86/90 | 91/94 | complete vtable/signature/opcode/body/callee contract |
| UID00039N | 86/90 | 90/93 | complete modeled body; source name inferred |
| UID0000CV | 93/94 | 94/94 | complete helper surface and corrected status type |
| UID0000NL | 91/93 | 92/94 | complete SelfLookPane2 packet-update route |
| UID00009R / UID0000M5 | 92/94 / 91/92 | unchanged | small support accessor closes consistency but does not justify broader rescore |

- Score blockers researched: raw starts/liveness, exact boundaries, tables/padding, source signatures, packet fields, status type, owner/emitter, source file, helper names, summary fields, object-id access, dispatcher route, Spelled route, generated pollution, and manual coverage. All are resolved to exact fact, bounded inference, or explicit lexical confidence cap.
- Scores remain below 95 because no symbols prove original method/member spellings, private/public access, or physical source file, and `m_displayValueA/B` semantics remain descriptive.

## Open Questions With Attempted Resolution

- Are zero-xref bodies dead? No. Exact inline mirrors in the live vtable method prove behavior is used; the out-of-line copies are retained source/compiler output.
- Is `+0x108` a LivingSpriteConfig? No. Exact 68-byte ObjectStatusBlob parser/helper contracts supersede that stale alias.
- Which object id is compared? `g_pUserPane`'s inherited ObjectPane id at `+0xfc`; use inline `GetObjectId()` rather than collection-private or raw-offset syntax.
- Why does body 1 read packet `+1/+3/+5` but use only object id/mode/status? Two BE16 calls survive and are preserved. The discarded byte lowering has no named semantic evidence and is documented without inventing a fake source field.
- What do `+960/+964` mean? They are exact cached display values copied from UserStatus during OnActivate and compared by body 5. No stronger semantic names survive; descriptive A/B names are safest and do not affect exact C++.
- Were the five methods public or private? Symbols do not survive. Placing declarations on the current public helper surface follows the sibling class and avoids inventing friend/free-function machinery; this lexical uncertainty caps confidence only.
- Any unresolved blocker affecting code, split, owner, range, or score? No. Remaining uncertainty is bounded naming/physical-placement uncertainty already reflected in scores.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The current manual files inspected read-only were `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md`. The generated `auto-generated/-ag-*` rows were not treated as manual coverage and are not edited or given replacement text.

The following five rows now use the exact validator-assigned UIDs 0004Q0-0004Q4. They were converted from pre-registration templates immediately after serial registration and are ready for later supervisor-owned manual coverage application.

### `by-memory/-coverage-report.md`

Replace the current UID0003QZ row with:

```text
        - [UID:0003QZ][0x005700e0-0x0057092c.SelfLookPane2OnActivate](by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md) 0x005700e0-0x0057092c | virtual method | SelfLookPane2OnActivate : reconstructable : 92% : very-strong : Exact primary +0x48 OnActivate override with 0x84c/2124-byte hash/bounds, packet text/state/equipment/status/toggle parsing, 68-byte ObjectStatusBlob, SpelledPane parser call, LegendPane rich-text rows, child lifecycle, mode restore, compiler exclusions, complete 0xd90 field mapping, and formal C++.
```

Insert after current UID0003RD and before the `0x005729c3` ignored-tail row:

```text
        - [UID:0003RE][0x00572120-0x005725ed.SelfLookPane2PacketEventHelper](by-memory/0x00572120-0x005725ed.SelfLookPane2PacketEventHelper.md) 0x00572120-0x005725ed | virtual method | SelfLookPane2OnPacketEvent : reconstructable : 91% : very-strong : Exact EventHandler-facet packet virtual with vtable cell 0x00624758, event payload at +0x0c, opcodes 0x08/0x1d/0x33/0x37/0x38/0x39/0x3a, five source-helper dispatches, OnActivate and Spelled routes, bool returns, complete formal C++, and compiler-only inline lowering excluded.
```

Replace the current single stale UID00023X row with this complete block. All former pre-registration templates below contain the real validator-assigned UIDs:

```text
    - [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) 0x005729e0-0x00573232 | mixed helper split/index | LookPanePacketAndEntryVectorHelpers : not_reconstructable : 88% : very-strong : Non-emitting mixed neighborhood index over SelfLookPane2 packet/update methods, compiler tables/padding, SelfLookPane2 Spelled dispatch, and SpelledPane vector insertion; exact children carry source ownership and emission.
        - [UID:00039L][0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers](by-memory/0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers.md) 0x005729e0-0x00572b54 | retained raw source helpers | SelfLookPane2PacketSendRawHelpers : reconstructable : 85% : strong : Three raw SelfLookPane2 packet-send helper bodies for option subtypes 0x02, 0x08, and 0x0b; owner/emitter remains SelfLookPane2.
        - [UID:00039M][0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers](by-memory/0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers.md) 0x00572b60-0x00572f25 | non-emitting exact split/index | SelfLookPane2LookUpdateRawHelpers : not_reconstructable : 92% : very-strong : Five exact SelfLookPane2 packet-update source methods with live OnPacketEvent inline mirrors, ObjectStatusBlob/equipment/display behavior, compiler switch tables/maps, exact padding, and child-only emission.
            - [UID:0004Q0][0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord](by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md) 0x00572b60-0x00572c1e | retained source method | SelfLookPane2ApplySelfLookRectRecord : reconstructable : 91% : very-strong : Exact object-id-gated full/partial ObjectStatusBlob temporary parse, 68-byte member copy, invalidation, false return, raw no-xref retained-copy evidence, and complete formal C++.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00572c1e-0x00572c20 | padding | SelfLookPane2 look-record to state-record alignment : ignored : 100% : strong : Two 0xcc bytes, SHA256 E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2.
            - [UID:0004Q1][0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord](by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md) 0x00572c20-0x00572ca0 | retained source method | SelfLookPane2ApplySelfLookRectStateRecord : reconstructable : 91% : very-strong : Exact object-id-gated direct full/partial ObjectStatusBlob member parse, invalidation, false return, raw no-xref retained-copy evidence, and complete formal C++.
            - [UID:0004Q2][0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord](by-memory/0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord.md) 0x00572ca0-0x00572da4 | retained source method | SelfLookPane2ApplyEquipmentSlotRecord : reconstructable : 92% : very-strong : Exact selectors 4/7/8/20/21, BE16 item ids, palette writes, unconditional invalidation/true return, raw no-xref inline-copy liveness, and complete formal C++.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00572da4-0x00572dbc | compiler jump table | SelfLookPane2 equipment-apply switch destinations : ignored : 100% : very-strong : Six exact little-endian targets regenerated from source switch control flow; SHA256 CC865EAD3DF805A24323ECEE7C55CAC401CECF40D615A0FDA91EF8C51FF4669D.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00572dbc-0x00572dce | compiler selector map | SelfLookPane2 equipment-apply selector map : ignored : 100% : very-strong : Exact 18-byte map for selector range 4..21; SHA256 66D86680FB7B74D686E6C41CD49343254F6EF2F929FC10128045E10085C668F9.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00572dce-0x00572dd0 | padding | SelfLookPane2 equipment-apply to clear alignment : ignored : 100% : strong : Two 0xcc bytes, SHA256 E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2.
            - [UID:0004Q3][0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord](by-memory/0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord.md) 0x00572dd0-0x00572e88 | retained source method | SelfLookPane2ClearEquipmentSlotRecord : reconstructable : 92% : very-strong : Exact id-only clears for selectors 4/7/8/20/21, palettes retained, unconditional invalidation/true return, inline-copy liveness, and complete formal C++.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00572e88-0x00572ea0 | compiler jump table | SelfLookPane2 equipment-clear switch destinations : ignored : 100% : very-strong : Six exact little-endian targets regenerated from source switch control flow; SHA256 C9A7D2FB073B77EEC0F49944DD2475953D4C41EBEF5DA2F369C306E1853852CE.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00572ea0-0x00572eb2 | compiler selector map | SelfLookPane2 equipment-clear selector map : ignored : 100% : very-strong : Exact 18-byte map for selector range 4..21; SHA256 66D86680FB7B74D686E6C41CD49343254F6EF2F929FC10128045E10085C668F9.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00572eb2-0x00572ec0 | padding | SelfLookPane2 equipment-clear to summary alignment : ignored : 100% : strong : Fourteen 0xcc bytes, SHA256 1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356.
            - [UID:0004Q4][0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord](by-memory/0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord.md) 0x00572ec0-0x00572f25 | retained source method | SelfLookPane2ApplySelfLookSummaryRecord : reconstructable : 91% : very-strong : Exact mask-0x40 optional BE32 display-value compare, no member stores, conditional invalidation, false return, inline-copy liveness, and complete formal C++.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00572f25-0x00572f30 | padding | SelfLookPane2 summary to Spelled dispatch alignment : ignored : 100% : strong : Eleven 0xcc bytes, SHA256 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943.
        - [UID:00039N][0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch](by-memory/0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch.md) 0x00572f30-0x00572fcf | source method | SelfLookPane2DispatchSpelledText : reconstructable : 90% : very-strong : Exact ANSI StringBase and cursor decode, BE32 value, SpelledPane remove/add-or-update dispatch, true return, compiler cleanup exclusion, and complete formal C++.
        - [UID:00039O][0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert](by-memory/0x00572fd0-0x00573232.SpelledPaneEntryVectorInsert.md) 0x00572fd0-0x00573232 | SpelledPane vector helper | SpelledPaneEntryVectorInsert : reconstructable : 87% : very-strong : Exact SpelledPane-owned entry-vector insert helper; ownership remains UID0000DK rather than SelfLookPane2.
```

### `by-class/-coverage-report.md`

Replace UID0000CV row with:

```text
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md) : reconstructable : 94% : very-strong : Complete PanelPane-derived 0xd90 SelfLookPane2 declaration with exact natural layout, primary OnActivate and EventHandler packet/key contracts, ObjectStatusBlob status field, five packet-update helpers, DispatchSpelledText, source-ready view/input methods, equipment/display/text state, complete class closure before children, and compiler/raw-liveness/lexical confidence caps.
```

Replace UID00009R row with:

```text
- [UID:00009R][ObjectPane](by-class/ObjectPane.md) : reconstructable : 92% : very-strong : Complete abstract 0x128 ObjectPane declaration over Pane with exact ObjectPaneType constants 0..11, byte m_objectType ABI, object-id inline accessor plus ObjectList friendship/direct access, exact object id/map/bounds/attachment/sound/transient layout, established methods/default virtuals, implicit padding, and compiler vtable coverage.
```

### `by-file/-coverage-report.md`

Replace UID0000NL row with:

```text
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/SelfLookPane.cpp source grouping with complete SelfLookPane/SelfLookPane2 splits, exact SelfLookPane2 OnActivate/view/input/packet dispatch, five exact packet-update method children, ObjectStatusBlob/equipment/display behavior, Spelled dispatch, retained raw source copies, compiler-table/padding exclusions, helper/destructor islands, shared child-pane ownership, and original filename/name confidence caps.
```

Replace UID0000M5 row with:

```text
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ObjectPane.cpp and reconstructed ObjectPane.h route for the complete 0x128 ObjectPane declaration, ObjectPaneType enum, inline object-id accessor, ObjectList forward declaration/friendship, exact child methods/layout/default virtuals, SoundObjectPane ownership, and compiler-only vtables without by-file reconstruction metadata.
```

Reason B004 does not apply this text: every named `-coverage-report.md` is manual supervisor-owned coverage under the project workflow. Validator-generated coverage does not satisfy these replacements.

## Follow-Up Actions

- Supervisor-owned report validation, execution, count, path, move, archive, and manual-coverage state remain external and are neither asserted nor directed by this artifact.
- A-agent actions: none; no IDA mutation or generic A-agent batch is needed for the accepted source plan.
- B004 callback work is complete: all accepted ordinary destinations were applied and scoped-validated, all temporary UID tokens were replaced, the waited generated readback passed, and no implementation item remains. Exact manual coverage text remains in this report for external supervisor-owned application.

## Confidence

- Recommendation confidence: `94/100` for split/owner/source disposition and `91/100` for exact original lexical names.
- Score confidence: high; applied values distinguish exact binary behavior from inferred spelling and remain below final-audit 95.
- Remaining uncertainty: original symbols, private/public helper access, physical source file, and the semantic labels behind display values A/B. None changes ABI, behavior, split, owner, emitter, or formal body.

## Validator Results

- Scoped command form: `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`, run from `source-3/project-documentation`. Every command exited `0`, scanned exactly one ordinary page, and deferred generated refresh until the final command.

| Command | Timestamp | Scoped destination | Exit/result | Warnings and validator-managed side effects |
| --- | --- | --- | --- | --- |
| `000000012022` | `2026-07-14T18:30:43-04:00` | UID0004Q0 child | 0; scanned 1; UID assigned; no explicit `ok` field printed | Pre-registration missing reference to UID0003RE; resolved after 12028/12037. |
| `000000012023` | `2026-07-14T18:31:48-04:00` | UID0004Q1 child | 0; scanned 1; UID assigned; no explicit `ok` field printed | No target failure reported. |
| `000000012024` | `2026-07-14T18:32:50-04:00` | UID0004Q2 child | 0; scanned 1; UID assigned; no explicit `ok` field printed | No target failure reported. |
| `000000012025` | `2026-07-14T18:33:53-04:00` | UID0004Q3 child | 0; scanned 1; UID assigned; no explicit `ok` field printed | No target failure reported. |
| `000000012026` | `2026-07-14T18:34:54-04:00` | UID0004Q4 child | 0; scanned 1; UID assigned; no explicit `ok` field printed | Pre-registration missing reference to UID00039N; resolved after 12029/12037. |
| `000000012027` | `2026-07-14T18:36:52-04:00` | UID00039M target | 0; `ok:1` | Registration-order missing UID0003RE/UID00039N references; both later scoped and present in final registry rebuild. |
| `000000012028` | `2026-07-14T18:37:45-04:00` | UID0003RE | 0; `ok:1` | Existing path registered; legacy UID0003R4/UID0003R5 and then-unscanned UID00039N warnings did not affect target validity. |
| `000000012029` | `2026-07-14T18:38:35-04:00` | UID00039N | 0; `ok:1` | Existing path registered; no target error. |
| `000000012030` | `2026-07-14T18:39:38-04:00` | UID0000CV class | 0; `ok:1` | Existing unrelated legacy-UID reference warnings only. |
| `000000012031` | `2026-07-14T18:40:04-04:00` | UID0003QZ | 0; `ok:1` | Bounded status-field/type correction accepted; no target error. |
| `000000012032` | `2026-07-14T18:41:10-04:00` | UID0000NL file | 0; `ok:1` | Validator also normalized two UID0003UT reverse-link display names from `LivingObjectPaneHandleUIPanelSwitchPacket` to `UserPaneHandleUIPanelSwitchPacket`; unrelated content otherwise preserved. |
| `000000012033` | `2026-07-14T18:42:13-04:00` | UID00023X parent | 0; `ok:1` | Existing missing registry entry for verify-only UID00039L reported; no scoped failure. |
| `000000012034` | `2026-07-14T18:43:13-04:00` | `by-memory/-ignored.md` | 0; `ok:1` | Large pre-existing control page reported 293 missing-reference warnings; validator normalized four UID0003H4/UID0003H5 reverse-link display names from LivingObjectPane to UserPane. All eight accepted rows validated. |
| `000000012035` | `2026-07-14T18:44:02-04:00` | UID00009R class | 0; `ok:1` | Existing legacy child-UID warnings; validator added current UID0004Q0/UID0004Q1 reference-index entries. |
| `000000012036` | `2026-07-14T18:45:22-04:00` | UID0000M5 file | 0; `ok:1` | Sixteen existing legacy UID warnings, two UID0004Q0/UID0004Q1 reference-index additions, and projected stats update; no scoped failure. |

- Original callback waited command: `python .\tools\validator.py --mode autogen --apply --wait-generated --queue-timeout 240`, command `000000012037`, timestamp `2026-07-14T18:45:31-04:00`, exit `0`, `generated_refresh: completed`, registry rebuild `4904` nodes/`3957` edges. Global fallback/missing-marker/no-code notices were unrelated project-wide diagnostics, not target failures.
- Gate 2 narrow scoped repair: `python .\tools\validator.py --mode file --file by-file/SelfLookPane.md --apply --queue-timeout 240`, command `000000012091`, timestamp `2026-07-14T19:03:35-04:00`, exit `0`, scanned `1`, `ok:1`, generated refresh deferred. It reported 26 pre-existing missing-reference UID warnings, `projected_stats_update:1`, and `stats_incremental_noop:1`; no scoped error or unrelated ordinary edit occurred.
- Gate 2 narrow waited refresh: `python .\tools\validator.py --mode autogen --apply --wait-generated --queue-timeout 240`, command `000000012096`, timestamp `2026-07-14T19:04:11-04:00`, exit `0`, `generated_refresh: completed`, registry rebuild `4904` nodes/`3957` edges, generated metadata refresh `280`, and one validator-owned memory auto-coverage refresh. Project-wide fallback/missing-marker/no-code diagnostics remained unrelated to UID00039M.
- Timestamp scope: the supervisor audit label `2026-07-14T19:05:15-04:00` and validator-emitted timestamps above are preserved verbatim from their separate records. Callback sequence is established by the supervisor message and monotonically later command IDs 12091/12096, not by comparing separate process clocks.
- Settled generated `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp`: 43,070 bytes, last-write `2026-07-14T19:04:55-04:00`, SHA256 `E7EEC46F70B361B9D6F27209ED08383966F05CF6AECA7B837501AD7D81652E59`; exactly one `class SelfLookPane2`; exactly one definition each for `OnPacketEvent`, `ApplySelfLookRectRecord`, `ApplySelfLookRectStateRecord`, `ApplyEquipmentSlotRecord`, `ClearEquipmentSlotRecord`, `ApplySelfLookSummaryRecord`, and `DispatchSpelledText`; exactly one `ObjectStatusBlob m_objectStatus`; zero `UID:00039M`, UID00039M Empty Emitter Marker, temporary UID token, `LivingSpriteConfig`, `m_spriteConfig`, `SelfLookPane2LookUpdateRawHelpers`, handwritten jump-table/selector-map body, or duplicate SelfLookPane2 sibling definition.
- Generated class readback contains exactly the six accepted helper declarations and `ObjectStatusBlob m_objectStatus`; it contains neither `LivingSpriteConfig` nor `m_spriteConfig`. Read-only `auto-generated/NexusTK/map/ObjectPane.cpp`, SHA256 `7A4218C2CCA83419659F0CC0F7C74EF3CE3729C41412748C5FCE2A52CD1EA681`, contains one inline `GetObjectId() const` returning `m_objectId`.
- Managed-block verification: ten report blocks were extracted after validation and compared byte-for-byte with UID00039M, UID0000CV, UID00009R, UID0004Q0-UID0004Q4, UID0003RE, and UID00039N. All ten comparisons passed; UID00039M remained exactly blank.

## Changed Files

- Created ordinary pages:
  - `by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md` UID0004Q0, SHA256 `1766C6324BC7CB9429F96F85309DC193BB707BB191AA8DEACCDD4598AED5E303`.
  - `by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md` UID0004Q1, SHA256 `1C09C118E015A2B818306A1C03AF9A10BDFC1F7738DA45E58E9F79804F0606F1`.
  - `by-memory/0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord.md` UID0004Q2, SHA256 `106E12DE3FEF4075B05E16EFAEFEBF0CCB47C78225CDAC98424384545EBA5FF3`.
  - `by-memory/0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord.md` UID0004Q3, SHA256 `A77384091AB48FFFFD67976EE5693F0EAE7679DD2628557C09B95B9B1493A88F`.
  - `by-memory/0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord.md` UID0004Q4, SHA256 `9E7F7AB18319D058D4C8EFC2DE24E2A8EA47DE31A63143DC9C792B422710D66F`.
- Modified ordinary pages:
  - UID00039M target, SHA256 `D642EE7A338B300AAA3D20F94E0532E288177140B97B60067211481AF09FC6A1`.
  - UID0003RE, SHA256 `C234DF29D5E13F9D5CA62D3537BA0AB97CFF2653DCBF792E0A027A0475289806`.
  - UID00039N, SHA256 `EBCA02FB3D9A17BDF38B378FFDA84D1DFE33F413456D685F95CA9E83BCCFDC65`.
  - `by-class/SelfLookPane2.md` UID0000CV, SHA256 `91190CC36A3A9039A4A1E8FD6DF44FCC90729763B07CCAE768D5E7D2C6D09220`.
  - UID0003QZ OnActivate, SHA256 `9871E2113684187229DEFCA8D7B629787742CAE9867D8324121E3748B6EE44E3`.
  - `by-file/SelfLookPane.md` UID0000NL, SHA256 `0F29235112C053EEB3F504AC3B3257D77E1DAF13CB5D3A543CE9CF7431F0DB0A`; Gate 2 repair changed only the active UID0003QZ split-summary type phrase while preserving every adjacent fact.
  - UID00023X parent, SHA256 `B7364FBE79875F3CFA75289A7039E6FFB9620BE90C57536EE7870472C80C3636`.
  - `by-memory/-ignored.md`, current SHA256 `8400EFA850EEF3B47669C5859966D4E4F382D54053E3C5C4234B6D05B618D8F7`; the hash changed after B004's callback only because retained B003 additively appended separate FrameRegistry padding, while all eight B004 rows remain unchanged and verified.
  - `by-class/ObjectPane.md` UID00009R, SHA256 `3764C079ACC6C5A355B3BBCBACB590E4BDD0D89A67CBE84969CD0F0270C7F245`.
  - `by-file/ObjectPane.md` UID0000M5, SHA256 `2905A04DD91025BA3922A646F480418DC9B4C2BC332FD9159730C6F9367E5C67`.
- Updated this same report in place; its exact current SHA256 is supplied with the callback return and is not embedded circularly.
- Renamed: none.
- Leases: five new-child registration windows used the existing UID00039M parent as the short coordination lease; each was released immediately after commands 12022-12026. Each of the ten remaining ordinary pages had one short lease immediately around reread/edit/scoped validation and was released immediately after commands 12027-12036. Gate 2 repair used one additional short UID0000NL lease around reread/edit/command 12091 and released it immediately. Final lease inspection contains no B004 entry.
- Restricted state: B004 did not manually edit any manual `-coverage-report.md`, generated file, tracker, audit, supervisor file, validator state, queue, lock, archive, goal, notes, or IDA database. Validator-managed registry/generated/statistics/reverse-link effects are listed above and were not manually altered.
- Report execution/lifecycle: B004 ran no execute, probe, count, move, archive, invalidate, revalidation, or other lifecycle command. External lifecycle state is not asserted here.

## Implementation Tracking Checklist

Accepted plan and implementation pass:

- [x] External supervisor acceptance boundary observed: exact Gate-1 artifact SHA `D57991D1F3B2E8DC9F2FBDBF8DBD5AE59C2E2C7113E032506C95579E17CDC9D8` was accepted before ordinary implementation.
- [x] Re-read every accepted destination immediately before its edit and preserved concurrent/unrelated content; validator-managed reverse-link display-name changes are enumerated separately.
- [x] Reclassified UID00039M to `92/94`, owner UID0000CV, false/non-emitting, blank emitter/position/formal, `Nested:0`, exact summary and complete evidence; validator 12027 and generated 12037 prove the result.
- [x] Created `0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md`, validated/registered it first as UID0004Q0 by 12022.
- [x] Created `0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md`, validated/registered it second as UID0004Q1 by 12023.
- [x] Created `0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord.md`, validated/registered it third as UID0004Q2 by 12024.
- [x] Created `0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord.md`, validated/registered it fourth as UID0004Q3 by 12025.
- [x] Created `0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord.md`, validated/registered it fifth as UID0004Q4 by 12026.
- [x] Replaced all five pre-registration tokens throughout this report and the manual-coverage text immediately after serial validator commands `000000012022`-`000000012026`; exact UIDs are 0004Q0-0004Q4 and no temporary token remains.
- [x] Applied all five exact child metadata/summary/Nested/formal blocks and report-level bytes/hash/ABI/behavior/liveness/history/negative evidence; commands 12022-12026 and formal comparisons pass.
- [x] Applied UID0003RE `91/94` complete OnPacketEvent formal block, packet/event/vtable/opcode/callee detail, with compiler-facet lowering separate; validator 12028 and generated 12037 pass.
- [x] Applied UID00039N `90/93`, `Nested:-4`, complete DispatchSpelledText formal block, summary, and exact StringBase/Spelled behavior; validator 12029 and generated 12037 pass.
- [x] Applied UID0000CV complete managed class block, six helper declarations, ObjectStatusBlob field correction, 94/94 score, exact layout/method/split/history detail, and class closure before `[[CHILDREN]]`; validator 12030 and generated class readback pass.
- [x] Rebased UID0003QZ only from `m_spriteConfig`/`LivingSpriteConfig` to `m_objectStatus`/`ObjectStatusBlob`, preserving its complete accepted body, scores, metadata, and unrelated detail; validator 12031 passes.
- [x] Applied UID00009R complete managed block with inline `GetObjectId()`, preserved unrelated class content/scores, and synchronized UID0000M5 prose without score inflation; validators 12035/12036 and ObjectPane.cpp readback pass.
- [x] Synchronized UID0000NL to 92/94 with the complete exact child/source route and no unrelated source-family compression; validator 12032 passed, and narrow Gate 2 correction validator 12091 replaced the sole active stale type phrase with exact `ObjectStatusBlob m_objectStatus` truth.
- [x] Synchronized UID00023X at unchanged 88/91 false/non-emitting with the exact five-child/data/padding inventory and preserved UID39L/39N/39O ownership distinctions; validator 12033 passes.
- [x] Added all eight exact source-excluded ranges to `by-memory/-ignored.md` with bytes/hashes/classifications and no handwritten table/padding C++; validator 12034 and generated 12037 pass.
- [x] Preserved ObjectStatusBlob/parsers, UserPane/global, SpelledPane, UID39L/UID39O, vtable, and unrelated siblings as verify-only; no listed verify-only page was edited.
- [x] Preserved direct facts separately from inferred names, including zero-start-route evidence and exact inline-copy liveness.
- [x] Preserved rejected aggregate, no-code, hand-table, stale-type, stale collection-private, raw-offset/cast/friend, duplicate-struct, and foreign-owner alternatives.
- [x] Kept all third-party import handling not applicable; no `third_party_embeds/...` source is involved.
- [x] Supplied exact supervisor-owned manual coverage text with real UIDs in this report only; B004 did not edit manual coverage.
- [x] Ran one scoped validator per changed ordinary page plus narrow repair validator 12091, recorded every command/result/warning/side effect, and released each one-file lease immediately.
- [x] Ran original waited command 12037 and narrow-repair waited command 12096; latest readback verifies seven exact definitions, no UID00039M marker/body, no compiler-data body, no stale type token, no duplicate SelfLookPane2 sibling C++, and preserved unrelated output.

Implementation callback pass:

- [x] Report accepted externally for implementation at exact Gate-1 SHA `D57991D1F3B2E8DC9F2FBDBF8DBD5AE59C2E2C7113E032506C95579E17CDC9D8`.
- [x] C01-C46 each has a legal terminal callback state with claim-specific destination and validator/generated proof.
- [x] All accepted target/support details are incorporated at report-level depth without compression.
- [x] All metadata/score/owner/emitter/split/Nested/C++ changes are applied or explicitly excluded with reason.
- [x] All five real child UIDs are recorded and every temporary token is removed.
- [x] Every complete managed block was compared byte-for-byte with its named destination after validation; all ten comparisons passed.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, exact hashes, packet behavior, and confidence caps are preserved.
- [x] All leases are released and no ordinary file is held by B004.
- [x] Scoped validator inventory and generated readback are recorded under Validator Results and Changed Files.
- [x] Manual coverage text uses real UIDs in this report while the manual coverage files remain untouched by B004.
- [x] No accepted implementation item remains unapplied.
- [x] B004 lifecycle boundary confirmed: no execute_report, probe, count, move, archive, invalidation, or revalidation command was run.

Gate 2 narrow additive repair pass:

- [x] Read the exact `2026-07-14T19:05:15-04:00` audit and preserved all independently passed C01-C27/C29-C40/C42-C45 content, all ten formal blocks, scores, UIDs, nesting, and ignored-range evidence.
- [x] Re-read UID0000NL under a short lease and changed only the active UID0003QZ split-summary type phrase, preserving the exact range, vtable, no-caller, byte-counted parsing, UID0004N5, LegendPane, child-detach, Spelled-scroll, mode-restoration, and no-draw facts.
- [x] Scanned all fifteen B004 destinations after repair: zero unclassified current-facing `LivingSpriteConfig`/`m_spriteConfig` occurrences; every remaining occurrence is explicitly historical, rejected, or superseded and paired with `ObjectStatusBlob`/`m_objectStatus`.
- [x] Scoped validator 12091 and waited refresh 12096 both exited zero; current UID0000NL and generated hashes, warnings, side effects, uniqueness, marker, compiler-data, and stale-token assertions are recorded above.
- [x] Released the UID0000NL lease immediately after validation; no B004 lease remains, no manual coverage was edited, and no report lifecycle command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000012105","destination_path":"executed-b-agent-research/B004/00039M-SelfLookPane2LookUpdateRawHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00039M-SelfLookPane2LookUpdateRawHelpers-source-quality.md","timestamp":"2026-07-14T19:14:41-04:00","uid":"00039M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
