** TARGET-REPORT-UID:0002J7 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002J7 StringMenuItem CopyText Source-Quality Recheck

## Finalized Report / Current Recommendation

- Current assignment sequence: `B003-report-string-menu-item-copy-text-source-quality-0002J7-mcp-20260623`, accepted by supervisor, then executed under `B003-implement-string-menu-item-copy-text-source-quality-0002J7-mcp-20260623`.
- Current report state: implementation callback completed by B003. The target/support by-* docs were updated with the accepted MCP-backed evidence, scoped validators were run, and the edit leases are no longer active.
- Target: [UID:0002J7] `by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md`.
- Assignment baseline before implementation: `COMPLETION:84`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000E8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E8`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.
- Implemented disposition: target metadata is now `COMPLETION:87`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000E8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E8`, blank `EMITTER_POSITION_OPTIONAL`, with populated first-draft `RECONSTRUCTION_CPP`.
- C++ disposition: first-draft C++ is present on the target page as `errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const`. `CopyTextToWideBuffer` is preserved as a historical/generated alias and `GetText` remains rejected for this direct helper because [UID:0002J9] owns the vtable `GetText` slot at `0x0061ebc4`.
- Supervisor-owned coverage: `by-memory/-coverage-report.md` remains supervisor-owned. This report supplies exact proposed coverage text below; B003 did not edit any `-coverage-report.md` file during implementation.
- Implementation constraint status: B003 edited only the accepted target/support by-* docs plus this report. The IDA DB was not changed. Generated/project-level changes were validator-managed side effects only and are recorded below.

## Supporting Research

## Target

- Target UID: `0002J7`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00517070-0x00517089.StringMenuItemCopyText.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\0002J7-StringMenuItemCopyText-source-quality.md`.
- Direct class parent: [UID:0000E8] `StringMenuItem`.
- Source-file root: [UID:0000MN] `PopupMenuControls`.
- Relevant aggregate: [UID:0001BK] `0x00516290-0x00517441.MenuPaneAndItems`.
- Related structure/vtable docs: [UID:0001V5] `MenuItemLayouts`, [UID:0001Y4] `MenuItemVtables`.
- Neighboring method pages checked: [UID:0002J6] constructor at `0x00516ff0-0x00517070`, [UID:0002J8] metric method at `0x00517090-0x005170d0`, [UID:0002J9] vtable text-copy method at `0x005170d0-0x005170e9`, [UID:0002JA] draw method at `0x005170f0-0x005171a2`, and [UID:0002JG] scalar deleting destructor at `0x00517400-0x00517441`.

## Current Target State

- Implemented metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:92`
  - `CANONICAL_OWNER:0000E8`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000E8`
  - blank `EMITTER_POSITION_OPTIONAL`
  - populated first-draft `RECONSTRUCTION_CPP`
- The target page now records the exact source-facing role: direct non-virtual `StringMenuItem::CopyText(...)`, not a vtable slot.
- The target page now carries the MCP-backed exact function range, body bytes, `_wcscpy_s` callee, `m_text` source field at byte offset `+0x18`, `retn 8` stack contract, and eleven direct caller sites.
- The previous source-quality gap, blank C++ pending a `GetText`/`CopyText` naming pass, is resolved for first-draft C++. Original historical spelling remains inferred, so completion remains capped below final-audit territory.

## Executive Recommendation

B003 implemented the accepted recommendation: [UID:0002J7] was raised from `84/92` to `87/92`, and first-draft C++ was added on the exact method page:

```cpp
errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_text);
}
```

The source-facing behavior is no longer blocked. MCP session `b880584f` confirms the method is a 25-byte `thiscall` wrapper that returns `_wcscpy_s(destination, sizeInWords, this+0x18)` and has eleven direct code xrefs from five caller functions. The class layout page already supports `m_text[0x80]` at byte offset `+0x18`, and the neighboring constructor, metric, virtual `GetText`, and draw pages all consume the same field.

Use `CopyText` as the current best source-facing name for the direct helper. Preserve `CopyTextToWideBuffer` as a historical Wave2/generated alias because older docs restored that name, but do not treat it as stronger than current evidence: the old note used a `void` signature, while current IDA types and the instruction stream return the CRT `errno_t`. Do not name [UID:0002J7] `GetText`; [UID:0002J9] is the vtable-backed `GetText` sibling with identical copy body, no direct code callers, and data xref `0x0061ebc4 -> 0x005170d0`.

The implemented owner/emitter route remains [UID:0000E8] `StringMenuItem`, with [UID:0000MN] `PopupMenuControls` as source-file root. Caller-feature ownership remains rejected because the xrefs span FolderSelectDialog, MusicControlDialog, TerminalPane/TerminalSetup, and UserInfoDialogPane contexts. Base `MenuItem` ownership remains rejected because the method reads the `StringMenuItem` extension field at `+0x18`.

## Supervisor Active Recheck

- MCP endpoint used: `http://127.0.0.1:13337/mcp`.
- Active session used: `b880584f`.
- `idb_list` confirmed one active adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_analyzing:false`, `is_active:true`, worker PID `27504`.
- `server_health(database=b880584f)` returned `status:"ok"`, `idb_path:"E:\NTK\Resources\NexusTK\NexusTK.exe.i64"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Current MCP schema requires an explicit `database` argument on target-specific tools. A schema check was performed before evidence collection.
- The current schema exposes no separate `callers` tool. Caller evidence was collected with `func_profile(include_lists=true)`, `xrefs_to`, and bounded `insn_query` scoped to the known caller functions.
- No IDA DB mutation tools were used. No `define_func`, `idb_save`, `put_int`, rename, type-change, comment, patch, or other write operation was run.
- No fallback-only report was produced. The implemented score/C++ disposition is based on current MCP evidence plus current checked by-* docs.

## Inference Research Guidance Check

- IDA MCP was used as the primary evidence source for function boundary, decompilation, disassembly, callees, caller-equivalent xrefs, vtable data route, bytes, integer/vtable reads, and negative route checks.
- Existing by-* docs, generated coverage rows, and old Wave2/Wave3 report text were used only as leads and current-state context.
- Project `tools/int_convert.py` was used for numeric conversions: `0x19` is 25, `0x18` is 24, `0x80` is 128, `0x100` is 256, `0x118` is 280, `0x0c` is 12, and `0x08` is 8.
- MCP-returned bytes were used to compute SHA256 prefixes for the function body, successor padding, and vtable slice.
- Evidence ladder application: direct MCP function/xref/disassembly/decompilation/byte data outweighs older imported names. Current support docs are accepted where they are consistent with MCP and current source-quality decisions.

## Heuristic / Inference Reanalysis And Validation

1. Exact function range and padding.
   - MCP `lookup_funcs` returns `sub_517070`, start `0x00517070`, size `0x19`, end `0x00517089`.
   - `0x19` is 25 bytes (Verified with `int_convert.py`).
   - MCP `lookup_funcs(0x00517089)` reports no function at the end address.
   - MCP `lookup_funcs(0x00517090)` returns the next function `sub_517090`, size `0x40`.
   - MCP `lookup_funcs(0x00516ff0)` returns the predecessor constructor `sub_516FF0`, size `0x80`, ending exactly at `0x00517070`.
   - MCP `get_bytes 0x00517070 size 25` returns the exact body bytes already documented on the target page. SHA256 prefix from MCP-returned bytes: `a858cb8bb45508d2`.
   - MCP `get_bytes 0x00517089 size 7` returns seven `0xcc` bytes. SHA256 prefix: `f145eca66705de68`.
   - Best inference: [UID:0002J7] is already an exact function-sized method page. No split, merge, or boundary repair is needed.

2. Body and `_wcscpy_s` semantics.
   - MCP disassembly:

```asm
00517070  push ebp
00517071  mov  ebp, esp
00517073  lea  eax, [ecx+18h]
00517076  push eax; Source
00517077  push [ebp+SizeInWords]; SizeInWords
0051707A  push [ebp+Destination]; Destination
0051707D  call _wcscpy_s
00517082  add  esp, 0Ch
00517085  pop  ebp
00517086  retn 8
```

   - MCP decompilation:

```cpp
errno_t __thiscall sub_517070(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)
{
  return wcscpy_s(Destination, SizeInWords, this + 12);
}
```

   - The decompiler's `this + 12` is a typed `const wchar_t *` offset; the instruction stream proves byte offset `+0x18`.
   - MCP `callees(0x00517070)` reports exactly one callee, `_wcscpy_s` at `0x005cd657`.
   - MCP `func_profile` reports prototype `errno_t __thiscall(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)`, `instruction_count:10`, `basic_block_count:1`, `callee_count:1`, `string_ref_count:0`, and constants `0x0c` and `0x08`.
   - Best inference: this is a source-owned bounded wide-string copy wrapper returning the CRT `errno_t`. It is not a `void` helper despite older Wave2 wording.

3. Inline field/layout evidence.
   - MCP body uses `lea eax, [ecx+18h]`.
   - [UID:0001V5] `MenuItemLayouts` records `StringMenuItem +0x18` as an inline UTF-16 buffer of size `0x100`, `wchar_t[0x80]`.
   - `0x18` is 24 bytes, `0x80` is 128 wide characters, `0x100` is 256 bytes, and the recovered `StringMenuItem` object size is `0x118` / 280 bytes (Verified with `int_convert.py`).
   - Neighbor [UID:0002J6] constructor copies constructor input into `this+0x18` with capacity `0x80`.
   - Neighbor [UID:0002J8] metric scans the same buffer.
   - Neighbor [UID:0002J9] vtable `GetText` copies from the same buffer.
   - Neighbor [UID:0002JA] draw uses the same buffer as display text.
   - Best inference: source C++ should use `m_text`, not an IDA expression, heap pointer, caller-owned string, or ad hoc `this + 0x18` arithmetic.

4. Direct caller set.
   - MCP `func_profile(0x00517070, include_lists=true)` reports five caller functions:
     - `0x004b1920`, `sub_4B1920`
     - `0x00529790`, `sub_529790`
     - `0x0058c240`, `sub_58C240`
     - `0x00599cc0`, `sub_599CC0`
     - `0x0059b5c0`, `sub_59B5C0`
   - MCP `xrefs_to(0x00517070)` reports eleven code xrefs:
     - `0x004b19d7` in `0x004b1920-0x004b1a00`
     - `0x00529af0` in `0x00529790-0x00529b2e`
     - `0x0058c2f8` in `0x0058c240-0x0058c350`
     - `0x0059a566`, `0x0059a9dc`, `0x0059ac36`, and `0x0059aede` in `0x00599cc0-0x0059aff0`
     - `0x0059b90b`, `0x0059b9cf`, `0x0059ba8f`, and `0x0059bb4f` in `0x0059b5c0-0x0059bc2c`
   - MCP bounded `insn_query` scoped to those five caller functions finds the same eleven `call sub_517070` instructions, with no truncation.
   - Current target documentation maps those caller families to FolderSelectDialog, MusicControlDialog, TerminalPane/TerminalSetup, and UserInfoDialogPane contexts. These callers use the helper to export a selected `StringMenuItem` label into local destination buffers.
   - Best inference: this is reusable `StringMenuItem` infrastructure, not a helper owned by any one caller feature.

5. Direct helper versus vtable `GetText`.
   - MCP `get_int` over the `StringMenuItem` vtable base confirms:
     - `0x0061ebb4 -> 0x00517400`
     - `0x0061ebb8 -> 0x004f4b10`
     - `0x0061ebbc -> 0x0041b6c0`
     - `0x0061ebc0 -> 0x00517090`
     - `0x0061ebc4 -> 0x005170d0`
     - `0x0061ebc8 -> 0x005170f0`
   - MCP `xrefs_to(0x005170d0)` reports one data xref at `0x0061ebc4`, matching the vtable `GetText` slot.
   - MCP `func_profile(0x005170d0)` reports `caller_count:0`, one callee `_wcscpy_s`, and the same `errno_t __thiscall(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)` prototype as [UID:0002J7].
   - MCP disassembly/decompilation of `0x005170d0` shows an identical source operation: return `wcscpy_s(Destination, SizeInWords, this+0x18)`.
   - MCP `xrefs_to(0x00517070)` reports only code xrefs, not a vtable data xref. MCP `xrefs_to(0x0061ebc4)` reports no xrefs to the slot address itself.
   - Best inference: [UID:0002J7] is the direct non-virtual text export helper; [UID:0002J9] is the vtable-exposed `GetText` method. They share body shape but should stay distinct pages and distinct source-facing roles.

6. Method naming.
   - Current target page name and current caller docs support a concise `CopyText` role for [UID:0002J7].
   - [UID:0002J9] already carries first-draft C++ as `StringMenuItem::GetText(wchar_t *destination, size_t sizeInWords) const`; using `GetText` again for [UID:0002J7] would create an impossible duplicate same-signature member unless one name is wrong.
   - Old `by-memory/-report.old.md` and `traces_loaded.wave2_annotated.txt` preserve the generated/imported alias `StringMenuItem::CopyTextToWideBuffer`. This is useful search context but not final authority because the old signature says `void`, while current MCP proves `errno_t`.
   - Best inference: implement [UID:0002J7] as `StringMenuItem::CopyText`, retain `CopyTextToWideBuffer` as historical alias/search text, and keep `GetText` reserved for the vtable sibling.
   - Remaining uncertainty: exact original historical spelling may have been `CopyTextToWideBuffer`, `CopyText`, or another text-export variant. This uncertainty caps completion below final-audit level but does not block first-draft C++.

7. Ownership and source placement.
   - The target reads a `StringMenuItem` extension field and is adjacent to other exact `StringMenuItem` methods.
   - [UID:0000E8] `StringMenuItem` clears the B-agent route gate and is already the target owner/emitter.
   - [UID:0000MN] `PopupMenuControls` remains the source-file root for the menu-item family. Current docs preserve possible future `MenuPane.cpp`/`MenuItem.cpp` splits, but no current evidence requires moving [UID:0002J7] out of the existing class -> file route.
   - Best inference: keep `CANONICAL_OWNER:0000E8`, keep `EMITTER_UIDS:0000E8`, keep [UID:0000MN] as support/source-root context, and do not route directly to callers, `PopupMenuControls` as method owner, base `MenuItem`, or no-owner/non-emitting status.

8. First-draft C++ safety.
   - The body has one source operation, no compiler-only scaffolding, no unresolved helper API, no indirect call, no state mutation, and no source-file split blocker for this method.
   - The field name `m_text` is already accepted on surrounding `StringMenuItem` pages.
   - The destination/size names are backed by IDA stack names and CRT `_wcscpy_s` semantics.
   - The return type should be `errno_t`, matching IDA type, `_wcscpy_s`, and the existing [UID:0002J9] implementation.
   - Best inference: the current C++ gate is satisfied for a first-draft body. Completion can rise to `87`; confidence can remain `92`.

## Evidence Standards Used

- Direct IDA MCP evidence: session health, tool schema, function lookup, disassembly, decompilation, xrefs, callee list, function profile, bounded instruction query, bytes, and vtable integer reads.
- Documentation evidence: current target/support docs, neighboring exact method pages, class/file/type/vtable docs, current coverage row, and historical Wave2 notes as leads only.
- Numeric verification: `tools/int_convert.py` for small offsets, sizes, and capacities used in source-facing claims.
- Byte identity: SHA256 prefixes computed from MCP-returned byte strings, not from a stale raw PE fallback.
- C++ gate application: the target has direct class owner/emitter, reconstructable metadata, behavior above the threshold, accepted field names, and a one-line source-owned body. Remaining naming uncertainty is recorded as a completion cap, not a no-code proof.

## Evidence Checked

- Assignment and workflow:
  - `tools/leaser/Agents/Agent-B003/goal.md`
  - project-level `ntk-b-agent-workflow` skill
  - `references/b-agent-research-and-implementation-workflow.md`
  - `references/supervisor-rule26-review-and-incorporation-standard.md`
  - `by-structure.md`
  - `tools/validator_README.txt`
  - `tools/int_convert_readme.md`
- Target and support docs:
  - [UID:0002J7] `by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md`
  - [UID:0000E8] `by-class/StringMenuItem.md`
  - [UID:0000MN] `by-file/PopupMenuControls.md`
  - [UID:0001BK] `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`
  - [UID:0001V5] `by-type/by-struct/MenuItemLayouts.md`
  - [UID:0001Y4] `by-type/by-vtable/MenuItemVtables.md`
  - [UID:0002J6] `by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md`
  - [UID:0002J8] `by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md`
  - [UID:0002J9] `by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md`
  - [UID:0002JA] `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md`
  - [UID:0002JG] `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md`
- Caller/current-state docs checked where relevant:
  - [UID:000154] `FolderSelectDialog`
  - [UID:0001CP] `MusicControlDialog`
  - [UID:0001JB] `TerminalPaneAndSetup`
  - [UID:0001KG] `UserInfoDialogPane`
  - [UID:00036I] `MenuItemVtableData` through vtable support docs
- Coverage/current-state checks:
  - `by-memory/-coverage-report.md` current [UID:0002J7] row
  - `by-class/-coverage-report.md` current [UID:0000E8] row
  - `by-memory/-report.old.md` historical `StringMenuItem::CopyTextToWideBuffer` note
  - `by-memory/traces_loaded.wave2_annotated.txt` historical `StringMenuItem::CopyTextToWideBuffer` trace line
- IDA MCP checks:
  - `tools/list`: confirmed schemas and database requirement.
  - `idb_list`: confirmed active session `b880584f`.
  - `server_health`: confirmed IDB path, module, imagebase, auto-analysis, Hex-Rays, and string cache readiness.
  - `lookup_funcs`: target, end address, successor, predecessor constructor, virtual `GetText`, and destructor neighbor.
  - `func_profile`: target, virtual `GetText`, constructor, metric sibling.
  - `disasm`: target and virtual `GetText`.
  - `decompile`: target and virtual `GetText`.
  - `callees`: target.
  - `xrefs_to`: target, virtual `GetText`, `StringMenuItem` vtable base, and vtable slot address.
  - `get_bytes`: target bytes, successor padding bytes, and `StringMenuItem` vtable slice.
  - `get_int`: `StringMenuItem` vtable cells from `0x0061ebb4` through `0x0061ebc8`.
  - `insn_query`: bounded scoped caller-site checks for all five caller functions and eleven direct calls.

## IDA MCP Facts

- Session health:
  - `idb_path`: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - module: `NexusTK.exe`
  - imagebase: `0x400000`
  - `auto_analysis_ready:true`
  - `hexrays_ready:true`
  - `strings_cache_ready:true`
- Target function:
  - Address: `0x00517070`
  - IDA name: `sub_517070`
  - Size: `0x19` / 25 bytes
  - End: `0x00517089`
  - Instruction count: 10
  - Basic block count: 1
  - Prototype: `errno_t __thiscall(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)`
  - Callee count: 1
  - Callee: `_wcscpy_s` at `0x005cd657`
  - Caller functions: 5
  - Direct code xrefs: 11
  - Strings: none
- Target bytes:
  - `55 8b ec 8d 41 18 50 ff 75 0c ff 75 08 e8 d5 65 0b 00 83 c4 0c 5d c2 08 00`
  - SHA256 prefix: `a858cb8bb45508d2`
- Successor padding:
  - Range: `0x00517089-0x00517090`
  - Bytes: seven `0xcc`
  - SHA256 prefix: `f145eca66705de68`
- StringMenuItem vtable slice:
  - Bytes at `0x0061ebb4` length 28: `00 74 51 00 10 4b 4f 00 c0 b6 41 00 90 70 51 00 d0 70 51 00 f0 70 51 00 24 b7 64 00`
  - SHA256 prefix: `7f94722621532fd1`
  - Slot `+0x0c` / `0x0061ebc0` points to [UID:0002J8] `0x00517090`.
  - Slot `+0x10` / `0x0061ebc4` points to [UID:0002J9] `0x005170d0`.
  - Slot `+0x14` / `0x0061ebc8` points to [UID:0002JA] `0x005170f0`.
  - No slot points to [UID:0002J7] `0x00517070`.

## Inference Claim Ledger

| Claim | Classification | Evidence | Status |
| --- | --- | --- | --- |
| [UID:0002J7] is exact range `0x00517070-0x00517089`. | Direct MCP fact | `lookup_funcs`, body bytes, successor `lookup_funcs`, padding bytes. | Accepted. |
| Body returns `_wcscpy_s(destination, sizeInWords, this+0x18)`. | Direct MCP fact | `disasm`, `decompile`, `callees`, stack names. | Accepted. |
| Return type is `errno_t`. | Direct MCP fact plus CRT semantics | IDA prototype and [UID:0002J9] matching source body. | Accepted. |
| Field at `+0x18` is `wchar_t m_text[0x80]`. | Strong documented inference | Layout page, constructor capacity, all string-item sibling consumers. | Accepted for first-draft C++. |
| [UID:0002J7] should be `CopyText`, not `GetText`. | High-probability source inference | Direct code xrefs to [UID:0002J7], vtable `GetText` at [UID:0002J9], impossible same-signature duplicate if both named `GetText`. | Accepted as current best. |
| Historical alias `CopyTextToWideBuffer` remains useful. | Context, not authority | Old Wave2 and trace docs. | Preserve as alias/rejected final authority. |
| [UID:0002J7] is not vtable-routed. | Direct MCP fact | `xrefs_to(0x00517070)` has code refs; vtable dwords omit `0x00517070`. | Accepted. |
| [UID:0002J9] is the vtable text-copy sibling. | Direct MCP fact plus current docs | `0x0061ebc4 -> 0x005170d0`, xref to [UID:0002J9], identical body. | Accepted. |
| Owner/emitter should stay [UID:0000E8]. | Strong source-route inference | StringMenuItem field use, class page clears gate, multiple caller families. | Accepted. |
| First-draft C++ is appropriate. | B-agent source-quality recommendation | One-line body, accepted field name, no unresolved helper/API/source placement blocker. | Accepted for recommendation. |

## Ownership / Source Placement Matrix

| Candidate owner/route | Decision | Evidence |
| --- | --- | --- |
| [UID:0000E8] `StringMenuItem` owner/emitter | Keep | Direct receiver field `+0x18`, string-item sibling method cluster, class page clears route gate, all callers consume a string-menu item. |
| [UID:0000MN] `PopupMenuControls` direct file owner/emitter | Reject as direct method owner; keep as source-file root | The file owns the menu framework, but method-level ownership should route through the concrete class now that [UID:0000E8] clears the gate. |
| [UID:00007V] `MenuItem` | Reject | Base class lacks `+0x18` text buffer; vtable/base docs separate `MenuItem` from `StringMenuItem`. |
| Caller feature pages: FolderSelectDialog, MusicControlDialog, TerminalPaneAndSetup, UserInfoDialogPane | Reject | Caller set spans multiple unrelated consumers. These are use sites, not ownership. |
| [UID:0001BK] `MenuPaneAndItems` aggregate | Reject as emitting owner | Aggregate records inventory and context; exact method child and class route are narrower. |
| [UID:0002J9] `StringMenuItemGetText` / vtable slot | Reject merge | MCP shows distinct addresses and route types: [UID:0002J7] has code xrefs; [UID:0002J9] has vtable data xref. |
| No-owner/non-emitting | Reject | Direct class method, reconstructable behavior, and live caller set are all strong. |

## Source Placement

Keep source placement under the current `StringMenuItem` -> `PopupMenuControls` route. The likely source root remains [UID:0000MN] `PopupMenuControls`, with possible future `MenuItem.cpp`/`MenuPane.cpp` splitting preserved as a broader file-layout caveat. This target does not require a dedicated source-file split to add first-draft method C++ because the implementation depends only on `StringMenuItem::m_text` and CRT `wcscpy_s`.

Recommended source-facing method name:

```cpp
errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const
```

Preserve these aliases/notes in documentation:

- `StringMenuItemCopyText` as the page/file role label.
- `CopyTextToWideBuffer` as historical Wave2/generated import alias.
- `GetText` only for [UID:0002J9], the vtable-backed sibling.

## Range / Split / Padding / Reclassification Analysis

- Keep [UID:0002J7] as `0x00517070-0x00517089`.
- Do not merge with [UID:0002J6] constructor. The constructor ends exactly at `0x00517070`; no padding exists between constructor and target.
- Do not merge with [UID:0002J8] metric method. Seven `0xcc` bytes from `0x00517089` through `0x0051708f` separate target end from successor start `0x00517090`.
- Do not split the body. It is a single 10-instruction, one-basic-block wrapper.
- Do not reclassify as padding or raw helper. IDA models it as a function, direct callers target it, and it has a normal `thiscall` ABI.
- Do not reclassify as aggregate-only or non-emitting support. It is a source-authored method with a safe first-draft C++ body.

## Negative Evidence Summary

- No vtable data xref points to `0x00517070`; the vtable text-copy slot points to `0x005170d0`.
- No evidence supports naming [UID:0002J7] `GetText`; [UID:0002J9] already uses that role and slot.
- No evidence supports old Wave2 `void` return. Current MCP type and `_wcscpy_s` return flow support `errno_t`.
- No object mutation, allocation, validation, state toggle, constructor work, or destructor work occurs in the body.
- No direct ownership evidence points to any one caller feature; the direct callers span multiple UI/dialog contexts.
- No evidence supports base `MenuItem` ownership because the method reads `StringMenuItem +0x18`, outside base layout.
- No source-placement evidence requires moving this one helper to a new dedicated file or leaving it blank-C++.
- No coverage-report, IDA DB, or manual generated/project-level edit was performed by B003 during implementation.

## IDA Rename / Type / Comment Recommendations

No IDA DB rename, type, or comment work was performed during this implementation callback. If a later IDA naming/type pass is approved, the following would be consistent with this report and the implemented by-* docs:

- Rename `sub_517070` to a project-style equivalent of `StringMenuItem::CopyText`.
- Apply a type equivalent to:

```cpp
errno_t __thiscall StringMenuItem::CopyText(wchar_t *destination, rsize_t sizeInWords) const;
```

- Add a comment noting that this is the direct non-virtual label-copy helper, distinct from the vtable-backed [UID:0002J9] `GetText` slot at `0x0061ebc4`.
- Do not rename [UID:0002J7] to `GetText` unless [UID:0002J9] is also re-evaluated as a different source method.

## First-Draft C++ Disposition

B003 added first-draft C++ to the target page:

```cpp
errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_text);
}
```

Rationale:

- `errno_t` is the live IDA return type and matches `_wcscpy_s`.
- `destination` and `sizeInWords` match the CRT contract and IDA stack names.
- `m_text` is the accepted class field at `StringMenuItem +0x18`.
- `const` is appropriate because the method does not mutate the object.
- The body is plausible human-written C++ and avoids IDA-shaped pointer arithmetic.

Rejected C++ variants:

- `void CopyTextToWideBuffer(...)`: stale Wave2 signature conflicts with current MCP return evidence.
- `StringMenuItem::GetText(...)`: collides with [UID:0002J9] vtable method of the same effective signature.
- `wcscpy_s(destination, sizeInWords, this + 12)` or `(wchar_t *)((char *)this + 0x18)`: decompiler-shaped and not acceptable as source-facing C++.
- Any helper-local free function: direct callers pass a `StringMenuItem` receiver in `ecx`; the body reads a class field.

## Final Recommendation

This target has moved above `84/92`. The implemented outcome is `87/92` with first-draft C++ present, same owner/emitter metadata, same reconstructable status, and exact supporting evidence synchronized into the target/support docs.

Coverage text remains supervisor-owned. B003 did not edit `by-memory/-coverage-report.md`; the exact replacement row for supervisor application/verification is supplied below.

## Recommended Target Doc Changes

Applied to `by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md` during the accepted implementation callback:

- Metadata is now `COMPLETION:87`; `CONFIDENCE:92`, `CANONICAL_OWNER:0000E8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E8`, and blank `EMITTER_POSITION_OPTIONAL` are preserved.
- First-draft C++ block is present as `errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const`.
- The old blank-C++/source-quality gap wording is superseded by the MCP-backed source-quality result.
- The target records MCP session `b880584f`, schema/database requirement, health, function boundary, SHA256 prefix `a858cb8bb45508d2`, seven-byte `0xcc` successor padding, disassembly, decompilation, `_wcscpy_s` callee, direct xrefs, bounded caller instruction query, and vtable-sibling comparison.
- Exact caller set and caller-family evidence are preserved.
- The direct helper versus vtable `GetText` distinction is preserved.
- Rejected alternatives are preserved: `GetText` for [UID:0002J7], stale `void CopyTextToWideBuffer`, caller-feature ownership, direct file owner/emitter, base `MenuItem`, merge with [UID:0002J9], and no-owner/non-emitting.
- Score rationale explains why completion rises to 87 while confidence remains 92.

## Recommended Support Doc Changes

Applied or explicitly left unchanged during the accepted implementation callback:

- `by-class/StringMenuItem.md`:
  - Updated [UID:0002J7] method-map row to `errno_t CopyText(wchar_t *destination, size_t sizeInWords) const`.
  - Recorded that [UID:0002J7] is the direct non-virtual helper and [UID:0002J9] remains the vtable `GetText` slot.
  - Preserved `CopyTextToWideBuffer` as a historical alias, not as stronger current source proof.
  - Recorded that [UID:0002J7] is first-draft C++ ready after the MCP-backed pass.
- `by-file/PopupMenuControls.md`:
  - Added a B003 support note that [UID:0002J7] now emits first-draft `StringMenuItem::CopyText(...)` through [UID:0000E8], while this file remains the source-root grouping.
  - Did not claim a final `MenuItem.cpp`/`StringMenuItem.cpp` split from this evidence alone.
- `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`:
  - Updated the [UID:0002J7] covered-ranges role from generic "Label copy helper" to direct non-virtual `StringMenuItem::CopyText(...)` helper, first-draft C++ ready.
- `by-type/by-vtable/MenuItemVtables.md`:
  - Refined support note that [UID:0002J7] is not a vtable slot; [UID:0002J9] remains `StringMenuItem` slot `+0x10` at `0x0061ebc4`.
  - Kept score unchanged.
- `by-type/by-struct/MenuItemLayouts.md`:
  - Not edited. Existing detail was sufficient: it already records `+0x18`, `0x100`, `wchar_t[0x80]`, and [UID:0002J7]/[UID:0002J9] as copy consumers.
- Neighbor [UID:0002J9] page:
  - Not edited. Existing distinction remains sufficient: current text already says [UID:0002J7] is the directly called helper and [UID:0002J9] is vtable-exposed.
- Caller pages:
  - Not edited. The exact caller set is centralized in the exact [UID:0002J7] target page.

## Score And Metadata Recommendation

- Implemented target metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:92`
  - `CANONICAL_OWNER:0000E8`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000E8`
  - blank `EMITTER_POSITION_OPTIONAL`
  - populated `RECONSTRUCTION_CPP`
- Why completion rises:
  - MCP-backed exact function boundary and bytes are current.
  - The direct caller set is current and complete for IDA-visible code xrefs.
  - The direct-helper versus vtable `GetText` split is now explicit.
  - `m_text[0x80]` is accepted by surrounding docs.
  - First-draft C++ is safe and source-shaped.
- Why completion stays below final-audit level:
  - Exact original source spelling is still inferred. `CopyText` is best current source-facing name, while `CopyTextToWideBuffer` remains a historical alias.
  - The exact public/private declaration location in an original header is not recovered.
  - Broader file splitting between `PopupMenuControls.cpp`, `MenuItem.cpp`, and class-specific files remains a source-layout caveat for the family.
- Why confidence stays `92`:
  - Behavior, range, caller set, field offset, callee, and route are very strong.
  - Remaining uncertainty is source spelling/header placement, not behavior or ownership.

## Open Questions With Attempted Resolution

- Was the original source name exactly `CopyText` or `CopyTextToWideBuffer`?
  - Evidence checked: current target path, class/caller docs, Wave2 historical report, trace annotation, direct-vs-virtual sibling evidence.
  - Resolution: use `CopyText` for first-draft source because it is plausible, concise, already appears in current caller/class documentation, and avoids the generated-looking `CopyTextToWideBuffer`. Preserve `CopyTextToWideBuffer` as an alias because historical tooling used it.
  - Score/C++ impact: does not block first-draft C++; caps completion below final.
- Is [UID:0002J7] actually another `GetText` entry?
  - Evidence checked: vtable dwords, `xrefs_to` for `0x00517070` and `0x005170d0`, [UID:0002J9] page.
  - Resolution: no. [UID:0002J9] is the vtable `GetText` slot; [UID:0002J7] is direct code-call helper.
  - Score/C++ impact: supports `CopyText` naming and first-draft C++.
- Should support docs be edited broadly?
  - Evidence checked: class/file/aggregate/type/vtable docs.
  - Resolution: target, class, file, aggregate, and vtable notes were synchronized during implementation. Layout and neighbor `GetText` already carry sufficient detail and were left unchanged.
  - Score/C++ impact: no blocker.

## Exact Supervisor-Owned Coverage Text

Supervisor-owned replacement row for `by-memory/-coverage-report.md` after implementation verification:

```markdown
        - [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) 0x00517070-0x00517089 | method | StringMenuItemCopyText : reconstructable : 87% : very strong : B003 2026-06-23 MCP-backed source-quality recheck resolves the direct non-virtual StringMenuItem label-copy helper as first-draft C++ ready: session b880584f confirms exact 0x19 / 25-byte boundary (Verified with int_convert.py), SHA256 prefix a858cb8bb45508d2, seven-byte 0xcc successor padding 0x00517089-0x00517090, one _wcscpy_s callee, inline m_text[0x80] at +0x18 / 24 bytes (Verified with int_convert.py), errno_t return/retn 8 stack contract, eleven direct FolderSelect/Music/Terminal/UserInfo code xrefs, no vtable data xref for 0x00517070, and distinct vtable-backed sibling [UID:0002J9] at 0x0061ebc4; source should use StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const with CopyTextToWideBuffer retained as a historical alias, reject GetText for this direct helper because slot +0x10 already owns that role, and emit through [UID:0000E8] -> [UID:0000MN].
```

No class/file/type coverage row change is required by this report. If the supervisor wants a class coverage refresh, it remains supervisor-owned and can mention [UID:0002J7] now joins constructor/metric/get-text/draw as first-draft source-ready exact child coverage.

## Follow-Up Actions

- Supervisor should verify the implemented target/support docs against this checklist, apply or decline the supervisor-owned coverage row, and then move this report to `research/executed/` if verification passes.
- No accepted B003 by-* edit remains pending for this callback.
- B003 did not edit any `-coverage-report.md` file. Use the coverage text above for supervisor-owned application.
- No MCP confirmation was needed during implementation because the accepted report already supplied the MCP-backed evidence. If a future MCP-dependent check is requested and MCP fails, B003 should stop with `PAUSED_MCP_UNAVAILABLE` rather than using fallback-only evidence.

## Confidence

High confidence for behavior, range, ownership, route, and first-draft C++ body. The only meaningful residual uncertainty is original source spelling and original header/source file declaration placement. That uncertainty is reflected in the implemented `87/92` score rather than a higher final-audit score.

## Validator Results

- Scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` after by-* implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002J7-StringMenuItemCopyText-source-quality-removed.md](0002J7-StringMenuItemCopyText-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Results:
  - `by-memory\0x00517070-0x00517089.StringMenuItemCopyText.md`: exit code `0`, `ok: 1`.
  - `by-class\StringMenuItem.md`: exit code `0`, `ok: 1`.
  - `by-file\PopupMenuControls.md`: exit code `0`, `ok: 1`.
  - `by-memory\0x00516290-0x00517441.MenuPaneAndItems.md`: exit code `0`, `ok: 1`.
  - `by-type\by-vtable\MenuItemVtables.md`: exit code `0`, `ok: 1`.
- Validator side effects/warnings recorded:
  - Target validator initially updated `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
  - Rerun output for each scoped validator retained `projected_stats_update` for `project-level/-auto-completion-stats.md`.
  - Rerun output retained unrelated `autogen_registry_stale` warnings for missing registered files `0003E6` and `00026U`.
  - Rerun output retained unrelated `autogen_cpp_conflict` warnings for existing non-sentinel files `auto-generated/NexusTK/render/FontImageLib.cpp`, `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp`, `auto-generated/NexusTK/login/HistoryViewingPane.cpp`, `auto-generated/NexusTK/ui/panels/HourPane.cpp`, and `auto-generated/NexusTK/input/IMEPanes.cpp`.
  - Rerun output reported `autogen_report_noop` for the `auto-generated/-ag-*` reports.
- `by-type\by-struct\MenuItemLayouts.md` was not edited, so its optional scoped validator was not run.

## Changed Files

- B003 edited these accepted by-* docs:
  - `by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md`
  - `by-class/StringMenuItem.md`
  - `by-file/PopupMenuControls.md`
  - `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`
  - `by-type/by-vtable/MenuItemVtables.md`
- B003 updated this report checklist:
  - `tools/leaser/Agents/Agent-B003/research/0002J7-StringMenuItemCopyText-source-quality.md`
- Validator-managed side effects occurred in:
  - `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Lease/tool-state files were touched by lease/unlease and validator queue operations:
  - `tools/leaser/lease.json`
  - `tools/leaser/Agents/current_leases.md`
  - `tools/validator_queue` runtime files
- B003 did not manually edit generated/project-level files.
- B003 did not edit any `-coverage-report.md` file.
- B003 did not edit the IDA DB.

## Implementation Tracking Checklist

- [x] Target metadata: updated [UID:0002J7] `by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md` from `84/92` to `87/92`; owner/emitter/reconstructable fields remain unchanged. Proof: target metadata block plus validator `by-memory\0x00517070-0x00517089.StringMenuItemCopyText.md`, exit `0`, `ok: 1`.
- [x] Target C++: added first-draft `errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const` body. Proof: target `RECONSTRUCTION_CPP` block plus validator `by-memory\0x00517070-0x00517089.StringMenuItemCopyText.md`, exit `0`, `ok: 1`.
- [x] Target evidence: incorporated MCP session `b880584f` facts for health, schema/database requirement, `lookup_funcs`, `func_profile`, `disasm`, `decompile`, `callees`, `xrefs_to`, `get_bytes`, `get_int`, and bounded `insn_query`. Proof: target `MCP Evidence`, `Caller Use`, `Direct Helper Versus Vtable GetText`, `Range / Split / Padding`, and `Score Rationale` sections plus validator exit `0`, `ok: 1`.
- [x] Target naming/rationale: preserved `CopyTextToWideBuffer` as historical alias, rejected stale `void` return, rejected `GetText` for [UID:0002J7], and distinguished [UID:0002J9] vtable slot. Proof: target status/reconstruction/negative-evidence sections plus validator exit `0`, `ok: 1`.
- [x] Target ownership/source route: kept [UID:0000E8] owner/emitter and [UID:0000MN] source-file root; rejected caller-feature, base `MenuItem`, aggregate, merge, and no-owner routes. Proof: target ownership/source-placement/score sections plus validator exit `0`, `ok: 1`.
- [x] Support doc `by-class/StringMenuItem.md`: updated method map/support note for [UID:0002J7] as direct non-virtual `CopyText(...)`, first-draft C++ ready, distinct from vtable [UID:0002J9] `GetText`; retained historical alias. Proof: `B003 CopyText Source-Quality Resolution` section and validator `by-class\StringMenuItem.md`, exit `0`, `ok: 1`.
- [x] Support doc `by-file/PopupMenuControls.md`: added B003 support note that [UID:0002J7] now emits first-draft `StringMenuItem::CopyText(...)` through [UID:0000E8], with file root unchanged and no forced split. Proof: support/source-root note and validator `by-file\PopupMenuControls.md`, exit `0`, `ok: 1`.
- [x] Support doc `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`: updated [UID:0002J7] inventory row/notes to direct non-virtual `CopyText(...)` helper, first-draft C++ ready. Proof: covered-ranges row/evidence note and validator `by-memory\0x00516290-0x00517441.MenuPaneAndItems.md`, exit `0`, `ok: 1`.
- [x] Support doc `by-type/by-vtable/MenuItemVtables.md`: refined note that [UID:0002J7] is not in the vtable, while [UID:0002J9] remains `StringMenuItem` slot `+0x10` at `0x0061ebc4`. Proof: slot-map support text and validator `by-type\by-vtable\MenuItemVtables.md`, exit `0`, `ok: 1`.
- [x] Support doc `by-type/by-struct/MenuItemLayouts.md`: not edited because existing detail already records `+0x18`, `0x100`, `wchar_t[0x80]`, and [UID:0002J7]/[UID:0002J9] copy use. Proof: accepted not-applicable decision; no validator required because the file was not changed.
- [x] Neighbor [UID:0002J9]: not edited because existing page already documents the vtable/direct-helper distinction and first-draft `GetText` C++. Proof: accepted not-applicable decision; no validator required because the file was not changed.
- [x] Caller pages: not edited because exact caller set is centralized in [UID:0002J7]. Proof: accepted not-applicable decision; no validator required because no caller page was changed.
- [x] Coverage: no `-coverage-report.md` file edited by B003. Proof: exact by-memory replacement row remains in this report for supervisor-owned application.
- [x] Validators after accepted implementation: ran all five scoped validator commands listed above; each returned exit code `0` and `ok: 1`. Proof: validator results section records commands, exit codes, ok counts, warnings, and side effects.
- [x] Lease discipline after accepted implementation: checked `current_leases.md` before editing and found no active leases; leased the five exact target/support docs immediately before editing with `Success` for each path; after the edit/scoped-validator batch, unlease reported `Rejected[No active lease]` for each path because the leases had already expired, and `current_leases.md` showed no active leases. Proof: final lease state has no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002J7-StringMenuItemCopyText-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0002J7"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002J7-StringMenuItemCopyText-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002J7-StringMenuItemCopyText-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002J7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
