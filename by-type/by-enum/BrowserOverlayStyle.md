*** UID:0001SM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserOverlayStyle

## Status

- Confidence: strong for observed values, browser owner, legacy draw-path boundary, localized-string lookup, and generic style-helper keep-out; medium-high for original enum/constant names.
- Current source evidence: IDA MCP decompilation of `BrowserControlPaneOld::DrawBrowserStatusOverlay`; generated source names are lead material only.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), likely browser-private constants.
- Reconstructable: yes as browser overlay constants if final source keeps symbolic names. The UID00032T method can now emit because `LanguageMan` and GrafPort helper names are source-ready; this constants page still keeps C++ blank because `236` and `128` are not proven final enum/declaration names.
- Classification: provisional browser overlay constants. Keep this page in `by-enum` as current inventory, but do not treat either value as a final enum declaration yet.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `128` | `kBrowserOverlayDrawStyle` | Style/opacity value applied before drawing the browser status overlay text. |
| `236` | `kBrowserStatusStringId` | Language/string-table id used for the browser status overlay text. |

## Value Use Map

| Observed value | Use site | Current interpretation | Remaining risk |
| --- | --- | --- | --- |
| `236` | Passed to `0x004f0350` from `BrowserControlPaneOld::DrawBrowserStatusOverlay`. | Localized string id for the browser status overlay text; current `STR.RES` payload text is `Please wait for a while...`. | The text remains resource-owned data, so source should keep `GetLocalizedString(236)` or a named id constant rather than hard-code the string. |
| `128` | Passed to text/style helper `0x004b9680` immediately before drawing the overlay text. | Overlay text draw style, opacity, color, or flag value. | The helper may be generic, so the final declaration could be shared text-rendering state rather than browser-private data. |
| Browser flag at `*(_DWORD *)(this + 272) + 546` | Checked before the overlay text path runs. | Gate for whether the status overlay is drawn. | This is control state, not a member of this constants page. |

## Declaration Boundary

| Candidate | Best current declaration form | Why not final yet |
| --- | --- | --- |
| `236` / `kBrowserStatusStringId` | Browser-local named constant or reference to a localized string-id enum. | The value is a language table key, not a draw-style setting. It may belong in a broader localized-string id inventory once the concrete `str.res` row is named. |
| `128` / `kBrowserOverlayDrawStyle` | Browser-local named constant pending helper ownership review. | The value is passed to generic helper `0x004b9680`; if later xrefs prove that helper owns a shared text-style enum, this value should move or cross-link there. |
| Overlay gate at `this+0x110 -> +0x222` equivalent expression | BrowserControlPaneOld state/flag field, not an enum value here. | The flag controls whether the overlay path executes, but no symbolic value is observed at this page's level. |

This page therefore tracks a browser overlay constant pair rather than a finished `enum class BrowserOverlayStyle`. Reconstruct source with symbolic constants only where they remove magic numbers in the legacy overlay path; keep final header placement open until the text-style helper and localized-string id inventory are reconciled.

## Evidence

- IDA MCP confirms `BrowserControlPaneOld::DrawBrowserStatusOverlay` at `0x0046f220-0x0046f30f`.
- IDA MCP decompilation shows the function first checks a flag at `*(_DWORD *)(this + 272) + 546` before drawing.
- The function fetches language/string-table id `236` through `0x004f0350`, measures and centers the returned wide string inside the pane rectangle, then applies style value `128` through `0x004b9680` before drawing the text.
- The constants are therefore confirmed in the overlay draw path, but their final source-level names are still naming hypotheses.
- [UID:0000HV][Browser](by-file/Browser.md) already groups this page with browser UI constants, and [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md) identifies `DrawBrowserStatusOverlay` as the evidence source for this page.
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) documents the `0x004f0350` language/string lookup helper used by the `236` path.
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md) now records this enum page as part of the old control pane's class-state/type evidence and keeps old-path layout questions separate from the constants.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed `BrowserControlPaneOld::DrawBrowserStatusOverlay` at `0x0046f220` size `0xef`, with vtable data xref `0x006137c4`.
- Live `analyze_function 0x0046f220` shows the overlay path reads the embedded browser/control state at `this + 272`, gates on byte `+546`, fetches localized string id `236` through `0x004f0350`, measures and centers the string in the pane rectangle, calls the draw-position helper, applies style value `128` through `0x004b9680`, and draws the wide string through `0x004bab70`.
- Live `xrefs_to 0x004b9680` returned at least 100 code xrefs with more results available; the browser overlay call at `0x0046f2db` is only one consumer. This supports keeping the `128` declaration as browser-use evidence until the generic text/style helper owner is documented.
- Supporting owner pages now clear the direct-route gate: [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md) is `85/87`, and [UID:0000HV][Browser](by-file/Browser.md) is `86/88` with BrowserOverlayStyle listed as browser-owned or browser-coupled data.
- 2026-06-16 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed `DrawBrowserStatusOverlay` as `sub_46F220`, size `0xef`, with the only xref coming from the BrowserControlPaneOld vtable slot at `0x006137c4`.
- 2026-06-16 `analyze_function 0x0046f220` again shows the overlay gate through `*(_DWORD *)(this + 272) + 546`, localized id `236` passed to `0x004f0350`, style value `128` passed to `0x004b9680`, and final text draw through `0x004bab70`.
- 2026-06-16 `xrefs_to` at the requested cap returned at least 120 references to `0x004b9680` and at least 120 references to `0x004f0350`, while `type_query Overlay` found only DirectDraw SDK overlay types and `type_query Browser` found no Browser-specific local enum. This confirms the helper/value ownership boundary is still unresolved rather than merely undocumented.
- 2026-07-02 B006 current MCP evidence for [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md) reconfirmed `sub_46F220` at size `0xef`, vtable/data xref `0x006137c4`, no direct code callers, width and line-height measurement through `g_pScreenPane`, localized lookup id `236`, style/color immediate `0x80` / 128 through `0x004b9680`, and final wide-text drawing through `0x004bab70`. Read-only `STR.RES` extraction ties id `236` to current text `Please wait for a while...`. This supports method-level C++ emission while preserving this page's provisional-constant classification.

## Placement And Classification

Keep this as browser UI overlay state. Do not move it to generic text-control constants unless later xrefs prove the values are shared outside browser overlay drawing.

The current evidence proves two immediate values in the browser overlay draw path, but it does not prove that the original source declared a named enum. The safest reconstruction stance is browser-owned constant candidates: `236` is a localization id consumed by browser overlay code, while `128` is a text-color/style value passed through a generic draw-state helper whose broader owner remains separate from Browser.

## Reconstruction Guidance

- Replace the magic `236` at the browser overlay call site with a symbolic status-string id only after the localized string table has a durable row/name for the text.
- Replace the magic `128` with a symbolic draw-style/opacity constant only in the overlay draw path until helper `0x004b9680` is assigned to a concrete text-rendering type or function page.
- Do not encode the overlay gate expression as an enum value; document it as `BrowserControlPaneOld` state/layout once the embedded Browser object and legacy control pane fields are named.
- Keep this page's final C++ blank until the declaration form is decided. A pair of `static const`/`constexpr` values may be more accurate than a true enum, even though [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md) can now emit its method body using the numeric immediates with documented caveats.

## Source Migration Checklist

When migrating the legacy browser overlay path, keep the two immediate values separated by purpose:

| Immediate | Safe migration use | Keep-out rule |
| --- | --- | --- |
| `236` | Browser overlay status text lookup through the `LanguageMan`/`str.res` helper path; current text is `Please wait for a while...`. | Do not rename it as a draw style or browser state flag, and do not hard-code the English text in source. |
| `128` | Browser overlay text-color/style argument passed immediately before text drawing. | Do not promote it to a shared text-rendering enum or browser-private enum until broader declaration proof exists. |
| `this+0x110 -> +0x222` gate | Legacy control-pane/browser-object state that decides whether the overlay path executes. | Do not include it in this constants page or in a future two-value enum; it belongs to `BrowserControlPaneOld`/Browser layout recovery. |

This checklist is the current source-facing boundary for the page: `Browser.cpp` may own the overlay constants, `LanguageMan` owns lookup mechanics and future string-id inventory, and the generic text-style helper remains unresolved.

## Autogen Status

- Reconstructable: true, as browser overlay constant candidates.
- Parent: [UID:0000HV][Browser](by-file/Browser.md).
- C++: intentionally blank for this constants page; final declarations should wait for enum-vs-constant proof and durable names for localized id `236` and style/color immediate `128`. UID00032T method C++ is no longer blocked by helper naming.

## Score Rationale

Completion is `86` because the page distinguishes localized string id, draw-style immediate, and overlay gate state; records declaration boundaries; links old control-pane, browser-file, memory, and `str.res` evidence; includes source migration keep-out rules; and now documents a current live decompile/xref/type-catalog refresh proving the two immediates and the generic helper boundary. Confidence is `89` because the use sites, owner route, vtable anchor, localized-string lookup, and broad helper fan-in are IDA-backed; it remains below final-audit range because the final declaration form, localized string name, and source name for the style value remain open.

## Open Questions

- Determine whether `236` should be documented primarily in the localized string table/resource docs rather than as a browser enum value.
- Determine whether `128` is a generic text/style flag shared by other panes or a browser-specific style constant passed through the generic draw helper.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)

## Changes

- 2026-07-02 B006 UID00032T implementation callback:
  - Score unchanged at `86/89`.
  - Evidence: current MCP reconfirmed `0x0046f220` size `0xef`, vtable-only/data xref `0x006137c4`, no direct code callers, `g_pScreenPane` width/line-height measurement, localized id `236`, style/color immediate `0x80` / 128 via `0x004b9680`, and final draw through `0x004bab70`. Read-only `STR.RES` extraction confirms zero-based id `236` / `0xec` as current text `Please wait for a while...`.
  - Classification: helper names are source-ready enough for [UID:00032T][0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay](by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md) method C++; this page remains a provisional constants inventory with blank C++ because `236` as a localized string id and `128` as a text-color/style immediate do not prove a final enum declaration.
- 2026-06-16 A002 Goal 2 source-quality refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:88`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`, with no C++ emission.
  - Evidence: live MCP reconfirmed `0x0046f220` size `0xef`, vtable-only xref `0x006137c4`, overlay gate/read/string/style/draw sequence, localized id `236`, style argument `128`, at least 120 xrefs each to generic helper `0x004b9680` and lookup helper `0x004f0350`, and no Browser-specific local enum/UDT. Final enum-vs-constant and helper-owner questions remain explicit blockers.
- 2026-06-14 A002 Goal2 by-type score refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:86`; the page had the right value-use split but only older evidence for the generic style-helper boundary.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`, with fresh live IDA evidence and no reconstruction C++.
  - Evidence: live MCP reconfirmed `0x0046f220` size `0xef`, vtable xref `0x006137c4`, overlay gate/read/string/style/draw sequence, localized id `236`, style argument `128`, and at least 100 xrefs to the generic helper `0x004b9680`. Final enum-vs-constant and helper-owner questions remain explicit blockers.
- 2026-06-02:
  - What existed before: the page was `62/82`, reconstructable, but had no parent attachment and only summarized the two observed values.
  - Changed to: completion/confidence `72/84`, `AUTOGEN_PARENT_UID:0000HV`, explicit value-use map, autogen status, placement/classification notes, and localization cross-reference.
  - Summary/evidence: `BrowserControlPaneOld::DrawBrowserStatusOverlay` confirms both immediate values; Browser already groups this page as browser UI constants, and `str.res` docs confirm the language lookup helper behind the `236` string-id path.
- 2026-06-07 A002 declaration-boundary pass:
  - What existed before: `COMPLETION:72`, with the two observed values and owner links documented but no explicit distinction between localized string id, draw-style immediate, and overlay gate state.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:84`, with declaration-boundary and reconstruction-guidance sections.
  - Summary/evidence: [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), [UID:0000HV][Browser](by-file/Browser.md), and [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) support the browser-local use while keeping final enum-versus-constant placement open.
- 2026-06-07 A006 source-migration checklist:
  - Before: `COMPLETION:76`, `CONFIDENCE:84`, with declaration boundaries documented but no concise source-facing checklist for replacing the immediate values safely.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:86`, with a migration checklist separating the `236` localized string id, `128` draw-style argument, and overlay gate state.
  - Evidence: [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md) records the legacy overlay owner, [UID:0000HV][Browser](by-file/Browser.md) owns browser-private constants, [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) owns the lookup mechanics, and [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md) keeps the surrounding browser/OLE aggregate context.
