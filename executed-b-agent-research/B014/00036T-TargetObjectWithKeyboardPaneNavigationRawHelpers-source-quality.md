** TARGET-REPORT-UID:00036T **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00036T] TargetObjectWithKeyboardPaneNavigationRawHelpers Source-Quality / Split Report

Agent: B014  
Assignment: report-only B-source-quality pass  
Target: `source-3/project-documentation/by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`  
Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md`  
Date: 2026-06-19

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:00036T] into three exact raw-helper children and convert the current page into a non-emitting split/container page. The current broad page is not one source body; it contains three independent, unmodeled helper bodies plus internal alignment.
- Final disposition for current target: `CANONICAL_OWNER:0000ED`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. Recommended score for the container after the evidence is incorporated: `COMPLETION:88`, `CONFIDENCE:89`.
- Final disposition for future child pages: each child is NexusTK-owned source-authored raw code, probably class-scoped/file-static support for `TargetObjectWithKeyboardPane`, but no formal C++ should be emitted until the supervisor explicitly accepts a retained-dead-static-helper policy or a real entry route is recovered. Recommended initial child scores: `85/88` for each exact body with blank emitters/C++.
- Confidence: strong for exact byte ranges, behavior, negative route evidence, `dword_69BF2C` role, and TargetObject/source-family ownership; medium-high for final original helper spellings and for whether the original source expressed these as private static class helpers or file-static helpers.

## Supporting Research

## Target

- Target UID: `00036T`
- Target path: `source-3/project-documentation/by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000ED`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ED`, blank formal C++.
- Current supervisor focus: three raw navigation helper bodies at `0x005b05d0`, `0x005b0640`, and `0x005b06b0`; previous/next/local-player semantics; target highlight toggling; `dword_69BF2C` source-quality name; split policy; relationship to keyboard handler and dispatch-forward helper.
- Related owner: [UID:0000ED] `by-class/TargetObjectWithKeyboardPane.md`.
- Source module context: [UID:0000OH] `by-file/TargetSelectionInputPanes.md`.

## Executive Recommendation

The current page should not remain an emitting singular raw island. It should become a reviewed container over three exact raw bodies:

| Proposed child range | Proposed child filename | Source-facing role | Initial C++ policy |
| --- | --- | --- | --- |
| `0x005b05d0-0x005b0638` | `0x005b05d0-0x005b0638.TargetObjectWithKeyboardPaneSelectPreviousTargetRawHelper.md` | Select the previous/up selectable target object from `s_targetObjectTargetId`. | Blank formal C++; document source-shaped candidate only. |
| `0x005b0640-0x005b06a8` | `0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md` | Select the next/down selectable target object from `s_targetObjectTargetId`. | Blank formal C++; document source-shaped candidate only. |
| `0x005b06b0-0x005b06ef` | `0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md` | Select the local-player object as the target-object saved target. | Blank formal C++; document source-shaped candidate only. |

The internal padding should be ignored separately if child pages are created:

- `0x005b0638-0x005b0640`: eight `0xcc` bytes between the previous-target and next-target raw bodies.
- `0x005b06a8-0x005b06b0`: eight `0xcc` bytes between the next-target and local-player raw bodies.
- `0x005b06ef-0x005b06f0`: one `0xcc` byte before [UID:00036U] `TargetObjectWithKeyboardPaneDispatchForwardHelper`.

Do not put formal C++ into [UID:00036T]. The parent page would have to contain three separate function bodies, which violates the by-memory source-scope rule for aggregate pages. Do not emit child C++ yet either: a direct PE scan found zero call/jump references and zero VA/RVA pointer hits to all three raw starts, and the active keyboard handler already contains inlined/direct copies of the same self/previous/next logic.

## Supervisor Active Recheck

- The assignment is report-only. I did not edit target/support by-* docs, generated files, project-level reports, IDA DB, or `by-memory/-coverage-report.md`.
- `by-structure.md` requires exact child pages for understood subitems inside aggregate ranges and restricts a by-memory code block to the exact range represented by that page.
- `inference_research.md` pushes source-placement conclusions to be confidence-labeled and evidence-backed. For this target, direct instruction semantics and xref absence are hard evidence; helper names and static/member source shape remain inferred.
- The current report closes the stale "raw helper island, maybe split later" question: split is structurally preferred, but the resulting raw children should remain non-emitting until route/source-retention policy is accepted.

## Inference Research Guidance Check

Facts used:

- Read-only PE byte/disassembly scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Existing live-IDA-backed by-* docs for `TargetObjectWithKeyboardPane`, `TargetSelectionInputPanes`, keyboard/mouse/clear/dispatch helper pages, saved-target globals, active MapPane singleton, and local-player/UserPane storage.
- Existing executed B005 report for [UID:0001LL] `TargetObjectWithKeyboardPaneMouseEvent`, used only as a source-quality lead for accepted names.

Limitations:

- Current session exposes no IDA MCP namespace. HTTP JSON-RPC probe to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`.
- I therefore do not claim new live-IDB renames, function creation, or IDA comments. The new hard evidence is local PE bytes plus Capstone disassembly/reference scans.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported conclusion | Rejected alternatives / uncertainty |
| --- | --- | --- | --- |
| Raw starts and exact subranges | PE disassembly of `0x005b05d0-0x005b06f0`; existing target/class/file docs. | Three executable bodies start at `0x005b05d0`, `0x005b0640`, `0x005b06b0`. Body ends are `0x005b0638`, `0x005b06a8`, and `0x005b06ef`; padding follows each body where noted. | Reject one-source-body aggregate. The current `0x005b05d0-0x005b06ef` page includes internal padding and excludes the final `0xcc`, so it is a documentation container, not a precise source body. |
| Direct route/reachability | Full `.text` scan for rel32 `call`/`jmp` to raw starts; full-file scan for absolute VA and RVA dword hits. | Zero rel32 `call`/`jmp` refs and zero VA/RVA dword hits to `0x005b05d0`, `0x005b0640`, and `0x005b06b0`. No vtable/data route was found in the local PE scan. | Reject active keyboard-handler-callee wording. These raw starts are not called by [UID:0001LK]. They are retained/unreferenced raw helper bodies or dead helper clones in the same source/object area. |
| Relationship to keyboard handler | PE disassembly of [UID:0001LK] around `0x005b0111-0x005b01d7`; keyboard doc. | The keyboard handler directly inlines equivalent logic: self target resolves current target at `0x005b011d`, clears old highlight at `0x005b0132`, highlights local player at `0x005b013b`, stores `dword_69BF2C` at `0x005b0147`; previous path calls `0x00506ae0` at `0x005b0177`; next path calls `0x00506b30` at `0x005b01a4`; common tail clears/highlights/stores or clears at `0x005b01b5-0x005b01cc`. | Reject "navigation helper body is the active key implementation." The active key path duplicates the same logic but does not branch to these raw starts. |
| Source-facing saved-target global name | B005 TargetObject mouse report, saved globals doc, class/file docs, raw bodies. | Use `s_targetObjectTargetId` as the primary descriptive source-facing name for `dword_69BF2C`; `s_targetObjectSavedTargetId` is an acceptable longer alias. | Reject older project-level alias `g_savedTargetDispatchObjectId` for new target docs because current support docs and accepted B005 work prefer the class-family `s_targetObject...` names. |
| Helper names for `0x005b05d0` | Body calls `MapPane::FindObjectPaneById`, then `0x00506ae0`, then toggles highlights/stores target id. Keyboard previous/up group uses same `0x00506ae0`. | Source-facing role/name: `SelectPreviousTargetObject` or `SelectPreviousTarget`. Prefer child filename `TargetObjectWithKeyboardPaneSelectPreviousTargetRawHelper` and prose name `SelectPreviousTargetObject()`. | Not a MapPane method: it mutates target-selection saved state. Not an instance method with `this`: it takes no `ecx`/stack parameter and uses only globals. |
| Helper names for `0x005b0640` | Body calls `MapPane::FindObjectPaneById`, then `0x00506b30`, then toggles highlights/stores target id. Keyboard next/down group uses same `0x00506b30`. | Source-facing role/name: `SelectNextTargetObject` or `SelectNextTarget`. Prefer child filename `TargetObjectWithKeyboardPaneSelectNextTargetRawHelper`. | Not a generic traversal helper: it is TargetObject-specific because it updates `s_targetObjectTargetId`. |
| Helper names for `0x005b06b0` | Body resolves `s_targetObjectTargetId`, compares with `dword_67A748` local-player object, toggles highlight, stores `[local + 0xfc]`. | Source-facing role/name: `SelectLocalPlayerTargetObject()`; `SelectSelfTarget()` is acceptable in keyboard-event prose. | Not a constructor/destructor, thunk, switch table, or compiler glue. It is executable source-shaped selector logic, but currently unreferenced. |
| MapPane helper names | Sibling SelectObject and B005 TargetObject docs; call sites in raw bodies. | `0x00506970` = `MapPane::FindObjectPaneById`; `0x00506ae0` = `MapPane::FindPreviousSelectableObject`; `0x00506b30` = `MapPane::FindNextSelectableObject`. | Exact original spellings are not symbol-proven, but descriptive names are strong because sibling first-draft C++ already uses them and dataflow matches. |
| Highlight helper name | Many target-selection docs and B005 report; calls in raw bodies with flag `0` and `1`. | `0x0053b1b0` = `LivingObjectPane::SetTargetHighlight(bool)`. | Reject treating the flag as visibility or focus generically; surrounding target-selection flows consistently use it for selection highlight. |
| Local player/global source name | [UID:0001OR] storage doc and B005 report. Raw bodies read `dword_67A748` and use `+0xfc` object id. | In TargetObject source-facing prose, use `g_pUserPane` / local-player object view, while preserving [UID:0001OR] broader storage alias `g_pCollectionData`. Field `+0xfc` is the living-object id accessed as `GetObjectId()`. | Do not create a new independent local-player global for this target. The storage page already explains the broad UserPane/player-state alias. |
| Owner/source placement | Address locality after TargetObject mouse handler; same saved target global as constructor, keyboard, mouse, clear, object-list, and dispatch-forward helpers; class/file docs. | Direct semantic owner remains [UID:0000ED] `TargetObjectWithKeyboardPane`, with source module [UID:0000OH] `TargetSelectionInputPanes`. If child C++ is ever emitted, source shape should be private static/class-scoped or file-static helper functions in this source family, not instance methods. | Reject `MapPane` owner; MapPane supplies lookup/traversal helpers but does not own `s_targetObjectTargetId`. Reject `UserPane`; it is the local-player fallback object only. Reject `LineInputPane`; it owns inherited event plumbing only. |
| Emitter policy | Current generated output has only an empty marker for [UID:00036T]; autogen coverage marks it as `emits` because `EMITTER_UIDS:0000ED`, but no code is inserted. | Clear `EMITTER_UIDS` on the current aggregate/container. If children are created, leave child emitters blank until route/source-retention policy is accepted. | Do not leave aggregate emitting through the class because it has no single formal source body and no route to a callable helper surface. |
| First-draft C++ readiness | Combined score currently qualifies the old minimum gate, but direct route, split scope, and source shape fail the code-quality side of the gate. | No formal C++ for [UID:00036T]. No formal child C++ initially. Document source-shaped candidate logic as behavior only. | Reject old `95/95` threshold wording. The blocker is not score; it is aggregate split plus no direct entry route for raw child starts. |

## Evidence Standards Used

- Direct PE facts: exact section mapping, bytes, instruction semantics, call targets, returns, padding, rel32 refs, absolute VA/RVA pointer hits.
- Documentation evidence: existing by-memory/class/file/global docs with stable UIDs, plus B005 executed report for accepted names.
- Inference: final helper names and source shape are descriptive/high-probability, not original-symbol proof.
- Negative evidence: no route to the raw starts found through rel32 calls/jumps or pointer literals; active keyboard handler contains equivalent inline logic.

## Local PE / IDA Facts

Read-only PE:

- Path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- Relevant section: `.text`, RVA `0x1000`, raw pointer `0x400`

Live IDA access:

- HTTP probe to `http://127.0.0.1:13337/mcp` with `tools/list` failed: `Unable to connect to the remote server`.
- Existing by-* docs preserve prior live IDA facts, including that IDA did not model starts at `0x005b05d0`, `0x005b0640`, or `0x005b06b0`.

Raw body A, `0x005b05d0-0x005b0638`:

- Starts with `mov ecx, dword ptr [0x67a764]`, saves `esi/edi`, pushes `dword ptr [0x69bf2c]`, calls `0x00506970`.
- If current target resolves, calls `0x00506ae0(g_activeMapPane, currentTarget)`; otherwise falls back to `dword_67A748`.
- Compares old/new object pointers, clears old highlight with `0x0053b1b0(old, 0)`, highlights new target with `0x0053b1b0(new, 1)`, stores `[new+0xfc]` into `0x0069bf2c`, or stores `0` if no new target exists.
- Returns at `0x005b062a` on the store-new path and at `0x005b0637` after the no-change/clear path.
- `0x005b0638-0x005b0640` is eight `0xcc` bytes.

Raw body B, `0x005b0640-0x005b06a8`:

- Same shape as body A but calls `0x00506b30(g_activeMapPane, currentTarget)`.
- Stores `[new+0xfc]` into `0x0069bf2c` or stores `0`.
- Returns at `0x005b069a` on the store-new path and at `0x005b06a7` after the no-change/clear path.
- `0x005b06a8-0x005b06b0` is eight `0xcc` bytes.

Raw body C, `0x005b06b0-0x005b06ef`:

- Loads `g_activeMapPane`, saves `esi`, pushes `dword ptr [0x69bf2c]`, loads `esi = dword_67A748`, calls `0x00506970`.
- If current target already equals local player, returns.
- Otherwise clears old highlight when present, highlights local player, stores `[localPlayer+0xfc]` into `0x0069bf2c`, pops `esi`, and returns at `0x005b06ee`.
- `0x005b06ef` is one `0xcc` byte before modeled [UID:00036U] at `0x005b06f0`.

Direct reference scan:

| Target | rel32 call/jmp refs | absolute VA dword hits | RVA dword hits |
| --- | ---: | ---: | ---: |
| `0x005b05d0` | 0 | 0 | 0 |
| `0x005b0640` | 0 | 0 | 0 |
| `0x005b06b0` | 0 | 0 | 0 |
| `0x005b05b0` clear helper | 3 rel32 calls at `0x005b0082`, `0x005b0422`, `0x005b0495` | 0 | 0 |
| `0x005b06f0` dispatch-forward helper | 2 rel32 calls at `0x005b00ce`, `0x005b00f4` | 0 | 0 |

The negative route finding is specific: the neighboring modeled helpers have direct call refs, while the three raw starts have none.

Keyboard-handler comparison:

- Self/local-player arm in [UID:0001LK] uses `sub_506970` at `0x005b011d`, clears old highlight at `0x005b0132`, highlights local player at `0x005b013b`, and writes `dword_69BF2C` at `0x005b0147`.
- Previous/up arm uses `sub_506970` at `0x005b0165`, calls `sub_506AE0` at `0x005b0177`, and enters the common highlight/update tail.
- Next/down arm uses `sub_506970` at `0x005b0192`, calls `sub_506B30` at `0x005b01a4`, and enters the common highlight/update tail.
- Common tail `0x005b01b5-0x005b01cc` clears old highlight, highlights new/local player, writes `[new+0xfc]`, or clears `dword_69BF2C`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent | Score recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b05d0-0x005b06ef` | [UID:00036T] current target | Container over three raw navigation helper bodies. | `FALSE` after split | `0000ED` | `88/89` | Non-emitting split/index; no formal C++. |
| `0x005b05d0-0x005b0638` | New child path recommended | Select previous/up target. | `TRUE` | `0000ED` | `85/88` | Raw source-authored body, no direct route, blank emitter/C++. |
| `0x005b0638-0x005b0640` | `by-memory/-ignored.md` row recommended | Padding. | `FALSE` | `0000VN` ignored ledger | `100/strong` coverage row | Eight `0xcc` bytes. |
| `0x005b0640-0x005b06a8` | New child path recommended | Select next/down target. | `TRUE` | `0000ED` | `85/88` | Raw source-authored body, no direct route, blank emitter/C++. |
| `0x005b06a8-0x005b06b0` | `by-memory/-ignored.md` row recommended | Padding. | `FALSE` | `0000VN` ignored ledger | `100/strong` coverage row | Eight `0xcc` bytes. |
| `0x005b06b0-0x005b06ef` | New child path recommended | Select local-player/self target. | `TRUE` | `0000ED` | `85/88` | Raw source-authored body, no direct route, blank emitter/C++. |
| `0x005b06ef-0x005b06f0` | `by-memory/-ignored.md` row recommended | Padding. | `FALSE` | `0000VN` ignored ledger | `100/strong` coverage row | One `0xcc` byte. |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x005b05d0` | No rel32 or pointer refs found. | Raw previous-target helper is retained/unreferenced by the checked binary. |
| `0x005b0640` | No rel32 or pointer refs found. | Raw next-target helper is retained/unreferenced by the checked binary. |
| `0x005b06b0` | No rel32 or pointer refs found. | Raw local-player target helper is retained/unreferenced by the checked binary. |
| `0x005b05b0` | Calls from keyboard/mouse handlers at `0x005b0082`, `0x005b0422`, `0x005b0495`. | Neighboring clear helper has an active route; this contrasts with the raw island. |
| `0x005b06f0` | Calls from keyboard handler at `0x005b00ce`, `0x005b00f4`. | Neighboring dispatch-forward helper has an active route; this contrasts with the raw island. |
| `0x00506970` | Calls from all three raw bodies and active keyboard/mouse flows. | `MapPane::FindObjectPaneById`. |
| `0x00506ae0` | Raw body A and active keyboard previous/up arm. | `MapPane::FindPreviousSelectableObject`. |
| `0x00506b30` | Raw body B and active keyboard next/down arm. | `MapPane::FindNextSelectableObject`. |
| `0x0053b1b0` | Calls from all three raw bodies and active target-selection flows. | `LivingObjectPane::SetTargetHighlight(bool)`. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0000ED] `TargetObjectWithKeyboardPane.md` already assigns the raw island to the class and lists the three raw starts.
- [UID:0000OH] `TargetSelectionInputPanes.md` already places the suffix helpers in the target-selection source family.
- [UID:0001LK] `TargetObjectWithKeyboardPaneKeyboardEvent.md` documents the active self/previous/next behavior and the saved-target/highlight state updates.
- [UID:00036S] `TargetObjectWithKeyboardPaneClearCurrentTarget.md` and [UID:00036U] `TargetObjectWithKeyboardPaneDispatchForwardHelper.md` document the modeled neighbors and their direct keyboard/mouse call routes.
- [UID:0002AB] `TargetSelectionSavedTargetGlobals.md` already uses `s_targetObjectTargetId` / `s_targetObjectSavedTargetId` for `dword_69BF2C`.
- [UID:0001OW] `ActiveMapPaneSingleton.md` and [UID:0001OR] `g_pCollectionData.md` document the active map and broad local-player/UserPane pointer storage.
- Executed B005 `0001LL-TargetObjectWithKeyboardPaneMouseEvent-source-quality.md` accepted the same source-facing names for `s_targetObjectTargetId`, `g_activeMapPane`, `LivingObjectPane::SetTargetHighlight`, and target-selection dependencies.

Existing docs that are stale or incomplete:

- [UID:00036T] does not record the direct-route negative evidence. It says the bodies match the keyboard handler but does not explicitly say the keyboard handler does not call them.
- [UID:0000ED] and [UID:0000OH] should clarify that the active keyboard handler inlines the same logic and that the raw starts have no direct refs in the current scan.
- `auto-generated/-ag-memory-coverage.md` says [UID:00036T] "emits" because the page has `EMITTER_UIDS:0000ED`; the generated `TargetSelectionInputPanes.cpp` contains only an empty marker. The emitter route should be cleared on the aggregate.
- `by-memory/-coverage-report.md` currently jumps from [UID:0001LL] `0x005b0290-0x005b050d` to [UID:0001LN] `0x005b0780-0x005b14e6`, so it is missing the documented TargetObject suffix rows [UID:00036R], [UID:00036S], [UID:00036T], [UID:00036U], and related padding.

## Ranked Ownership Analysis

### 1. [UID:0000ED] TargetObjectWithKeyboardPane - Accepted Semantic Owner

Evidence for:

- The raw bodies operate exclusively on `s_targetObjectTargetId` / `dword_69BF2C`, the saved object id used by `TargetObjectWithKeyboardPane` constructor, keyboard handler, mouse handler, object-list helper, clear helper, and dispatch-forward helper.
- The bodies sit between TargetObject-specific modeled helpers at `0x005b05b0` and `0x005b06f0`.
- Source behavior matches active TargetObject keyboard navigation semantics.
- The parent class is above the gate and already owns the surrounding suffix pages.

Evidence against:

- The raw bodies take no `this` pointer and have no direct route, so they are probably not ordinary non-static instance methods.

Decision:

- Keep [UID:0000ED] as the semantic documentation owner, but state that the source shape is private static/class-scoped or file-static helper code, not an ordinary `thiscall` instance method.

### 2. [UID:0000OH] TargetSelectionInputPanes - Accepted Source Module / Secondary Owner

Evidence for:

- The target-selection source family owns the SpellWho/ItemWho/SelectObject/TargetObject input-pane cluster and the saved-target globals.
- A file-scope static helper implementation would naturally live in `TargetSelectionInputPanes.cpp`.

Evidence against:

- The state is not generic to all target-selection panes; it is the TargetObject saved target slot and class suffix neighborhood.

Decision:

- Use [UID:0000OH] as the source module context and final generated source root. Do not promote it over [UID:0000ED] for `CANONICAL_OWNER` unless the project decides all no-`this` class-specific static helpers must be file-owned.

### 3. [UID:0001OW] MapPane / `g_activeMapPane` - Rejected Owner

Evidence for:

- `MapPane` supplies lookup and traversal callees.

Evidence against:

- The raw bodies mutate `TargetObjectWithKeyboardPane` saved selection state and target highlights; they do not mutate MapPane ownership state or implement generic traversal.

Decision:

- Dependency only.

### 4. [UID:0001OR] UserPane / local player storage - Rejected Owner

Evidence for:

- `dword_67A748` is used as the local-player fallback/self target object.

Evidence against:

- It is only the selected object. The raw bodies do not own UserPane lifetime or broad player-state layout.

Decision:

- Dependency only.

### 5. Compiler-generated/padding/ignored - Rejected for body bytes, accepted for internal padding

Evidence for:

- IDA did not model the starts as functions and no callers were found.

Evidence against:

- The bytes are coherent executable logic with real project callees and source-shaped saved-target behavior.

Decision:

- Raw body bytes are source-authored but retained/unreferenced; internal `0xcc` bytes are compiler/linker alignment and should be ignored.

## Negative Evidence Summary

- Zero rel32 calls/jumps to raw starts `0x005b05d0`, `0x005b0640`, `0x005b06b0`.
- Zero absolute VA dword hits and zero RVA dword hits to the same starts.
- No route through neighboring modeled helpers; the clear helper and dispatch-forward helper both have direct call refs, but the raw starts do not.
- No vtable route observed or documented; the TargetObject vtables route keyboard/mouse/object-list/destructor surfaces, not these raw starts.
- The active keyboard handler contains equivalent inlined logic, so behavior similarity is not caller proof.
- The raw bodies take no `this` pointer; ordinary instance-method declarations are not supported.

## First-Draft C++ / No-Code Proof

Do not populate formal C++ for [UID:00036T].

Target-specific no-code proof:

1. [UID:00036T] is not one source body. It contains three independent `void`-shaped raw helper bodies and internal padding.
2. The three raw starts have no direct `call`/`jmp` refs and no VA/RVA pointer refs in the local PE scan.
3. The neighboring modeled helpers at `0x005b05b0` and `0x005b06f0` do have direct refs, proving the scan method finds normal routes in this exact neighborhood.
4. The active keyboard handler already implements the same self/previous/next target-selection logic inline, so these raw helpers are not required to explain active key behavior.
5. The likely source shape is retained file-static/private-static helper functions, but final original names and source-retention policy are not proven.
6. Adding formal C++ to the aggregate would place child-body code in the parent page, which violates the by-memory code-scope rule.

Source-shaped candidate signatures for documentation only:

```cpp
static void SelectPreviousTargetObject();
static void SelectNextTargetObject();
static void SelectLocalPlayerTargetObject();
```

If a future implementation callback creates exact child pages and the supervisor explicitly accepts emitting retained dead helper functions, use child-level first-draft C++ only, not aggregate C++. The child code should be simple source-style helper logic using `s_targetObjectTargetId`, `g_activeMapPane`, `g_pUserPane` / local-player object view, and `LivingObjectPane::SetTargetHighlight`.

## Recommended Exact Target / Support Changes

### Target: `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`

Recommended metadata after split:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ED | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended body changes:

- Replace "raw helper island" as a reconstructable emitting item with "reviewed non-emitting split/container over three source-authored raw helper bodies."
- Add a `Covered Raw Bodies` table with:
  - `0x005b05d0-0x005b0638` previous/up raw body.
  - `0x005b0638-0x005b0640` eight `0xcc` padding bytes.
  - `0x005b0640-0x005b06a8` next/down raw body.
  - `0x005b06a8-0x005b06b0` eight `0xcc` padding bytes.
  - `0x005b06b0-0x005b06ef` local-player/self raw body.
  - `0x005b06ef-0x005b06f0` one `0xcc` padding byte before [UID:00036U].
- Add source-facing names:
  - `dword_69BF2C` -> `s_targetObjectTargetId` / `s_targetObjectSavedTargetId`.
  - `dword_67A764` -> `g_activeMapPane`.
  - `dword_67A748` -> local-player/UserPane object view; source prose may use `g_pUserPane` or `g_pLocalPlayerObject` with the [UID:0001OR] alias caveat.
  - `sub_506970` -> `MapPane::FindObjectPaneById`.
  - `sub_506AE0` -> `MapPane::FindPreviousSelectableObject`.
  - `sub_506B30` -> `MapPane::FindNextSelectableObject`.
  - `sub_53B1B0` -> `LivingObjectPane::SetTargetHighlight(bool)`.
  - object `+0xfc` -> object id / `GetObjectId()`.
- Add route-negative evidence:
  - local PE hash and date;
  - zero rel32 call/jump refs to `0x005b05d0`, `0x005b0640`, `0x005b06b0`;
  - zero absolute VA and zero RVA pointer hits to those starts;
  - neighboring `0x005b05b0` and `0x005b06f0` have direct refs, so the negative route is meaningful.
- Add keyboard-handler relationship correction:
  - [UID:0001LK] implements equivalent logic inline; it does not call these raw starts.
  - Cite self path at `0x005b011d/0x005b0132/0x005b013b/0x005b0147`, previous path at `0x005b0165/0x005b0177`, next path at `0x005b0192/0x005b01a4`, and common tail at `0x005b01b5-0x005b01cc`.
- Add rejected alternatives:
  - not padding/compiler-only for body bytes;
  - not active keyboard callees;
  - not MapPane-owned;
  - not UserPane-owned;
  - not ordinary non-static `TargetObjectWithKeyboardPane` instance methods;
  - not formal aggregate C++ ready.

If the supervisor chooses not to split immediately, a lower-risk interim update is acceptable: keep the existing page as `RECONSTRUCTABLE:TRUE`, raise to `87/88`, clear `EMITTER_UIDS`, and add the same evidence/no-code proof. The split remains the preferred structural fix.

### New child pages if split is accepted

Create:

- `by-memory/0x005b05d0-0x005b0638.TargetObjectWithKeyboardPaneSelectPreviousTargetRawHelper.md`
- `by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md`
- `by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md`

Recommended metadata for each initial child:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000ED
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Recommended child common text:

- "Source-authored raw body retained in the TargetObjectWithKeyboardPane source neighborhood; no direct route found in B014 PE scan."
- "Semantic owner is TargetObjectWithKeyboardPane; source module is TargetSelectionInputPanes."
- "Formal C++ remains blank because no direct caller/pointer/vtable route is known; this is likely retained/static helper code duplicated by active keyboard handler logic."

### `by-class/TargetObjectWithKeyboardPane.md`

Recommended changes:

- Update the method row for [UID:00036T] to call it a non-emitting raw helper container pending exact child split.
- Add that B014's PE scan found no direct refs or pointer refs to `0x005b05d0`, `0x005b0640`, or `0x005b06b0`.
- Clarify that [UID:0001LK] contains the active key-navigation implementation inline; [UID:00036T] is retained/unreferenced raw helper code with matching behavior, not a keyboard-handler callee.
- Add source-facing names for the three roles: `SelectPreviousTargetObject`, `SelectNextTargetObject`, `SelectLocalPlayerTargetObject`.
- No class score change is required. If the class status is refreshed, `87/88` can stay because the raw island is now better understood but remains non-emitting/no-route.

### `by-file/TargetSelectionInputPanes.md`

Recommended changes:

- Replace the generic raw-island note with exact body ranges and route-negative evidence.
- State that the raw bodies are source-shaped retained TargetObject navigation helpers in the source module, while active keyboard navigation is in [UID:0001LK].
- Add split recommendation and no formal aggregate C++ policy.
- Keep score unchanged unless the file page receives a broader suffix-helper coverage refresh.

### `by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md`

Recommended changes:

- Add a relationship note: [UID:00036T] duplicates the self/previous/next target update patterns but is not called by this handler in the checked PE.
- Keep the current method C++ policy independent of [UID:00036T]; this method remains the active virtual keyboard handler.
- Optional future source-quality work: this method is now a better candidate for first-draft C++ than [UID:00036T], because it has vtable reachability and active behavior. That is outside this report's implementation scope.

### `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`

Recommended changes:

- No score/metadata change required.
- Optional support note: B014 raw-island recheck confirms `dword_69BF2C` is read/written by the retained raw helper bodies as the TargetObject saved/current selected object id; preferred source names remain `s_targetObjectTargetId` / `s_targetObjectSavedTargetId`.

### `by-memory/-ignored.md`

If child split is accepted, add ignored padding entries:

```text
- `0x005b0638-0x005b0640` - `TargetObjectWithKeyboardPane` raw navigation helper alignment.
  - Why ignored: eight `0xcc` compiler/linker alignment bytes between the previous-target and next-target retained raw helper bodies.
  - Evidence: B014 2026-06-19 PE/Capstone scan over `NexusTK.exe` hash `4247e04e20b65d6414c7238aa8ff5515`.
  - Replacement/procurement: compiler/linker alignment.

- `0x005b06a8-0x005b06b0` - `TargetObjectWithKeyboardPane` raw navigation helper alignment.
  - Why ignored: eight `0xcc` compiler/linker alignment bytes between the next-target and local-player retained raw helper bodies.
  - Evidence: B014 2026-06-19 PE/Capstone scan over `NexusTK.exe` hash `4247e04e20b65d6414c7238aa8ff5515`.
  - Replacement/procurement: compiler/linker alignment.

- `0x005b06ef-0x005b06f0` - `TargetObjectWithKeyboardPane` navigation-to-dispatch alignment.
  - Why ignored: one `0xcc` compiler/linker alignment byte after the local-player retained raw helper body and before [UID:00036U][0x005b06f0-0x005b077a.TargetObjectWithKeyboardPaneDispatchForwardHelper](by-memory/0x005b06f0-0x005b077a.TargetObjectWithKeyboardPaneDispatchForwardHelper.md).
  - Evidence: B014 2026-06-19 PE/Capstone scan over `NexusTK.exe` hash `4247e04e20b65d6414c7238aa8ff5515`.
  - Replacement/procurement: compiler/linker alignment.
```

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. Placement context: insert the TargetObject suffix rows after the current [UID:0001LL] row for `0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent` and before the current [UID:0001LN] row for `0x005b0780-0x005b14e6.SpellArgumentInputPanes`.

Minimum exact row for current target if the supervisor applies only this report without child split:

```text
        - [UID:00036T][0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers](by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md) 0x005b05d0-0x005b06ef | raw helper island | TargetObjectWithKeyboardPaneNavigationRawHelpers : reconstructable : 87% : strong : B014 2026-06-19 PE/Capstone recheck confirms three source-authored raw TargetObject navigation helper bodies at `0x005b05d0`, `0x005b0640`, and `0x005b06b0`; previous/up uses `MapPane::FindPreviousSelectableObject` / `0x00506ae0`, next/down uses `MapPane::FindNextSelectableObject` / `0x00506b30`, and local-player retarget uses `dword_67A748`; all resolve/update `s_targetObjectTargetId` / `dword_69BF2C`, toggle `LivingObjectPane::SetTargetHighlight`, and store object id `+0xfc`; scan found zero rel32 call/jump refs and zero VA/RVA pointer hits to the raw starts, while neighboring clear/dispatch helpers have active refs, so formal C++ remains blank and emitter routing should be cleared pending split/retained-static-helper policy.
```

Preferred coverage text if split is accepted. Child rows require validator-assigned UIDs at creation time; replace `UID:<new>` placeholders with the actual new UIDs before supervisor-owned coverage application:

```text
        - [UID:00036T][0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers](by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md) 0x005b05d0-0x005b06ef | raw helper container | TargetObjectWithKeyboardPaneNavigationRawHelpers : ignored : 88% : strong : B014 2026-06-19 PE/Capstone recheck converts the old emitting raw island into a non-emitting split/container over three retained source-authored TargetObject navigation helper bodies. The checked PE has zero rel32 call/jump refs and zero VA/RVA pointer hits to starts `0x005b05d0`, `0x005b0640`, and `0x005b06b0`; active keyboard navigation duplicates the same self/previous/next logic inline, so the parent carries no formal C++ and exact children carry any future retained-static-helper source policy.
            - [UID:<new>][0x005b05d0-0x005b0638.TargetObjectWithKeyboardPaneSelectPreviousTargetRawHelper](by-memory/0x005b05d0-0x005b0638.TargetObjectWithKeyboardPaneSelectPreviousTargetRawHelper.md) 0x005b05d0-0x005b0638 | raw helper | TargetObjectWithKeyboardPaneSelectPreviousTargetRawHelper : reconstructable : 85% : strong : Retained source-authored TargetObject helper body resolving `s_targetObjectTargetId` through `MapPane::FindObjectPaneById`, traversing previous/up with `MapPane::FindPreviousSelectableObject` / `0x00506ae0` or falling back to local player, clearing old highlight, setting new highlight, and storing or clearing the saved target id; no direct call/pointer/vtable route found, so blank formal C++ and blank emitter initially.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b0638-0x005b0640 | padding | TargetObjectWithKeyboardPane previous-to-next raw helper alignment : ignored : 100% : strong : B014 PE/Capstone scan confirmed eight `0xcc` bytes between retained raw helper bodies.
            - [UID:<new>][0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper](by-memory/0x005b0640-0x005b06a8.TargetObjectWithKeyboardPaneSelectNextTargetRawHelper.md) 0x005b0640-0x005b06a8 | raw helper | TargetObjectWithKeyboardPaneSelectNextTargetRawHelper : reconstructable : 85% : strong : Retained source-authored TargetObject helper body resolving `s_targetObjectTargetId` through `MapPane::FindObjectPaneById`, traversing next/down with `MapPane::FindNextSelectableObject` / `0x00506b30` or falling back to local player, clearing old highlight, setting new highlight, and storing or clearing the saved target id; no direct call/pointer/vtable route found, so blank formal C++ and blank emitter initially.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b06a8-0x005b06b0 | padding | TargetObjectWithKeyboardPane next-to-local-player raw helper alignment : ignored : 100% : strong : B014 PE/Capstone scan confirmed eight `0xcc` bytes between retained raw helper bodies.
            - [UID:<new>][0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper](by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md) 0x005b06b0-0x005b06ef | raw helper | TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper : reconstructable : 85% : strong : Retained source-authored TargetObject helper body resolving the current saved target, comparing it to the local-player/UserPane object view at `dword_67A748`, clearing the old highlight when needed, highlighting local player, and storing `[localPlayer+0xfc]` into `s_targetObjectTargetId`; no direct call/pointer/vtable route found, so blank formal C++ and blank emitter initially.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b06ef-0x005b06f0 | padding | TargetObjectWithKeyboardPane navigation-to-dispatch alignment : ignored : 100% : strong : B014 PE/Capstone scan confirmed one `0xcc` byte before [UID:00036U][0x005b06f0-0x005b077a.TargetObjectWithKeyboardPaneDispatchForwardHelper](by-memory/0x005b06f0-0x005b077a.TargetObjectWithKeyboardPaneDispatchForwardHelper.md).
```

Recommended related suffix rows currently missing from `by-memory/-coverage-report.md` and useful placement context:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b050d-0x005b0510 | padding | TargetObjectWithKeyboardPane mouse-to-object-list alignment : ignored : 100% : strong : Existing docs and B005 byte checks confirm three `0xcc` bytes between [UID:0001LL][0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent](by-memory/0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md) and [UID:00036R][0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper](by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md).
        - [UID:00036R][0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper](by-memory/0x005b0510-0x005b05a3.TargetObjectWithKeyboardPaneObjectListHelper.md) 0x005b0510-0x005b05a3 | helper | TargetObjectWithKeyboardPaneObjectListHelper : reconstructable : 85% : strong : Existing exact split page documents the modeled `sub_5B0510` object-list helper, saved target `dword_69BF2C` checks, local-player/highlight fallback pattern, exact start/end, and TargetObject owner/source-module route.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b05a3-0x005b05b0 | padding | TargetObjectWithKeyboardPane object-list-to-clear alignment : ignored : 100% : strong : Existing [UID:00036R] docs record thirteen `0xcc` bytes before [UID:00036S][0x005b05b0-0x005b05cf.TargetObjectWithKeyboardPaneClearCurrentTarget](by-memory/0x005b05b0-0x005b05cf.TargetObjectWithKeyboardPaneClearCurrentTarget.md).
        - [UID:00036S][0x005b05b0-0x005b05cf.TargetObjectWithKeyboardPaneClearCurrentTarget](by-memory/0x005b05b0-0x005b05cf.TargetObjectWithKeyboardPaneClearCurrentTarget.md) 0x005b05b0-0x005b05cf | helper | TargetObjectWithKeyboardPaneClearCurrentTarget : reconstructable : 86% : strong : Existing exact split page documents modeled `sub_5B05B0`, keyboard/mouse calls, `s_targetObjectTargetId` lookup through active MapPane, highlight clear behavior, and TargetObject owner/source-module route.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b05cf-0x005b05d0 | padding | TargetObjectWithKeyboardPane clear-to-navigation alignment : ignored : 100% : strong : B014 PE/Capstone scan confirmed one `0xcc` byte after [UID:00036S] and before raw navigation start `0x005b05d0`.
        - [UID:00036U][0x005b06f0-0x005b077a.TargetObjectWithKeyboardPaneDispatchForwardHelper](by-memory/0x005b06f0-0x005b077a.TargetObjectWithKeyboardPaneDispatchForwardHelper.md) 0x005b06f0-0x005b077a | helper | TargetObjectWithKeyboardPaneDispatchForwardHelper : reconstructable : 86% : strong : Existing exact split page documents modeled `sub_5B06F0`, keyboard-handler calls at `0x005b00ce` and `0x005b00f4`, target-dispatch temporary map state setup, `byte_69BEDA`, `dword_69BF30`, event key rewrite to Tab, base forwarding, and TargetObject owner/source-module route.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b077a-0x005b0780 | padding | TargetObjectWithKeyboardPane suffix-to-SpellFourArgs alignment : ignored : 100% : strong : Existing [UID:00036U] docs record six `0xcc` alignment bytes before [UID:0001LM][0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor](by-memory/0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor.md).
```

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were made. If IDA work is later authorized:

| Address / symbol | Recommendation | Confidence | Notes |
| --- | --- | --- | --- |
| `0x005b05d0` | Create function and name `TargetObject_SelectPreviousTargetObject_Retained` or `TargetObjectWithKeyboardPane_SelectPreviousTargetObject`. Type `void __cdecl(void)` / no parameters. | Medium-high for behavior, medium for final spelling. | Add comment: no direct xrefs/pointer refs found; retained clone of TargetObject keyboard previous/up logic. |
| `0x005b0640` | Create function and name `TargetObject_SelectNextTargetObject_Retained` or `TargetObjectWithKeyboardPane_SelectNextTargetObject`. Type `void __cdecl(void)` / no parameters. | Medium-high for behavior, medium for final spelling. | Add comment: no direct xrefs/pointer refs found; retained clone of TargetObject keyboard next/down logic. |
| `0x005b06b0` | Create function and name `TargetObject_SelectLocalPlayerTargetObject_Retained` or `TargetObjectWithKeyboardPane_SelectLocalPlayerTargetObject`. Type `void __cdecl(void)` / no parameters. | Medium-high for behavior, medium for final spelling. | Add comment: no direct xrefs/pointer refs found; retained clone of TargetObject keyboard self-target logic. |
| `0x0069bf2c` | Use `s_targetObjectTargetId` / `s_targetObjectSavedTargetId` in comments or local type aliases. | Strong. | Keep historical `dword_69BF2C` searchable. |
| `0x00506970` | Comment/type as `MapPane::FindObjectPaneById`. | Strong descriptive. | Already supported by sibling docs. |
| `0x00506ae0` | Comment/type as `MapPane::FindPreviousSelectableObject`. | Strong descriptive. | Matches SelectObject accepted C++ and keyboard path. |
| `0x00506b30` | Comment/type as `MapPane::FindNextSelectableObject`. | Strong descriptive. | Matches SelectObject accepted C++ and keyboard path. |
| `0x0053b1b0` | Comment/type as `LivingObjectPane::SetTargetHighlight(bool)`. | Strong descriptive. | Flag `0` clears, flag `1` sets selected highlight. |

## Validation Commands Expected After Implementation

Run from `source-3/project-documentation`.

If only the current target/support docs are updated without split:

> Executable block R001 was removed from this report and preserved verbatim in [00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality-removed.md](00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If split children are created, additionally validate every created child and `by-memory/-ignored.md`:

> Executable block R002 was removed from this report and preserved verbatim in [00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality-removed.md](00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation result:

- No metadata dead-end for [UID:00036T] after `EMITTER_UIDS` is cleared.
- New child pages receive validator-assigned UIDs if split is executed.
- Generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` should no longer list [UID:00036T] as an emitting item if the aggregate is reclassified/cleared. If child emitters remain blank, they should appear as non-emitting/reconstructable research items, not formal source output.

## Final Recommendation

1. Prefer split implementation: create three child pages, mark current [UID:00036T] as a non-emitting container, add ignored padding rows, and update class/file/key-handler support docs with the exact behavior/negative-route evidence.
2. Do not emit first-draft C++ for the aggregate.
3. Do not emit first-draft C++ for the children until one of these conditions is met:
   - a direct call/pointer/vtable route to a raw start is recovered; or
   - the supervisor explicitly accepts a policy that retained unreferenced source-shaped helpers should be emitted as file-static/private-static functions for binary reconstruction.
4. Use source-facing names now in prose and future comments: `SelectPreviousTargetObject`, `SelectNextTargetObject`, `SelectLocalPlayerTargetObject`, `s_targetObjectTargetId`, `MapPane::FindObjectPaneById`, `MapPane::FindPreviousSelectableObject`, `MapPane::FindNextSelectableObject`, and `LivingObjectPane::SetTargetHighlight`.

## Follow-Up Actions

- Supervisor: review the split/no-code recommendation and decide whether to send an implementation callback for split child creation or a lower-risk target-page-only update.
- A-agent/future implementation: update `TargetObjectWithKeyboardPane`, `TargetSelectionInputPanes`, and keyboard-handler docs with the direct-route correction so future agents do not assume [UID:00036T] is active code.
- B014 future research: if assigned, perform the split and child documentation under a supervisor implementation callback; otherwise leave this report pending review.

## Confidence

- Recommendation confidence: strong for split/non-emitting aggregate; medium-high for child retained-helper disposition.
- Score confidence: strong for `88/89` parent container after evidence incorporation; strong for initial `85/88` children if created with this evidence.
- Remaining uncertainty: final original helper spellings and whether the original source declared these as file-static functions, private static class members, or dead retained helpers from an earlier refactor cannot be proven without debug symbols, a linker map, or a recovered source route.

## Validator Results

- No validators were run because this is report-only and no by-* files were edited.
- Evidence commands run:
  - `Get-Content` / `Select-String` over target/support docs and coverage reports.
  - Local PE/Capstone disassembly and reference scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - IDA MCP HTTP probe to `http://127.0.0.1:13337/mcp`, which failed to connect.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md`
- Modified: none outside the B014 research folder.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00036T"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00036T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
