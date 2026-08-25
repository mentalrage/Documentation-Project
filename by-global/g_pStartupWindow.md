*** UID:0002ZS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static StartupWindow *g_pStartupWindow;

template <>
Singleton<StartupWindow>::Singleton()
{
    g_pStartupWindow = static_cast<StartupWindow *>(this);
}

template <>
Singleton<StartupWindow>::~Singleton()
{
    g_pStartupWindow = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pStartupWindow

## Status

- Address: `0x0069bac8`
- Storage page: [UID:0002ZT][0x0069bac8-0x0069bacc.g_pStartupWindow](by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md)
- Type hypothesis: `StartupWindow *`.
- Owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Emission: sole source-local forward declaration and definition; physical UID0002ZT and aggregate UID0002AM are non-emitting evidence pages.

## Evidence

The exact memory storage is the final dword in [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md), with exact storage on [UID:0002ZT][0x0069bac8-0x0069bacc.g_pStartupWindow](by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md). This global page owns the source-level declaration:

```cpp
class StartupWindow;

static StartupWindow *g_pStartupWindow;
```

The source-local forward declaration makes the pointer definition compile-visible without inventing an external header contract. The storage child must not duplicate either line; it preserves exact address/range evidence with blank formal channels.

Historical B013 session `ddf5b602` established the declaration/storage route. Historical pre-catalog0373 evidence from read-only MCP session `1da2b2ae` against saved IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, `143191140` bytes, saved `2026-07-29T15:00:32.0998001-04:00`, reconfirmed eight zero bytes, four refs to `0x0069bac4`, zero refs to both reserved addresses, four refs to `0x0069bac8`, and a separate four-ref successor at `0x0069bacc`, but had no persisted target symbol/type/comment and no `StartupWindow` UDT. The prior `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, and earlier identities are historical checkpoints only.

Catalog0373 applied the accepted analysis prerequisite and pointer item. A later bounded no-drift readback at dated saved IDB SHA256 `DBF6280848C1301A796458235703DB91091BB160FD6D3022D6D8FDF483A1F5FD`, `143192467` bytes, saved `2026-07-31T01:36:48.7011378-04:00`, reconfirmed an opaque `StartupWindow` declaration with unknown size and zero members and one exact four-byte `StartupWindow *g_pStartupWindow` item at `0x0069bac8`. Its regular comment is `Active StartupWindow instance used by the update notice WndProc.` and its repeatable comment is `Source reconstruction: static StartupWindow *g_pStartupWindow; initialized to NULL.` The item retains four zero bytes, four lifecycle refs, and intact fences. No complete `StartupWindow` layout is currently defined or inferred. The source-facing name/type remain the best human reconstruction from complete lifecycle behavior, and the opaque analysis declaration does not create a public-header contract.

Current singleton lifecycle refs to `0x0069bac8` are:

- Constructor publish at `0x005807e5` in `StartupWindow__Constructor`: MCP decompile writes `unk_69BAC8 = v2`; disassembly is `mov dword ptr unk_69BAC8, eax`.
- WndProc read/null guard at `0x00581114` in [UID:0004CT][0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc](by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md): MCP decompile starts with `v4 = unk_69BAC8` and falls back to `DefWindowProcA` when the singleton is null.
- Ordinary destructor raw clear at `0x00580864` in [UID:0004CR][0x00580810-0x00580870.StartupWindowOrdinaryDestructor](by-memory/0x00580810-0x00580870.StartupWindowOrdinaryDestructor.md): the raw no-function body ends its cleanup with `mov dword ptr unk_69BAC8, 0`.
- Scalar deleting destructor wrapper clear at `0x00581d94` in [UID:0004D4][0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor](by-memory/0x00581d30-0x00581db2.StartupWindowScalarDeletingDestructor.md): MCP decompile clears `unk_69BAC8 = 0` before optional object free.

[UID:0000DZ][StartupWindow](by-class/StartupWindow.md) independently records this as narrow StartupWindow static state, with constructor, WndProc, and destructor refs in the StartupWindow range. Exact original global spelling is still inferred from project convention and role, so confidence remains capped below final despite the strong lifecycle evidence.

The four-use lifetime pattern rules out an integer, handle, pointer-to-base, class-static member, packed aggregate member, or generic-global-file placement. Every reference is in StartupWindow.cpp, supporting file-local `static` linkage. Lack of original symbols caps lexical confidence but does not justify an IDA label or an external declaration.

## Assignment Gate

Assigned to [UID:0000O5][StartupWindow](by-file/StartupWindow.md) after the file page reached `87/85`. The relationship is direct because this is the StartupWindow singleton pointer storage for the notice/update object, and the adjacent string-buffer pools start only at `0x0069bacc`.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md)
- [UID:0002ZT][0x0069bac8-0x0069bacc.g_pStartupWindow](by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md)

## Changes

- 2026-08-17 B007 UID0000PA singleton source-cause implementation:
  - Raised `92/94 -> 94/95` and replaced the pointer-only fragment with the file-local pointer plus explicit `Singleton<StartupWindow>` constructor/destructor specializations.
  - The constructor specialization's `static_cast<StartupWindow *>(this)` regenerates the observed null-safe PMD `+4/-4` adjustment and publishes the complete object. Reverse base destruction runs the destructor specialization after the derived cleanup and clears the pointer unconditionally.
  - The pointer stays `static` because all four lifecycle/consumer references are in `StartupWindow.cpp`. A public extern, class-static member, generic Singleton storage member, or duplicate constructor/destructor writes would contradict the exact file-local route or duplicate the accepted source cause.

- 2026-07-29 B009 accepted semantic-global closure:
  - Raised `86/88` to `92/94`; preserved canonical owner/emitter UID0000O5 and `RECONSTRUCTABLE:TRUE`.
  - Formal CPP is exactly a source-local `class StartupWindow;` declaration followed by a blank line and `static StartupWindow *g_pStartupWindow;`. H remains blank because no external consumer exists; `[[CHILDREN]]` was removed.
  - Preserved exact constructor publish, WndProc read/null fallback, ordinary-destructor clear, and scalar-wrapper clear evidence. UID0002ZT is physical backing only and cannot emit a second pointer definition or marker.
  - Historical raw `unk_69BAC8`, reconstructable-storage-marker, duplicate-definition, and unresolved-header assumptions remain documented as superseded evidence. Final generated closure requires one forward declaration, one pointer definition, and no UID0002ZT/UID0002AM contribution.

- 2026-07-01 B008 accepted StartupWindow implementation: inserted the formal `static StartupWindow *g_pStartupWindow;` declaration plus `[[CHILDREN]]`. Exact storage remains on [UID:0002ZT][0x0069bac8-0x0069bacc.g_pStartupWindow](by-memory/0x0069bac8-0x0069bacc.g_pStartupWindow.md) and must not duplicate the pointer definition.
- 2026-07-04 B013 UID0002ZT support sync: added current MCP session `ddf5b602` proof for the exact storage child, zeroed bytes/value, split-boundary xrefs, constructor publish `0x005807e5`, WndProc read/null guard `0x00581114`, ordinary destructor raw clear `0x00580864`, scalar deleting destructor wrapper clear `0x00581d94`, and the no-duplicate declaration rule.
- 2026-06-07 A003 Batch 055: created as the canonical global page for the `0x0069bac8` StartupWindow singleton-pointer split from [UID:0002AM][0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals](by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md).
