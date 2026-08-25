** TARGET-REPORT-UID:0003UA **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003UA **
# 0003UA LivingObjectPaneRawConfigHotkeyHelper Source-Quality Report

Status: FINISHED

## Current Recommendation

- Target: [UID:0003UA] `source-3/project-documentation/by-memory/0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper.md`
- Report: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality.md`
- Disposition: keep as `RECONSTRUCTABLE:TRUE`, keep canonical owner [UID:00007B] `LivingObjectPane`, keep emitter [UID:00007B], and keep source placement through [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
- Score recommendation after implementation: `COMPLETION:87`, `CONFIDENCE:88`.
- C++ recommendation: populate a first-draft retained-helper body in the target page, with explicit prose that this is source-authored/retained or unmodeled code and has no proven live entry route. Do not wire it into any live caller unless a later route is proven.
- Best source-facing name: `LivingObjectPane::DispatchConfiguredShortcutHotkey` or `LivingObjectPane::DispatchCompactShortcutHotkey`. Use the first in prose/C++ unless the supervisor wants the filename to keep the current raw name.
- Best source-facing signature: `void LivingObjectPane::DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused)`. The first argument is proven as a signed 16-bit selector; the second stack argument is not read and is likely a callback/signature residue. Keep the second parameter named `unused` until a caller is recovered.
- Exact route finding: no direct rel32, absolute VA, or RVA references to `0x005a3a20` or `0x005a3ad4` were found in the PE scan. The same scan finds positive-control calls into this raw body's callees, so the negative route result is meaningful.
- Source-quality conclusion: behavior, owner, source placement, compact-record layout, helper roles, and boundary/padding are now resolved well enough for retained-helper first-draft C++. Entrypoint provenance remains unresolved after concrete scans; it caps confidence and must be documented, but it no longer justifies vague "not final-C++ ready" wording.

## Evidence Checked

### Governing / Process Evidence

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - Rule 20: active C++ gate is `RECONSTRUCTABLE:TRUE`, nonblank valid emitter, and average score greater than 85, subject to source-quality evidence.
  - Rules 21, 24, 25, 26, and 27: source-quality issues, raw-route issues, names, fields, ranges, and final-C++ blockers must be investigated and either resolved or capped with concrete evidence.
  - Rule 30/31 assignment context: B-agent report-only work first; no `by-memory/-coverage-report.md` edits.
- `.codex/AGENTS.md` and `Agent-B013/goal.md`: report-only B-agent pass; do not edit by-* docs or shared coverage during the research pass; include exact implementation instructions and coverage text.
- Target page currently says `85/86`, owner/emitter [UID:00007B], reconstructable true, formal C++ blank, and open questions around route, name/signature, and final C++.

### Target And Support Docs

- [UID:0003UA] target page: current raw no-function/no-xref summary, calls to `0x005a4530` and [UID:0001KN], and padding `0x005a3ad4-0x005a3ae0`.
- [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`: non-emitting split index for the local-player mixed source neighborhood, exact child inventory, raw projected start caveats, and macro/hotkey context.
- [UID:0003UB] `LivingObjectPaneExecuteHotkeyAction`: live modeled macro/hotkey executor, caller from `UserPane::OnKeyEvent`, and dispatch to `0x005a4530` / `0x005a3e30`.
- [UID:0001KN] `UseInventorySlotDispatch`: exact inventory/item slot dispatcher at `0x005a3e30-0x005a3ff3`, item-use behavior, `ItemWhoInputPane` target path, and direct callers.
- [UID:0003UC] `LivingObjectPaneUseCommandSlotDispatch`: exact command/spell slot dispatcher at `0x005a4530-0x005a4908`, current name caveat, spell-command state usage, and direct callers including raw `0x005a3a20`.
- [UID:00007B] `LivingObjectPane` and [UID:0000KU] `LivingObjectPane` file page: class/file ownership, raw local-player helper policy, local-player command/packet helper family, stale generated-name warnings, and separation from `UserPane`.
- [UID:00028Q] `g_pConfig`: confirms `0x0067a7c8` as process-global configuration pointer and records known profile/macro/shortcut offset clusters.
- [UID:0001VR] `RegistryConfigUserProfileBlock`: confirms `+0x28e89c` legacy shortcut text, `+0x28f29c` compact shortcut records, and `+0x28f2ec` macro/hotkey records. This is the key support doc for this target's compact-record fields.
- [UID:0001V1] `MacroHotkeyRecord`: confirms the separate 30-row integrated macro table used by `0x005a3ae0`; this report rejects treating `0x005a3a20` as another 0x108-stride macro-row reader.
- [UID:0003UJ] `LivingObjectPaneRawFunctionKeyDebounceHelper` and [UID:00030B] `g_lastFunctionKeyTick`: related raw function-key helper and legacy shortcut support, used only as a comparison for retained/no-route LivingObjectPane command helpers.
- [UID:0001MQ] `SpellSpellInputPaneAccept`: source precedent for single-character `a-z` / `A-Z` slot mapping and current descriptive `UseCommandSlot` call.
- `by-memory/-ignored.md`: already records `0x005a3ad4-0x005a3ae0` as `0xcc` alignment after [UID:0003UA].
- B001 prior reports:
  - `0001KM-livingobject-localplayer-source-split-audit.md`: created the raw child recommendation and proved initial no-function/no-xref status.
  - `00007B-LivingObjectPane-class-source-quality.md`: fresh route table, zero-route raw starts, positive controls, and source-facing name suggestion `DispatchConfiguredHotkeySlotRaw`.

### Fresh PE / Binary Evidence

PE scanned:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5 4247e04e20b65d6414c7238aa8ff5515
Image base 0x00400000
.text 0x00401000-0x0060c600, raw 0x000400, size 0x20b600
.rdata 0x0060d000-0x0066c200
.data 0x0066d000-0x0069ce24
```

Route scan results:

| Target | rel32 refs | absolute VA refs | RVA refs | Interpretation |
| --- | ---: | ---: | ---: | --- |
| `0x005a3a20` | 0 | 0 | 0 | No direct route to raw helper start. |
| `0x005a3ad4` | 0 | 0 | 0 | No route to helper end/alignment start. |
| `0x005a3ae0` | 1 | 0 | 0 | Positive control: modeled `ExecuteHotkeyAction` called at `0x005a5ce5`. |
| `0x005a3e30` | 8 | 0 | 0 | Positive control: calls at `0x004eab81`, `0x004ed711`, `0x004ed7fc`, `0x004ef0e1`, `0x005070c1`, `0x005a3ac6`, `0x005a3ba1`, and `0x005b5e51`. |
| `0x005a4530` | 8 | 0 | 0 | Positive control: calls at `0x005a3ab8`, `0x005a3bf2`, `0x005a3c28`, `0x005a3c4e`, `0x005a92c6`, `0x005a92eb`, `0x005a92ff`, and `0x005b62bd`. |
| `0x005a9250` | 0 | 0 | 0 | Related raw function-key debounce helper also has no direct route. |
| `0x005b6260` | 0 | 1 | 0 | Positive control for vtable/data route class; absolute VA at `0x00630464` is the `SpellSpellInputPane::OnAccept` vtable slot. |

Boundary/padding bytes:

```text
0x005a3a10-0x005a3a1f: previous epilogue then cc fill
0x005a3a20: 55 8b ec 51 ... function-shaped prologue
0x005a3ad0-0x005a3ad3: 5d c2 08 00
0x005a3ad4-0x005a3adf: cc cc cc cc cc cc cc cc cc cc cc cc
0x005a3ae0: 55 8b ec 81 ec 34 02 00 ...
```

Disassembly summary:

```asm
005a3a20  push ebp
005a3a21  mov  ebp, esp
005a3a23  push ecx
005a3a24  movsx eax, word ptr [ebp+8]        ; hotkey selector
...
005a3a2d  test eax, eax
005a3a31  lea  edx, [eax+0x24]
005a3a34  mov  esi, 0x28f2c0                 ; selector 0 -> compact record 9
...
005a3a3b  cmp  eax, 0xa
005a3a40  lea  edx, [eax+0x42]
005a3a43  mov  esi, 0x28f2e8                 ; selector 10 -> compact record 19
...
005a3a4a  lea  edx, [eax*4-4]
005a3a51  lea  esi, [eax*4+0x28f298]         ; otherwise selector-1
005a3a58  mov  eax, dword ptr [0x67a7c8]     ; g_pConfig
005a3a5d  movzx ebx, word ptr [esi+eax]      ; compactShortcutRecords[index].key
005a3a61  mov  al, byte ptr [edx+eax+0x28f29e] ; compactShortcutRecords[index].mode
005a3a6f  call 0x5de870                      ; isalpha/narrow classification
...
005a3a8a  sub  bl, 0x60                      ; a-z -> 1-26
005a3aa1  sub  bl, 0x26                      ; A-Z -> 27-52
005a3aa9  mov  byte ptr [ebp-4], 0xff        ; fallback slot
005a3aad  cmp  byte ptr [ebp+0xb], 0         ; saved mode byte
005a3ab8  call 0x5a4530                      ; nonzero mode -> command/spell-slot dispatch
005a3ac6  call 0x5a3e30                      ; zero mode -> inventory/item-slot dispatch
005a3ad1  ret 8
```

## Behavior And Source Shape

This helper dispatches the compact shortcut records in [UID:0001VR] at `g_pConfig + 0x28f29c`. It is separate from [UID:0003UB] `ExecuteHotkeyAction`, which dispatches the integrated 30-row [UID:0001V1] `MacroHotkeyRecord` table at `g_pConfig + 0x28f2ec`.

Resolved behavior:

- The first parameter is a 16-bit hotkey selector.
- The selector maps to one of 20 compact shortcut records:
  - selector `0` maps to compact record index `9`;
  - selectors `1..9` map to indexes `0..8`;
  - selector `10` maps to compact record index `19`;
  - selectors `11..19` map to indexes `10..18`;
  - no internal range check exists, so source callers were expected to pass only the supported key range.
- The compact record is `4` bytes at `g_pConfig + 0x28f29c + index * 4`.
- Record `+0` is a UTF-16/narrow ASCII-compatible key code; the body uses the low byte and calls the runtime alpha classifier at `0x005de870`.
- Record `+2` is the mode byte. Current profile docs say compact writer emits mode `S` when this byte is nonzero and `I` otherwise. Runtime behavior matches that:
  - mode byte nonzero calls [UID:0003UC] `0x005a4530` (`UseCommandSlotDispatch` / spell-command slot path);
  - mode byte zero calls [UID:0001KN] `0x005a3e30` (`UseInventorySlotDispatch` / inventory-item path).
- The stored key is mapped like other slot-entry paths:
  - `'a'..'z'` -> `1..26`;
  - `'A'..'Z'` -> `27..52`;
  - if `isalpha` is false, the helper returns without dispatch;
  - if `isalpha` is true but not in the ASCII ranges, it dispatches slot `0xff`; in the shipped C locale this is unlikely except for extended classifications.
- The second stack argument is not read. Because the function returns with `retn 8`, preserve it as an unknown/unused callback argument rather than pretending it is absent.

Best source shape:

```cpp
struct CompactShortcutRecord
{
    wchar_t key;
    unsigned char mode;
    unsigned char reserved;
};
```

This type name is descriptive and belongs in the `RegistryConfigUserProfileBlock` / config profile-layout docs, not as a `LivingObjectPane` member. `LivingObjectPane` is only the runtime consumer.

## Heuristic / Inference Reanalysis And Validation

### 1. Entrypoint / Caller Provenance

Finding: unresolved after concrete negative scans, but not a generic blocker.

Evidence checked:

- Current target page and B001 split audit both reported no IDA function object and no xrefs to start.
- Fresh local PE scan found zero rel32 branches, absolute VA dwords, or RVA dwords to `0x005a3a20`.
- The same scan found direct calls into this raw body's callees (`0x005a4530` and `0x005a3e30`) and into modeled successor `0x005a3ae0`, so the route scanner is not blind.
- `by-memory/-ignored.md` already records post-body alignment, confirming this is not an accidental mid-function decode into the modeled successor.
- No vtable/data pointer route like `0x005b6260` was found.

Rejected alternatives:

- "Missed ordinary direct caller": rejected by rel32 scan over `.text`.
- "Missed pointer table in `.rdata`/`.data`": no absolute VA/RVA hits were found.
- "Part of `0x005a3ae0`": rejected by `0xcc` alignment and separate prologue at `0x005a3ae0`.
- "Compiler switch case inside previous function": rejected by previous epilogue ending at `0x005a3a11` and `0xcc` fill before `0x005a3a20`.

Remaining uncertainty:

- An indirect route through encoded/computed data not present as a plain VA/RVA remains theoretically possible, but no evidence currently supports it.
- A retained out-of-line helper with no live route is plausible in a mid-2000s MSVC codebase when a whole object file is linked and function-level dead stripping does not remove every unreferenced function.

Impact:

- No-route status caps confidence and must be preserved in the target doc.
- No-route status should not force `CANONICAL_OWNER:NONE` or `RECONSTRUCTABLE:FALSE`, because the body is source-shaped, uniquely bounded, and semantically tied to resolved LivingObjectPane dispatch helpers.
- First-draft C++ is acceptable only as a retained helper, not as an active method called from `UserPane::OnKeyEvent` or `ExecuteHotkeyAction`.

### 2. Source-Facing Name / Signature

Accepted best name: `LivingObjectPane::DispatchConfiguredShortcutHotkey`.

Evidence:

- The helper consumes `RegistryConfigUserProfileBlock::m_compactShortcutRecords`, not the integrated macro row table.
- It dispatches a configured shortcut into the same slot helpers used by hotkey/action paths.
- It does not implement text macro packet sending; therefore `ExecuteHotkeyAction` is too broad and belongs to [UID:0003UB].
- It is not a pure "function-key debounce" helper; that role belongs to [UID:0003UJ].

Rejected names:

- `ExecuteConfigHotkey`: too close to [UID:0003UB] and does not distinguish compact shortcut records.
- `UseCommandSlot`: too narrow; the helper conditionally calls both command/spell and inventory/item dispatchers.
- `UseSpellSlot`: rejected for the same reason and because current docs already warn that generated spell/item names are misleading.
- `SpellManager::*` / `g_pSpellMan`: rejected. [UID:0001MQ] and [UID:0001OR] show these are generated-output aliases for the broader local-player/UserPane state and command dispatch, not a standalone spell manager.
- `RegistryConfig::*`: rejected for this executable helper. `RegistryConfig` owns the compact records, but the runtime receiver and dispatch behavior are LivingObjectPane/local-player command behavior.

Signature:

- `void __thiscall LivingObjectPane::DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused)`.
- The `this` pointer is forwarded to `0x005a4530` / `0x005a3e30` through `ecx`.
- First parameter is proven by `movsx eax, word ptr [ebp+8]`.
- `retn 8` proves two stack arguments, but the second is not referenced.

### 3. Field / Type / Global Names

Resolved names for target docs:

| Raw evidence | Source-facing name | Confidence | Owner |
| --- | --- | ---: | --- |
| `dword_67A7C8` | `g_pConfig` | High | [UID:00028Q] / Config |
| `g_pConfig + 0x28f29c` | `m_compactShortcutRecords[20]` | High for role, medium for exact spelling | [UID:0001VR] / RegistryConfig user profile block |
| record `+0` | `key` / `shortcutKey` (`wchar_t`) | High | Compact shortcut record |
| record `+2` | `mode` / `spellMode` | Medium-high | Compact shortcut record |
| `0x005de870` | narrow `isalpha` helper | High for role, low for exact CRT import spelling | CRT/runtime |
| `0x005a4530` | `UseCommandSlotDispatch` / `UseSpellCommandSlotDispatch` | Medium-high | [UID:0003UC] / LivingObjectPane |
| `0x005a3e30` | `UseInventorySlotDispatch` | High | [UID:0001KN] / LivingObjectPane |

Important distinction:

- `m_compactShortcutRecords` at `+0x28f29c` are 20 compact four-byte records and are the target's source data.
- `MacroHotkeyRecord` rows at `+0x28f2ec` are 30 rows of `0x108` bytes and are [UID:0003UB]'s source data.
- Legacy shortcut text at `+0x28e89c` is consumed by the related [UID:0003UJ] raw function-key debounce helper, not this target.

### 4. Owner / Emitter / Source File Route

Accepted route:

- Target owner: [UID:00007B] `LivingObjectPane`
- Target emitter: [UID:00007B]
- Source file: [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`

Evidence:

- Receiver `ecx` is preserved in `edi` and passed as `ecx` to both LivingObjectPane dispatch helpers.
- Callees are [UID:0003UC] and [UID:0001KN], both already attached to [UID:00007B].
- The helper is physically inside [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`, immediately before the modeled [UID:0003UB] hotkey executor.
- [UID:0000KU] explicitly owns the local command/spell slot dispatch family and warns that compact/raw helper names are provisional but LivingObjectPane-local.

Rejected owner alternatives:

- `RegistryConfig`: owns the compact shortcut records, but not this runtime dispatch method.
- `ProfileStorage`: imports/saves the compact records, but is not the live key/action dispatcher.
- `MacroDialogs`: edits hotkey data, but this helper is runtime dispatch and has no UI editor behavior.
- `UserPane`: owns the active key-event dispatcher and local player object lifetime, but this helper forwards to LivingObjectPane local action dispatch and is documented in the LivingObjectPane source family.
- `SpellInputPanes`: [UID:0001MQ] calls `0x005a4530` through a vtable-routed input pane, but this target consumes config shortcuts rather than input-pane text.

### 5. Range / Split / Merge

Recommendation: keep the target as an exact child `0x005a3a20-0x005a3ad4`; do not merge into [UID:0003UB] or [UID:0001KM].

Evidence:

- The body starts after previous function epilogue/padding at `0x005a3a20`.
- It ends at `0x005a3ad4` with `retn 8`; following bytes `0x005a3ad4-0x005a3ae0` are `0xcc` alignment.
- The successor [UID:0003UB] starts at `0x005a3ae0` with its own prologue and modeled IDA function.
- The parent [UID:0001KM] is a non-emitting mixed split index; it should not absorb exact children.

Rejected split alternatives:

- Split the calls to `0x005a4530` and `0x005a3e30` into children: rejected. They are branches inside one short helper and do not form independent source functions.
- Merge with [UID:0003UJ] function-key debounce helper: rejected. That helper reads `g_lastFunctionKeyTick` and legacy shortcut text at `+0x28e89c`; this helper reads compact records at `+0x28f29c`.

## First-Draft C++ Recommendation

Insert the following into [UID:0003UA] if the supervisor accepts retained-helper emission. The body is intentionally source-style rather than decompiler-shaped, but it preserves the no-bound-check and two-argument signature evidence.

```cpp
void LivingObjectPane::DispatchConfiguredShortcutHotkey(short hotkeyNumber, int /*unused*/)
{
    int shortcutIndex;
    if (hotkeyNumber == 0) {
        shortcutIndex = 9;
    } else if (hotkeyNumber == 10) {
        shortcutIndex = 19;
    } else {
        shortcutIndex = hotkeyNumber - 1;
    }

    const CompactShortcutRecord& shortcut =
        g_pConfig->m_userProfile.m_compactShortcutRecords[shortcutIndex];

    const wchar_t configuredKey = shortcut.key;
    if (!isalpha(static_cast<unsigned char>(configuredKey))) {
        return;
    }

    unsigned char slot = 0xff;
    if (configuredKey >= L'a' && configuredKey <= L'z') {
        slot = static_cast<unsigned char>(configuredKey - L'a' + 1);
    } else if (configuredKey >= L'A' && configuredKey <= L'Z') {
        slot = static_cast<unsigned char>(configuredKey - L'A' + 27);
    }

    if (shortcut.mode != 0) {
        UseCommandSlotDispatch(slot);
    } else {
        UseInventorySlotDispatch(slot);
    }
}
```

C++ notes to include with the target:

- `CompactShortcutRecord`, `m_userProfile`, `m_compactShortcutRecords`, `UseCommandSlotDispatch`, and `UseInventorySlotDispatch` are descriptive source-facing names. Exact original spellings remain open.
- The draft intentionally does not add a range check for `hotkeyNumber`. The binary has no range check; caller contract should supply `0..19`.
- The draft intentionally keeps the unused second parameter because the binary uses `retn 8`.
- The draft should be described as retained/unmodeled source. Do not add a call from [UID:0003UB] or `UserPane::OnKeyEvent` unless later evidence proves that call.

If the supervisor chooses to keep formal C++ blank despite the draft, the target-specific no-code proof is:

```text
Keep RECONSTRUCTION_CPP blank only if the project policy forbids emitting no-route retained helpers. The behavior, fields, and owner are resolved, but direct rel32/VA/RVA route scans found no entrypoint into 0x005a3a20. Without an approved retained-helper policy, emitting this as an ordinary live method would overstate reachability. This is a policy blocker, not an unresolved behavior/name blocker.
```

My recommendation is to emit the draft with the retained-helper caveat because the active gate is met and the body is source-authored, exact, and semantically resolved.

## Score / Metadata Recommendation

Current target state:

```text
COMPLETION:85
CONFIDENCE:86
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
formal C++ blank
```

Recommended after implementation:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:00007B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007B
```

Rationale:

- Completion should rise because the report resolves the compact-record layout, source-facing name/signature, exact behavior, caller-route result, callee roles, boundary/padding proof, owner/source route, and first-draft retained-helper C++.
- Confidence should rise to `88` because binary route scans, disassembly, support docs, and positive controls agree. It should not rise above `88` because no entrypoint/caller is proven and original names remain descriptive rather than recovered.
- Do not demote reconstructability: the function-shaped body is exact source-authored code and already has a valid owner/emitter.
- Do not raise to `90+`: no live route, no original helper name, and no final compact shortcut record type spelling.

## Recommended Target Doc Changes

Apply these in a later supervisor implementation callback only.

1. Header metadata:
   - `COMPLETION:85` -> `COMPLETION:87`
   - `CONFIDENCE:86` -> `CONFIDENCE:88`
   - Keep `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007B`.
   - Add the first-draft C++ above unless the supervisor explicitly chooses the no-code proof policy.

2. Rename/status prose:
   - Keep filename if desired, but add best source-facing name `LivingObjectPane::DispatchConfiguredShortcutHotkey`.
   - Replace "not final-C++ ready" with "retained/no-route source-shaped helper; first-draft C++ is safe only as retained helper with no live caller asserted."

3. Behavior section:
   - Add selector mapping:
     - `0 -> compactShortcutRecords[9]`
     - `1..9 -> compactShortcutRecords[0..8]`
     - `10 -> compactShortcutRecords[19]`
     - `11..19 -> compactShortcutRecords[10..18]`
   - Add compact record layout at `g_pConfig + 0x28f29c + index * 4`.
   - Add key mapping `a-z -> 1..26`, `A-Z -> 27..52`, non-alpha returns, fallback `0xff` if alpha but not ASCII range.
   - Add mode dispatch:
     - nonzero compact record mode byte calls [UID:0003UC] `0x005a4530`;
     - zero mode calls [UID:0001KN] `0x005a3e30`.

4. Evidence section:
   - Add PE details and route scan table from this report.
   - Add disassembly summary and raw boundary bytes.
   - Add positive-control route evidence for `0x005a3ae0`, `0x005a3e30`, `0x005a4530`, and vtable/data route `0x005b6260`.

5. Open questions:
   - Close behavior/name/source-placement questions with the conclusions above.
   - Leave only the entrypoint provenance as an unresolved issue, with exact evidence checked and score impact.

6. Cross-references:
   - Add [UID:0001VR] `RegistryConfigUserProfileBlock`.
   - Keep [UID:0001KM], [UID:0003UB], [UID:0001KN], [UID:0003UC], [UID:00007B], and [UID:0000KU].
   - Optionally add [UID:00028Q] `g_pConfig` and [UID:0003UJ] as related comparison, not ownership dependencies.

## Recommended Support Doc Changes

Apply these only during accepted implementation.

### [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`

- Update the [UID:0003UA] child inventory entry to say it is a compact shortcut record dispatcher, not just a raw config hotkey helper.
- Add the fresh no-route/positive-control table or a summarized version:
  - zero rel32/absolute/RVA route to `0x005a3a20`;
  - positive rel32 routes to `0x005a3ae0`, `0x005a3e30`, and `0x005a4530`.
- Add compact shortcut distinction:
  - `0x005a3a20` uses `g_pConfig + 0x28f29c`;
  - `0x005a3ae0` uses [UID:0001V1] macro rows at `+0x28f2ec`;
  - `0x005a9250` uses legacy shortcut text at `+0x28e89c`.

### [UID:00007B] `LivingObjectPane`

- In raw/local-player boundary caveats, update [UID:0003UA] from generic unresolved raw helper to "retained compact shortcut dispatcher with resolved behavior and no proven entry route."
- Do not claim it is called by active `UserPane::OnKeyEvent`.
- Add the score/source-shape note that retained-helper C++ may be emitted only with the no-route caveat.

### [UID:0000KU] `LivingObjectPane` file

- Under command/spell slot dispatch or boundary notes, add [UID:0003UA] as the compact shortcut consumer of `RegistryConfigUserProfileBlock::m_compactShortcutRecords`.
- Preserve `ProfileStorage` / `RegistryConfig` ownership of the data layout and `LivingObjectPane` ownership of the runtime dispatch.

### [UID:0001VR] `RegistryConfigUserProfileBlock`

- Add [UID:0003UA] as a runtime consumer of `+0x28f29c` compact shortcut records.
- Clarify mode byte runtime behavior:
  - nonzero mode byte routes to LivingObjectPane command/spell slot dispatch (`0x005a4530`);
  - zero routes to inventory/item dispatch (`0x005a3e30`).
- Existing docs already say writer emits `S` when mode byte is nonzero and `I` otherwise; keep that and tie it to runtime evidence here.

### [UID:0003UB] `LivingObjectPaneExecuteHotkeyAction`

- Add a short comparison note that [UID:0003UA] is a compact shortcut dispatcher and [UID:0003UB] is the integrated macro/hotkey dispatcher.
- This helps avoid future mislabeling of `0x005a3a20` as a macro row helper.

### [UID:0001KN] and [UID:0003UC]

- No metadata change required.
- If edited for source-quality wording, add [UID:0003UA] as an additional raw retained caller/consumer:
  - [UID:0003UC] receives compact record mode nonzero.
  - [UID:0001KN] receives compact record mode zero.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` in this B-agent pass.

Search result during this pass: no current line for `0003UA`, `0x005a3a20`, or `LivingObjectPaneRawConfigHotkeyHelper` was found in `source-3/project-documentation/by-memory/-coverage-report.md`. Therefore there is no literal replacement line in that file to apply today.

If the supervisor chooses to insert or refresh a manual `by-memory/-coverage-report.md` child row under [UID:0001KM], use this exact row text in address order after [UID:0003U9] and before [UID:0003UB]:

```markdown
        - [UID:0003UA][0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper](by-memory/0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper.md) 0x005a3a20-0x005a3ad4 | retained raw helper | LivingObjectPaneRawConfigHotkeyHelper : reconstructable : 87% : strong : Retained/no-route `LivingObjectPane` compact shortcut dispatcher; exact prologue body with `retn 8`, zero rel32/absolute/RVA route to start, resolved `g_pConfig+0x28f29c` compact shortcut record reads, `0/10` selector remapping to records `9/19`, ASCII key-to-slot mapping `a-z -> 1..26` and `A-Z -> 27..52`, mode byte nonzero dispatch to [UID:0003UC] `0x005a4530`, mode byte zero dispatch to [UID:0001KN] `0x005a3e30`, `0x005a3ad4-0x005a3ae0` alignment padding, and first-draft C++ valid only as retained helper with no live caller asserted.
```

Generated memory coverage expected after accepted implementation with first-draft C++ inserted:

```markdown
| [UID:0003UA][0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper](by-memory/0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper.md) | emits | `00007B` | `00007B` |  | yes | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `by-memory/0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper.md` |  |
```

If the supervisor rejects C++ insertion under a no-route retained-helper policy, keep the generated memory coverage row's `has code` column as `no` and add the target-specific no-code proof from this report to the by-memory page.

## Validation Commands Needed After Implementation

Run from `source-3/project-documentation` after accepted target/support edits:

> Executable block R001 was removed from this report and preserved verbatim in [0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality-removed.md](0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run only if the specific support docs are edited:

> Executable block R002 was removed from this report and preserved verbatim in [0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality-removed.md](0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If first-draft C++ is inserted, refresh generated output after scoped validators pass:

> Executable block R003 was removed from this report and preserved verbatim in [0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality-removed.md](0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If supervisor inserts the manual coverage row, validate the coverage report:

> Executable block R004 was removed from this report and preserved verbatim in [0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality-removed.md](0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

Do not edit IDA during this report-only task. Recommended future IDA/documentation names:

| Address / item | Recommended name | Confidence | Notes |
| --- | --- | ---: | --- |
| `0x005a3a20` | `LivingObjectPane_DispatchConfiguredShortcutHotkey` | Medium-high behavior, medium route | No IDA function object today; add only if modeling the raw function start. |
| `0x005a3ad4-0x005a3ae0` | alignment | High | `0xcc` padding before `0x005a3ae0`. |
| `0x005a3ae0` | `LivingObjectPane_ExecuteHotkeyAction` | High | Already documented; consumes macro rows. |
| `0x005a3e30` | `LivingObjectPane_UseInventorySlotDispatch` | High | Existing [UID:0001KN]. |
| `0x005a4530` | `LivingObjectPane_UseCommandSlotDispatch` or `UseSpellCommandSlotDispatch` | Medium-high | Existing [UID:0003UC]; exact final spell/command name still provisional. |
| `g_pConfig + 0x28f29c` | `m_compactShortcutRecords` | High role, medium exact spelling | Owned by RegistryConfig user-profile block. |
| compact record `+0` | `key` / `shortcutKey` | High | UTF-16 code point, low byte used for ASCII dispatch. |
| compact record `+2` | `mode` / `spellMode` | Medium-high | Nonzero routes to command/spell, zero to inventory/item. |

Suggested IDA comment at `0x005a3a20` if modeled:

```text
Retained/no-route LivingObjectPane compact shortcut dispatcher. PE scan found zero rel32/absVA/RVA refs to this start. Reads RegistryConfig compact shortcut records at g_pConfig+0x28f29c, maps configured ASCII key to slot 1..52, mode!=0 calls 0x005a4530, mode==0 calls 0x005a3e30. Do not assert live caller until route is proven.
```

## Implementation Callback Checklist

If accepted, send B013 these exact implementation instructions:

1. Edit only the target/support docs listed in this report; do not edit `by-memory/-coverage-report.md`.
2. In [UID:0003UA], update scores to `87/88`, keep owner/emitter metadata, add the retained-helper first-draft C++ body, and add detailed sections for behavior, route scan, boundary bytes, source name/signature, owner/source route, rejected alternatives, and C++ retained-helper caveat.
3. In [UID:0001KM], update the child entry and raw-projected-start notes for `0x005a3a20` with compact shortcut behavior and route evidence.
4. In [UID:00007B] and [UID:0000KU], add concise but factual support notes so class/file docs distinguish [UID:0003UA] compact shortcut dispatch from [UID:0003UB] macro-row dispatch and [UID:0003UJ] legacy function-key debounce.
5. In [UID:0001VR], add [UID:0003UA] as the runtime consumer of `m_compactShortcutRecords` and document mode byte runtime routing.
6. In [UID:0003UB], add the compact-vs-integrated hotkey comparison note.
7. Edit [UID:0001KN], [UID:0003UC], or [UID:00028Q] only if needed to add cross-reference notes; no score changes required there.
8. Provide the exact supervisor-owned coverage row from this report rather than editing `by-memory/-coverage-report.md`.
9. Run the validation commands listed above and report exact results.

## Changed Files In This Report Pass

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality.md`
- Modified by-* docs: none.
- Modified `by-memory/-coverage-report.md`: none.
- Moved/executed reports: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UA","source_path":"executed-b-agent-research/B013/0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
