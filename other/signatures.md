# IDA Signature Review

Date: 2026-06-12

This report records IDA FLIRT signature probe results for the NexusTK IDB and compares selected candidate matches against project documentation and IDA/MCP evidence. Items copied from screenshots are treated as provisional until checked in IDA, because the UI truncates long names and may hide low-order address digits in narrow columns.

## Review Summary

This is a cautionary signature review, not a blanket approval to rename everything IDA Feeds or FLIRTDB can probe. The signatures are useful for identifying MSVC/STL/runtime islands, but the checked candidates also show false positives where generic compiler-looking byte patterns collide with real NexusTK product code.

- Screenshot candidates reviewed: `119`
- Signature verdicts: `83` accurate support/classification hits, `36` inaccurate hits
- Documentation verdicts: `19` accurate, `5` partial, `0` inaccurate
- Main safe use: reinforce already-documented non-reconstructable MSVC/STL/runtime/compiler-support ranges
- Main unsafe use: applying individual names inside reconstructable Browser, MapPane, Socket, Layer, Mail/Dialog, Group/Collection, or SystemMessage code without a local IDA check

## External Research Notes

These references were used to frame the review. They do not replace the local IDA and `by-memory` checks, because signature databases can identify common library code but cannot know this project's source-ownership boundaries.

| Source | Relevance to this review |
| --- | --- |
| Hex-Rays FLIRT technology docs: `https://docs.hex-rays.com/core/flirt/concepts/ida-f.l.i.r.t.-technology-in-depth` | FLIRT identifies standard library functions from signature patterns. That makes it good first-pass evidence for compiler/runtime support, but pattern matches still need local validation when a candidate overlaps documented project code. |
| Hex-Rays IDA Feeds docs: `https://docs.hex-rays.com/extensions/plugins/concepts/plugins-shipped-with-ida/ida-feeds` | IDA Feeds is useful for finding/applying many candidate signatures quickly. For this IDB, the probe output should be treated as a triage list rather than a safe bulk-apply list. |
| FLIRTDB repository: `https://github.com/maktm/flirtdb` | The probed `flirtdb_*_15_msvc_x86.sig` files appear to come from a community signature collection. Its README discusses signature generation and collision handling, which matches the false-positive pattern seen here. |
| Hex-Rays Lumina docs: `https://docs.hex-rays.com/lumina/overview` and `https://docs.hex-rays.com/ida-9.2/user-guide/user-interface/menu-bar/common-actions-3` | Lumina provides function metadata such as names, prototypes, comments, and operand data. It can overwrite existing metadata when pulling/applying matches, so it should be used with an IDB snapshot and the same by-memory validation used for FLIRT rows. |

## High-Risk Match Patterns Found

- Tiny generic stubs are risky. Several `_Get_deleter` matches landed on five-byte project virtual methods or COM stubs that simply return zero.
- Interior addresses are risky. Some candidates land inside a documented product function or table-driven dispatcher rather than at a clean function start.
- Truncated screenshot addresses are risky. Rows ending in `?` are judged only from the visible neighborhood and should not be renamed until the exact IDA row is exported or copied.
- Runtime islands can still have wrong concrete names. The broad `MSVC runtime/STL` classification can be correct while a proposed symbol such as `__vcrt_GetModuleHandleW` is wrong at the exact address.
- EH handler and unwind funclet matches are support-only. They help classify compiler-generated exception-support regions, but they should not become source reconstruction targets.

## Screenshot-Extracted Candidates

The following candidates were transcribed from the provided screenshots before deeper analysis. The entries are function-start candidates, not byte ranges. Addresses are normalized to the `0x00......` image base style when enough digits were visible; entries ending in `?` need IDA confirmation because the screenshot appears to truncate one or more low-order digits.

### `flirtdb_libcmt_15_msvc_x86.sig`

| Candidate address | Screenshot name/status |
| --- | --- |
| `0x0043a590` | `unknown_libname_96` |
| `0x00470160` | `??0?$_crt_unique_heap_ptr@UTlsDtorNo...` |
| `0x005c5e42` | `unknown_libname_97` |
| `0x00577526` | `unknown_libname_98` |
| `0x005776d?` | `??_Gtype_info@@UAEPAXI@Z` |
| `0x0057790?` | `??_U@YAPAXI@Z` |
| `0x0057910?` | `unknown_libname_99` |
| `0x005791e?` | `unknown_libname_100` |
| `0x005084e?` | `?post_pgo_initialization@@YAHXZ` |
| `0x005084b6` | `?pre_cpp_initialization@@YAXXZ` |
| `0x0058704?` | `??0bad_array_new_length@std@@QAE@...` |
| `0x0050895e` | `__scrt_set_unhandled_exception_filter` |
| `0x00508a9b` | `__scrt_is_user_matherr_present` |
| `0x005f97d0` | `__ehhandler$??0YAPAXIABUnothrow_t...` |
| `0x005fd608` | `__ehhandler$??0YAPAXIABUnothrow_t...` |
| `0x005fd660` | `__ehhandler$??0YAPAXIABUnothrow_t...` |
| `0x005ffcd3` | `__ehhandler$??0YAPAXIABUnothrow_t...` |
| `0x006000c0` | `__ehhandler$??0YAPAXIABUnothrow_t...` |
| `0x00603ee1` | `__ehhandler$??0YAPAXIABUnothrow_t...` |
| `0x006051ad` | `__ehhandler$??0YAPAXIABUnothrow_t...` |
| `0x00609a29` | `__ehhandler$??0YAPAXIABUnothrow_t...` |
| `0x0060c07b` | `__ehhandler$??0YAPAXIABUnothrow_t...` |

### `flirtdb_libcpmt_15_msvc_x86.sig`

| Candidate address | Screenshot name/status |
| --- | --- |
| `0x00439c40` | `??1?$basic_istream@DU?$char_traits@D...` |
| `0x00439c60` | `??1?$basic_ostream@DU?$char_traits@D...` |
| `0x0043a590` | `unknown_libname_96` |
| `0x004f170?` | `unknown_libname_97` |
| `0x0040a60?` | `unknown_libname_98` |
| `0x0040ad0?` | `unknown_libname_99` |
| `0x0040f20?` | `unknown_libname_100` |
| `0x0040f90?` | `unknown_libname_101` |
| `0x0046a160` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x0046a170` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x0046a1e0` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x0046c870` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x0046c880` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x0046c8f0` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x0046f720` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x0046f730` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x0046f7a0` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x00470160` | `unknown_libname_102` |
| `0x004a60c?` | `??Ufilesystem@experimental@std@@...` |
| `0x0047cb0?` | `?_Init_atomic_counter@std@@YAXAAK...` |
| `0x00516040` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x005655a0` | `?_Get_deleter@_Ref_count_base@std@@...` |
| `0x005c5d79` | `??0invalid_argument@std@@QAE@ABV...` |
| `0x005c5db3` | `??0length_error@std@@QAE@ABV01@...` |
| `0x005c5ded` | `??0logic_error@std@@QAE@ABV01@Z` |
| `0x005c5e0?` | `??0out_of_range@std@@QAE@ABV01@...` |
| `0x005c5e42` | `unknown_libname_103` |
| `0x0056f4a?` | `unknown_libname_104` |
| `0x0056cae?` | `unknown_libname_105` |
| `0x005c6bc?` | `unknown_libname_106` |
| `0x005776d?` | `??_G_Ref_count_base@std@@UAEPAXI@Z` |
| `0x005f6f4d` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005f8f50` | `__ehhandler$?_CurrentException@_Exce...` |
| `0x005f9180` | `__unwindfunclet$??0_Locinfo@std@@...` |
| `0x005f9188` | `__unwindfunclet$??0_Locinfo@std@@...` |
| `0x005f9193` | `__unwindfunclet$??0_Locinfo@std@@...` |
| `0x005f919e` | `__unwindfunclet$??0_Locinfo@std@@...` |
| `0x005f91a9` | `__unwindfunclet$??0_Locinfo@std@@...` |
| `0x005f91b4` | `__unwindfunclet$??0_Locinfo@std@@...` |
| `0x005f91bf` | `__unwindfunclet$??0_Locinfo@std@@...` |
| `0x005f91ca` | `__unwindfunclet$??0_Locinfo@std@@...` |
| `0x005f9c6c` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005f900?` | `__ehhandler$?_CurrentException@_Exce...` |
| `0x005f9f1?` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005f9f7?` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005fa070` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005fc18d` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005fd4e3` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005ff080` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005ff26b` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005ff68e` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005ff780` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005ff9e3` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005ffd16` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005ffed7` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x005fff74` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x006004a0` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x00602aa3` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x006021e3` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x0060313e` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x0060401b` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x006040f?` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x006040a0` | `__ehhandler$?_CurrentException@_Exce...` |
| `0x00605a9b` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x00605e50` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x00607f50` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x00608240` | `__ehhandler$?_CurrentException@_Exce...` |
| `0x00608370` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x00608b70` | `__unwindfunclet$?Rethrow_future_exce...` |
| `0x00608b78` | `__ehhandler$?_Rethrow_future_exceptio...` |
| `0x00608ba0` | `__unwindfunclet$?Rethrow_future_exce...` |
| `0x00608ba8` | `__ehhandler$?_Rethrow_future_exceptio...` |
| `0x00608ce2` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x00609152` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x0060a1f8` | `__ehhandler$??0locale@std@@QAE@AB...` |
| `0x0060bab0` | `__ehhandler$?_CurrentException@_Exce...` |

### `flirtdb_libvcruntime_15_msvc_x86.sig`

| Candidate address | Screenshot name/status |
| --- | --- |
| `0x004297c0` | `unknown_libname_96` |
| `0x00429890` | `unknown_libname_97` |
| `0x0043a590` | `unknown_libname_98` |
| `0x0040160?` | `unknown_libname_99` |
| `0x005c5d2c` | `??0bad_exception@std@@QAE@XZ` |
| `0x005c5e42` | `unknown_libname_100` |
| `0x005c6cae` | `__vcrt_GetModuleHandleW` |
| `0x005c6cbc` | `__vcrt_GetModuleHandleW` |
| `0x005c791e` | `unknown_libname_101` |
| `0x005c87f?` | `??0bad_exception@std@@UAE@XZ` |
| `0x005c91f2` | `__std_terminate` |
| `0x005cc7be` | `??0bad_exception@std@@QAE@XZ` |
| `0x005f97d0` | `__ehhandler$?CallUnexpected@@YAXPB...` |
| `0x005fd608` | `__ehhandler$?CallUnexpected@@YAXPB...` |
| `0x005fd660` | `__ehhandler$?CallUnexpected@@YAXPB...` |
| `0x005ffcd3` | `__ehhandler$?CallUnexpected@@YAXPB...` |
| `0x006000c0` | `__ehhandler$?CallUnexpected@@YAXPB...` |
| `0x00603ee1` | `__ehhandler$?CallUnexpected@@YAXPB...` |
| `0x006051ad` | `__ehhandler$?CallUnexpected@@YAXPB...` |
| `0x00609a29` | `__ehhandler$?CallUnexpected@@YAXPB...` |
| `0x0060c07b` | `__ehhandler$?CallUnexpected@@YAXPB...` |

## Initial Notes Before Analysis

- The same addresses appear under multiple MSVC-related signatures, especially `0x0043a590`, `0x005c5e42`, and several `__ehhandler` addresses. These overlaps need manual review before applying names broadly.
- Many `__ehhandler` and `__unwindfunclet` entries are compiler-generated exception metadata/helper fragments. They are likely non-reconstructable support, but this should be checked against the existing ignored/runtime-support documentation.
- The C++ standard-library names under `libcpmt` are plausible because project documentation already records MSVC/Dinkumware/STL helper islands near JsonCpp and iostream/string support.

## IDA/MCP Session

The checks below used the headless `idalib-mcp` server against:

- Target IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- MCP endpoint: `127.0.0.1:13337`
- MCP session: `826292b2`

The first server start failed because the IDB was still open in IDA. After closing the interactive IDA copy, the server opened the same IDB successfully.

## Documentation Range Cross-Check

These ranges are from the project documentation and are used to decide whether a signature match is probably third-party/runtime support or project-owned code. This is a documentation and IDA-name cross-check, not a fresh byte-for-byte FLIRT validation.

| Candidate area | Existing documentation range | Current project classification | Assessment |
| --- | --- | --- | --- |
| `0x00439c40`, `0x00439c60` | `0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md` | Non-reconstructable MSVC/Dinkumware STL support | Signature names are plausible support names. |
| `0x0043a590` | `0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md` | Non-reconstructable MSVC/Dinkumware STL/numeric support | Signature/runtime classification is plausible. |
| `0x00470160` | `0x00470160-0x0047016e.CAtlExceptionConstructorThunk.md` | Non-reconstructable ATL exception helper thunk | Do not accept unrelated CRT heap pointer naming here without stronger proof. |
| `0x0046a160` | `0x00469640-0x0046a39c.BrowserWindowCore.md` | Reconstructable Browser project code | `std::_Ref_count_base::_Get_deleter` is likely a false positive. |
| `0x0046c870` | `0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` | Reconstructable Browser project code | `std::_Ref_count_base::_Get_deleter` is likely a false positive. |
| `0x0046f720` | `0x0046f670-0x0046f808.BrowserComStubMethods.md` | Browser COM stub methods | `std::_Ref_count_base::_Get_deleter` is likely a false positive. |
| `0x005c5d79`, `0x005c5db3`, `0x005c5ded`, `0x005c5e42`, `0x005c6cae`, `0x005c91f2` | `0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md` | Non-reconstructable MSVC runtime/STL support | Several hits are plausible, but some individual names conflict with IDA evidence. |
| `0x005f97d0` through `0x0060c07b` samples | `0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md` | Non-reconstructable compiler-generated EH/SEH funclet island | Treat as compiler-support classification. Avoid turning these fragments into source work. |

## Documentation Verdicts

These verdicts are for the `by-memory` documentation itself, separate from the signature verdicts. `Accurate` means the documentation's ownership/classification and important boundaries match the current IDA evidence used in this review. `Partial` means the documentation is directionally correct but broad, mixed-owner, raw-byte-dependent, or below exact final-source precision. `Inaccurate` would mean the documentation contradicts current IDA in a way that affects these signature decisions; no full `Inaccurate` documentation verdict was found in this pass.

| Documentation | Verdict | Documentation check | IDA check | Effect on signature review |
| --- | --- | --- | --- | --- |
| `0x00401000-0x00414283.LibJpeg6bCore.md` | **Accurate** | Documents IJG libjpeg 6b with source/string anchors. | Candidate neighborhoods such as `0x0040160?` and `0x0040a60?` fall inside this third-party JPEG range, not MSVC runtime/STL. | Signature rows in this range are inaccurate, but the documentation is not the problem. |
| `0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md` plus children `0x00428b50-0x00428c53`, `0x00428c60-0x00429473`, and `0x00429480-0x004298e6` | **Accurate** | Now documents a JsonCpp split index with source-bearing CommentInfo, PathArgument/Path, and iterator children. | Current IDA modeled count is still `15`, but B002 raw disassembly found additional JsonCpp method starts; `0x004297c0` and `0x00429890` are best treated as JsonCpp iterator trivial copy/helper bodies with runtime-like signatures. | Keeps the generic runtime-like signature note for those byte shapes, but rejects standalone runtime source ownership for the local range. |
| `0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md` | **Accurate** | Documents non-reconstructable MSVC/Dinkumware iostream support. | Current IDA count is `63` function starts; `0x00439c40` and `0x00439c60` remain inside this support island. | Supports accepting those signature rows as library support. |
| `0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md` | **Accurate** | Documents non-reconstructable MSVC/Dinkumware STL/numeric support. | Current IDA count is `80` function starts; `0x0043a590` is still an IDA Visual C 14 runtime-marked helper. | Supports accepting the `0x0043a590` runtime/STL rows. |
| `0x004f0480-0x004f1bf6.Layer.md` | **Accurate** | Identifies reconstructable `Layer` product code with live boundaries. | The visible `0x004f170?` candidate falls in this product range, not a standard-library island. | Makes the libcpmt `0x004f170?` row inaccurate. |
| `0x00469640-0x0046a39c.BrowserWindowCore.md` | **Accurate** | Identifies reconstructable `BrowserWindow` product code. | IDA still has `0x0046a160`, `0x0046a170`, and `0x0046a1e0` as five-byte return-zero COM stubs inside the range. | Confirms the `_Get_deleter` rows are false positives. |
| `0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` | **Accurate** | Identifies reconstructable `BrowserControlPane` product code. | IDA still has `0x0046c870`, `0x0046c880`, and `0x0046c8f0` as five-byte return-zero COM stubs inside the range. | Confirms the `_Get_deleter` rows are false positives. |
| `0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md` | **Accurate** | Documents a non-emitting mixed Browser/OLE inventory with exact children. | Checked child boundaries support the Browser COM stub child and the `CAtlException` helper child. | Supports using child pages instead of treating the whole range as one library hit. |
| `0x0046f670-0x0046f808.BrowserComStubMethods.md` | **Accurate** | Documents Browser COM stub methods. | IDA still has `0x0046f720`, `0x0046f730`, and `0x0046f7a0` as five-byte Browser COM return-zero stubs. | Confirms the `_Get_deleter` rows are false positives. |
| `0x00470160-0x0047016e.CAtlExceptionConstructorThunk.md` | **Accurate** | Documents the caller path into an ATL throw helper. | IDA still reports `unknown_libname_10` at `0x00470160-0x0047016e`. | Makes the concrete CRT heap-pointer name inaccurate, but generic library classification is acceptable. |
| `0x00479110-0x0047ec2b.MailDialogs.md` | **Accurate** | Records the mail-dialog aggregate and function inventory. | The checked `0x0047cb40` body is mail dialog code, not `std::_Init_atomic_counter`. | Makes the libcpmt `0x0047cb0?` row inaccurate. |
| `0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md` | **Accurate** | Documents `0x004a60c0` as an IDA Visual C runtime helper. | Current decompilation matches the documented int64 helper behavior. | The documentation is correct; the `experimental::filesystem` signature name is the inaccurate part. |
| `0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md` | **Partial** | Correct as a non-emitting coverage aggregate, but intentionally contains exact child pages plus an excluded ProfileStorage island. | IDA evidence should be interpreted through exact child pages such as `MapPanePacketDispatcher`. | Broad aggregate is useful context, but do not use it as one source-owner verdict. |
| `0x00507c90-0x00508f60.MapPanePacketDispatcher.md` | **Accurate** | Documents the dispatcher body and table tail through `0x00508f60`. | IDA resolves `0x005084b6`, `0x0050895e`, and `0x00508a9b` inside the single `0x00507c90-0x00508e06` dispatcher body. | Confirms the SCRT/PGO rows inside this dispatcher are false positives. |
| `0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md` | **Accurate** | Calls out `0x00516040` as an unmodeled no-xref return-zero stub between MemoryMan helpers. | Current bytes are `xor eax,eax; retn 4`. | Confirms the `_Get_deleter` row at `0x00516040` is a false positive. |
| `0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md` | **Accurate** | Documents `0x005655a0` as `GetContentWidth`. | IDA still shows a five-byte default virtual returning zero at `0x005655a0`. | Confirms the `_Get_deleter` row at `0x005655a0` is a false positive. |
| `0x0056c4c0-0x0056e939.GroupPanes.md` | **Partial** | Directionally correct for group-pane ownership, but explicitly contains raw helper gaps and provisional final source splits. | IDA-backed ownership is good enough for this signature decision, but not final-source exact. | Good enough to reject MSVC library classification in `0x0056cae?`, but not final-source exact. |
| `0x0056e940-0x0056fe75.CollectionPane.md` | **Partial** | Directionally correct for CollectionPane/CollectionPane2 ownership, but includes raw constructor caveats and unresolved final split details. | IDA-backed ownership is good enough for this signature decision, but not final-source exact. | Good enough to reject MSVC library classification in `0x0056f4a?`, but not final-source exact. |
| `0x00575d90-0x005796c7.SocketTransportCore.md` | **Partial** | Correct as a mixed non-emitting aggregate combining Socket methods, packet-transform helpers, raw bodies, and STL support. | Exact child pages carry the precise IDA-backed verdicts. | Explains why `0x00577526`/`0x005776d?` are product code while `0x005791xx` can still be STL support. |
| `0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md` | **Accurate** | Documents the raw serial-open Socket body. | IDA still has no function object at the raw start, but the bytes decode as the documented Socket body. | Confirms the `0x005776d?` rows are inaccurate as MSVC library names. |
| `0x00578f70-0x005797ae.StlTreeStringMapSupport.md` | **Accurate** | Identifies the tree/string-map support island and excludes it from handwritten Socket source. | Visible `0x005791xx` candidates land in this support family. | Supports accepting the `0x005791xx` rows as library/support classification. |
| `0x00584ea0-0x0058af3b.SystemMessagePanes.md` | **Partial** | Directionally supports system-message ownership, but is lower completion and lists interleaved ForcedInformMessageDialog exclusions. | IDA-backed ownership is enough to reject the sampled bad-array-new-length row, but not final-source exact. | Good enough to reject the `0x0058704?` bad-array signature row, but this page still needs more exact child splitting. |
| `0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md` | **Accurate** | Documents non-reconstructable MSVC runtime/STL support. | Current IDA count is `295` function starts; checked bodies confirm STL exception constructors, critical-section wrappers, bad-exception/bad-allocation distinction, and runtime helpers. | Supports runtime classification while rejecting bad concrete names such as `__vcrt_GetModuleHandleW` at critical-section wrappers. |
| `0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md` | **Accurate** | Documents a compiler-generated EH/SEH funclet island. | Current IDA has zero function starts inside the half-open range; candidate addresses resolve as fragments or containing-function tail areas. | Supports treating EH/SEH rows as support-only and not source work. |

## IDA Verification Highlights

These are the sampled addresses checked directly through IDA/MCP. The result is intentionally conservative: a match can be useful for classification even when the proposed symbol name should not be applied.

| Address | IDA/MCP observation | Recommendation |
| --- | --- | --- |
| `0x00439c40` | `sub_439C40`, small function inside documented STL iostream template support. | Plausible library support. Safe as non-reconstructable classification evidence. |
| `0x00439c60` | `sub_439C60`, same documented STL support range. | Plausible library support. Safe as non-reconstructable classification evidence. |
| `0x0043a590` | `unknown_libname_4`, IDA decompile comment identifies Microsoft Visual C 14 runtime and calls `___std_exception_destroy`. | Plausible runtime/STL helper. |
| `0x00470160` | Existing exact documentation identifies this as a `CAtlException` constructor thunk. | Keep the ATL exception interpretation unless a stronger source proves otherwise. |
| `0x0046a160` | Five-byte `return 0` style Browser method in `BrowserWindowCore`. | Reject `_Get_deleter` name here. This is a generic-body false positive. |
| `0x0046c870` | Five-byte `return 0` style Browser method in `BrowserControlPaneCore`. | Reject `_Get_deleter` name here. This is a generic-body false positive. |
| `0x0046f720` | Five-byte `return 0` style Browser COM stub in `BrowserComStubMethods`. | Reject `_Get_deleter` name here. This is a generic-body false positive. |
| `0x005c5d79` | Sets the `std::invalid_argument` vftable. | Plausible `std::invalid_argument` constructor support. |
| `0x005c5db3` | Sets the `std::length_error` vftable. | Plausible `std::length_error` constructor support. |
| `0x005c5ded` | Sets the `std::logic_error` vftable. | Plausible `std::logic_error` constructor support. |
| `0x005c5e42` | `unknown_libname_14`, IDA marks as Microsoft Visual C 14 runtime and calls exception cleanup helpers. | Plausible runtime/STL support. |
| `0x005c6cae` | Decompile shows a wrapper around `EnterCriticalSection`, not `__vcrt_GetModuleHandleW`. | Reject or manually re-check this specific proposed name. |
| `0x005c91f2` | Resolves inside an existing function/tail area rather than a clean standalone function start. | Do not blindly apply `__std_terminate` here. Needs stronger confirmation. |
| `0x005f97d0`, `0x005fd608`, `0x005fd660`, `0x005ffcd3`, `0x006000c0`, `0x00603ee1`, `0x006051ad`, `0x00609a29`, `0x0060c07b` | Resolve as EH handler/unwind fragments or inside containing functions in the documented `MsvcSehFuncletIsland`. | Useful as support evidence; do not promote these into reconstructable source targets. |

## Full Candidate Verdicts

Every screenshot-transcribed candidate below was checked against the smallest matching `by-memory` page and, where the address was exact enough, IDA/MCP lookup or decompilation. `Accurate` means the signature is consistent with the current documentation and IDA evidence for library/runtime/support classification. Some accurate rows are still support-only EH/SEH fragments and should not become source reconstruction targets. `Inaccurate` means the proposed name conflicts with the documented owner, lands inside a product/third-party function, or is not a clean function start. Rows with `?` in the address are judged from the visible address neighborhood because the screenshot hid one or more low-order digits.

Summary: `83` accurate support/classification hits, `36` inaccurate hits.

### `flirtdb_libcmt_15_msvc_x86.sig`

| Candidate | Proposed name | Verdict | Documentation check | IDA check |
| --- | --- | --- | --- | --- |
| `0x0043a590` | `unknown_libname_96` | **Accurate** | Documented MSVC/STL numeric-support helper. | IDA marks current body as Visual C 14 runtime. |
| `0x00470160` | `??0?$_crt_unique_heap_ptr@UTlsDtorNo...` | **Inaccurate** | by-memory identifies an ATL `CAtlException` thunk. | IDA agrees with ATL thunk ownership; wrong concrete CRT heap-pointer name. |
| `0x005c5e42` | `unknown_libname_97` | **Accurate** | Documented MSVC runtime/STL support island. | IDA evidence is consistent with an exception cleanup helper. |
| `0x00577526` | `unknown_libname_98` | **Inaccurate** | Documented Socket transport product code. | IDA resolves this as an interior offset in `ConnectEndpoint`, not a CRT function start. |
| `0x005776d?` | `??_Gtype_info@@UAEPAXI@Z` | **Inaccurate** | Visible address neighborhood is documented `SocketOpenSerialTransportRaw` product code. | Exact low-order digit is hidden in screenshot; no exact IDA rename should be applied yet. |
| `0x0057790?` | `??_U@YAPAXI@Z` | **Inaccurate** | Visible address neighborhood is documented Socket endpoint/parser product code. | Exact low-order digit is hidden in screenshot; no exact IDA rename should be applied yet. |
| `0x0057910?` | `unknown_libname_99` | **Accurate** | Visible address neighborhood is documented STL tree/string-map support. | Exact low-order digit is hidden in screenshot; plausible library/support classification only. |
| `0x005791e?` | `unknown_libname_100` | **Accurate** | Visible address neighborhood is documented STL tree/string-map support. | Exact low-order digit is hidden in screenshot; plausible library/support classification only. |
| `0x005084e?` | `?post_pgo_initialization@@YAHXZ` | **Inaccurate** | Visible address neighborhood is documented MapPane packet dispatcher product code. | Not confirmed as CRT startup; exact digit is hidden in screenshot. |
| `0x005084b6` | `?pre_cpp_initialization@@YAXXZ` | **Inaccurate** | Documented MapPane packet dispatcher product code. | IDA resolves this as an interior offset, not `pre_cpp_initialization`. |
| `0x0058704?` | `??0bad_array_new_length@std@@QAE@...` | **Inaccurate** | Visible address neighborhood is documented `SystemMessagePanes` product code. | Not confirmed as `std::bad_array_new_length`. |
| `0x0050895e` | `__scrt_set_unhandled_exception_filter` | **Inaccurate** | Documented MapPane packet dispatcher product code. | IDA resolves this as an interior offset, not SCRT unhandled-exception setup. |
| `0x00508a9b` | `__scrt_is_user_matherr_present` | **Inaccurate** | Documented MapPane packet dispatcher product code. | IDA resolves this as an interior offset, not SCRT matherr probe. |
| `0x005f97d0` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005fd608` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005fd660` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ffcd3` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x006000c0` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00603ee1` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x006051ad` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00609a29` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x0060c07b` | `__ehhandler$??0YAPAXIABUnothrow_t...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |

### `flirtdb_libcpmt_15_msvc_x86.sig`

| Candidate | Proposed name | Verdict | Documentation check | IDA check |
| --- | --- | --- | --- | --- |
| `0x00439c40` | `??1?$basic_istream@DU?$char_traits@D...` | **Accurate** | Documented MSVC/Dinkumware iostream support island. | No contradictory IDA evidence found in the checked address neighborhood. |
| `0x00439c60` | `??1?$basic_ostream@DU?$char_traits@D...` | **Accurate** | Documented MSVC/Dinkumware iostream support island. | No contradictory IDA evidence found in the checked address neighborhood. |
| `0x0043a590` | `unknown_libname_96` | **Accurate** | Documented MSVC/STL numeric-support helper. | IDA marks current body as Visual C 14 runtime. |
| `0x004f170?` | `unknown_libname_97` | **Inaccurate** | Visible address neighborhood is documented `Layer` product code. | Exact low-order digit is hidden in screenshot; no exact IDA rename should be applied yet. |
| `0x0040a60?` | `unknown_libname_98` | **Inaccurate** | Visible address neighborhood is documented `LibJpeg6bCore` third-party JPEG code. | Not checked as a valid MSVC C++ standard-library function start. |
| `0x0040ad0?` | `unknown_libname_99` | **Inaccurate** | Visible address neighborhood is documented `LibJpeg6bCore` third-party JPEG code. | Not checked as a valid MSVC C++ standard-library function start. |
| `0x0040f20?` | `unknown_libname_100` | **Inaccurate** | Visible address neighborhood is documented `LibJpeg6bCore` third-party JPEG code. | Not checked as a valid MSVC C++ standard-library function start. |
| `0x0040f90?` | `unknown_libname_101` | **Inaccurate** | Visible address neighborhood is documented `LibJpeg6bCore` third-party JPEG code. | Not checked as a valid MSVC C++ standard-library function start. |
| `0x0046a160` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented `BrowserWindow` project code. | IDA shows a return-zero stub; false positive for `std::_Get_deleter`. |
| `0x0046a170` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented `BrowserWindow` project code. | IDA shows a return-zero stub; false positive for `std::_Get_deleter`. |
| `0x0046a1e0` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented `BrowserWindow` project code. | IDA shows a return-zero stub; false positive for `std::_Get_deleter`. |
| `0x0046c870` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented `BrowserControlPane` project code. | IDA shows a return-zero stub; false positive for `std::_Get_deleter`. |
| `0x0046c880` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented `BrowserControlPane` project code. | IDA shows a return-zero stub; false positive for `std::_Get_deleter`. |
| `0x0046c8f0` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented `BrowserControlPane` project code. | IDA shows a return-zero stub; false positive for `std::_Get_deleter`. |
| `0x0046f720` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented Browser COM stub methods. | IDA shows a return-zero COM stub; false positive for `std::_Get_deleter`. |
| `0x0046f730` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented Browser COM stub methods. | IDA shows a return-zero COM stub; false positive for `std::_Get_deleter`. |
| `0x0046f7a0` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented Browser COM stub methods. | IDA shows a return-zero COM stub; false positive for `std::_Get_deleter`. |
| `0x00470160` | `unknown_libname_102` | **Accurate** | Exact docs identify an ATL `CAtlException` thunk. | Generic unknown-library classification is acceptable, but the concrete name should stay ATL-related. |
| `0x004a60c?` | `??Ufilesystem@experimental@std@@...` | **Inaccurate** | Documented `MsvcInt64RuntimeHelpers` helper range. | Visible function is an int64 runtime helper, not `experimental::filesystem` operator delete. |
| `0x0047cb0?` | `?_Init_atomic_counter@std@@YAXAAK...` | **Inaccurate** | Visible address neighborhood is documented MailDialogs/BulletinMail product code. | Not confirmed as `std::_Init_atomic_counter`. |
| `0x00516040` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented `MemoryManAndAllocationHelpers` return-zero stub. | IDA bytes match a local return-zero stub; false positive for `std::_Get_deleter`. |
| `0x005655a0` | `?_Get_deleter@_Ref_count_base@std@@...` | **Inaccurate** | Documented `ScrollablePaneVirtualDefaults` project/default method. | IDA shows `GetContentWidth` default return-zero behavior; false positive for `std::_Get_deleter`. |
| `0x005c5d79` | `??0invalid_argument@std@@QAE@ABV...` | **Accurate** | Documented MSVC runtime/STL support range. | IDA body sets `std::invalid_argument` vftable. |
| `0x005c5db3` | `??0length_error@std@@QAE@ABV01@...` | **Accurate** | Documented MSVC runtime/STL support range. | IDA body sets `std::length_error` vftable. |
| `0x005c5ded` | `??0logic_error@std@@QAE@ABV01@Z` | **Accurate** | Documented MSVC runtime/STL support range. | IDA body sets `std::logic_error` vftable. |
| `0x005c5e0?` | `??0out_of_range@std@@QAE@ABV01@...` | **Accurate** | Documented MSVC runtime/STL support range. | Visible range includes `std::out_of_range` constructor at `0x005c5e08`. |
| `0x005c5e42` | `unknown_libname_103` | **Accurate** | Documented MSVC runtime/STL support island. | IDA evidence is consistent with an exception cleanup helper. |
| `0x0056f4a?` | `unknown_libname_104` | **Inaccurate** | Visible address neighborhood is documented `CollectionPane` product code. | Exact low-order digit is hidden in screenshot; no exact IDA rename should be applied yet. |
| `0x0056cae?` | `unknown_libname_105` | **Inaccurate** | Visible address neighborhood is documented `GroupPanes` product code. | Exact low-order digit is hidden in screenshot; no exact IDA rename should be applied yet. |
| `0x005c6bc?` | `unknown_libname_106` | **Accurate** | Visible address neighborhood is documented MSVC runtime/STL support. | Exact low-order digit is hidden in screenshot; plausible mutex/locale helper area. |
| `0x005776d?` | `??_G_Ref_count_base@std@@UAEPAXI@Z` | **Inaccurate** | Visible address neighborhood is documented `SocketOpenSerialTransportRaw` product code. | Exact low-order digit is hidden in screenshot; no exact IDA rename should be applied yet. |
| `0x005f6f4d` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented EH/SEH funclet island. | IDA resolves this as an EH/SEH fragment; support-only. |
| `0x005f8f50` | `__ehhandler$?_CurrentException@_Exce...` | **Accurate** | Documented EH/SEH funclet island. | IDA resolves this as an EH/SEH fragment; support-only. |
| `0x005f9180` | `__unwindfunclet$??0_Locinfo@std@@...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x005f9188` | `__unwindfunclet$??0_Locinfo@std@@...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x005f9193` | `__unwindfunclet$??0_Locinfo@std@@...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x005f919e` | `__unwindfunclet$??0_Locinfo@std@@...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x005f91a9` | `__unwindfunclet$??0_Locinfo@std@@...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x005f91b4` | `__unwindfunclet$??0_Locinfo@std@@...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x005f91bf` | `__unwindfunclet$??0_Locinfo@std@@...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x005f91ca` | `__unwindfunclet$??0_Locinfo@std@@...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x005f9c6c` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005f900?` | `__ehhandler$?_CurrentException@_Exce...` | **Accurate** | Visible address neighborhood is documented SEH funclet island. | Exact low-order digit is hidden in screenshot; support-only until exported. |
| `0x005f9f1?` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Visible address neighborhood is documented SEH funclet island. | Exact low-order digit is hidden in screenshot; support-only until exported. |
| `0x005f9f7?` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Visible address neighborhood is documented SEH funclet island. | Exact low-order digit is hidden in screenshot; support-only until exported. |
| `0x005fa070` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005fc18d` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005fd4e3` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ff080` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ff26b` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ff68e` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ff780` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ff9e3` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ffd16` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ffed7` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005fff74` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x006004a0` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00602aa3` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x006021e3` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x0060313e` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x0060401b` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x006040f?` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Visible address neighborhood is documented SEH funclet island. | Exact low-order digit is hidden in screenshot; support-only until exported. |
| `0x006040a0` | `__ehhandler$?_CurrentException@_Exce...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00605a9b` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00605e50` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00607f50` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00608240` | `__ehhandler$?_CurrentException@_Exce...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00608370` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00608b70` | `__unwindfunclet$?Rethrow_future_exce...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x00608b78` | `__ehhandler$?_Rethrow_future_exceptio...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00608ba0` | `__unwindfunclet$?Rethrow_future_exce...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an unwind funclet fragment; support-only. |
| `0x00608ba8` | `__ehhandler$?_Rethrow_future_exceptio...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00608ce2` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00609152` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x0060a1f8` | `__ehhandler$??0locale@std@@QAE@AB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x0060bab0` | `__ehhandler$?_CurrentException@_Exce...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |

### `flirtdb_libvcruntime_15_msvc_x86.sig`

| Candidate | Proposed name | Verdict | Documentation check | IDA check |
| --- | --- | --- | --- | --- |
| `0x004297c0` | `unknown_libname_96` | **Accurate generic signature, revised local owner** | Documented in [UID:0003WK] JsonCpp iterator support. | IDA marks this two-dword copy helper as Visual C 14 runtime-like, but surrounding JsonCpp iterator methods and source order make it a `ValueConstIterator` copy/from-iterator helper candidate rather than standalone runtime source. |
| `0x00429890` | `unknown_libname_97` | **Accurate generic signature, revised local owner** | Documented in [UID:0003WK] JsonCpp iterator support. | IDA marks this two-dword copy helper as Visual C 14 runtime-like, but surrounding JsonCpp iterator methods and source order make it a `ValueIterator` copy/helper candidate rather than standalone runtime source. |
| `0x0043a590` | `unknown_libname_98` | **Accurate** | Documented MSVC/STL numeric-support helper. | IDA marks current body as Visual C 14 runtime. |
| `0x0040160?` | `unknown_libname_99` | **Inaccurate** | Visible address neighborhood is documented `LibJpeg6bCore` third-party JPEG code. | Exact low-order digit is hidden in screenshot; not confirmed as vcruntime. |
| `0x005c5d2c` | `??0bad_exception@std@@QAE@XZ` | **Inaccurate** | Documented MSVC runtime/STL support range. | IDA body initializes bad allocation, not `bad_exception`. |
| `0x005c5e42` | `unknown_libname_100` | **Accurate** | Documented MSVC runtime/STL support island. | IDA evidence is consistent with an exception cleanup helper. |
| `0x005c6cae` | `__vcrt_GetModuleHandleW` | **Inaccurate** | Documented MSVC runtime/STL support range. | IDA body calls `EnterCriticalSection`, not `GetModuleHandleW`. |
| `0x005c6cbc` | `__vcrt_GetModuleHandleW` | **Inaccurate** | Documented MSVC runtime/STL support range. | IDA body calls `LeaveCriticalSection`, not `GetModuleHandleW`. |
| `0x005c791e` | `unknown_libname_101` | **Accurate** | Documented MSVC runtime/STL support range. | IDA marks this security-cookie helper as Microsoft Visual C 14 runtime. |
| `0x005c87f?` | `??0bad_exception@std@@UAE@XZ` | **Inaccurate** | Documented MSVC runtime/STL support range. | Visible neighborhood is SCRT/SEH startup helper code, not confirmed `bad_exception`. |
| `0x005c91f2` | `__std_terminate` | **Inaccurate** | Documented MSVC runtime/STL support range. | IDA resolves this as an interior/tail address, not a clean `__std_terminate` function start. |
| `0x005cc7be` | `??0bad_exception@std@@QAE@XZ` | **Accurate** | Documented MSVC runtime/STL support range. | IDA body initializes the string `bad exception`; `bad_exception` candidate is plausible. |
| `0x005f97d0` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005fd608` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005fd660` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x005ffcd3` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x006000c0` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00603ee1` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x006051ad` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x00609a29` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |
| `0x0060c07b` | `__ehhandler$?CallUnexpected@@YAXPB...` | **Accurate** | Documented SEH funclet island. | IDA resolves this as an EH handler fragment; support-only. |

## Apply Recommendation

Do not bulk-apply all probed community signature results globally. The probes are useful, but this review found both valid runtime/STL matches and clear false positives. Use signatures as evidence to improve classification, then apply exact names only when IDA, the smallest matching `by-memory` page, and the candidate symbol agree.

Recommended handling:

- Accept the broad classification that the documented ranges `0x004361b0-0x00439df9`, `0x00439ee0-0x0043e0a3`, `0x00578f70-0x005797ae`, `0x005c5c87-0x005cea43`, and `0x005f66f7-0x0060c0a0` contain MSVC/STL/runtime/compiler-support code. For `0x00428b4b-0x004298f0`, use the newer split docs: most executable code is JsonCpp source, while `0x004297c0` and `0x00429890` remain generic runtime-like copy-helper signatures inside the JsonCpp iterator child.
- Treat `Accurate` EH handler and unwind rows as compiler support only. They help explain non-reconstructable areas but should not be promoted into source methods.
- Reject `_Get_deleter` rows at the Browser and pane virtual/default stubs unless a later exact decompile proves they are actual STL control-block methods. Current evidence says they are generic-body false positives.
- Reject SCRT/PGO rows inside the MapPane packet dispatcher. Current evidence places `0x005084b6`, `0x0050895e`, and `0x00508a9b` inside product dispatcher code, not CRT startup.
- Reject product-overlap rows in `LibJpeg6bCore`, `Layer`, `MailDialogs`, `GroupPanes`, `CollectionPane`, `SocketTransportCore`, and `SystemMessagePanes` unless a smaller child page and exact decompile prove a local runtime helper.
- Use concrete runtime exception names only where the IDA body agrees, such as `std::invalid_argument`, `std::length_error`, `std::logic_error`, `std::out_of_range`, and the checked `bad_exception` constructor at `0x005cc7be`.
- Keep `0x00470160` as the documented ATL `CAtlException` constructor thunk. Do not replace it with a CRT heap-pointer name from the screenshot.
- Before applying any row with `?` in the address, export or copy the exact IDA Feeds/FLIRT probe result from IDA so the low-order address digits and full symbol name are no longer inferred from a screenshot.

The safest workflow is to keep an IDB snapshot/backup before applying any FLIRT, IDA Feeds, or Lumina metadata, then apply only the matches that remain inside already-documented runtime/STL/support ranges and do not overwrite known project-owned names.

## Follow-Up Items

- Export the exact IDA Feeds/FLIRT probe table from IDA instead of relying on screenshots. This is especially important for addresses currently written with `?`.
- Split or refine partial documentation where source ownership is intentionally broad: `MapPaneInputPacketRenderCore`, `GroupPanes`, `CollectionPane`, `SocketTransportCore`, and `SystemMessagePanes`.
- Re-check the low-nibble-hidden rows after export, then update the candidate verdict table if any inferred neighborhood was off by enough to change ownership.
- If Lumina is used, prefer `View all` or selective pull/apply workflows over unattended bulk pull. Treat pulled names/types as advisory until they survive the same `by-memory` and IDA decompile check.
- Keep the current verdict distinction in future updates: documentation verdicts measure whether our `by-memory` pages match IDA, while signature verdicts measure whether a proposed signature name/classification should be trusted.

## Launcher Note

The desktop launcher input issue was checked while starting this MCP session. The helper script now reads menu keys through PowerShell host raw input first and falls back to console input if needed, which should make the polling/menu loop respond correctly in the normal launched window.
