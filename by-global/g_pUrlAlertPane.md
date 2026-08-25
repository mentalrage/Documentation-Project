*** UID:0000SM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UrlAlertPane *g_pUrlAlertPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pUrlAlertPane

## UID0003ZT Declaration And Guard Consumer - 2026-07-23

- This page remains the sole four-byte `UrlAlertPane *g_pUrlAlertPane` storage definition under [UID:0000HE][AlertPanes](by-file/AlertPanes.md); its `87/92` score, owner/emitter, lifecycle, and six-xref evidence are unchanged.
- `NexusTK/ui/dialogs/AlertPanes.h` exports `extern UrlAlertPane *g_pUrlAlertPane;`. AlertPanes.cpp emits the one definition; MapPane.cpp includes the header and must not add a second definition.
- [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) is a read-only guard consumer: after matching `kEventWorkNotification`, it returns without creating `ConnectionClosedDialog` while this pointer is non-null.
- The target does not construct, publish, clear, or own UrlAlertPane. This guard relationship adds a consumer route only and preserves all alert-family ownership.

## Status

- Symbol kind: process-wide singleton pointer.
- Address: `0x0069b4dc`
- IDA name: `dword_69B4DC`
- Likely source module: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Generated output target: `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`
- Exact storage child: [UID:0002WC][0x0069b4dc-0x0069b4e0.g_pUrlAlertPane](by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md)
- Source declaration: `UrlAlertPane *g_pUrlAlertPane = NULL;`. Exact `static` versus external linkage is not proven from the binary; cross-module guard reads and the existing by-global route favor a non-static declaration until source-layout evidence proves otherwise.
- Confidence: very strong for storage, lifecycle, and `AlertPanes.cpp` ownership; still below final for original linkage/spelling.

## Purpose

`g_pUrlAlertPane` tracks the active [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), if one is displayed. The constructor stores the new pane pointer, the ordinary destructor/scalar wrapper/constructor-unwind cleanup clear it, and external alert-open guards read it to prevent overlapping modal alert panes. B013's 2026-06-19 MapPane notify split clarifies that the `0x00508fd6` reader uses this pointer as a broad active-alert guard before constructing a connection-closed dialog; it does not prove that the constructed object at that site is a `UrlAlertPane`.

## Score Rationale

- Completion `87`: this global now has a declaration-level first draft under [UID:0000HE][AlertPanes](by-file/AlertPanes.md), plus exact one-dword storage child [UID:0002WC][0x0069b4dc-0x0069b4e0.g_pUrlAlertPane](by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md), reviewed non-emitting split index [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), class/method lifecycle [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) / [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md), and packet/guard caller separation. It is not higher because exact original linkage (`static` or external) and every caller's semantic name are still below the final reconstruction bar.
- Confidence `92`: strong for address, `0x4` / 4-byte storage shape (Verified with int_convert.py), six lifecycle/read refs, active-alert guard usage, URL buffer and exit flag context, vtable-backed class identity, and `AlertPanes.cpp` ownership. It remains below `95` because the declaration linkage is still inferred rather than proven original source text.

## Evidence Notes

- Live IDA MCP rechecked `0x0069b4dc` on 2026-06-03 in `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`; IDA names it `dword_69B4DC` and the initial dword is `0xffffffff`.
- [UID:0002WC][0x0069b4dc-0x0069b4e0.g_pUrlAlertPane](by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md) documents the exact `0x4` / 4-byte storage child (Verified with int_convert.py), predecessor/successor boundaries, and the Batch044 split out of the mixed singleton cluster.
- The full data-xref set is six sites: the active-alert guard read at `0x00508fd6`, constructor writes at `0x00599a94` and `0x00599a9b`, normal destructor clear at `0x00599b73`, singleton-clear helper at `0x00599bd0`, and scalar deleting destructor clear at `0x00599c5a`.
- `0x00599a40-0x00599b19` constructs the pane, calls the alert-pane base constructor, writes `this` to the singleton, installs the `UrlAlertPane` vtables, stores the URL buffer pointer at `+0x270`, stores the exit-after-open flag at `+0x274`, copies the URL bytes, and terminates the buffer.
- 2026-06-21 B011 source-quality recheck names the source fields as `UrlAlertPane::m_url` at `+0x270` and `UrlAlertPane::m_exitAfterOpen` at `+0x274`, and resolves the direct source declaration as `UrlAlertPane *g_pUrlAlertPane = NULL;` under `AlertPanes.cpp`. The non-static spelling is a best current source-layout choice, not proof of original linkage.
- `0x00599b20-0x00599b92` and `0x00599c00-0x00599cb3` free the URL buffer and clear the singleton during normal and scalar-deleting teardown.
- `0x00599ba0-0x00599bcf` confirms the object role: it calls `ShellExecuteA` on the stored URL and optionally requests application exit when the `+0x274` flag is set.
- [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) reads `dword_69B4DC` at `0x00508fd6` and refuses to allocate another modal alert when this singleton is non-null. The direct constructor called from that notify path is [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md), so the guard is shared alert-state evidence rather than `UrlAlertPane` construction evidence. Constructor xrefs to the actual `UrlAlertPane` constructor `0x00599a40` remain the main-menu/alert callers rechecked at `0x00503034`, `0x00513f7e`, and `0x0051402f`.
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) owns the `0x00503034` constructor call site: opcode `0x66` subtypes `1` and `2` parse counted ANSI URL/text payloads and construct `UrlAlertPane` with the exit flag set or clear.
- The surrounding slot run `0x0069b4c8-0x0069b4ec` is a sequence of adjacent `0xffffffff`-initialized UI singleton pointers, with `g_pUrlAlertPane` occupying the `0x0069b4dc` slot.

## Lifecycle Evidence

| Address | Access | Meaning |
| --- | --- | --- |
| `0x00508fd6` | read | [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) active-alert guard refuses to allocate the connection-closed dialog while `g_pUrlAlertPane` is non-null. |
| `0x00599a94` | write | Constructor publishes `this` to `dword_69B4DC` before class-specific vtable setup. |
| `0x00599a9b` | clear/write | Constructor null/fallback path updates the singleton slot during setup. |
| `0x00599b73` | clear | Normal destructor frees the URL buffer and clears the active singleton pointer. |
| `0x00599bd0` | clear | Constructor exception-cleanup helper clears the singleton before adjacent destructor adjustor thunks. |
| `0x00599c5a` | clear | Scalar deleting destructor wrapper clears the singleton after the destructor path. |

## Cross-References

- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:0002WC][0x0069b4dc-0x0069b4e0.g_pUrlAlertPane](by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md)
- [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md)
- [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md)
- [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md)

## Changes

- 2026-06-21 B011 Rule 26 source-quality incorporation: raised `86/91` to `87/92` and added first-draft global declaration C++. The source declaration is `UrlAlertPane *g_pUrlAlertPane = NULL;` under [UID:0000HE][AlertPanes](by-file/AlertPanes.md), with exact `static` versus external linkage left as a narrow caveat. Evidence: B011 rechecked [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md), all six data refs, constructor/destructor/scalar/unwind lifecycle, `m_url`/`m_exitAfterOpen`, and packet/guard consumers.

- 2026-06-19 B013 MapPane notify/timer split sync: corrected the `0x00508fd6` reader from "URL alert construction" wording to broad active-alert guard evidence. [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) uses `g_pUrlAlertPane` to suppress overlapping alerts before allocating and constructing [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md); actual `UrlAlertPane` construction remains with the `0x00599a40` constructor callers.
- 2026-06-11 A005 Batch239: Raised `82/90` to `86/91` by linking the direct exact memory child [UID:0002WC][0x0069b4dc-0x0069b4e0.g_pUrlAlertPane](by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md), verifying the one-dword `0x4` / 4-byte storage size with int_convert.py, and recording that [UID:0000HE][AlertPanes](by-file/AlertPanes.md) remains above the direct parent gate. This makes the global page eligible as the direct parent for the exact storage child; final C++ remains blank below the `95/95` emission bar.

- 2026-06-06: Raised completion/confidence from `78/88` to `82/90`. Added lifecycle evidence for the duplicate-open read, constructor writes, normal-destructor clear, constructor-cleanup helper clear, and scalar deleting destructor clear; linked the surrounding singleton-slot aggregate, main-menu ANSI/URL packet helper, and UrlAlertPane vtable family. Evidence: [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) documents the `88/90` class identity and layout offsets, [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md) maps the constructor/destructor/confirm/helper ranges, [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) records the exact `0x0069b4dc` singleton slot, and [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) identifies the main-menu opcode `0x66` constructor caller.

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:70`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HE` for [UID:0000HE][AlertPanes](by-file/AlertPanes.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4dc` as a 4-byte singleton pointer with 6 data xrefs spanning active-alert checks, UrlAlertPane construction, cleanup, normal destructor, and scalar deleting destructor.
- 2026-06-03: Raised completion/confidence from `70/84` to `78/88`.
  - Reason: live IDA MCP reconfirmed the exact global, all six data xrefs, constructor caller set, duplicate-open guard, URL buffer/exit flag offsets, and the neighboring singleton-slot inventory.
  - Boundary: no final C++ declaration was emitted because original source spelling/linkage and complete caller semantic names remain below the `95/95` reconstruction threshold.
