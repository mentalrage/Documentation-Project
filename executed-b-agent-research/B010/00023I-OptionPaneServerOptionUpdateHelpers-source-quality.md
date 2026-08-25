** TARGET-REPORT-UID:00023I **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023I OptionPaneServerOptionUpdateHelpers Source-Quality Report

Status: FINISHED

Agent: B010
Assignment target: [UID:00023I] `source-3/project-documentation/by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md`
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00023I-OptionPaneServerOptionUpdateHelpers-source-quality.md`

## Recommendation Summary

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000M7
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000M7
```

Keep the current half-open range `0x0053e3d0-0x0053e520` as a mixed old-`OptionPane` helper island unless the supervisor wants a later granularity split. The range is valid: `0x0053e3d0-0x0053e41b` is one raw source-shaped packet sender, `0x0053e41b-0x0053e420` is `0xcc` alignment, and `0x0053e420-0x0053e520` is one raw source-shaped `OptionPane` apply helper. A future split would be mechanically clean, but it is not required to resolve source-quality names or C++ readiness for this target.

Keep [UID:0000M7] `OptionPane` by-file as canonical owner/emitter for the combined page. The first helper is a file-static/free `__stdcall` packet sender with no `this`; the second helper is an unadjusted `OptionPane *` `__thiscall` receiver helper. Assigning the whole page to [UID:00009V] `OptionPane` class would overstate the first helper, while assigning it outside `OptionPane.cpp` would lose the local command/packet context.

The target should no longer be blocked by passive "raw/no-xref/final names unresolved" language. The two bodies are source-authored project logic, not compiler wrappers or runtime library thunks. No direct callers were found for either raw start, and that remains a score cap, but the names/signatures and field/control semantics are now strong enough for a first-draft C++ block.

## Evidence Checked

- Target doc [UID:00023I] `by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md`.
- Parent/support docs:
  - [UID:0001DO] `by-memory/0x0053d820-0x0053e520.OptionPane.md`
  - [UID:0001DP] `by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md`
  - [UID:0001DQ] `by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md`
  - [UID:0003NO] `by-memory/0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md`
  - [UID:0003NQ] `by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md`
  - [UID:00009V] `by-class/OptionPane.md`
  - [UID:0000M7] `by-file/OptionPane.md`
  - [UID:0000BI] `by-class/RadioGroupControlPane.md`
  - [UID:0000IT] `by-file/DialogPane.md`
  - [UID:0000Q5] `by-global/g_packetSender.md`
  - [UID:0001HU] `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- Current `by-memory/-coverage-report.md` row for [UID:00023I]; the manual row is stale at `78%` while the target metadata is already `85/86`.
- Current `project-level/-auto-completion-stats.md`; [UID:00023I] and [UID:0001DO] appear at `85/86`.
- Executed older B001 report `tools/leaser/Agents/Agent-B001/research/executed/older/B001-MEMTOOL-0053E380-OptionPaneSendOptionPacket11B.md`, which confirms the adjacent three-byte helper's file-level ownership and direct `OptionPane::OnOptionCommand` caller set.
- Local export JSONs:
  - `exports/0053e3d0.json`
  - `exports/0053e420.json`
  - `exports/0053e1e0.json`
  - `exports/0053e380.json`
  - `exports/0053ddb0.json`
  - `exports/0053d820.json`
  - `exports/00496110.json`
  - `exports/00575470.json`
  - `exports/00540ea0.json`
- `source-3/simroot_v2/class_OptionPane.cpp` as generated-output negative evidence; it omits this helper island and should not be treated as a final source shape.
- Live MCP health was attempted at `http://127.0.0.1:13337/mcp` and failed with "Unable to connect to the remote server" in this session. I therefore used existing live-IDA notes in the by-* docs plus local export JSONs for current reanalysis.

## Raw Helper 0x0053e3d0

Best source-facing name:

```text
static void SendOptionPacket11BSubcommand63(unsigned char optionCode, unsigned char selectedIndex);
```

IDA/local-export shape:

```text
address: 0x0053e3d0
size: 0x4b / 75 bytes
signature: void __stdcall FUN_0053e3d0(undefined1 param_1, undefined1 param_2)
callers: none found
callees: 0x00574bb0 QueueAndSendPacket, security cookie
```

Behavior:

- Builds a stack packet.
- Stores word opcode `0x011b` at sent offsets `+0x00..+0x01`.
- Stores fixed subcommand `0x63` at sent offset `+0x02`.
- Stores caller byte 1 at sent offset `+0x03`.
- Stores caller byte 2 at sent offset `+0x04`.
- Stores a zero byte at local offset `+0x05`, but sends length `5`; the terminator is not transmitted.
- Calls [UID:0001HU] `QueueAndSendPacket` through [UID:0000Q5] `g_packetSender`.

Ownership/name reasoning:

- This is not an `OptionPane` method: it is `__stdcall`, consumes two stack bytes via `retn 8`, ignores incoming `ecx` as a pane pointer, and uses only `g_packetSender`.
- It belongs in `OptionPane.cpp`, not Socket/network sources, because the opcode family and neighboring callers are old/new option-pane packet helpers.
- The nearest source context is [UID:0001DQ] `OptionPaneSendOptionPacket11B` and [UID:0003NO] `NewOptionPaneSendOptionPacket11BSubcommand63`; `0x00540ea0` has the same two-argument `0x011b/0x63` packet body.
- The old command handler at `0x0053ddb0` inlines the same five-byte packet shape for command/control `3`: it builds bytes `0x011b`, `0x63`, first payload `0x0d`, and second payload equal to the selected index. That makes `optionCode, selectedIndex` the best parameter role pair. The helper is not directly called by that handler in the observed binary.

Rejected alternatives:

- `OptionPane::SendOptionPacket11B63`: reject for final source shape because no `this` is consumed.
- `sub_53E3D0` / `FUN_0053e3d0`: reject as compiler/raw labels.
- `CashShopRequest::meth_0x574bb0` ownership: reject; the callee is the generic Socket queue/send funnel, and the feature packet builder remains in `OptionPane.cpp`.
- `NewOptionPane` class ownership: reject for this old address; use it only as duplicate-body evidence.
- Import/runtime wrapper: reject; this is game-specific packet construction.

## Raw Helper 0x0053e420

Best source-facing name:

```text
bool OptionPane::ApplyServerOptionAvailability(const unsigned char *payload);
```

IDA/local-export shape:

```text
address: 0x0053e420
size: 0x100 / 256 bytes
signature: undefined4 __thiscall FUN_0053e420(void *this, int param_1)
callers: none found
callees: 0x00575470 byte reader, 0x00496110 RadioGroupControlPane::SetSelectedIndex
```

Behavior:

- Treats `param_1` as a pointer to a packet/server payload whose leading byte is skipped.
- Reads payload bytes `+1..+5` through `0x00575470`, a trivial one-byte reader.
- Stores the bytes into actual primary `OptionPane` object offsets `+0x26c..+0x270`.
- Fetches child controls through the inherited `DialogPane` control manager at actual primary offset `+0x1fc`.
- Updates controls in exact order `5`, `4`, `7`, `8`, `3`.
- Calls [UID:0000BI] `RadioGroupControlPane::SetSelectedIndex` (`0x00496110`) with `(storedByte == 0)`.
- Returns `true` / `1`.

Corrected control semantics:

The current target wording says the helper enables/disables child controls. That is mechanically wrong. The callee at `0x00496110` compares the argument against `RadioGroupControlPane::m_selectedIndex`, invalidates the previous and new option rectangles, and writes the new selected index. The source-quality description should be:

```text
sets each two-state radio group selected index to (serverByte == 0)
```

Do not describe this as `EnableWindow`, `SetEnabled`, child activation, or hit-test disabling. The UI meaning may be an option enabled/off state, but the function call is a radio selected-index update.

Field/control mapping:

| Actual primary offset | Payload byte | Control id updated | Command-handler evidence |
| --- | --- | --- | --- |
| `OptionPane + 0x26c` | `payload[1]` | `5` | command `5` compares `mbr_0x26c == 0` and sends regular option byte `6` if changed |
| `OptionPane + 0x26d` | `payload[2]` | `4` | command `4` compares `mbr_0x26d == 0` and sends regular option byte `5` if changed |
| `OptionPane + 0x26e` | `payload[3]` | `7` | command `7` compares `mbr_0x26e == 0` and sends regular option byte `4` if changed |
| `OptionPane + 0x26f` | `payload[4]` | `8` | command `8` compares `mbr_0x26f == 0` and sends regular option byte `9` if changed |
| `OptionPane + 0x270` | `payload[5]` | `3` | constructor initializes from `g_pConfig + 0x28de48`; command `3` sends `0x011b/0x63/0x0d/<selected>` inline |

Best current field name:

```text
unsigned char m_serverOptionState[5]; // actual offsets +0x26c..+0x270, control order 5,4,7,8,3
```

`m_serverOptionAvailability[5]` is also acceptable if the existing docs want continuity, but "availability" should be described as a server-provided state/status byte rather than a widget enable flag. Exact option label names are not recovered from this evidence.

Adjusted-this reconciliation:

[UID:0001DP] `OptionPaneServerOptionResponse` writes `this + 0x1cc..0x1d0` and uses `this + 0x15c` in its `'#'` branch. That should not be documented as a separate parallel state block. The same decompiled response helper constructs the alert against `this - 0xa0`, proving that its handler view is adjusted by `+0xa0`. Therefore:

```text
secondary-handler this + 0x1cc == primary OptionPane + 0x26c
secondary-handler this + 0x15c == primary OptionPane + 0x1fc
```

The response helper and raw `0x0053e420` apply helper are touching the same physical old-`OptionPane` server-option state and the same inherited `DialogPane` control manager.

Rejected alternatives:

- Separate `this+0x1cc` and `this+0x26c` field groups: reject after adjusted-this reconciliation.
- `SetControlEnabled` / child enable-disable names: reject; `0x00496110` is radio selected-index state.
- File-static/free apply helper: weaker than class method because `0x0053e420` is `__thiscall` and consumes primary `OptionPane *this`.
- `NewOptionPane::ApplyServerOptions`: reject for this old helper; [UID:0003NQ] is the new-pane config-writing analog, not this body.
- Compiler thunk/destructor wrapper: reject; the body reads packet payload bytes, writes pane fields, fetches controls, and returns a boolean.

## Caller/Reachability Findings

Both raw starts still have no proven inbound route:

- Existing by-* docs record no direct IDA xrefs to `0x0053e3d0` or `0x0053e420`.
- Local export JSONs also list `callers: []` and no `data_refs` for both starts.
- No table/pointer route to these raw starts was found in the checked docs or local exports.

This is a confidence cap, not a no-code proof:

- The bodies are complete, normal source-shaped functions with stack frames and returns.
- They are not import thunks, adjustor thunks, scalar deleting destructors, CRT wrappers, or padding.
- The packet sender duplicates the exact new-option subcommand-63 helper at `0x00540ea0`.
- The apply helper is the unadjusted primary-`this` counterpart of [UID:0001DP]'s adjusted `'#'` response branch.
- The old command handler contains positive semantic evidence for the packet sender's parameter roles and for the field/control mapping.

Recommended wording: "retained raw source helper with no direct xref found" rather than "unresolved blocker." Keep the no-xref fact visible, but do not leave final helper names, field names, or C++ readiness blocked by it.

## Split/Merge/Range Policy

Current range stays valid:

```text
0x0053e3d0-0x0053e41b  file-level packet helper
0x0053e41b-0x0053e420  internal alignment padding
0x0053e420-0x0053e520  OptionPane apply helper
```

No endpoint change is recommended. `0x0053e3c1-0x0053e3d0` remains predecessor padding after [UID:0001DQ]. `0x0053e520` remains the [UID:0001DR] `MacroDialogs` boundary.

Optional future split, if supervisor wants narrower ownership:

- `0x0053e3d0-0x0053e41b.OptionPaneSendOptionPacket11BSubcommand63.md`, owner/emitter [UID:0000M7].
- `0x0053e420-0x0053e520.OptionPaneApplyServerOptionAvailability.md`, owner [UID:00009V] or emitter [UID:0000M7].
- Keep `0x0053e41b-0x0053e420` as ignored alignment.

I do not recommend requiring that split for this implementation. A mixed helper-island page under by-file `OptionPane.cpp` is adequate and avoids churn.

Rejected merge alternatives:

- Do not merge `0x0053e3d0` into [UID:0001DQ] `0x0053e380-0x0053e3c1`; they are separate physical helpers with different packet lengths and padding between them.
- Do not merge `0x0053e3d0` with [UID:0003NO] `0x00540ea0`; they are duplicate-body old/new option helpers at distinct addresses.
- Do not merge `0x0053e420` into [UID:0001DP]; [UID:0001DP] is the vtable/table response handler with the alert branch and adjusted `this`, while `0x0053e420` is the no-alert primary-this apply body.

## First-Draft C++ Readiness

Recommendation: populate the formal `RECONSTRUCTION_CPP` block for [UID:00023I] with first-draft source-style C++ if the supervisor accepts same-page multi-function emission for this helper island. If a split is chosen later, move the first function to the file-level packet-helper child and the second to the class/helper child.

Draft:

```cpp
static void SendOptionPacket11BSubcommand63(unsigned char optionCode, unsigned char selectedIndex)
{
    unsigned char packet[6];

    *(unsigned short *)&packet[0] = 0x011b;
    packet[2] = 0x63;
    packet[3] = optionCode;
    packet[4] = selectedIndex;
    packet[5] = 0;

    g_packetSender->QueueAndSendPacket(packet, 5);
}

bool OptionPane::ApplyServerOptionAvailability(const unsigned char *payload)
{
    RadioGroupControlPane *control;

    m_serverOptionState[0] = ReadPacketByte(payload + 1);
    m_serverOptionState[1] = ReadPacketByte(payload + 2);
    m_serverOptionState[2] = ReadPacketByte(payload + 3);
    m_serverOptionState[3] = ReadPacketByte(payload + 4);
    m_serverOptionState[4] = ReadPacketByte(payload + 5);

    control = (RadioGroupControlPane *)m_controlManager->GetControl(5);
    control->SetSelectedIndex(m_serverOptionState[0] == 0);

    control = (RadioGroupControlPane *)m_controlManager->GetControl(4);
    control->SetSelectedIndex(m_serverOptionState[1] == 0);

    control = (RadioGroupControlPane *)m_controlManager->GetControl(7);
    control->SetSelectedIndex(m_serverOptionState[2] == 0);

    control = (RadioGroupControlPane *)m_controlManager->GetControl(8);
    control->SetSelectedIndex(m_serverOptionState[3] == 0);

    control = (RadioGroupControlPane *)m_controlManager->GetControl(3);
    control->SetSelectedIndex(m_serverOptionState[4] == 0);

    return true;
}
```

Caveats for implementation prose:

- `ReadPacketByte` is the source-facing role for `0x00575470`; exact final helper name can remain descriptive.
- `QueueAndSendPacket` should use the existing Socket/send wrapper naming accepted around [UID:0001HU], not generated `CashShopRequest::meth_0x574bb0`.
- `m_controlManager` is the inherited [UID:0000IT] `DialogPane` control manager at primary offset `+0x1fc`.
- If the layout docs do not yet want an array field, use five field names but keep the exact control order and offsets.

## Exact Recommended Target Changes

Update `by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md`:

- Change `COMPLETION:85` to `COMPLETION:88`.
- Change `CONFIDENCE:86` to `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000M7`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000M7`.
- Replace "C++ remains outside the autogen box because these raw starts are not IDA functions and final helper naming is not source-quality yet" with resolved wording: raw starts/no xrefs cap confidence, but names/signatures/field semantics are source-quality enough for first-draft C++.
- Rename the first helper from `OptionPane::SendOptionPacket11B63 or file-local equivalent` to file-static/free `SendOptionPacket11BSubcommand63(unsigned char optionCode, unsigned char selectedIndex)`.
- Rename the second helper to `OptionPane::ApplyServerOptionAvailability(const unsigned char *payload)`.
- Replace "enables/disables five child controls" and `SetControlEnabled` sketch language with `RadioGroupControlPane::SetSelectedIndex(serverByte == 0)`.
- Document the field/control mapping table:
  - `+0x26c` / payload `+1` / control `5` / regular outgoing code `6`
  - `+0x26d` / payload `+2` / control `4` / regular outgoing code `5`
  - `+0x26e` / payload `+3` / control `7` / regular outgoing code `4`
  - `+0x26f` / payload `+4` / control `8` / regular outgoing code `9`
  - `+0x270` / payload `+5` / control `3` / subcommand-63 outgoing code `0x0d`
- Add the adjusted-this reconciliation with [UID:0001DP]:
  - [UID:0001DP] `this+0x1cc..0x1d0` equals primary `OptionPane+0x26c..0x270`.
  - [UID:0001DP] `this+0x15c` equals primary `OptionPane+0x1fc`.
- Record no direct callers/data refs found for both raw starts as a route cap, not a no-code proof.
- Replace the provisional C++ sketch with the first-draft C++ above, or split it into target prose plus formal block if validator style requires shorter formal code.
- Add rejected alternatives: class-only owner for whole island, `CashShopRequest` callee ownership, NewOptionPane ownership for old helper, separate `this+0x1cc` field group, child enable/disable helper naming, compiler/runtime helper, and merge with [UID:0001DQ]/[UID:0003NO]/[UID:0001DP].

## Support-Doc Update List

Update [UID:0001DO] `by-memory/0x0053d820-0x0053e520.OptionPane.md`:

- Replace the touched-state table's separate `this+0x1cc..0x1d0` and `this+0x26c..0x270` rows with an adjusted-this note. The actual primary fields are `OptionPane+0x26c..0x270`; [UID:0001DP] sees them as `this+0x1cc..0x1d0` because its handler view is `primary+0xa0`.
- Update child row [UID:00023I] to use `SendOptionPacket11BSubcommand63` and `OptionPane::ApplyServerOptionAvailability`.
- Correct control update wording to `SetSelectedIndex(byte == 0)`.
- Keep parent non-final/aggregate caution only for full class field names and no-xref raw routes, not for helper names/signatures.

Update [UID:0001DP] `by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md`:

- Add the adjusted-this alias note:
  - `this+0x1cc..0x1d0` in the `'#'` branch are primary `OptionPane+0x26c..0x270`.
  - `this+0x15c` is primary `OptionPane+0x1fc`.
- Replace "control-state update" ambiguity with `RadioGroupControlPane::SetSelectedIndex(byte == 0)`.
- Cross-reference [UID:00023I] as the primary-this apply-body counterpart with no direct route found.

Update [UID:00009V] `by-class/OptionPane.md`:

- Method table should distinguish:
  - file-static/free `SendOptionPacket11BSubcommand63(unsigned char,unsigned char)` in [UID:00023I], no `this`;
  - `bool OptionPane::ApplyServerOptionAvailability(const unsigned char *)` in [UID:00023I], primary `this`;
  - response handler [UID:0001DP] as adjusted secondary-view/vtable dispatch.
- Replace "raw helper bodies ... final names unresolved" with "raw no-xref bodies retained; helper names/signatures resolved to first-draft quality."
- Add field map `m_serverOptionState[5]` at `+0x26c..+0x270` in control order `5,4,7,8,3`.

Update [UID:0000M7] `by-file/OptionPane.md`:

- Change "option-local helpers under review" for [UID:00023I] to resolved mixed helper island under `OptionPane.cpp`.
- Add [UID:00023I] source-quality naming:
  - `SendOptionPacket11BSubcommand63`
  - `OptionPane::ApplyServerOptionAvailability`
- Keep file-level owner/emitter and explicitly reject moving the first helper to class-only ownership or central Socket/protocol ownership.
- Note [UID:0003NO] as the new-option duplicate-body analog, not a merge target.

Update [UID:0001DQ] `by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md` only if touched during implementation:

- Add a sibling note that [UID:00023I] `0x0053e3d0` is the adjacent five-byte `0x011b/0x63` sender and remains physically separate.

Update [UID:0003NO] `by-memory/0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md` only if touched during implementation:

- Add a cross-reference that [UID:00023I] `0x0053e3d0` is the old-option duplicate-body counterpart.

No required edits to [UID:0000Q5] `g_packetSender`, [UID:0001HU] `QueueAndSendPacket`, [UID:0000BI] `RadioGroupControlPane`, or [UID:0000IT] `DialogPane` are needed unless implementation wants additional back-references. Those pages already support the source-quality names used here.

## Exact Pending Coverage Replacement Row

Do not edit `by-memory/-coverage-report.md` as B010. If the supervisor applies this recommendation, replace the current [UID:00023I] row with:

```markdown
    - [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md) 0x0053e3d0-0x0053e520 | helper-island | OptionPaneServerOptionUpdateHelpers : reconstructable : 88% : strong : Old `OptionPane` mixed helper island with file-static `SendOptionPacket11BSubcommand63(unsigned char,unsigned char)` at `0x0053e3d0-0x0053e41b`, `0xcc` alignment at `0x0053e41b-0x0053e420`, and primary-this `OptionPane::ApplyServerOptionAvailability(const unsigned char *)` at `0x0053e420-0x0053e520`; evidence confirms no direct raw-start xrefs, five-byte `0x011b/0x63` packet send through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / [UID:0001HU][QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), payload bytes `+1..+5` stored to actual `OptionPane+0x26c..+0x270`, controls `5/4/7/8/3` updated by `RadioGroupControlPane::SetSelectedIndex(byte == 0)`, [UID:0001DP] adjusted-this aliases reconciled, file-level owner/emitter [UID:0000M7][OptionPane](by-file/OptionPane.md) retained for mixed file/class helper shape, and first-draft C++ is ready despite no-xref route cap.
```

## Validation Commands Needed

Run from `source-3/project-documentation` after any implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00023I-OptionPaneServerOptionUpdateHelpers-source-quality-removed.md](00023I-OptionPaneServerOptionUpdateHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional sibling cross-references are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [00023I-OptionPaneServerOptionUpdateHelpers-source-quality-removed.md](00023I-OptionPaneServerOptionUpdateHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated-file watch list after validation:

- `project-level/-auto-completion-stats.md` may update if target/support scores change.
- `tools/validator.ini` may update queue/checkpoint state.
- Normal validator-generated logs/cache files may change.
- `by-memory/-coverage-report.md` must remain supervisor-owned; use the row above in notes/report only.

## IDA Rename/Type/Comment Recommendations

Recommended IDA labels/types:

```text
0x0053e3d0 -> OptionPaneSendOptionPacket11BSubcommand63
type: void __stdcall OptionPaneSendOptionPacket11BSubcommand63(unsigned char optionCode, unsigned char selectedIndex)
confidence: high for type/body, medium-high for exact original source name
comment: Old OptionPane file-local 0x011b/0x63 sender; sends five bytes through g_packetSender, no direct xrefs found, same packet shape as 0x00540ea0 and inline case-3 command packet.
```

```text
0x0053e420 -> OptionPaneApplyServerOptionAvailability
type: bool __thiscall OptionPane::ApplyServerOptionAvailability(const unsigned char *payload)
confidence: high for thiscall/body/return, medium-high for exact original source name
comment: Primary-this apply helper; reads payload[1..5] into OptionPane+0x26c..+0x270 and updates controls 5/4/7/8/3 with RadioGroupControlPane::SetSelectedIndex(byte == 0); no direct xrefs found.
```

```text
0x00496110 -> RadioGroupControlPane::SetSelectedIndex
type: void __thiscall RadioGroupControlPane::SetSelectedIndex(int selectedIndex)
confidence: high; class doc already uses this role
comment: Invalidates old/new radio option rectangles and stores m_selectedIndex; not an enable/disable helper.
```

```text
0x00575470 -> ReadPacketByte or PacketBufferReadUInt8
type: unsigned char __cdecl ReadPacketByte(const unsigned char *p)
confidence: high for behavior, medium for final global helper name because it has broad caller fan-in.
```

Field/layout recommendations:

```text
OptionPane +0x26c..+0x270 -> m_serverOptionState[5]
control order: 5, 4, 7, 8, 3
selected-index expression: m_serverOptionState[i] == 0
confidence: high for offsets/order, medium for final field name and exact UI labels.
```

```text
DialogPane inherited +0x1fc in primary OptionPane -> m_controlManager / child-control manager
confidence: high from DialogPane support docs and matching adjusted-this alias in 0001DP.
```

## Open Questions And Resolution Attempts

Open: exact original source helper names.

- Evidence checked: local export names, neighboring by-memory filenames, old B001 report, old/new duplicate helper docs, command-handler decompile, and file/class support docs.
- Resolution: use descriptive source-quality names `SendOptionPacket11BSubcommand63` and `ApplyServerOptionAvailability`. These are high-probability roles but not proven original symbols.

Open: direct caller route to `0x0053e3d0` and `0x0053e420`.

- Evidence checked: current by-* live IDA xref notes, local export `callers`/`data_refs`, command-handler decompile, response-helper decompile, and duplicate new-option helper docs.
- Resolution: no direct route proven. Treat as retained raw source helpers with no-xref route cap. This is not a no-code proof because both bodies are complete source-authored project logic with strong local semantic analogs.

Open: exact UI labels for the five server-option controls.

- Evidence checked: constructor/control ids, command-handler cases, config offsets, response/apply helper field writes.
- Resolution: exact labels are not safely recoverable from this evidence. Document control IDs, field offsets, outgoing packet codes, and selected-index semantics instead of inventing labels.

Open: array field versus five individual byte fields.

- Evidence checked: contiguous offsets `+0x26c..+0x270`, repeated unrolled code, command-handler field uses, constructor initialization of `+0x270`.
- Resolution: `m_serverOptionState[5]` is the best source-facing model, but implementation can use five named bytes if the existing layout doc avoids arrays. The exact offset/control map must be preserved either way.

## Files Changed By This Report

Created only:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00023I-OptionPaneServerOptionUpdateHelpers-source-quality.md
```

No by-* docs were edited. `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00023I-OptionPaneServerOptionUpdateHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00023I"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00023I-OptionPaneServerOptionUpdateHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00023I-OptionPaneServerOptionUpdateHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00023I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
