** TARGET-REPORT-UID:0002QT **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002QT CreateUserDialogPaneCore Source-Quality Research


Assignment: `B008-implement-0002QT-create-user-dialog-pane-core-split-20260626`  
Agent: `Agent-B008`  
Mode: implementation callback applied. Target/support by-* docs were updated from the accepted report, exact children were created, scoped validators passed, and leases were released. No manual generated/project-level/coverage/tool-state/IDA database edits were made.  
Current target: [UID:0002QT] `by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md`  
Required report path: `tools/leaser/Agents/Agent-B008/research/0002QT-CreateUserDialogPaneCore-source-quality.md`

## Executive Conclusion

The current [UID:0002QT] monolithic emitting C++ should not be kept as-is. Live IDA MCP evidence confirms the old `CreateUserDialogPane` route and most existing source-shape names, but it also proves that the current aggregate formal C++ is materially unsafe: it omits the constructor and several hidden raw bodies, scopes a file-local packet helper as a class method, adds preview refresh/invalidation side effects that are not in several small helpers, reads the reply packet from the wrong byte offset, and treats the post-reply jump-table gap as padding.

Recommended implementation after supervisor acceptance:

| Field | Current [UID:0002QT] | Recommended |
| --- | --- | --- |
| `COMPLETION` | `88` | `90` |
| `CONFIDENCE` | `89` | `90` |
| `CANONICAL_OWNER` | `00003B` | `0000IJ` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `00003B` | blank |
| C++ body | broad aggregate method block | blank parent block; exact child ranges carry their own reconstruction/no-code state; every source-authored child selected for creation has exact formal C++ below |
| Range | `0x0052dd30-0x0052f6e5` | repair to `0x0052dd30-0x0052f710` if accepted |
| `Nested` | absent/current aggregate | `22` |

The owner change is for the split/index parent only. This revised report recommends creating every exact child range now. Source-authored class methods route to [UID:00003B] `CreateUserDialogPane`; the file-local account packet helper routes to [UID:0000IJ] `CreateUserDialogPane.cpp`; compiler/generated/no-route spans are non-reconstructable no-code children. The current revision resolves the rejected non-emitting source-child disposition for the constructor, dispatcher, submit path, account helper, character helper, reply handler, opener, and base bridges: each source-authored child now has a nonblank emitter route and exact formal C++ insertion text below.

The parent score can move to `90/90` only because this revision pairs the complete split/range map with implementation-ready child C++ for every source-authored range and target-specific no-code proof for every raw/null/switch span. The parent remains non-emitting; the score is not based on a monolithic rewrite.

## Files And Evidence Read

Direct target/support docs read or rechecked:

| Item | Use |
| --- | --- |
| `tools/leaser/Agents/Agent-B008/goal.md` | Assignment id, report-only mode, target, report path, MCP requirement, and no-edit rules. |
| `by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md` | Current `88/89`, owner/emitter `00003B`, reconstructable aggregate formal C++ and prior B004/B005/B007/B009/B010 notes. |
| `by-class/CreateUserDialogPane.md` | Class declaration, fields, method inventory, owner route, vtable/singleton links, and stale source-quality caps. |
| `by-file/CreateUserDialogPane.md` | Concrete old-dialog source root and current statement that [UID:0002QT] is the only method-body emitter. |
| `by-file/CreateUserDialogs.md` | Non-emitting create-user family/index role; sibling source-file placement. |
| `by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md` | Family split/index precedent and sibling boundaries. |
| `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md` | Executed local precedent: broad mixed aggregate converted to non-emitting split index with `Nested:21`. |
| `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md` | Retained/newer sibling route, separate owner [UID:00008Z], and non-collapse evidence. |
| `by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md` | Successor lifecycle island; boundary statement that currently treats preceding bytes as padding. |
| `by-memory/0x0061fe3c-0x0061fed8.CreateUserDialogPaneVtableData.md` | Vtable bases, secondary/tertiary slot evidence, and class route. |
| `by-memory/0x0069b890-0x0069b894.CreateUserDialogPaneSingletonSlot.md` | Old-dialog singleton slot references. |
| `by-file/UserCreateAppearanceControls.md` | Hair/face/preview/color-list support ownership, confirming `CreateUserDialogPane` owns coordinator/callback methods only. |
| `by-file/Event.md`, `by-class/Event.md`, `by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md`, `by-memory/0x0052b910-0x0052b936.NewUserDialogPane2HandleCreateUserPacketEvent.md` | Event-family and sibling packet/key-handler source-shape precedents used for the narrow recheck of `OnKeyEvent` and `OnCreateUserReplyEvent`. |
| `auto-generated/NexusTK/ui/dialogs/OptionPane.cpp`, `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, `auto-generated/NexusTK/ui/panels/CollectionPane.cpp`, `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` | Read-only generated-source precedents for `PacketEvent::payload`, `KeyEvent *event`, and sibling create-user packet bridge shape. |
| `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/NexusTK/login/CreateUserDialogPane.cpp` | Read-only stale generated/tracker comparison. These were not edited. |

Prior B-agent report conclusions from B004/B005/B007/B009/B010 were treated as leads and revalidated against current IDA MCP evidence instead of being accepted on fallback-only authority.

## Current IDA MCP Session

IDA MCP was available and used. No IDA DB edits were made.

| Evidence | Result |
| --- | --- |
| MCP endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` 1.0.0 |
| Active database | Session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module/input | `NexusTK.exe`, imagebase `0x400000`; input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Health | `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`; later health recheck after a broad text-search timeout remained `status:ok`. |

One optional broad `search_text` query timed out. This was not treated as MCP failure because immediate `server_health` rechecks succeeded and narrow `lookup_funcs`, `xrefs_to`, `find_bytes`, `insn_query`, `callees`, `analyze_component`, string/byte, and decompiler-backed calls completed afterward.

Numeric conversions used for size/offset reporting were verified with `tools/int_convert.py`.

## Current Target State

[UID:0002QT] currently has:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `89` |
| `CANONICAL_OWNER` | `00003B` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00003B` |
| Formal C++ | populated aggregate block |

The current formal C++ begins at `SelectBodyShape` and omits the constructor, hidden raw bodies, and the post-reply jump table. It also includes first-draft assumptions from older passes that current MCP disproves.

## Function Map And Boundary Evidence

Live `lookup_funcs` gives this exact modeled map. Decimal sizes are verified with `int_convert.py`.

| Range | IDA name/status | Size | Disposition |
| --- | --- | ---: | --- |
| `0x0052dd30-0x0052e6eb` | `sub_52DD30` | `0x9bb` / 2491 | constructor, source method |
| `0x0052e6eb-0x0052e6f0` | alignment | 5 bytes | padding |
| `0x0052e6f0-0x0052e72a` | not a function | `0x3a` / 58 | unmodeled constructor cleanup/fallback body; no direct route |
| `0x0052e72a-0x0052e730` | alignment | 6 bytes | padding |
| `0x0052e730-0x0052e744` | not a function | `0x14` / 20 | unmodeled preview-direction raw helper; no direct route |
| `0x0052e744-0x0052e750` | alignment | 12 bytes | padding |
| `0x0052e750-0x0052e75e` | not a function | `0x0e` / 14 | unmodeled raw setter for `+0x26c`; no direct route |
| `0x0052e75e-0x0052e770` | alignment | 18 bytes | padding |
| `0x0052e770-0x0052e832` | `sub_52E770` | `0xc2` / 194 | `SelectBodyShape` |
| `0x0052e840-0x0052e843` | `nullsub_43` | `0x3` / 3 | no-route nullsub, `retn 4` |
| `0x0052e850-0x0052e8b7` | `sub_52E850` | `0x67` / 103 | `SelectMale` |
| `0x0052e8c0-0x0052e927` | `sub_52E8C0` | `0x67` / 103 | `SelectFemale` |
| `0x0052e930-0x0052e94f` | `sub_52E930` | `0x1f` / 31 | hair color setter |
| `0x0052e950-0x0052e96f` | `sub_52E950` | `0x1f` / 31 | face color setter |
| `0x0052e970-0x0052ea44` | `sub_52E970` | `0xd4` / 212 | optional Nexonclub helper; no direct xrefs |
| `0x0052ea50-0x0052ea7c` | `sub_52EA50` | `0x2c` / 44 | Nexonclub callback |
| `0x0052ea80-0x0052ec80` | `sub_52EA80` | `0x200` / 512 | command dispatcher |
| `0x0052ecc0-0x0052ecc9` | `sub_52ECC0` | `0x9` / 9 | key-event bridge |
| `0x0052ecd0-0x0052ecf6` | `sub_52ECD0` | `0x26` / 38 | create-user reply event bridge |
| `0x0052ed00-0x0052ed09` | `sub_52ED00` | `0x9` / 9 | show/open bridge |
| `0x0052ed10-0x0052ed11` | `nullsub_44` | `0x1` / 1 | no-route nullsub, `retn` |
| `0x0052ed80-0x0052ef4c` | `sub_52ED80` | `0x1cc` / 460 | submit/validate |
| `0x0052ef50-0x0052f155` | `sub_52EF50` | `0x205` / 517 | file-local account packet helper |
| `0x0052f160-0x0052f38d` | `sub_52F160` | `0x22d` / 557 | character packet helper |
| `0x0052f390-0x0052f6e5` | `sub_52F390` | `0x355` / 853 | reply handler |
| `0x0052f6e5-0x0052f710` | data/alignment | `0x2b` / 43 | reply-handler switch table at `0x0052f6e8`, then padding |
| `0x0052f710` | next modeled lifecycle helper | `0x0b` / 11 | [UID:0002QU] successor |

Target nominal length `0x0052f6e5 - 0x0052dd30` is `0x19b5` / 6581 bytes, verified with `int_convert.py`. If accepted, the source-quality range should extend to the next child boundary at `0x0052f710` so the compiler switch table is not left as undocumented padding.

Boundary proof:

- `lookup_funcs` reports no function at `0x0052f6e5`; the next modeled function starts at `0x0052f710`.
- `insn_query 0x0052f6e5-0x0052f710` shows alignment at `0x0052f6e5`, a `dd offset loc_52F426` jump table beginning at `0x0052f6e8`, then `0xcc` alignment before `0x0052f710`.
- [UID:0002QU] correctly begins at `0x0052f710`; it should not absorb the preceding reply switch table.

## Constructor, Vtable, Singleton, And Sibling Evidence

Positive source route evidence:

- Constructor `0x0052dd30` has callers at `0x004f7a82` in `sub_4F7A10` and `0x004f8ff8` in [UID:00019P] `OpenCreateUserDialog`.
- Constructor callees include dialog setup, `SimpleUString` init, `time`, `srand`, `rand`, rectangle helper `0x004b7c50`, allocator `0x004f4aa0`, DLG background `0x004991f0`, old appearance controls, local `SelectBodyShape`, `SelectMale`, and `SelectFemale`.
- Vtable bases `0x0061fe3c`, `0x0061fe9c`, and `0x0061fecc` have references from constructor stores at `0x0052dda2`, `0x0052dda8`, and `0x0052ddb2`; cleanup/fallback stores at `0x0052e6f9`, `0x0052e6ff`, and `0x0052e709`; and destructor/scalar-deleting paths at `0x0052f80c`, `0x0052f812`, and `0x0052f81c`.
- The successor vtable data at `0x0061fed8` is only referenced by `NewUserDialogPane2` constructor code, confirming the sibling boundary.
- Singleton slot [UID:0002B3] `0x0069b890` is referenced at `0x0052dd87`, `0x0052dd8e`, `0x0052e71a`, `0x0052f710`, and `0x0052f82d`; constructor, cleanup, singleton-clear, and scalar-deleting paths agree on the same old-dialog singleton.
- [UID:0002QS] remains the separate retained/newer `NewCreateUserDialogPane` branch, and [UID:0002QR] remains the alternate `NewUserDialogPane2` branch. Current MCP evidence does not collapse these siblings.

Negative/source-quality evidence:

- `0x0052e970` has zero direct xrefs; its body is coherent and its callback object targets `0x0052ea50`, but the exact original helper spelling remains inferred.
- `0x0052e6f0`, `0x0052e730`, and `0x0052e750` have no modeled function records, no incoming xrefs, and no VA/RVA pointer byte-pattern hits for their starts.
- `0x0052e840` and `0x0052ed10` have no xrefs and no VA/RVA pointer byte-pattern hits. `insn_query` confirms `0x0052e840` is only `retn 4` and `0x0052ed10` is only `retn`; they should be documented as no-route nullsubs unless future evidence proves a virtual table route.

## Raw And Hidden Body Evidence

The current aggregate target treats the bytes between constructor and `SelectBodyShape` as if they were just gaps. Current MCP disproves that.

| Range | Body evidence | Recommended source-quality disposition |
| --- | --- | --- |
| `0x0052e6f0-0x0052e72a` | Starts `push esi; mov esi, ecx; lea ecx, [esi+27Ch]`; stores the three `CreateUserDialogPane` vtables, destroys `m_createUserExtraText`, clears singleton `unk_69B890`, then tail-jumps to a base teardown helper. | Non-emitting no-code child: constructor cleanup/fallback/lifecycle body, not hand-authored method C++. |
| `0x0052e730-0x0052e744` | Fetches child control id `18` through inherited manager at `+0x1fc`, loads the child vtable/receiver, then tail-jumps to `UserCreatePreviewControlPane::AdvanceDirection` at `0x00501d50`. | Non-emitting no-code child unless a direct source route is later found; document as raw preview-direction helper. |
| `0x0052e750-0x0052e75e` | `movsx eax, word ptr [ebp+8]`; writes `eax` to `[ecx+0x26c]`; `retn 4`. | Non-emitting no-route raw setter child. This changes `+0x26c` from "constructor-only write" to "written by constructor/raw setter, still no read evidence." |

`+0x26c` is offset 620 decimal, `+0x270` is 624, `+0x278` is 632, `+0x279` is 633, `+0x27c` is 636, and inherited control manager `+0x1fc` is 508; these conversions were verified with `int_convert.py`.

## Method Behavior Revalidation

Current MCP decompilation supports these corrections to the old aggregate C++.

### Selection And Color Helpers

- `SelectBodyShape` gets controls 10-13 through inherited child/control manager at `+0x1fc`, toggles the previous `m_bodyShapeIndex` button false, stores the new index at `+0x270`, toggles the new button true, and sets label/control 14 to `g_pLanguageMan->GetString(bodyShapeIndex + 212)`.
- `SelectMale` sets `m_isFemale` at `+0x279` to 0, toggles controls 4/5, calls hair helper `0x00501620`, writes face selector gender byte `+0x10c` to 0, and invalidates the face selector. It does not call the preview refresh helper.
- `SelectFemale` mirrors `SelectMale`, sets `m_isFemale` to 1, calls hair helper `0x00501640`, writes face selector gender byte `+0x10c` to 1, and invalidates the face selector. It does not call the preview refresh helper.
- `SetHairColorIndex` gets control id 6, writes selector byte `+0x10d`, and returns the color. It does not invalidate and does not refresh preview.
- `SetFaceColorIndex` gets control id 7, writes selector byte `+0x10d`, and returns the color. It does not invalidate and does not refresh preview.

The current formal C++ adds preview refreshes to `SelectMale`, `SelectFemale`, and both color setters. That is not source-shape accurate; in MCP the command dispatcher performs preview refresh after relevant commands.

### Nexonclub Helper And Callback

- `0x0052e970` falls back to `SendCreateCharacterRequest(this)` when its gate argument is false/null.
- With a true/nonzero gate it allocates a 24-byte `PlainMemberFunctionObjectT`, installs vtable `0x00620094`, stores callback target `this` and member-function pointer `0x0052ea50`, allocates a 632-byte registration dialog, and calls `0x0052f950` with language id 227 and the callback object.
- `0x0052ea50` copies a non-empty callback string into `m_createUserExtraText` at `+0x27c` and then calls `SendCreateCharacterRequest`.

The behavior is solved. MCP proves the opener argument is only tested for truth and is never dereferenced or passed onward, so the source-facing formal C++ should use a boolean gate (`bool openRegistration`) rather than a raw opaque context pointer. The exact parameter name remains inferred because the opener has no direct xrefs.

### Command And Event Dispatch

- `OnDialogAction` handles command ids 4/5 by calling `SelectMale`/`SelectFemale` and then refreshing the preview through `UserCreatePreviewControlPane::UpdatePreview`.
- Command ids 6/7 refresh the preview from the selected hair/face state.
- Command ids 8/9 invalidate or advance the selector state and then refresh the preview.
- Command ids 10-13 call `SelectBodyShape(0..3)`.
- Command id 15 calls `SubmitCreateUser`; id 16 closes the dialog; id 17 advances preview direction through `UserCreatePreviewControlPane::AdvanceDirection`.
- The default switch case returns without a base-call fallback. The current formal C++ base-call default is not backed by current MCP.
- `OnKeyEvent` delegates to `DialogPane` key handling. Local generated/source precedents use `KeyEvent *event` for this handler family.
- `OnCreateUserReplyEvent` checks the packet-event payload marker byte for value 2 and calls `HandleCreateUserReply((this - 0xa0), packet)`. The adjusted receiver is a secondary-vtable thunk/interface detail; the exact packet-event wrapper name is inferred from current `Event`/generated-source precedent as `PacketEvent`.
- `OnDialogShow` delegates to base show/open behavior.

### Submit And Packet Builders

- `SubmitCreateUser` reads controls 1, 2, and 3 into 16-wide buffers with a max length of 15, not larger 32-character buffers.
- It enforces the digit-in-password rule. The failure string at `0x0061e318` decodes from raw UTF-16 as `password must containt at least 1 number` with the binary typo preserved.
- Password mismatch uses language id 90.
- On success it creates a screen dimmer under `g_pScreenPane` and calls the account packet helper with account, password, and `word_60DB20`.
- `0x0052ef50` is `__stdcall` and file-local/free, not `CreateUserDialogPane::SendCreateAccountRequest`. It writes opcode 2, length-prefixed MBCS account/password/profile/default strings, a trailing zero byte, and sends through `g_packetSender`.
- `SendCreateCharacterRequest` creates the dimmer if absent, fetches preview control id 18, calls `UserCreatePreviewControlPane::BuildPreviewParams`, writes opcode 4, writes one word field via `sub_5753A0`, writes the remaining appearance bytes, a trailing zero, `m_bodyShapeIndex`, and the MBCS `m_createUserExtraText`, then sends through `g_packetSender`.

Packet helper names such as `WriteByte`, `WriteWord`, and `WriteLengthPrefixedString` remain source-name inferences. Opcodes, ordering, globals, and string conversion routes are backed by current MCP.

### Reply Handler

The current formal C++ has the most serious behavior issue in `HandleCreateUserReply`: MCP shows the result/status byte is `packet[1]`, not `packet[0]`. The message length is `packet[2]`, and message bytes start at `packet + 3`.

Current MCP-backed behavior:

- If `m_waitingForCharacterReply` (`+0x278`) is false and status is nonzero, the handler closes the dimmer if present, focuses account control 1 for result codes 3, 4, 14, 16, 17, 18, 20, and 21; focuses password control 2 for result codes 5, 6, 7, 8, 9, and 15; decodes and displays the server message when non-empty.
- If first-stage status is zero, it sets `m_waitingForCharacterReply = 1`, sends the character request, reads account control 1 into a 16-wide buffer, and passes it to the config/profile helper through [UID:00028Q] `dword_67A7C8`; exact setter name remains inferred.
- If `m_waitingForCharacterReply` is true and status is nonzero, it closes the dimmer and displays a non-empty decoded message.
- If second-stage status is zero, it closes the dimmer, displays the decoded message when non-empty, otherwise displays fallback `word_61FF48`, and closes the dialog.

Raw bytes at `0x0061ff48` decode as UTF-16 code units `U+C091 U+C0AC U+B9AC U+0021` (`"삑사리!"`). This resolves the prior "raw fallback word" blocker enough for source-quality docs. The original source variable name is still inferred, so use a neutral source-facing name such as `kCreateUserFallbackReplyText`.

## Defects In The Current Formal C++ Block

These are not style issues; they are source-quality blockers for keeping [UID:0002QT] as a single emitting aggregate:

| Current aggregate issue | MCP-backed correction |
| --- | --- |
| Omits constructor `0x0052dd30` while the target range begins at the constructor. | Constructor must be its own source child or the aggregate is incomplete. |
| Treats hidden raw bytes between constructor and `SelectBodyShape` as non-code. | Three raw bodies exist at `0x0052e6f0`, `0x0052e730`, and `0x0052e750`; all need no-code/source-quality treatment. |
| Models `0x0052ef50` as `CreateUserDialogPane::SendCreateAccountRequest`. | It is a `__stdcall` file-local/free helper and should emit through [UID:0000IJ], not [UID:00003B]. |
| Adds preview refreshes to `SelectMale`, `SelectFemale`, `SetHairColorIndex`, and `SetFaceColorIndex`. | MCP shows those side effects belong in the dispatcher path, not the helper bodies. |
| Adds invalidation to color setters. | MCP shows the 31-byte setters only write byte `+0x10d` and return the color. |
| Gives `OnDialogAction` a base-call default. | MCP shows default returns. |
| Reads reply status from `packet[0]`. | MCP shows status/result at `packet[1]`, length at `packet[2]`, payload at `packet + 3`. |
| Treats `word_61FF48` as unresolved raw fallback. | Current bytes decode to UTF-16 code units `U+C091 U+C0AC U+B9AC U+0021`; source variable spelling remains inferred, but the literal is solved. |
| Treats bytes after `0x0052f6e5` as padding only. | `0x0052f6e8` is a reply-handler switch table, then padding to [UID:0002QU]. |

## Heuristic And Inference Ledger

| Item | Current status | Implementation guidance |
| --- | --- | --- |
| Inherited control accessor names | Behavior is strong through manager at `+0x1fc`; exact original spellings are not symbol-proved. | Emit with fixed inferred source-facing wrappers (`GetControl<T>`, `GetChildEditText`, `FocusChildControl`, `SetDialogButtonChecked`, `SetDialogLabelText`) as exact formal insertion text. These are the report-selected names for the observed inherited routes. |
| Event parameter names/types | Secondary event bridge behavior is solved, including marker byte 2 and receiver adjustment by `0xa0` / 160. `Event` docs prove packet type 18 and payload-slot layout; generated/source precedents use `PacketEvent::payload` for typed packet handlers and `KeyEvent *event` for key handlers. Exact original wrapper typedef spelling is not symbol-proved, but raw buffer formal C++ is not source-shaped. | Emit `OnKeyEvent(KeyEvent *event)` and `OnCreateUserReplyEvent(const PacketEvent *event)` with `event->payload`; do not emit raw event-pointer casts or offset extraction. |
| Nexonclub helper spelling | Body and callback route solved; direct xrefs are absent, but the helper is source-authored and named in the class declaration. MCP proves the opener parameter is only a truth gate and is not dereferenced or forwarded. | Emit `OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration)` with an inferred but fixed source-facing callback/dialog construction shape. |
| `+0x26c` field | Constructor writes and raw setter writes are proved; no read route found in modeled methods or pointer checks. | Keep low-confidence field name `m_initialAppearanceRoll` or `m_initialGenderRoll`; document raw setter child as no-route. Do not pretend it is solved as a live source API. |
| `m_bodyShapeIndex` `+0x270` | Strong: selected/toggled by `SelectBodyShape`, serialized by character packet builder. | Keep field name. |
| `m_waitingForCharacterReply` `+0x278` | Strong: reply phase byte. | Keep field name. |
| `m_isFemale` `+0x279` | Strong: gender byte set by gender helpers and used in appearance routes. | Keep field name. |
| `m_createUserExtraText` `+0x27c` | Strong: `SimpleUString`, initialized/destroyed and serialized in character request. | Keep field name. |
| `word_61FF48` fallback | Solved literal, original variable spelling inferred. | Use neutral source name and include decoded literal. |
| Account/profile helper | First-stage success passes account text through [UID:00028Q] config/profile global. Exact setter name remains inferred. | Emit with the fixed source-facing global `g_newUserDialogCreatedAccountName.Assign(accountName)`, matching accepted sibling report style and preserving route evidence. |
| Packet-buffer helpers | Opcode/order/argument sizes proved; helper names inferred. | Emit `PacketBuffer`, `WriteByte`, `WriteWord`, `WriteLengthPrefixedMbcString`, `Size`, and `SizeWithoutTerminator` as fixed source-facing packet wrappers. Keep opcode/field order precise. |
| Nullsubs `0x0052e840`, `0x0052ed10` | Function records exist, but no xrefs or pointer hits. | Non-emitting no-route child docs, not source C++ methods, unless future route evidence appears. |

## Source Owner And Placement Ranking

| Rank | Candidate | Decision |
| ---: | --- | --- |
| 1 | [UID:0000IJ] `by-file/CreateUserDialogPane.md` | Best parent owner for the split/index because the range contains class methods, file-local packet helper code, raw/no-route bodies, and compiler switch data. This mirrors [UID:0002QR]'s file-owned split-index precedent. |
| 2 | [UID:00003B] `by-class/CreateUserDialogPane.md` | Correct source owner for constructor and class method child ranges. Keep the class declaration, field inventory, vtable/singleton route, and `[[CHILDREN]]` route here; all source-authored class-method children selected in this report now emit through this route. |
| 3 | [UID:0000IK] `by-file/CreateUserDialogs.md` | Non-emitting family/index only; should link the repaired old-dialog split without emitting code. |
| 4 | [UID:0001CR] `CreateUserDialogVariants` | Non-emitting broad memory split/index only; should point to exact children and boundary repair. |
| 5 | [UID:0000OX] `UserCreateAppearanceControls` | Owns appearance control classes and helper methods; does not own old-dialog coordinator methods or packet/reply behavior. |
| 6 | Siblings [UID:0002QR] and [UID:0002QS] | Separate create-user implementations; useful precedent and contrast, not owner candidates for [UID:0002QT]. |

## Recommended Split Plan

If accepted, do not retain the current [UID:0002QT] aggregate C++ block. Convert the parent to a non-emitting split/source-quality index, repair the range to `0x0052dd30-0x0052f710`, and create every exact child range in the function map below. Paths are proposed; exact UIDs are assigned by the project tooling/supervisor.

This revision recommends emitters for every source-authored child whose exact range is understood. The only blank child formal C++ blocks are for raw/no-route cleanup helpers, nullsubs, and compiler switch-table/padding data with target-specific no-code proof.

## Report Revision For Supervisor Recheck

Supervisor rejection reason addressed: the prior report included non-formal C++ snippets and non-final helper names. Those snippets are removed. No non-formal C++ body remains in this revised report. The exact formal blocks below are insertion text for the named child pages.

The MCP-backed behavior evidence remains valid and should be preserved in prose on the split parent, child pages, and relevant support docs. It is an instruction to emit code only for the child pages explicitly listed as `insert exact block below`; all raw/no-route and compiler-data child pages remain blank with no-code proof.

## Report Revision For Supervisor Recheck 2

Supervisor rejection reason addressed: the prior revision made [UID:0002QT] a false container while leaving source-authored ranges only as deferred candidates. This revision fixes the container rule violation. The parent can be `RECONSTRUCTABLE:FALSE` only because all understood exact ranges are now listed for child-page creation. Source-authored ranges are not omitted and are not left as non-emitting deferred work: they become `RECONSTRUCTABLE:TRUE` child pages with nonblank emitters and exact formal C++ below. Compiler-generated/no-route/padding ranges become `RECONSTRUCTABLE:FALSE` child pages with exact no-code proof.

Revision 3 supersedes the previous blank source-child disposition. The container rule is satisfied because every understood exact range is represented as a child page and every source-authored child has a complete implementation disposition now.

## Report Revision For Supervisor Recheck 3

Supervisor rejection reason addressed: the prior revision still treated many source-authored children as final non-emitting children on the strength of unresolved names/signatures. This pass rechecked the active MCP session and support docs instead of leaving those blockers as a final report shape.

Current MCP proof added to this revision:

- `initialize` and `tools/list` returned HTTP 200 from `http://127.0.0.1:13337/mcp`; the active tool list includes `server_health` and `lookup_funcs`.
- `idb_list` reports active database session `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_analyzing:false`.
- `server_health(database=80de0a67)` returns `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `lookup_funcs(database=80de0a67, queries=0x0052dd30,0x0052e970,0x0052ea80,0x0052ed80,0x0052ef50,0x0052f160,0x0052f390)` reconfirms `sub_52DD30` size `0x9bb`, `sub_52E970` size `0xd4`, `sub_52EA80` size `0x200`, `sub_52ED80` size `0x1cc`, `sub_52EF50` size `0x205`, `sub_52F160` size `0x22d`, and `sub_52F390` size `0x355`.
- Current decompilation was rerun for the broad and small candidate emitters: `0x0052dd30`, `0x0052e770`, `0x0052e850`, `0x0052e8c0`, `0x0052e930`, `0x0052e950`, `0x0052e970`, `0x0052ea50`, `0x0052ea80`, `0x0052ecc0`, `0x0052ecd0`, `0x0052ed00`, `0x0052ed80`, `0x0052ef50`, `0x0052f160`, and `0x0052f390`.

Current-pass name/type investigation result:

- The appearance-control support pages already declare `UserHairSelectControlPane::SetMaleMode`, `SetFemaleMode`, `SetHairColorIndex`, and `GetSelectedHairPartFrame`; `UserFaceSelectControlPane::SetGender`, `SetFaceColorIndex`, and `GetSelectedFacePartId`; and `UserCreatePreviewControlPane::UpdatePreview`, `AdvanceDirection`, and `BuildPreviewParams`. The report selects these and the inherited dialog wrappers as fixed source-facing names for implementation. They are inferred where symbols are absent, but they are fixed for this implementation plan.
- `DialogPane` support identifies `0x0049e6e0` as the inherited key/control handler, and local generated/source precedents use `KeyEvent *event`; the `OnKeyEvent` bridge now emits through `DialogPane::OnKeyEvent(event)` with that source-facing key-event type. The `0x0052ed00` bridge is a source-authored show/open bridge in the class vtable slot; this revision emits the current class declaration shape `DialogPane::OnDialogShow(reason)` and documents the `0x0049e240` target caveat at support-detail level rather than leaving the child blank.
- The reply-event bridge has exact marker and packet-payload-slot evidence. `Event` support docs identify packet family type 18 and payload slots; current generated-source precedents use `PacketEvent::payload` for typed packet handlers. The formal block below therefore emits `const PacketEvent *event` and reads `event->payload`, not a raw event-buffer extraction.
- The constructor, command dispatcher, submit/alert/dimmer path, file-local account packet helper, character packet helper, and reply handler were rechecked against current MCP and accepted sibling split style. Exact complete formal blocks are now provided below with fixed source-facing helper names and conservative scores. Remaining name caveats are support-prose caveats, not reasons to suppress source-authored child C++.

## Report Revision For Supervisor Recheck 4

Narrow supervisor rejection addressed: the child C++ for packet/key/opener paths no longer emits raw event-buffer formal code. MCP was rechecked on 2026-06-26 against session `80de0a67`; `server_health` remained `status:"ok"` with auto-analysis, Hex-Rays, and strings cache ready. `lookup_funcs(database=80de0a67, queries=0x0052ecc0,0x0052ecd0,0x0052ed00,0x0052e970,0x004a9fa0,0x004aa050,0x004aa110)` reconfirmed all seven expected function records, and current decompilation was rerun for those addresses.

- `0x0052ecd0` still proves packet marker byte `0x02`, payload-slot use, and `HandleCreateUserReply` routing. Current `Event` support docs model packet events as type 18 with payload slots, and generated source already uses `PacketEvent::payload` for typed packet handlers, so the exact formal block now uses `const PacketEvent *event` and `event->payload`.
- `0x0052ecc0` only forwards the event object to the inherited key/control handler at `0x0049e6e0`; generated-source precedents use `KeyEvent *event` for this handler family, so the exact formal block now uses `KeyEvent *event`.
- `0x0052e970` only tests its parameter as a gate before either sending the character request or opening the registration dialog; it never dereferences or forwards that parameter. The exact formal block now uses `bool openRegistration`.
- The remaining `const unsigned char *packet` parameters are packet-payload helper/reply-handler parameters, matching the accepted sibling `NewUserDialogPane2::HandleCreateUserPacketEvent(const unsigned char *packet)` shape. They are not raw event-buffer access.

## Child Formal C++ And No-Code Dispositions

For [UID:0002QT] itself, the exact formal C++ block after implementation should be empty: leave the `RECONSTRUCTION_CPP CODE:BEGIN/END` block with no code between the markers.

Implementation-ready child plan for every exact range:

| Child page to create now | Completion / confidence | Owner | Reconstructable | Emitters | Exact formal C++ action | C++ blocker or no-code proof |
| --- | ---: | --- | --- | --- | --- | --- |
| `by-memory/0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor.md` | `87/89` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored constructor with direct callers and class ownership. The exact block below uses fixed source-facing constructor helpers for the observed `DLGNEW3` layout, child-control construction, singleton publication, randomized initial state, selector setup, and preview creation. |
| `by-memory/0x0052e6f0-0x0052e72a.CreateUserDialogPaneConstructorCleanupRaw.md` | `88/90` | `00003B` | `FALSE` | blank | empty formal C++ block | IDA has no function record; `xrefs_to` found no incoming references; VA/RVA pointer-pattern checks for the start address found no matches; body is a constructor cleanup/fallback teardown that resets vtables, destroys `m_createUserExtraText`, clears singleton, and tail-jumps to base teardown. Source-level constructor/destructor declarations generate this lifecycle code; do not hand-author it as standalone source. |
| `by-memory/0x0052e730-0x0052e744.CreateUserDialogPaneAdvancePreviewDirectionRaw.md` | `86/90` | `00003B` | `FALSE` | blank | empty formal C++ block | IDA has no function record; `xrefs_to` found no incoming references; VA/RVA pointer-pattern checks for the start address found no matches. The body fetches preview control id 18 and tail-jumps to `UserCreatePreviewControlPane::AdvanceDirection`; the live dispatcher already has its own direct advance-direction call. No source entry route is proved, so emitting a standalone helper would invent reachability. |
| `by-memory/0x0052e750-0x0052e75e.CreateUserDialogPaneSetInitialAppearanceRollRaw.md` | `86/90` | `00003B` | `FALSE` | blank | empty formal C++ block | IDA has no function record; `xrefs_to` found no incoming references; VA/RVA pointer-pattern checks for the start address found no matches. The body only sign-extends its argument and writes `+0x26c`; the original field/helper name and any source entry route remain unproved. Do not create source C++ for dead/no-route raw code. |
| `by-memory/0x0052e770-0x0052e832.CreateUserDialogPaneSelectBodyShape.md` | `88/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored class method. Current MCP decompilation confirms controls 10-13, `UserShapeSelectControlPane::SetActive`, `m_bodyShapeIndex`, control 14, and language id `bodyShapeIndex + 212`. `SetDialogLabelText` remains an inferred dialog helper name, but the behavior and owner route are source-shaped enough for formal insertion. |
| `by-memory/0x0052e840-0x0052e843.CreateUserDialogPaneNullsub43.md` | `90/92` | `00003B` | `FALSE` | blank | empty formal C++ block | Modeled function is only `retn 4`; current MCP found zero xrefs and zero VA/RVA pointer-pattern hits. It is a no-route nullsub, not a source method to emit. |
| `by-memory/0x0052e850-0x0052e8b7.CreateUserDialogPaneSelectMale.md` | `88/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored class method. Current MCP decompilation confirms controls 4/5, `m_isFemale = 0`, hair selector control 6 `SetMaleMode`, face selector control 7 gender byte 0 plus invalidate, and no preview refresh in this method. |
| `by-memory/0x0052e8c0-0x0052e927.CreateUserDialogPaneSelectFemale.md` | `88/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored class method. Current MCP decompilation confirms the mirror behavior for female selection: controls 4/5, `m_isFemale = 1`, hair selector `SetFemaleMode`, face selector gender byte 1 plus invalidate, and no preview refresh in this method. |
| `by-memory/0x0052e930-0x0052e94f.CreateUserDialogPaneSetHairColorIndex.md` | `89/91` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored color setter. Current MCP decompilation confirms control id 6, selected color byte `+0x10d`, return of the argument, and no invalidate/preview refresh. `UserHairSelectControlPane::SetHairColorIndex` is the accepted source-facing inline setter name from support docs. |
| `by-memory/0x0052e950-0x0052e96f.CreateUserDialogPaneSetFaceColorIndex.md` | `89/91` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored color setter. Current MCP decompilation confirms control id 7, selected color byte `+0x10d`, return of the argument, and no invalidate/preview refresh. `UserFaceSelectControlPane::SetFaceColorIndex` is the accepted source-facing inline setter name from support docs. |
| `by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md` | `87/89` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored helper retained in the old dialog cluster. Current-pass MCP solves the boolean-gate fallback, callback target, language id `227`, and registration dialog allocation; the exact block below fixes the inferred source-facing callback/dialog names and does not expose a raw opaque pointer. |
| `by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md` | `88/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored callback. Current MCP decompilation confirms `SimpleUString` non-empty test, assignment to `m_createUserExtraText`, and unconditional `SendCreateCharacterRequest`. The class declaration already carries `const SimpleUString &text`. |
| `by-memory/0x0052ea80-0x0052ec80.CreateUserDialogPaneOnDialogAction.md` | `88/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored dispatcher. Current-pass MCP solves command ids `4-17`, selector refresh routing, submit/cancel behavior, preview direction advance, and default return. The exact block below uses fixed source-facing helper names for the repeated inline preview-refresh sequence. |
| `by-memory/0x0052ecc0-0x0052ecc9.CreateUserDialogPaneOnKeyEvent.md` | `88/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored/base-delegating event bridge. Current MCP decompilation confirms the direct call to `0x0049e6e0`, and `DialogPane`/generated-source support documents that as inherited key/control handling with `KeyEvent *event`. |
| `by-memory/0x0052ecd0-0x0052ecf6.CreateUserDialogPaneOnCreateUserReplyEvent.md` | `86/89` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored packet-event bridge. Current MCP decompilation confirms payload-slot packet access, marker byte `2`, and call to `HandleCreateUserReply`; `Event` docs and generated typed packet handlers justify the source-facing `PacketEvent::payload` accessor. The secondary `this - 0xa0` adjustment is compiler multiple-inheritance routing, not a reason to emit raw adjusted-this code. |
| `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md` | `86/89` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored/base-delegating bridge. The current class vtable slot and declaration name are `OnDialogShow`; the exact block below emits the source-facing base delegation while preserving the `0x0049e240` inherited-target caveat in prose. |
| `by-memory/0x0052ed10-0x0052ed11.CreateUserDialogPaneNullsub44.md` | `90/92` | `00003B` | `FALSE` | blank | empty formal C++ block | Modeled function is only `retn`; current MCP found zero xrefs and zero VA/RVA pointer-pattern hits. It is a no-route nullsub, not a source method to emit. |
| `by-memory/0x0052ed80-0x0052ef4c.CreateUserDialogPaneSubmitCreateUser.md` | `89/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored submit/validation method. Current MCP solves 16-wide buffers, max 15 characters, digit rule, mismatch rule, dimmer creation, and file-local account helper call; the exact block below uses the accepted sibling helper style. |
| `by-memory/0x0052ef50-0x0052f155.CreateUserDialogPaneSendCreateAccountRequest.md` | `88/90` | `0000IJ` | `TRUE` | `0000IJ` | insert exact block below | Source-authored file-local `__stdcall` helper. Current MCP solves opcode `2`, three length-prefixed MBCS string fields, trailing zero byte, and send route. It must emit through [UID:0000IJ], not as a `CreateUserDialogPane` method. |
| `by-memory/0x0052f160-0x0052f38d.CreateUserDialogPaneSendCreateCharacterRequest.md` | `88/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored character packet helper. Current MCP solves dimmer behavior, preview control `18`, `BuildPreviewParams`, opcode `4`, word/four-byte field order, trailing zero, body shape, `m_createUserExtraText`, and `SizeWithoutTerminator` send. |
| `by-memory/0x0052f390-0x0052f6e5.CreateUserDialogPaneHandleCreateUserReply.md` | `89/90` | `00003B` | `TRUE` | `00003B` | insert exact block below | Source-authored reply handler. Current MCP solves status byte `packet[1]`, message length `packet[2]`, message bytes `packet + 3`, two-phase reply state, focus-code groups, dimmer closing, fallback literal, and account-cache route. |
| `by-memory/0x0052f6e5-0x0052f710.CreateUserDialogPaneReplySwitchTableAndPadding.md` | `90/91` | `00003B` | `FALSE` | blank | empty formal C++ block | `insn_query` shows alignment at `0x0052f6e5`, a compiler switch table beginning at `0x0052f6e8`, and padding to [UID:0002QU] at `0x0052f710`. This is compiler-generated switch data/padding attached to the reply handler, not handwritten source code. |

### Exact Formal C++ Blocks For Emitting Children

These blocks are exact `RECONSTRUCTION_CPP CODE` insertion text for the named child pages, not examples. The implementation callback must not insert them into the [UID:0002QT] parent; they belong only to the corresponding child page formal blocks.

Name/type rationale for emitted blocks: `GetControl<T>`, `GetChildEditText`, `FocusChildControl`, `SetDialogButtonChecked`, `SetDialogLabelText`, `CreateCreateUserScreenDimmer`, `DestroyCreateUserScreenDimmer`, and child-creation helpers are fixed inferred source-facing wrappers for inherited dialog/control-manager routes. `KeyEvent` and `PacketEvent` are fixed source-facing event wrapper names selected from current Event support docs and generated-source precedents; the packet bridge uses `PacketEvent::payload` rather than raw event storage. `PacketBuffer`, `WriteByte`, `WriteWord`, `WriteLengthPrefixedMbcString`, `Size`, and `SizeWithoutTerminator` are fixed packet-writer wrappers matching accepted sibling child pages. `createUserPacketWord` / `createUserPacketByte0..3` are selected packet-layout names for the unresolved `HumanImageRenderParams` typedef fields; the field order is MCP-backed even though the final structure member names remain a support-level caveat. All names in the blocks are fixed choices for this report.

`by-memory/0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor.md`:

```cpp
CreateUserDialogPane::CreateUserDialogPane()
    : DialogPane(L"NE", -1, 4),
      m_initialAppearanceRoll(0),
      m_bodyShapeIndex(0),
      m_waitingForCharacterReply(0),
      m_isFemale(0)
{
    g_pCreateUserDialogPane = this;
    m_createUserExtraText.clear();

    srand((unsigned)_time64(0));

    LoadDialogBackground(L"DLGNEW3.EPF", L"DLGNEW3.PAL");

    CreateChildEditControl(1, RectBounds(232, 132, 414, 144), false);
    CreateChildEditControl(2, RectBounds(232, 168, 414, 180), true);
    CreateChildEditControl(3, RectBounds(232, 206, 414, 218), true);

    CreateGenderButton(4, RectBounds(68, 480, 118, 530), 0);
    CreateGenderButton(5, RectBounds(110, 480, 160, 530), 1);

    const RectBounds hairBounds = {170, 342, 926, 477};
    UserHairSelectControlPane *hairSelector =
        new UserHairSelectControlPane(rand() % 10, 12, 0, &hairBounds, 0);
    AddChildControl(6, hairSelector);

    const RectBounds faceBounds = {170, 545, 676, 662};
    UserFaceSelectControlPane *faceSelector =
        new UserFaceSelectControlPane(rand() % 10, 1, 0, &faceBounds, 0);
    AddChildControl(7, faceSelector);

    AddChildControl(
        8,
        new UserHairColorSelectListPane(
            RectBounds(814, 545, 964, 695),
            this));
    AddChildControl(
        9,
        new UserFaceColorSelectListPane(
            RectBounds(663, 545, 813, 695),
            this));

    CreateBodyShapeButton(10, RectBounds(501, 146, 551, 196), 0);
    CreateBodyShapeButton(11, RectBounds(559, 146, 609, 196), 1);
    CreateBodyShapeButton(12, RectBounds(501, 201, 551, 251), 2);
    CreateBodyShapeButton(13, RectBounds(559, 201, 609, 251), 3);

    CreateDialogLabel(
        14,
        RectBounds(627, 124, 909, 250),
        g_pLanguageMan->GetString(m_bodyShapeIndex + 212));

    CreateCommandButton(15, RectBounds(371, 713, 484, 749), 0);
    CreateCommandButton(16, RectBounds(539, 713, 652, 749), 1);
    CreatePreviewDirectionButton(17, RectBounds(85, 541, 135, 591), L"DIREC.EPF");

    m_initialAppearanceRoll = rand() % 2;
    SelectBodyShape((short)(rand() % 4));

    if ((rand() % 2) != 0) {
        SelectMale();
    } else {
        SelectFemale();
    }

    const RectBounds previewBounds = {65, 355, 147, 472};
    AddChildControl(
        18,
        new UserCreatePreviewControlPane(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale,
            &previewBounds,
            0));

    SetActiveControl(15);
    SetDefaultControl(16);
    EnableDialogFocusRouting(true);
    SetDialogFrameResource(L"DLGNEW.EPF", 0);
    CreateDialogWindow();
    Show();
}
```

`by-memory/0x0052e770-0x0052e832.CreateUserDialogPaneSelectBodyShape.md`:

```cpp
void CreateUserDialogPane::SelectBodyShape(short bodyShapeIndex)
{
    UserShapeSelectControlPane *bodyShapes[4];

    bodyShapes[0] = GetControl<UserShapeSelectControlPane>(10);
    bodyShapes[1] = GetControl<UserShapeSelectControlPane>(11);
    bodyShapes[2] = GetControl<UserShapeSelectControlPane>(12);
    bodyShapes[3] = GetControl<UserShapeSelectControlPane>(13);

    bodyShapes[m_bodyShapeIndex]->SetActive(false);
    bodyShapes[bodyShapeIndex]->SetActive(true);
    m_bodyShapeIndex = bodyShapeIndex;

    SetDialogLabelText(14, g_pLanguageMan->GetString(bodyShapeIndex + 212));
}
```

`by-memory/0x0052e850-0x0052e8b7.CreateUserDialogPaneSelectMale.md`:

```cpp
void CreateUserDialogPane::SelectMale()
{
    m_isFemale = 0;
    SetDialogButtonChecked(4, true);
    SetDialogButtonChecked(5, false);

    UserHairSelectControlPane *hairSelector = GetControl<UserHairSelectControlPane>(6);
    hairSelector->SetMaleMode();

    UserFaceSelectControlPane *faceSelector = GetControl<UserFaceSelectControlPane>(7);
    faceSelector->SetGender(0);
    faceSelector->Invalidate();
}
```

`by-memory/0x0052e8c0-0x0052e927.CreateUserDialogPaneSelectFemale.md`:

```cpp
void CreateUserDialogPane::SelectFemale()
{
    m_isFemale = 1;
    SetDialogButtonChecked(4, false);
    SetDialogButtonChecked(5, true);

    UserHairSelectControlPane *hairSelector = GetControl<UserHairSelectControlPane>(6);
    hairSelector->SetFemaleMode();

    UserFaceSelectControlPane *faceSelector = GetControl<UserFaceSelectControlPane>(7);
    faceSelector->SetGender(1);
    faceSelector->Invalidate();
}
```

`by-memory/0x0052e930-0x0052e94f.CreateUserDialogPaneSetHairColorIndex.md`:

```cpp
unsigned char CreateUserDialogPane::SetHairColorIndex(unsigned char colorIndex)
{
    UserHairSelectControlPane *hairSelector = GetControl<UserHairSelectControlPane>(6);
    hairSelector->SetHairColorIndex(colorIndex);
    return colorIndex;
}
```

`by-memory/0x0052e950-0x0052e96f.CreateUserDialogPaneSetFaceColorIndex.md`:

```cpp
unsigned char CreateUserDialogPane::SetFaceColorIndex(unsigned char colorIndex)
{
    UserFaceSelectControlPane *faceSelector = GetControl<UserFaceSelectControlPane>(7);
    faceSelector->SetFaceColorIndex(colorIndex);
    return colorIndex;
}
```

`by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md`:

```cpp
void CreateUserDialogPane::OpenNexonclubRegistrationOrSendCharacterRequest(
    bool openRegistration)
{
    if (!openRegistration) {
        SendCreateCharacterRequest();
        return;
    }

    PlainMemberFunctionObject<
        CreateUserDialogPane,
        const SimpleUString &> *callback =
            new PlainMemberFunctionObject<
                CreateUserDialogPane,
                const SimpleUString &>(
                    this,
                    &CreateUserDialogPane::OnNexonclubRegistrationResult);

    new NexonclubRegistrationDialog(g_pLanguageMan->GetString(227), callback);
}
```

`by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md`:

```cpp
void CreateUserDialogPane::OnNexonclubRegistrationResult(const SimpleUString &text)
{
    if (!text.empty()) {
        m_createUserExtraText = text;
    }

    SendCreateCharacterRequest();
}
```

`by-memory/0x0052ea80-0x0052ec80.CreateUserDialogPaneOnDialogAction.md`:

```cpp
void CreateUserDialogPane::OnDialogAction(int commandId, int action)
{
    UserHairSelectControlPane *hairSelector =
        GetControl<UserHairSelectControlPane>(6);
    UserFaceSelectControlPane *faceSelector =
        GetControl<UserFaceSelectControlPane>(7);
    UserCreatePreviewControlPane *previewPane =
        GetControl<UserCreatePreviewControlPane>(18);

    switch (commandId) {
    case 4:
        SelectMale();
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 5:
        SelectFemale();
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 6:
    case 7:
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 8:
        hairSelector->Invalidate();
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 9:
        faceSelector->Invalidate();
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 10:
    case 11:
    case 12:
    case 13:
        SelectBodyShape((short)(commandId - 10));
        return;

    case 15:
        SubmitCreateUser();
        return;

    case 16:
        Close();
        return;

    case 17:
        previewPane->AdvanceDirection();
        return;

    default:
        return;
    }
}
```

`by-memory/0x0052ecc0-0x0052ecc9.CreateUserDialogPaneOnKeyEvent.md`:

```cpp
bool CreateUserDialogPane::OnKeyEvent(KeyEvent *event)
{
    return DialogPane::OnKeyEvent(event);
}
```

`by-memory/0x0052ecd0-0x0052ecf6.CreateUserDialogPaneOnCreateUserReplyEvent.md`:

```cpp
bool CreateUserDialogPane::OnCreateUserReplyEvent(const PacketEvent *event)
{
    const unsigned char *packet = event->payload;

    if (packet[0] != 0x02) {
        return false;
    }

    return HandleCreateUserReply(packet);
}
```

`by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md`:

```cpp
bool CreateUserDialogPane::OnDialogShow(int reason)
{
    return DialogPane::OnDialogShow(reason);
}
```

`by-memory/0x0052ed80-0x0052ef4c.CreateUserDialogPaneSubmitCreateUser.md`:

```cpp
void CreateUserDialogPane::SubmitCreateUser()
{
    wchar_t accountName[16];
    wchar_t password[16];
    wchar_t confirmPassword[16];

    GetChildEditText(1, accountName, 15);
    GetChildEditText(2, password, 15);
    GetChildEditText(3, confirmPassword, 15);

    bool hasDigit = false;
    for (const wchar_t *scan = password; *scan != L'\0'; ++scan) {
        if (*scan >= L'0' && *scan <= L'9') {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        FocusChildControl(2);
        ShowCreateUserAlert(kPasswordMustContainDigitText);
        return;
    }

    if (wcscmp(password, confirmPassword) != 0) {
        FocusChildControl(2);
        ShowCreateUserAlert(g_pLanguageMan->GetString(90));
        return;
    }

    CreateCreateUserScreenDimmer();
    SendCreateAccountRequest(accountName, password, kCreateUserDefaultProfileText);
}
```

`by-memory/0x0052ef50-0x0052f155.CreateUserDialogPaneSendCreateAccountRequest.md`:

```cpp
namespace
{
void SendCreateAccountRequest(const wchar_t *accountName,
                              const wchar_t *password,
                              const wchar_t *profileText)
{
    PacketBuffer packet;
    packet.WriteByte(0x02);
    packet.WriteLengthPrefixedMbcString(accountName);
    packet.WriteLengthPrefixedMbcString(password);
    packet.WriteLengthPrefixedMbcString(profileText);
    packet.WriteByte(0);
    g_packetSender->QueueAndSendPacket(packet.Data(), packet.Size());
}
}
```

`by-memory/0x0052f160-0x0052f38d.CreateUserDialogPaneSendCreateCharacterRequest.md`:

```cpp
void CreateUserDialogPane::SendCreateCharacterRequest()
{
    if (g_createUserScreenDimmer == 0) {
        CreateCreateUserScreenDimmer();
    }

    HumanImageRenderParams appearance;
    GetControl<UserCreatePreviewControlPane>(18)->BuildPreviewParams(&appearance);

    PacketBuffer packet;
    packet.WriteByte(0x04);
    packet.WriteWord(appearance.createUserPacketWord);
    packet.WriteByte(appearance.createUserPacketByte0);
    packet.WriteByte(appearance.createUserPacketByte1);
    packet.WriteByte(appearance.createUserPacketByte2);
    packet.WriteByte(appearance.createUserPacketByte3);
    packet.WriteByte(0);
    packet.WriteByte((unsigned char)m_bodyShapeIndex);
    packet.WriteLengthPrefixedMbcString(m_createUserExtraText.c_str());

    g_packetSender->QueueAndSendPacket(packet.Data(), packet.SizeWithoutTerminator());
}
```

`by-memory/0x0052f390-0x0052f6e5.CreateUserDialogPaneHandleCreateUserReply.md`:

```cpp
namespace
{
SimpleUString DecodeCreateUserReplyMessage(const unsigned char *packet)
{
    return SimpleUString::FromMbcString(packet + 3, packet[2]);
}

bool IsCreateUserNameReplyError(unsigned char result)
{
    switch (result) {
    case 3:
    case 4:
    case 14:
    case 16:
    case 17:
    case 18:
    case 20:
    case 21:
        return true;

    default:
        return false;
    }
}

bool IsCreateUserPasswordReplyError(unsigned char result)
{
    switch (result) {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 15:
        return true;

    default:
        return false;
    }
}

void ShowCreateUserReplyText(const SimpleUString &message)
{
    if (!message.empty()) {
        ShowCreateUserAlert(message.c_str());
    }
}
}

bool CreateUserDialogPane::HandleCreateUserReply(const unsigned char *packet)
{
    const unsigned char result = packet[1];
    const SimpleUString message = DecodeCreateUserReplyMessage(packet);

    if (!m_waitingForCharacterReply) {
        if (result == 0) {
            wchar_t accountName[16];

            m_waitingForCharacterReply = true;
            SendCreateCharacterRequest();

            GetChildEditText(1, accountName, 15);
            g_newUserDialogCreatedAccountName.Assign(accountName);
            return true;
        }

        DestroyCreateUserScreenDimmer();

        if (IsCreateUserNameReplyError(result)) {
            FocusChildControl(1);
        } else if (IsCreateUserPasswordReplyError(result)) {
            FocusChildControl(2);
        }

        ShowCreateUserReplyText(message);
        return true;
    }

    DestroyCreateUserScreenDimmer();

    if (result != 0) {
        ShowCreateUserReplyText(message);
        return true;
    }

    if (!message.empty()) {
        ShowCreateUserAlert(message.c_str());
    } else {
        ShowCreateUserAlert(kCreateUserCompleteMessage);
    }

    Close();
    return true;
}
```

## Score Recommendation

Recommended [UID:0002QT] score after implementation callback: `90/90`.

Completion moves from 88 to 90 because current MCP evidence resolves the function map, confirms direct constructor/vtable/singleton routes, finds and bounds hidden raw bodies, corrects the file-local helper ownership, decodes the fallback reply literal, produces a structurally valid 22-child split/no-code plan, and now supplies exact formal C++ for every source-authored child selected in the split.

Confidence moves to 90 because the evidence is live MCP-backed, sibling split precedent is revalidated, and the prior non-emitting source-child blockers are resolved into exact child C++ or target-specific no-code proof. The parent still should not exceed 90 because several helper/type names remain inferred source-facing names rather than symbol-proved original spellings.

If the supervisor rejects the split and requires [UID:0002QT] to stay as a monolithic emitter, the score should not improve until the aggregate C++ is rewritten to include the constructor, hidden raw/no-code dispositions, corrected small helper side effects, corrected packet offsets, corrected file-local helper scope, and switch-table boundary note. The split is the safer source-quality repair.

## Target And Support Changes Needed If Accepted

Target-level changes:

- Convert [UID:0002QT] to a non-emitting split/index.
- Recommended filename/title range repair: `0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md`.
- Set metadata to `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000IJ`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++ block, and `Nested:22`.
- Replace aggregate formal C++ with full exact child inventory and source-quality notes; do not preserve the unsafe aggregate body.

Support doc changes:

- [UID:00003B] `by-class/CreateUserDialogPane.md`: keep class declaration/fields, but update method notes so [UID:0002QT] is a split/source-quality index; class method ranges are reconstructable child pages owned/emitted by `00003B` with exact child formal C++ as listed in this report. Update the declarations for `OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration)`, `OnKeyEvent(KeyEvent *event)`, and `OnCreateUserReplyEvent(const PacketEvent *event)` so support docs do not preserve the rejected raw pointer shapes. Remove the stale `static SendCreateAccountRequest` member declaration because `0x0052ef50` is a file-local helper owned by [UID:0000IJ]. Remove stale statements that color setters invalidate/refresh, that gender helpers refresh preview, and that `+0x26c` is only constructor-written. Preserve the inherited-target caveat for `0x0052ed00` while allowing the exact `OnDialogShow` child block from this report.
- [UID:0000IJ] `by-file/CreateUserDialogPane.md`: update proposed contents to reference the full 22-child split, account helper file-local ownership/emitter route, decoded fallback literal, raw helper/no-code children, boundary repair, and exact formal C++ for every source-authored child.
- [UID:0000IK] `by-file/CreateUserDialogs.md`: keep non-emitting umbrella status; update old-dialog route to the repaired [UID:0002QT] split/source-quality index and full 22-child plan.
- [UID:0001CR] `CreateUserDialogVariants`: update old-dialog child row from monolithic emitter to split/source-quality index and mention the switch-table child before [UID:0002QU].
- [UID:0002QU] `CreateUserDialogDestructorAndThunkIsland`: replace "padding before `0x0052f710`" with "reply-handler switch table at `0x0052f6e8` plus padding"; keep [UID:0002QU] start unchanged.
- [UID:0002SI] `CreateUserDialogPaneVtableData`: no code change is required, but a note may reference that `0x0052e840` and `0x0052ed10` currently have no pointer/xref route if child docs are created.
- [UID:0002B3] `CreateUserDialogPaneSingletonSlot`: no required metadata change; optional note can mention the cleanup/fallback raw body at `0x0052e6f0` also clears the singleton.
- [UID:0000OX] `UserCreateAppearanceControls`: no ownership change; update stale callback prose so old-dialog color setters are recorded as direct selector color-byte writes with no invalidate/preview refresh inside those dialog methods, and so `SetHairColorIndex`, `SetFaceColorIndex`, and `SetGender` are treated as inline/trivial state-setter names for the accepted child C++ blocks.
- Generated files, project-level trackers, coverage reports, validator/tool state, and IDA DB files must not be edited manually.

## Validation Plan For Implementation Callback

Report-only phase did not run by-* validators because no by-* docs were edited. After an implementation callback, run scoped validation for:

- repaired [UID:0002QT] parent;
- every newly created child page in the 22-child plan;
- [UID:00003B], [UID:0000IJ], [UID:0000IK], [UID:0001CR], [UID:0002QU], and [UID:0000OX];
- any optional support docs touched in [UID:0002SI] or [UID:0002B3].

Validation must be scoped to changed docs and must not hand-edit generated/project-level coverage/tool-state outputs.

## Implementation Tracking Checklist

- [x] Lease only the immediate target/support docs selected for the implementation batch. Proof: `python tools/leaser/leaser.py B008 lease ...` returned `Success` for the initial target/support set and optional support files were leased only immediately before their edits; post-batch `python tools/leaser/leaser.py B008 unlease` returned `B008: No active leases`, and `rg B008 tools/leaser/Agents/current_leases.md` found no active B008 lease rows.
- [x] Repair [UID:0002QT] range/title to `0x0052dd30-0x0052f710` if supervisor accepts the boundary change. Proof: parent moved to `by-memory/0x0052dd30-0x0052f710.CreateUserDialogPaneCore.md`; validator command `000000003340` at `2026-06-26T20:38:42-04:00` returned `ok: 1`.
- [x] Convert [UID:0002QT] metadata to `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000IJ`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, empty formal C++ block, and `Nested:22`. Proof: command `000000003340` returned `ok: 1`.
- [x] Remove the unsafe aggregate formal C++ from [UID:0002QT]; do not insert replacement C++ in the parent. Proof: parent formal block is empty and command `000000003340` returned `ok: 1`.
- [x] On [UID:0002QT], add a child inventory for all 22 exact child pages listed below, preserving which children have exact child formal C++ and which children are non-reconstructable no-code. Proof: TMP allocation command `000000003329` at `2026-06-26T20:36:36-04:00` inserted child UIDs `00046E` through `00046Z` and replaced 22 TMP refs; final parent command `000000003340` returned `ok: 1`.
- [x] Create `by-memory/0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor.md` as [UID:00046E] with `87/89`, owner/emitter `00003B`, `RECONSTRUCTABLE:TRUE`, and the exact constructor C++ block. Proof: validator `000000003342` at `2026-06-26T20:38:45-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e6f0-0x0052e72a.CreateUserDialogPaneConstructorCleanupRaw.md` as [UID:00046F] with `88/90`, owner `00003B`, non-reconstructable blank C++, and cleanup no-code proof. Proof: validator `000000003344` at `2026-06-26T20:38:47-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e730-0x0052e744.CreateUserDialogPaneAdvancePreviewDirectionRaw.md` as [UID:00046G] with `86/90`, owner `00003B`, non-reconstructable blank C++, and no-route proof. Proof: validator `000000003347` at `2026-06-26T20:38:49-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e750-0x0052e75e.CreateUserDialogPaneSetInitialAppearanceRollRaw.md` as [UID:00046H] with `86/90`, owner `00003B`, non-reconstructable blank C++, and no-route `+0x26c` proof. Proof: validator `000000003350` at `2026-06-26T20:38:53-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e770-0x0052e832.CreateUserDialogPaneSelectBodyShape.md` as [UID:00046I] with `88/90`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003353` at `2026-06-26T20:38:56-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e840-0x0052e843.CreateUserDialogPaneNullsub43.md` as [UID:00046J] with `90/92`, owner `00003B`, non-reconstructable blank C++, and `retn 4` proof. Proof: validator `000000003356` at `2026-06-26T20:38:58-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e850-0x0052e8b7.CreateUserDialogPaneSelectMale.md` as [UID:00046K] with `88/90`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003358` at `2026-06-26T20:39:01-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e8c0-0x0052e927.CreateUserDialogPaneSelectFemale.md` as [UID:00046L] with `88/90`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003360` at `2026-06-26T20:39:03-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e930-0x0052e94f.CreateUserDialogPaneSetHairColorIndex.md` as [UID:00046M] with `89/91`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003362` at `2026-06-26T20:39:06-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e950-0x0052e96f.CreateUserDialogPaneSetFaceColorIndex.md` as [UID:00046N] with `89/91`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003364` at `2026-06-26T20:39:07-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md` as [UID:00046O] with `87/89`, owner/emitter `00003B`, and exact `bool openRegistration` C++. Proof: validator `000000003366` at `2026-06-26T20:39:09-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md` as [UID:00046P] with `88/90`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003368` at `2026-06-26T20:39:12-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052ea80-0x0052ec80.CreateUserDialogPaneOnDialogAction.md` as [UID:00046Q] with `88/90`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003370` at `2026-06-26T20:39:13-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052ecc0-0x0052ecc9.CreateUserDialogPaneOnKeyEvent.md` as [UID:00046R] with `88/90`, owner/emitter `00003B`, and exact `KeyEvent *event` C++. Proof: validator `000000003372` at `2026-06-26T20:39:15-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052ecd0-0x0052ecf6.CreateUserDialogPaneOnCreateUserReplyEvent.md` as [UID:00046S] with `86/89`, owner/emitter `00003B`, and exact `const PacketEvent *event` / `event->payload` C++. Proof: validator `000000003374` at `2026-06-26T20:39:17-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md` as [UID:00046T] with `86/89`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003376` at `2026-06-26T20:39:19-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052ed10-0x0052ed11.CreateUserDialogPaneNullsub44.md` as [UID:00046U] with `90/92`, owner `00003B`, non-reconstructable blank C++, and `retn` proof. Proof: validator `000000003378` at `2026-06-26T20:39:21-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052ed80-0x0052ef4c.CreateUserDialogPaneSubmitCreateUser.md` as [UID:00046V] with `89/90`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003380` at `2026-06-26T20:39:23-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052ef50-0x0052f155.CreateUserDialogPaneSendCreateAccountRequest.md` as [UID:00046W] with `88/90`, owner/emitter `0000IJ`, and exact file-local C++. Proof: validator `000000003382` at `2026-06-26T20:39:25-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052f160-0x0052f38d.CreateUserDialogPaneSendCreateCharacterRequest.md` as [UID:00046X] with `88/90`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003384` at `2026-06-26T20:39:27-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052f390-0x0052f6e5.CreateUserDialogPaneHandleCreateUserReply.md` as [UID:00046Y] with `89/90`, owner/emitter `00003B`, reconstructable exact C++. Proof: validator `000000003386` at `2026-06-26T20:39:29-04:00`, `ok: 1`.
- [x] Create `by-memory/0x0052f6e5-0x0052f710.CreateUserDialogPaneReplySwitchTableAndPadding.md` as [UID:00046Z] with `90/91`, owner `00003B`, non-reconstructable blank C++, and switch-table/padding proof. Proof: validator `000000003388` at `2026-06-26T20:39:31-04:00`, `ok: 1`.
- [x] Preserve MCP-backed corrections in prose: color setters do not invalidate/refresh; gender helpers do not refresh preview; dispatcher default returns; account helper is file-local/free; reply status is `packet[1]`, message length `packet[2]`, message bytes `packet + 3`; the opener argument is a boolean gate; `OnKeyEvent` uses `KeyEvent *event`; `OnCreateUserReplyEvent` uses `const PacketEvent *event` / `event->payload`; `0x0052ed00` is a base input/control-dispatch bridge with exact `OnDialogShow` source-facing C++ and an inherited-target caveat. Proof: parent/support validators listed in this checklist returned `ok: 1`, with final reruns for [UID:00003B] command `000000003424` and [UID:0000IJ] command `000000003425`.
- [x] Document fallback `word_61FF48` as decoded UTF-16 `U+C091 U+C0AC U+B9AC U+0021` with original variable-name caveat. Proof: [UID:0002QT] parent and [UID:00046Y] reply child contain the caveat; validators `000000003340` and `000000003386` returned `ok: 1`.
- [x] Update [UID:00003B] class notes/declaration and [UID:0000IJ] file notes for split/source-quality placement, exact source-authored child emitters, source-facing event/opener signatures, removal of the stale static member account-helper route, file-local account helper ownership, and no-code children. Proof: final validators `000000003424` and `000000003425` returned `ok: 1`.
- [x] Update [UID:0000OX] appearance-control notes if touched to remove stale claims that old-dialog color setters invalidate/refresh and to record that `SetHairColorIndex`, `SetFaceColorIndex`, and `SetGender` are used here as inline/trivial state setters for the exact child C++ blocks. Proof: validator `000000003405` at `2026-06-26T20:39:49-04:00`, `ok: 1`.
- [x] Update [UID:0000IK], [UID:0001CR], and [UID:0002QU] boundary/source-placement notes. Proof: validators `000000003396` (`CreateUserDialogs`), `000000003399` (`CreateUserDialogVariants`), and final rerun `000000003426` (`CreateUserDialogDestructorAndThunkIsland`) returned `ok: 1`.
- [x] Optional support links [UID:0002SI], [UID:0002B3], and [UID:00025Z] were updated only for the repaired parent/link boundary. Proof: validators `000000003423`, `000000003411`, and `000000003414` returned `ok: 1`; prerequisite mapping validators `000000003332` and `000000003334` restored referenced exact child mappings.
- [x] Confirm no required manual edit to generated files, project-level reports, manual coverage docs, tool state, or IDA DB files. Proof: no manual patches targeted generated/project-level/coverage/tool-state/IDA DB paths; scoped validators were run with `--no-generated-refresh`.
- [x] Run scoped validators for [UID:0002QT], each new child page, and each changed support by-* file. Proof: parent `000000003340`, child commands `000000003342` through `000000003388` as listed above, and support commands `000000003396`, `000000003399`, `000000003405`, `000000003411`, `000000003414`, `000000003423`, `000000003424`, `000000003425`, and `000000003426` all returned `ok: 1`.
- [x] Release leases immediately after the edit/validator batch. Proof: `python tools/leaser/leaser.py B008 unlease` returned `B008: No active leases`; `rg B008 tools/leaser/Agents/current_leases.md` returned no matches.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002QT-CreateUserDialogPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002QT-CreateUserDialogPaneCore-source-quality.md","timestamp":"2026-06-26T20:51:27","uid":"0002QT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
