** TARGET-REPORT-UID:00018U **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018U LanguageManLookupAndSingletonHelpers Source-Quality Report

## Finalized Report / Current Recommendation

- Target: [UID:00018U] `by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md`.
- Recommendation: update the target from stale below-95 no-code wording to current 85/85 source-code gate handling.
- Recommended metadata after supervisor implementation callback: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KK`.
- Recommended source route: keep the direct owner/emitter as [UID:0000KK] `LanguageMan` / `NexusTK/localization/LanguageMan.cpp`. Do not route the whole aggregate through [UID:000071] `LanguageMan` class because the range includes the file-level constructor-cleanup singleton clear helper at `0x004f03c0`.
- First-draft C++ is ready. Remaining uncertainty is final string-output type/API spelling and public helper names, not behavior or source ownership. A no-code proof is not warranted under the current 85/85 gate.
- Split/child need: no required split before updating `00018U`. The range is a cohesive three-helper LanguageMan source cluster with internal `0xcc` padding already documented in `by-memory/-ignored.md`. Optional exact children could be created later for `0x004f0350`, `0x004f0380`, and `0x004f03c0`, but they are not needed for current source-quality repair.

## Evidence Checked

Primary target and owner docs:

- Target page currently records `84/90`, parent/emitter `0000KK`, reconstructable true, blank C++, and stale "95% reconstruction-code gate" language.
- [UID:0000KK] `by-file/LanguageMan.md` now clears `88/85`, places the module at `NexusTK/localization/LanguageMan.cpp`, treats `LanguageManager` as an alias/view, and lists `GetLocalizedString`, the copy-out helper, and `g_pLanguageMan` in this source file.
- [UID:000071] `by-class/LanguageMan.md` clears `86/88` and confirms layout: `+0x0` `LObject`/vtable, `+0x4` string table, `+0x8` string count.
- [UID:000072] `by-class/LanguageManager.md` is `RECONSTRUCTABLE:FALSE`, `-1/-1`, and explicitly ignored as a standalone generated alias over `LanguageMan`.
- [UID:0000RC] and [UID:0001OS] `g_pLanguageMan` pages confirm singleton storage at `0x0067a750`, lifecycle writes/clears, and broad read fanout before localization lookups.
- [UID:0001RP] `str-res-localized-strings.md` confirms the `str.res` line-table contract and the `L"Invalid String ID"` fallback literal at `0x0061ca20`.
- `by-memory/-ignored.md` confirms internal LanguageMan alignment gaps `0x004f0372-0x004f0380`, `0x004f03bb-0x004f03c0`, and `0x004f03cb-0x004f03d0` are compiler/linker `0xcc` padding.

Exported/raw function evidence:

- `resources/exported_data/functions/0x004f0350.json` records size `34` / `0x22`, Ghidra name `meth_0x4f0350`, IDA name `sub_4F0350`, signature `wchar_t * __thiscall ... (this, int)`, 351 callers, zero callees, and both decompilers agreeing on `0 <= id < this[2] ? *(this[1] + 4 * id) : L"Invalid String ID"`.
- `resources/exported_data/functions/0x004f0380.json` records size `59` / `0x3b`, raw names `FUN_004f0380` / `sub_4F0380`, signature `__thiscall(this, out, int)`, two callers, one callee `0x00582560`, and IDA decompilation calling `sub_582560(out, selectedOrFallbackText)` then returning `out`.
- `resources/exported_data/functions/0x004f03c0.json` records size `11` / `0xb`, raw names `FUN_004f03c0` / `sub_4F03C0`, no arguments, one unwind/cleanup xref from `0x00600a64` in `sub_4F0010`, zero callees, and exact body `dword_67A750 = 0`.
- `resources/exported_data/functions/0x00582560.json` shows the copy helper takes `const unsigned __int16 *Src`, computes `wcslen`, grows/allocates through `0x00582e30`, `memmove`s the UTF-16 bytes, and returns `this`. This supports copy/assign semantics while leaving the final public type name open.
- `resources/exported_data/master_globals.json` records `0x0061ca20` as Unicode `"Invalid String ID"` with references from `0x004f0350` and `0x004f0380`.
- `resources/exported_data/master_names.json` still has raw/generated Ghidra names for all three starts and no source-quality IDA names in that stale export, so the docs must normalize names rather than copying `meth_0x4f0350`, `FUN_004f0380`, or `FUN_004f03c0`.

Generated/coverage evidence:

- `source-3/simroot_v2/class_LanguageManager.cpp` emits only `LanguageManager::GetLocalizedString` at `0x004f0350`, with an artificial `LanguageManagerLayout` and old Wave3 threshold `95.0`. This should be folded into `LanguageMan.cpp`; it is not proof of a separate original class.
- `source-3/simroot_v2/class_LanguageMan.cpp` emits the constructor and deleting destructor but still omits `0x004f0380` and `0x004f03c0`.
- `auto-generated/NexusTK/localization/LanguageMan.cpp` includes an empty emitter marker for `00018U` because the target has no C++ block despite being routed to `0000KK`.
- `auto-generated/-ag-memory-coverage.md` already lists `00018U` as `emits` through `0000KK` into `auto-generated/NexusTK/localization/LanguageMan.cpp`.
- `project-level/-auto-completion-stats.md` currently lists `00018U` as `84 | 90 | 87.0`.
- Current `by-memory/-coverage-report.md` row still says `84%`.

Tooling checks:

- Local IDA MCP at `http://127.0.0.1:13337/mcp` was unavailable in this pass: `Unable to connect to the remote server`.
- Current unmodified target validator baseline:

_Executable command block removed from the research report; preserved in [00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md](00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md)._

## Source-Quality Reanalysis

### Helper Signatures And Names

Recommended source-facing names:

| Address | Recommended signature | Notes |
| --- | --- | --- |
| `0x004f0350-0x004f0372` | `const wchar_t *LanguageMan::GetLocalizedString(int stringId) const` | Direct in-range pointer return. Existing `LanguageManager::GetLocalizedString` generated view should fold into this method. |
| `0x004f0380-0x004f03bb` | `WideStringLike *LanguageMan::CopyLocalizedString(WideStringLike *out, int stringId) const` | Source name provisional. Behavior is exact: copy the same selected/fallback text into `out` through the wide-string assign/copy helper and return `out`. |
| `0x004f03c0-0x004f03cb` | `static void LanguageMan_ClearSingletonHelper()` or `static void ClearLanguageManSingleton()` | File-level constructor-unwind cleanup helper; not a public class method. |

Raw/generated names to retire or normalize:

- `cls_0x4f0350`, `meth_0x4f0350`, `FUN_004f0380`, `FUN_004f03c0`, `sub_4F0350`, `sub_4F0380`, `sub_4F03C0`.
- `LanguageManager` as a separate class name. Keep as alias prose only unless future RTTI/header evidence proves a real separate class.
- `DAT_0067a750`, `dword_67A750`, and generated `g_pStringTable`; normalize to [UID:0000RC] `g_pLanguageMan`.
- `aInvalidStringI` / `u_Invalid_String_ID_0061ca20`; use a source literal or private constant such as `kInvalidStringIdText`.

### Fields And Singleton Ownership

- `this + 0x4` is the `LanguageMan` localized string pointer table, best source field name `m_strings`.
- `this + 0x8` is the count of loaded strings, best source field name `m_stringCount`.
- `g_pLanguageMan` at `0x0067a750` is process-wide LanguageMan singleton storage, set by the constructor and cleared by destructor paths plus `0x004f03c0`.
- No source evidence supports a second `LanguageManager` allocation or separate singleton.

### Lookup And Reset Behavior

- Both lookup helpers use signed lower-bound plus upper-bound check: `stringId >= 0 && stringId < m_stringCount`.
- Valid ids index `m_strings[stringId]`.
- Invalid ids use the same fallback literal `L"Invalid String ID"`; direct helper returns it, copy helper copies it.
- `0x004f03c0` only clears `g_pLanguageMan`; it does not free strings, touch `LanguageMan` fields, or call destructors. It is best modeled as cleanup metadata support for a failed/partially unwound constructor path.

### Reachability

- `0x004f0350` has 351 caller refs in exported data, spanning startup, dialogs, input panes, mail/bulletin/inventory, scanner, and UI code. This is high-fanout localization API evidence.
- `0x004f0380` has exactly two direct callers: `0x00530c27` inside the `0x00530b40` NumberInputDialog-family behavior and `0x005c08a2` inside `0x005c07b0` VirusChecker-family code.
- `0x004f03c0` is reached from constructor cleanup/unwind metadata at `0x00600a64`; this is why it belongs in `LanguageMan.cpp` but should not be presented as a normal public method.

## Recommended Exact Target Changes

Metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Status text replacement:

```text
- Confidence: strong for exact helper boundaries, lookup/copy/reset behavior, LanguageMan field use, singleton ownership, caller reachability, and LanguageMan.cpp routing. Remaining caps are final copy-output string type/API spelling and whether the public source name used `GetLocalizedString`, `GetString`, or an overload.
- Disposition: reconstructable LanguageMan.cpp helper cluster. The target clears the current 85/85 first-draft source gate after the completion repair; the prior "blank under 95% gate" language is stale.
- Current generated status: active `simroot_v2` emits `0x004f0350` only through a generated `LanguageManager` alias and omits `0x004f0380` and `0x004f03c0`; `auto-generated/NexusTK/localization/LanguageMan.cpp` contains an empty marker for this UID.
```

Recommended first-draft C++ block:

```cpp
static const wchar_t *kInvalidStringIdText = L"Invalid String ID";

const wchar_t *LanguageMan::GetLocalizedString(int stringId) const
{
    if (stringId >= 0 && stringId < m_stringCount) {
        return m_strings[stringId];
    }

    return kInvalidStringIdText;
}

WideStringLike *LanguageMan::CopyLocalizedString(WideStringLike *out, int stringId) const
{
    const wchar_t *text = GetLocalizedString(stringId);
    WideString_Assign(out, text);
    return out;
}

static void LanguageMan_ClearSingletonHelper()
{
    g_pLanguageMan = 0;
}
```

Implementation notes for that block:

- `WideStringLike` and `WideString_Assign` are placeholders for the `0x00582560` string helper family; if the supervisor wants only repository-established type names in reconstruction blocks, use the local established alias (`SimpleUString`, `StringBaseW`, or `StringLike`) from the current string-family pass.
- The source logic should not preserve `LanguageManagerLayout`, `reserved00[4]`, `cls_0x4f0350`, raw `sub_` names, or a raw `reinterpret_cast` layout.
- The literal may be inlined instead of named if the project style prefers literal returns.

Recommended function table additions/replacements:

```text
| `0x004f0350-0x004f0372` | `LanguageMan::GetLocalizedString` | Returns `m_strings[stringId]` when `0 <= stringId < m_stringCount`; otherwise returns `L"Invalid String ID"`. |
| `0x004f0380-0x004f03bb` | `LanguageMan::CopyLocalizedString` / output overload | Applies the same bounds check and copies the selected/fallback UTF-16 text into the caller-provided string object through `0x00582560`; returns the output object. |
| `0x004f03c0-0x004f03cb` | `LanguageMan_ClearSingletonHelper` | File-level constructor cleanup helper that stores `0` to `g_pLanguageMan`. |
```

## Validator Needs

Current report-only baseline already passed UID validation for the unmodified target.

After supervisor implementation callback, validate at least:

_Executable command block removed from the research report; preserved in [00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md](00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md)._

If the C++ block is added and the validator supports a non-UID/reference pass for one file in the current workflow, also run that on the target page before updating coverage text.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from this B-agent pass. If the supervisor accepts this recommendation, replace the current `00018U` row with:

```text
    - [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) 0x004f0350-0x004f03cb | helper cluster | LanguageMan lookup and singleton helpers : reconstructable : 86% : strong : B013 source-quality pass resolves the stale 95% no-code gate under the current 85/85 rules: exact LanguageMan.cpp helper cluster with `GetLocalizedString` at `0x004f0350`, copy-out lookup at `0x004f0380`, and constructor-cleanup singleton clear at `0x004f03c0`; exported IDA/Ghidra records confirm sizes `0x22`/`0x3b`/`0xb`, 351 direct callers for the return helper, two direct callers for the copy helper, one constructor-unwind xref for the clear helper, zero/one/zero callee sets, shared `m_strings`/`m_stringCount` fields, `L"Invalid String ID"` fallback refs at `0x004f0369`/`0x004f03a9`, `g_pLanguageMan` clear at `0x004f03c0`, LanguageMan/Singleton<LanguageMan> RTTI with no LanguageManager RTTI, and file owner/emitter [UID:0000KK]; first-draft C++ is ready, with final copy-output string type and public helper spelling as remaining caps.
```

## Open Questions

- Final public method spelling: `GetLocalizedString`, `GetString`, or an overload pair.
- Final copy-output type name: the callee `0x00582560` has wide-string assign/copy behavior, but the broader string-family docs still distinguish `SimpleUString`, pointer-backed `StringBase`, and aliases.
- Whether the constructor cleanup helper should be named with `LanguageMan_` prefix, a private static source name, or left as compiler/EH cleanup prose.
- Whether future granularity work should create exact child pages for the three starts; not required for this source-quality repair.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00018U-LanguageManLookupAndSingletonHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00018U"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00018U-LanguageManLookupAndSingletonHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
