** TARGET-REPORT-UID:0001JB **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B006 source-quality report: [UID:0001JB] TerminalPaneAndSetup

## Assignment

- Target UID: `0001JB`
- Target path: `source-3/project-documentation/by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0001JB-TerminalPaneAndSetup-source-quality.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000OI`, `EMITTER_UIDS:0000OI`
- Required workflow status: report-only. I did not edit the target/support by-* docs and did not edit `by-memory/-coverage-report.md`.

## Executive recommendation

`0001JB` should remain a source-quality aggregate map under `NexusTK/login/TerminalPane.cpp`, but it should not emit aggregate-level C++ yet. The range contains multiple source-authored methods across two classes (`TerminalPane` and `TerminalSetupPane`), existing child ranges, one missing retained raw helper at `0x0058b0f0`, vtable-only virtual callbacks, and the immediate successor boundary for `PhoneBookDialog` at `0x0058c350`. Emitting one broad C++ block here would duplicate or overrun child emission scopes.

Recommended target state after implementation:

- Raise target to `COMPLETION:87`, `CONFIDENCE:88`.
- Keep `RECONSTRUCTABLE:TRUE` and `CANONICAL_OWNER:0000OI`.
- Keep `EMITTER_UIDS:0000OI` for routing until exact source-bearing children are created or updated.
- Keep formal C++ blank in this aggregate, with an explicit target-specific no-code/defer proof.
- Add exact child/split map and first-draft readiness notes for constructor, parser, disconnect, close, reconnect/leave callback, setup constructor, setup update, and setup command handler.
- Add missing raw helper `0x0058b0f0-0x0058b12c` as a retained no-xref source-shaped helper candidate.
- Update support docs with source-facing field names for the terminal serial settings at `g_pConfig+0x28de28/+0x28de2c`, startup flag at `+0x2916ca`, parser state field, Socket helper names, callback type, and `PhoneBookDialog` boundary.

Rejected alternatives:

- Do not convert the aggregate to a class declaration with `[[CHILDREN]]` at this stage. The aggregate still owns unsplit source-bearing code, and `[[CHILDREN]]` would not capture the missing raw helper or unsplit child methods cleanly.
- Do not make the aggregate `RECONSTRUCTABLE:FALSE` yet. The range contains reconstructable source-authored methods; the non-emitting policy is about split/emission scope, not generated-binary-only status.
- Do not merge the successor `0x0058c350+` `PhoneBookDialog` code into this aggregate. Evidence supports an exact successor boundary.

## Evidence checked

### Local instruction and status files

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B006/goal.md`
- Existing B006 research directory, to avoid overwriting earlier reports.

### Primary and support docs

- `source-3/project-documentation/by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`
- `source-3/project-documentation/by-file/TerminalPane.md`
- `source-3/project-documentation/by-class/TerminalPane.md`
- `source-3/project-documentation/by-class/TerminalSetupPane.md`
- `source-3/project-documentation/by-global/g_pTerminalPane.md`
- `source-3/project-documentation/by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md`
- `source-3/project-documentation/by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`
- `source-3/project-documentation/by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md`
- `source-3/project-documentation/by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md`
- `source-3/project-documentation/by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`
- `source-3/project-documentation/by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md`
- `source-3/project-documentation/by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md`
- `source-3/project-documentation/by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`
- `source-3/project-documentation/by-memory/0x0062de34-0x0062dee8.TerminalSetupPaneResourceStrings.md`
- `source-3/project-documentation/by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md`
- `source-3/project-documentation/by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md`
- `source-3/project-documentation/by-file/PhoneBookDialog.md`
- `source-3/project-documentation/by-class/PhoneBookDialog.md`
- `source-3/project-documentation/by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

### Socket/helper dependency docs

- `source-3/project-documentation/by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`
- `source-3/project-documentation/by-memory/0x00574c20-0x00574c35.PostSocketModeByteCommand.md`
- `source-3/project-documentation/by-memory/0x00574c40-0x00574ca1.QueueTransportStringCommand.md`
- `source-3/project-documentation/by-memory/0x00574cb0-0x00574cc5.SendSingleByteCommand.md`
- `source-3/project-documentation/by-memory/0x00574cf0-0x00574d00.SetSocketConnectionFlag.md`
- `source-3/project-documentation/by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md`

### Generated/export evidence

- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/project-documentation/auto-generated/NexusTK/login/TerminalPane.cpp`
- `source-3/project-documentation/simroot_v2/class_TerminalPane.cpp`
- `source-3/project-documentation/simroot_v2/class_TerminalSetupPane.cpp`
- Exported function JSON/decompile records for `0x0058af50`, `0x0058b130`, `0x0058b470`, `0x0058b5e0`, `0x0058b620`, `0x0058b650`, `0x0058c1a0`, and `0x0058c240`.
- Local PE bytes from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for exact boundary/padding checks.

### IDA/MCP status

- Checked local IDA MCP endpoint `http://127.0.0.1:13337/mcp`; it was unavailable (`Unable to connect to the remote server`).
- Conclusions therefore use existing live-IDA-backed docs, exported decompile/function records, coverage exports, generated source, support docs, and direct PE byte scans.

## Exact range and split evidence

The target range is a broad half-open aggregate from `0x0058af50` through `0x0058c350`. The successor `0x0058c350` is the `PhoneBookDialog` constructor start, not Terminal code.

Recommended exact source/split map:

| Range | Recommended source-facing role | Evidence and emission policy |
|---|---|---|
| `0x0058af50-0x0058b0ee` | `TerminalPane::TerminalPane()` | Live constructor with four callers. Source-authored. First-draft child C++ is feasible after child split. |
| `0x0058b0ee-0x0058b0f0` | padding | Direct PE bytes are `CC CC`. |
| `0x0058b0f0-0x0058b12c` | retained configured-connect helper, best name `TerminalPane_PostConfiguredTerminalConnectIfSerial_raw` | Real code not currently represented as an exported function or child doc. Reads `g_pConfig+0x28de28/+0x28de2c`, posts Socket connect, then queues `ATZ\n\r`. Local PE rel32/dword scans found no direct refs. Source-shaped retained no-xref helper; do not treat as padding or compiler glue. |
| `0x0058b12c-0x0058b130` | padding | Direct PE bytes are `CC` alignment before parser. |
| `0x0058b130-0x0058b44c` | `TerminalPane::ParseTerminalStream(SocketPacket *packet)` | Existing child path ends in filename `...0x0058b44b...`; raw/function evidence shows exclusive end `0x0058b44c`. Vtable/data ref at `0x0062da80`. Source-authored parser; first-draft child C++ feasible with accepted packet/helper names. |
| `0x0058b44c-0x0058b470` | padding/alignment | Raw bytes show padding between parser and disconnect virtual. |
| `0x0058b470-0x0058b5e0` | `TerminalPane::OnDisconnect(...)` | Vtable/data ref at `0x0062daa4`; raw epilogue is `ret 0x0c`, so three stack args are present even if simplified decompile drops them. Source-authored virtual. First-draft child C++ feasible with signature caveat. |
| `0x0058b5e0-0x0058b5fc` | `TerminalPane::OnClose()` | Vtable/data ref at `0x0062da54`. Source-authored short method. Ready for child C++. |
| `0x0058b5fc-0x0058b620` | padding/alignment | Padding before callback helper. |
| `0x0058b620-0x0058b64f` | `TerminalPane::OnReconnectOrLeave(unsigned long decision)` | Existing callback child; xref from callback object construction at `0x0058b56d`. Source-authored callback body; ready for child C++. |
| `0x0058b64f-0x0058b650` | alignment byte | Immediate alignment before setup constructor. |
| `0x0058b650-0x0058c192` | `TerminalSetupPane::TerminalSetupPane(...)` | Long source-authored constructor, no code/data xrefs found in export or PE direct scans. Best explanation is retained/legacy setup dialog code linked with its vtable/resources. Raw epilogue indicates `ret 4`, so one unused/legacy stack argument should be documented until caller recovery. First-draft child C++ feasible after split. |
| `0x0058c192-0x0058c1a0` | padding/alignment | Direct PE bytes are padding before update virtual. |
| `0x0058c1a0-0x0058c23f` | `TerminalSetupPane::UpdateControlState()` | Vtable/data ref at `0x0062daf8`; no stack args. Source-authored. Ready for child C++. |
| `0x0058c23f-0x0058c240` | alignment byte | Immediate boundary before command virtual. |
| `0x0058c240-0x0058c350` | `TerminalSetupPane::OnCommand(int commandId, int commandParam)` | Vtable/data ref at `0x0062daf4`; raw epilogue is `ret 8`, second stack arg unused. Source-authored. Ready for child C++. |
| `0x0058c350+` | `PhoneBookDialog` successor | Confirmed by `PhoneBookDialog` docs and raw prologue; do not merge into `TerminalPaneAndSetup`. |

## Function and behavior findings

### `0x0058af50-0x0058b0ee`: `TerminalPane::TerminalPane()`

Evidence:

- Exported as `sub_58AF50`, size `0x19e`, exclusive end `0x0058b0ee`.
- Callers recorded at `0x004f5f9b`, `0x004f647a`, `0x004f7cbb`, and `0x004f924f`.
- `OpenTerminalPane`/main menu support confirms an active menu route and retained helper duplicate route.
- Constructor installs `TerminalPane` vtables, initializes layout state, writes `g_pTerminalPane`, and sets terminal startup state.

Source-quality behavior to incorporate:

- Constructs a `DialogPane`-derived terminal pane with an empty title and full-screen/hidden startup placement.
- Stores the singleton/global `g_pTerminalPane` at `0x0069bdf8`.
- Posts Socket command 9 through `PostSocketModeByteCommand(g_packetSender, 1)` (`0x00574c20`), which sets the Socket protocol/mode byte. Do not invent a Terminal-owned send helper for this.
- Calls the session/reset helper currently at `0x00596620`; existing class output calls this `ResetCashShopRequest` but support docs should verify the exact non-Terminal owner before source emission.
- Reads `g_pConfig+0x28de28`; if it is in `1..4`, treats it as a COM port number and posts a Socket connect command through `0x00574b00`, passing the port and `g_pConfig+0x28de2c` baud rate.
- Queues modem reset string `ATZ\n\r` through `QueueTransportStringCommand(g_packetSender, "ATZ\n\r")` (`0x00574c40`) after configured serial connect.
- Initializes the terminal parser state field to `0`.
- Writes `g_pConfig+0x2916ca = 1`, matching the startup-ready/authenticated path used by `OpenTerminalPane`.
- If the startup flag was previously set, starts or re-arms the terminal callback/timer path through `0x005975e0` with the adjusted subobject at `this+0xa4`.
- Calls the final UI/pane helper at `0x00557430`; source-facing name remains unresolved enough that implementation should keep it as a dependency until its owner doc is checked.

Best source-facing signature:

```cpp
TerminalPane::TerminalPane();
```

Rejected alternatives:

- `OpenTerminalPane` or menu helper ownership: rejected for this function. The active menu helper calls into/duplicates construction logic, but `0x0058af50` is the class constructor.
- Socket helper reownership under Terminal: rejected. `0x00574c20` and `0x00574c40` already have Socket-owned docs and broad Socket caller evidence.

### `0x0058b0f0-0x0058b12c`: retained configured-connect helper

Evidence:

- This is real code between constructor padding and parser start, not exported as a function in the current JSON set and not documented as a child.
- Raw bytes show:
  - load `g_pConfig` from `0x0067a7c8`
  - read byte/field at `+0x28de28`
  - accept only values `1..4`
  - push `g_pConfig+0x28de2c`
  - call `0x00574b00`
  - push `0x0062dddc` (`ATZ\n\r`)
  - call `0x00574c40`
  - return
- Local PE scans found no direct rel32 calls/jumps to `0x0058b0f0` and no dword/immediate refs to the entrypoint.

Best source-facing role:

- `TerminalPane_PostConfiguredTerminalConnectIfSerial_raw`
- Alternate acceptable name: `TerminalPane::PostConfiguredTerminalConnectIfSerial()`

Policy:

- Treat as a retained no-xref source-shaped helper in `TerminalPane.cpp`.
- Do not emit source from the parent aggregate yet.
- If a child page is created, it should record no direct caller evidence and either keep C++ blank or use a tiny source helper only after the supervisor accepts retained helper emission.

Rejected alternatives:

- Padding/alignment: rejected by executable bytes and Socket calls.
- Compiler-generated thunk/glue: rejected because the body is semantic terminal configuration logic.
- Active callback route: not proven. Current direct call/data scans did not find a route.

### `0x0058b130-0x0058b44c`: `TerminalPane::ParseTerminalStream(SocketPacket *packet)`

Evidence:

- Exported as `sub_58B130`, size `0x31c`, exclusive end `0x0058b44c`.
- Data/vtable reference at `0x0062da80`; no ordinary code callers expected for this virtual/parser callback.
- Existing child doc path uses `0x0058b130-0x0058b44b...`; raw and exported evidence show the half-open exclusive end should be `0x0058b44c`.
- Packet layout evidence: reads data pointer at packet offset `+0x0c` and length at `+0x10`.
- Parser state is accessed as adjusted `this+0x1cc`. Because the vtable callback receives a secondary/adjusted receiver, the full `TerminalPane` field is best documented as `m_terminalParserState` at full-object offset `+0x26c`.

Best source-facing name/signature:

```cpp
char TerminalPane::ParseTerminalStream(SocketPacket *packet);
```

Alternative names:

- `OnTerminalStreamData(SocketPacket *packet)` is acceptable if the codebase prefers event-callback naming.
- `OnSocketPacket` is too generic and should be rejected for docs unless stronger source evidence appears.

Behavior to incorporate:

- Scans received terminal bytes from `packet->data`/`packet->length`.
- Handles BEL and ESC sequences.
- Recognizes the `%I\n</RunRegistry=` sequence and final login/registry handoff behavior.
- Handles Telnet IAC/DO/terminal-type negotiation and sends `dumb` terminal type responses through Socket single-byte/string helpers.
- Uses `g_pConfig+0x2918f8` as a random/jitter gate during one branch of the S/C transition.
- Sends the final `baram` transport string, calls `SendPositionUpdate`, and closes the terminal pane once the login handoff is complete.

Rejected alternatives:

- Treating `this+0x1cc` as the full-object offset is misleading. The parser is called through an adjusted subobject; support docs should carry both adjusted and full-object offsets.
- Treating helper calls as Terminal-owned packet code is too broad. Use existing Socket helper names where support docs exist.

### `0x0058b470-0x0058b5e0`: `TerminalPane::OnDisconnect(...)`

Evidence:

- Exported as `sub_58B470`, size `0x170`, exclusive end `0x0058b5e0`.
- Vtable/data reference at `0x0062daa4`.
- Raw epilogue is `ret 0x0c`, so the binary virtual consumes three stack arguments.
- Adjusted receiver is `this+0xa4`; body computes the containing `TerminalPane`.
- Constructs alert text id `156`; may construct reconnect/leave alert text id `157`.
- Posts Socket event/close activity and session cleanup before displaying the reconnect prompt.
- Allocates a `0x18` callback object and installs a `PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>` vtable before binding callback target `0x0058b620`.

Best source-facing signature:

```cpp
int TerminalPane::OnDisconnect(int disconnectCode, int detail, int flags);
```

Notes:

- The exact names of the three stack parameters should remain descriptive rather than over-specific. The first significant disconnect parameter controls whether reconnect prompting occurs; its high byte is tested.
- Current simplified generated output that models a single parameter is incomplete because it misses `ret 0x0c`.

Behavior to incorporate:

- If the primary disconnect parameter indicates an actual disconnect, post Socket event 4 with current terminal serial config.
- Call the Socket event-backed disconnect request at `0x00574b30`.
- Call the current session/request cleanup helper at `0x00596760`.
- Close the current alert pane, then optionally create a `VersatileAlertPane` with `Reconnect` and `Leave` buttons.
- Bind `TerminalPane::OnReconnectOrLeave` as the alert callback.
- Return success/handled.

Rejected alternatives:

- Classifying this as a destructor/helper thunk: rejected by vtable slot, alert construction, Socket calls, and callback allocation.
- Collapsing it into the reconnect callback: rejected. `0x0058b470` creates the callback object; `0x0058b620` is the callback body.

### `0x0058b5e0-0x0058b5fc`: `TerminalPane::OnClose()`

Evidence:

- Exported as `sub_58B5E0`, size `0x1c`, exclusive end `0x0058b5fc`.
- Vtable/data reference at `0x0062da54`.
- Body calls `sub_4B9660(this, 0)`, clears byte at `this+0x70`, and invokes the invalidation callback at `dword_69B3FC(this, this+0x44)`.

Best source-facing signature:

```cpp
void TerminalPane::OnClose();
```

Behavior to incorporate:

- Hides or disables the pane.
- Clears the pane-visible/open flag at offset `+0x70`.
- Invalidates/redraws the pane rectangle at `+0x44`.

Rejected alternatives:

- Treating it as a destructor: rejected. It is a short close/visibility virtual and does not release ownership or clear `g_pTerminalPane`.

### `0x0058b620-0x0058b64f`: `TerminalPane::OnReconnectOrLeave(unsigned long decision)`

Evidence:

- Existing child `TerminalPaneReconnectLeaveCallback`.
- Xref from callback object construction at `0x0058b56d`.
- If the decision is nonzero, calls `0x005975e0(this+0xa4, 0, 0, 0, 0)`.
- If zero, calls `Application::RequestExit(g_pApplication)` at `0x00464e40`.

Best source-facing signature:

```cpp
int TerminalPane::OnReconnectOrLeave(unsigned long decision);
```

Alternative:

- `HandleReconnectLeaveDecision(unsigned long decision)` is readable, but callback/vtable support docs already point toward `OnReconnectOrLeave`.

Behavior to incorporate:

- `decision != 0`: reconnect/restart the terminal callback/timer path.
- `decision == 0`: leave the terminal flow by requesting application exit.

### `0x0058b650-0x0058c192`: `TerminalSetupPane::TerminalSetupPane(...)`

Evidence:

- Exported as `sub_58B650`, size `0xb42`, exclusive end `0x0058c192`.
- No code/data xrefs to the constructor were found in exported function records or local PE rel32/dword scans for `0x0058b650`.
- Raw epilogue indicates `ret 4`, so the binary pops one stack argument. No semantic use of that argument was found in the decompile evidence.
- Installs `TerminalSetupPane` vtables at primary/secondary offsets.
- Uses resource title `Terminal Setup`.
- Selects one of two layout branches based on `g_useEpfAssets`/`byte_66DA97`.
- EPF branch uses `DLGSETUP.EPF`/`DLGSETUP.PAL` and approximately `338x190` dialog dimensions.
- EPD branch uses `DLGSETUP.EPD`/`NPAL8.PAL` and approximately `407x210` dialog dimensions.
- Adds image buttons/control ids `14` and `22`.
- Builds terminal mode group, COM popup, and baud popup controls.
- COM entries are `COM1`, `COM2`, `COM3`, `COM4`.
- Baud entries are `9600`, `14400`, `19200`, `28800`, `38400`, `57600`.
- Seeds UI from `g_pConfig+0x28de28` and `g_pConfig+0x28de2c`.
- If configured COM port is outside `1..4`, disables COM/baud selection and treats the setup mode as no-COM/direct mode.
- Maps baud values to popup selections; fallback/default is `19200`.

Best source-facing signatures:

```cpp
TerminalSetupPane::TerminalSetupPane();
```

or, if the implementation wants ABI fidelity until the caller is recovered:

```cpp
explicit TerminalSetupPane::TerminalSetupPane(int unused);
```

Recommendation:

- Use `TerminalSetupPane::TerminalSetupPane()` in class/source prose as the source-facing declaration.
- Document the binary `ret 4` and the unused/legacy stack argument as a validator/IDA caveat.
- If a child first-draft C++ implementation is emitted before caller recovery, an `int unused` parameter with `(void)unused;` is safer for ABI commentary than silently ignoring the cleanup evidence.

Rejected alternatives:

- Treating the setup constructor as dead compiler residue: rejected. It is long source-authored UI construction with matching vtables and resource strings.
- Merging `TerminalSetupPane` into `TerminalPane` constructor: rejected by vtable/resource/control evidence and separate class docs.

### `0x0058c1a0-0x0058c23f`: `TerminalSetupPane::UpdateControlState()`

Evidence:

- Exported as `sub_58C1A0`, size `0x9f`, exclusive end `0x0058c23f`.
- Vtable/data reference at `0x0062daf8`.
- No stack arguments.
- Fetches controls with ids `3`, `4`, `5`, and `1`.

Best source-facing signature:

```cpp
void TerminalSetupPane::UpdateControlState();
```

Behavior to incorporate:

- Control id `3` is the mode/use-COM control.
- Control id `4` is the COM port popup.
- Control id `5` is the baud-rate popup.
- Control id `1` is the accept/OK command.
- If the mode/use-COM control is unchecked, disable COM/baud controls and enable OK.
- If it is checked, enable COM/baud and enable OK only when a COM port selection exists.

### `0x0058c240-0x0058c350`: `TerminalSetupPane::OnCommand(int commandId, int commandParam)`

Evidence:

- Exported as `sub_58C240`, size `0x110`, exclusive end `0x0058c350`.
- Vtable/data reference at `0x0062daf4`.
- Raw epilogue is `ret 8`, so two stack arguments are present; second is unused in current decompile.
- Command id `1` applies setup changes and closes.
- Command id `2` cancels/closes.

Best source-facing signature:

```cpp
void TerminalSetupPane::OnCommand(int commandId, int commandParam);
```

Behavior to incorporate:

- On command `1`, read mode/use-COM control id `3`, COM popup id `4`, and baud popup id `5`.
- If use-COM is unchecked, write `g_pConfig+0x28de28 = 5`.
- If use-COM is checked, write selected COM index + 1 to `g_pConfig+0x28de28`.
- Copy selected baud text via `StringMenuItemCopyText` (`0x00517070`) and parse it through the wide format helper at `0x004944f0` with `"%d"` into `g_pConfig+0x28de2c`.
- Calls `g_pTerminalPane` virtual slot `0x4c` after applying settings. Source-facing role is best documented as refresh/restart of terminal setup state until the exact virtual name is recovered.
- Calls Socket helper `0x00574b20`, which the Socket event helper doc identifies as a Socket reset/cleanup command. Do not name this `SendTerminalSetupPacket`.
- Persists/closes the setup pane through `0x0049eb90` and `0x0049dad0`.
- On command `2`, persist/close without modifying terminal config.

Rejected alternatives:

- `OnCommand(int)` with one arg is incomplete for ABI/source-quality docs because the raw epilogue is `ret 8`.
- `SendTerminalSetupPacket` for `0x00574b20` is rejected by the Socket helper family docs.

## Source placement and ownership

Recommended source placement:

- `NexusTK/login/TerminalPane.cpp` owns this aggregate and the source-authored TerminalPane/TerminalSetupPane methods listed above.
- `TerminalPane` and `TerminalSetupPane` should remain separate class docs but share the same source file.
- `Socket` helper calls should remain owned by Socket docs; Terminal docs should link to their existing helper names instead of creating Terminal-owned aliases.
- The rdata/vtable/string ranges should remain generated-binary/data docs under their current owners; do not emit source bodies from rdata.
- `PhoneBookDialog` owns `0x0058c350+` and should remain a successor boundary, not a child of `TerminalPaneAndSetup`.

Owner/emitter recommendation:

- Keep target `CANONICAL_OWNER:0000OI`.
- Keep target `EMITTER_UIDS:0000OI`.
- Child pages that are created for exact methods should also emit to `0000OI` unless the supervisor introduces a more granular file UID for setup-only code. There is not enough evidence to split `TerminalSetupPane` into a separate source file.

Rejected owner/source alternatives:

- Separate `TerminalSetupPane.cpp`: rejected for now. Existing by-file docs and contiguous code/resource layout support a shared `TerminalPane.cpp` route.
- `MainMenuPane` ownership: rejected except for callers/open helpers. The constructor and setup code are Terminal-owned.
- `PhoneBookDialog` ownership for any bytes before `0x0058c350`: rejected by range/function/vtable evidence.

## Field, global, helper, and type names

### Recommended class fields

For `TerminalPane`:

- `m_terminalParserState`: full-object offset `+0x26c`; adjusted parser-view offset `+0x1cc`.
- Existing pane/layout fields from `DialogPane` remain inherited and should not be renamed as Terminal-specific without separate evidence.

For `TerminalSetupPane`:

- No durable setup fields were proven in this pass beyond inherited dialog/control fields. Most state is stored directly in controls and `g_pConfig`.

### Recommended config fields

Add to `g_pConfig` support docs:

- `g_pConfig+0x28de28`: `terminalComPort` or `terminalConnectionMode`
  - Type: byte or small int field, accessed as byte in constructor/helper checks and as a config value in setup.
  - Values `1..4`: `COM1`..`COM4`.
  - Value `5`: no serial COM/direct/disabled mode written by setup when use-COM is unchecked.
  - Evidence: TerminalPane constructor, raw helper `0x0058b0f0`, TerminalSetupPane constructor, TerminalSetupPane `OnCommand`, startup parser docs.
  - Preferred name: `terminalComPort`.
  - Rejected name: `terminalModemMode` because the most direct UI strings are COM ports and the field is passed as the connect port.
- `g_pConfig+0x28de2c`: `terminalBaudRate`
  - Type: int.
  - Values observed in UI: `9600`, `14400`, `19200`, `28800`, `38400`, `57600`.
  - Default/fallback in setup UI: `19200`.
- `g_pConfig+0x2916ca`: `startupReadyFlag` or `launcherStartupReady`
  - Written by startup/authentication paths and `TerminalPane::TerminalPane`.
  - Read by `OpenTerminalPane` before terminal construction.
  - Do not name it only as a Terminal flag; the field participates in startup/authentication state.
- `g_pConfig+0x2918f8`: retain existing config field name if already established, but add that the terminal stream parser uses it as a random/jitter gate during the S/C transition.

### Recommended globals

- `dword_69BDF8`: `g_pTerminalPane`
  - Set by constructor.
  - Cleared by scalar deleting/destructor path.
  - Read by setup/phone/dial helpers.
- `dword_67A7C8`: `g_pConfig`
- `dword_67A7EC`: use existing Socket/global name from Socket docs, likely `g_packetSender`, for Socket helper calls.
- `g_pApplication`: used by reconnect/leave callback when choosing Leave/exit.

### Recommended helper names

Use existing support-doc names where available:

- `0x00574c20`: `PostSocketModeByteCommand`
- `0x00574c40`: `QueueTransportStringCommand`
- `0x00574cb0`: `SendSingleByteCommand`
- `0x00574cf0`: `SetSocketConnectionFlag`
- `0x00574d40`: `SendPositionUpdate`
- `0x00574b20`: Socket reset/cleanup command from `SocketEventDispatchHelpers`; do not call it `SendTerminalSetupPacket`.

Terminal-local names to recommend:

- `sub_58AF50`: `TerminalPane_ctor`
- `0x0058B0F0`: `TerminalPane_PostConfiguredTerminalConnectIfSerial_raw`
- `sub_58B130`: `TerminalPane_ParseTerminalStream`
- `sub_58B470`: `TerminalPane_OnDisconnect`
- `sub_58B5E0`: `TerminalPane_OnClose`
- `sub_58B620`: `TerminalPane_OnReconnectOrLeave`
- `sub_58B650`: `TerminalSetupPane_ctor`
- `sub_58C1A0`: `TerminalSetupPane_UpdateControlState`
- `sub_58C240`: `TerminalSetupPane_OnCommand`

### Recommended callback type

```cpp
PlainMemberFunctionObject<void (__thiscall TerminalPane::*)(unsigned long), TerminalPane>
```

This is supported by the callback rdata doc and the allocation/binding code in `OnDisconnect`.

### Recommended packet type

Use a provisional Socket receive packet type:

```cpp
struct SocketPacket {
    // ...
    unsigned char *data; // observed at +0x0c
    int length;          // observed at +0x10
};
```

If an existing project type has already been named in Socket docs, prefer that type. Otherwise, `SocketPacket` or `SocketReceivePacket` are both defensible; this report prefers `SocketPacket` because support docs already use Socket helper terminology.

## Vtable and generated-binary policy

TerminalPane vtable/rdata evidence:

- TerminalPane primary/secondary vtable data is documented under `0x0062da10-0x0062daac`.
- Parser slot reference at `0x0062da80` receives an adjusted TerminalPane subobject.
- Disconnect slot reference at `0x0062daa4` receives adjusted `this+0xa4`.
- OnClose slot reference at `0x0062da54`.

TerminalSetupPane vtable/rdata evidence:

- Setup vtable data is documented under `0x0062daac-0x0062db48`.
- `OnCommand` slot reference at `0x0062daf4`.
- `UpdateControlState` slot reference at `0x0062daf8`.

Generated-binary policy:

- Vtable/rdata docs should remain no-code generated-binary data docs.
- Adjustor thunks at `0x0058dc01-0x0058dc17` should remain `RECONSTRUCTABLE:FALSE` no-code compiler glue.
- Scalar deleting destructor wrapper at `0x0058dc60-0x0058dca5` should remain a generated wrapper/source-teardown bridge; source-level destructor behavior belongs in `TerminalPane::~TerminalPane`, not in the scalar deleting wrapper as user-authored code.

## C++ readiness and exact no-code/defer proof

### Aggregate-level formal C++

The parent aggregate `0001JB` should keep formal C++ blank.

Target-specific no-code/defer proof:

- The range includes at least eight source-authored methods across two classes plus one retained no-xref helper.
- Several methods already have or should have child pages.
- Emitting a parent C++ block would either duplicate child emissions or emit code outside a single source method's coverage.
- The aggregate has an exact successor boundary at `0x0058c350`, so a broad class/source file body here risks crossing into `PhoneBookDialog` if expanded carelessly.
- Rdata/vtable resources are non-contiguous support docs and should not be represented by aggregate code.
- The right implementation path is child method emission plus support-doc updates, not aggregate emission.

### Class declaration shape for support docs

This declaration is appropriate for `by-class/TerminalPane.md` and `by-class/TerminalSetupPane.md` after implementation review, not for the aggregate's formal C++ block:

```cpp
class TerminalPane : public DialogPane
{
public:
    TerminalPane();
    virtual ~TerminalPane();

    virtual void OnClose();
    virtual int OnDisconnect(int disconnectCode, int detail, int flags);
    virtual char ParseTerminalStream(SocketPacket *packet);

private:
    int OnReconnectOrLeave(unsigned long decision);
    unsigned int m_terminalParserState;
};

class TerminalSetupPane : public DialogPane
{
public:
    TerminalSetupPane();
    explicit TerminalSetupPane(int unused); // ABI-safe form if caller recovery requires ret-4 fidelity.

    virtual void OnCommand(int commandId, int commandParam);
    virtual void UpdateControlState();
};
```

### First-draft child snippets

These are implementation-ready as child-scoped drafts, not as aggregate code.

`TerminalPane::OnClose()`:

```cpp
void TerminalPane::OnClose()
{
    SetVisible(false);
    m_visible = false;
    InvalidateRect(&m_clientRect);
}
```

`TerminalPane::OnReconnectOrLeave(unsigned long decision)`:

```cpp
int TerminalPane::OnReconnectOrLeave(unsigned long decision)
{
    if (decision != 0)
        return StartTerminalReconnectTimer(0, 0, 0, 0);

    return g_pApplication->RequestExit();
}
```

`TerminalSetupPane::UpdateControlState()`:

```cpp
void TerminalSetupPane::UpdateControlState()
{
    DialogControlHost *host = GetControlHost();
    ToggleControlPane *useCom = static_cast<ToggleControlPane *>(host->GetControl(3));
    PopupMenuControlPane *comPort = static_cast<PopupMenuControlPane *>(host->GetControl(4));
    PopupMenuControlPane *baudRate = static_cast<PopupMenuControlPane *>(host->GetControl(5));
    ControlPane *ok = host->GetControl(1);

    if (!useCom->IsChecked()) {
        comPort->Enable(false);
        baudRate->Enable(false);
        ok->Enable(true);
        return;
    }

    comPort->Enable(true);
    baudRate->Enable(true);
    ok->Enable(comPort->GetSelectedIndex() != -1);
}
```

`TerminalSetupPane::OnCommand(int commandId, int commandParam)`:

```cpp
void TerminalSetupPane::OnCommand(int commandId, int commandParam)
{
    (void)commandParam;

    if (commandId == 1) {
        DialogControlHost *host = GetControlHost();
        ToggleControlPane *useCom = static_cast<ToggleControlPane *>(host->GetControl(3));
        PopupMenuControlPane *comPort = static_cast<PopupMenuControlPane *>(host->GetControl(4));
        PopupMenuControlPane *baudRate = static_cast<PopupMenuControlPane *>(host->GetControl(5));

        if (!useCom->IsChecked()) {
            g_pConfig->terminalComPort = 5;
        } else {
            g_pConfig->terminalComPort = comPort->GetSelectedIndex() + 1;

            wchar_t text[32];
            baudRate->CopySelectedItemText(text, sizeof(text) / sizeof(text[0]));
            swscanf(text, L"%d", &g_pConfig->terminalBaudRate);
        }

        if (g_pTerminalPane != 0)
            g_pTerminalPane->RefreshTerminalSetup();

        g_packetSender->PostResetConnectionCommand();
        SaveDialogPlacement();
        Close();
        return;
    }

    if (commandId == 2) {
        SaveDialogPlacement();
        Close();
    }
}
```

`TerminalPane::TerminalPane()` is first-draft feasible as a child after the exact constructor child is created:

```cpp
TerminalPane::TerminalPane()
    : DialogPane(L"", -1, 0),
      m_terminalParserState(0)
{
    g_pTerminalPane = this;

    Hide();
    MoveToFullClientArea();

    PostSocketModeByteCommand(g_packetSender, 1);
    ResetStartupSessionState();

    if (g_pConfig->terminalComPort >= 1 && g_pConfig->terminalComPort <= 4) {
        g_packetSender->PostSerialConnect(g_pConfig->terminalComPort, g_pConfig->terminalBaudRate);
        QueueTransportStringCommand(g_packetSender, "ATZ\n\r");
    }

    g_pConfig->startupReadyFlag = 1;

    if (g_pConfig->startupReadyFlag)
        StartTerminalReconnectTimer(0, 0, 0, 0);

    AttachToApplicationPaneList();
}
```

Implementation note: the constructor snippet expresses source shape only. Exact helper names for `ResetStartupSessionState`, `MoveToFullClientArea`, `PostSerialConnect`, `StartTerminalReconnectTimer`, and `AttachToApplicationPaneList` must use the names accepted by their support docs during implementation.

`TerminalPane::OnDisconnect(...)` is first-draft feasible once the event-parameter names are accepted:

```cpp
int TerminalPane::OnDisconnect(int disconnectCode, int detail, int flags)
{
    (void)detail;

    if (disconnectCode != 0) {
        SocketPostTerminalDisconnectEvent(g_pConfig->terminalComPort, g_pConfig->terminalBaudRate);
        g_packetSender->PostDisconnectRequest();
        ResetStartupSessionAfterDisconnect();
        CloseCurrentAlert();

        if ((flags & 0xff00) == 0) {
            ShowReconnectLeaveAlert(
                LoadString(157),
                new PlainMemberFunctionObject<TerminalPane, unsigned long>(
                    this,
                    &TerminalPane::OnReconnectOrLeave));
        }
    }

    return 1;
}
```

`TerminalPane::ParseTerminalStream(SocketPacket *packet)` is also first-draft feasible as a child, but should not be emitted from this aggregate. Use the existing stream parser child page and include full behavior: byte scan, BEL/ESC handling, `%I\n</RunRegistry=` recognition, Telnet IAC/DO/TTYPE negotiation, `dumb` response, `baram` handoff, `SendPositionUpdate`, and close.

## Open questions and closure status

### Is `TerminalSetupPane` active or retained?

Conclusion: retained/source-authored setup dialog code with unresolved route.

Evidence checked:

- Exported xrefs show no code/data caller for `0x0058b650`.
- Local PE rel32 and dword scans found no direct refs to the constructor entry.
- Vtable and resource docs strongly identify the class and UI.
- The constructor/update/command methods are contiguous and coherent.

Why this is not a passive blocker:

- Source name, class placement, UI behavior, config fields, and first-draft child readiness are still high-confidence.
- The route should be documented as “no direct xrefs found; likely legacy/retained setup dialog entrypoint” rather than leaving the class unresolved.

### What is the exact source signature of `TerminalSetupPane::TerminalSetupPane`?

Conclusion: source-facing constructor is `TerminalSetupPane::TerminalSetupPane()`, but binary ABI evidence requires documenting an unused `ret 4` argument.

Evidence checked:

- Decompile and raw epilogue.
- No caller recovered, so the argument cannot be named semantically.

Best implementation direction:

- Prose/class docs can show the source-facing no-arg constructor.
- A first-draft child C++ block can use `explicit TerminalSetupPane(int unused)` if the implementer wants to preserve the binary evidence until caller recovery.

### What is `0x0058b0f0`?

Conclusion: retained no-xref terminal configured-connect helper.

Evidence checked:

- Direct PE bytes.
- Local direct ref scans.
- Socket helper docs.
- Constructor duplicated logic.

Best direction:

- Add it to target/support docs as a missing raw helper.
- Optional later child page: `by-memory/0x0058b0f0-0x0058b12c.TerminalPaneConfiguredConnectHelperRaw.md`.

### Should `0x0058b130-0x0058b44b` child path be renamed to `...0x0058b44c...`?

Conclusion: the exact exclusive end is `0x0058b44c`; filename normalization is optional supervisor policy.

Evidence checked:

- Exported function size/end.
- Raw bytes at the end of parser.

Best direction:

- At minimum, update prose to state `0x0058b130-0x0058b44c` half-open.
- If the supervisor permits path repair, rename the child doc to the half-open exclusive end. Do not do this during a B report-only pass.

### Is `PhoneBookDialog` part of this aggregate?

Conclusion: no.

Evidence checked:

- `PhoneBookDialog` by-file/class docs.
- `TerminalPhoneReadOnlyData` boundary docs.
- Raw function start at `0x0058c350`.

Best direction:

- Keep `0x0058c350+` in PhoneBook docs.
- Mention `0x0058c350` as immediate successor boundary in the target.

## Recommended exact doc/support changes

### Primary target: `by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`

Implement these changes:

- Update score to `COMPLETION:87`, `CONFIDENCE:88`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep owner/emitter `0000OI`.
- Replace the old “blank because 90/90+ active gate” explanation with target-specific no-code/defer proof:
  - multi-method, two-class aggregate;
  - child pages should emit exact methods;
  - parent aggregate should remain a source-quality map;
  - emitting here would duplicate child output and risk scope overrun.
- Add exact split table from this report.
- Add missing raw helper `0x0058b0f0-0x0058b12c`.
- State `0x0058b130` parser exclusive end as `0x0058b44c`.
- Add `OnDisconnect` raw `ret 0x0c` signature caveat.
- Add `TerminalSetupPane::OnCommand` raw `ret 8` signature caveat.
- Add `TerminalSetupPane` constructor `ret 4` unused/legacy arg caveat and no-direct-xref evidence.
- Add source-facing field names:
  - `g_pConfig+0x28de28` = `terminalComPort`
  - `g_pConfig+0x28de2c` = `terminalBaudRate`
  - `g_pConfig+0x2916ca` = `startupReadyFlag`/`launcherStartupReady`
  - `TerminalPane+0x26c` = `m_terminalParserState`
- Add Socket helper names and rejected stale helper names, especially `0x00574b20` not being a Terminal setup packet.
- Add `PhoneBookDialog` successor boundary.

### `by-file/TerminalPane.md`

Add/update:

- Exact child/split map.
- `0x0058b0f0-0x0058b12c` retained no-xref configured-connect helper.
- Shared source placement for `TerminalPane` and `TerminalSetupPane`.
- Terminal serial config fields and control ids.
- Socket helper dependency names.
- Setup constructor no-direct-xref/ret-4 caveat.
- First-draft child emission policy: exact method children should emit; aggregate should not.

### `by-class/TerminalPane.md`

Add/update:

- Class declaration shape from this report.
- `m_terminalParserState` at full-object `+0x26c`, adjusted parser-view `+0x1cc`.
- Method inventory:
  - `TerminalPane::TerminalPane()`
  - retained `PostConfiguredTerminalConnectIfSerial` helper at `0x0058b0f0`
  - `ParseTerminalStream(SocketPacket *)`
  - `OnDisconnect(int,int,int)`
  - `OnClose()`
  - `OnReconnectOrLeave(unsigned long)`
  - destructor/scalar deleting destructor support route
- Callback type.
- Socket helper names.
- Rejected alternatives for parser offset and stale single-arg `OnDisconnect`.

### `by-class/TerminalSetupPane.md`

Add/update:

- Class declaration shape from this report.
- Constructor retained/no-direct-xref evidence.
- Constructor raw `ret 4` unused arg caveat.
- Control ids:
  - `1` OK/apply
  - `2` cancel
  - `3` use-COM/mode toggle
  - `4` COM port popup
  - `5` baud popup
  - `14` and `22` image buttons
- Resource/layout branches:
  - EPF: `DLGSETUP.EPF`/`DLGSETUP.PAL`, `338x190`
  - EPD: `DLGSETUP.EPD`/`NPAL8.PAL`, `407x210`
- COM and baud values.
- Config writes to `terminalComPort` and `terminalBaudRate`.
- `OnCommand(int,int)` raw `ret 8` caveat.
- Reject `SendTerminalSetupPacket` for `0x00574b20`; use Socket reset/cleanup naming.

### `by-global/g_pTerminalPane.md`

Add/update:

- Constructor set at `0x0058af50`.
- Destructor/scalar deleting route clears the global.
- Setup command calls through `g_pTerminalPane` virtual slot `0x4c` after applying terminal serial settings.
- Phone/dial helpers read the singleton but do not own it.

### `by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md`

Add/update:

- State exact exclusive end `0x0058b44c`.
- Source-facing name/signature `TerminalPane::ParseTerminalStream(SocketPacket *packet)`.
- Packet fields `+0x0c` data pointer and `+0x10` length.
- Parser state field full-object `+0x26c`, adjusted `+0x1cc`.
- Socket helper names for Telnet response and final handoff.
- First-draft child C++ readiness.

### `by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`

Add/update:

- Source-facing signature `TerminalPane::OnReconnectOrLeave(unsigned long decision)`.
- Callback type from this report.
- First-draft child C++ readiness.

### `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

Add/update:

- `+0x28de28` `terminalComPort` / terminal connection mode, values `1..4` COM ports and `5` no-COM/direct mode.
- `+0x28de2c` `terminalBaudRate`, integer values from setup UI.
- `+0x2916ca` `startupReadyFlag`/`launcherStartupReady`.
- `+0x2918f8` terminal parser random/jitter gate usage if not already captured.

### `by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`

Add/update:

- Note `ATZ\n\r` is referenced by both constructor configured-connect logic and retained raw helper `0x0058b0f0`.
- Keep callback/parser rdata generated-binary/no-code.

### `by-memory/0x0062de34-0x0062dee8.TerminalSetupPaneResourceStrings.md`

Add/update:

- Note IDA label split around `Terminal Setup` is a label artifact; source string is the title.
- Link COM/baud strings to `TerminalSetupPane` constructor and command/update semantics.

### `by-file/PhoneBookDialog.md`, `by-class/PhoneBookDialog.md`, and PhoneBook memory docs

Add/update:

- Reinforce `0x0058c350` as the exact successor boundary after TerminalSetupPane `OnCommand`.
- Do not merge `PhoneBookDialog` into `TerminalPaneAndSetup`.

### Socket helper docs

No direct edits are required for correctness, but Terminal docs should reference these existing Socket helper docs instead of inventing local names. If any Terminal support doc currently says `SendTerminalSetupPacket` for `0x00574b20`, replace it with the Socket reset/cleanup command naming from `SocketEventDispatchHelpers`.

## IDA rename/type/comment recommendations

High confidence:

- Rename `sub_58AF50` to `TerminalPane_ctor`.
- Define/comment `dword_69BDF8` as `g_pTerminalPane`.
- Rename `sub_58B130` to `TerminalPane_ParseTerminalStream`.
- Rename `sub_58B470` to `TerminalPane_OnDisconnect`.
- Rename `sub_58B5E0` to `TerminalPane_OnClose`.
- Rename `sub_58B620` to `TerminalPane_OnReconnectOrLeave`.
- Rename `sub_58B650` to `TerminalSetupPane_ctor`.
- Rename `sub_58C1A0` to `TerminalSetupPane_UpdateControlState`.
- Rename `sub_58C240` to `TerminalSetupPane_OnCommand`.

Medium/high confidence:

- Add function at `0x0058B0F0` if IDA missed it; name it `TerminalPane_PostConfiguredTerminalConnectIfSerial_raw`.
- Comment it: “No direct refs found; reads `g_pConfig->terminalComPort/terminalBaudRate`; posts Socket serial connect and queues `ATZ\n\r`; retained TerminalPane.cpp helper candidate.”

Type/comment recommendations:

- `g_pConfig+0x28de28`: `terminalComPort`, values `1..4` = COM1-COM4, `5` = no-COM/direct mode.
- `g_pConfig+0x28de2c`: `terminalBaudRate`.
- `g_pConfig+0x2916ca`: `startupReadyFlag`/`launcherStartupReady`.
- `g_pConfig+0x2918f8`: terminal parser random/jitter gate.
- TerminalPane parser state: full-object `+0x26c`, adjusted parser receiver `+0x1cc`.
- Parser packet: data pointer at `+0x0c`, length at `+0x10`.
- Vtable comments:
  - `0x0062da80` TerminalPane stream parser adjusted receiver.
  - `0x0062daa4` TerminalPane disconnect callback, raw `ret 0x0c`.
  - `0x0062daf4` TerminalSetupPane command callback, raw `ret 8`.
  - `0x0062daf8` TerminalSetupPane update-control-state callback.
- Rdata comment at `0x0062de34`: one UTF-16 `Terminal Setup` title string despite current label split.

## Score and metadata recommendation

Recommended target metadata:

```yaml
COMPLETION:87
CONFIDENCE:88
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000OI
EMITTER_UIDS:0000OI
```

Rationale:

- Positive: exact boundary/split map is now stronger, missing raw helper identified, config fields named, Socket helper ownership clarified, parser/callback/setup command signatures improved, and PhoneBook successor boundary verified.
- Remaining limits: local IDA MCP unavailable, setup constructor direct route remains unresolved, raw helper has no direct caller, and exact UI helper names for several non-Terminal callees still need support-doc validation before method C++ emission.
- Therefore `87/88` is a fair improvement but not a jump to high-90s.

## Exact coverage row replacement

Do not edit `by-memory/-coverage-report.md` during this B report. If supervisor accepts implementation, replace the current `0001JB` row with:

```text
    - [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md) : reconstructable : 87% : strong : B006 source-quality pass resolves the TerminalPane/TerminalSetupPane aggregate as a no-code child-emission map under `TerminalPane.cpp`, adds exact IDA-exclusive method boundaries plus the retained no-xref `0x0058b0f0` configured-connect helper, ties terminal serial fields to `g_pConfig+0x28de28/+0x28de2c`, confirms parser/callback/vtable/singleton/resource evidence and the `PhoneBookDialog` successor boundary, and recommends exact child split pages for first-draft method C++.
```

## Exact implementation checklist for callback

If the supervisor sends an implementation callback, apply these changes:

1. Update `source-3/project-documentation/by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md`.
   - Score to `87/88`.
   - Add the no-code/defer proof.
   - Add exact split map.
   - Add missing raw helper `0x0058b0f0-0x0058b12c`.
   - Add field/helper/signature conclusions and rejected alternatives.
   - Keep formal C++ blank.

2. Update `source-3/project-documentation/by-file/TerminalPane.md`.
   - Add same split model.
   - Add source placement and child emission policy.
   - Add config and Socket helper names.
   - Add setup constructor retained/no-route caveat.

3. Update `source-3/project-documentation/by-class/TerminalPane.md`.
   - Add class declaration shape and method inventory.
   - Add parser state field, callback type, and Socket helper names.

4. Update `source-3/project-documentation/by-class/TerminalSetupPane.md`.
   - Add class declaration shape, constructor route caveat, setup UI controls/resources, config fields, command semantics, and first-draft child readiness.

5. Update `source-3/project-documentation/by-global/g_pTerminalPane.md`.
   - Add constructor/set and setup command callback use if not already present.

6. Update `source-3/project-documentation/by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md`.
   - Add exclusive-end correction and source-quality signature/field names.
   - Do not rename the file unless supervisor explicitly approves path normalization.

7. Update `source-3/project-documentation/by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md`.
   - Add source signature and first-draft readiness.

8. Update `source-3/project-documentation/by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`.
   - Add terminal serial fields and startup flag details.

9. Update rdata/resource support docs:
   - `source-3/project-documentation/by-memory/0x0062dddc-0x0062de34.TerminalPaneModemCallbackAndParserData.md`
   - `source-3/project-documentation/by-memory/0x0062de34-0x0062dee8.TerminalSetupPaneResourceStrings.md`
   - `source-3/project-documentation/by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`

10. Update PhoneBook support docs only to reinforce boundary:
    - `source-3/project-documentation/by-file/PhoneBookDialog.md`
    - `source-3/project-documentation/by-class/PhoneBookDialog.md`

11. Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` unless supervisor explicitly owns/schedules that step. Use the exact replacement row above.

12. Optional later child creation, if supervisor wants exact method emission:
    - `by-memory/0x0058af50-0x0058b0ee.TerminalPaneConstructor.md`
    - `by-memory/0x0058b0f0-0x0058b12c.TerminalPaneConfiguredConnectHelperRaw.md`
    - `by-memory/0x0058b470-0x0058b5e0.TerminalPaneOnDisconnect.md`
    - `by-memory/0x0058b5e0-0x0058b5fc.TerminalPaneOnClose.md`
    - `by-memory/0x0058b650-0x0058c192.TerminalSetupPaneConstructor.md`
    - `by-memory/0x0058c1a0-0x0058c23f.TerminalSetupPaneUpdateControlState.md`
    - `by-memory/0x0058c240-0x0058c350.TerminalSetupPaneOnCommand.md`

## Validation commands

Run after implementation from `source-3/project-documentation` using scoped validator file mode:

> Executable block R001 was removed from this report and preserved verbatim in [0001JB-TerminalPaneAndSetup-source-quality-removed.md](0001JB-TerminalPaneAndSetup-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional child pages are created, validate each new child path with the same `--file ... --apply --queue-timeout 240` form.

Expected validation result:

- Target and support pages pass metadata/coverage-link validation.
- Formal C++ remains blank only for the aggregate and generated-binary support docs with explicit no-code/defer proof.
- No duplicate emission warnings between aggregate and child method docs.
- No coverage edit is required unless supervisor separately applies the replacement row.

## Final status

FINISHED

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0001JB-TerminalPaneAndSetup-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001JB-TerminalPaneAndSetup-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0001JB"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001JB-TerminalPaneAndSetup-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001JB-TerminalPaneAndSetup-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001JB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
