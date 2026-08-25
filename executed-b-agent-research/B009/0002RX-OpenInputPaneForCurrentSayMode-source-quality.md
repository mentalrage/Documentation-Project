** TARGET-REPORT-UID:0002RX **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002RX] OpenInputPaneForCurrentSayMode source-quality report

Agent: B009
Mode: report-only research
Target: `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md`
Skill: project-level `ntk-b-agent-workflow`
MCP evidence session: `80de0a67`

## Report Status

`FINISHED_REPORT`

This report is implementation-ready for supervisor validation. No by-* files, generated files, coverage reports, validator/tool state, or IDA DB state were edited during this report-only pass. No leases were taken because no implementation edit was performed.

## Current Target Metadata

- UID: `0002RX`
- Current path: `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md`
- Current completion/confidence: `85/88`
- Current owner/emitter route: `CANONICAL_OWNER:0000N9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N9`
- Current formal C++: blank
- Current documented blocker theme: final mode/global/member/helper names and support placement details needed before formal C++.

## Recommended Target Metadata

- `COMPLETION:90`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0000N9`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000N9`
- Keep blank emitter position.
- Add formal C++ to this target's `RECONSTRUCTION_CPP CODE` block using the exact insertion text in this report.

The score should rise because the previously listed blockers were investigated rather than carried forward as deferrals. The mode field, EPF/current-vs-legacy gate, chat-handle pending-target gate, recent-recipient list route, raw jump-table caller, sibling helper relationships, group/clan inline construction pattern, and source-facing name choices are now supported by live MCP evidence plus existing by-* documentation. Confidence should remain below 95 because exact original symbol spellings for the current-mode field, chat-handle pending flag, recent-recipient list method names, and free-function/member helper spelling are still inferred from context rather than recovered from original symbols.

## Documents Reviewed

- `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md` [UID:0002RX]
- `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` [UID:0001KO]
- `by-file/SayInputPanes.md` [UID:0000N9]
- `by-class/SayInputPane.md` [UID:0000C3]
- `by-class/ShoutInputPane.md` [UID:0000D5]
- `by-class/NewSayToUserMessageInputPane.md` [UID:000099]
- `by-class/SayToGroupMessageInputPane.md` [UID:0000C4]
- `by-class/SayToPlanMessageInputPane.md` [UID:0000C5]
- `by-global/g_useEpfAssets.md` [UID:0000SW]
- `by-global/g_pChattingHandlePane.md` [UID:0002XE]
- `by-global/g_pChattingVarietyPane.md` [UID:0002X5]
- `by-global/g_pCollectionData.md` [UID:0000QK]

Generated files were treated only as stale routing leads. `auto-generated/NexusTK/social/SayInputPanes.cpp` still shows [UID:0002RX] as an empty emitter marker with old projected scores, so it must not override the current by-* evidence.

## MCP Availability and Evidence Scope

IDA MCP was available and responsive for this report.

- `idb_list` showed active session `80de0a67` for `NexusTK.exe.i64`.
- `server_health` for session `80de0a67` returned status `ok`, module `NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and populated string cache.
- The report uses MCP-backed `lookup_funcs`, `analyze_function`, `xref_query`, `insn_query`, `func_profile`, `find_bytes`, `get_bytes`, and string/xref checks.

## Target Function Identity

MCP `lookup_funcs` identifies `0x005a5110` as `sub_5A5110`, size `0x227`, with no function at the exclusive end address `0x005a5337`. Bytes around the target show padding before the prologue and `0xcc` padding after the return at `0x005a5336`; the next function starts at `0x005a5340`. This supports the current by-memory range as exact.

`analyze_function 0x005a5110` reports a `__thiscall`-shaped function whose `this` parameter is the `UserPane` object reached through `g_pUserPane` in caller paths. The current source-facing title `OpenInputPaneForCurrentSayMode` remains the best target-level name: the function examines the current say/chat input mode and opens the corresponding input pane.

## Caller and Reachability Evidence

MCP `analyze_function` and `xref_query` found live code refs to `0x005a5110` from:

- `0x0048126b` inside `sub_4811C0`.
- `0x00481ef6` inside `sub_481D60`.
- `0x004cf704` inside `sub_4CF3E0`.
- `0x004cf937`, a raw no-function jump-table case stub.
- `0x005a6351` inside `sub_5A5BD0`.

The raw `0x004cf937` route is not an unresolved standalone caller. MCP `insn_query 0x004cf8e0-0x004cf960` shows a no-function switch helper that loads `ecx = dword_67A748` (`g_pUserPane`) and dispatches cases through `jpt_4CF8FF`; case 5 calls `sub_5A5110` at `0x004cf937` and returns. MCP also showed refs to this raw stub/jump table from `0x004cf8ff` and `0x004cf954`. This should be documented as a raw switch-case route, not as an unknown owner or separate implementation target.

MCP `find_bytes` found no little-endian VA/RVA/raw-offset pointer patterns for the target start or exclusive end. That negative evidence is expected for normal rel32 call sites and does not undermine the code refs above.

## Caller Context

### `sub_4811C0` Chat Variety Selection Handler

MCP `analyze_function 0x004811c0` shows a chat variety selection handler. It calls a virtual slot on `g_pChattingVarietyPane`, compares the result, and writes the selected mode to `g_pUserPane + 0x3eb4`. For mode zero/default it writes zero and calls `sub_5A5110(g_pUserPane)` at `0x0048126b`.

The same function routes specific non-default selections directly:

- Case 1 sets mode `1` and calls `sub_5A5710`, the shout-input creator.
- Case 2 sets mode `2` and calls a misnamed IDA helper that is actually part of the recent-recipient/direct-message path.
- Case 3 sets mode `3` and calls `sub_5A5570`, the standalone group-input creator.
- Case 4 sets mode `4` and calls `sub_5A5640`, the standalone clan-input creator.

This supports the target as the central "open input pane for current mode" helper and supports the mode constants used in the recommended C++.

### `sub_481D60` Chat Handle Event Path

MCP `analyze_function 0x00481d60` shows a chat-handle event path that calls `sub_5A5110(g_pUserPane)` at `0x00481ef6` in a branch that checks user/chat state. This is a normal UI event caller, not a separate owner.

### `sub_4CF3E0` Icon/Action Dispatch Path

MCP `analyze_function 0x004cf3e0` shows a dispatch path that calls `sub_5A5110(g_pUserPane)` at `0x004cf704` when the selected UI action corresponds to this say-mode opener. MCP `insn_query` also shows the related raw no-function jump-table case at `0x004cf937`. These two routes are consistent with an action/menu dispatch wrapper around the same helper.

### `sub_5A5BD0` UserPane Key/Event Path

MCP `func_profile 0x005a5bd0` shows a large UserPane input/event function that calls the target at `0x005a6351` alongside sibling say/shout/direct-message helper calls. This confirms the target is part of the same `SayInputPanes.cpp` social-input cluster documented by [UID:0000N9].

## Behavior Reconstruction

The target implements the central say-mode dispatcher:

1. If `g_useEpfAssets` (`byte_66DA97`) is not `1`, open the default say pane through `sub_5A53C0`.
2. If `g_pChattingHandlePane + 0x111` is true, open the default say pane through `sub_5A53C0`.
3. Read `UserPane + 0x3eb4`, the current say/chat input mode selected by ChattingVarietyPane.
4. If the mode is zero/default, open the default say pane through `sub_5A53C0`.
5. If the mode is `1`, call `sub_5A5710`, the shout input pane creator.
6. If the mode is `2`, load the recent-recipient list at `UserPane + 0x13eb08`.
   - If the list count is greater than zero, read the last entry through the list virtual accessor and copy it into a local 64-wide-character stack buffer.
   - If the list is empty, use an empty recipient string.
   - Call `sub_5A4B60(userPane, recipientName)`, which updates/deduplicates the recent-recipient list and sets the selector byte at `UserPane + 0x13eb10`.
   - Allocate a 520-byte `NewSayToUserMessageInputPane` and call `sub_5B1990` with the recipient name.
7. If the mode is `3`, allocate a 520-byte `SayToGroupMessageInputPane`, construct it inline, store the group vtables, copy `L"!!"` into the name buffer at `+0x108`, format/use `L"Group => "`, and open/update the pane prompt through `sub_4F20A0`.
8. If the mode is `4`, allocate a 520-byte currently-page-named `SayToPlanMessageInputPane` but source-facing `SayToClanMessageInputPane`, construct it inline, store the clan/plan vtables, copy `L"!"` into the name buffer at `+0x108`, format/use `L"Clan => "`, and open/update the pane prompt through `sub_4F20A0`.
9. Other nonzero values fall through without opening a pane.

## Callee and Field Evidence

### `g_useEpfAssets`

The first branch compares `byte_66DA97` with `1`. [UID:0000SW] already documents this byte as source-facing `g_useEpfAssets`, a global EPF/current-vs-legacy selector whose only setter is StartupWindow and whose readers choose modern/current vs legacy paths. Here it gates the modern chat variety/say-mode dispatcher. If the byte is not enabled, the function opens normal say input.

### `g_pChattingHandlePane + 0x111`

The target reads `unk_67ADE0 + 0x111`. [UID:0002XE] documents `unk_67ADE0` as source-facing `g_pChattingHandlePane`, type `ChattingHandlePane *`. Existing docs identify this offset as a pending chat-target state. The best source-facing reconstruction is a boolean chat-target pending flag, currently named `m_chatTargetPending` in the draft C++ below. The exact original field spelling remains a final-audit cap, but the field role is no longer an unresolved behavior blocker.

### `UserPane + 0x3eb4`

The target reads `this[4013]`, which is `UserPane + 0x3eb4`. [UID:0000QK] and [UID:0000N9] already document this offset as the current chat variety/mode consumed by ChattingVarietyPane. MCP caller analysis shows `sub_4811C0` writes values 0 through 4 to this field before dispatching specific pane creation routes. The best source-facing field name is `m_currentSayMode`.

### `UserPane + 0x13eb08`

The direct-message branch reads `this[326338]`, which is `UserPane + 0x13eb08`, as the recent-recipient list pointer/object. [UID:0001KO] already documents this neighborhood and `sub_5A4B60`. MCP `analyze_function 0x005a4b60` confirms this helper deduplicates/removes old list entries, inserts the current recipient, keeps the bounded list length, and sets `UserPane + 0x13eb10` to `1`. The best source-facing field name is `m_recentSayRecipients`.

### `sub_5A53C0`

MCP `analyze_function 0x005a53c0` confirms this is the default say input opener. It writes `UserPane + 0x3eb4 = 0`, allocates a 268-byte `SayInputPane`, initializes the base `LineInputPane` prompt with `L"> "`, installs `SayInputPane` vtables, and initializes the chat history cursor at `+0x108` to `-1`.

### `sub_5A5710`

MCP `analyze_function 0x005a5710` confirms this is the shout input opener. It writes `UserPane + 0x3eb4 = 1`, allocates a 264-byte `ShoutInputPane`, initializes the base prompt with `L"! "`, and installs `ShoutInputPane` vtables.

### `sub_5B1990`

MCP `analyze_function 0x005b1990` confirms this is the `NewSayToUserMessageInputPane` constructor. It initializes a `LineInputPane`, installs the `NewSayToUserMessageInputPane` vtables, copies the recipient name into the `+0x108` buffer with `_wcscpy_s(..., 0x80, ...)`, formats the prompt as `L"To %s : "`, and calls the shared prompt/open helper.

### Group and Clan Inline Construction

MCP string/xref checks show:

- `L"!!"` at `0x006309d0` is referenced by the target and `sub_5A5570`.
- `L"!"` at `0x006309d8` is referenced by the target and `sub_5A5640`.
- `L"Group => "` at `0x00630a44` is referenced by the target, `sub_5A5570`, and the group constructor `0x005b1ec0`.
- `L"Clan => "` at `0x00630a58` is referenced by the target, `sub_5A5640`, and the clan constructor `0x005b22d0`.

MCP `analyze_function 0x005a5570` and `0x005a5640` show standalone group/clan creators with the same construction pattern as the target's mode 3 and 4 branches. MCP `analyze_function 0x005b1ec0` and `0x005b22d0` show constructor bodies for group and clan panes, but those constructors have no direct xrefs. The most source-realistic reconstruction is that the target source used `new SayToGroupMessageInputPane(L"!!")` and `new SayToClanMessageInputPane(L"!")`, with the compiler emitting/inlining constructor setup in this target range. The absence of direct constructor xrefs is therefore not a blocker; it is an inlining/source-shape clue.

## Source Placement Decision

Keep the target owned by [UID:0000N9] `by-file/SayInputPanes.md`.

Positive evidence:

- All target branches allocate or open `SayInputPane`, `ShoutInputPane`, `NewSayToUserMessageInputPane`, `SayToGroupMessageInputPane`, or `SayToClanMessageInputPane` objects.
- Existing exact sibling child pages in [UID:0000N9] already document the same constructors and submit handlers.
- Callers route from ChattingVarietyPane and UserPane event paths into this social input cluster.
- The target uses the same literals, vtables, and prompt/open helper pattern as the documented `SayInputPanes.cpp` cluster.

Rejected placements:

- `UserPane` ownership is rejected for emission because the target is a social input pane construction dispatcher even though the `this` object is `UserPane`.
- `ChattingVarietyPane` ownership is rejected because ChattingVarietyPane selects the mode but does not own the pane constructors or prompt behavior.
- [UID:0001KO] `SayModeHelpers` ownership is rejected because that page is a mixed non-emitting index/support neighborhood; [UID:0002RX] is the exact reconstructable child with a valid file emitter.

## Ownership, Emitter, and Split Decision

Keep:

- `CANONICAL_OWNER:0000N9`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N9`

No split is required. The target range is an exact complete function from `0x005a5110` through `0x005a5336`, followed by padding. The raw `0x004cf937` caller is outside this range and should be documented as a switch-case route, not split into this target. The group/clan branches are in-range inline construction bodies and are naturally represented in the target's formal C++ as source-level constructor calls.

## Name and Heuristic Decisions

The following names are recommended as current best source-facing names:

- `OpenInputPaneForCurrentSayMode`: target function. It describes the exact behavior and matches the current path/title.
- `SayInputMode`: enum/constant group for modes 0 through 4.
- `kSayInputModeDefault`, `kSayInputModeShout`, `kSayInputModeWhisper`, `kSayInputModeGroup`, `kSayInputModeClan`: mode constants based on MCP caller writes and target branch behavior.
- `UserPane::m_currentSayMode`: `UserPane + 0x3eb4`, selected by ChattingVarietyPane and consumed here.
- `UserPane::m_recentSayRecipients`: `UserPane + 0x13eb08`, recent-recipient list used by the direct-message branch.
- `ChattingHandlePane::m_chatTargetPending`: `g_pChattingHandlePane + 0x111`, pending chat-target flag that forces default say input.
- `UpdateRecentRecipientList`: source-facing name for `sub_5A4B60`; it deduplicates and inserts the recipient, then sets the selector byte.
- `OpenDefaultSayPane`: source-facing name for `sub_5A53C0`.
- `OpenShoutInputPane`: source-facing name for `sub_5A5710`.
- `SayToClanMessageInputPane`: source-facing class name for current [UID:0000C5] stable path `SayToPlanMessageInputPane`.

These are not arbitrary aliases. They are inferred from branch behavior, caller writes, existing by-file/by-class names, literal prompts, constructor bodies, and sibling support docs. They should replace raw `dword`, `byte`, `sub_`, and `unk_` spellings in final source-facing documentation for this target.

## Rejected Alternatives and Negative Evidence

- Leaving formal C++ blank is rejected. The target now has exact range, owner/emitter, branch behavior, caller map, helper identities, and source-facing names sufficient for first-draft C++.
- Treating mode 4 as "plan" in final source code is rejected. The stable documentation path may retain `SayToPlanMessageInputPane` for UID/path continuity, but [UID:0000N9] and [UID:0000C5] already document `SayToClanMessageInputPane` as the best source-facing class name. The target literal `L"Clan => "` and packet/input context support clan, not plan.
- Treating `0x004cf937` as an independent unresolved function is rejected. MCP disassembly shows it is a raw switch/jump-table case that loads `ecx = g_pUserPane` and calls the target.
- Treating the group/clan no-direct-constructor-xref state as a blocker is rejected. The target contains inline construction code that is source-equivalent to constructor calls; sibling standalone helpers and constructor bodies corroborate the same vtables/literals.
- Treating `g_useEpfAssets` as unknown is rejected. [UID:0000SW] documents the global and the target's compare-to-1 behavior matches the current-vs-legacy gate pattern.
- Treating `UserPane + 0x3eb4` as an unknown integer is rejected. MCP caller analysis shows it is written with selection values and consumed as the current say mode.
- Treating `UserPane + 0x13eb08` as an unknown pointer is rejected. MCP `sub_5A4B60` and the mode 2 branch show it is a recent-recipient list.

## Formal C++ Recommendation

If accepted, insert the following exact text into [UID:0002RX]'s `RECONSTRUCTION_CPP CODE` block. This is first-draft formal reconstruction text, not prose-only sample code.

```cpp
enum SayInputMode
{
    kSayInputModeDefault = 0,
    kSayInputModeShout = 1,
    kSayInputModeWhisper = 2,
    kSayInputModeGroup = 3,
    kSayInputModeClan = 4,
};

void OpenInputPaneForCurrentSayMode(UserPane *userPane)
{
    if (!g_useEpfAssets || g_pChattingHandlePane->m_chatTargetPending) {
        OpenDefaultSayPane(userPane);
        return;
    }

    switch (userPane->m_currentSayMode) {
    case kSayInputModeDefault:
        OpenDefaultSayPane(userPane);
        break;

    case kSayInputModeShout:
        OpenShoutInputPane(userPane);
        break;

    case kSayInputModeWhisper:
    {
        wchar_t recipientName[64] = L"";

        if (userPane->m_recentSayRecipients.GetCount() > 0) {
            wcscpy_s(
                recipientName,
                _countof(recipientName),
                userPane->m_recentSayRecipients.GetText(
                    userPane->m_recentSayRecipients.GetCount() - 1));
        }

        UpdateRecentRecipientList(userPane, recipientName);
        new NewSayToUserMessageInputPane(recipientName);
        break;
    }

    case kSayInputModeGroup:
        new SayToGroupMessageInputPane(L"!!");
        break;

    case kSayInputModeClan:
        new SayToClanMessageInputPane(L"!");
        break;

    default:
        break;
    }
}
```

Source-shape notes:

- The function is reconstructed as `void` because every identified caller uses it for side effects. The binary return register is inherited from the last constructor/helper call and is not a documented caller contract.
- `m_chatTargetPending`, `m_currentSayMode`, `m_recentSayRecipients`, `GetCount`, and `GetText` are best current source-facing names. Exact original spelling remains a final-audit cap, but raw `unk_`/offset names should not be used in final source-facing C++.
- The group/clan branches are expressed as constructor calls because that is the human source shape most likely to produce the observed inline constructor setup.
- The direct-message branch preserves the observed bounded 64-wide-character stack buffer, last-entry selection, `_wcscpy_s` behavior, recent-list update call, and `NewSayToUserMessageInputPane` construction.

## Support Documentation Recommendations

### `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md`

Implement:

- Update metadata to `90/92`.
- Insert the exact formal C++ block above.
- Replace stale blocker language with resolved evidence:
  - `byte_66DA97` is `g_useEpfAssets`.
  - `unk_67ADE0 + 0x111` is the pending chat-target flag on `g_pChattingHandlePane`.
  - `this + 0x3eb4` is `UserPane::m_currentSayMode`.
  - `this + 0x13eb08` is the recent-recipient list.
  - `sub_5A4B60` is the recent-recipient update/dedup helper.
  - raw `0x004cf937` is a jump-table case, not unresolved source ownership.
- Add current MCP session `80de0a67` evidence with exact caller/callee/range facts.
- Add score rationale explaining why the target is no longer blank-C++ blocked and why exact original spellings still cap confidence.

### `by-file/SayInputPanes.md`

Implement:

- Update the [UID:0002RX] row/section to state that the current-mode opener is now first-draft formal C++ ready.
- Add the resolved mode enum mapping:
  - `0`: default say.
  - `1`: shout.
  - `2`: direct-message/whisper through last recent recipient.
  - `3`: group message, default target text `L"!!"` and prompt `L"Group => "`.
  - `4`: clan message, default target text `L"!"` and prompt `L"Clan => "`.
- Add the raw `0x004cf937` switch-case route so future readers do not treat it as an unknown function.
- Preserve the `SayToClanMessageInputPane` source-facing name decision while noting the stable path remains `SayToPlanMessageInputPane.md`.

### `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`

Implement:

- Update the [UID:0002RX] entry to say formal C++ is now available in the exact child.
- Record that [UID:0002RX] consumes the `sub_5A4B60` recent-recipient helper and that mode 2 is the current-mode dispatcher path for opening `NewSayToUserMessageInputPane`.
- Keep this support page non-emitting. It remains a mixed neighborhood/index, not the owner of the exact target function.

### `by-global/g_pCollectionData.md`

Implement if supervisor accepts support edits:

- Add or strengthen the `UserPane + 0x3eb4` description as `m_currentSayMode`.
- Add or strengthen the `UserPane + 0x13eb08` description as the recent say/direct-message recipient list and note `UserPane + 0x13eb10` as the selector byte set by the recent-recipient update helper.
- No score change is required unless the file currently has stale or conflicting language.

### `by-global/g_pChattingHandlePane.md`

Implement if supervisor accepts support edits:

- Add a target-linked note that [UID:0002RX] reads `g_pChattingHandlePane + 0x111` as a pending chat-target flag that forces the default say input path.
- Use source-facing language such as `m_chatTargetPending` or "pending chat target state"; do not promote raw offset spelling as the final name.
- No score change is required unless current text conflicts with this behavior.

### `by-class/SayToPlanMessageInputPane.md`

Implement if supervisor accepts support edits:

- Add a cross-reference that [UID:0002RX] mode 4 constructs the source-facing `SayToClanMessageInputPane` path inline using `L"!"` and `L"Clan => "`.
- Keep the stable page/file path if required for UID continuity.
- No score change is required.

## Coverage Report Recommendation

B agents must not edit any `-coverage-report.md` file. If the supervisor wants manual coverage rows after implementation, the supervisor should update them separately after validating the by-* changes.

## Validation Plan for Implementation Callback

During implementation callback, run scoped validators from `source-3/project-documentation` for every edited by-* file. At minimum:

> Executable block R001 was removed from this report and preserved verbatim in [0002RX-OpenInputPaneForCurrentSayMode-source-quality-removed.md](0002RX-OpenInputPaneForCurrentSayMode-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support globals/classes are edited, validate each edited path with the same scoped command.

Do not manually edit `project-level/-auto-completion-stats.md`; refresh generated/project-level outputs only through the documented validator/report tool if the supervisor requests that after implementation.

## Implementation Tracking Checklist

Supervisor should validate this checklist before sending an implementation callback. During implementation, B009 should check off each accepted item only after applying it or proving it is already present/stale/not applicable.

- [x] Target metadata updated to `COMPLETION:90`, `CONFIDENCE:92`; owner/emitter route kept as `0000N9`, reconstructable true. Proof: `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md` metadata updated and validator command `000000002847` confirmed `completion_update 90`, `confidence_update 92`, `canonical_owner_update 0000N9`, and `ok: 1`.
- [x] Exact formal C++ block inserted into [UID:0002RX] `RECONSTRUCTION_CPP CODE`. Proof: target page now contains the accepted `SayInputMode` enum and `OpenInputPaneForCurrentSayMode(UserPane *userPane)` block; validator command `000000002847` recorded reconstruction code hash update and `blank -> block`.
- [x] Target prose updated with MCP session `80de0a67`, exact range, no-function exclusive end, caller map, raw jump-table route, branch behavior, helper identities, field/global names, score rationale, and rejected alternatives. Proof: target `Behavior`, `IDA Evidence`, `Reconstruction Notes`, `Score Rationale`, and `Changes` sections updated; command `000000002847` exited `0`.
- [x] `by-file/SayInputPanes.md` updated with the formal-C++-ready status, mode enum mapping, raw switch-case route, and clan-vs-plan source-facing name decision. Proof: proposed-content row, boundary/data notes, and changes section updated; validator command `000000002848` exited `0`, `ok: 1`. Existing unrelated missing-ref diagnostics remain.
- [x] `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` updated so [UID:0002RX] is no longer described as blank-C++ blocked and its recent-recipient helper dependency is clear. Proof: item summary, covered-range row, IDA evidence, and changes section updated; validator command `000000002849` exited `0`, `ok: 1`. Existing unrelated missing-ref diagnostics remain.
- [x] `by-global/g_pCollectionData.md` reviewed and updated for `m_currentSayMode`, recent recipient list, and selector-byte facts. Proof: `Other Player-State Views` now records `+0x3eb4` / `m_currentSayMode`, `+0x13eb08` / `m_recentSayRecipients`, and `+0x13eb10`; changes section records the B009 support sync. Final corrective validator command `000000002898` exited `0`, `ok: 1`; existing unrelated missing-ref diagnostics remain.
- [x] `by-global/g_pChattingHandlePane.md` reviewed and updated for the `+0x111` pending chat-target gate. Proof: evidence and changes sections now link [UID:0002RX] to `g_pChattingHandlePane + 0x111` / `m_chatTargetPending`; validator command `000000002852` exited `0`, `ok: 1`.
- [x] `by-class/SayToPlanMessageInputPane.md` reviewed and updated for the [UID:0002RX] mode-4 inline construction route. Proof: method notes, evidence notes, boundary matrix, and changes section now record the `90/92` dispatcher child and source-facing `SayToClanMessageInputPane` mode-4 route; validator command `000000002853` exited `0`, `ok: 1`.
- [x] No manual generated-file, project-level generated-file, manual coverage-report, validator/tool-state, or IDA DB edits performed. Proof: only by-* docs and this report were manually edited; validators produced allowed side effects in `tools/validator.ini`, `project-level/-auto-completion-stats.md`, and generated/autogen outputs.
- [x] Short leases used only for immediate implementation edits and released/expired immediately afterward. Proof: B009 leased the six edited by-* files for the implementation/validator batch; the cleanup `unlease` attempt after validation returned `Rejected[No active lease]` for all six, and the current lease report shows no active B009 leases.
- [x] Scoped validators run for every edited by-* file with exit `0` and reported `ok` counts. Proof: commands `000000002847`, `000000002848`, `000000002849`, `000000002898`, `000000002852`, and `000000002853` all exited `0` with `ok: 1`. All returned `generated_refresh: deferred`; `auto-generated/NexusTK/social/SayInputPanes.cpp` refreshed through validator command `000000002853` and contains [UID:0002RX]'s new C++ block. The generated refresh queue still had later pending jobs from broader validator activity, so only the target generated C++ header was used for freshness.

## Remaining Final-Audit Caps

These are not blockers to implementation or score improvement, but they should remain documented as confidence caps:

- Exact original source spellings for `m_currentSayMode`, `m_recentSayRecipients`, `m_chatTargetPending`, `GetCount`, and `GetText` are inferred, not symbol-proven.
- Exact original source signature may have been a `UserPane` member or a file-local helper taking `UserPane *`; current owner evidence supports [UID:0000N9] emission either way. The recommended source shape uses a file-level helper with explicit `UserPane *` because [UID:0000N9] owns the social-input source cluster.
- The target's binary return value is not used by known callers. The recommended source uses `void`; if a later project-wide source-signature pass requires preserving return expression shape, the body can be adapted without changing the documented branch behavior.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002RX-OpenInputPaneForCurrentSayMode-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0002RX-OpenInputPaneForCurrentSayMode-source-quality.md","timestamp":"2026-06-26T16:31:27","uid":"0002RX"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RX-OpenInputPaneForCurrentSayMode-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0002RX-OpenInputPaneForCurrentSayMode-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
