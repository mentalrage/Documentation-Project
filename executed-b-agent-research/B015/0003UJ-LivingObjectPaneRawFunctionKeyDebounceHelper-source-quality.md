** TARGET-REPORT-UID:0003UJ **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003UJ **
# Agent-B015 Source-Quality Report: [UID:0003UJ] LivingObjectPaneRawFunctionKeyDebounceHelper

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality.md`

Target path: `source-3/project-documentation/by-memory/0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md`

Assignment: report-only B-agent source-quality pass. I did not edit by-* docs and did not edit `by-memory/-coverage-report.md`.

## Recommendation Summary

Keep [UID:0003UJ] as a reconstructable, source-shaped `LivingObjectPane` raw helper with direct owner/emitter [UID:00007B] `LivingObjectPane`, but do not populate formal reconstruction C++ yet.

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
```

Rationale for the modest score raise from `85/86` to `87/88`:

- The raw body is source-authored code, not compiler-generated glue: it has a normal `thiscall` body, two parameters, branch structure, `_isalpha` use, config-table lookup, and three calls to the command/spell slot dispatcher at `0x005a4530`.
- The body is still not live-routed in the current evidence: PE-aware scans found no external direct branch, no VA/RVA/raw-offset pointer value, and no start xref into `0x005a9250-0x005a930a`.
- The debounce global [UID:00030B] `g_lastFunctionKeyTick` is read only by this helper in the current scan. No direct writer/update site is known, so final source must not invent the write that would make the debounce lifecycle complete.
- The current target page has a boundary wording issue: `ret 8` starts at `0x005a9307` and consumes bytes through `0x005a9309`; true `int3` padding is `0x005a930a-0x005a9310`, not `0x005a9307-0x005a9310`.

Best source-facing role if this raw helper later becomes emitted C++:

```cpp
// Route-contingent draft only. Do not paste into the formal C++ block yet.
void LivingObjectPane::TryDispatchFunctionKeyShortcut(unsigned short functionKeyOrdinal,
                                                      unsigned int currentTick)
{
    if (currentTick >= g_lastFunctionKeyTick &&
        currentTick - g_lastFunctionKeyTick <= 100) {
        return;
    }

    const unsigned int rowOffset = functionKeyOrdinal == 0
        ? 9 * 0x100
        : (static_cast<unsigned int>(functionKeyOrdinal) - 1) * 0x100;

    const wchar_t configuredKey =
        g_pConfig->m_legacyShortcutInputSlots[rowOffset / sizeof(wchar_t)];

    unsigned char slot = 0xff;
    if (isalpha(static_cast<unsigned char>(configuredKey))) {
        if (configuredKey >= L'a' && configuredKey <= L'z') {
            slot = static_cast<unsigned char>(configuredKey - L'a' + 1);
        } else if (configuredKey >= L'A' && configuredKey <= L'Z') {
            slot = static_cast<unsigned char>(configuredKey - L'A' + 27);
        }
    }

    UseCommandSlotDispatch(slot);
}
```

This draft is behaviorally useful but intentionally not first-draft-formal ready. It still has unresolved live entry route, unresolved original helper name, unresolved exact function-key ordinal naming, and no proven `g_lastFunctionKeyTick` update site. If an implementation callback updates the target doc now, the formal C++ block should remain blank and the draft should appear only as a source-shape note.

## Evidence Checked

Target and support docs read:

- `by-memory/0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md`
- `by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md`
- `by-memory/0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md`
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- `by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md`
- `by-memory/0x005a3ae0-0x005a3d39.LivingObjectPaneExecuteHotkeyAction.md`
- `by-memory/0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper.md`
- `by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md`
- `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`
- `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md`
- `by-class/LivingObjectPane.md`
- `by-file/LivingObjectPane.md`
- `by-class/UserPane.md`
- `by-file/UserPane.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-global/g_pCollectionData.md`
- `by-type/by-struct/RegistryConfigUserProfileBlock.md`
- `by-type/by-struct/MacroHotkeyRecord.md`

Searches and binary checks performed:

- `rg -n "0003UJ|005a9250|LivingObjectPaneRawFunctionKeyDebounceHelper" by-memory/-coverage-report.md`
- `rg -n "69bf74|g_lastFunctionKeyTick|lastFunctionKey|function-key|FunctionKey|0x005a9250|5a9250|005a9250|0x005a9307|5A9250" source-3/project-documentation`
- `rg -n "28e89c|0x28e89c|function key|function-key|0x900" source-3/project-documentation/by-*`
- PE-aware Python scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for raw bytes, dword pointer hits into target range, exact absolute refs to `0x0069bf74`, and direct rel/short branch destinations.

Positive controls:

- The same branch scan found eight direct calls to `0x005a4530`: `0x005a3ab8`, `0x005a3bf2`, `0x005a3c28`, `0x005a3c4e`, `0x005a92c6`, `0x005a92eb`, `0x005a92ff`, and `0x005b62bd`.
- The scan found six direct calls to successor `0x005a9310`: `0x005a7c44`, `0x005a7c64`, `0x005a7c84`, `0x005abbdb`, `0x005abbfb`, and `0x005abc1b`.
- Exact VA scan found the predecessor `0x005a9240` as a data/vtable value at `0x0062ef88`.

Negative route evidence:

- Exact little-endian VA `0x005a9250`: zero hits in loaded sections.
- Exact little-endian VA `0x005a9307`: zero hits in loaded sections.
- Dword values into the corrected full body range `0x005a9250-0x005a930a`: zero hits.
- Direct rel/short branch destinations into the target full-body range: only the helper's own internal branches; no external branch source.
- Exact absolute refs to `0x0069bf74`: exactly two operand immediates, at `0x005a925a` and `0x005a9268`, corresponding to instructions at `0x005a9258` and `0x005a9266`. No direct write refs were found.

## Raw Body Findings

Corrected body and padding:

- Function-shaped bytes start at `0x005a9250`.
- The last instruction is `c2 08 00` / `ret 8` at `0x005a9307-0x005a9309`.
- The true alignment bytes before modeled successor `0x005a9310` are six `cc` bytes at `0x005a930a-0x005a930f`.
- Existing wording that treats `0x005a9307-0x005a9310` as padding is stale if the project is using half-open byte ranges. If the existing file name is kept, the page should still state that the final instruction begins at the filename end address.

Key disassembly:

```asm
005a9250  push ebp
005a9251  mov  ebp, esp
005a9253  mov  edx, [ebp+0xc]            ; currentTick
005a9258  sub  eax, [0x0069bf74]         ; g_lastFunctionKeyTick
005a9261  cmp  eax, 0x64
005a9264  ja   0x005a9272
005a9266  cmp  edx, [0x0069bf74]         ; wrap/lower-than-baseline allowance
005a926c  jae  0x005a9305                ; suppress dispatch
005a9272  mov  ax, [ebp+8]               ; function-key ordinal/sentinel
005a927b  mov  ecx, 0x900                ; ordinal 0 maps to tenth row
005a9282  movsx ecx, ax
005a9285  shl  ecx, 8
005a9288  sub  ecx, 0x100                ; ordinal n maps to (n - 1) * 0x100
005a928e  mov  eax, [0x0067a7c8]         ; g_pConfig, not g_pCollectionData
005a9294  movzx ebx, word [eax+ecx+0x28e89c]
005a92a0  call 0x005de870                ; _isalpha
005a92bb  sub  bl, 0x60                  ; lowercase a..z -> 1..26
005a92c6  call 0x005a4530
005a92e0  sub  bl, 0x26                  ; uppercase A..Z -> 27..52
005a92eb  call 0x005a4530
005a92f6  mov  byte [ebp+8], 0xff        ; invalid sentinel
005a92ff  call 0x005a4530
005a9307  ret  8
```

Behavior model:

- Parameter 1 (`[ebp+8]`) is a 16-bit function-key ordinal or sentinel. Nonzero values select row `(ordinal - 1) * 0x100`; zero selects row `9 * 0x100`. High-probability interpretation: F1..F9 pass `1..9`, and F10 or a tenth legacy key slot is encoded as `0`.
- Parameter 2 (`[ebp+0xc]`) is the current tick/time value compared against `g_lastFunctionKeyTick`.
- The helper suppresses dispatch if `currentTick >= g_lastFunctionKeyTick` and the unsigned delta is `<= 0x64` / decimal `100`.
- If `currentTick < g_lastFunctionKeyTick`, it treats the counter as wrapped or reset and allows dispatch.
- It reads a configured UTF-16 shortcut key from [UID:00028Q] `g_pConfig` at `+0x28e89c + rowOffset`.
- [UID:0001VR] `RegistryConfigUserProfileBlock` documents `+0x28e89c` as `10 * 0x100` bytes, `wchar_t[10][0x80]`, "legacy single-character shortcut/input slots." That is the right support type for this helper.
- It maps configured lowercase `a..z` to slot `1..26`, uppercase `A..Z` to slot `27..52`, and nonalphabetic or empty keys to `0xff`.
- It calls [UID:0003UC] `0x005a4530` / current provisional `UseCommandSlotDispatch` with that one-byte slot value.
- It does not write `g_lastFunctionKeyTick`. Do not synthesize an update in documentation or C++.

## Source Placement And Owner/Emitter

Recommended source placement remains `map/LivingObjectPane.cpp` through [UID:00007B] `LivingObjectPane`.

Evidence for `LivingObjectPane` route:

- The helper is `thiscall`-shaped: it preserves `ecx` in `edi` and restores it before all three calls to `0x005a4530`.
- Its only direct callee of semantic importance is [UID:0003UC] `0x005a4530`, the local-player command/spell slot dispatch helper currently routed through `LivingObjectPane`.
- It sits in the [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions` neighborhood, near movement/command/server packet helpers, with similar raw no-function starts documented for the local-player tail.
- [UID:00030B] `g_lastFunctionKeyTick` is already assigned to [UID:0000KU] `LivingObjectPane` as file-level legacy/orphan function-key command support.
- `UserPane::HandleKeyEvent` is the active keyboard dispatcher, but its documented hotkey/macro path calls [UID:0003UB] `0x005a3ae0`, not this helper. That makes `UserPane` a related caller-family context, not the owner of this raw body.

Rejected owner/source alternatives:

- Do not attach to [UID:0000FQ] `UserPane` or [UID:0000P1] `UserPane.cpp`: the current key handler has no call route to this helper, and the local-player command helper it calls belongs to `LivingObjectPane`.
- Do not attach to [UID:0001V1] `MacroHotkeyRecord`: this helper reads the legacy shortcut array at `g_pConfig + 0x28e89c`, while `MacroHotkeyRecord` is the later 30-row table at `g_pConfig + 0x28f2ec`.
- Do not attach to [UID:0000QK] `g_pCollectionData`: the raw instruction at `0x005a928e` loads `0x0067a7c8`, which is [UID:00028Q] `g_pConfig`; it does not load `0x0067a748`.
- Do not attach to the mixed [UID:0002A3] `KeyboardInputCommandStateGlobals` aggregate as an emitter: that page is a split map across unrelated globals. The exact [UID:00030B] child carries the data slot, while [UID:0003UJ] carries the code body.
- Do not mark as compiler-generated wrapper/thunk: the body contains application logic, CRT character classification, config lookup, and command dispatch.
- Do not force a no-owner/non-reconstructable status solely because the route is missing. The body is source-shaped and its best owner family is strong; the route absence should cap confidence and formal C++ readiness, not erase the source-family assignment.

## First-Draft C++ Readiness And No-Code Proof

Formal reconstruction C++ should remain blank for [UID:0003UJ] in the immediate implementation callback.

Target-specific no-code/defer proof:

- No current IDA function object exists at `0x005a9250`.
- No external entrypoint xref, branch destination, pointer table entry, VA/RVA/raw-offset value, or vtable route was found into `0x005a9250-0x005a930a`.
- The only branch destinations into the helper are internal control-flow edges produced by the helper itself.
- [UID:00030B] `g_lastFunctionKeyTick` has no known writer. The helper's name and intended runtime cadence imply a debounce update somewhere, but current evidence proves only reads. Formal C++ that updates `g_lastFunctionKeyTick` would be invented behavior.
- The first parameter's exact source spelling and caller-side encoding remain unknown. The `0 -> tenth row`, `1..9 -> rows 0..8` shape is strong enough to document, but not enough to freeze as an original source signature.
- The helper likely represents retained/orphan legacy function-key shortcut support, or a source-shaped function that was projected by older analysis but not live-routed in this build. Either way, emitting it as normal class C++ would overstate reachability.

Implementation policy:

- Keep the formal `RECONSTRUCTION_CPP` block empty.
- Add the route-contingent draft source shape in prose only, with explicit "do not emit until route/writer are proven" wording.
- If the project later adopts a formal retained-dead-helper policy, this target can emit a private helper with the candidate signature below, but the body still must not include a `g_lastFunctionKeyTick` write unless a writer is proven:

```cpp
void LivingObjectPane::TryDispatchFunctionKeyShortcut(unsigned short functionKeyOrdinal,
                                                      unsigned int currentTick);
```

## Open Questions With Attempted Resolution

1. Live entry route

   Evidence checked: exact VA refs to `0x005a9250`, dword values into `0x005a9250-0x005a930a`, direct rel/short branches into the helper, target start docs, [UID:0001KM], `UserPane::HandleKeyEvent`, and positive controls for `0x005a4530` and `0x005a9310`.

   Result: no live route found. Best inference is retained/orphan source-shaped `LivingObjectPane` helper, not an active `UserPane::HandleKeyEvent` callee.

2. `g_lastFunctionKeyTick` writer/provenance

   Evidence checked: exact absolute refs to `0x0069bf74` in the PE, [UID:00030B], [UID:0002A3], and workspace text refs.

   Result: exactly two direct operand refs, both reads inside this raw helper. No writer. The name remains a source-name lead and should stay annotated as lifecycle-incomplete.

3. Config/global name

   Evidence checked: raw instruction loads `0x0067a7c8`; [UID:00028Q] documents `g_pConfig`; [UID:0000QK] documents `g_pCollectionData` at `0x0067a748`.

   Result: the target and support docs should say `g_pConfig + 0x28e89c`, not `g_pCollectionData / g_pConfig`. `g_pCollectionData` is a rejected alternative for this exact lookup.

4. Legacy shortcut table type

   Evidence checked: [UID:0001VR] `RegistryConfigUserProfileBlock` layout.

   Result: source-quality support type is `wchar_t[10][0x80]` legacy single-character shortcut/input slots at `g_pConfig + 0x28e89c`. The helper reads only the first UTF-16 code unit of a selected row.

5. Function-key ordinal naming

   Evidence checked: raw row offset arithmetic and absence of callers.

   Result: use descriptive names like `functionKeyOrdinal`, `functionKeySlot`, or `functionKeyIndex` with caveat. The strongest behavioral inference is `1..9` select rows `0..8` and `0` selects row `9`; exact source spelling is not recoverable without a caller.

6. Boundary/padding

   Evidence checked: raw bytes and disassembly through `0x005a9310`.

   Result: target page padding note is stale. `0x005a9307` is the `ret 8` instruction start, not padding. True padding is `0x005a930a-0x005a9310`.

## Exact Recommended Target Doc Changes

File: `source-3/project-documentation/by-memory/0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md`

1. Update metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Replace status/open-question wording that says only "not final-C++ ready" with:

```text
Disposition: source-shaped retained/orphan `LivingObjectPane` helper. The body is reconstructable as behavior, but formal C++ remains blank because no live entry route and no `g_lastFunctionKeyTick` update site are proven.
```

3. Add corrected boundary text:

```text
Raw byte review shows the body starts at `0x005a9250` and the final `ret 8` instruction starts at `0x005a9307` (`c2 08 00`, bytes through `0x005a9309`). True `int3` alignment before [UID:0003UK] `0x005a9310` is `0x005a930a-0x005a9310`. The existing filename uses the ret-start address; do not describe `0x005a9307-0x005a9310` as padding.
```

4. Add behavior details:

```text
The helper accepts `this`, a 16-bit function-key ordinal/sentinel at `[ebp+8]`, and a current tick value at `[ebp+0xc]`. It suppresses dispatch when `currentTick >= g_lastFunctionKeyTick` and the unsigned delta is `<= 0x64` / decimal `100`; if `currentTick < g_lastFunctionKeyTick`, it treats the tick value as wrapped/reset and dispatches. Nonzero ordinals select `(ordinal - 1) * 0x100` in the legacy shortcut table; ordinal `0` selects `0x900`, the tenth row. It reads [UID:00028Q] `g_pConfig + 0x28e89c`, the [UID:0001VR] `wchar_t[10][0x80]` legacy single-character shortcut/input slot array, maps lowercase `a..z` to command slots `1..26`, uppercase `A..Z` to `27..52`, and passes `0xff` when the configured key is nonalphabetic or empty. All dispatch paths call [UID:0003UC] `0x005a4530`.
```

5. Add no-route evidence:

```text
B015 PE-aware route scan found no external direct branch, VA/RVA/raw-offset pointer value, or loaded-section dword value into corrected body range `0x005a9250-0x005a930a`. Direct branch hits into the range are only internal helper branches. Positive controls found eight direct calls to `0x005a4530`, six direct calls to successor `0x005a9310`, and the predecessor `0x005a9240` vtable/data value at `0x0062ef88`.
```

6. Add debounce-global evidence:

```text
The only exact `0x0069bf74` operand refs in the PE are the two reads in this helper: instruction `0x005a9258` (`sub eax, [0x0069bf74]`) and instruction `0x005a9266` (`cmp edx, [0x0069bf74]`). No writer was found; do not invent `g_lastFunctionKeyTick = currentTick` in final source.
```

7. Replace stale global wording:

```text
Use [UID:00028Q] `g_pConfig`, not [UID:0000QK] `g_pCollectionData`, for the `0x005a928e` load. [UID:0000QK] is a separate local-player/client-state pointer at `0x0067a748` and is not touched by this helper.
```

8. Add source-shape policy:

```text
Best source-facing candidate, if a future route is proven: `void LivingObjectPane::TryDispatchFunctionKeyShortcut(unsigned short functionKeyOrdinal, unsigned int currentTick)`. Do not place this candidate in the formal C++ block yet; keep it as route-contingent prose until a live caller and tick update lifecycle are known.
```

## Exact Support Doc Updates

File: `by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md`

- Replace "through [UID:0000QK] `g_pCollectionData` / `g_pConfig + 0x28e89c`" with:

```text
through [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) at `g_pConfig + 0x28e89c`, the [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) legacy `wchar_t[10][0x80]` single-character shortcut/input slot array.
```

- Add corrected boundary:

```text
B015 raw PE review corrects the helper boundary wording: the final `ret 8` instruction starts at `0x005a9307` and ends at `0x005a930a`; only `0x005a930a-0x005a9310` is `0xcc` padding.
```

- Keep the no-writer caveat and add:

```text
B015 exact operand scan found only two direct `0x0069bf74` refs in the PE, both read operands inside the raw helper. No direct write/update encoding was found.
```

File: `by-memory/0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md`

- Update the `0x0069bf74-0x0069bf78` row to use [UID:00028Q] `g_pConfig + 0x28e89c`, not `g_pCollectionData`.
- Replace broad stale value wording if this page is touched. Current exact [UID:00030B] says the active value is zero-filled and the older `0xffffffff` sample is superseded; the aggregate page still says "All four dwords are sampled as `0xffffffff`." Do not change the unrelated sibling dwords without rechecking them, but remove or narrow any statement that contradicts [UID:00030B].

File: `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`

- Add [UID:0003UJ] to child/cross-reference lists.
- Add or update the raw helper row:

```text
| `0x005a9250-0x005a930a` | `LivingObjectPaneRawFunctionKeyDebounceHelper` | Raw source-shaped retained/no-live-route function-key shortcut helper; reads `g_lastFunctionKeyTick`, indexes `g_pConfig + 0x28e89c`, maps configured alphabetic keys to command slots, and calls `0x005a4530`. Final `ret 8` starts at `0x005a9307`; padding is `0x005a930a-0x005a9310`. |
```

File: `by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md`

- Refine raw caller wording:

```text
[UID:0003UJ] `0x005a9250` has three raw internal calls to this helper (`0x005a92c6`, `0x005a92eb`, `0x005a92ff`) after mapping a legacy configured function-key shortcut to slot `1..52` or `0xff`. The raw helper has no proven live entry route, so it is caller evidence for shared source-family behavior, not proof of active dispatch reachability.
```

File: `by-class/LivingObjectPane.md`

- Under boundary caveats/local-player tail notes, replace passive "projected helper start" language for `0x005a9250` with:

```text
[UID:0003UJ] `0x005a9250` is a source-shaped retained/orphan function-key shortcut helper in the local-player tail. B015 raw PE recheck found no live route into the helper and no writer for [UID:00030B] `g_lastFunctionKeyTick`, but the body is `thiscall`-shaped, reads [UID:00028Q] `g_pConfig + 0x28e89c`, maps configured alphabetic keys to command slots, and calls the `LivingObjectPane` command/spell slot dispatcher at `0x005a4530`. Keep owner/emitter on `LivingObjectPane`, with formal C++ deferred.
```

File: `by-file/LivingObjectPane.md`

- Update the `legacy function-key debounce state` proposed contents row:

```text
| legacy function-key shortcut/debounce support | [UID:00030B][0x0069bf74-0x0069bf78.g_lastFunctionKeyTick](by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md), [UID:0003UJ][0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper](by-memory/0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md) | File-level legacy/orphan function-key command support. B015 found no live entry route into the raw helper and no writer for the debounce tick, but the helper is source-shaped LivingObjectPane code: it reads `g_pConfig + 0x28e89c`, maps configured alphabetic shortcuts to slots `1..52` or `0xff`, and dispatches through `0x005a4530`. |
```

File: `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

- Optional low-risk support addition under Known Field Clusters:

```text
| `+0x28e89c` | Legacy `wchar_t[10][0x80]` single-character shortcut/input slots. [UID:0003UJ] reads the first code unit of one selected row when attempting legacy function-key command dispatch. |
```

File: `by-type/by-struct/RegistryConfigUserProfileBlock.md`

- No structural change required. The existing `+0x28e89c` row is already the best support type. Add [UID:0003UJ] as a consumer if implementing support cross-links.

## Coverage Report Text For Supervisor

`by-memory/-coverage-report.md` currently does not contain a direct [UID:0003UJ] row. Add this child row under [UID:0001KM] after the [UID:0003VB] row and before later tail helpers:

```text
        - [UID:0003UJ][0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper](by-memory/0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md) 0x005a9250-0x005a930a | raw retained/no-live-route function-key helper | LivingObjectPaneRawFunctionKeyDebounceHelper : reconstructable : 87% : strong : Source-shaped `LivingObjectPane` thiscall helper with no current IDA function object, no external rel32/VA/RVA/pointer route into the body, and no known caller; B015 PE scan found only internal branch targets into `0x005a9250-0x005a930a`, positive controls for `0x005a4530` and `0x005a9310`, and true padding only at `0x005a930a-0x005a9310` after the `ret 8` at `0x005a9307`. The helper reads [UID:00030B] `g_lastFunctionKeyTick` at `0x005a9258`/`0x005a9266`, suppresses dispatch for non-wrapped deltas `<= 0x64`, reads [UID:00028Q] `g_pConfig + 0x28e89c` legacy shortcut slots, maps lowercase/uppercase alphabetic keys to command slots `1..52`, passes `0xff` for invalid keys, and calls [UID:0003UC] `0x005a4530`; owner/emitter remain [UID:00007B], but formal C++ stays blank/deferred until a live entry route and tick writer/update site are proven.
```

If the supervisor wants the parent row refreshed at the same time, use this replacement for the existing [UID:0001KM] parent row:

```text
    - [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad441 | mixed source-family split index | LivingObjectPaneLocalPlayerExtensions : ignored : 88% : strong : Non-emitting split index for the local-player movement/command/server-packet neighborhood; exact children carry LivingObjectPane/UserPane/SayInputPanes/Chatting/Quit/SelfSave ownership, while raw retained/no-live-route helpers such as [UID:0003UJ] `0x005a9250` are documented as source-shaped candidates with explicit no-route/no-formal-C++ policy rather than hidden blockers.
```

## IDA Rename, Type, And Comment Recommendations

Do not make IDA edits from this B-agent report unless a supervisor implementation callback explicitly asks for them.

If IDA modeling is allowed later:

- Consider creating a function at `0x005a9250` only if the team's raw-helper policy allows no-xref source-shaped bodies to be modeled. Use:

```text
LivingObjectPane_TryDispatchFunctionKeyShortcut
void __thiscall LivingObjectPane_TryDispatchFunctionKeyShortcut(LivingObjectPane *this, unsigned short functionKeyOrdinal, unsigned int currentTick)
```

- Add a comment at `0x005a9258` / `0x005a9266`:

```text
Reads g_lastFunctionKeyTick; no writer found in current PE scan. Do not synthesize debounce update.
```

- Add a comment at `0x005a928e`:

```text
Loads g_pConfig (0x0067a7c8), not g_pCollectionData. Uses RegistryConfig legacy shortcut/input slots at +0x28e89c.
```

- Add a comment at `0x005a9294`:

```text
functionKeyOrdinal selects rows: 1..9 -> rows 0..8, 0 -> row 9; reads first UTF-16 code unit.
```

- Add comments at the three `0x005a4530` calls:

```text
Dispatch mapped command/spell shortcut slot; 1..52 for alphabetic key, 0xff sentinel for invalid/nonalphabetic configured key.
```

- Keep `sub_5A4530` naming provisional unless a separate source-quality pass finalizes it. Existing `UseCommandSlotDispatch` is serviceable but still coupled to spell/item slot naming.
- Do not rename `0x0067a748` / [UID:0000QK] `g_pCollectionData` for this helper; it is not touched here.
- Do not add a write xref or variable assignment for `g_lastFunctionKeyTick`.

## Implementation Checklist For Later Callback

1. Edit `by-memory/0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md`:
   - Raise metadata to `87/88`.
   - Keep owner/emitter [UID:00007B].
   - Keep formal C++ blank.
   - Add corrected boundary/padding details.
   - Add full behavior model and raw route evidence.
   - Replace any `g_pCollectionData` reference with [UID:00028Q] `g_pConfig` for the `0x0067a7c8` load.
   - Add route-contingent candidate signature only as prose.

2. Edit support docs:
   - `by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md`
   - `by-memory/0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md`
   - `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
   - `by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md`
   - `by-class/LivingObjectPane.md`
   - `by-file/LivingObjectPane.md`
   - Optional: `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
   - Optional cross-link only: `by-type/by-struct/RegistryConfigUserProfileBlock.md`

3. Do not edit `by-memory/-coverage-report.md`; supervisor should apply the exact pending row above.

4. Run validators from `source-3/project-documentation` for each edited file:

> Executable block R001 was removed from this report and preserved verbatim in [0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality-removed.md](0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

5. If the supervisor applies the coverage row, validate:

> Executable block R002 was removed from this report and preserved verbatim in [0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality-removed.md](0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Final State

This report resolves the key heuristic questions enough for implementation:

- Best source route: `LivingObjectPane.cpp`, direct class owner [UID:00007B].
- Best source-facing helper name: `TryDispatchFunctionKeyShortcut` or `TryDispatchFunctionKeyCommand`; use as candidate only.
- Best signature: `void __thiscall LivingObjectPane::TryDispatchFunctionKeyShortcut(unsigned short functionKeyOrdinal, unsigned int currentTick)`.
- Correct config/global dependency: [UID:00028Q] `g_pConfig + 0x28e89c`; reject `g_pCollectionData` for this lookup.
- Correct legacy shortcut type: [UID:0001VR] `wchar_t[10][0x80]` legacy single-character shortcut/input slots.
- Correct byte boundary: body through `ret 8` at `0x005a9307-0x005a9309`; padding `0x005a930a-0x005a9310`.
- No-route proof: no external branch/pointer route into `0x005a9250-0x005a930a`; only internal branches.
- No-writer proof: exact `0x0069bf74` refs are the two reads in this helper; no direct writer found.
- Formal C++ policy: defer/blank. Include draft source shape only as a route-contingent note.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UJ","source_path":"executed-b-agent-research/B015/0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
