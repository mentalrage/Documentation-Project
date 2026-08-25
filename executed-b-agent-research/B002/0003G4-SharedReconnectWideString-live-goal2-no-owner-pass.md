** TARGET-REPORT-UID:0003G4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G4 **
# Final Recommendation

Keep [UID:0003G4] `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md` unchanged.

- Final state: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N0,0000OI`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.
- Ownership decision: no canonical declaration owner is defensible. The literal is a pooled/shared UTF-16 button label used by both the ReconnectDialog/ConnectionClosedDialog source route and the TerminalPane source route.
- Emitter decision: keep both emitters. [UID:0000N0] `ReconnectDialog` is proven by three direct use sites, and [UID:0000OI] `TerminalPane` is proven by one direct use site. This is a valid no-owner/multiple-emitter output-routing case under the current system.
- Required edits: none to the target page, sibling pages, generated coverage, or `by-memory/-coverage-report.md`.
- Split/reclass decision: no split, merge, child-page creation, IDA repair, or reclassification is justified. The interior `aConnect`/`connect` suffix and the later `kServerReconnect` suffix have no direct references.
- Score/C++ decision: keep `89/94`. Although the item is reconstructable and has valid emitters, this pass should not add standalone C++; final reconstruction should place `L"Reconnect"` at each proven semantic use site unless later source evidence proves a named shared declaration.
- Confidence: high.

---

## Target And Scope

- Agent: `Agent-B002`.
- Assignment: live Goal 2 B-agent no-owner memory pass.
- Target UID: `0003G4`.
- Target path: `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`.
- Target range: `0x00622f28-0x00622f3c`.
- Current generated state from assignment and target page: `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000N0,0000OI`, `RECONSTRUCTABLE:TRUE`.
- Final report path: `tools/leaser/Agents/Agent-B002/research/0003G4-SharedReconnectWideString-live-goal2-no-owner-pass.md`.
- Prior report reviewed as evidence only: `tools/leaser/Agents/Agent-B002/research/executed/0003G4-SharedReconnectWideString-fresh-no-owner-pass.md`.

No lease was used because this pass creates only this Agent-B002 research report and does not edit any non-agent by-* file.

Current target header checked in the live docs:

```text
*** UID:0003G4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0,0000OI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Current Documentation Context

The current `by-structure.md` model separates declaration ownership from output routing:

- `CANONICAL_OWNER` requires a defensible semantic source/declaration owner.
- `EMITTER_UIDS` routes generated output and may contain multiple proven source-use emitters.
- `CANONICAL_OWNER:NONE` is valid for pooled/shared data where no single source root owns the declaration.
- Do not invent a shared source root solely to remove `NONE`.
- `RECONSTRUCTABLE:TRUE` does not require a canonical owner when the safe reconstruction is source-use placement rather than a unique shared declaration.

The containing map [UID:0003CW] `ReconnectTerminalCopyStringTailMap` is a mixed literal tail map, not a source-level owner. Its exact children are:

```text
0003G3 0x00622f1c-0x00622f28 SharedLeaveWideString        NONE, emitters 0000N0,0000OI
0003G4 0x00622f28-0x00622f3c SharedReconnectWideString    NONE, emitters 0000N0,0000OI
0003G5 0x00622f3c-0x00622f44 CopyWindowNoButtonWideString owner/emitter 000039
0003G6 0x00622f44-0x00622f4c CopyWindowYesButtonWideString owner/emitter 000039
0003G7 0x00622f4c-0x00622f54 SharedBaramPacketLiteral     NONE, emitters 0000N0,0000OI
```

That parent confirms the range is a compiler/linker-adjacent data island with mixed ownership, not a single reconstructable C++ declaration block.

## Live IDA MCP Evidence

IDA MCP session used:

```text
session_id: a001_goal2_class_batch
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
```

Target bytes from current `get_bytes`:

```text
0x00622f28:
52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00

Decoded as UTF-16LE:
"Reconnect"
```

Containing data bytes from `0x00622f1c` show neighboring literals are separate entries:

```text
0x00622f1c: 4c 00 65 00 61 00 76 00 65 00 00 00             UTF-16LE "Leave"
0x00622f28: 52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00  UTF-16LE "Reconnect"
0x00622f3c: 4e 00 6f 00 00 00 00 00                         UTF-16LE "No" plus alignment
0x00622f44: 59 00 65 00 73 00 00 00                         UTF-16LE "Yes"
0x00622f4c: 62 61 72 61 6d 00 00 00                         ANSI "baram" plus alignment
```

Direct xrefs to `0x00622f28`:

| Target | Xref | Function | Interpretation |
| --- | --- | --- | --- |
| `0x00622f28` | `0x00553c44` | `sub_553C10` | `ConnectionClosedDialog` constructor variant passes the reconnect label. |
| `0x00622f28` | `0x00553cf4` | `sub_553CC0` | Alternate `ConnectionClosedDialog` constructor path passes the reconnect label. |
| `0x00622f28` | `0x0055435e` | `sub_554210` | `ReconnectDialog` button path constructs a replacement connection-closed prompt. |
| `0x00622f28` | `0x0058b5b1` | `sub_58B470` | `TerminalPane::OnDisconnect` constructs the reconnect/leave prompt. |

Paired `Leave` refs match the same four use sites:

```text
0x00622f1c <- 0x00553c3f in sub_553C10
0x00622f1c <- 0x00553cef in sub_553CC0
0x00622f1c <- 0x00554359 in sub_554210
0x00622f1c <- 0x0058b5ac in sub_58B470
```

Negative xref checks:

```text
xrefs_to 0x00622f2c: 0
xrefs_to 0x00622f30: 0
xrefs_to 0x00622f34: 0
xrefs_to 0x00622f38: 0
xrefs_to 0x006288a2: 0
xrefs_to 0x006288b0: 0
xrefs_to 0x00622f54: 0
```

The no-xref result for `0x00622f2c` rejects splitting the target at the IDA suffix name `aConnect`/`connect`; that suffix is a string-pooling artifact, not an independently referenced child.

## Use-Site Evidence

IDA disassembly around the `ReconnectDialog`/`ConnectionClosedDialog` paths:

```text
sub_553C10:
553c3f: push offset off_622F1C
553c44: push offset off_622F28
553c49: push dword_67A740
553c4f: push 9Ah
553c5c: call sub_49FEB0

sub_553CC0:
553cef: push offset off_622F1C
553cf4: push offset off_622F28
553cf9: push [ebp+arg_0]
553cfc: push 9Ah
553d09: call sub_49FEB0

sub_554210:
554359: push offset off_622F1C
55435e: push offset off_622F28
554363: push dword_67A740
554369: push 9Ah
554376: call sub_49FEB0
```

Hex-Rays currently renders the same three ReconnectDialog/ConnectionClosedDialog paths as:

```text
sub_49FEB0(v2, v4, &off_622F28, &off_622F1C);   /*0x553c5c*/
sub_49FEB0(v3, a2, &off_622F28, &off_622F1C);   /*0x553d09*/
sub_49FEB0(v8, v11, &off_622F28, &off_622F1C);  /*0x554376*/
```

IDA disassembly around the TerminalPane path:

```text
sub_58B470:
58b5ac: push offset off_622F1C
58b5b1: push offset off_622F28
58b5b6: push esi
58b5b7: push ebx
58b5c2: push eax
58b5c3: mov ecx, edi
58b5c5: call sub_4A0690
```

Hex-Rays currently renders that TerminalPane prompt path as:

```text
sub_4A0690(v11, v5, v10, &off_622F28, &off_622F1C); /*0x58b5c5*/
```

`analyze_component` over `0x00553c10`, `0x00553cc0`, `0x00554210`, `0x0058b470`, `0x0049feb0`, and `0x004a0690` reports:

```text
sub_553C10 callees include sub_49FEB0 and sub_4F0350.
sub_553CC0 callees include sub_49FEB0 and sub_4F0350.
sub_554210 callees include sub_553CC0, sub_49FEB0, sub_4F0350, and also uses string "baram".
sub_58B470 callees include sub_4A0690, sub_49FEB0, sub_4F0350, and TerminalPane callback construction.
sub_4A0690 is a short wrapper/caller into sub_49FEB0.
shared_globals includes off_622F1C and off_622F28 accessed by sub_553C10, sub_553CC0, sub_554210, and sub_58B470.
```

This supports the current emitter split: the same label pair is shared by the ReconnectDialog/ConnectionClosedDialog route and the TerminalPane route.

## Raw PE Verification

Raw executable checked:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5: 4247e04e20b65d6414c7238aa8ff5515
imagebase: 0x400000
```

Relevant section mapping:

```text
.text  RVA 0x1000-0x20c600 raw 0x400-0x20ba00
.rdata RVA 0x20d000-0x26c200 raw 0x20ba00-0x26ac00
.data  RVA 0x26d000-0x27a800 raw 0x26ac00-0x278400
.rsrc  RVA 0x29d000-0x2b2e00 raw 0x278400-0x28e200
```

Target mapping:

```text
VA 0x00622f28 -> raw 0x221928
```

PE pattern results:

```text
UTF-16LE "Reconnect\0":
  raw 0x221928 -> VA 0x00622f28
  raw 0x2272b0 -> VA 0x006288b0

UTF-16LE "kServerReconnect\0":
  raw 0x2272a2 -> VA 0x006288a2

push 0x00622f28:
  raw 0x153044 -> VA 0x00553c44
  raw 0x1530f4 -> VA 0x00553cf4
  raw 0x15375e -> VA 0x0055435e
  raw 0x18a9b1 -> VA 0x0058b5b1

dword 0x00622f28:
  raw 0x153045 -> VA 0x00553c45
  raw 0x1530f5 -> VA 0x00553cf5
  raw 0x15375f -> VA 0x0055435f
  raw 0x18a9b2 -> VA 0x0058b5b2

dword RVA 0x00222f28: 0 hits
dword 0x00622f2c: 0 hits
dword 0x006288a2: 0 hits
dword 0x006288b0: 0 hits
ASCII "Reconnect\0": 0 hits
```

The second raw UTF-16 `Reconnect` spelling at `0x006288b0` is the suffix of the unreferenced UTF-16 `kServerReconnect` literal at `0x006288a2`. It is outside this target and has no absolute references in the executable scan or IDA xref checks.

## Candidate Owner And Emitter Analysis

[UID:0000N0] `ReconnectDialog`:

- Accepted as an emitter.
- Current docs route `ReconnectDialog.cpp` / `ConnectionClosedDialog` reconstruction through this file root.
- IDA proves three direct uses of `off_622F28` in this source route: `0x00553c44`, `0x00553cf4`, and `0x0055435e`.
- Rejected as canonical owner because it would overclaim the independent TerminalPane use at `0x0058b5b1`.

[UID:0000OI] `TerminalPane`:

- Accepted as an emitter.
- Current docs route `TerminalPane::OnDisconnect` through this file root.
- IDA proves one direct use of `off_622F28` at `0x0058b5b1`, paired with `Leave` and callback construction.
- Rejected as canonical owner because it would overclaim the three ReconnectDialog/ConnectionClosedDialog uses.

[UID:0000HE] `AlertPanes`:

- Rejected as owner and emitter.
- It is a shared alert framework route, but current docs keep feature-specific alert subclasses and prompt text with their feature modules.
- The literal is passed into alert construction from feature code; no direct evidence places the declaration in a generic alert framework source file.

Class-level candidates such as `ConnectionClosedDialog`, `ReconnectDialog`, or `TerminalPane` class pages:

- Rejected as canonical owners for this memory page.
- Each class-level owner covers only part of the use set.
- The generated file emitters already collapse those class routes to the correct source-file roots: `0000N0` and `0000OI`.

Containing map [UID:0003CW]:

- Rejected as a canonical owner.
- It contains literals with multiple ownership shapes: shared Reconnect/Leave, CopyWindow-only No/Yes, and shared `baram`.
- It is useful memory evidence, not a reconstructable source declaration unit.

Synthetic shared label source or new child source file:

- Rejected.
- There is no source path, source-string, debug, unique reference cluster, or naming evidence proving a human-authored common label declaration.
- Creating one would hide the meaningful fact that both feature roots independently need the label at their prompt construction sites.

## Split, Merge, And Reclassification Review

No split is justified:

- `0x00622f28-0x00622f3c` is exactly the UTF-16LE `Reconnect` literal including the terminator.
- Interior addresses `0x00622f2c`, `0x00622f30`, `0x00622f34`, and `0x00622f38` have zero IDA xrefs.
- Raw PE scan finds no `0x00622f2c` absolute references.
- The IDA suffix string at `0x00622f2c` is a pooled-string view artifact, not a separate source string.

No merge is justified:

- `SharedLeaveWideString` is a paired but separately terminated literal with its own target range.
- `CopyWindowNoButtonWideString` and `CopyWindowYesButtonWideString` have CopyWindow-only xrefs and a different owner.
- `SharedBaramPacketLiteral` is ANSI packet text with different source-use semantics.
- `kServerReconnect` at `0x006288a2` is a different, unreferenced full literal outside the range.

No reclassification is justified:

- The target is string data, reconstructable as a source-authored wide literal at use sites.
- It is not a pointer table, vtable artifact, class object, or non-source compiler artifact.

No IDA repair is required:

- Names like `off_622F28` and suffix string readings are imperfect, but xrefs, bytes, and decompilation are sufficient for ownership/source-routing.

## Exact Recommended Changes

Target page:

```text
No change.
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000N0,0000OI
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:[[[]]]
COMPLETION:89
CONFIDENCE:94
```

Coverage report:

```text
No direct edit to by-memory/-coverage-report.md.
No replacement row is required.
```

Generated memory coverage:

```text
No manual generated-file change.
Current no-owner/multiple-emitter route remains the intended generated state.
```

Child pages:

```text
No new child pages.
No split pages.
```

## Why No-Owner With Emitters Is Correct

This item is reconstructable because the bytes and use sites are clear: the final source can emit the literal text `L"Reconnect"` in known prompt construction contexts. It still should not receive a canonical owner because the memory address is a pooled constant shared across two source routes, and neither source route can claim the declaration without overclaiming the other.

The correct model is therefore:

```text
CANONICAL_OWNER:NONE
EMITTER_UIDS:0000N0,0000OI
```

That preserves two distinct facts:

- No single file/class owns the shared declaration address.
- Both reconstructed source files need the literal at proven semantic use sites.

## Validation Needs

- No validation run is required for this report-only pass.
- If a future generator changes no-owner/multiple-emitter behavior, validate that `0003G4` remains routed to both `auto-generated/NexusTK/network/ReconnectDialog.cpp` and `auto-generated/NexusTK/login/TerminalPane.cpp` use contexts rather than being forced into a synthetic owner.
- If future source/debug evidence surfaces a named shared label constant, reassess canonical ownership then; current IDA/PE evidence does not support that.

## Confidence

High confidence. Current documentation, live IDA MCP evidence, decompiler output, xref checks, and raw PE scans agree on the exact target bytes, the exact four direct use-site references, the absence of interior/suffix references, and the absence of references to the later `kServerReconnect` suffix.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G4","source_path":"executed-b-agent-research/B002/0003G4-SharedReconnectWideString-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
