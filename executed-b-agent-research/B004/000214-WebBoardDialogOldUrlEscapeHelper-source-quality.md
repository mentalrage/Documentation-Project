** TARGET-REPORT-UID:000214 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000214] WebBoardDialogOldUrlEscapeHelper Source-Quality Refresh

Status: FINISHED  
Agent: B004  
Assignment: Refresh/rework pending report only  
Target: `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`  
Scope followed: edited only this report. No by-* pages, support pages, generated files, or `by-memory/-coverage-report.md` were edited.

## Recommendation Summary

Promote [UID:000214] from a raw/no-code old WebBoard URL escape helper to a first-draft source helper emitted by [UID:0000P9] `by-file/WebBoardDialog.md`.

Exact target metadata recommendation:

```text
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000P9
EMITTER_UIDS:0000P9
```

Exact source-facing helper recommendation:

```cpp
static char *__cdecl EscapeOldWebBoardUrl(const char *source,
                                          short sourceLength,
                                          char *dest,
                                          short destCapacity);
```

Destination remains:

```text
auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp
```

Current generator state confirms the route but not the code: `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` contains an Empty Emitter Marker for UID `000214` with current score `84/88`. `auto-generated/-ag-memory-coverage.md` likewise classifies the row as `emits`, owner/emitter `0000P9`, destination `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`, `Code: no`. After implementation, that marker should be replaced by the helper C++ below.

## Evidence Rechecked

Instruction and assignment sources read:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B004/goal.md`

Target and project routing sources read:

- `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Owner/support documents read:

- `by-file/WebBoardDialog.md`
- `by-class/WebBoardDialogOld.md`
- `by-class/WebBoardDialog.md`
- `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md`
- `by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md`
- `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md`
- `by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md`
- `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`
- `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`
- `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md`
- `by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md`
- `by-file/Browser.md`
- `by-file/BoardDialogs.md`
- `by-file/RankingDialog.md`
- `by-resource/webboard-dialog-resources.md`

Generated/current status sources read:

- `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`
- `project-level/-auto-completion-stats.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `by-memory/-coverage-report.md`
- `auto-generated/by-memory-tool-report.md`
- `project-level/-unresolved.md`
- `project-level/-resolved.md`

Related pending/executed reports read as leads and cross-checks:

- `tools/leaser/Agents/Agent-B006/research/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md`
- `tools/leaser/Agents/Agent-B008/research/0000G3-WebBoardDialogOld-class-source-quality.md`
- `tools/leaser/Agents/Agent-B001/research/executed/older/000210-webboard-render-escape-source-split.md`

Fresh local PE validation was run against three identical copies:

```text
E:\NTK\Resources\NexusTK\NexusTK.exe
C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
size   2679296
MD5    4247e04e20b65d6414c7238aa8ff5515
SHA1   c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a
SHA256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
```

Fresh validator baseline run:

> Executable block R001 was removed from this report and preserved verbatim in [000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md](000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result summary: dry run, `ok: 1`; target UID header accepted. The dry run also rebuilt generated metadata in memory and left generated outputs unchanged because `--apply` was not passed.

## Current Target State

The target currently has:

```text
COMPLETION:84
CONFIDENCE:88
CANONICAL_OWNER:0000P9
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P9
```

The by-memory page already routes to the correct source file owner and is above the code-entry threshold by average score, but its formal C++ block is empty. Its open questions are now narrow enough to document rather than block:

- no direct function/xref/caller evidence to the raw helper entry;
- source-facing name should not remain raw `sub_46EE80`;
- active and old helpers are duplicated twins, not one merged active helper;
- the old state page contains stale `0xff` wording that conflicts with the current BSS-zero PE evidence;
- support names should be normalized so the emitted helper does not carry raw `byte_67ACB0`/`byte_67ACB8` names.

## Binary Facts

Fresh PE mapping confirms:

```text
.text  VA 0x00401000, raw 0x400, raw size 0x20b600
.rdata VA 0x0060d000, raw 0x20ba00, raw size 0x5f200
.data  VA 0x0066d000, raw 0x26ac00, raw size 0xd800, virtual size 0x2fe24
```

Target range:

```text
old helper: 0x0046ee80-0x0046efda, length 0x15a, .text, SHA1 1dba393f40f683e56a02910f9cb03061264b79c8
preceding pad: 0x0046ee7a-0x0046ee80, 6 bytes, cc cc cc cc cc cc
following pad: 0x0046efda-0x0046efe0, 6 bytes, cc cc cc cc cc cc
```

Active twin range:

```text
active helper: 0x0046da70-0x0046dbca, length 0x15a, .text, SHA1 8aae2ff99533ced77a906e2cd4d43e944a3b24fc
```

Support data:

```text
old state:    0x0067acb0-0x0067adb8, length 0x108, .data virtual tail, all zero bytes
active state: 0x0067aba8-0x0067acb0, length 0x108, .data virtual tail, all zero bytes
charsets:     0x0066d430-0x0066d468, length 0x38
```

Charset bytes:

```text
$&+,/:=?@\0\0\0 "<>#%{}|\^~[]`\0$&+,/:=?@\0\0\0 "<>#%{}|\^~[]`\0
```

The local scan found no raw little-endian byte references to the active or old helper entry/tail as absolute VA, RVA, or file offset. It also found no direct `E8`/`E9` rel32, `0F 8x` rel32, short conditional jump, `EB`, or `E3` control-flow edge to:

```text
0x0046ee80
0x0046efda
0x0046da70
0x0046dbca
```

This confirms the current documentation's no-caller/no-pointer caveat and keeps confidence below a fully proven called helper. It does not justify no-code: the helper body is complete, bounded, source-shaped, and routed to the correct file.

## Heuristic And Inference Reanalysis

### Raw Helper Dispatch And Liveness

The helper is not currently proven live by a direct function call. Ghidra/current docs report no function callers/xrefs for the active helper and no proven dispatch path for the old helper. Fresh binary scanning also found no direct pointer/control-flow references to either helper entry or tail. The old response parser at `0x0046eaa0-0x0046ee7a` contains the same old table/charset/`%%%2X` percent-escape logic inline rather than a direct call to `0x0046ee80`.

Accepted interpretation: keep this as a source-local helper or compiler-emitted duplicate whose body is reconstructable, but document that liveness is unresolved. This is a confidence limiter, not an ownership or C++ blocker. Rejected interpretation: mark no-code solely because the helper has no xrefs. That would leave a complete routed reconstructable body as an empty emitter despite clear old WebBoard state/data ownership.

### Source-Facing Helper Name And Signature

Recommended name:

```text
EscapeOldWebBoardUrl
```

Reasoning:

- It distinguishes the old helper from the active twin at `0x0046da70`.
- It matches the actual behavior: URL percent-escape from a source byte span into a destination buffer.
- It avoids raw address/compiler names.
- It keeps the helper file-local under `WebBoardDialog.cpp`, matching [UID:0000P9].

Rejected names:

- `sub_46EE80`: raw and not source-facing.
- `WebBoardDialogOld::EscapeBoardInfo`: there is no `this` pointer evidence, and the helper is a byte-span URL escape routine, not specifically a class method or boardinfo-only operation.
- `BrowserUrlEscape`: Browser owns related browser/runtime concepts, but current docs route WebBoardDialog/WebBoardDialogOld logic to [UID:0000P9], and the active/old duplicated state blocks are WebBoardDialog-coupled.
- `EscapeBoardInfo`: too narrow because the helper only sees bytes/length/capacity and can escape any old WebBoard URL component.

Recommended signature:

```cpp
static char *__cdecl EscapeOldWebBoardUrl(const char *source,
                                          short sourceLength,
                                          char *dest,
                                          short destCapacity);
```

Signature evidence:

- Four stack arguments, no `this` pointer.
- The first argument is read as source bytes.
- The second and fourth arguments are short-sized loop/limit values in the current target evidence.
- The third argument is the output buffer.
- The function null-terminates output and returns the destination pointer.
- `__cdecl` is the conservative raw helper convention absent class/thiscall evidence.

### Active-Versus-Old Split

The active and old helpers are duplicate algorithms with separate state:

```text
active helper      0x0046da70-0x0046dbca
active guard       0x0067aba8
active table       0x0067abb0
active charsets    0x0066d430 / 0x0066d43c

old helper         0x0046ee80-0x0046efda
old guard          0x0067acb0
old table          0x0067acb8
old charsets       0x0066d44c / 0x0066d458
```

The duplicated data and separate state blocks support two file-local helpers, not one shared emitted helper. The active helper should likely be named `EscapeWebBoardUrl`; the old helper should be named `EscapeOldWebBoardUrl`.

### Field, Global, And Helper Names

Recommended source-facing support names:

```cpp
static bool s_webBoardUrlEscapeInitialized;
static unsigned char s_webBoardUrlEscapeTable[256];
static bool s_oldWebBoardUrlEscapeInitialized;
static unsigned char s_oldWebBoardUrlEscapeTable[256];

static const char kWebBoardUrlReservedChars[] = "$&+,/:=?@";
static const char kWebBoardUrlUnsafeChars[] = " \"<>#%{}|\\^~[]`";
static const char kOldWebBoardUrlReservedChars[] = "$&+,/:=?@";
static const char kOldWebBoardUrlUnsafeChars[] = " \"<>#%{}|\\^~[]`";
```

The old state page should not describe image-initialized `0xff` bytes. Current local PE mapping shows the state pages are in the virtual tail of `.data` and initialize to zero. The function then writes `1` into table entries that should be escaped.

### Owner And Source Placement

Accepted owner and emitter:

```text
[UID:0000P9] by-file/WebBoardDialog.md
NexusTK/ui/dialogs/WebBoardDialog.cpp
```

Ranking:

1. [UID:0000P9] `WebBoardDialog.md` - accepted. It is the current canonical owner/emitter, owns the generated destination, and already groups active/old WebBoard dialog logic.
2. [UID:0000G3] `WebBoardDialogOld.md` - class context only. Useful for method notes, but the raw helper has no `this` and should remain file-local under the file owner.
3. [UID:000013] `Browser.md` / browser source - rejected. Charset names are browser-like, but support docs explicitly keep WebBoardDialog/WebBoardDialogOld out of Browser ownership.
4. [UID:0000HT] `BoardDialogs.md` - rejected as too broad. The WebBoard-specific file route is more precise.
5. [UID:0000KA] `RankingDialog.md` - rejected. Current docs already flag WebBoardDialogOld pollution/exclusion there.
6. No-code/no-owner - rejected. The row is reconstructable, routed, and source-shaped; only raw dispatch is unresolved.

### Range And Padding

Keep the exact target range:

```text
0x0046ee80-0x0046efda
```

Do not expand into either padding island:

```text
0x0046ee7a-0x0046ee80
0x0046efda-0x0046efe0
```

Do not trim the target end without live disassembly agreement. The current by-memory row and local PE scan agree that the first bytes after `0x0046efda` are `CC` padding, and the full 0x15a bytes are the currently documented helper allocation.

### First-Draft C++ Readiness

The helper is ready for first-draft C++ because:

- the algorithm is complete and bounded;
- state initialization is clear;
- source/destination/length/capacity roles are clear;
- source owner and generated route are already assigned;
- support data bytes are exact;
- open questions are documented and do not change the emitted algorithm.

Confidence should stop at `90`, not higher, because:

- no direct caller or dispatch site has been found;
- the best source name is inferred from behavior/context, not recovered from symbols;
- support state pages still need stale `0xff` wording corrected.

## Recommended Target C++

Insert this formal C++ into `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`.

```cpp
static bool s_oldWebBoardUrlEscapeInitialized;
static unsigned char s_oldWebBoardUrlEscapeTable[256];

static const char kOldWebBoardUrlReservedChars[] = "$&+,/:=?@";
static const char kOldWebBoardUrlUnsafeChars[] = " \"<>#%{}|\\^~[]`";

static char *__cdecl EscapeOldWebBoardUrl(const char *source,
                                          short sourceLength,
                                          char *dest,
                                          short destCapacity)
{
    if (!s_oldWebBoardUrlEscapeInitialized) {
        for (int ch = 0; ch < 256; ++ch) {
            s_oldWebBoardUrlEscapeTable[ch] =
                (ch < 0x20 || ch >= 0x80) ? 1 : 0;
        }

        for (int i = 0; i < 9; ++i) {
            const unsigned char ch =
                static_cast<unsigned char>(kOldWebBoardUrlReservedChars[i]);
            s_oldWebBoardUrlEscapeTable[ch] = 1;
        }

        for (int i = 0; i < 15; ++i) {
            const unsigned char ch =
                static_cast<unsigned char>(kOldWebBoardUrlUnsafeChars[i]);
            s_oldWebBoardUrlEscapeTable[ch] = 1;
        }

        s_oldWebBoardUrlEscapeInitialized = true;
    }

    short sourceIndex = 0;
    short produced = 0;

    while (sourceIndex < sourceLength && produced < destCapacity - 3) {
        const unsigned char ch =
            static_cast<unsigned char>(source[sourceIndex]);

        if (s_oldWebBoardUrlEscapeTable[ch] == 1) {
            sprintf_s(dest + produced,
                      destCapacity - produced,
                      "%%%2X",
                      static_cast<unsigned int>(ch));
            produced += 3;
        } else {
            dest[produced++] = static_cast<char>(ch);
        }

        ++sourceIndex;
    }

    dest[produced] = '\0';
    return dest;
}
```

Range-boundary note for implementation: the four file-static support declarations model bytes documented by [UID:000278] and [UID:0002AH]. To avoid duplicate output, leave those support pages' formal C++ blank during this helper-first implementation unless the supervisor chooses a coordinated support-data emission pass. If support-data pages later emit the declarations themselves, remove the duplicate declarations from this helper block and keep only the function body plus forward declarations as needed by generated ordering.

## Exact Target Page Changes To Apply

In `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`:

1. Change `COMPLETION` from `84` to `88`.
2. Change `CONFIDENCE` from `88` to `90`.
3. Keep `CANONICAL_OWNER:0000P9`.
4. Keep `RECONSTRUCTABLE:TRUE`.
5. Keep `EMITTER_UIDS:0000P9`.
6. Update the source-facing name in prose from raw/helper wording to `EscapeOldWebBoardUrl`.
7. Replace unresolved/no-code wording with: first-draft C++ is recommended; raw dispatch remains unresolved and is the primary confidence limiter.
8. Add the C++ block above.
9. Add explicit state/data names:
   - `s_oldWebBoardUrlEscapeInitialized`
   - `s_oldWebBoardUrlEscapeTable`
   - `kOldWebBoardUrlReservedChars`
   - `kOldWebBoardUrlUnsafeChars`
10. Add local-PE evidence that both active and old escape-state pages are BSS-zero initialized, not `0xff` initialized.
11. Preserve the exact range `0x0046ee80-0x0046efda` and note the `CC` padding before and after.

## Support-Doc Changes To Apply

### `by-file/WebBoardDialog.md`

Recommended changes:

- Keep file owner score `88/90`.
- Keep [UID:000214] routed to this file.
- Update the UID `000214` row/note to say:

```text
[UID:000214] is the file-local old WebBoard URL percent-escape helper `EscapeOldWebBoardUrl`, using the old state at 0x0067acb0/0x0067acb8 and old duplicated URL character sets at 0x0066d44c/0x0066d458. It has no proven direct caller, but emits beside the old response parser in WebBoardDialog.cpp.
```

- Note that `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` should stop showing UID `000214` as an Empty Emitter Marker after implementation.

### `by-class/WebBoardDialogOld.md`

Recommended changes:

- Keep class context score `88/85`.
- Keep `CANONICAL_OWNER:0000P9` and `EMITTER_UIDS:0000P9`.
- Update the method/helper inventory row for `0x0046ee80-0x0046efda` to:

```text
0x0046ee80-0x0046efda | EscapeOldWebBoardUrl | file-local old URL percent-escape helper; no this pointer; uses old state/table and old duplicated charsets; no direct caller found.
```

- Explicitly state this is context for `WebBoardDialogOld`, not proof of a `WebBoardDialogOld::` member function.

### `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md`

Recommended changes:

- Keep `COMPLETION:86`, `CONFIDENCE:90`, owner/emitter `0000P9` unless a separate owner pass changes the old parser.
- Add a note that the old response parser contains inline percent-escape logic matching `EscapeOldWebBoardUrl` but current xref/PE scans do not show a call to `0x0046ee80`.
- Use the same support names:
  - `s_oldWebBoardUrlEscapeInitialized`
  - `s_oldWebBoardUrlEscapeTable`
  - `kOldWebBoardUrlReservedChars`
  - `kOldWebBoardUrlUnsafeChars`
- Preserve its current C++ readiness separately; this report only promotes the helper.

### `by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md`

Recommended changes:

- Add a mirror note that the active response parser corresponds to the active helper/state pair, not the old pair.
- If naming is touched, use `EscapeWebBoardUrl` for the active helper counterpart and reserve `EscapeOldWebBoardUrl` for UID `000214`.

### `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md`

Recommended changes:

- Keep active helper separate from UID `000214`.
- Prefer source-facing name `EscapeWebBoardUrl`.
- Add a cross-reference note:

```text
Active twin of [UID:000214] `EscapeOldWebBoardUrl`; same algorithm, separate active guard/table and active duplicated charset pair. Current evidence likewise does not prove a direct caller.
```

### `by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md`

Recommended changes:

- Do not merge active and old helpers into this split index.
- Clarify that its active URL helper child is the active counterpart only; UID `000214` is the old helper outside this split range.
- Keep its non-reconstructable split-index role.

### `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`

Recommended changes:

- Keep owner/emitter `0000P9`.
- Add/normalize names:

```text
0x0066d430 kWebBoardUrlReservedChars
0x0066d43c kWebBoardUrlUnsafeChars
0x0066d44c kOldWebBoardUrlReservedChars
0x0066d458 kOldWebBoardUrlUnsafeChars
```

- State that old xrefs are from `0x0046eaa0` inline logic and `0x0046ee80` helper logic.
- If formal C++ remains blank, document that the first helper implementation emits the old declarations as local source context to avoid generated-order duplicates.

### `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`

Recommended changes:

- Correct stale `0xff` image-initialized wording. The current PE mapping shows this page is BSS/virtual `.data` and initializes to zero.
- Normalize names:

```text
0x0067acb0 s_oldWebBoardUrlEscapeInitialized
0x0067acb8 s_oldWebBoardUrlEscapeTable
```

- Correct the support link that currently points at `[UID:0001OD] BrowserAlertStrings`; it should point at `[UID:000278] BrowserUrlEscapeCharacterSets`.
- Add a note that the helper writes `1` into entries for control/high bytes and duplicated old reserved/unsafe characters.

### `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md`

Recommended changes:

- Keep active state separate from old state.
- If the stale change-log line still says `0xff`, replace it with BSS-zero wording for consistency.
- Normalize names:

```text
0x0067aba8 s_webBoardUrlEscapeInitialized
0x0067abb0 s_webBoardUrlEscapeTable
```

### `by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md`

Recommended changes:

- Add a support note that the literal `"%%%2X"` is used by WebBoard URL escaping and is intentionally not rewritten to `"%02X"`.
- Keep its non-reconstructable mixed-data/index role.

### `by-file/Browser.md`

No metadata change recommended. Add only if touching nearby text:

```text
Browser URL character terminology supports the WebBoard URL escape helpers, but ownership for active/old WebBoard escape state and helpers remains [UID:0000P9] WebBoardDialog.cpp.
```

### `by-file/BoardDialogs.md`

No metadata change recommended. Add only if touching nearby text:

```text
WebBoardDialog URL escaping is tracked under [UID:0000P9], not the broader BoardDialogs.cpp bucket.
```

### `by-file/RankingDialog.md`

No change required. Its existing WebBoardDialogOld pollution/exclusion remains correct.

### `by-resource/webboard-dialog-resources.md`

No change required for this helper. The fixed-art old resource context supports WebBoardDialogOld ownership but does not affect URL escape code.

## Exact Supervisor-Owned Coverage Row

Do not edit `by-memory/-coverage-report.md` in the B-agent report pass. If the supervisor accepts this recommendation, replace the current UID `000214` row with:

```text
    - [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) 0x0046ee80-0x0046efda | function/local helper | EscapeOldWebBoardUrl : reconstructable : 88% : strong : Old WebBoard URL percent-escape helper: lazily initializes the old 0x0067acb0/0x0067acb8 escape state from duplicated old URL character sets at 0x0066d44c/0x0066d458, escapes control/high/reserved/unsafe bytes with the legacy %%%2X format, copies safe bytes until the dest-capacity-minus-three guard, null-terminates, and returns the destination buffer; current Ghidra/local PE evidence finds no direct caller or pointer reference, so it emits as a file-local WebBoardDialog.cpp helper with raw-dispatch caveat.
```

Keep placement between the surrounding padding rows:

```text
0x0046ee7a-0x0046ee80
0x0046ee80-0x0046efda
0x0046efda-0x0046efe0
```

## IDA Naming Recommendations

If a supervisor or IDA-owning agent applies database names, use:

```text
0x0046ee80 EscapeOldWebBoardUrl
0x0046da70 EscapeWebBoardUrl
0x0067acb0 s_oldWebBoardUrlEscapeInitialized
0x0067acb8 s_oldWebBoardUrlEscapeTable
0x0067aba8 s_webBoardUrlEscapeInitialized
0x0067abb0 s_webBoardUrlEscapeTable
0x0066d430 kWebBoardUrlReservedChars
0x0066d43c kWebBoardUrlUnsafeChars
0x0066d44c kOldWebBoardUrlReservedChars
0x0066d458 kOldWebBoardUrlUnsafeChars
```

Recommended repeatable comments:

```text
0x0046ee80: Old WebBoard URL percent-escape helper. No direct caller found in current Ghidra/local PE scans; old response parser contains matching inline logic.
0x0067acb0: BSS-zero guard for old WebBoard URL escape table initialization.
0x0067acb8: 256-byte old WebBoard URL escape table; entries set to 1 for bytes that must be percent-escaped.
```

## Validator Commands After Implementation

Run these after applying accepted by-* changes:

> Executable block R002 was removed from this report and preserved verbatim in [000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md](000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage-row wording:

> Executable block R003 was removed from this report and preserved verbatim in [000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md](000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-generation checks:

> Executable block R004 was removed from this report and preserved verbatim in [000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md](000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result after accepted implementation:

- `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` contains `EscapeOldWebBoardUrl`.
- UID `000214` no longer appears as an Empty Emitter Marker in that file.
- `auto-generated/-ag-memory-coverage.md` still routes UID `000214` to owner/emitter `0000P9`, destination `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`, but changes `Code` from `no` to `yes`.
- `project-level/-auto-completion-stats.md` should no longer list UID `000214` in `Low_Completion_Reconstructable`.

## Implementation Checklist

For a later supervisor-approved implementation pass:

1. Open `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`.
2. Update metadata to `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged.
3. Replace raw-name prose with `EscapeOldWebBoardUrl` and add the raw-dispatch caveat.
4. Insert the C++ block from this report.
5. Ensure the page still documents exact range `0x0046ee80-0x0046efda` and padding on both sides.
6. Update `by-file/WebBoardDialog.md` with the file-local helper note and generated marker expectation.
7. Update `by-class/WebBoardDialogOld.md` with a context/helper row, not a member-method claim.
8. Update old and active response/helper docs with active-vs-old split notes and consistent helper names.
9. Update `BrowserUrlEscapeCharacterSets.md` with active/old charset names and xref roles.
10. Correct `WebBoardDialogOldUrlEscapeState.md` BSS-zero wording, names, and wrong charset support link.
11. Mirror active state names in `WebBoardDialogUrlEscapeState.md` and remove stale `0xff` wording if present.
12. Add the `%%%2X` support note to `BoardMailReadOnlyData.md`.
13. Leave `RankingDialog.md` and `webboard-dialog-resources.md` unchanged unless nearby text is already being touched.
14. Do not edit `by-memory/-coverage-report.md` unless acting as supervisor; if acting as supervisor, use the exact coverage row above.
15. Run the validator commands listed above.
16. Inspect `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` and generated coverage/stats for the expected post-generation changes.

## Residual Risks

- Direct runtime dispatch remains unresolved. If a future IDA/live-debug pass finds an indirect caller, update the target and old parser support docs, and confidence can likely move above `90`.
- The helper may represent a source inline clone rather than a manually called function. The recommended file-local helper is still source-facing and preserves behavior without pretending it is a class method.
- The C++ block includes file-static support declarations for helper-first generated readability. If a later support-data emission pass moves those declarations into [UID:000278] or [UID:0002AH], remove duplicates from UID `000214`.

## Report Pass Result

No by-* or generated files were changed in this pass. This refreshed report now contains the exact metadata, owner/emitter, C++, support-doc, coverage-row, validator, and implementation-checklist recommendations needed for supervisor review.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"000214"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000214"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
