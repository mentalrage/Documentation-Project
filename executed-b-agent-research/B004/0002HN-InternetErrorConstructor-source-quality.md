** TARGET-REPORT-UID:0002HN **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002HN InternetErrorConstructor Source-Quality Research

Agent: B004  
Assignment id: `B004-report-0002HN-InternetErrorConstructor-source-quality-20260627`  
Mode: report-only research  
Target: [UID:0002HN] `by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md`  
Report path: `tools/leaser/Agents/Agent-B004/research/0002HN-InternetErrorConstructor-source-quality.md`

Status: report-only research complete. No by-* docs, generated reports, generated C++, coverage reports, project-level generated files, validator state, or IDA database state were edited. No leases were taken. No subagents were spawned.

## Recommendation Summary

Update [UID:0002HN] from its current source-header state:

- `COMPLETION:85`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00006Q`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006Q`
- blank formal `RECONSTRUCTION_CPP CODE`

Recommended target state:

- `COMPLETION:90`
- `CONFIDENCE:92`
- keep `CANONICAL_OWNER:00006Q`
- keep `RECONSTRUCTABLE:TRUE`
- keep `EMITTER_UIDS:00006Q`
- keep `EMITTER_POSITION_OPTIONAL` blank
- populate the formal `RECONSTRUCTION_CPP CODE` block with the first-draft constructor C++ below

Recommended Item Summary:

`Source-ready exact InternetError constructor; live MCP confirms the 0x11a modeled range, one httpget caller, vtable store to 0x00619404, pointer-backed SimpleUString/StringBase wide member at +0x04, LoadLibraryW/FormatMessageW dispatch slots, 255-wide fallback buffer initialized to "General internet error", and formal constructor C++ through the InternetError/Error.cpp route.`

The current target body still has stale text from the earlier strict-gate era, including the old `78/88` and below-gate rationale in the Item Summary and reconstruction notes. That is no longer accurate: the child and direct [UID:00006Q] `InternetError` parent clear the active gate, the current MCP body is exact, and the target-local source shape is now strong enough for formal first-draft C++.

## Formal C++ Recommendation

Insert this exact block into [UID:0002HN]'s formal C++ section:

```cpp
InternetError::InternetError()
{
    HMODULE wininetModule = LoadLibraryW(L"WININET.DLL");
    wchar_t message[255] = L"General internet error";

    FormatMessageW(FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM,
                   wininetModule,
                   GetLastError(),
                   0,
                   message,
                   255,
                   0);

    m_message = message;
}
```

Notes for implementation:

- `m_message = message` is the source-facing expression for the observed `0x00582d20` `AssignWideLiteral` call on the pointer-backed wide string member at byte offset `+0x04`.
- The implicit base and member construction lower to `sub_4F4A80(this)` and `0x00582b20(this + 4)`. Do not emit those helper calls, vtable stores, SEH state changes, stack-cookie checks, or `return this` as source statements.
- The local buffer is exactly 255 wide characters. MCP disassembly pushes `0xff` as the `FormatMessageW` buffer length and zeroes the remaining 464 bytes after copying the 23-wide-character fallback literal including the terminator.
- `0x1800` is `FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM`. Do not mislabel it as `FORMAT_MESSAGE_IGNORE_INSERTS`.
- The final public facade name may still be `SimpleUString`, `StringBase<wchar_t>`, or a typedef, but the target documentation already uses `SimpleUString m_message`; this report preserves that local field name while citing the `StringBaseTemplate` helper evidence.

## Evidence Checked

Read before writing this report:

- B004 `goal.md`
- Project `ntk-b-agent-workflow` skill and required workflow/rule references
- Target [UID:0002HN] `InternetErrorConstructor`
- Support docs: [UID:00006Q] `InternetError`, [UID:00006P] `InternetConnectionError`, [UID:0000J5] `Error`, [UID:00013X] `ErrorWrappers`, [UID:0001UE] `ErrorObjectLayouts`, [UID:0001XI] `ErrorHierarchyVtables`, [UID:0002ND] `ErrorHierarchyVtableData`, [UID:0003I4] `ErrorHierarchyMessageStrings`, [UID:0000TQ] `WideApiDispatchTable`, [UID:0002RN] `StringBaseShareAssignAndAccess`, [UID:0001W4] `SimpleUStringPointerBackedLayout`, and [UID:0000D9] `SimpleUString`.
- Caller context [UID:0001CJ] `MiscWorkThreadAndNotifications`.
- Prior accepted reports: B013 `00013X-ErrorWrappers-source-quality`, B002 `0002TV-error-destructor-name-helpers-source-quality`, and B006 `0002RN-StringBaseShareAssignAndAccess-source-quality`.
- Generated/coverage state was read only for stale-row detection. No generated file or coverage report was edited.

## Live MCP Provenance

IDA MCP was mandatory and available.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp` version `1.0.0`
- Active database/session id: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready
- No IDA DB edits were made.

Read-only MCP calls used included `lookup_funcs`, `analyze_batch`, `xrefs_to`, `get_string`, and `get_bytes` for the target, caller, vtable/data refs, string literals, and support helpers.

## Current IDA Facts

`lookup_funcs` confirms:

| Query | Result |
| --- | --- |
| `0x004a6550` | `sub_4A6550`, size `0x11a`, exact target range `0x004a6550-0x004a666a` |
| `0x004a6670` | `sub_4A6670`, size `0x1e`, successor stored-message copy helper |
| `0x004a6690` | `sub_4A6690`, size `0xe2`, sibling `InternetConnectionError` constructor |
| `0x004a69c0` | `sub_4A69C0`, size `0x48`, shared string-member deleting destructor |
| `0x005277c0` / `0x0052786c` | caller function `sub_5277C0`, size `0x3e6` |
| `0x00582b20` | `InitializeEmptyWide` helper, size `0x0a` |
| `0x00582d20` | `AssignWideLiteral` helper, size `0x41` |
| `0x00584540` | two-instruction string data accessor, size `0x03` |
| `0x00619404` | data, not a function |

Target decompilation and disassembly show the exact constructor order:

1. Call shared base setup `sub_4F4A80(this)`.
2. Compute member address `this + 4`.
3. Install `InternetError::vftable` at `0x004a65a2` using vtable base `0x00619404`.
4. Initialize the pointer-backed wide string member through `0x00582b20(this + 4)`.
5. Call the wide API dispatch slot at `0x0069be30` with `0x006195e0`, the UTF-16 `WININET.DLL` literal.
6. Initialize the local wide buffer with the UTF-16 `General internet error` fallback at `0x006195f8`, then zero the rest of the 255-wide-character buffer.
7. Call imported `GetLastError`.
8. Call the wide API dispatch slot at `0x0069be6c` with flags `0x1800`, module handle, last-error code, language `0`, buffer pointer, size `0xff`, and arguments `0`.
9. Assign/copy the buffer into `this + 4` through `0x00582d20`.
10. Return through the compiler SEH/security-cookie epilogue.

MCP `analyze_batch` reports exactly one direct target caller: `0x0052786c` inside `sub_5277C0`. That caller allocates 8 bytes through `sub_4F4AA0(8)`, calls `sub_4A6550`, stores the resulting pointer in an `httpget::Notification` object, and posts the notification. This is construction/use evidence only; it does not move the constructor out of the shared Error hierarchy.

## Boundary And Split Evidence

The target range remains exact:

- `get_bytes 0x004a6540 size 16` shows predecessor return bytes followed by `0xcc` padding through `0x004a654f`.
- `0x004a6550` is the target prologue.
- `0x004a6669` is the target `retn`.
- `get_bytes 0x004a666a size 16` shows six `0xcc` padding bytes before the `0x004a6670` successor prologue.
- `lookup_funcs 0x004a6670` confirms the successor is the separate stored-message output helper, not part of this constructor.

Do not widen the target into `0x004a6670`, and do not merge it back into [UID:00013X] as aggregate-only source. The exact constructor is the correct emitting unit.

## Vtable And Data Routes

MCP `get_bytes 0x00619400 size 24` decodes the `InternetError` subtable:

| Data | Meaning |
| --- | --- |
| `0x00619400 -> 0x00646e00` | RTTI/COL pointer |
| `0x00619404 -> 0x004a69c0` | destructor slot |
| `0x00619408 -> 0x004f4b10` | inherited runtime/LObject slot |
| `0x0061940c -> 0x0041b6c0` | no-op slot |
| `0x00619410 -> 0x004a6670` | message-output slot |
| `0x00619414 -> 0x004a6a70` | common error-name slot |

`xrefs_to` confirms:

- `0x00619404` has a single data xref at `0x004a65a2`, the constructor vtable install.
- `0x004a6670` has a single vtable data xref at `0x00619410`.
- `0x004a69c0` has vtable data xrefs at `0x00619404` and `0x0061941c`, proving the shared `InternetError` / `InternetConnectionError` string-member deleting destructor route.

`0x004a6670` decompiles as:

```cpp
errno_t __thiscall sub_4A6670(int this, wchar_t *Destination, rsize_t SizeInWords)
{
    const wchar_t *text = (const wchar_t *)sub_584540((void *)(this + 4));
    return wcscpy_s(Destination, SizeInWords, text);
}
```

This proves the constructor's `+0x04` member is later consumed as a wide string object, and it supports the current `m_message` field name.

## String And API Support Evidence

The API dispatch blocker is closed:

- [UID:0000TQ] `WideApiDispatchTable` already maps `0x0069be30` to `LoadLibraryW` and `0x0069be6c` to `FormatMessageW`.
- Live target disassembly uses `call dword ptr unk_69BE30` after pushing `0x006195e0`, the `WININET.DLL` literal.
- Live target disassembly uses `call dword ptr unk_69BE6C` after pushing `0x1800`, the module handle, `GetLastError()`, language `0`, the local message buffer, `0xff`, and `0`.

The string-member blocker is now target-local and resolved:

- The `httpget` caller allocates 8 bytes for the error object, proving the object is vptr plus one 4-byte pointer-backed wide string handle at `+0x04`, not the separate 24-byte SSO-7 `SimpleUString` layout.
- [UID:0001W4] `SimpleUStringPointerBackedLayout` documents this one-pointer string facade and says `StringBase<wchar_t>` is the strongest helper-family spelling while `SimpleUString` remains a valid facade/alias in surrounding docs.
- `0x00582b20` decompiles to storing the wide empty-string sentinel `0x00670278` into the member.
- `0x00582d20` decompiles to release current wide storage, compute `wcslen(source)`, allocate wide storage through `0x00582e30`, and `memmove` exactly `2 * length` bytes from the source literal/buffer. B006's accepted StringBase report names this source-facing helper role `AssignWideLiteral`.
- `0x00584540`, used by the copy-out virtual, is a two-instruction accessor returning the stored data pointer.

The source expression `m_message = message` is therefore acceptable first-draft C++ for this exact constructor. It records product-level intent while letting the supporting StringBase pages own the helper mechanics.

## Literal Evidence

MCP `get_bytes 0x006195e0 size 96` decodes:

- `0x006195e0`: UTF-16 `WININET.DLL`, length `0x18` including terminator.
- `0x006195f8`: UTF-16 `General internet error`, length `0x2e` including terminator.

MCP `xrefs_to` confirms:

- `0x006195e0` is consumed at `0x004a65ad` in the constructor.
- `0x006195f8` is consumed at `0x004a65bc` in the constructor.

[UID:0003I4] `ErrorHierarchyMessageStrings` already records both literals under [UID:0000J5] `Error`.

## Rejected Alternatives

- Keep target C++ blank because of the old `95+` or strict `90/90+` language: rejected. The current active gate is cleared, and the old target rationale is stale.
- Keep target C++ blank because `SimpleUString`/`StringBase` public API spelling is unresolved: rejected for this exact child. The public facade caveat caps final class-level confidence, but the source intent is clear enough for `m_message = message`, just as other exact constructor pages now emit with inferred source-facing member names.
- Emit helper-shaped code with `sub_4F4A80`, `sub_582B20`, `sub_582D20`, `dword_69BE30`, `dword_69BE6C`, raw vtable stores, or `this + 4`: rejected as compiler/decompiler form. Use source-facing Win32 APIs and member assignment.
- Treat the `+0x04` member as the 24-byte SSO-7 `SimpleUString` object: rejected by the caller's 8-byte allocation and the `0x00582b20` one-pointer sentinel initializer.
- Move ownership to `httpget`, `MiscWorkThread`, or networking/download files: rejected. The only direct caller constructs the shared error object and posts it in a notification; implementation remains under `InternetError` / `Error.cpp`.
- Treat `0x004a6670` or `0x004a69c0` as part of this constructor: rejected by exact function boundaries and vtable-slot roles.
- Misname `0x1800` as `FORMAT_MESSAGE_IGNORE_INSERTS`: rejected by Win32 constants. It is `FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM`.

## Recommended Target Doc Changes

For [UID:0002HN] `by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md`:

1. Set `COMPLETION:90`, `CONFIDENCE:92`.
2. Keep owner/emitter metadata unchanged: `CANONICAL_OWNER:00006Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Q`.
3. Replace the stale Item Summary with the recommended summary above.
4. Insert the formal C++ block from this report.
5. Replace the blank-C++ reconstruction notes with the current source-shape decision: formal constructor source is safe; class-level helper/declaration names remain broader caveats.
6. Add 2026-06-27 B004 MCP evidence for session `80de0a67`, exact range, caller, vtable route, API dispatch slots, 255-wide fallback buffer, string helper roles, and rejected alternatives.
7. Preserve the exact half-open range and successor boundary before `0x004a6670`.

## Recommended Support-Doc Changes

Apply these only during an implementation callback with leases:

- [UID:00006Q] `by-class/InternetError.md`: update the constructor row/evidence to say [UID:0002HN] is source-ready with formal constructor C++. Keep class-level formal C++ blank until `0x004a6670`, the shared destructor/source declaration, and the `+0x0c` virtual name are standardized.
- [UID:0000J5] `by-file/Error.md`: add a support-sync note that `InternetError::InternetError()` is now exact source-ready and emits through the `InternetError` class route inside `util/Error.cpp`. Keep broader Error hierarchy C++ policies unchanged.
- [UID:00013X] `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`: update the [UID:0002HN] range row to "Exact source-ready child; emits formal constructor C++ with WinINet `FormatMessageW` fallback and pointer-backed `m_message` assignment." Keep aggregate formal C++ blank.
- [UID:0001UE] `by-type/by-struct/ErrorObjectLayouts.md`: refine the `InternetError` / `InternetConnectionError` row to state that this family uses a pointer-backed wide string handle at byte offset `+0x04`; [UID:0002HN]'s caller allocation is 8 bytes, and the constructor uses `InitializeEmptyWide` plus `AssignWideLiteral`.
- [UID:0001XI] `by-type/by-vtable/ErrorHierarchyVtables.md` and [UID:0002ND] `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`: add a score-neutral B004 support sync that the `0x00619404` constructor-store route now has source-ready exact constructor C++. Do not emit raw vtable bytes.
- [UID:0003I4] `by-memory/0x00619448-0x00619628.ErrorHierarchyMessageStrings.md`: no required score change; optionally add a support-sync note that current MCP reconfirmed `0x006195e0` and `0x006195f8` constructor xrefs while implementing [UID:0002HN].
- [UID:0000TQ] `WideApiDispatchTable`, [UID:0002RN] `StringBaseShareAssignAndAccess`, and [UID:0001W4] `SimpleUStringPointerBackedLayout`: no required edits. They already preserve the API/string-helper evidence needed by this target; cite them from the target/support pages rather than duplicating their full contents.

Do not edit generated coverage reports or generated C++ by hand. The current `by-memory/-coverage-report.md` nested row still shows the old `78%` / below-gate text for [UID:0002HN]; leave any coverage/report refresh to the supervisor-owned generated-report workflow.

## Validation Commands Needed After Implementation

Run validators only after by-* edits are actually made. From `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002HN-InternetErrorConstructor-source-quality-removed.md](0002HN-InternetErrorConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation does not edit one of the optional support docs, skip that file's validator. Release leases immediately after each edit/validator batch.

## Implementation Tracking Checklist

- [x] Lease [UID:0002HN] target doc, update metadata to `90/92`, insert the formal constructor C++ block, replace stale Item Summary/gate language, add B004 MCP proof, and validate the target.
  - Proof: edited `by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md` header metadata to `COMPLETION:90` / `CONFIDENCE:92`, preserved owner/emitter fields, inserted formal `InternetError::InternetError()` in `RECONSTRUCTION_CPP CODE`, replaced Item Summary, added `## 2026-06-27 B004 MCP Evidence`, updated reconstruction notes/score rationale/rejected alternatives/change log.
  - Validators: `python .\tools\validator.py --mode file --file by-memory\0x004a6550-0x004a666a.InternetErrorConstructor.md --apply --queue-timeout 240 --wait-generated` from `source-3/project-documentation` returned exit `0`, `command_id:000000004070`, `command_timestamp:2026-06-27T10:10:51-04:00`, `ok:1`, `generated_refresh:completed`. Earlier target proof reruns also returned exit `0` / `ok:1`: `000000004050` at `2026-06-27T08:57:03-04:00` with generated refresh completed and `000000004054` at `2026-06-27T08:57:52-04:00`.
  - Generated freshness proof: read-only check of `auto-generated/NexusTK/util/Error.cpp` shows `validator-command-id: 000000004070`, `validator-refreshed-at: 2026-06-27T10:10:51-04:00`, and UID block `// UID:0002HN` emits `InternetError::InternetError()`, `LoadLibraryW(L"WININET.DLL")`, `FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM`, and `m_message = message`.
- [x] Lease [UID:00006Q] `InternetError.md`, sync the constructor as source-ready, keep class-level formal C++ blank for the unresolved virtual/declaration work, and validate if edited.
  - Proof: edited `by-class/InternetError.md` `Important Methods`, `Ownership Notes`, `Autogen Status`, and `Changes` to state [UID:0002HN] is source-ready with formal constructor C++, while class-level `RECONSTRUCTION_CPP CODE` remains blank pending `0x004a6670`, shared destructor/declaration, string facade spelling, and `+0x0c` virtual-name work.
  - Validator: `python .\tools\validator.py --mode file --file by-class\InternetError.md --apply --queue-timeout 240` returned exit `0`, `command_id:000000004051`, `command_timestamp:2026-06-27T08:57:25-04:00`, `ok:1`, `generated_refresh:deferred`.
- [x] Lease [UID:0000J5] `Error.md`, add the source-ready `InternetError::InternetError()` support note under the shared Error hierarchy, and validate if edited.
  - Proof: edited `by-file/Error.md` `Evidence`, `Open Questions`, and `Changes` to add [UID:0002HN] as source-ready exact constructor evidence through `util/Error.cpp`, preserving the broader Error hierarchy C++ policy and unresolved `0x004a6670` / declaration caveats.
  - Validator: `python .\tools\validator.py --mode file --file by-file\Error.md --apply --queue-timeout 240` returned exit `0`, `command_id:000000004066`, `command_timestamp:2026-06-27T10:10:14-04:00`, `ok:1`, `generated_refresh:deferred`.
- [x] Lease [UID:00013X] `ErrorWrappers.md`, update the [UID:0002HN] row and aggregate evidence while keeping aggregate C++ blank, and validate if edited.
  - Proof: edited `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` Item Summary, Covered Range row, Evidence, Source-Facing Names, Formatter/Copy Behavior, Aggregate Coverage State, Score Rationale, and Changes to mark [UID:0002HN] as exact source-ready while keeping aggregate `RECONSTRUCTION_CPP CODE` blank.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x004a60d0-0x004a6a76.ErrorWrappers.md --apply --queue-timeout 240` returned exit `0`, `command_id:000000004067`, `command_timestamp:2026-06-27T10:10:21-04:00`, `ok:1`, `generated_refresh:deferred`.
- [x] Lease [UID:0001UE] `ErrorObjectLayouts.md`, add the pointer-backed 4-byte wide-string handle proof for the WinINet error wrappers, and validate if edited.
  - Proof: edited `by-type/by-struct/ErrorObjectLayouts.md` `Layout Families`, `Source-Layout Impact`, `Open Questions`, and `Changes` to record the WinINet family pointer-backed `SimpleUString` / `StringBase<wchar_t>` handle at byte offset `+0x04`, [UID:0002HN]'s 8-byte caller allocation, `InitializeEmptyWide`, `AssignWideLiteral`, and rejection of the 24-byte SSO layout for this constructor.
  - Validator: `python .\tools\validator.py --mode file --file by-type\by-struct\ErrorObjectLayouts.md --apply --queue-timeout 240` returned exit `0`, `command_id:000000004068`, `command_timestamp:2026-06-27T10:10:29-04:00`, `ok:1`, `generated_refresh:deferred`.
- [x] Lease [UID:0001XI] `ErrorHierarchyVtables.md` and [UID:0002ND] `ErrorHierarchyVtableData.md`, add score-neutral support sync for the source-ready constructor and vtable-store route, and validate if edited.
  - Proof: edited `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md` `Table Sequence`, `Constructor And Store Evidence`, `Boundary Evidence`, `Reconstruction Notes`, and `Changes` to connect the `0x00619404` constructor-store route to source-ready [UID:0002HN] without emitting raw vtable bytes. Edited `by-type/by-vtable/ErrorHierarchyVtables.md` `Common Slot Shape`, `Live IDA Recheck`, `Data Caveats`, and `Changes` with the same score-neutral support sync and kept raw vtable bytes compiler-generated.
  - Validators: `python .\tools\validator.py --mode file --file by-memory\0x00619340-0x00619448.ErrorHierarchyVtableData.md --apply --queue-timeout 240` returned exit `0`, `command_id:000000004052`, `command_timestamp:2026-06-27T08:57:32-04:00`, `ok:1`, `generated_refresh:deferred`; `python .\tools\validator.py --mode file --file by-type\by-vtable\ErrorHierarchyVtables.md --apply --queue-timeout 240` returned exit `0`, `command_id:000000004069`, `command_timestamp:2026-06-27T10:10:38-04:00`, `ok:1`, `generated_refresh:deferred`.
- [x] Optionally lease [UID:0003I4] `ErrorHierarchyMessageStrings.md` only if the implementer wants to record the current MCP xref refresh for `WININET.DLL` and `General internet error`; validate if edited.
  - Proof: edited optional `by-memory/0x00619448-0x00619628.ErrorHierarchyMessageStrings.md` Item Summary, `Evidence`, and `Changes` to record B004's current MCP refresh for `WININET.DLL` at `0x006195e0`, `General internet error` at `0x006195f8`, and constructor xrefs at `0x004a65ad` / `0x004a65bc`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x00619448-0x00619628.ErrorHierarchyMessageStrings.md --apply --queue-timeout 240` returned exit `0`, `command_id:000000004053`, `command_timestamp:2026-06-27T08:57:39-04:00`, `ok:1`, `generated_refresh:deferred`.
- [x] Do not edit `WideApiDispatchTable`, `StringBaseShareAssignAndAccess`, or `SimpleUStringPointerBackedLayout` unless validators or supervisor review require a citation sync; their current text already proves the dependencies.
  - Proof: no edits were made to `by-global/WideApiDispatchTable.md`, `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`, or `by-type/by-struct/SimpleUStringPointerBackedLayout.md`. The target and support docs cite those dependency pages instead; validator link normalizations on edited docs were validator-managed.
- [x] Do not edit generated reports, generated C++, coverage reports, validator/tool state, project-level generated files, or the IDA database.
  - Proof: no manual edits were made to generated reports, generated C++, `project-level/*`, any `-coverage-report.md`, validator/tool state, or IDA DB. Validator-owned side effects were from scoped validator commands only: projected stats updates, generated auto coverage refresh, generated metadata refresh, generated `Error.cpp` refresh, and known unrelated stale/missing registry diagnostics.
- [x] After each edit/validator batch, release any leases immediately.
  - Proof: first B004 lease batch for target/class/vtable-data/message-strings was explicitly released after validators. The interrupted support batch no longer had active B004 leases on proof-fix recheck (`tools/leaser/Agents/current_leases.md` showed only unrelated B006 leases), so no contested file was edited through an active conflict. A fresh proof-fix lease was taken only for `by-type/by-vtable/ErrorHierarchyVtables.md`, validated, then explicitly released. Final lease report check recorded no active B004 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002HN-InternetErrorConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002HN-InternetErrorConstructor-source-quality.md","timestamp":"2026-06-27T10:14:17","uid":"0002HN"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002HN-InternetErrorConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002HN-InternetErrorConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002HN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
