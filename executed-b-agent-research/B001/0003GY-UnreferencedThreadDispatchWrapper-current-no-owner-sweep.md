** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# 0003GY UnreferencedThreadDispatchWrapper Current No-Owner Sweep

## Final Recommendation

Keep [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](../../../../../by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) unchanged:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- blank `EMITTER_UIDS`
- blank `RECONSTRUCTION_CPP`
- current target score remains defensible at `86/86`

This is still real NexusTK executable code, not padding or runtime filesystem glue, but the current evidence does not prove a direct semantic owner or any source-output route. The function has no inbound IDA xrefs, no raw VA/RVA pointer hits, no caller table evidence, and no source-use context. Its only behavior is to forward two stack arguments plus literal zero to the generic Thread async post helper at `0x00596960`.

No by-memory target edit, no split, no merge, no reclassification, and no `by-memory/-coverage-report.md` edit is required. If a supervisor touches the shared report, keep the existing row text listed below.

## Target And Scope

- Assignment: current Goal 2 no-owner memory sweep, one target only.
- UID/path: `0003GY`, `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`.
- Current generated row: `auto-generated/-ag-memory-coverage.md` still lists this item as `no-owner`, owner `` `NONE` ``, and blank emitter fields.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, section `Active 2026-06-14 Remaining No-Owner Memory Sweep`, assigns `0003GY` to Agent-B001.
- Prior report reviewed as background only: `Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-current-goal2-pass.md`.

## Evidence Standards Applied

I used the current owner/emitter model in `by-structure.md`:

- `CANONICAL_OWNER` is the direct semantic owner, not the nearest file or a convenient output parent.
- `EMITTER_UIDS` are output routes, not ownership. A reconstructable page can remain non-emitting when no route is proven.
- `CANONICAL_OWNER:NONE` with emitters can be right for shared literals/data, but this target is code with no proven source-use route.
- `RECONSTRUCTABLE:TRUE` remains appropriate for real source-authored code even when owner and emitter are not ready.
- C++ reconstruction remains blank because the target is below the active `90/90+` code-entry gate and has no proven owner/emitter route.

I also applied the inference guidance that source ownership cannot be inferred from address adjacency alone. The wrapper sits in a FileDownloader neighborhood, and it calls a Thread helper, but neither fact by itself clears the direct-owner gate.

## Current Documentation Evidence

Current target header:

```text
UID:0003GY
COMPLETION:86
CONFIDENCE:86
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP blank
```

Current target body already records the central facts: a 20-byte wrapper preserves `ecx`, pushes literal zero as the third dispatch argument, forwards the two stack arguments to `0x00596960`, and returns with `retn 8`. It also states that Thread is the best forced semantic candidate, but no callers, vtable/data references, receiver type, or class-specific fields prove a direct owner.

The surrounding aggregate [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](../../../../../by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md) treats this span as an exact child inside a mixed address inventory. It explicitly keeps the aggregate non-reconstructable and parent-blank after splitting children, and notes that `0003GY` is real unreferenced code whose parent remains blank.

The generic callee is documented under [UID:0000OR][Thread](../../../../../by-file/Thread.md), [UID:0000EV][Thread](../../../../../by-class/Thread.md), and [UID:0001JX][0x00596250-0x0059756e.ThreadAndThreadMan](../../../../../by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md) as the base Thread async queue-post primitive. That supports the callee's ownership, not the wrapper's declaration owner.

The adjacent pages still have stronger owner evidence than this wrapper:

- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](../../../../../by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) has a known FittingRoom caller and a FileDownloader singleton receiver route.
- [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](../../../../../by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) has a constructor-unwind xref and a direct `dword_67A738` write.
- `0003GY` has neither kind of inbound relation.

## Live IDA MCP Evidence

IDA MCP endpoint was healthy during this pass.

```text
database: b001_0003gy
module: NexusTK.exe
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
```

Function boundary and neighborhood facts:

- `lookup_funcs 0x0041b2d0`: function start `0x41b2d0`, current IDA name `___std_fs_create_symbolic_link@8`, size `0x14`.
- `lookup_funcs 0x0041b2c9`: not a function, matching the preceding padding boundary.
- `lookup_funcs 0x0041b2e4`: not a function, matching the following padding boundary.
- `lookup_funcs 0x0041b2f0`: `sub_41B2F0`, size `0x0b`, the adjacent FileDownloader global-clear helper.
- Function listing for `0x0041a600-0x0041b700` shows the expected FileDownloader functions through `0x0041b270`, then `0x0041b2d0`, `0x0041b2f0`, string/JsonCpp/CashShop helpers, and later Thread no-op virtuals. This confirms the wrapper is a distinct modeled function, not an interior chunk of the neighboring functions.

Disassembly of `0x0041b2d0`:

```asm
0041b2d0  push ebp
0041b2d1  mov  ebp, esp
0041b2d3  push 0
0041b2d5  push [ebp+arg_4]
0041b2d8  push [ebp+arg_0]
0041b2db  call sub_596960
0041b2e0  pop  ebp
0041b2e1  retn 8
```

Hex-Rays decompile:

```c
BOOL __thiscall __std_fs_create_symbolic_link(HANDLE *this, int a2, int a3)
{
  return sub_596960(this, a2, a3, 0);
}
```

The decompiler's return type and `HANDLE *` argument are label/type pollution from the current IDA name. The machine code itself is simply a `thiscall` forwarding wrapper over the Thread post helper.

Xrefs:

- `xrefs_to 0x0041b2d0`: zero.
- `xrefs_to 0x0041b2e4`: zero.
- `xrefs_to 0x0041b2f0`: one code xref from the FileDownloader constructor unwind block at `0x005f670e`.
- `xrefs_to 0x0041b270`: one code xref at `0x0041c21b`.
- `xrefs_to 0x00596960`: 22 code xrefs from downloader submit helpers, MiscWorkThread, socket/packet-send wrappers, and this wrapper. The broad callee fan-in confirms generic Thread queue-post behavior; it does not prove this unreferenced wrapper's owner.

Callees:

- `callees 0x0041b2d0`: only `sub_596960`.
- `callees 0x00596960`: `sub_556580` and imported `ReleaseSemaphore`.

Decompile/disassembly of `0x00596960`:

- It builds a six-dword stack record from the three supplied arguments plus three zero dwords.
- It obtains the queue from `this+0x4c`, calls the queue insertion helper `sub_556580`, then calls `ReleaseSemaphore(this+0x0c, 1, 0)`.
- This matches the Thread docs' generic async queue-post primitive.

## PE And Raw Byte Evidence

Raw executable scanned: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

```text
ImageBase: 0x00400000
.text VA: 0x00401000
.text RVA: 0x00001000
.text raw pointer: 0x400
Target VA: 0x0041B2D0
Target RVA: 0x0001B2D0
Target raw offset: 0x1A6D0
```

Raw bytes:

```text
before 0x0041b2d0: CC CC CC CC CC CC CC
target body:        55 8B EC 6A 00 FF 75 0C FF 75 08 E8 80 B6 17 00 5D C2 08 00
after 0x0041b2e4:  CC CC CC CC CC CC CC CC CC CC CC CC
```

Raw/IDA byte searches:

- Exact target body occurs once, at `0x0041b2d0` / raw offset `0x1A6D0`.
- The direct call encoding `E8 80 B6 17 00` occurs once, at `0x0041b2db`.
- Raw PE scan found zero little-endian VA pointer hits for `0x0041b2d0` (`D0 B2 41 00`).
- Raw PE scan found zero little-endian RVA pointer hits for `0x0001b2d0` (`D0 B2 01 00`).
- Raw PE scan found zero `push 0x0041b2d0` patterns (`68 D0 B2 41 00`).

## Stale IDA Name Check

The current IDA name `___std_fs_create_symbolic_link@8` is not supported as a semantic name for this target.

- Import query for `Symbolic`, `HardLink`, `FileLink`, `Symlink`, and `CreateSymbolic` returned no matching imports.
- IDA has another unreferenced function named `___std_fs_create_symbolic_link@8_0` at `0x0058ea60`.
- `0x0058ea60` has the same tiny wrapper shape, but calls `sub_58F690` instead of `sub_596960`.
- `xrefs_to 0x0058ea60`: zero.

This duplication supports a stale/generated/borrowed IDA label pattern, not a real filesystem API identity for `0003GY`. A safe IDA hygiene rename would be something like `UnreferencedThreadDispatchWrapper_41B2D0`, but this is optional and not required for the documentation state.

## Function And Child Inventory

This target should remain a single exact function page:

| Range | Current role | Decision |
| --- | --- | --- |
| `0x0041b2c9-0x0041b2d0` | `0xcc` padding after `0x0041b270` | Already ignored; no action. |
| `0x0041b2d0-0x0041b2e4` | unreferenced wrapper forwarding to `0x00596960` | Keep as `0003GY`, reconstructable, no owner, no emitters. |
| `0x0041b2e4-0x0041b2f0` | `0xcc` padding before `0x0041b2f0` | Already ignored; no action. |

No child split is warranted. The body is only eight instructions, one function, and one behavior. No merge is warranted with the FileDownloader aggregate, Thread aggregate, or the duplicate wrapper at `0x0058ea60`, because those pages either have different source ownership evidence or different helper targets.

## Owner And Emitter Alternatives Rejected

1. `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` - accepted.
   - Positive evidence: real function bytes, exact boundary, generic Thread queue-post behavior.
   - Negative owner evidence: zero inbound xrefs, zero pointer/immediate hits, no vtable/table slot, no receiver-origin route, no source-use context.
   - Negative emitter evidence: no caller or source-use route can justify adding this function to a generated output file.

2. Owner/emitter [UID:0000OR][Thread].
   - Why considered: target calls the generic Thread async post helper `0x00596960`.
   - Why rejected: calling a Thread helper proves the callee abstraction, not the wrapper declaration owner. The wrapper is outside the Thread island and has no xref from Thread code, vtable slot, or class layout evidence.

3. Owner/emitter [UID:0000JC][FileDownloader].
   - Why considered: target is physically between FileDownloader submit helper `0x0041b270` and FileDownloader constructor-unwind helper `0x0041b2f0`.
   - Why rejected: adjacency is weak evidence. The adjacent helpers have proven FileDownloader caller/global-unwind relations; `0003GY` has none. It is also separated by `0xcc` padding on both sides.

4. Owner/emitter [UID:0000I1][CashShopVersionRequest] or [UID:00001I][CashShopVersionRequest].
   - Why considered: immediately follows the version request submit helper.
   - Why rejected: no payload vtable, no version request fields, no caller from version-request code, and no xref from the dispatcher.

5. Runtime/CRT/STL filesystem helper or ignored library artifact.
   - Why considered: stale IDA name contains `std_fs_create_symbolic_link`.
   - Why rejected: behavior calls NexusTK Thread queue helper, not a filesystem import or CRT filesystem implementation. No matching import was found, and the duplicate stale label at `0x0058ea60` shows the name is unreliable.

## Required Edits

No direct edits are required to the target page, generated reports, or shared `by-memory/-coverage-report.md`.

Recommended target metadata to keep:

```text
*** UID:0003GY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended generated memory coverage state to keep:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |
```

Recommended shared `by-memory/-coverage-report.md` row to keep if supervisor reapplies shared text:

```text
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Real unreferenced queue wrapper that forwards two arguments plus zero to generic Thread dispatch helper `0x00596960`; B003 second-pass review kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS` because no caller/vtable/source-island, raw pointer, branch, import/IAT relation, or source-use context proves the direct owner or output route, and the stale symbolic-link IDA name is not supported by wrapper behavior.
```

Optional supervisor tracker update after accepting this fresh report:

```text
| `0003GY` | 0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` | Agent-B001 | 2026-06-14 | complete-no-change | `Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-current-no-owner-sweep.md` | `Agent-B001/research/executed/0003GY-UnreferencedThreadDispatchWrapper-current-goal2-pass.md` |
```

## Validation And Lease State

- Changed files: this report only.
- By-memory/by-file/by-class documentation changed: none.
- `by-memory/-coverage-report.md` changed directly: no.
- Validator: not run, because no validator-managed by-* documentation was changed. No dry run was used.
- Lease: created this new report placeholder, then leased the report path as Agent-B001 before writing the final report body. Lease released after final file verification.

## Confidence

Recommendation confidence: `90` for keeping owner and emitter blank. The negative evidence is current and redundant: live IDA xrefs, current raw PE pointer scans, exact bytes, function boundaries, and current docs all point the same way. I do not recommend raising the target page above `86/86` in this assignment because the original source declaration, intended source name, and reason the wrapper survived unused remain unknown.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-current-no-owner-sweep.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
