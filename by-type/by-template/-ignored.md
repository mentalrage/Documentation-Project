*** UID:0001WM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Ignored Template Records

Use this file to list template candidates that should not become NexusTK-owned templates.

Add entries for STL/Dinkumware templates, compiler support templates, third-party-library templates, stale generated template guesses, or templates superseded by concrete helper/class docs. Include name, reason, evidence, and replacement link.

## Ignored Entries

- `CandidateStringDequeTemplate` - MSVC/Dinkumware `std::deque<std::wstring>` helper materialization for IME candidate strings, not a NexusTK-owned template body. Evidence: [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md), exact helper pages [UID:0002MS][0x004e8450-0x004e85ae.CandidateStringQueueAssignRange](by-memory/0x004e8450-0x004e85ae.CandidateStringQueueAssignRange.md), [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md), [UID:0002MU][0x004e8a00-0x004e8ae6.CandidateStringQueueClear](by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md), and [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md). Replacement owner: source-facing `std::deque<std::wstring>` use inside [UID:0000K5][IMEPanes](by-file/IMEPanes.md) / [UID:0000K6][InputMan](by-file/InputMan.md).
