** TARGET-REPORT-UID:0000WH **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000WH CashShopRequestItemSetup Memory-Range Audit

## Finalized Report / Current Recommendation

- Current recommendation: repair [UID:0000WH] as a range-bearing documentation defect. The broad `0x0041a5d0-0x0041b5da.CashShopRequestItemSetup` page is not a contiguous source-owned range and should not remain `RECONSTRUCTABLE:TRUE` or parented to `CashShopRequest`.
- Final disposition: actionable memory-range/split defect found from `auto-generated/by-memory-tool-report.md`. No by-memory edits were applied in this fallback audit because the clean fix has broad rename/reference impact and should be run as a scoped repair with leases.
- Required action: scoped split/rename pass should repurpose UID `0000WH` to the exact early raw lifecycle container `0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle`, mark that container `not_reconstructable` and parent blank, keep exact child ownership on `0002CH` and `0002CI`, move `0002CM` out from under the old broad aggregate, and separately split the hidden non-FileDownloader helper gap inside UID `0000WI`.
- Confidence: strong that the current `0000WH` range is structurally wrong; strong that the exact early raw children belong to `CashShopRequest`; strong that the middle span belongs to FileDownloader/JsonCpp/runtime/support owners rather than `CashShopRequest`; medium on the final exact names for `0x0041b300` and `0x0041b350` until a dedicated JsonCpp/support split pass names them.

## Supporting Research

## Target

- Target UID: `0000WH`
- Target path: `by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md`
- Source queue/report row: `auto-generated/by-memory-tool-report.md`, `Barrier Crossings Errors`, report timestamp `2026-06-12 05:21:29`.
- Reported rows:
  - Parent/barrier `0x0041a5d0-0x0041b5da` `CashShopRequestItemSetup` crossing `0x0041a670-0x0041b69f.FileDownloaderDispatch`.
  - Parent/barrier `0x0041a5d0-0x0041b5da` `CashShopRequestItemSetup` crossing `0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor`.
- Current scores and parent state: `COMPLETION:80`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:00001H` (`CashShopRequest` class).

## Executive Recommendation

The immediate range-tool defect is not just the legacy exclusive-end mismatch at `0x0041b5da`. Changing the old end to `0x0041b5db` would only stop the child-destructor crossing; it would still leave `0000WH` claiming a broad non-contiguous span across FileDownloader, JsonCpp/support, and padding regions.

The best repair is:

1. Rename/retitle UID `0000WH` from `0x0041a5d0-0x0041b5da.CashShopRequestItemSetup` to `0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle`.
2. Reclassify UID `0000WH` as `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID:` blank, and document it as a parent-blank non-emitting split inventory over only:
   - [UID:0002CH] `0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw`
   - padding `0x0041a607-0x0041a610`
   - [UID:0002CI] `0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw`
3. Keep [UID:0002CM] `0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor` as a separate direct `CashShopRequest` child, not under the old broad aggregate.
4. Leave FileDownloader-owned children under [UID:0000WI] and [UID:0000WJ], but schedule a second scoped repair for [UID:0000WI] because live IDA shows undocumented or under-modeled non-FileDownloader functions inside its span: `0x0041b2d0`, `0x0041b300`, and `0x0041b350`.

This should clear the reported `0000WH` barrier crossing while preserving the existing strong child evidence. It also avoids using a by-memory filename as a non-contiguous source-family index.

## Supervisor Active Recheck

- Triggering instruction: fallback audit of `auto-generated/by-memory-tool-report.md`; identify real range-boundary, split, stale filename, ownership, compiler/runtime, or documentation issues; write a durable report under B001 research if actionable.
- Split repair requirement: no direct split was applied in this fallback pass. The repair touches many references and should be handled under a focused lease/validator pass.
- Source-bearing children in scope: no new children were created. Existing exact children `0002CH`, `0002CI`, and `0002CM` already carry source-bearing CashShopRequest evidence. Additional exact children are recommended for the hidden `0000WI` gap.

## Inference Research Guidance Check

`by-structure.md` says a mixed-owner convenience page whose exact children carry real ownership should be `RECONSTRUCTABLE:FALSE` when the container itself is only an audit/index map. The current `0000WH` body text already says "Do not interpret this file as ownership over every address in the broad filename range," but the metadata contradicts that by marking the broad file reconstructable and parented to `CashShopRequest`.

The inference rule applied here is: direct machine-code facts and xrefs override the current broad by-memory filename. Existing docs are useful leads, but not authority. The raw CashShop constructor/destructor vtable writes are IDA facts; the FileDownloader vtable/global writes are IDA facts; the broad `CashShopRequestItemSetup` ownership is a documentation hypothesis that the range tool correctly exposes as structurally unsafe.

## Evidence Standards Used

- IDA MCP: `entity_query`, `lookup_funcs`, `xrefs_to`, `decompile`, `disasm`, and `get_bytes` against active session `a001-b276`.
- Generated report evidence: `auto-generated/by-memory-tool-report.md` and `auto-generated/-ag-memory-coverage.md`.
- Manual coverage evidence: `by-memory/-coverage-report.md`.
- Documentation evidence: existing by-memory, by-class, by-file, by-global, and by-project-structure pages.
- Negative evidence: no xrefs to raw starts `0x0041a5d0` or `0x0041a610`; no direct proof that the broad `0000WH` filename corresponds to one source-level contiguous object; no direct FileDownloader ownership for `0x0041b300` or `0x0041b350`.

## IDA MCP Facts

Function/range facts:

- `entity_query` over `0x0041a5c0-0x0041b6b0` returns modeled functions at `0x0041a670`, `0x0041a6f0`, `0x0041a750`, `0x0041aa00`, `0x0041ae20`, `0x0041b110`, `0x0041b180`, `0x0041b200`, `0x0041b270`, `0x0041b2d0`, `0x0041b2f0`, `0x0041b300`, `0x0041b350`, `0x0041b570`, `0x0041b5e0`, and `0x0041b610`.
- `lookup_funcs` reports `0x0041a5d0`, `0x0041a610`, and `0x0041a662` are not function objects.
- `lookup_funcs` reports `0x0041b570` as `sub_41B570`, size `0x6b`, so the exact exclusive end is `0x0041b5db`; `0x0041b5db` is not a function.
- `lookup_funcs` reports hidden/gap functions currently not represented as exact modern by-memory pages:
  - `0x0041b2d0` `___std_fs_create_symbolic_link@8`, size `0x14`, no xrefs.
  - `0x0041b300` `sub_41B300`, size `0x4a`.
  - `0x0041b350` `sub_41B350`, size `0x215`.

Data/table/padding facts:

- Raw disassembly from `0x0041a5d0` shows a constructor-shaped body through `0x0041a606`, then `0xcc` alignment at `0x0041a607-0x0041a610`.
- Raw disassembly from `0x0041a610` shows a destructor-shaped body through `0x0041a65c`, an invalid-parameter noreturn path at `0x0041a65d`, and alignment beginning at `0x0041a662`.
- `get_bytes 0x0041a5d0 size 160` confirms `0xcc` padding before `0x0041a670`.
- `get_bytes 0x0041b2c9 size 55` confirms padding `0x0041b2c9-0x0041b2d0`, real code `0x0041b2d0-0x0041b2e4`, padding `0x0041b2e4-0x0041b2f0`, clear helper `0x0041b2f0-0x0041b2fb`, and padding `0x0041b2fb-0x0041b300`.
- `get_bytes 0x0041b565 size 11` confirms `0xcc` padding through `0x0041b56f` before `0x0041b570`.

Xref facts:

- `xrefs_to 0x0041a5d0` and `xrefs_to 0x0041a610`: no cross-references to either raw start.
- `xrefs_to 0x0060d7a0` (`CashShopRequest` vtable slot): refs at `0x0041a5e8`, `0x0041a613`, `0x0041b22d`, and `0x0041b576`.
- `xrefs_to 0x0041b570`: one data xref from `0x0060d7a0`.
- `xrefs_to 0x0060d7a8` (`FileDownloader` vtable slot): refs from FileDownloader constructor/destructor/destructor wrapper at `0x0041a6c8`, `0x0041a715`, and `0x0041b63c`.
- `xrefs_to 0x0067a738`: nine refs; writes/clears come from FileDownloader constructor/destructor family (`0x0041a6b1`, `0x0041a6b8`, `0x0041a722`, `0x0041b2f0`, `0x0041b649`), while submit callers pass this global into `0x0041b180`, `0x0041b200`, and `0x0041b270`.
- `xrefs_to 0x0041b300`: 340 xrefs from 110 distinct functions, including JsonCpp/product cleanup paths and startup/update code. This is broad support-helper fanout, not FileDownloader-local ownership.
- `xrefs_to 0x0041b350`: four xrefs from two functions: `0x0041aa00` and `0x00422740` plus their EH references. This ties it to JsonCpp document/parser cleanup, not to FileDownloader as a class.
- `xrefs_to 0x0041b2d0`: no xrefs.

Decompilation facts:

- `0x0041a670` constructs FileDownloader-style thread state, writes `dword_67A738`, installs `FileDownloader::vftable`, and starts worker state.
- `0x0041a6f0` restores `FileDownloader::vftable`, stops/cleans worker state, clears `dword_67A738`, and tears down base state.
- `0x0041b110` switches downloader messages `10000`, `10001`, and `10002`, dispatching to `0x0041a750`, `0x0041ae20`, and `0x0041aa00`.
- `0x0041b180`, `0x0041b200`, and `0x0041b270` allocate payloads and post downloader messages through `sub_596960`.
- `0x0041b570` restores `CashShopRequest::vftable`, frees an embedded SSO-style string when needed, resets string fields, and optionally deletes `this`.
- `0x0041b300` frees heap storage only when capacity is at least `0x10`, then resets length/capacity/first byte. This matches a generic MSVC-style small-string cleanup helper.
- `0x0041b350` tears down multiple JsonCpp/string/container fields and calls the same invalid-parameter guard on bad allocations. It is cleanup support for JsonCpp-style document/value state.

Negative IDA facts:

- No IDA function covers the broad `0x0041a5d0-0x0041b5da` range.
- No IDA evidence makes the FileDownloader middle span a `CashShopRequest` source range.
- No direct call/xref evidence makes `0x0041b300` or `0x0041b350` FileDownloader-owned despite their physical address inside `0000WI`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0041a5d0-0x0041a607` | [UID:0002CH] `CashShopRequestConstructorRaw` | Raw constructor body | TRUE | `CashShopRequest` class | `82/88` | Keep exact child |
| `0x0041a607-0x0041a610` | [UID:0000VN] ignored ledger | Padding | FALSE/ignored | none | `100/strong` | Add coverage row if `0000WH` is narrowed |
| `0x0041a610-0x0041a662` | [UID:0002CI] `CashShopRequestNonDeletingDestructorRaw` | Raw non-deleting destructor | TRUE | `CashShopRequest` class | `82/88` | Keep exact child |
| `0x0041a662-0x0041a670` | [UID:0000VN] ignored ledger | Padding | FALSE/ignored | none | `100/strong` | Add coverage row if `0000WH` is narrowed |
| `0x0041a670-0x0041b69f` | [UID:0000WI] `FileDownloaderDispatch` | FileDownloader/download aggregate | TRUE now | `FileDownloader` file | `84/88` | Needs later split review because it contains hidden non-FileDownloader/support functions |
| `0x0041b2d0-0x0041b2e4` | no exact modern page found | Unreferenced queue/std-named wrapper | open | open | open | Create exact page or ignored/runtime row in scoped pass |
| `0x0041b300-0x0041b34a` | no exact modern page found; old report names `SmallStringStorage_Reset_41B300` | Generic small-string cleanup helper | likely FALSE as NexusTK product code | support/runtime or helper bucket | old reviewed-only | Create exact ignored/support page |
| `0x0041b350-0x0041b565` | no exact modern page found | JsonCpp cleanup/destructor helper | likely TRUE as third-party JsonCpp or FALSE if compiler cleanup adapter | `JsonCpp` / third-party support | open | Create exact page after JsonCpp comparison |
| `0x0041b565-0x0041b570` | [UID:0000VN] ignored ledger candidate | Padding | FALSE/ignored | none | `100/strong` | Add row if hidden gap split |
| `0x0041b570-0x0041b5db` | [UID:0002CM] `CashShopRequestScalarDeletingDestructor` | CashShopRequest deleting destructor | TRUE | `CashShopRequest` class | `84/88` | Keep exact child, but move out from old broad `0000WH` containment |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041a5e8` | data ref to `0x0060d7a0` | Raw constructor writes CashShopRequest vtable |
| `0x0041a613` | data ref to `0x0060d7a0` | Raw non-deleting destructor writes CashShopRequest vtable |
| `0x0041a6c8` | data ref to `0x0060d7a8` | FileDownloader constructor writes FileDownloader vtable |
| `0x0041a6b1`, `0x0041a6b8` | writes to `0x0067a738` | FileDownloader constructor owns singleton lifetime |
| `0x0041a722`, `0x0041b649` | clears `0x0067a738` | FileDownloader destructor wrappers own singleton cleanup |
| `0x0041b168`, `0x0041b156`, `0x0041b13c` | `FileDownloader::OnMessage` calls download helpers | Message dispatcher, not CashShopRequest contiguous ownership |
| `0x0041b22d` | writes `0x0060d7a0` into allocated payload | Submit helper allocates CashShopRequest payload but receiver remains FileDownloader singleton |
| `0x0041b300` | 340 xrefs / 110 functions | Broad support cleanup helper, not FileDownloader-local |
| `0x0041b350` | four xrefs from `0x0041aa00` and `0x00422740` | JsonCpp cleanup helper used by product JSON consumers |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- `by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md` explicitly says the filename is broader than a contiguous source-owned body and should not be interpreted as ownership over every address.
- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md` records FileDownloader constructor/destructor/dispatcher ownership and the `dword_67A738` singleton lifetime.
- `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md` already states the recovered global name is misleading and the lifetime is FileDownloader/download-dispatcher, not a pure CashShopRequest object.
- `by-class/FileDownloader.md`, `by-file/FileDownloader.md`, and `by-project-structure/proposed-source-tree.md` all state that `FileDownloader.cpp` owns the worker-thread HTTP dispatcher and `dword_67A738` lifetime.
- `by-file/JsonCpp.md` identifies a high-confidence JsonCpp third-party owner for parser/value cleanup support.

Existing docs that are stale, incomplete, or contradicted:

- `0000WH` metadata says `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:00001H`, contradicting its own mixed-container text.
- `by-memory/-coverage-report.md` nests `0002CM` under the old broad `0000WH` row and has no exact coverage rows for `0x0041a607-0x0041a610`, `0x0041a662-0x0041a670`, `0x0041b2d0-0x0041b2e4`, `0x0041b300-0x0041b34a`, `0x0041b350-0x0041b565`, or `0x0041b565-0x0041b570`.
- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md` notes `0x0041b2d0-0x0041b2e4` is real unrelated code but has no exact modern child page for it.
- `by-memory/-report.old.md` documents `0x0041B300 - SmallStringStorage_Reset_41B300` as reviewed support glue, but the current canonical by-memory coverage does not have an exact page.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` still assigns `0000WH` to `CashShopRequest` as `0x0041a5d0-0x0041b5da`.
- `by-memory/-coverage-report.md` still carries `0000WH` as reconstructable, assigned, and broad.
- The memory-range report correctly flags the partial overlap between `0000WH` and `0000WI`, and between `0000WH` and `0002CM`.

## Ranked Ownership Analysis

### 1. Repurpose UID 0000WH to `CashShopRequestRawLifecycle` exact container

Evidence for:

- The only contiguous CashShopRequest-owned early span before FileDownloader begins is `0x0041a5d0-0x0041a662`, covering the raw constructor/destructor bodies.
- Vtable writes at `0x0041a5e8` and `0x0041a613` point to `CashShopRequest::vftable`.
- The successor modeled function at `0x0041a670` is FileDownloader constructor and installs the FileDownloader vtable.
- This repair removes the reported partial overlap with `FileDownloaderDispatch`.

Evidence against:

- `0000WH` currently contains useful cross-links for submit helpers and the later scalar destructor. Those should be preserved in `CashShopRequest` class/file docs and exact child cross-references, not as a broad by-memory filename.

Decision: best repair. Make it a parent-blank, non-emitting split inventory over exact early raw lifecycle children only.

### 2. Endpoint-only repair to `0x0041b5db`

Evidence for:

- `0x0041b570` has size `0x6b`, so `0x0041b5db` is the exact exclusive end of the scalar deleting destructor.
- This would fix the second reported crossing with `0002CM`.

Evidence against:

- It leaves the broader and more important crossing with `FileDownloaderDispatch`.
- It keeps the page as a non-contiguous source-owned range from `0x0041a5d0` to `0x0041b5db`.
- It still hides middle support/JsonCpp/runtime functions under a CashShopRequest by-memory page.

Decision: reject as incomplete.

### 3. Keep current `0000WH` as a reconstructable CashShopRequest aggregate

Evidence for:

- Existing docs use it as a convenient cross-reference for CashShopRequest raw lifecycle and request-payload setup.
- Some submit helper behavior allocates CashShopRequest or CashShopVersionRequest payload objects.

Evidence against:

- The page crosses FileDownloader-owned constructor/destructor/message-dispatch code.
- Submit helper receivers come from FileDownloader-lifetime `dword_67A738`.
- `by-structure.md` says mixed convenience pages whose children carry source ownership should be non-emitting, parent-blank containers.
- The memory-range report correctly sees the broad filename as a barrier crossing.

Decision: reject.

### 4. Move all `0x0041b180-0x0041b270` submit helpers back under CashShopRequest

Evidence for:

- `0x0041b200` allocates a payload with `CashShopRequest::vftable`.
- `0x0041b270` allocates a payload with `CashShopVersionRequest::vftable`.
- Product feature semantics are cash-shop/fitting-room/minimap.

Evidence against:

- Callers pass `dword_67A738`, whose writes/clears are FileDownloader constructor/destructor-family.
- `FileDownloader::OnMessage` consumes message IDs `10000`, `10001`, and `10002` and dispatches the corresponding downloader helpers.
- Existing FileDownloader class/file docs have the stronger lifetime evidence and already clear the parent gate.

Decision: keep as FileDownloader-attached submit helpers with feature cross-links unless a later source comparison proves a facade class/source split.

### 5. Treat `0x0041b300` / `0x0041b350` as FileDownloader children

Evidence for:

- They are physically inside `0x0041a670-0x0041b69f.FileDownloaderDispatch`.
- `0x0041b350` is called from the cash-shop version downloader at `0x0041aa00`.

Evidence against:

- `0x0041b300` has 340 xrefs from 110 functions and an old reviewed classification as generic small-string cleanup support.
- `0x0041b350` also appears in fitting-room JSON parsing and has JsonCpp-style cleanup behavior.
- Neither function has FileDownloader vtable/global lifetime evidence.

Decision: reject FileDownloader direct ownership. Create exact support/JsonCpp pages in a scoped split pass.

### Proposed new file/grouping

Proposed owner/name/path:

- Do not create a new project source file for `0000WH`. Use existing `CashShopRequest` for `0002CH`, `0002CI`, and `0002CM`, existing `FileDownloader` for downloader constructor/dispatcher/submit helpers, existing `JsonCpp` for JsonCpp cleanup/support, and existing ignored/support ledgers for padding/runtime helpers.

Likely full contents:

- `CashShopRequestRawLifecycle` should be a narrow by-memory inventory only, not a source file. It would contain raw constructor/destructor children and padding.
- `JsonCpp` or support-helper follow-up should consider exact pages for:
  - `0x0041b300-0x0041b34a.SmallStringStorageReset` as reviewed support/string-storage glue, likely non-reconstructable as NexusTK product code.
  - `0x0041b350-0x0041b565.JsonCppCleanupHelper` as a JsonCpp/parser/value cleanup function or compiler cleanup adapter requiring source comparison.
  - `0x0041b2d0-0x0041b2e4` as an unreferenced wrapper with misleading `___std_fs_create_symbolic_link@8` IDA name, to classify as ignored/runtime/support or stale-name queue wrapper after deeper review.

Candidate related items that belong:

- [UID:0002CH] and [UID:0002CI] belong under the narrowed `CashShopRequestRawLifecycle` inventory.
- [UID:0002CM] belongs directly under `CashShopRequest`, not under the narrowed inventory.
- [UID:0002TP] through [UID:0002CO] remain in FileDownloader/CashShopVersion/FileDownloader child documentation, but `0000WI` should be audited as a non-emitting map after hidden children are exact.
- Existing JsonCpp owner [UID:0000KI] is the right candidate for `0x0041b350` if source comparison confirms it is source-level JsonCpp code.

Candidate related items rejected:

- Do not route `0x0041b300` to `CashShopRequest`, `FileDownloader`, or `FittingRoom`; fanout and behavior are generic support cleanup.
- Do not route `0x0041b350` to FileDownloader solely because `DownloadCashShopVersion` calls it.
- Do not use `g_pCashShopRequest` recovered alias to assign FileDownloader lifetime state to `CashShopRequest`.

Standalone, narrow, or broad source-file inference:

- `0000WH` should be a narrow non-emitting inventory, not a standalone file.
- The real source-file grouping remains broad and existing: `NexusTK/cashshop/CashShopRequest.cpp`, `NexusTK/network/FileDownloader.cpp`, and `NexusTK/third_party/jsoncpp/`.

## Negative Evidence Summary

- Address adjacency is not enough: `0x0041b300` and `0x0041b350` sit in the broad FileDownloader span but have generic support/JsonCpp behavior.
- Consumer xrefs are not ownership proof: cash-shop/fitting-room callers consume FileDownloader and JsonCpp helpers, but those callers do not own the helper bodies.
- The recovered `g_pCashShopRequest` alias is not source-owner proof: the live writer set is FileDownloader constructor/destructor-family.
- The current broad by-memory title is not proof of source ownership: the page text already contradicts the title/range by calling itself a navigation page.

## Final Recommendation

Exact changes recommended:

1. Lease and rename:
   - From `by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md`
   - To `by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md`
2. Update UID `0000WH` metadata:
   - `COMPLETION:86`
   - `CONFIDENCE:90`
   - `RECONSTRUCTABLE:FALSE`
   - `AUTOGEN_PARENT_UID:` blank
   - C++ block blank
3. Rewrite `0000WH` body as a narrow non-emitting inventory over `0002CH`, `0002CI`, and padding only.
4. Update affected docs that currently treat `0000WH` as a broad item setup range:
   - `by-file/CashShopRequest.md`
   - `by-class/CashShopRequest.md`
   - `by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md`
   - `by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md`
   - `by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md`
   - `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`
   - `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`
   - `by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md`
   - `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`
5. Run validator on the renamed `0000WH` page and each manually edited reference page. Do not manually edit `by-memory/-coverage-report.md`; supervisor should apply the coverage rows after the rename/validation.

Exact parent assignments recommended:

- `0000WH`: parent blank, non-reconstructable container.
- `0002CH`: keep `AUTOGEN_PARENT_UID:00001H` (`CashShopRequest` class).
- `0002CI`: keep `AUTOGEN_PARENT_UID:00001H`.
- `0002CM`: keep `AUTOGEN_PARENT_UID:00001H`, but no longer nested under the narrowed `0000WH`.
- `0002CJ`, `0002CK`, `0002CL`: keep FileDownloader attachment with cash-shop/minimap payload cross-links.

Exact future work outside this report:

- Split/reclassify the hidden FileDownloader-span gap:
  - `0x0041b2d0-0x0041b2e4`
  - `0x0041b300-0x0041b34a`
  - `0x0041b350-0x0041b565`
  - `0x0041b565-0x0041b570`
- Reevaluate [UID:0000WI] after those exact children exist. It may also need reclassification as a parent-blank non-emitting mixed inventory rather than a reconstructable FileDownloader source owner.

## Required Coverage-Report Edits For Supervisor

Do not apply until the `0000WH` rename/rewrite is performed and validator updates UID path annotations. Replace the current `0000WH` block near the `0x0041a5d0` area with:

```text
    - [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) 0x0041a5d0-0x0041a662 | raw lifecycle split inventory | CashShopRequestRawLifecycle : not_reconstructable : 86% : strong : B001 fallback memory-range audit narrowed the former broad CashShopRequestItemSetup page to a parent-blank non-emitting inventory over the exact raw constructor/destructor children only; live IDA confirms raw non-function starts, CashShopRequest vtable writes at `0x0041a5e8` and `0x0041a613`, padding boundaries, and successor FileDownloader constructor at `0x0041a670`.
        - [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md) 0x0041a5d0-0x0041a607 | raw-method | CashShopRequestConstructorRaw : reconstructable : 82% : strong : Raw `CashShopRequest` constructor body; IDA MCP confirms no modeled function or direct start xrefs, exact bytes through `0x0041a606`, vtable write at `0x0041a5e8`, touched state offsets, and autogen attachment to CashShopRequest.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041a607-0x0041a610 | padding | CashShopRequest constructor to raw destructor alignment : ignored : 100% : strong : IDA disassembly/byte check shows three `0xcc` bytes before the raw non-deleting destructor body at `0x0041a610`.
        - [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md) 0x0041a610-0x0041a662 | raw-method | CashShopRequestNonDeletingDestructorRaw : reconstructable : 82% : strong : Raw non-deleting `CashShopRequest` destructor body; IDA MCP confirms no modeled function or direct start xrefs, string cleanup/free path, invalid-parameter guard at `0x0041a65d`, vtable write at `0x0041a613`, and autogen attachment to CashShopRequest.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041a662-0x0041a670 | padding | CashShopRequest raw destructor to FileDownloader constructor alignment : ignored : 100% : strong : IDA byte check shows fourteen `0xcc` bytes after the raw destructor's invalid-parameter path and before the FileDownloader constructor at `0x0041a670`.
```

Move the current [UID:0002CM] row out from under `0000WH`. If the supervisor applies only the `0000WH` narrowing first and leaves [UID:0000WI] unchanged, place `0002CM` temporarily under the [UID:0000WI] physical inventory immediately before the existing [UID:0002CN] row. This is a physical-containment placement only; the direct autogen parent remains [UID:00001H][CashShopRequest], and the preferred follow-up is to reclassify or resplit `0000WI` as a parent-blank mixed inventory after its hidden helper gap is exact:

```text
        - [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) 0x0041b570-0x0041b5db | method | CashShopRequestScalarDeletingDestructor : reconstructable : 84% : strong : Physical child of the mixed `0x0041a670-0x0041b69f` inventory but direct autogen child of `CashShopRequest`; IDA MCP confirms function `sub_41B570` size `0x6b`, data xref from `0x0060d7a0`, no direct code callers, callees `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`, and CashShopRequest vtable ownership.
```

For the later `0000WI` split, do not apply coverage-report rows yet because the exact child pages do not exist and therefore have no UIDs. The scoped repair should create/classify these ranges first, then add exact rows after validator assigns stable UIDs:

- `0x0041b2d0-0x0041b2e4`: unreferenced wrapper currently named `___std_fs_create_symbolic_link@8`; live IDA confirms size `0x14`, no xrefs, and a tail call to `sub_596960`.
- `0x0041b300-0x0041b34a`: generic MSVC-style small-string cleanup helper with 340 xrefs from 110 functions; not FileDownloader or CashShopRequest product logic.
- `0x0041b350-0x0041b565`: JsonCpp-style cleanup/destructor helper called from cash-shop version and fitting-room JSON parse cleanup paths; assign to JsonCpp only after source comparison confirms source-level ownership versus compiler cleanup adapter.
- `0x0041b565-0x0041b570`: padding before `sub_41B570`; IDA byte check shows eleven `0xcc` bytes.

## Follow-Up Actions

Supervisor actions:

- Assign a scoped repair for `0000WH` rename/reclassification with broad reference updates and validator.
- Assign a follow-up split target for the `0000WI` hidden gap, preferably after the `0000WH` barrier repair lands.
- Do not apply the `by-memory/-coverage-report.md` replacement until the corresponding docs/filenames are changed.

A-agent actions:

- When editing CashShopRequest/FileDownloader docs, remove wording that treats `0000WH` as a broad source-owned setup range.
- Preserve cross-links to submit helper pages, but phrase them as FileDownloader receiver helpers with cash-shop/minimap payload semantics.

B001 future research actions:

- Perform IDA-backed exact child pages for `0x0041b2d0`, `0x0041b300`, and `0x0041b350`.
- Compare `0x0041b350` against staged JsonCpp `b299d3581f4dc670734f1fe1a34fce1282337802` before deciding whether it is a source-level third-party helper or compiler cleanup adapter.
- Reassess whether `0000WI` should become a parent-blank non-emitting mixed inventory after exact children exist.

## Confidence

- Recommendation confidence: strong.
- Score confidence for proposed `0000WH` `86/90`: strong enough because exact child/padding boundaries, ownership split, and disconfirming evidence are now documented; not higher because the surrounding `0000WI` split remains incomplete.
- Remaining uncertainty: final source-facing names for `0x0041b2d0`, `0x0041b300`, and `0x0041b350`; whether `0000WI` remains a source-bearing FileDownloader aggregate or becomes a non-emitting mixed inventory after hidden children are split.

## Validator Results

- Commands run: none.
- Results: no validator run because this fallback audit created only a B001 research report and did not edit by-memory docs.
- Any unresolved validator warnings/errors: not checked in this pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0000WH-CashShopRequestItemSetup-MemoryRangeAudit.md`
- Modified: none outside B001 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000WH-CashShopRequestItemSetup-MemoryRangeAudit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000WH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
