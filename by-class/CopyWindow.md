*** UID:000039 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../localization/LanguageMan.h"
#include "../map/BackPane.h"
#include "../ui/controls/TextEditPane.h"
#include "../ui/dialogs/AlertPanes.h"

class CopyWindow : public AlertPane
{
public:
    CopyWindow()
        : AlertPane(g_pLanguageMan->GetLocalizedString(0xf1),
                    g_pBackPane,
                    L"Yes",
                    L"No")
    {
    }

protected:
    virtual void OnPrimaryButton()
    {
        g_pActiveTextEditPane->CopyAllToClipboard();
        g_pActiveTextEditPane = NULL;
    }

    virtual void OnSecondaryButton()
    {
        g_pActiveTextEditPane = NULL;
    }

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CopyWindow

## Status

- Confidence: very strong for exact callback behavior, vtable slots, active-editor global use, source placement, and raw constructor modeling under the inline-construction proof.
- Current source file: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), position `20`, as a private file-local class.
- Documentation basis: IDA-reviewed raw constructor/callback bytes, vtable references, active [UID:0000EO][TextEditPane](by-class/TextEditPane.md) global ownership, and reconnect-flow inline construction evidence.
- Recovered-output caveat: prior recovered class output still uses the stale `g_pCopyWindowTextEditPane` alias; the canonical global is [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md).
- Formal CPP is the complete inline class and method implementation above. UID0001FV and vtable/string children emit only covered-by/compiler-source comments; formal H remains blank because no external complete-type consumer exists.

## Class Purpose

`CopyWindow` is a small [UID:00000B][AlertPane](by-class/AlertPane.md) subclass that coordinates clipboard publication with the active [UID:0000EO][TextEditPane](by-class/TextEditPane.md). It presents a modal alert and, on primary confirmation, calls `CopyAllToClipboard()` before clearing the active-editor global.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005544c0-0x00554513` | Calls `AlertPane::AlertPane` through the source shape `AlertPane(g_pLanguageMan->GetLocalizedString(0xf1), g_pBackPane, L"Yes", L"No")`, then installs the three `CopyWindow` vtables. Historical pre-Gate-2B checkpoint (`2026-08-22`): IDA did not model this start as a function. Current canonical state models `[0x005544c0,0x00554513)` as function `CopyWindow__CopyWindow` with persisted public type `CopyWindow *__thiscall(CopyWindow *this)`. Zero inbound xrefs remain, but the complete retained body and live inline duplicate preserve source liveness. |
| `OnPrimaryButton` / accept/yes behavior alias | `0x00554520-0x00554536` | Calls `TextEditPane::CopyAllToClipboard` at `0x00590520` through [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md), then clears the global. |
| `OnSecondaryButton` / cancel/no behavior alias | `0x00554540-0x0055454b` | Clears [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md). |

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md). The class is `95/96` and emits at source position `20`; [UID:0000IH][CopyWindow](by-file/CopyWindow.md) remains a non-emitting historical index. This route places the complete private class before the ConnectionClosed helper that constructs it.

## Source-Quality Decisions

- Formal source callback names are `OnPrimaryButton()` and `OnSecondaryButton()` because [UID:00000B][AlertPane](by-class/AlertPane.md) declares those no-argument slots. `OnAccept` and `OnCancel` remain behavior aliases for the primary/yes and secondary/no actions.
- `0x0069be00` is [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md), not a CopyWindow-owned `g_pCopyWindowTextEditPane` global. The accept handler unconditionally calls `g_pActiveTextEditPane->CopyAllToClipboard()` before clearing it; the binary has no null guard.
- `0x0067a750` is [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), and the constructor asks it for localized string id `0xf1`. The exact text of id `0xf1` is not resolved in current string-resource docs, so first-draft C++ keeps the numeric id.
- `0x0067a740` is [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md), passed as the `AlertPane` layout/reference argument.
- [UID:0003G6][0x00622f44-0x00622f4c.CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) is source literal UTF-16 `L"Yes"` and [UID:0003G5][0x00622f3c-0x00622f44.CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) is UTF-16 `L"No"`. Current canonical IDA state for UID0003G6 is one eight-byte item `[0x00622f44,0x00622f4c)` named `aYes`, public type `const wchar_t`, with exact bytes decoding as UTF-16LE `Yes`, exact head refs `{0x00553ec0,0x005544ca}`, zero interior refs, and the accepted repeatable comment. Current public `get_string` results are `Y/e/s` at `0x622f44/46/48`; `off_622F44` is neither current item authority nor source-level button-table evidence, and its four-byte item, undefined tail, and two-call handoff are historical pre-Gate-2B evidence only.
- The primary vtable view at `0x00622e7c`, secondary view at `0x00622ee4`, and tertiary view at `0x00622f14` are generated from `class CopyWindow : public AlertPane`. Callback slots `0x00622ed8` and `0x00622edc` point to the primary and secondary button overrides.
- The standalone constructor has zero direct rel32 branch/call refs and zero absolute VA/RVA dword hits in the B014 PE scan, but it is a complete source-authored constructor body. The live reconnect helper at [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) duplicates the same base-constructor call, label arguments, and vtable stores inline when the active text editor has positive text length.
- Rejected ownership/routes: not `TextEditPane` despite using the active editor, not generic [UID:0000HE][AlertPanes](by-file/AlertPanes.md) despite inheriting `AlertPane`, not a standalone CopyWindow translation unit despite the retained out-of-line body, and not dead/no-code bytes despite no direct constructor xref. The selected owner is the ReconnectDialog translation unit because it contains the sole live construction context.

## Current Source And Compiler Closure

- The complete class is file-local, fieldless beyond `AlertPane`, and headerless. Its `0x270` allocation size, three vptr stores, callback slots, and type descriptor prove one class while ordinary C++ regenerates compiler artifacts.
- The retained constructor's exact SHA256 is `F60A271C1E5608BA4A23E356AC4EC665E197F58198F960E6EF18E45DAE51B5A`; the primary and secondary callback hashes are `0F320B7C42E472261185E1CCB80D5367E478714179AB71BB43D1A0258B88642F` and `6C4EE44F24614EB481044283CB6DFB6FC686F039BBF263DED1FB65E8E93FC6AF`.
- The primary callback has only vtable xref `0x00622ed8`, calls `0x00590520`, and then clears `0x0069be00`; secondary has only vtable xref `0x00622edc`, no callee, and only clears the global.
- Vtable/RTTI [UID:0003CV][0x00622e78-0x00622f1c.CopyWindowVtableData](by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md) and literal children UID0003G5/UID0003G6 route through `[[CHILDREN]]` at positions `20`, `30`, and `40`; UID0001FV is position `10`. These are covered-by source evidence, not duplicate bodies/data declarations.
- The prior dedicated-file, declaration-only, `GetString`, and `SelectAll` conclusions are preserved as historical reconstruction stages and superseded by the current same-unit class, `GetLocalizedString`, and `CopyAllToClipboard` evidence.

## Evidence Notes

- `CopyWindow` vtable data at `0x00622e7c` references `0x00554520` and `0x00554540` as callbacks.
- The constructor has no IDA caller xrefs, but the helper at `0x00553e60` allocates a 624-byte object, calls the same alert base constructor, and installs `CopyWindow` vtables inline.
- B014's PE pass reconfirmed the raw constructor body at `0x005544c0-0x00554513`, eight `0xcc` bytes before it, thirteen `0xcc` bytes after it, `OnPrimaryButton` size `0x16`, `OnSecondaryButton` size `0x0b`, and the next helper at `0x00554550` as unrelated non-CopyWindow code.
- B014's PE pass found zero rel32 call/jump refs to `0x005544c0`, `0x00554520`, and `0x00554540`; callbacks are reached as vtable targets at `0x00622ed8` and `0x00622edc`.
- 2026-05-25 IDA caller checks show `0x00553e60` is a `ConnectionClosedDialog`/reconnect-flow init helper that conditionally constructs `CopyWindow`, not a CopyWindow-owned open method.
- 2026-05-26 IDA MCP recheck kept `0x005544c0` as not-a-function, kept `0x00554520`/`0x00554540` as vtable-only callback xrefs, and kept `0x00553e60` as a real `0xd6`-byte helper with reconnect-flow callers.
- 2026-06-01 IDA MCP byte review confirms the constructor-shaped raw body at `0x005544c0-0x00554513`, `OnAccept` at `0x00554520-0x00554536`, and `OnCancel` at `0x00554540-0x0055454b`; the previous callback end omitted the final `retn` byte.
- 2026-06-07 A008 Batch 082 IDA MCP refresh reconfirmed `OnAccept` as `0x00554520-0x00554536`, `OnCancel` as `0x00554540-0x0055454b`, the raw constructor byte range at `0x005544c0-0x00554513`, and thirteen `0xcc` padding bytes after the constructor.
- The same refresh reconfirmed the inline construction side path at `0x00553e60-0x00553f36` with three reconnect-flow callers, and `CopyWindow` vtable slots at `0x00622e7c` include the accept and cancel callbacks at `0x00554520` and `0x00554540`.
- 2026-06-12 A002 Batch 263 split the shared `.rdata` tail and assigned the exact `CopyWindow` button-label children [UID:0003G5][0x00622f3c-0x00622f44.CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) and [UID:0003G6][0x00622f44-0x00622f4c.CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) to this class. Live IDA confirmed the same two labels are referenced only by the raw constructor at `0x005544c5`/`0x005544ca` and the reconnect helper's inline `CopyWindow` construction at `0x00553ebb`/`0x00553ec0`.
- The recovered-output global name `g_pCopyWindowTextEditPane` is too narrow; IDA xrefs show `dword_69BE00` is an active text-edit pointer set by `TextEditPane` construction and cleared by `TextEditPane` destruction.
- Existing TextEditPane/global docs use the canonical `g_pActiveTextEditPane` identity; any recovered class output that still uses the CopyWindow-specific alias should be treated as stale.

## Score Rationale

- Completion `95`: the page now carries the complete private file-local class and method bodies, exact constructor/callback ranges and hashes, active-editor clipboard behavior, localized/back-pane/`L"Yes"`/`L"No"` dependencies, three vtable facets, ordered compiler/literal children, rejected ownership routes, blank-header proof, and the accepted UID0000N0 position-`20` emission route before the same-unit helper. The remaining completion cap is limited to compiler/original-source presentation details rather than missing behavior or source.
- Confidence `96`: raw bytes, vtable-only callback refs, the live inline-construction mirror, exact globals/literals, current dependency APIs, class layout, child order, and generated ReconnectDialog closure independently support the behavior and source placement. The small residual cap reflects the unproved exact historical local-class/header visibility spelling and localized id `0xf1` source token, neither of which changes emitted behavior.
- Historical score: `88/90` was the 2026-06-22 declaration-level stage before the complete inline class, current owner/emitter route, covered children, and generated-source closure were implemented. It remains valid only as dated history in `## Changes`, not as the active score rationale.

## Cross-References

- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:0003G5][0x00622f3c-0x00622f44.CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) CopyWindow `No` button-label wide string.
- [UID:0003G6][0x00622f44-0x00622f4c.CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) CopyWindow `Yes` button-label wide string.
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md)

## Changes

- 2026-08-22 B008 C-IH-013 current-truth callback: Preserved exact `L"Yes"` class semantics, historicalized the former split/two-call itemization, and recorded the completed persisted one-item `aYes` endpoint; class score, owner/emitter, source, children, and formal CPP/H remain unchanged.
- Historical/superseded pre-Gate-2B checkpoint - 2026-08-22 B008 C-IH-013 callback: This callback preserved exact `L"Yes"` class semantics while qualifying the then-canonical `off_622F44` plus undefined-tail itemization and the then-pending child-owned deterministic IDA handoff; class score, owner/emitter, source, children, and formal CPP/H remained unchanged. Completed supervisor Gate 2B later persisted one eight-byte `[0x00622f44,0x00622f4c)` item named `aYes` with public type `const wchar_t` through one `make_data` call, so the split/pending-handoff statement is historical evidence only and is not current authority.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `68/76`.
  - Summary/evidence: accept/cancel callbacks, vtable references, active text-edit global behavior, and reconnect-flow inline construction evidence are documented; remaining uncertainty is the constructor boundary and stale generated alias cleanup.
- 2026-06-01:
  - Before: method ranges used pre-byte-review endpoints and scores were capped at `68/76`.
  - After: corrected constructor/callback ranges and raised scores to `78/84`.
  - Summary/evidence: IDA MCP confirms exact raw bytes, vtable references, active-editor global access, and callback bodies. Completion remains below file-level because final source method names and constructor modeling remain open.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP reconfirms `0x005544c0` is raw constructor-shaped code rather than a modeled function, and confirms modeled callback starts at `0x00554520` and `0x00554540`; existing project docs place the dialog in [UID:0000IH][CopyWindow](by-file/CopyWindow.md).
- 2026-06-06 provenance cleanup:
  - Before: the status section cited a direct recovered-output file path and generated grade/coverage values, and the evidence notes referenced current recovered class output as though it were authoritative.
  - After: replaced those lines with the IDA-backed documentation basis and kept only a recovered-output alias caveat.
  - Evidence: the page already records raw constructor/callback byte review, vtable references, active text-edit global ownership, and reconnect-flow inline construction evidence. Scores, reconstructability, parent, and blank C++ gate remain unchanged.
- 2026-06-07 A008 Batch 082 class-coverage pass:
  - Before: `78/84`, `AUTOGEN_PARENT_UID:` blank.
  - After: `85/86`, `AUTOGEN_PARENT_UID:0000IH`.
  - Evidence: current IDA MCP reconfirmed raw constructor bytes, callback ranges, active-editor global behavior, vtable slots, and the reconnect-flow side-path exclusion; the direct source parent [UID:0000IH][CopyWindow](by-file/CopyWindow.md) was refreshed to `86/86`.
- 2026-06-12 A002 Batch 263:
  - Score unchanged at `85/86`.
  - Added exact CopyWindow button-label children [UID:0003G5][0x00622f3c-0x00622f44.CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) and [UID:0003G6][0x00622f44-0x00622f4c.CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) after live IDA confirmed both labels are used by CopyWindow constructor logic and no non-CopyWindow xrefs.
- 2026-06-22 B014 Rule 26 incorporation:
  - Raised from `85/86` to `88/90` and added declaration-level first-draft C++.
  - Resolved formal callback names as `OnPrimaryButton` and `OnSecondaryButton` while preserving accept/cancel aliases.
  - Corrected stale `g_pCopyWindowTextEditPane`, `dword_67A750`, `dword_67A740`, and `off_622F44` wording to `g_pActiveTextEditPane`, `g_pLanguageMan`, `g_pBackPane`, and `L"Yes"`/`L"No"`.
  - Documented the raw-constructor no-direct-route evidence, the reconnect helper's live inline construction proof, and the rejected TextEditPane/ReconnectDialog/generic AlertPane ownership alternatives.
