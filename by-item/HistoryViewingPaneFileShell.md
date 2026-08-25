*** UID:00054J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "HistoryViewingPane.h"

#include "../app/Application.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../ui/MainUiGraph.h"
#include "../ui/core/Event.h"
#include "../ui/core/ScreenPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_LOGIN_HISTORYVIEWINGPANE_H
#define NEXUSTK_LOGIN_HISTORYVIEWINGPANE_H

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HistoryViewingPane File Shell

## Status

- Source root: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), `NexusTK/login/HistoryViewingPane.cpp` and sibling `HistoryViewingPane.h`.
- Role: validator-compatible file-level include/guard shell. By-file pages are source roots but are excluded from direct reconstruction payload metadata, so this child carries the exact accepted UID0000JW formal CPP/H wrappers at emitter position `0`.
- Child order: class UID000066 at shell position `10`; singleton/global UID0000R3 at shell position `20`. UID000066 in turn owns method definitions UID0001A0 and UID0001A1 at positions `10` and `20`.
- This page contains no independent executable or data entity. It exists only to preserve one source-authentic include shell, one complete header guard, and deterministic nested child order without duplicating source.

## Exact Source Contract

- CPP includes the generated sibling header plus Application, EPFTileContext, ImageLib, MainUiGraph, Event, and ScreenPane dependencies before `[[CHILDREN]]`.
- H wraps every class/global child in `NEXUSTK_LOGIN_HISTORYVIEWINGPANE_H`.
- No compiler helper, vtable array, RTTI record, raw data island, or generated-file text is copied into this shell.
- The class child emits authored methods through its own `[[CHILDREN]]`; the global child emits the singleton definition and specializations after the class methods.

## Evidence And Rationale

- The accepted UID0000JW whole-file report proves one standalone compilation unit with one required sibling H, six authored method bodies, an implicit destructor effect, and one source global.
- Directly placing a reconstruction block on the by-file page is not supported by the current validator metadata model. A dedicated position-zero child is therefore required to realize the accepted file-level formal payload and guard all declarations.
- Folding the shell into MainMenuPane, ChattingColorPane, BackStoryDialogPane, or NewHistoryDialogPane would contradict class RTTI, source routing, singleton ownership, and caller evidence.

## Cross-References

- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md)

## Changes

- 2026-08-16 Agent-B010 accepted UID0000JW callback: created the exact validator-compatible file-shell carrier required to implement the accepted formal CPP/H and deterministic nested source order without direct generated-file edits.
