*** UID:0002ZQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static ATOM g_startupWindowClassAtom;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_startupWindowClassAtom

## Status

- Address: `0x0069bac4`
- Storage page: [UID:0002ZR][0x0069bac4-0x0069bac6.g_startupWindowClassAtom](by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md)
- Type: Win32 `ATOM` / registered notice-window class atom.
- Owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Emission: sole source definition; physical UID0002ZR and aggregate UID0002AM are non-emitting evidence pages.

## Evidence

The exact memory storage is the first word in [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md). Existing IDA evidence on the startup executable range records four refs to `word_69BAC4`: two from `StartupWindow::RunUpdateCheck` at `0x00580a57` and `0x00580a6e`, and two from the raw alternate setup path at `0x00581af4` and `0x00581b08`.

[UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) ties those refs to the notice-window class registration/check path. [UID:0000DZ][StartupWindow](by-class/StartupWindow.md) records the same static-data owner and keeps this atom with the startup/update notice class.

Historical 2026-06-16 C001 work saved `g_startupWindowClassAtom`, `StartupWindow_Constructor`, and `StartupWindow_RunUpdateCheck`. Historical pre-catalog0373 evidence from read-only MCP session `1da2b2ae` against saved IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, `143191140` bytes, saved `2026-07-29T15:00:32.0998001-04:00`, no longer contained a persisted data name/type/comment at `0x0069bac4`, but it preserved eight zero bytes and exactly four atom refs. `ATOM` existed in IDA at size two. The prior `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, and earlier identities are historical checkpoints only.

Catalog0373 materialized the analysis item that corroborates this semantic source definition. A later bounded no-drift readback at dated saved IDB SHA256 `DBF6280848C1301A796458235703DB91091BB160FD6D3022D6D8FDF483A1F5FD`, `143192467` bytes, saved `2026-07-31T01:36:48.7011378-04:00`, reconfirmed the two-byte `ATOM g_startupWindowClassAtom` item at `0x0069bac4`, regular comment `StartupWindow notice-window class registration atom.`, repeatable comment `Source reconstruction: static ATOM g_startupWindowClassAtom; initialized to zero.`, zero bytes, four refs, and intact fences. This IDA state corroborates but does not duplicate the sole source definition `static ATOM g_startupWindowClassAtom;` on this semantic page. Modeled RunUpdateCheck and UID0004D2 both compare the word against zero, call `RegisterClassExA`, store `AX`, and fail when registration returns zero. The helper is an exact source child with a retained private/static route, so it does not block this global's declaration.

2026-07-01 B008 implementation preserves this as the source-level Win32 `ATOM` declaration. The four-ref proof and zeroed initial storage are enough for declaration emission; the exact storage child remains a no-duplicate marker.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | Exact bytes, type, four refs, both registration paths, semantic/physical split, sole source definition, blank H route, source owner, IDA handoff, and generated closure are documented. |
| Confidence | 94 | Storage role, API type, source file, and behavior are independently supported. Exact original lexical spelling and `static` versus equivalent private linkage remain inferred, keeping confidence below final audit. |

## Assignment Gate

Assigned to [UID:0000O5][StartupWindow](by-file/StartupWindow.md) after the file page reached `87/85`. The relationship is direct because this atom is file-local StartupWindow notice-window registration state; it is not a neighboring packet-transform or string-buffer pool global.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md)
- [UID:0002ZR][0x0069bac4-0x0069bac6.g_startupWindowClassAtom](by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md)

## Changes

- 2026-07-29 B009 accepted semantic-global closure:
  - Raised `87/90` to `92/94`; preserved canonical owner/emitter UID0000O5 and `RECONSTRUCTABLE:TRUE`.
  - Kept formal CPP exactly `static ATOM g_startupWindowClassAtom;`, kept H blank, and removed `[[CHILDREN]]`. UID0002ZR is physical backing only and cannot contribute a second definition or marker.
  - Selected the human source name from behavior and established project style; raw `word_69BAC4`/`unk_69BAC4` aliases are historical analysis labels, not final source.
  - Internal linkage is best supported because all refs remain in StartupWindow.cpp. External linkage, class-static membership, function-local static storage, a packed aggregate, and a generic globals-file route are rejected by the ref set and existing source ownership.
  - Dated command19259's physical comments and malformed trailing text are retained as generated-defect history. Final closure requires one atom definition and no UID0002ZR/UID0002AM source contribution.

- 2026-07-01 B008 accepted StartupWindow implementation: inserted the formal `static ATOM g_startupWindowClassAtom;` declaration plus `[[CHILDREN]]`; exact storage remains [UID:0002ZR][0x0069bac4-0x0069bac6.g_startupWindowClassAtom](by-memory/0x0069bac4-0x0069bac6.g_startupWindowClassAtom.md).
- 2026-06-07 A003 Batch 055: created as the canonical global page for the `0x0069bac4` StartupWindow notice-class atom split from [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md).
- 2026-06-16 C001 safe IDA refresh:
  - Before: `86/87`, with the atom still represented by generic IDA names and the raw alternate setup path only summarized from prior docs.
  - Changed to: `87/90`; saved `g_startupWindowClassAtom`, `StartupWindow_Constructor`, and `StartupWindow_RunUpdateCheck`.
  - Summary/evidence: live IDA confirmed zeroed cluster bytes, four atom refs, RunUpdateCheck registration use, and raw alternate setup `RegisterClassExA` check/store behavior. No raw function creation, prototype/type/member edit, or final C++ was made because raw setup reachability/source shape remains unresolved.
