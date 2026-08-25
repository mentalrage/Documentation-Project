** TARGET-REPORT-UID:0001KG **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Source-Quality Report - [UID:0001KG] UserInfoDialogPane

## Assignment

- Agent: B004
- Assignment ID: `B004-report-user-info-dialog-pane-source-quality-0001KG-mcp-20260623`
- Target: [UID:0001KG] `by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md`
- Required output: report-only for the original pass; supervisor later accepted this report for implementation callback `B004-implement-0001KG-user-info-dialog-pane-20260623`.
- Implementation write-scope used after callback: edited accepted by-* target/support docs and this report checklist only; scoped validators performed tool-owned generated/project-state updates. No IDA DB/tool-state edits and no `-coverage-report.md` files were edited by B004.
- Original target metadata before implementation: `COMPLETION:88`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000OY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OY`, blank emitter position, blank formal C++.
- Implemented target metadata after callback: `COMPLETION:90`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OY`, blank emitter position, blank formal C++.

## Recommendation Summary

Raise [UID:0001KG] from `88/86` to `90/88`. Keep `CANONICAL_OWNER:0000OY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OY`, and blank emitter position unchanged. Keep the target formal `RECONSTRUCTION_CPP CODE` block empty.

The current pass closes several named source-quality blockers: `this[127]` is not a UserInfo-local control host but the inherited `DialogPane::m_controlManager` at `+0x1fc`; control IDs `3..10` are well enough named through the validation/message/option tables; packet opcode `0x53` subtype `1` sends four text fields followed by four selected option labels; and the source-file placement under `login/UserInfoDialogPane.cpp` remains the best owner/emitter route. The constructor launch route remains negative after current MCP xrefs and a local PE route scan, so confidence should rise modestly but stay capped.

No first-draft method-body C++ should be added to [UID:0001KG] in this callback. The target is a broad executable class island with a large constructor, virtual callbacks, private helpers, destructor, ignored thunks, and padding. A partial method-body block would duplicate future child output or over-select one method; a complete block would require final source signatures for the dialog control manager, text/choice controls, alert/close/focus helpers, packet-buffer helpers, and the constructor's control-building API. Because any C++ written must be formal block content, the correct recommendation is a target-specific no-code proof, not prose examples.

## MCP And Binary Provenance

Current IDA MCP evidence was gathered through endpoint `http://127.0.0.1:13337/mcp` against database session `80de0a67`.

Positive session facts:

- `idb_list` reported active worker-backed session `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, worker pid `21816`, `is_active:true`, and `is_analyzing:false`.
- `server_health` with `database='80de0a67'` reported `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and strings cache size `2067`.
- A read-only listener check after a broad-tool timeout showed `127.0.0.1:13337` in `Listen` state owned by python pid `13684`; a follow-up light `server_health` call returned `status:"ok"`.

Tool caveat:

- Broad `insn_query` operand sweeps and a late `survey_binary` refresh were too broad for the active MCP worker and timed out. They are not used as proof. The report relies on successful bounded MCP calls (`lookup_funcs`, `xrefs_to`, `callees`, selected `decompile`, `idb_list`, and `server_health`) plus a supplemental local PE scan with positive controls.

Executable provenance and local PE scan:

- Local executable scanned: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- PE SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- The target executable range hash for raw bytes `0x00599cc0-0x0059bc8b` is SHA-256 `6d7ee091250689b5545a601de50e4ed202deef8f5b65363243412a2aed9902e2`.
- Range size is `0x1fcb` / decimal `8139` (Verified with int_convert.py).

## Current Function And Boundary Evidence

MCP `lookup_funcs` on 2026-06-23 confirms the current IDB boundaries:

| Range | MCP identity | Size |
| --- | --- | --- |
| `0x00599cb3` | not a function | leading padding |
| `0x00599cc0-0x0059aff0` | `sub_599CC0` | `0x1330` / decimal `4912` (Verified with int_convert.py) |
| `0x0059aff0` | not a function | internal padding |
| `0x0059b000-0x0059b0ed` | `sub_59B000` | `0xed` / decimal `237` (Verified with int_convert.py) |
| `0x0059b0ed` | not a function | internal padding |
| `0x0059b0f0-0x0059b110` | `sub_59B0F0` | `0x20` / decimal `32` (Verified with int_convert.py) |
| `0x0059b110-0x0059b130` | `sub_59B110` | `0x20` / decimal `32` (Verified with int_convert.py) |
| `0x0059b130-0x0059b14a` | `sub_59B130` | `0x1a` / decimal `26` (Verified with int_convert.py) |
| `0x0059b150-0x0059b253` | `sub_59B150` | `0x103` / decimal `259` (Verified with int_convert.py) |
| `0x0059b260-0x0059b5b4` | `sub_59B260` | `0x354` / decimal `852` (Verified with int_convert.py) |
| `0x0059b5c0-0x0059bc2c` | `sub_59B5C0` | `0x66c` / decimal `1644` (Verified with int_convert.py) |
| `0x0059bc2d-0x0059bc38` | `sub_59BC2D` | `0xb` adjustor thunk |
| `0x0059bc38-0x0059bc43` | `sub_59BC38` | `0xb` adjustor thunk |
| `0x0059bc50-0x0059bc8b` | `sub_59BC50` | `0x3b` / decimal `59` (Verified with int_convert.py) |
| `0x0059bc8b` | not a function | following padding |
| `0x0059bc90` | `sub_59BC90` successor | `0x1508` / decimal `5384` (Verified with int_convert.py) |

Supplemental raw PE bytes confirm all padding fences are `0xcc`:

- `0x00599cb3-0x00599cc0`: thirteen `cc` bytes before the constructor.
- `0x0059aff0-0x0059b000`: sixteen `cc` bytes before `OnButtonCommand`.
- `0x0059b0ed-0x0059b0f0`: three `cc` bytes.
- `0x0059b14a-0x0059b150`: six `cc` bytes.
- `0x0059b253-0x0059b260`: thirteen `cc` bytes.
- `0x0059b5b4-0x0059b5c0`: twelve `cc` bytes.
- `0x0059bc2c-0x0059bc2d`: one `cc` byte before ignored adjustor thunks.
- `0x0059bc43-0x0059bc50`: thirteen `cc` bytes after ignored adjustor thunks.
- `0x0059bc8b-0x0059bc90`: five `cc` bytes before the [UID:0001KI] UserList successor.

Boundary conclusion: [UID:0001KG] should remain `0x00599cc0-0x0059bc8b`. The predecessor padding and successor padding are already ignored; the successor at `0x0059bc90` is not part of the user-info form.

## Xref, Route, And Reachability Evidence

MCP `xrefs_to` current-session facts:

- `0x00599cc0` constructor: zero xrefs, with MCP message "No cross-references to this address".
- `0x0059b000` command handler: one data xref from `0x0062e670` vtable slot.
- `0x0059b150` OK-state updater: one data xref from `0x0062e674` vtable slot.
- `0x0059b260` validation helper: one code xref from `0x0059b058` inside `sub_59B000`.
- `0x0059b5c0` packet sender: one code xref from `0x0059b066` inside `sub_59B000`.
- `0x0059bc50` scalar deleting destructor: code xrefs from adjustor thunks `0x0059bc33` and `0x0059bc3e`, plus data xref from `0x0062e628`.

MCP read-only data xrefs tie the `.rdata` companion to the constructor:

- `0x0062e628` is referenced from constructor address `0x00599d20`.
- `0x0062e688` is referenced from constructor address `0x00599d26`.
- `0x0062e6b8` is referenced from constructor address `0x00599d30`.
- The dialog title at `0x0062e6c0` is referenced from constructor address `0x00599d03`.
- `USERINFO.EPF` at `0x0062e7ec` is referenced from constructor addresses `0x00599e3a` and `0x0059af49`.
- Option-list roots are referenced from the constructor: blood type at `0x0062e808`, residence at `0x0062e818`, primary access method at `0x0062e888`, and discovery/referral at `0x0062e8c4`.

Local PE route scan:

- For target constructor `0x00599cc0`, the PE scan found zero `E8` call, `E9` jump, and near conditional branch rel32 transfers to the target.
- The same scan found zero little-endian dword hits for the target VA `0x00599cc0`, target RVA `0x00199cc0`, or target raw offset `0x00199280`.
- Positive control: `0x0059b260` has an `E8` rel32 hit at `0x0059b058`, matching the command handler's call to `ValidateInput`.
- Positive control: `0x0059b5c0` has an `E8` rel32 hit at `0x0059b066`, matching the command handler's call to `SendUserInfo`.
- Positive control: `0x0059b000` has a VA dword hit in `.rdata` at VA `0x0062e670`, matching the vtable slot.
- Positive control: `0x0059bc50` has two `E9` rel32 hits from adjustor thunks and a VA dword hit at `.rdata` VA `0x0062e628`.

Reachability conclusion: the constructor path is still not a direct call, direct branch, or simple VA/RVA/raw-offset pointer route in the executable. This does not defeat ownership because vtable stores, read-only data use, method cluster, and proposed source-tree placement are coherent, but it does cap confidence below a route-proven final state.

## Behavior Evidence Reanalysis

`OnButtonCommand` / `sub_59B000`:

- Command ID `1` is OK. It calls `ValidateInput` at `0x0059b058`.
- Validation status `10` is success. On success, it calls `SendUserInfo` at `0x0059b066`, then shared close/slide helpers.
- Validation status `0..7` indexes `m_validationMessages` and focuses control `status + 3`, tying the validation enum directly to control IDs `3..10`.
- Command ID `2` is cancel/close.

`UpdateOkButtonState` / `sub_59B150`:

- It fetches OK button control ID `1`.
- It fetches text controls `3`, `4`, `5`, and `6` and checks each with the text-control empty-test helper.
- It fetches choice controls `7`, `8`, and `9` and checks selected index against `-1`.
- It enables or disables the OK button through the control virtual slots. It intentionally does not gate on control `10`; control `10` is enforced by `ValidateInput` and sent by `SendUserInfo`.

`ValidateInput` / `sub_59B260`:

- It reads controls through `this[127]`, which is `DialogPane::m_controlManager` at inherited offset `+0x1fc` / decimal `508` (Verified with int_convert.py), not a new UserInfo-local control host.
- It uses a stack wide buffer of `0x80` / decimal `128` (Verified with int_convert.py) elements.
- Control `3` is the name text field. Any ASCII digit causes status `0`.
- Control `4` is resident-registration prefix. Non-digit failure or later checksum failure maps to status `1`.
- Control `5` is resident-registration suffix. Non-digit failure maps to status `2`; the checksum uses `(11 - sum % 0xb) % 0xa` against the seventh suffix digit.
- Control `6` is parent-name. Any ASCII digit causes status `3`.
- Control IDs `7`, `8`, `9`, and `10` are required selections returning statuses `4`, `5`, `6`, and `7` respectively when missing.
- Success returns status `10`.

`SendUserInfo` / `sub_59B5C0`:

- The helper initializes packet state, writes opcode `0x53` / decimal `83` / ASCII `S` (Verified with int_convert.py), then writes subtype `1`.
- It serializes four text fields in order: name, resident-id prefix, resident-id suffix, and parent name.
- It then serializes four selected option labels in order: blood type, residence, primary access method, and discovery reason.
- Text and selected labels are converted through `WideCharToMultiByte` into bounded 256-byte scratch storage, then emitted as one-byte length plus bytes.
- The final packet length is stored in two header bytes; payloads over `0x1000` / decimal `4096` (Verified with int_convert.py) hit the compiler range-check failure path.
- The final send uses `dword_67A7EC`, documented project-wide as [UID:0000Q5] `g_packetSender`, and calls the Socket-owned queue/send funnel at `0x00574bb0`.

Event/focus wrappers:

- `0x0059b0f0` refreshes focus through `0x0049fe20` and forwards input through `0x0049e240`.
- `0x0059b110` refreshes focus through `0x0049fe20` and forwards key handling through `0x0049e6e0`.
- `0x0059b130` updates focus/hover through `0x0049fc00` and refreshes/repaints through a virtual slot.

Constructor:

- The constructor is large and current decompiler output is less suitable for final source, but MCP/read-only-data xrefs prove it installs `UserInfoDialogPane` vtable views, consumes the title and `USERINFO.EPF`, copies validation messages to `this+0x26c`, builds/looks up controls, decodes packet-supplied fields, populates option controls, applies preselected options when present, and updates the OK state.
- The validation-message table begins at derived offset `+0x26c` / decimal `620` (Verified with int_convert.py), immediately after the current documented `DialogPane` base tail. This supports `wchar_t m_validationMessages[8][128]` as the source-facing class field already present on [UID:0000FM].

Destructor and thunks:

- `0x0059bc2d` and `0x0059bc38` are compiler adjustor thunks into `0x0059bc50`; they remain ignored through [UID:0001KH] and [UID:0000VN].
- `0x0059bc50` is the scalar deleting destructor wrapper/body for the source destructor relationship. The decompiler's historical `boost::exception` pollution is not ownership evidence.

## Naming, Type, And Layout Decisions

Resolved or strengthened in this pass:

- `this[127]` should be documented as inherited `DialogPane::m_controlManager`, not `m_controlHost` or a UserInfo-local `m_controls` field. The `DialogPaneLayout` page documents `+0x1fc` as `DialogControlManager *m_controlManager`, and UserInfo's `this[127]` equals `+0x1fc`.
- Control ID constants already present on [UID:0000FM] are source-facing enough and should be retained: OK `1`, cancel `2`, name `3`, resident-id prefix `4`, resident-id suffix `5`, parent name `6`, blood type `7`, residence `8`, primary access method `9`, discovery reason `10`.
- Prefer `m_residenceCombo` over `m_regionCombo` because the validation message and support literal role are residence/region with a "residence required" message. `m_regionCombo` can remain a historical/secondary wording only if needed for literal-list interpretation.
- Prefer `m_discoveryReasonCombo` over `m_referralSourceCombo` because validation status `7` and the option list represent first-discovery/reason semantics. `m_referralSourceCombo` remains a weak alternate for the literal-list domain but should not be the primary field name.
- `m_primaryAccessMethodCombo` is a better source-facing name than generic method/access control names because the option list is the user's primary play/access method list.
- `m_validationMessages[8][128]` is supported by constructor copies, `OnButtonCommand` table indexing, eight validation statuses, and offset `+0x26c`.
- Packet field order should be documented as name, resident-id prefix, resident-id suffix, parent name, blood type label, residence label, primary access method label, discovery reason label. Avoid generic "form field A/B/C" names.
- Packet constants can be documented as opcode `0x53` subtype `1`; the exact original constant spellings are not proven and should not be invented.

Rejected generated/decompiler names:

- `this[127]` as `m_controlHost` / `m_controls`: superseded by `DialogPane::m_controlManager`.
- `aUs_1`, `off_62E7EC`, `ERINFO.EPF`, `aCd`, and `off_62E8F0`: IDA/string-label artifacts; the source roles are `USERINFO.EPF` and full localized option/message literals.
- `RadioGroupControlPane` as a final type for every control: generated output lead only. The binary patterns show text/edit controls and choice/list controls, but exact support class names should follow the documented DialogControlManager/control pages rather than generated casts.
- Treating `g_packetSender` as UserInfo-owned: rejected. It is a Socket-owned process sender global; UserInfo is only a consumer.

## Ownership And Source Placement Alternatives

1. Keep [UID:0000OY] `UserInfoDialogPane.cpp` as canonical owner/emitter. This is the best supported path. The target is a coherent class/method island, read-only data and vtable consumers are local to the constructor/class, source tree places it under `login/`, and the behavior is a pre-login account/user-information form.
2. [UID:0000FM] `UserInfoDialogPane` class owner. Correct for class declaration and method roles, but the by-memory executable target already routes through the file root for generated output. The class page should stay synchronized with the field/control/validation enum conclusions.
3. `LoginDialogPane` / main-menu login owner. Rejected as canonical owner for this exact range. The login family explains source placement, but no direct current xref route to `0x00599cc0` was found and the UserInfo range has its own class/file pages and read-only data.
4. `CreateUserDialogs` / account-create family. Rejected. That page is a non-standalone family index for create-user variants; UserInfo is a separate account-information form with its own file root.
5. `UserListDialogPane` or adjacent user-list owner. Rejected. The executable successor begins at `0x0059bc90`, and read-only data successor begins at `0x0062e8fc`. UserInfo's range and `.rdata` island end before UserList.
6. `Socket`, packet helpers, or `g_packetSender` as owner. Rejected. `SendUserInfo` consumes the sender, but Socket owns the queue/send global and method.
7. No-owner/non-emitting. Rejected. The range is reconstructable source-authored dialog code with a valid owner/emitter route through `login/UserInfoDialogPane.cpp`; only method-body C++ remains withheld.

## Split And C++ Readiness Decision

Formal C++ recommendation for [UID:0001KG]: keep the target's formal `RECONSTRUCTION_CPP CODE` block empty.

Target-specific no-code proof:

- The target is not a single source method. It spans a large constructor, command handler, input/key/focus callbacks, OK-state helper, validation helper, packet sender, scalar deleting destructor, ignored adjustor thunks, and alignment.
- A formal block containing only one or two bodies would be a partial duplicate waiting to happen if exact child pages are later created.
- A formal block containing all bodies would require finalized support signatures and source names for `DialogControlManager`, text edit controls, choice/list controls, alert/close/focus helpers, packet buffer helpers, and constructor control-building helpers. Current evidence resolves the roles and preferred names well enough for documentation, but not enough for copy/paste-ready original-source-shaped method bodies.
- Generated `class_UserInfoDialogPane.cpp` is decompiler-shaped and contains generated scaffolding, casts, artificial vtable structures, and imprecise control types. It is useful as a lead but should not be elevated into formal reconstruction C++.
- Current class and read-only data formal C++ already carry safe declarations/literals through [UID:0000FM] and [UID:00026T]. Adding a weak broad method-body block to [UID:0001KG] would reduce source quality.

Split investigation:

- Exact method child boundaries are known and are implementation-ready if the supervisor wants a future split: constructor `0x00599cc0-0x0059aff0`, command handler `0x0059b000-0x0059b0ed`, input wrapper `0x0059b0f0-0x0059b110`, key wrapper `0x0059b110-0x0059b130`, focus-change wrapper `0x0059b130-0x0059b14a`, OK-state helper `0x0059b150-0x0059b253`, validation helper `0x0059b260-0x0059b5b4`, packet sender `0x0059b5c0-0x0059bc2c`, and scalar deleting destructor `0x0059bc50-0x0059bc8b`.
- Do not split during the immediate accepted implementation unless the supervisor explicitly expands the callback. The current assignment can improve score and documentation without creating nine new pages, and splitting alone would not make the method bodies formal-C++ ready because the same support API blockers remain.
- If a future split is approved, keep ignored thunks [UID:0001KH] and padding in ignored ledgers, and make each method child inherit owner/emitter [UID:0000OY] with formal C++ blank until the exact support API names/signatures are finalized for that method.

## Score And Metadata Recommendation

Target [UID:0001KG]:

- `COMPLETION:90`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000OY`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OY`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE`: blank

Reason for completion increase: current MCP and PE evidence should replace older route wording, and the report resolves source-facing field/control/packet/message names at documentation level rather than restating them as unresolved.

Reason confidence is capped at `88`: no direct constructor caller, no MCP xref to `0x00599cc0`, no PE direct-transfer route, no VA/RVA/raw-offset pointer route, original packet constant spellings are not proven, and formal method-body C++ is still withheld for broad-target/support-API reasons.

Support docs:

- Recommend [UID:0000FM] `by-class/UserInfoDialogPane.md` rise from `88/86` to `90/88` after it incorporates the `m_controlManager`, preferred control field names, packet-field order, and no-method-body proof.
- Recommend [UID:0000OY] `by-file/UserInfoDialogPane.md` rise from `88/86` to `90/88` after it incorporates current session `80de0a67` evidence, source-placement confirmation, route-scan negative proof, and generated-output caveat.
- [UID:00026T] `by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md` can remain `88/92`; it needs only wording cleanup replacing `m_controlHost` / `m_controls` with inherited `DialogPane::m_controlManager` and preferring `m_residenceCombo` / `m_discoveryReasonCombo`.
- `by-type/by-struct/DialogPaneLayout.md`, [UID:0000Q5] `by-global/g_packetSender.md`, `by-file/CreateUserDialogs.md`, and `by-file/LoginDialogPane.md` already contain sufficient or non-contradictory support context; no edit is required unless a callback reviewer wants explicit cross-reference reinforcement.

## Target And Support Edits Needed If Accepted

Required target edit:

- Update `by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md` to `90/88`, keep owner/emitter/reconstructable and blank C++ unchanged.
- Add a dated `2026-06-23 B004 MCP-backed source-quality recheck` section containing the MCP session/provenance, exact function inventory, byte/hash/padding evidence, current xrefs, route-scan negative proof with positive controls, decompile-backed behavior for command/OK-state/validation/send/focus wrappers, `m_controlManager` resolution, packet-field order, rejected alternatives, score rationale, and target-specific no-code proof.
- Supersede older wording that says helper/field/control names remain unresolved. The remaining caveat is not generic "needs investigation"; it is specifically the lack of constructor route and lack of formal support API signatures for method-body C++.

Required support synchronization:

- Update `by-class/UserInfoDialogPane.md` to `90/88`; keep existing formal class declaration block unless a stronger already-accepted class block exists. Add the current evidence that inherited `DialogPane::m_controlManager` replaces `m_controlHost` / `m_controls`, prefer the field/control names listed in this report, preserve validation enum/status mapping, preserve the no-route constructor caveat, and record that broad method-body C++ remains blank on [UID:0001KG].
- Update `by-file/UserInfoDialogPane.md` to `90/88`; add current session `80de0a67` evidence, PE negative route scan, source placement under `NexusTK/login/`, generated-output caveat, and no-code proof.
- Update `by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md` wording only: replace `m_controlHost` / `m_controls` with inherited `DialogPane::m_controlManager`; prefer `m_residenceCombo` and `m_discoveryReasonCombo`; preserve existing score and formal read-only data C++ unless the implementation reviewer decides the support update warrants a one-point completion bump.

Already sufficient / no edit expected:

- `by-type/by-struct/DialogPaneLayout.md`: already documents `+0x1fc` as `DialogControlManager *m_controlManager` and explains why this is preferred over `m_controls`.
- `by-global/g_packetSender.md`: already documents `dword_67A7EC` as Socket-owned `g_packetSender` and rejects feature-local ownership.
- `by-file/CreateUserDialogs.md`: already non-standalone and does not contradict UserInfo ownership.
- `by-file/LoginDialogPane.md`: source-family context is sufficient and does not own [UID:0001KG].

## Expected Validators After Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for each changed by-* doc:

- `python .\tools\validator.py --mode file --file by-memory\0x00599cc0-0x0059bc8b.UserInfoDialogPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class\UserInfoDialogPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file\UserInfoDialogPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md --apply --queue-timeout 240` if the read-only support wording is edited.

## Supervisor-Owned Coverage Text

Do not edit coverage reports during B-agent implementation. If accepted and verified, supervisor should replace these rows.

`by-memory/-coverage-report.md` replacement for [UID:0001KG]:

```text
    - [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md) 0x00599cc0-0x0059bc8b | class | UserInfoDialogPane : reconstructable : 90% : strong : 2026-06-23 B004 MCP-backed source-quality recheck documents active session 80de0a67 evidence, exact method boundaries and padding, constructor no-xref/no-PE-route proof with positive controls, vtable/read-only-data refs, inherited DialogPane::m_controlManager at +0x1fc, final control/validation/packet-field naming, opcode 0x53 subtype 1 send flow, owner/emitter retention through UserInfoDialogPane.cpp, rejected Login/CreateUser/UserList/Socket/no-owner alternatives, and a target-specific blank-C++ no-code proof.
```

`by-class/-coverage-report.md` replacement for [UID:0000FM] if class score is raised:

```text
- [UID:0000FM][UserInfoDialogPane](by-class/UserInfoDialogPane.md) : reconstructable : 90% : strong : account/user information form with constructor, validation, OK-state, packet serialization, event/focus forwarding, read-only data, thunk/boundary evidence, inherited DialogPane::m_controlManager, final control/validation enum names, packet-field order, and blank method-body C++ rationale documented.
```

`by-file/-coverage-report.md` replacement for [UID:0000OY] if file score is raised:

```text
- [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md) : reconstructable : 90% : strong : login/UserInfoDialogPane.cpp source role with current MCP session 80de0a67 method sizes, validation/send flow, vtable/read-only-data refs, no direct constructor route after MCP/PE checks, corrected control-manager/packet-field naming, generated-output caveat, UserList boundary rejection, and blank aggregate method-body C++ proof documented.
```

No coverage row is required for [UID:00026T] if only wording changes and score stays `88/92`.

## Open Questions Closed Or Capped

- Field/control names: closed to documentation level. Use inherited `m_controlManager`, `m_nameEdit`, `m_residentIdPrefixEdit`, `m_residentIdSuffixEdit`, `m_parentNameEdit`, `m_bloodTypeCombo`, `m_residenceCombo`, `m_primaryAccessMethodCombo`, and `m_discoveryReasonCombo`.
- Packet fields/subtype: closed to documentation level. Opcode `0x53` subtype `1`; field order is four text fields then four selected option labels.
- Validation enum/message table: closed to documentation level. Statuses `0..7` index eight messages and focus controls `3..10`; status `10` succeeds.
- Caller/source route: investigated and capped. MCP xrefs and PE route scan found no constructor route; positive controls prove the scans can find internal calls/vtable dwords.
- Support type names: partially capped, not deferred. `DialogPane::m_controlManager` is accepted; text/choice control concrete class/API signatures are not strong enough for method-body formal C++.
- C++ readiness: closed for this target as no-code. Method-body examples must not be placed outside formal blocks, and the formal block should stay empty for [UID:0001KG].

## Implementation Tracking Checklist

- [x] Target `by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md` updated to `COMPLETION:90`, `CONFIDENCE:88`, owner/emitter/reconstructable unchanged, formal C++ blank. Proof: header now has `90/88`, `CANONICAL_OWNER:0000OY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OY`, blank emitter position, and empty `RECONSTRUCTION_CPP CODE` block.
- [x] Target receives the `2026-06-23 B004 MCP-backed source-quality recheck` with session/provenance, function inventory, padding/hash, xrefs, route-negative proof, behavior details, naming decisions, rejected alternatives, score rationale, and no-code proof. Proof: target section `2026-06-23 B004 MCP-Backed Source-Quality Recheck` records session `80de0a67`, executable and range hashes, exact inventory/padding, MCP/PE route-negative evidence with controls, decompile-backed behavior, `m_controlManager`, field/control names, rejected alternatives, `90/88` rationale, and blank-C++ no-code proof.
- [x] `by-class/UserInfoDialogPane.md` updated to `90/88` with `m_controlManager`, final field/control/validation/packet names, no-route cap, and no-method-body proof; existing formal declaration preserved unless a stronger accepted declaration is already present. Proof: header now has `90/88`, the existing formal class declaration is unchanged, and Data/Evidence/Changes notes document `DialogPane::m_controlManager`, preferred control names, validation/result mapping, packet field order, constructor no-route proof, and [UID:0001KG] no-method-body proof.
- [x] `by-file/UserInfoDialogPane.md` updated to `90/88` with current MCP/PE route evidence, source-placement rationale, generated-output caveat, rejected owner alternatives, and no-code proof. Proof: header now has `90/88`; Evidence/Ownership/Changes notes record session `80de0a67`, PE SHA/range hash, zero constructor route/pointer hits with controls, `NexusTK/login/` placement, generated-output lead caveat, UserList/Login/CreateUser/Socket/no-owner rejections, and the broad-target blank-C++ proof.
- [x] `by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md` checked/updated for `m_controlManager`, preferred residence/discovery field names, and no stale `m_controlHost` / `m_controls` primary wording. Proof: score/formal C++ unchanged at `88/92`; Control/Field/Helper table now uses `DialogPane::m_controlManager`, primary `m_residenceCombo`, primary `m_discoveryReasonCombo`, and preserves older alternates only as historical/secondary wording.
- [x] `by-type/by-struct/DialogPaneLayout.md` checked as already sufficient for `+0x1fc` `DialogControlManager *m_controlManager`, or updated only if implementation reviewer finds a direct contradiction. Proof: read-only check found the page already documents `+0x1fc` as `DialogControlManager *m_controlManager` and says to prefer `m_controlManager` over `m_controls`; no edit was needed.
- [x] `by-global/g_packetSender.md`, `by-file/CreateUserDialogs.md`, and `by-file/LoginDialogPane.md` checked as already sufficient/no edit, unless stale contradiction is found during implementation. Proof: read-only checks found `g_packetSender` remains Socket-owned and rejects feature-local ownership; `CreateUserDialogs` is non-standalone and does not claim [UID:0001KG]; `LoginDialogPane` provides source-family context without owning this range. No edits were needed.
- [x] Formal [UID:0001KG] C++ remains blank; no prose-only/sample/example method-body C++ snippets are added to target/support docs. Proof: target `RECONSTRUCTION_CPP CODE` block is empty; implementation added behavior prose/no-code proof only. Existing formal class declaration on [UID:0000FM] and existing formal read-only literal block on [UID:00026T] were preserved and no method-body snippets were added outside formal blocks.
- [x] Historical/stale assumptions preserved or superseded explicitly: `m_controlHost` / `m_controls`, generated control casts, IDA string-label fragments, constructor direct-route assumptions, UserList adjacency, Socket/g_packetSender ownership, and no-owner/non-emitting alternatives. Proof: target/support notes explicitly mark `m_controlHost` / `m_controls` as superseded, generated/IDA labels and generated casts as rejected, no constructor route as PE/MCP-negative with controls, UserList adjacency/Login/CreateUser/Socket/no-owner alternatives as rejected, and Socket ownership of `g_packetSender` retained.
- [x] Validators run for every changed by-* file and command/exit code/ok count recorded. Proof:
  - `python .\tools\validator.py --mode file --file by-memory\0x00599cc0-0x0059bc8b.UserInfoDialogPane.md --apply --queue-timeout 240` from `source-3/project-documentation`: exit code `0`, `ok: 1`. Reported validator-owned side effects included `completion_update 0001KG`, `confidence_update 0001KG`, UID link insertions, reference-index additions, `project-level/-auto-completion-stats.md` projected stats update, `tools/validator.ini` registry rebuild, `auto-generated/NexusTK/login/UserInfoDialogPane.cpp` update, `auto-generated/NexusTK/ui/dialogs/SpellMenuDialogs.cpp` update, `auto-generated/-ag-file-coverage.md` update, `auto-generated/-ag-memory-coverage.md` update, and validator backup `tools/validator_autogen_backup/20260623-184516`.
  - `python .\tools\validator.py --mode file --file by-class\UserInfoDialogPane.md --apply --queue-timeout 240` from `source-3/project-documentation`: exit code `0`, `ok: 1`. Reported validator-owned side effects included `completion_update 0000FM`, `confidence_update 0000FM`, UID link insertions, reference-index additions, stats update/removal, `tools/validator.ini` registry rebuild, `auto-generated/NexusTK/login/UserInfoDialogPane.cpp` update, and validator backup `tools/validator_autogen_backup/20260623-184529`.
  - `python .\tools\validator.py --mode file --file by-file\UserInfoDialogPane.md --apply --queue-timeout 240` from `source-3/project-documentation`: exit code `0`, `ok: 1`. Reported validator-owned side effects included `completion_update 0000OY`, `confidence_update 0000OY`, UID link insertions, `project-level/-auto-completion-stats.md` projected stats update, and `tools/validator.ini` registry rebuild; generated C++ and autogen coverage reports were no-op in this run.
  - `python .\tools\validator.py --mode file --file by-memory\0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md --apply --queue-timeout 240` from `source-3/project-documentation`: exit code `0`, `ok: 1`. Reported existing `missing_ref_target` warnings for stale registered UserList paths `by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md` and `by-memory/0x0062e960-0x0062e998.UserListDialogPaneVtableLeadInData.md`, plus UID link insertions, `project-level/-auto-completion-stats.md` projected stats update, and `tools/validator.ini` registry rebuild.
- [x] Supervisor-owned coverage replacement text above applied only by supervisor after verification; B004 must not edit any `-coverage-report.md`. Proof: B004 did not manually edit any `-coverage-report.md`; exact replacement rows remain in this report for supervisor application.
- [x] Remaining unapplied items, if any, listed with exact blocker such as lease conflict or MCP unavailability. Proof: no accepted non-coverage item remains unapplied. Leases were taken earlier for the four changed by-* docs; cleanup command reported `Rejected[No active lease]` for all four because the leases had expired, and `current_leases.md` has no B004 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001KG-UserInfoDialogPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0001KG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
