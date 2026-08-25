** TARGET-REPORT-UID:0000WI **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000WI FileDownloaderDispatch Hidden Helper Gap

Revision: B001-0000WI hidden-helper split and mixed-inventory repair, 2026-06-12

## Finalized Recommendation

- Target: [UID:0000WI] `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`.
- Final disposition: keep the numeric range as a reviewed mixed address inventory, not a source-emitting FileDownloader parent. The page is now `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, and `AUTOGEN_PARENT_UID:` blank.
- Final title: `0x0041a670-0x0041b69f FileDownloader Dispatch And Support Inventory`. The filename was intentionally retained to avoid unnecessary broad-reference churn; the title, metadata, and body now make the mixed inventory status explicit.
- Exact child pages created before the parent recommendation:
  - [UID:0003GY] `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`: real 20-byte queue-post wrapper, `RECONSTRUCTABLE:TRUE`, `86/86`, parent blank. Best forced semantic candidate is Thread/worker-thread dispatch support, but zero inbound xrefs prevent direct parent assignment.
  - [UID:0003GZ] `by-memory/0x0041b300-0x0041b34a.SmallStringStorageReset.md`: MSVC/Dinkumware SSO-15 reset helper, `RECONSTRUCTABLE:FALSE`, `86/90`, parent blank and ignored as runtime/string support.
  - [UID:0003H0] `by-memory/0x0041b350-0x0041b565.JsonCppReaderDestructor.md`: JsonCpp `Json::Reader` implicit destructor, `RECONSTRUCTABLE:TRUE`, `88/90`, attached to [UID:0000KI] `JsonCpp`.
- Padding/ignored ledger repaired for these exact alignment spans: `0x0041b2c9-0x0041b2d0`, `0x0041b2e4-0x0041b2f0`, `0x0041b34a-0x0041b350`, and `0x0041b565-0x0041b570`.
- Ownership recommendation: do not attach [UID:0000WI] itself to [UID:0000JC] `FileDownloader`. Keep exact FileDownloader children attached to FileDownloader, exact JsonCpp child attached to JsonCpp, exact CashShopRequest/CashShopVersionRequest children attached to their owners, runtime string support ignored, and [UID:0003GY] parent-blank until caller/source evidence appears.
- Confidence: `90/100` for the mixed-inventory repair and split boundaries; `90/100` for JsonCpp destructor ownership; `90/100` for runtime string-support exclusion; `86/100` for the unreferenced thread-dispatch wrapper behavior; below assignment threshold for that wrapper's direct source parent.
- Coverage-report handling: `by-memory/-coverage-report.md` was not edited. Exact replacement/pending rows for the supervisor are included near the end of this report.

## Actions Taken

- Created exact child documentation for the three real hidden helper spans inside [UID:0000WI].
- Updated [UID:0000WI] from a reconstructable FileDownloader-parented aggregate into a non-reconstructable parent-blank mixed inventory.
- Updated `by-memory/-ignored.md` to include the four newly confirmed `0xcc` padding spans around the hidden helpers.
- Ran validator file mode with `--apply` over the new child pages and the touched parent/ignored pages. The final correction pass exited `0`; no unresolved validator errors remained. Validator-owned autogen/projection side effects were produced by the tool, but `by-memory/-coverage-report.md` was not manually edited.

## IDA MCP Evidence

Live IDA MCP session: `b001_nexustk`, opened against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` on 2026-06-12.

Function boundary facts:

| Address | IDA result | Size / end | Classification |
| --- | --- | --- | --- |
| `0x0041b2d0` | `___std_fs_create_symbolic_link@8` | `0x14`, ends `0x0041b2e4` | real queue wrapper, IDA name rejected |
| `0x0041b2e4` | not a function | n/a | padding starts |
| `0x0041b2f0` | `sub_41B2F0` | `0x0b`, ends `0x0041b2fb` | existing [UID:0000WK] FileDownloader global clear helper |
| `0x0041b300` | `sub_41B300` | `0x4a`, ends `0x0041b34a` | SSO-15 string reset helper |
| `0x0041b34a` | not a function | n/a | padding starts |
| `0x0041b350` | `sub_41B350` | `0x215`, ends `0x0041b565` | JsonCpp `Json::Reader` destructor |
| `0x0041b565` | not a function | n/a | padding starts |
| `0x0041b570` | `sub_41B570` | `0x6b` | existing CashShopRequest scalar deleting destructor |

Padding byte facts:

- `0x0041b2c9-0x0041b2d0`: seven `0xcc` bytes between the version submit helper and `0x0041b2d0`.
- `0x0041b2e4-0x0041b2f0`: twelve `0xcc` bytes between `0x0041b2d0` and [UID:0000WK].
- `0x0041b2fb-0x0041b300`: five `0xcc` bytes reconfirmed between [UID:0000WK] and `0x0041b300`.
- `0x0041b34a-0x0041b350`: six `0xcc` bytes between `0x0041b300` and `0x0041b350`.
- `0x0041b565-0x0041b570`: eleven `0xcc` bytes between `0x0041b350` and `0x0041b570`.

Queue wrapper at `0x0041b2d0`:

- Disassembly: `push ebp; mov ebp, esp; push 0; push [ebp+arg_4]; push [ebp+arg_0]; call sub_596960; pop ebp; retn 8`.
- Decompilation: `return sub_596960(this, a2, a3, 0);`.
- Callees: only `0x00596960`.
- Xrefs to function start: zero ordinary or data xrefs.
- Callee `0x00596960` is the generic thread queue helper: it packs six dwords, calls `0x00556580`, and signals the thread semaphore through `ReleaseSemaphore`.
- The IDA name `___std_fs_create_symbolic_link@8` is not credible because the body has no path/string/filesystem API behavior and directly forwards to project thread queue support.

Small-string reset at `0x0041b300`:

- Decompilation reads capacity at `this[5]`, frees heap storage when capacity is at least `0x10`, applies the MSVC large-allocation validation branch when capacity plus terminator reaches `0x1000`, then writes empty SSO state: length `0`, capacity `15`, and first byte `0`.
- Callees: `0x005c7526` free wrapper and `__invalid_parameter_noinfo_noreturn`.
- Xrefs: `340` xrefs from `110` distinct functions.
- Representative callers include `0x0041aa00` `DownloadCashShopVersion`, `0x00422740` fitting-room JSON state parsing, JsonCpp/value support paths, startup/update string paths, and later shared string/container users.
- The broad caller distribution and MSVC SSO-15 layout disqualify FileDownloader or JsonCpp-only ownership.

JsonCpp reader destructor at `0x0041b350`:

- Decompilation frees `JSONCPP_STRING`-shaped fields at `+0x54/+0x64/+0x68` and `+0x28/+0x38/+0x3c`, iterates the error container at `+0x18/+0x1c/+0x20/+0x24`, frees each error message string at entry `+0x0c/+0x1c/+0x20`, releases maps/pointers at `+0x18`, `+0x14`, and `+0x04`, then resets counters/pointers.
- Callees: `0x005c7526` free wrapper and `__invalid_parameter_noinfo_noreturn`.
- Xrefs: four total. Ordinary calls are `0x0041add9` in `DownloadCashShopVersion` and `0x004228ac` in `FittingRoomDialogItemStateLoadEncodedStateBuffer`; EH/unwind references are `0x005f6770` and `0x005f6caf`.
- Paired constructor `0x004298f0` initializes the same layout: `nodes_`, `errors_`, `document_`, cursor pointers, `commentsBefore_`, `features_ = Features::all()`, and `collectComments_`.
- Staged source comparison: `source-3/third_party_embeds/jsoncpp/include/json/reader.h` declares `Json::Reader` with `Nodes nodes_; Errors errors_; JSONCPP_STRING document_; Location begin_; Location end_; Location current_; Location lastValueEnd_; Value* lastValue_; JSONCPP_STRING commentsBefore_; Features features_; bool collectComments_;`. `src/lib_json/json_reader.cpp` initializes the same members in `Reader::Reader()`.

## Documentation Evidence Checked

- [UID:0000OR] `Thread` and [UID:0000EV] `Thread` document `0x00596960` as generic thread queue-post support. IDA confirms `0x0041b2d0` forwards to it, but no xref or type evidence proves the wrapper itself is declared by Thread.
- [UID:0000WN] `MsvcStringSupportHelpers`, [UID:0002CZ] `SmallStringStorageAssign`, and [UID:0002UG] `SmallString24AssignCopyHelper` already document the same SSO-15 runtime helper family. IDA confirms `0x0041b300` belongs with that ignored runtime/string-support surface.
- [UID:0000KI] `JsonCpp` is a `92/88` third-party parent for the statically embedded JsonCpp source. IDA and staged-source comparison confirm `0x0041b350` is the `Json::Reader` destructor side of the same constructor/parse front-end family documented at [UID:0000X0].
- [UID:0002TS] `DownloadCashShopVersion` and [UID:0002E9] `FittingRoomDialogItemStateLoadEncodedStateBuffer` are product consumers of the JsonCpp reader. Their calls prove usage, not direct product ownership of `0x0041b350`.
- Existing [UID:0000WI] FileDownloader aggregate documentation was partly correct for the downloader children, but incorrect as a single-source parent because the hidden helper spans belong to multiple owners/dispositions.

## Ranked Candidate Ownership

### 1. Mixed Inventory For [UID:0000WI] - Accepted

Evidence for:

- The numeric range includes exact FileDownloader methods/helpers, existing CashShopRequest/CashShopVersionRequest destructor wrappers, ignored padding, runtime string support, a JsonCpp destructor, and a real unreferenced queue wrapper.
- By-structure rules require exact children to carry direct source ownership when a broad page is only an address-neighborhood inventory.
- The repaired parent no longer claims source reconstruction for code owned by JsonCpp/runtime/CashShopRequest or unknown Thread support.

Evidence against:

- Keeping the old filename may still look FileDownloader-biased from the path alone.

Decision:

- Accepted. The title and body now explicitly state "Dispatch And Support Inventory"; no source parent is assigned to the aggregate.

Confidence: `90/100`.

### 2. FileDownloader As Parent For Whole [UID:0000WI] - Rejected

Evidence for:

- The span begins with FileDownloader constructor/destructor/download dispatch helpers.
- Several exact children remain valid FileDownloader children.

Evidence against:

- `0x0041b300` has `340` xrefs across `110` functions and is shared SSO runtime support.
- `0x0041b350` is a JsonCpp `Json::Reader` destructor also used by fitting-room JSON parsing.
- `0x0041b570` and later exact children carry CashShopRequest/CashShopVersionRequest ownership.
- `0x0041b2d0` has no FileDownloader xrefs, fields, singleton access, message constants, or vtable evidence.

Decision:

- Rejected for the aggregate. Valid only for exact FileDownloader children.

Confidence: `90/100`.

### 3. Thread / Worker-Queue Support For [UID:0003GY] - Best Forced Candidate, Not Assigned

Evidence for:

- `0x0041b2d0` does only one thing: forward two stack arguments plus a zero optional argument to generic thread queue helper `0x00596960`.
- Receiver stays in `ecx`, consistent with a tiny method wrapper over a thread-like object.
- Existing Thread docs already classify `0x00596960` as shared base-thread queue-post support.

Evidence against:

- IDA reports zero inbound xrefs to `0x0041b2d0`.
- There is no vtable slot, class field access, data reference, caller type, or source-island evidence proving this exact wrapper's declaration owner.
- Nearby FileDownloader submit helpers call `0x00596960` directly, so adjacency does not prove this wrapper is a FileDownloader helper.

Decision:

- Leave [UID:0003GY] reconstructable and parent-blank. Do not create a new parent from one dead wrapper. If later caller/source evidence appears, the likely family would be Thread or a derived worker-dispatch overload family containing small wrappers around `0x00596960`, not a FileDownloader-only file.

Confidence: `86/100` behavior, below assignment threshold for parent.

### 4. Runtime String Support For [UID:0003GZ] - Accepted

Evidence for:

- SSO-15 byte-string layout, length/capacity fields, heap/inline threshold, large-allocation validation, and `0x005c7526` free wrapper match the existing ignored MSVC/Dinkumware string-support family.
- The helper is shared broadly across product and third-party callers.

Evidence against:

- Exact vendor/internal symbol name is not recovered.

Decision:

- Accepted. [UID:0003GZ] is ignored runtime/compiler support, not source-authored FileDownloader or JsonCpp product code.

Confidence: `90/100`.

### 5. JsonCpp For [UID:0003H0] - Accepted

Evidence for:

- `0x0041b350` destructs the exact layout initialized by `0x004298f0`.
- Product callers pair JsonCpp construction `0x004298f0`, parse `0x00429b30`, JSON key reads, and this destructor.
- Staged JsonCpp source layout matches the binary member order and constructor behavior.
- [UID:0000KI] clears the parent gate and already owns the embedded JsonCpp source family.

Evidence against:

- The destructor body is compiler-generated from source declarations rather than a named handwritten upstream method recovered from symbols.

Decision:

- Accepted. Attach [UID:0003H0] to [UID:0000KI] `JsonCpp`; rebuild should come from compiling the vendored JsonCpp source, not NexusTK product code.

Confidence: `90/100`.

## Disconfirming Evidence Summary

- The current IDA name on `0x0041b2d0` is disconfirmed by the body: no filesystem arguments, no filesystem API, no path/string work, and a direct call to thread queue support.
- FileDownloader ownership for `0x0041b2d0` is disconfirmed by zero inbound xrefs and absence of downloader fields/messages/singleton access.
- FileDownloader ownership for `0x0041b300` is disconfirmed by `340` xrefs from `110` functions and the SSO runtime layout.
- JsonCpp-only ownership for `0x0041b300` is disconfirmed by non-JsonCpp callers across product/runtime code.
- FileDownloader or FittingRoom ownership for `0x0041b350` is disconfirmed by matching JsonCpp `Reader` layout and two independent product JSON consumers.
- Treating the whole `0x0041a670-0x0041b69f` span as one reconstructable FileDownloader entity is disconfirmed by the hidden helper splits and existing non-FileDownloader exact children.

## Repair Details

Created:

- `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`
- `by-memory/0x0041b300-0x0041b34a.SmallStringStorageReset.md`
- `by-memory/0x0041b350-0x0041b565.JsonCppReaderDestructor.md`

Updated:

- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`
- `by-memory/-ignored.md`

Not edited:

- `by-memory/-coverage-report.md`

Validator:

- File-mode validator with `--apply` was run over the three new child pages.
- File-mode validator with `--apply` was then run over the parent inventory and ignored ledger.
- A final correction pass repaired the JsonCpp child cross-reference from the stale fitting-room UID to [UID:0002E9] and exited `0`.
- Validator-owned generated outputs were updated by the tool; no manual coverage-report edit was made.

## Pending Coverage-Report Edits For Supervisor

Replace the current stale [UID:0000WI] coverage-report row:

```text
    - [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) 0x0041a670-0x0041b69f | aggregate | FileDownloaderDispatch : reconstructable : 84% : strong : Aggregate FileDownloader construction, message dispatch, download helpers, attached submit helpers, cleanup, and destructor wrappers; live IDA confirms exact child functions, queue callsites, singleton xrefs, and internal padding.
```

with:

```text
    - [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) 0x0041a670-0x0041b69f | aggregate | FileDownloaderDispatchAndSupportInventory : ignored : 88% : strong : Reviewed non-emitting mixed address inventory for FileDownloader dispatch plus adjacent Thread-wrapper, MSVC string-support, JsonCpp reader destructor, and CashShop request destructor spans; exact children carry source/runtime ownership.
```

Inside that parent block, after the existing [UID:0002CL] row and before the existing [UID:0002CM] row, replace the stale [UID:0000WK] through [UID:0002CM] sequence with the following rows. The existing earlier FileDownloader child rows through [UID:0002CL] remain unchanged. The existing [UID:0002CM] and following rows may remain unchanged after these inserted rows except for placement after the new padding row.

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b2c9-0x0041b2d0 | padding | Version submit to unreferenced queue wrapper alignment : ignored : 100% : strong : 2026-06-12 B001 byte audit shows seven `0xcc` bytes.
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Real unreferenced queue wrapper that forwards two arguments plus zero to generic Thread dispatch helper `0x00596960`; parent remains blank because no caller/vtable/source-island evidence proves the direct owner.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b2e4-0x0041b2f0 | padding | Queue wrapper to FileDownloader clear-helper alignment : ignored : 100% : strong : 2026-06-12 B001 byte audit shows twelve `0xcc` bytes.
        - [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) 0x0041b2f0-0x0041b2fb | function | ClearFileDownloaderRequestGlobal : reconstructable : 85% : strong : Tiny constructor-unwind cleanup helper that clears `dword_67A738`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b2fb-0x0041b300 | padding | Clear helper to small-string reset alignment : ignored : 100% : strong : 2026-06-12 B001 byte audit reconfirmed five `0xcc` bytes.
        - [UID:0003GZ][0x0041b300-0x0041b34a.SmallStringStorageReset](by-memory/0x0041b300-0x0041b34a.SmallStringStorageReset.md) 0x0041b300-0x0041b34a | runtime | SmallStringStorageReset : ignored : 86% : strong : Shared SSO-15 byte-string reset/destructor helper with 340 xrefs from 110 functions; regenerate through source string/container declarations and compiler/runtime support.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b34a-0x0041b350 | padding | Small-string reset to JsonCpp Reader destructor alignment : ignored : 100% : strong : 2026-06-12 B001 byte audit shows six `0xcc` bytes.
        - [UID:0003H0][0x0041b350-0x0041b565.JsonCppReaderDestructor](by-memory/0x0041b350-0x0041b565.JsonCppReaderDestructor.md) 0x0041b350-0x0041b565 | third-party | JsonCppReaderDestructor : reconstructable : 88% : strong : JsonCpp `Json::Reader` implicit destructor paired with constructor `0x004298f0` and parser `0x00429b30`; assigned to [UID:0000KI][JsonCpp](by-file/JsonCpp.md) after staged-source layout comparison.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b565-0x0041b570 | padding | JsonCpp Reader destructor to CashShopRequest deleting destructor alignment : ignored : 100% : strong : 2026-06-12 B001 byte audit shows eleven `0xcc` bytes.
        - [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) 0x0041b570-0x0041b5db | method | CashShopRequestScalarDeletingDestructor : reconstructable : 84% : strong : Physical child of the mixed `0x0041a670-0x0041b69f` inventory but direct autogen child of `CashShopRequest`; IDA MCP confirms function `sub_41B570` size `0x6b`, data xref from `0x0060d7a0`, no direct code callers, callees `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`, and CashShopRequest vtable ownership.
```

Placement context:

- The replacement parent row belongs immediately after the existing `0x0041a662-0x0041a670` ignored padding row.
- The inserted child/padding rows belong after [UID:0002CL] `0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest` and before [UID:0002CN] `0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor`, with [UID:0002CM] retained in address order after the new `0x0041b565-0x0041b570` padding row.

## Concrete Next Actions

- Supervisor should apply the exact `by-memory/-coverage-report.md` row edits above.
- Do not create a new source/file/class parent for [UID:0003GY] from the current evidence. Revisit only if a caller, vtable slot, source signature, or broader wrapper family is found.
- Keep [UID:0003GZ] ignored as runtime string support.
- Keep [UID:0003H0] under [UID:0000KI] `JsonCpp`.
- Continue future B-agent ownership/split backlog work one task at a time from the archived supervisor queue after this report is accepted.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000WI-FileDownloaderDispatchHiddenHelperGap.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000WI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
