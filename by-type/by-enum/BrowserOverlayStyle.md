*** UID:0001SM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserOverlayStyle

## Status

- Confidence: strong for observed values, owner, and localized-string/helper boundary; medium for original enum/constant name.
- Current source evidence: IDA MCP decompilation of `BrowserControlPaneOld::DrawBrowserStatusOverlay`; generated source names are lead material only.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), likely browser-private constants.
- Reconstructable: yes as browser overlay constants if final source keeps symbolic names, but do not emit C++ until the text/style helper prototypes and source names are settled.
- Classification: provisional browser overlay constants. Keep this page in `by-enum` as current inventory, but do not treat either value as a final enum declaration yet.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `128` | `kBrowserOverlayDrawStyle` | Style/opacity value applied before drawing the browser status overlay text. |
| `236` | `kBrowserStatusStringId` | Language/string-table id used for the browser status overlay text. |

## Value Use Map

| Observed value | Use site | Current interpretation | Remaining risk |
| --- | --- | --- | --- |
| `236` | Passed to `0x004f0350` from `BrowserControlPaneOld::DrawBrowserStatusOverlay`. | Localized string id for the browser status overlay text. | The string-id mapping belongs with `str.res` once the concrete text is recovered. |
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

## Placement And Classification

Keep this as browser UI overlay state. Do not move it to generic text-control constants unless later xrefs prove the values are shared outside browser overlay drawing.

The current evidence proves two immediate values in the browser overlay draw path, but it does not prove that the original source declared a named enum. The safest reconstruction stance is browser-owned constant candidates: `236` is a localization id consumed by browser overlay code, while `128` is a draw-style value passed through a helper whose owner is still unresolved.

## Reconstruction Guidance

- Replace the magic `236` at the browser overlay call site with a symbolic status-string id only after the localized string table has a durable row/name for the text.
- Replace the magic `128` with a symbolic draw-style/opacity constant only in the overlay draw path until helper `0x004b9680` is assigned to a concrete text-rendering type or function page.
- Do not encode the overlay gate expression as an enum value; document it as `BrowserControlPaneOld` state/layout once the embedded Browser object and legacy control pane fields are named.
- Keep final C++ blank until the declaration form is decided. A pair of `static const`/`constexpr` values may be more accurate than a true enum.

## Source Migration Checklist

When migrating the legacy browser overlay path, keep the two immediate values separated by purpose:

| Immediate | Safe migration use | Keep-out rule |
| --- | --- | --- |
| `236` | Browser overlay status text lookup through the `LanguageMan`/`str.res` helper path. | Do not rename it as a draw style or browser state flag; it is a localized string id until the concrete resource row is named. |
| `128` | Browser overlay draw-style argument passed immediately before text drawing. | Do not promote it to a shared text-rendering enum until the helper at `0x004b9680` has an owner and xref audit. |
| `this+0x110 -> +0x222` gate | Legacy control-pane/browser-object state that decides whether the overlay path executes. | Do not include it in this constants page or in a future two-value enum; it belongs to `BrowserControlPaneOld`/Browser layout recovery. |

This checklist is the current source-facing boundary for the page: `Browser.cpp` may own the overlay constants, `LanguageMan` owns lookup mechanics and future string-id inventory, and the generic text-style helper remains unresolved.

## Autogen Status

- Reconstructable: true, as browser overlay constant candidates.
- Parent: [UID:0000HV][Browser](by-file/Browser.md).
- C++: intentionally blank; final declarations should wait for text/style helper naming and `str.res` string-id mapping.

## Score Rationale

Completion is `80` because the page distinguishes localized string id, draw-style immediate, and overlay gate state; records declaration boundaries; links the old control-pane class and `str.res` evidence; gives reconstruction guidance; and now includes a source migration checklist with explicit keep-out rules. Confidence is `86` because the use sites and owner are exact in existing IDA-backed docs and the localized-string boundary is independently documented, but the final declaration form, localized string name, and owner of the style helper remain open.

## Open Questions

- Determine whether `236` should be documented primarily in the localized string table/resource docs rather than as a browser enum value.
- Determine whether `128` is a generic text/style flag shared by other panes or a browser-specific style constant passed through the generic draw helper.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)

## Changes

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
