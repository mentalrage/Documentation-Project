*** UID:00055D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Argumented Item Input Dialog Resources

## Status

- Scope: source literals and shared UI/resource dependencies used by the argumented-item quantity and confirm dialogs.
- Canonical owner: [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md).
- Source disposition: resource index only. Source emission remains in the formal constructor/action methods and shared dependency owners.
- Score: `91/94`; strong.

## Owned Source Literals

| Address | Literal | Owner/use |
| --- | --- | --- |
| `0x0061f99c` | `ArgumentQuantity` | Quantity dialog title passed to DialogPane construction. |
| `0x0061f9c0` | `You can't buy more than 100.` | Quantity validation alert for unsigned values above 100. |
| `0x0061f9fc` | `How much?` | Confirm flow prompt when it opens the quantity dialog. |
| `0x0061fa10` | `Price is different.` | Confirm mismatch alert; the confirm dialog remains open. |

[UID:00055B][0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings](by-memory/0x0061f99c-0x0061fa3c.ArgumentedItemInputDialogStrings.md) is the exact memory authority. These literals are emitted directly in the owning methods; this page does not own duplicate string arrays.

## Shared Resource Dependencies

| Resource/dependency | Use | Ownership boundary |
| --- | --- | --- |
| `DLGEXC3.EPF`, frame `0` | Background image/control and DialogPane background resource. | Shared dialog asset; linked here, not reowned. |
| `PAL01.PAL` | Palette passed to the EPF background control. | Shared palette dependency. |
| `%d` | Quantity text parsing/format contract. | Shared formatting literal, outside the owned literal band. |
| `OK` | Alert button label used by validation/mismatch alerts. | Shared alert/dialog resource; not an argumented-item-local literal. |
| LanguageMan/localized menu data | Provides argumented-menu entry text and related localization. | Owned by the localization and argumented-menu modules. |
| `g_pBackPane` | Parent pane passed to `OnShow`. | Shared UI global dependency. |
| Main UI overlay layer context | Parent/layer context passed to `OnCreate`. | Shared UI graph dependency. |
| ImageButton, StaticText, TextEdit, and EPF image controls | Runtime-created controls and constructor contracts. | Control class/header owners retain declarations and resource behavior. |

## Behavior And Xref Contract

- Quantity construction owns the title literal and creates a `239 x 283` DLGEXC3/PAL01-backed pane.
- Quantity command processing owns the limit message. Values over 100 show the alert; zero sends no packet; the control-1 path closes afterward.
- Confirm command processing owns both `How much?` and `Price is different.`. A price mismatch alerts and returns without closing; a match sends one-item purchase or opens quantity input, then closes.
- Exact code references tie the four literals only to UID0000HH methods. Shared assets and labels have broader xrefs and therefore remain cross-module dependencies.

## Source/Resource Contract

| Area | Source-owned behavior | Resource-owned data |
| --- | --- | --- |
| Dialog construction | Control allocation order, exact bounds, command ids, focus/pending/hover setup, OnCreate/OnShow, and slide-open behavior. | DLGEXC3 image frames and PAL01 palette bytes. |
| Quantity validation | Unsigned parse, `> 100` alert, zero/no-send path, packet send, and close ordering. | Limit-message and shared OK wide text. |
| Price confirmation | Expected/current price comparison, mismatch no-close path, direct purchase or quantity-dialog branch, and close ordering. | Mismatch/prompt literals and localized menu text. |
| Packet output | Exact argument id, quantity, and list-context values. | Shared packet protocol/sender implementation. |

## Boundaries And Exclusions

- This page does not absorb shared DialogPane frame assets, general palettes, LanguageMan state, BackPane, control declarations, packet sender code, or shared alert strings.
- The Message vtable beginning at `0x0061fa3c` is the exact successor to the owned literal band and is unrelated.
- No separate DAT dialog layout is proven for these runtime-created controls. The source constructs the control tree programmatically.

## Reconstruction Notes

- Emit the four owned strings only as wide literals in exact formal methods.
- Use existing shared declarations for DLGEXC3/PAL01 controls, BackPane, Main UI layer context, localization, alert dialogs, and packet sending.
- Do not create a local resource singleton, duplicate string table, callback array, or manually generated vtable data.

## Historical Assumptions And Corrections

- Earlier broad merchant-menu read-only-data ownership is superseded for the four literal addresses by exact method xrefs and standalone UID0000HH source placement.
- Shared resource use is dependency evidence, not permission to reassign those resource owners to this file.

## Cross-References

- [UID:0000HH][ArgumentedItemInputDialogs](by-file/ArgumentedItemInputDialogs.md)
- [UID:00000G][ArgumentedItemQuantityInputDialogPane](by-class/ArgumentedItemQuantityInputDialogPane.md)
- [UID:00000F][ArgumentedItemConfirmInputDialogPane](by-class/ArgumentedItemConfirmInputDialogPane.md)
