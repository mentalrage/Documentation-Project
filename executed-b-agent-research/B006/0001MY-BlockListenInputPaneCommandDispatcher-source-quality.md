** TARGET-REPORT-UID:0001MY **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001MY BlockListenInputPaneCommandDispatcher Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:0001MY][by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md](../../../../../by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) from a documented blank-C++ dispatcher to a first-draft C++ ready `BlockListenInputPane::HandleCommandSelection()` method.
- Final disposition: keep the current owner/emitter route through [UID:00000X][BlockListenInputPane](../../../../../by-class/BlockListenInputPane.md), keep `RECONSTRUCTABLE:TRUE`, keep the switch-table bytes at `0x005b6c00-0x005b6c30` as non-source support data for this method, and do not attach the adjacent raw packet helper [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](../../../../../by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) to this class method.
- Required action after supervisor validation: update the target page, class/file support pages, and split-index support page with the current MCP-backed source-quality evidence and exact formal C++ block. Do not edit any `-coverage-report.md` file directly.
- Confidence: high for method boundary, vtable route, command behavior, source file/class placement, helper names, and first-draft C++ shape; below final-audit only because original symbol names for alert ids and the exact virtual return type are inferred from surrounding source shape rather than recovered symbols.

## Target

- Target UID: `0001MY`
- Target path: `by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md`
- Assignment id: `B006-report-0001MY-BlockListenInputPaneCommandDispatcher-source-quality-20260627`
- Source queue row at assignment: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, row reported `80/86`, combined `83.0`, reconstructable `true`, reports `0`.
- Current target header at report time: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00000X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000X`, blank formal C++.
- Current generated coverage context: `auto-generated/-ag-memory-coverage.md` routes [UID:0001MY] through [UID:00000X] to `auto-generated/NexusTK/social/BlockListenInputPanes.cpp`.

## Current Target State

- Existing owner/emitter state is correct: [UID:00000X] `BlockListenInputPane` is the direct semantic class owner, and the class routes through [UID:0000HS] `BlockListenInputPanes.cpp`.
- Existing C++ state is stale: the target has a blank `RECONSTRUCTION_CPP CODE` block even though the current child, class, file, input helper, constructor, vtable, and alert support docs now resolve the stated blockers enough for first-draft source.
- Existing blocker text says final C++ stays blank pending source-quality names for input helpers, config vector fields, and alert/dialog classes. That is no longer accurate as a C++ blocker:
  - `0x004f2310` is already documented as [UID:00035S] `LineInputPaneTextLength`, and accepted sibling source uses `GetTextLength()` / `TextLength()`.
  - `0x004f2300` is already documented as [UID:00035R] `LineInputPaneCopyText`, and accepted sibling source uses `CopyText(...)`.
  - The block-list vector is already used as `g_pConfig->m_blockListenNames` by [UID:0001MX] `BlockListenInputPane::OnKeyInput(const InputEvent *)`.
  - `0x004f0350`, `dword_67A750`, `dword_67A764`, `sub_49FEB0`, and `off_613A18` are already documented through support pages and sibling C++ as `g_pLanguageMan->GetLocalizedString(...)`, `g_activeMapPane`, `AlertPane`, and `kDialogOkButtonText`.
  - Add/delete prompt constructors are already source-ready as `new AddToBlockListenInputPane()` / `new DeleteFromBlockListenInputPane()` source operations even though the compiler inlined their trivial constructor sequence at this allocation site.
- Related target/support docs checked:
  - [UID:00000X][by-class/BlockListenInputPane.md](../../../../../by-class/BlockListenInputPane.md)
  - [UID:0000HS][by-file/BlockListenInputPanes.md](../../../../../by-file/BlockListenInputPanes.md)
  - [UID:0001MW][by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md](../../../../../by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
  - [UID:0001MX][by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md](../../../../../by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md)
  - [UID:0001MZ][by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md](../../../../../by-memory/0x005b6c80-0x005b6cc0.AddToBlockListenInputPaneConstructor.md)
  - [UID:0001N1][by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md](../../../../../by-memory/0x005b7100-0x005b7140.DeleteFromBlockListenInputPaneConstructor.md)
  - [UID:0002RY][by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md](../../../../../by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md)
  - [UID:00035R][by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md](../../../../../by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md)
  - [UID:00035S][by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md](../../../../../by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md)
  - [UID:0000K7][by-file/InputPanes.md](../../../../../by-file/InputPanes.md)
  - Central executed B reports for [UID:0001MV], [UID:0001MW], [UID:0001MX], [UID:0001MZ], [UID:0001N1], and [UID:0002RY].

## Executive Recommendation

- Keep `CANONICAL_OWNER:00000X`, `EMITTER_UIDS:00000X`, and `RECONSTRUCTABLE:TRUE`.
- Raise the target from `86/88` to `90/91`.
- Replace the stale blank-C++ blocker with first-draft formal C++ for `void BlockListenInputPane::HandleCommandSelection()`.
- Keep [UID:00000X] class and [UID:0000HS] file metadata unchanged unless the supervisor wants a broader parent score pass. The support docs should still be updated to remove the stale "dispatcher C++ still separate/blank" statement and to preserve this report's evidence at target-level detail.
- Do not create a new child for `0x005b6c00-0x005b6c30`; it is switch/jump-table data for this method.
- Do not merge this method with [UID:0001MX] key handling, [UID:0001MZ]/[UID:0001N1] raw constructors, [UID:0001N0]/[UID:0001N2] submit/confirm handlers, or [UID:0002RY] raw packet helper.

## Supervisor Active Recheck

- Current supervisor assignment is report-only research first. No target/support by-* docs were edited.
- The target did not require split repair before this report: IDA models `0x005b6a20-0x005b6bff` as one function, `0x005b6bff` is not a function start, and `0x005b6c00-0x005b6c30` is data referenced by the switch at `0x005b6a7b`.
- Every score blocker named by the target was chased in this pass:
  - input helper names resolved through [UID:00035S]/[UID:00035R] and accepted command-input source convention;
  - config vector field resolved through [UID:0001MX] as `g_pConfig->m_blockListenNames`;
  - alert and dialog classes resolved through existing `AlertPane`, `g_activeMapPane`, `kDialogOkButtonText`, and sibling prompt constructor docs;
  - packet helper ownership remains separate with current negative route evidence, not a blocker for this method's C++;
  - aggregate C++ risk is avoided by emitting only the exact method body in this target.

## Inference Research Guidance Check

- Stale Wave2/Wave3 material was not used.
- IDA facts are separated from source-shape inference. IDA provides the modeled body, switch table, refs, callees, vtable slots, and constants. Current by-* docs provide accepted helper/source names. The source-facing `void` method shape and constant names are inferred from accepted command-input pages and side-effect-only virtual handler patterns.
- Existing documentation was treated as a lead, not authority. The old target blocker text is now stale because support docs created after it already resolved the named helper and field issues.
- Lack of exact original symbol proof is not used as a reason to retain `sub_`, `dword_`, or decompiler temporary names in the recommended C++.

## Heuristic / Inference Reanalysis And Validation

### Method name and signature

- Best source-facing name: `BlockListenInputPane::HandleCommandSelection()`.
- Evidence: the class page already names the method this way; the body reads one command character and dispatches command selection rather than raw key input. It is distinct from [UID:0001MX] `BlockListenInputPane::OnKeyInput(const InputEvent *)`.
- Return type inference: recommend `void`.
  - IDA currently decompiles `__int16 __thiscall sub_5B6A20(_DWORD **this)`, but the apparent return value is a decompiler artifact of last-register state around constructors, `operator new`, default switch math, and exception cleanup.
  - Accepted sibling pages such as `QuitInputPane::OnConfirmInput()` and `PostInputPane::OnConfirmInput()` model one-character line-input submit/confirm handlers as side-effect-only `void` methods using `GetTextLength()` and `CopyText(...)`.
  - The only observed incoming route is the vtable slot `0x00630694`; no direct caller is present that consumes a return value.
  - Remaining uncertainty: if a later class hierarchy pass proves this virtual slot has a non-void source signature, the body can be adjusted. Current evidence makes `void` the strongest human-source shape and should not block first-draft C++.

### Inherited input helpers

- Best source-facing names: inherited `GetTextLength()` and `CopyText(...)`.
- Evidence:
  - [UID:00035S] `0x004f2310-0x004f231b.LineInputPaneTextLength` documents `sub_4F2310` as a `LineInputPane` text-length accessor, returning current editable-child text length from the child at `this+0xfc`.
  - [UID:00035R] `0x004f2300-0x004f230f.LineInputPaneCopyText` documents `sub_4F2300` as a `LineInputPane` text-copy accessor, forwarding to the editable child at `this+0xfc`.
  - Accepted `QuitInputPane`, `PostInputPane`, `SpellSpellInputPane`, `EmotionInputPane`, and chat input pages use `GetTextLength()`/`TextLength()` and `CopyText(...)`.
- Rejected alternative: leaving `sub_4F2310` / `sub_4F2300` or "shared input helper" in final C++ is weaker and no longer necessary.

### Config vector field and list count

- Best source-facing field: `g_pConfig->m_blockListenNames`.
- Evidence:
  - [UID:0001MX] first-draft key-handler C++ already iterates `g_pConfig->m_blockListenNames.begin` to `.end`.
  - This dispatcher uses the same global and offsets `+0x2918fc` / `+0x291900`; IDA disassembly subtracts begin from end and shifts by two, matching a 4-byte entry/count stride in the currently documented vector representation.
- Rejected alternatives:
  - `dword_67A7C8` in source C++ is rejected as a raw IDA global.
  - A generic `m_names` or separate `m_ignoreNames` field is weaker because current accepted docs consistently use `m_blockListenNames`.
- Remaining uncertainty: exact final project-wide `Config` type declaration is still broader than this target. It does not block this method from using the already accepted field name.

### Command cases and resources

- Best command model:
  - `A/a` opens add prompt if block-listen count is below `0x28` / 40.
  - `A/a` opens full-list alert id `0xf2` / 242 otherwise.
  - `D/d` opens delete prompt if count is nonzero.
  - `D/d` opens empty-list alert id `0xf3` / 243 otherwise.
  - Other one-character input returns without action.
- Evidence: live IDA decompilation/disassembly branches at `0x005b6a82`, `0x005b6b34`, and default `0x005b6bef`; `int_convert.py` verified constants `0x28` / 40, `0xf2` / 242, and `0xf3` / 243.
- Recommended source-facing constant names:
  - `kBlockListenCommandMaxEntries = 0x28`
  - `kBlockListenListFullStringId = 0xf2`
  - `kBlockListenListEmptyStringId = 0xf3`
- Rejected alternative: embedding raw `dword_67A750`/`sub_4F0350` calls in C++ is rejected because support docs already resolve `g_pLanguageMan->GetLocalizedString(...)`.
- Capacity caveat: [UID:0000HS] records that this dispatcher opens the add prompt below `0x28`, while [UID:0001N0] accepts insertion below `0x14`. Preserve this as observed. It is a feature behavior detail, not a reason to leave this method blank.

### Prompt construction and dialog routing

- Best source shape:
  - `new AddToBlockListenInputPane();`
  - `new DeleteFromBlockListenInputPane();`
  - `new AlertPane(g_pLanguageMan->GetLocalizedString(...), g_activeMapPane, kDialogOkButtonText, NULL);`
- Evidence:
  - IDA shows `operator new` size `0x108` / 264, `LanguageMan::GetLocalizedString(0x28/0x29)`, `LineInputPane::LineInputPane`, and vtable stores for Add/Delete prompt objects.
  - [UID:0001MZ] and [UID:0001N1] document the retained raw out-of-line constructors and explain that the dispatcher contains inline construction mirrors generated at the allocation site. The source expression is still a normal `new AddToBlockListenInputPane()` or `new DeleteFromBlockListenInputPane()`.
  - IDA shows `operator new` size `0x270` / 624 for full/empty alerts, followed by `g_pLanguageMan`, `g_activeMapPane`, `kDialogOkButtonText`, and `AlertPane` construction.
- Rejected alternatives:
  - Do not call raw constructor addresses directly.
  - Do not represent vtable stores as handwritten source statements.
  - Do not model the alerts as packet sends or `ProtocolSend` ownership.

### Packet helper and adjacent table

- Best disposition:
  - `0x005b6c00-0x005b6c30` is switch/jump-table data for this dispatcher.
  - [UID:0002RY] `0x005b6c30-0x005b6c7c` is a separate raw no-route file-level packet helper, not part of this method.
- Evidence:
  - Current MCP `xrefs_to 0x005b6c00` reports a data xref from `0x005b6a7b` inside `sub_5B6A20`.
  - Current MCP `xrefs_to 0x005b6c30` reports zero xrefs.
  - B008 executed report and [UID:0002RY] show the table starts with internal targets `0x005b6a82`, `0x005b6b34`, and `0x005b6bef` and has no pointer/rel32 route to the packet helper.
- Rejected alternatives:
  - Do not merge [UID:0002RY] into this class method.
  - Do not create a source child for the switch-table bytes.

## Evidence Standards Used

- IDA MCP was required and used. Active session `875bf182` was available and `server_health` reported `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, module `NexusTK.exe`, imagebase `0x400000`.
- Function and range claims use current MCP `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, and `disasm`.
- Name/source-shape claims use current by-* support docs and accepted sibling C++ pages, then reject raw/decompiler labels where behavior-backed names exist.
- Numeric conversions used `tools/int_convert.py`; note that the first batch invocation with multiple positional values was invalid shell usage, then values were converted individually or with `--size 2` for values above signed 1-byte range.
- A preliminary MCP call helper incorrectly used PowerShell's automatic `$args` variable and produced "database is required"; this was a local request-shape error, not an MCP outage. The corrected helper produced the current evidence below.

## Evidence Checked

### IDA MCP checks

- `tools/list`: confirmed current schemas require `database` inside each tool input.
- `idb_list`: active session `875bf182`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26088`, active, not analyzing.
- `server_health database=875bf182`: `status: ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`:
  - `0x005b6a20`: `sub_5B6A20`, size `0x1df`.
  - `0x005b6bff`: not a function.
  - `0x005b6c00`: not a function.
  - `0x005b6c30`: not a function.
  - `0x004f2300`: `sub_4F2300`, size `0xf`.
  - `0x004f2310`: `sub_4F2310`, size `0xb`.
  - `0x004f0350`: `sub_4F0350`, size `0x22`.
  - `0x004f4aa0`: `sub_4F4AA0`, size `0x14`.
  - `0x004f1c00`: `sub_4F1C00`, size `0x409`.
  - `0x0049feb0`: `sub_49FEB0`, size `0x6c5`.
- `xrefs_to`:
  - `0x005b6a20`: one data xref from `0x00630694`.
  - `0x005b6c00`: one data xref from switch jump at `0x005b6a7b`.
  - `0x005b6c30`: zero xrefs.
  - `0x006306d8`, `0x00630728`, `0x00630758`: dispatcher AddToBlock vtable stores at `0x005b6b0a`, `0x005b6b10`, `0x005b6b1a`, plus raw constructor stores at `0x005b6c9f`, `0x005b6ca7`, `0x005b6cb1`.
  - `0x00630764`, `0x006307b4`, `0x006307e4`: dispatcher DeleteFromBlockListen vtable stores at `0x005b6bd5`, `0x005b6bdb`, `0x005b6be5`, plus raw constructor stores at `0x005b711f`, `0x005b7127`, `0x005b7131`.
- `callees 0x005b6a20`: `0x004f2310`, `0x004f2300`, `0x004f4aa0`, `0x004f0350`, `0x004f1c00`, and `0x0049feb0`.
- `decompile 0x005b6a20`: confirms `GetTextLength`/copy-one-character flow, `A/a` and `D/d` cases, `g_pConfig` vector count, add/delete prompt construction mirrors, full/empty alert construction, and refs to `g_pLanguageMan`, `g_activeMapPane`, and `kDialogOkButtonText`.
- `disasm 0x005b6a20`: confirms the switch table, branch addresses, constants, vtable store addresses, return sites, and compiler EH/security-cookie cleanup records.

### Documentation and report checks

- Current target and parent/support docs listed in Current Target State.
- Central executed reports checked:
  - B002 `0001MV-BlockListenInputPaneConstructor-source-quality.md`
  - B004 `0001MX-BlockListenInputPaneKeyHandler-source-quality.md`
  - B006 `0001MZ-AddToBlockListenInputPaneConstructor-source-quality.md`
  - B006 `0001N1-DeleteFromBlockListenInputPaneConstructor-source-quality.md`
  - B007 `0001MW-BlockListenInputPanes-source-quality.md`
  - B008 `0002RY-SendBlockListenModePacket-source-quality.md`
- Generated reports checked as read-only inputs: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-memory-coverage.md`.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0001MY] is a `BlockListenInputPane` method. | Confirmed | Vtable data ref `0x00630694 -> 0x005b6a20`, class/file docs, modeled function boundary. | Config, AlertPane, packet helper, and raw constructor ownership checked and rejected as direct owners. | None for current owner/emitter route. |
| `0x005b6c00-0x005b6c30` is switch-table data for this method. | Confirmed | Current MCP xref from `0x005b6a7b`, B008 table bytes, internal targets `0x005b6a82/0x005b6b34/0x005b6bef`. | Zero xrefs to `0x005b6c30`, no route to packet helper. | None. |
| `GetTextLength()` / `CopyText(...)` are correct source-facing inherited helpers. | Strong | [UID:00035S]/[UID:00035R], accepted sibling pages. | Raw `sub_4F2310`/`sub_4F2300` names rejected as IDA labels. | Exact final `GetTextLength` versus `TextLength` spelling is a style-level choice; this report uses the accepted Quit/Post-style spelling. |
| `g_pConfig->m_blockListenNames` is the field used for count checks. | Strong | Same offsets as [UID:0001MX], accepted key-handler C++, vector begin/end usage. | Raw `dword_67A7C8` and generic config field names rejected. | Final project-wide `Config` declaration remains broader work but does not block this target. |
| First-draft `void HandleCommandSelection()` is source-quality ready. | High | Vtable-only route, side-effect behavior, sibling submit-handler conventions, no caller consuming return value, exact branch behavior. | IDA `__int16` pseudotype considered and rejected as decompiler artifact. | Later class hierarchy pass can revise signature if a non-void virtual declaration is proven. |

## Positive Evidence Summary

- `0x005b6a20` is a single IDA-modeled function, size `0x1df` / 479 (Verified with int_convert.py in existing docs).
- The only direct route is the `BlockListenInputPane` vtable slot at `0x00630694`.
- The method reads exactly one inherited line-input character before dispatch.
- The switch handles only `A/a` and `D/d`; other one-character input does not open dialogs or send packets.
- Add and delete prompt construction mirrors are already explained by sibling constructor pages as normal `new AddToBlockListenInputPane()` / `new DeleteFromBlockListenInputPane()` source inlined by the compiler.
- Full/empty alert creation uses already accepted project-level names: `AlertPane`, `g_pLanguageMan`, `g_activeMapPane`, and `kDialogOkButtonText`.
- The adjacent switch table and raw packet helper have current negative route evidence and no longer block this method's first-draft C++.

## Negative Evidence Summary

- No code caller was found; this is expected for a virtual dispatch slot and does not block class ownership.
- `0x005b6bff`, `0x005b6c00`, and `0x005b6c30` are not modeled functions.
- `0x005b6c00` is referenced by the switch jump; it is not standalone source.
- `0x005b6c30` has zero current xrefs and remains a separate file-level raw helper, not a callee or fall-through target of this method.
- `ProtocolSend`, `PacketBuffer`, `Socket`, and `g_packetSender` are rejected as owners for [UID:0001MY]; this method does not serialize packets.
- `Config` and `AlertPane` are dependencies, not owners: the method reads list state and creates alerts, but it is reached through the `BlockListenInputPane` vtable and implements the user's command selection for that class.
- The raw out-of-line add/delete constructors are not direct callees here. The dispatcher emits inline construction mirrors, so source C++ should use normal `new` expressions instead of raw constructor-address calls.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b68c0-0x005b6900` | [UID:0001MV](../../../../../by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) | Top-level prompt constructor | TRUE | [UID:00000X] | `88/90` | Source-ready constructor C++ present. |
| `0x005b6900-0x005b6a1b` | [UID:0001MX](../../../../../by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md) | Ctrl+`?` show-list key handler | TRUE | [UID:00000X] | `90/91` | Source-ready key handler C++ present. |
| `0x005b6a1b-0x005b6a20` | none | `0xcc` padding | false/source padding | [UID:0001MW] inventory | n/a | No source child. |
| `0x005b6a20-0x005b6bff` | [UID:0001MY](../../../../../by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) | `A/a` and `D/d` command dispatcher | TRUE | [UID:00000X] | current `86/88`, recommended `90/91` | This report recommends formal first-draft C++. |
| `0x005b6c00-0x005b6c30` | none / ignored inventory | Switch/jump-table data for [UID:0001MY] | false/source table | [UID:0001MY] support bytes | n/a | No source child. |
| `0x005b6c30-0x005b6c7c` | [UID:0002RY](../../../../../by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) | Raw no-payload packet helper | TRUE but no route | [UID:0000HS] file-level helper | `87/89` | Separate blank-C++ no-route helper. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b6a20` | data xref from `0x00630694` | Primary vtable slot route to this method. |
| `0x005b6c00` | data xref from `0x005b6a7b` | Switch table used by this method. |
| `0x005b6c30` | zero xrefs | Adjacent raw packet helper is not reached by this method. |
| `0x004f2310` | callee | Inherited line-input text-length helper. |
| `0x004f2300` | callee | Inherited line-input text-copy helper. |
| `0x004f4aa0` | callee | Allocation helper / `operator new` front-end. |
| `0x004f0350` | callee | `g_pLanguageMan->GetLocalizedString(...)`. |
| `0x004f1c00` | callee | `LineInputPane::LineInputPane(...)` during inlined prompt construction. |
| `0x0049feb0` | callee | `AlertPane` construction. |

## Ranked Ownership Analysis

### 1. [UID:00000X] BlockListenInputPane

- Evidence for: vtable slot `0x00630694`, class page method map, behavior belongs to the top-level block-listen prompt, and exact range is a method-sized function after the key handler.
- Evidence against: no direct code caller, but that is normal for virtual handlers and not an ownership blocker.
- Decision: accepted direct owner and emitter.

### 2. [UID:0000HS] BlockListenInputPanes file

- Evidence for: source file owns the class family, source folder `NexusTK/social/`, and file-local raw helpers.
- Evidence against: the target is a class method with a precise class vtable route, so file-level ownership is too broad for the direct canonical owner.
- Decision: accepted as source-root parent through the class, not canonical owner for this method.

### 3. AddToBlockListenInputPane / DeleteFromBlockListenInputPane

- Evidence for: dispatcher constructs those panes in the `A/a` and `D/d` branches.
- Evidence against: these are allocated outputs of the top-level command selection; their constructors have separate exact pages and prompt ids.
- Decision: rejected as target owner.

### 4. AlertPane, Config, PacketBuffer, Socket, ProtocolSend, g_packetSender

- Evidence for: Alert and Config participate in the behavior; packet helpers exist in the same source island.
- Evidence against: no vtable route, no source method ownership, no packet serialization in this target, and zero route from this method to [UID:0002RY].
- Decision: dependencies only.

## Source Placement

- Recommended source placement: `NexusTK/social/BlockListenInputPanes.cpp`, through [UID:00000X] `BlockListenInputPane`.
- Why it fits: the file already owns the block-listen prompt family, packet helper family, and config-vector feature behavior. The method is part of the top-level block-listen prompt, not a generic command-input base.
- Rejected placement: `ui/dialogs/CommandInputPanes.cpp` remains a weaker historical/adjacency alternative. It explains generic input-pane mechanics but not the social/block-list feature-specific config vector, prompt family, and opcode cluster.
- Remaining placement uncertainty: none for current target; only final source tree file naming remains project-level reconstruction polish.

## Range / Split / Padding / Reclassification Analysis

- `0x005b6a20-0x005b6bff`: exact modeled function body for [UID:0001MY].
- `0x005b6bff-0x005b6c00`: no separate source; exclusive boundary before switch-table data.
- `0x005b6c00-0x005b6c30`: switch/jump-table bytes for this method, not standalone source.
- `0x005b6c30-0x005b6c7c`: [UID:0002RY] raw packet helper, separate file-level helper.
- No split, merge, rename, new child, or reclassification is recommended for this target. The only required change is source-quality documentation plus formal C++.

## IDA Rename / Type / Comment Recommendations

- No IDA DB edits are requested in this report-only assignment.
- Source-facing names recommended for documentation/C++:
  - `BlockListenInputPane::HandleCommandSelection()`
  - `GetTextLength()`
  - `CopyText(...)`
  - `g_pConfig->m_blockListenNames`
  - `kBlockListenCommandMaxEntries`
  - `kBlockListenListFullStringId`
  - `kBlockListenListEmptyStringId`
- Keep IDA names such as `sub_5B6A20`, `sub_4F2310`, `sub_4F2300`, `dword_67A7C8`, `dword_67A750`, and `dword_67A764` only in evidence/provenance prose, not in finalized C++.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has a nonblank emitter route, clears the code-entry score gate already, and the named blockers are now resolved enough for first-draft source.
- Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
namespace {
const int kBlockListenCommandMaxEntries = 0x28;
const int kBlockListenListFullStringId = 0xf2;
const int kBlockListenListEmptyStringId = 0xf3;
}

void BlockListenInputPane::HandleCommandSelection()
{
    if (GetTextLength() != 1)
        return;

    wchar_t command = 0;
    CopyText(&command, 1);

    const int blockListenCount =
        static_cast<int>(g_pConfig->m_blockListenNames.end -
                         g_pConfig->m_blockListenNames.begin);

    switch (command)
    {
    case L'A':
    case L'a':
        if (blockListenCount < kBlockListenCommandMaxEntries)
        {
            new AddToBlockListenInputPane();
        }
        else
        {
            new AlertPane(g_pLanguageMan->GetLocalizedString(kBlockListenListFullStringId),
                          g_activeMapPane,
                          kDialogOkButtonText,
                          NULL);
        }
        break;

    case L'D':
    case L'd':
        if (blockListenCount > 0)
        {
            new DeleteFromBlockListenInputPane();
        }
        else
        {
            new AlertPane(g_pLanguageMan->GetLocalizedString(kBlockListenListEmptyStringId),
                          g_activeMapPane,
                          kDialogOkButtonText,
                          NULL);
        }
        break;

    default:
        break;
    }
}
```

- Reason it preserves exact original behavior:
  - Reads no command unless inherited text length is exactly one.
  - Copies exactly one wide command character.
  - Handles only `A/a` and `D/d`.
  - Uses the observed count threshold `0x28` for opening the add prompt and nonzero count for opening the delete prompt.
  - Uses localized ids `0xf2` and `0xf3` for the full/empty alert paths.
  - Uses normal `new` expressions for prompt/alert allocation, matching the compiler's observed allocation plus constructor/vtable effects.
- Reason it matches plausible original source shape:
  - It follows accepted command-input pages that call `GetTextLength()` and `CopyText(...)`.
  - It uses feature-level constants instead of raw IDA labels.
  - It keeps alert construction and prompt construction in normal late-1990s/mid-2000s C++ style.
  - It does not expose vtable stores, SEH state variables, or decompiler temporaries.
- Reason code should not remain blank: every blocker named in the target's current C++ note now has a documented source-quality route or a precise separate-target disposition.
- Third-party import directive: not applicable.

## Final Recommendation

- Update [UID:0001MY] to first-draft C++ ready and populate the formal C++ block above.
- Raise [UID:0001MY] from `86/88` to `90/91`.
- Keep owner/emitter/reconstructable metadata unchanged.
- Update support docs so [UID:0001MY] is no longer described as blank pending helper/config/alert names.
- Preserve negative evidence for [UID:0002RY] and switch-table separation.
- Leave broader class/file metadata unchanged unless supervisor chooses a separate parent rescore pass.

## Recommended Target Doc Changes

- Target path: `by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md`
- Metadata:
  - `COMPLETION:86 -> 90`
  - `CONFIDENCE:88 -> 91`
  - keep `CANONICAL_OWNER:00000X`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00000X`
  - insert formal C++ block from this report.
- Item Summary: update to mention source-ready `BlockListenInputPane::HandleCommandSelection()` with one-character inherited input read, `A/a` add-prompt/full-alert and `D/d` delete-prompt/empty-alert routing, preserved switch-table boundary, and first-draft C++ present.
- Body facts to incorporate:
  - current MCP session `875bf182`, health ok, IDB path, current function/xref/callee/decompile/disasm facts;
  - helper-name closure for `GetTextLength()` and `CopyText(...)`;
  - `g_pConfig->m_blockListenNames` count checks and `0x28` add-open threshold;
  - localized alert ids `0xf2` and `0xf3`;
  - prompt allocation/constructor mirror reasoning for add/delete prompts;
  - switch table at `0x005b6c00-0x005b6c30` is support data, not a source child;
  - [UID:0002RY] remains separate no-route file helper.
- Historical/stale assumptions to preserve or correct:
  - Replace "Final C++ stays blank pending final source-quality names for input helpers, config vector fields, and alert/dialog classes" with "Earlier blank-C++ blockers were resolved by current support docs; remaining exact original spelling uncertainty is a final-audit cap, not a C++ blocker."

## Recommended Support Doc Changes

- `by-class/BlockListenInputPane.md`
  - Update the method map row for [UID:0001MY] to say `HandleCommandSelection()` is source-ready with first-draft C++ in the child page.
  - Update parent-chain/score rationale to remove the statement that [UID:0001MY] is still blank/separate pending command-dispatcher C++.
  - Preserve direct class ownership, [UID:0000HS] source placement, and [UID:0002RY] file-helper caveat.
  - No class score change is required in this callback unless supervisor chooses a parent-score pass; remaining class-level blockers are final class declaration layout and add/delete submit/confirm source-quality outside this target.
- `by-file/BlockListenInputPanes.md`
  - Update proposed contents for [UID:00000X]/[UID:0001MY] to say the command dispatcher has source-ready first-draft C++.
  - Preserve `NexusTK/social/BlockListenInputPanes.cpp` as stronger than `CommandInputPanes.cpp`.
  - Preserve `0x28` add-open threshold versus `0x14` add-submit insert threshold as observed.
  - Preserve packet helper separation and support dependency roles.
  - No file score change is required by this target alone.
- `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`
  - Update the child table/status row for [UID:0001MY] from blank pending method naming to `90/91`, source-ready first-draft C++ in exact child.
  - Preserve `0x005b6c00-0x005b6c30` as switch/jump-table bytes for [UID:0001MY].
  - Update any score rationale text saying [UID:0001MY] still needs a method-specific pass.
  - No aggregate score change is required by this target alone because [UID:0001N0], [UID:0001N2], and raw packet helpers remain separate concerns.

## Score And Metadata Recommendation

- Current score/metadata:
  - `COMPLETION:86`
  - `CONFIDENCE:88`
  - `CANONICAL_OWNER:00000X`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00000X`
  - blank formal C++.
- Recommended score/metadata:
  - `COMPLETION:90`
  - `CONFIDENCE:91`
  - keep `CANONICAL_OWNER:00000X`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00000X`
  - populate formal C++ block.
- Reason higher:
  - current MCP revalidated exact body, vtable route, switch table, callees, and negative packet-helper route;
  - named blockers for input helper names, config vector field, alert/dialog names, and first-draft C++ have source-quality resolutions;
  - C++ can now be written inside the exact target range without aggregate overreach.
- Reason not higher:
  - original debug/source symbols are not recovered;
  - exact final class hierarchy declaration and whether the virtual slot was source-declared `void` or a non-void internal return remains inferred from source shape;
  - localized id constant names `kBlockListenListFullStringId` and `kBlockListenListEmptyStringId` are inferred, not original-proof;
  - broader add/delete submit handlers and file-local raw packet helpers remain separate source-quality targets.
- Reason not lower:
  - ownership/emitter route is direct and already gate-clearing;
  - first-draft C++ uses accepted helper names and source placement;
  - all old target blockers were investigated and either resolved or separated from this method.

## Open Questions With Attempted Resolution

- Input helper names:
  - Resolution: use inherited `GetTextLength()` and `CopyText(...)`.
  - Evidence: [UID:00035S], [UID:00035R], and accepted sibling source.
  - Score/C++ impact: no longer a blocker.
- Config vector field:
  - Resolution: use `g_pConfig->m_blockListenNames`.
  - Evidence: [UID:0001MX] and same offsets in current MCP decompile/disasm.
  - Score/C++ impact: no longer a blocker.
- Alert/string ids:
  - Resolution: use source-facing constants for ids `0xf2` and `0xf3`, with localized lookups through `g_pLanguageMan`.
  - Evidence: current MCP branches and existing AlertPane/source conventions.
  - Score/C++ impact: small final-audit cap only.
- `0x28` versus `0x14` capacity difference:
  - Resolution: preserve observed `0x28` add-prompt-open threshold in this method; do not rewrite it to match add-submit insertion threshold.
  - Evidence: current MCP compare at `0x005b6a97`; [UID:0000HS] already records the mismatch.
  - Score/C++ impact: behavior documented, not a blocker.
- Adjacent packet helper:
  - Resolution: keep [UID:0002RY] separate, file-level, and blank C++/no-route; it is not part of this method.
  - Evidence: zero xrefs to `0x005b6c30`, switch-table xref to `0x005b6c00`, B008 raw table evidence.
  - Score/C++ impact: no longer a blocker for [UID:0001MY].
- Return type:
  - Resolution: first-draft source should use `void`, matching side-effect submit/confirm handler style and lack of return-consuming caller.
  - Evidence: accepted sibling pages and vtable-only route.
  - Remaining uncertainty: final class declaration pass may adjust signature if source hierarchy evidence appears. This is a confidence cap, not a current C++ blocker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable for this report-only pass.
- Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, or any manual `-coverage-report.md` file.
- After implementation and scoped validation, supervisor should let validator refresh generated reports and should update manual coverage only if current supervisor policy still requires it.

## Follow-Up Actions

- Supervisor:
  - validate this report and checklist;
  - if accepted, send B006 an implementation callback for the listed target/support docs;
  - after implementation verification, execute the report through validator lifecycle, not by manual move.
- B006 after callback:
  - lease only the exact by-* docs to edit immediately;
  - apply target/support doc changes at report-level detail;
  - run scoped validators listed below;
  - update this checklist with checked proof items.
- Future B-agent work outside this target:
  - [UID:0001N0] and [UID:0001N2] still need submit/confirm source-quality passes;
  - [UID:0002RY], [UID:0002S0], and [UID:0002RZ] remain separate raw packet-helper/no-route questions and should not be folded into this method without new evidence.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `90/91`; not final-audit because symbol names and source declaration details remain inferred.
- Remaining uncertainty: original exact resource constant names and virtual slot return declaration. Both are documented and do not block first-draft C++.

## Validator Results

- Commands run: none. This was report-only research, and no by-* docs were edited.
- Expected scoped validators after implementation from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class/BlockListenInputPane.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file/BlockListenInputPanes.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md --apply --queue-timeout 240`
- If generated output freshness matters after the target C++ is inserted, use `--wait-generated` on the target validator or run the supervisor-approved generated refresh path.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B006/research/0001MY-BlockListenInputPaneCommandDispatcher-source-quality.md`
- Implementation callback modified:
  - `by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md`
  - `by-class/BlockListenInputPane.md`
  - `by-file/BlockListenInputPanes.md`
  - `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`
  - this report checklist.
- Validator/registry support: `by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md`, `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md`, and `by-type/by-vtable/BlockListenInputPaneFamilyVtables.md` were validated to register existing UIDs after initial missing-ref diagnostics; no content diff remained in those three files.
- Validator-owned side effects: `tools/validator.ini`, `project-level/-auto-completion-stats.md`, generated coverage/C++ outputs, and `tools/validator_autogen_backup/20260627-230818` were updated by validator commands only, not manually.
- Renamed: none.
- Report execution: not run. Supervisor owns `tools/validator.py execute_report ... --apply` after report validation and implementation verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: current `goal.md` assignment is `B006-implement-0001MY-block-listen-input-pane-command-dispatcher-20260627`, mode `accepted implementation callback`.
- [x] Update target doc `by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md`. Proof: target body now contains B006 source-quality implementation section, updated score rationale, and change-log entry.
- [x] Target metadata change to apply: `COMPLETION:86 -> 90`, `CONFIDENCE:88 -> 91`; keep `CANONICAL_OWNER:00000X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000X`. Proof: target header now has `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00000X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000X`.
- [x] Insert the exact formal C++ block from `First-Draft C++ Recommendation` into the target's `RECONSTRUCTION_CPP CODE` header/block. Proof: target formal block now contains the `namespace` constants and `void BlockListenInputPane::HandleCommandSelection()` body from this report.
- [x] Update target item summary to source-ready `HandleCommandSelection()` with one-character inherited input read, `A/a` add/full-alert routing, `D/d` delete/empty-alert routing, switch-table boundary, and first-draft C++ present. Proof: target `Item Summary` line now states that exact source-ready dispatcher summary and first-draft C++ status.
- [x] Incorporate current MCP facts from session `875bf182`: health ok, `lookup_funcs`, `xrefs_to`, `callees`, decompile, and disasm evidence for `0x005b6a20`. Proof: target, class, and file support pages record accepted report session `875bf182`; callback probe session `b001_000241_20260627` additionally reconfirmed `sub_5B6A20` size `0x1df`, vtable xref `0x00630694`, switch-table xref `0x005b6a7b -> 0x005b6c00`, zero xrefs to `0x005b6c30`, and callees.
- [x] Replace stale blank-C++ blocker text with the resolved helper/config/alert/source-quality rationale from this report. Proof: target reconstruction notes now state the earlier blank-C++ blocker is resolved through `GetTextLength()`, `CopyText(...)`, `g_pConfig->m_blockListenNames`, localized alert dependencies, and prompt constructor source shape.
- [x] Preserve negative evidence that `0x005b6c00-0x005b6c30` is switch-table data and [UID:0002RY] remains a separate no-route file helper. Proof: target, class, file, and aggregate docs all preserve the switch-table boundary and [UID:0002RY] separation/no-route evidence.
- [x] Update support doc `by-class/BlockListenInputPane.md`: method map and parent-chain/score prose should mark [UID:0001MY] source-ready with first-draft C++ in child, while preserving class/file route and [UID:0002RY] caveat. Proof: class method map, evidence notes, parent-chain repair, score rationale, and change entry now mark [UID:0001MY] `90/91` with formal C++ present and keep [UID:0002RY] separate.
- [x] Update support doc `by-file/BlockListenInputPanes.md`: proposed contents/evidence should mark [UID:0001MY] source-ready, preserve `NexusTK/social/BlockListenInputPanes.cpp`, preserve `0x28` versus `0x14` capacity caveat, and preserve packet helper separation. Proof: file proposed contents, evidence notes, ownership notes, and change entry now carry those details.
- [x] Update support doc `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`: child table/status should mark [UID:0001MY] `90/91` with formal C++ present and remove "method-specific pass still needed" for this child only. Proof: aggregate covered-range row, child-disposition row, source-facing names, score rationale, and change entry now mark [UID:0001MY] `90/91` with formal C++ present; only unrelated [UID:0001N0]/[UID:0001N2] remain pending.
- [x] Confirm no split/rename/new-child changes are applied. Proof: no file rename/new child was performed; `0x005b6c00-0x005b6c30` remains support data and [UID:0002RY] remains separate.
- [x] Confirm no IDA DB edits are applied. Proof: MCP was used only for read-only `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, and `callees` probes; no IDA write tools were called.
- [x] Confirm third-party import directive is not applicable. Proof: this is NexusTK UI/social C++ method reconstruction, not a vetted static third-party embed; no import directive was added.
- [x] Do not edit generated reports, project-level generated files, or any manual `-coverage-report.md` file. Proof: no manual edits were made to generated/project-level/coverage files; validator-owned generated/project-level side effects came only from scoped validator commands.
- [x] Run scoped validators listed in `Validator Results` after implementation. Proof: required edited-file validators ran with exit code 0 and `ok: 1`; final affected-file reruns after UID registration were commands `000000004729`, `000000004731`, `000000004732`, and `000000004723`, plus target `--wait-generated` command `000000004733`.
- [x] Report validator command, command_id, command_timestamp, exit code, ok count, and generated-refresh state after implementation. Proof: validator result table below records commands and outcomes.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` says accepted implementation callback; no new report was written.
- [x] Leases acquired only immediately before by-* edits and released immediately after edit/validator batch. Proof: B006 leased the four edited docs before patching; after validators, release reported `No active lease` for those original four because they had already expired, and B006 released the three reference-target validator leases successfully. Current lease report shows no B006 leases.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target/support docs include function/range facts, helper names, config field, thresholds, alert ids, prompt construction, switch-table and packet-helper separation, source placement, rejected alternatives, and score rationale.
- [x] Metadata/score/C++ changes applied or explicitly not applied with reason. Proof: target is `90/91` with formal C++; owner/emitter/reconstructable unchanged; class/file/aggregate scores unchanged by assignment because broader parent concerns remain outside this callback.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target and supports preserve the resolved old blank-C++ blocker as a historical correction, rejected raw labels/source placements/ownership candidates, zero-xref packet-helper evidence, and switch-table classification.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: helper/config/alert/source-shape blockers are resolved; exact original resource constant spellings and virtual return declaration remain documented confidence caps, not current C++ blockers.
- [x] Validators run and results recorded. Proof: table below.
- [x] Generated report refresh completed by validator or supervisor-owned coverage/tracker text confirmed not applicable. Proof: target validator with `--wait-generated`, command `000000004733`, completed `generated_refresh: completed` at `2026-06-27T23:08:07-04:00`.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted items remain unapplied; blockers are only unrelated future work for [UID:0001N0], [UID:0001N2], and retained raw helpers.

Validator proof table:

| Command | command_id | command_timestamp | Exit | ok | generated_refresh | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory\0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md --apply --queue-timeout 240` | `000000004720` | `2026-06-27T23:06:26-04:00` | 0 | 1 | deferred | Initial target scan applied metadata/C++ registry updates; reported missing refs for existing helper UIDs, resolved below. |
| `python .\tools\validator.py --mode file --file by-class\BlockListenInputPane.md --apply --queue-timeout 240` | `000000004721` | `2026-06-27T23:06:28-04:00` | 0 | 1 | deferred | Initial class scan; same helper UID registry diagnostics, resolved below. |
| `python .\tools\validator.py --mode file --file by-file\BlockListenInputPanes.md --apply --queue-timeout 240` | `000000004722` | `2026-06-27T23:06:30-04:00` | 0 | 1 | deferred | Initial file scan; preexisting [UID:0003HN] registry diagnostic, resolved below. |
| `python .\tools\validator.py --mode file --file by-memory\0x005b68c0-0x005b7354.BlockListenInputPanes.md --apply --queue-timeout 240` | `000000004723` | `2026-06-27T23:06:40-04:00` | 0 | 1 | deferred | Aggregate support scan clean for edited file. |
| `python .\tools\validator.py --mode file --file by-memory\0x004f2310-0x004f231b.LineInputPaneTextLength.md --apply --queue-timeout 240` | `000000004726` | `2026-06-27T23:07:28-04:00` | 0 | 1 | deferred | Registered existing [UID:00035S] path. |
| `python .\tools\validator.py --mode file --file by-memory\0x004f2300-0x004f230f.LineInputPaneCopyText.md --apply --queue-timeout 240` | `000000004727` | `2026-06-27T23:07:30-04:00` | 0 | 1 | deferred | Registered existing [UID:00035R] path. |
| `python .\tools\validator.py --mode file --file by-type\by-vtable\BlockListenInputPaneFamilyVtables.md --apply --queue-timeout 240` | `000000004728` | `2026-06-27T23:07:31-04:00` | 0 | 1 | deferred | Registered existing [UID:0003HN] path. |
| `python .\tools\validator.py --mode file --file by-memory\0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md --apply --queue-timeout 240` | `000000004729` | `2026-06-27T23:07:42-04:00` | 0 | 1 | deferred | Target rerun after UID registration; no missing-ref diagnostics. |
| `python .\tools\validator.py --mode file --file by-class\BlockListenInputPane.md --apply --queue-timeout 240` | `000000004731` | `2026-06-27T23:07:44-04:00` | 0 | 1 | deferred | Class rerun after UID registration; no missing-ref diagnostics. |
| `python .\tools\validator.py --mode file --file by-file\BlockListenInputPanes.md --apply --queue-timeout 240` | `000000004732` | `2026-06-27T23:07:46-04:00` | 0 | 1 | deferred | File rerun after UID registration; no missing-ref diagnostics. |
| `python .\tools\validator.py --mode file --file by-memory\0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md --apply --queue-timeout 240 --wait-generated` | `000000004733` | `2026-06-27T23:08:07-04:00` | 0 | 1 | completed | Generated refresh completed; validator reported `generated_metadata_refresh: 283`, `autogen_backup_create: 3` under `tools/validator_autogen_backup/20260627-230818`, and many unrelated stale/missing-file registry diagnostics during generated refresh. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001MY-BlockListenInputPaneCommandDispatcher-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001MY-BlockListenInputPaneCommandDispatcher-source-quality.md","timestamp":"2026-06-27T23:11:15","uid":"0001MY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
