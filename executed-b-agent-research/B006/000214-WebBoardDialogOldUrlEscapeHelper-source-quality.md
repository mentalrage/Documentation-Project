** TARGET-REPORT-UID:000214 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000214 WebBoardDialogOldUrlEscapeHelper Source-Quality Report

Agent: B006  
Assignment: `B006-goal2-webboarddialogold-url-escape-helper-source-quality-000214-20260619`  
Target UID: [UID:000214]  
Target path: `source-3/project-documentation/by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`  
Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md`  
Status: report-only; no by-* docs, generated files, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Executive Decision

The target should be treated as a reconstructable, source-authored, file-local helper retained in the old WebBoard dialog source neighborhood, not as padding, compiler glue, a vtable callback, or a live dispatcher entry. The current binary has no direct call, jump, absolute VA pointer, or Ghidra/IDA caller route to `0x0046ee80`, but the body is a complete 346-byte helper with normal prologue/epilogue, a clear four-argument cdecl signature, stable old URL-escape state refs, and behavior duplicated inline by the preceding old response parser.

Recommended source-facing helper name: `EscapeOldWebBoardUrl`.  
Recommended signature:

```cpp
static char *__cdecl EscapeOldWebBoardUrl(const char *source,
                                          short sourceLength,
                                          char *dest,
                                          short destCapacity);
```

`EscapeBoardInfo` is rejected as too narrow because the helper accepts an arbitrary source pointer and length and has no direct `boardinfo` string reference; the only currently documented semantic use is board-info cookie escaping, but the helper itself is a generic old-variant byte URL-escape routine. A shared active/old parameterized helper is also rejected for the binary-level target because the active and old helpers are emitted as two separate clone bodies with hard-coded active or old guard/table/charset references.

Recommended metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000P9
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P9
```

The formal C++ block should no longer stay blank. The target clears the active code-entry gate `(84 + 88) / 2 = 86`, the behavior is source-authored and reconstructable, and the no-direct-caller state is now a documented liveness fact rather than a C++ blocker.

## Evidence Checked

- `Agent-B006/goal.md`, `tools/leaser/Agents/Supervisor.md`, and `.codex/AGENTS.md` were read for report-only rules, heuristic/source-quality obligations, code-entry gate, and coverage-row handling.
- Target doc `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`.
- Old response parser [UID:0000ZD] `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md`.
- Active response parser [UID:0000Z9] `by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md`.
- Active raw helper [UID:0003V1] `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md`.
- Split parent [UID:000210] `by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md`.
- Charset data [UID:000278] `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`.
- Active URL state [UID:0002AG] `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md`.
- Old URL state [UID:0002AH] `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`.
- File/class routes: `by-file/WebBoardDialog.md`, `by-class/WebBoardDialogOld.md`, `by-class/WebBoardDialog.md`, and `by-file/BoardDialogs.md`.
- Read-only data/resource pages: `by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md`, `by-resource/webboard-dialog-resources.md`.
- Formatter/runtime page: `by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md`.
- Ghidra exports: `resources/exported_data/functions/0x0046ee80.json` and `resources/exported_data/functions/0x0046da70.json`.
- Manual coverage context: `by-memory/-coverage-report.md` rows around the target and `by-memory/-ignored.md` padding entries around `0x0046ee7a-0x0046ee80` and `0x0046efda-0x0046efe0`.
- Raw PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, using BSS-aware VA mapping.

## Heuristic / Inference Reanalysis And Validation

### Boundary And Range

The exact helper body is `0x0046ee80-0x0046efda`, size `0x15a` / 346 bytes. Ghidra models it as `FUN_0046ee80`; IDA docs continue to report no modeled function object at the entry. The range is still a valid code body despite IDA's missing function metadata.

Boundary evidence:

- `0x0046ee7a-0x0046ee80` is six bytes of `0xcc` padding after modeled old response parser `sub_46EAA0`.
- `0x0046ee80` starts `55 8B EC 51 80 3D B0 AC 67 00 00`, a normal frame-pointer prologue plus guard check against `0x0067acb0`.
- `0x0046efda-0x0046efe0` is six bytes of `0xcc` padding.
- `0x0046efe0` begins the successor AutoInit non-deleting destructor body, not a continuation of this helper.

The current padding docs in `by-memory/-ignored.md` are correct and do not need content changes.

### Raw Liveness And Dispatch Route

Direct route checks remain negative:

- IDA documentation records no function object and no direct xrefs to `0x0046ee80`.
- Ghidra export records `num_callers: 0` for `FUN_0046ee80`.
- BSS-aware PE scan found no absolute dword pattern for `0x0046ee80`, no absolute dword pattern for the tail `0x0046efda`, and no absolute dword pattern for active helper `0x0046da70`.
- Rel32 scan of `.text` found no `E8` call and no `E9` jump to `0x0046ee80`.
- The same rel32 scan found no `E8` call and no `E9` jump to active helper `0x0046da70`, while it did find the expected modeled response-handler routes:
  - `0x0046eaa0`: `E8=0x0046e850`, `E9=0x0046ea1e`.
  - `0x0046d580`: `E8=0x0046d2a6`, `E9=0x0046d49e`.

Positive reference evidence is inside the body, not to the entry:

- Old guard `0x0067acb0` absolute refs: `0x0046ec29`, `0x0046ecf6`, `0x0046ee86`, `0x0046ef56`.
- Old table `0x0067acb8` absolute refs: 24 hits from the old response parser and raw helper, including `0x0046ec50` through `0x0046ed30` and `0x0046eeb1` through `0x0046ef8b`.
- Old first charset `0x0066d44c` refs: `0x0046ec5f`, `0x0046eec0`.
- Old second charset `0x0066d458` refs: `0x0046ece3`, `0x0046ef43`.
- Percent-format literal `0x00613adc` refs: `0x0046d83b`, `0x0046db88`, `0x0046ed4b`, `0x0046ef98`.

Conclusion: there is no live dispatch route to the raw helper in the current binary. This is best documented as a retained file-local helper / out-of-line clone. It is not dead padding because it is valid source-shaped code with stable state/string/data references. It is not a callback because there is no vtable/table/pointer entry. It is not compiler glue because the body has project-specific URL escaping, charset data, cookie/board helper state, and a normal cdecl helper signature.

### Relationship To The Preceding Old Response Parser

[UID:0000ZD] `WebBoardDialogOld::HandleWebBoardResponse` at `0x0046eaa0-0x0046ee7a` contains the live runtime route. Its direct callers are the old constructor at `0x0046e850` and old packet forwarder at `0x0046ea1e`. The parser initializes the same old escape table at `0x0067acb0/0x0067acb8`, reads the same old character-set literals at `0x0066d44c/0x0066d458`, calls the same `_sprintf_s`-style formatter through `0x00443a00`, uses the same `%%%2X` literal at `0x00613adc`, and then sets the `boardinfo` cookie.

That parser does not call `0x0046ee80`. It carries an inline clone of the same escape logic. The raw helper following the parser is therefore most likely an out-of-line source helper that the compiler retained even though the live old response path inlined or duplicated its logic. This is the same pattern as the active helper at `0x0046da70`: active parser has the live inline path, active raw helper is source-shaped but has no caller.

### Active-Versus-Old Split

The active and old URL-escape implementations should remain separate in documentation and first-draft source:

| Variant | Helper | Guard | Table | First charset | Second charset |
| --- | --- | --- | --- | --- | --- |
| Active | `0x0046da70-0x0046dbca` | `0x0067aba8` | `0x0067abb0` | `0x0066d430` | `0x0066d43c` |
| Old | `0x0046ee80-0x0046efda` | `0x0067acb0` | `0x0067acb8` | `0x0066d44c` | `0x0066d458` |

The two helper bodies have the same 346-byte Ghidra size and same signature shape but hard-code different state and character-set addresses. This rejects a shared active/old parameterized helper as the correct binary target shape. A future human source cleanup could factor them, but the by-memory reconstruction should preserve the two emitted bodies.

### Character Sets And Table Initialization

Old first character set at `0x0066d44c-0x0066d458`:

```text
24 26 2B 2C 2F 3A 3D 3F 40 00 00 00
$  &  +  ,  /  :  =  ?  @
```

Old second character set at `0x0066d458-0x0066d468`:

```text
20 22 3C 3E 23 25 7B 7D 7C 5C 5E 7E 5B 5D 60 00
space " < > # % { } | \ ^ ~ [ ] `
```

Initialization first marks bytes `0x20..0x7f` as safe and all other byte values as escaped. It then marks all bytes from the two old character-set arrays as escaped. The first group is emitted as nine direct stores; the second group is emitted as a 15-iteration loop. The first group has three trailing zero/alignment bytes in rdata and should be modeled as a fixed string/array of nine characters, not a loop over twelve bytes.

Recommended names:

- `kOldWebBoardUrlReservedChars` for `$&+,/:=?@`.
- `kOldWebBoardUrlUnsafeChars` for ` " <>#%{}|\\^~[]\``.
- Active counterparts: `kWebBoardUrlReservedChars` and `kWebBoardUrlUnsafeChars`.

### State Globals And Initialization Value

Recommended names:

- `byte_67ACB0` -> `s_oldWebBoardUrlEscapeInitialized`.
- `byte_67ACB8` -> `s_oldWebBoardUrlEscapeTable`.
- Active counterparts:
  - `byte_67ABA8` -> `s_webBoardUrlEscapeInitialized`.
  - `byte_67ABB0` -> `s_webBoardUrlEscapeTable`.

BSS-aware PE evidence should replace the stale/contradictory old-state notes that say this area is image-initialized as `0xff`. The file section map is:

```text
.data VA=0x0066d000 VSize=0x2fe24 rawSize=0xd800
```

The `.data` raw payload ends at VA `0x0067a800`; both active state `0x0067aba8` and old state `0x0067acb0` are after that raw payload but inside `.data` virtual size. Loader semantics therefore zero-initialize these bytes. The BSS-aware byte scan returns zeros for `0x0067aba8`, `0x0067abb0`, `0x0067acb0`, and `0x0067acb8`.

This matches the code's guard check: if the guard were initially `0xff`, the table initialization would be skipped and the table would not have the documented seeded values. The best-supported conclusion is that both state blocks are zero-initialized BSS static storage.

### Formatter Helper

`sub_443A00` should be named `_sprintf_s` / `sprintf_s` in this context. Ghidra names callee `0x00443a00` `_sprintf_s`, and the runtime support page classifies `sub_443990`, `sub_4439C0`, `sub_443A00`, and `sub_443A30` as local stdio/printf/scanf wrappers. Other docs use `sub_443A00` for bounded narrow formatting.

The exact format string is `%%%2X`, not `%02X`. The output is a literal percent sign plus uppercase hex with width 2. Existing prose that says `%XX` is acceptable shorthand, but target/support docs should preserve `%%%2X` when describing exact behavior. If source draft comments mention zero-padding, that would be wrong.

### Argument Widths, Return Type, And Bounds

Ghidra signature:

```text
int __cdecl FUN_0046ee80(int param_1, short param_2, int param_3, short param_4)
```

Best source-quality signature:

```cpp
static char *__cdecl EscapeOldWebBoardUrl(const char *source,
                                          short sourceLength,
                                          char *dest,
                                          short destCapacity);
```

Rationale:

- The return value is the original destination pointer `param_3`, so `char *` is better than `int`.
- `param_1` is read byte-wise as input; `const char *` or `const unsigned char *` are both defensible. Use `const char *` for source style and cast each byte to `unsigned char` before table indexing.
- `param_2` and `param_4` are used as signed 16-bit values in Ghidra output and short counters drive the input/output loop; use `short` for first-draft fidelity.
- The helper treats `sourceLength <= 0` as empty output and does no source null check.
- The helper checks `destCapacity - 3 <= produced` before every input byte, so it stops when it cannot reserve room for a potential three-byte escape. This also prevents copying additional safe bytes once fewer than four nominal bytes remain.
- It null-terminates `dest[produced]` and returns `dest`.
- The function assumes the caller gives a valid non-null destination with room for at least the final NUL.

### Source Placement And Ownership

Keep `CANONICAL_OWNER:0000P9` and `EMITTER_UIDS:0000P9`.

The helper is old-variant-specific, but it has no `this` pointer and no class-method route. It should be documented as a file-local helper in `ui/dialogs/WebBoardDialog.cpp`, used by or duplicated beside the `WebBoardDialogOld` response parsing family. The `by-class/WebBoardDialogOld.md` page should list it as an old-class-family file-local helper, but it should not become a static class method unless later source evidence proves that original declaration style.

Rejected owner alternatives:

- `WebBoardDialogOld` direct class owner: rejected as direct owner because there is no `this`, vtable slot, class static proof, or caller route. It remains the semantic old-dialog family.
- `WebBoardDialog` active class owner: rejected because this helper uses the old state block and old charsets.
- `Browser` / `BrowserControlPane`: rejected because the state, parser, cookies, and board response flow are WebBoard-specific.
- `BoardDialogs`: only a broader feature bucket; the file route is already `WebBoardDialog.cpp`.
- `RankingDialog`: generated-output pollution; old WebBoard helpers appear in `class_RankingDialog.cpp` but vtables, singleton, resources, and parser evidence route to WebBoardDialogOld.
- Compiler-generated/no-code: rejected because the body is project-specific source behavior, not destructor/thunk/template glue.

### First-Draft C++ Readiness

First-draft C++ is appropriate for this target. The only unresolved fact is the exact original symbol spelling, and the report provides a defensible source-facing name. The no-direct-caller state should be documented in prose, not used to keep the formal C++ blank.

Recommended formal C++:

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
                (ch >= 0x20 && ch < 0x80) ? 0 : 1;
        }

        for (int i = 0; i < 9; ++i) {
            s_oldWebBoardUrlEscapeTable[kOldWebBoardUrlReservedChars[i]] = 1;
        }

        for (int i = 0; i < 15; ++i) {
            s_oldWebBoardUrlEscapeTable[kOldWebBoardUrlUnsafeChars[i]] = 1;
        }

        s_oldWebBoardUrlEscapeInitialized = true;
    }

    short sourceIndex = 0;
    short produced = 0;

    while (sourceIndex < sourceLength) {
        if (destCapacity - 3 <= produced) {
            break;
        }

        const unsigned char ch =
            static_cast<unsigned char>(source[sourceIndex]);

        if (s_oldWebBoardUrlEscapeTable[ch] == 1) {
            sprintf_s(dest + produced, destCapacity - produced, "%%%2X", ch);
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

Implementation note: the target page should state that this is a retained no-direct-caller helper and that the live old parser currently inlines/duplicates the same behavior. The C++ block should not claim a proven direct call from `HandleWebBoardResponse`.

## Recommended Target Doc Changes

Update `source-3/project-documentation/by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`:

- Set `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter `0000P9`; keep reconstructable true.
- Change entity kind/disposition from a vague raw class/string helper to `raw file-local helper`.
- Add the recommended source name/signature:
  - `EscapeOldWebBoardUrl(const char *source, short sourceLength, char *dest, short destCapacity) -> char *`.
- Add exact boundary evidence:
  - predecessor padding `0x0046ee7a-0x0046ee80`;
  - helper body `0x0046ee80-0x0046efda`;
  - successor padding `0x0046efda-0x0046efe0`;
  - successor `AutoInitNonDeletingDestructor` at `0x0046efe0`.
- Replace passive "dispatch unresolved" language with a resolved liveness statement:
  - no function object in IDA;
  - Ghidra models complete 346-byte function;
  - no direct callers in Ghidra;
  - no rel32 call/jump and no absolute VA pointer route to `0x0046ee80`;
  - old parser duplicates/inlines the same escape logic.
- Document active/old split and reject a shared parameterized helper for by-memory reconstruction.
- Document old state variables with source-facing names:
  - `s_oldWebBoardUrlEscapeInitialized`;
  - `s_oldWebBoardUrlEscapeTable`.
- Document old charset names:
  - `kOldWebBoardUrlReservedChars`;
  - `kOldWebBoardUrlUnsafeChars`.
- Correct state initialization to zero/BSS static storage.
- State that `sub_443A00` is `_sprintf_s` / `sprintf_s` and preserve exact format `%%%2X`.
- Add first-draft C++ above.

## Recommended Support Doc Changes

Update `by-file/WebBoardDialog.md`:

- In the old-variant row, replace "raw old URL escape helper" caveat with: retained no-direct-caller file-local helper `EscapeOldWebBoardUrl`, emitted as source-authored helper under `WebBoardDialog.cpp`; the live old response parser duplicates/inlines the same escape behavior.
- Add that B006 2026-06-19 resolved helper name/signature, state names, BSS initialization, and C++ readiness for [UID:000214].
- Keep generated `RankingDialog` pollution rejection unchanged.

Update `by-class/WebBoardDialogOld.md`:

- Change method note row from generic "old URL escape helper" to file-local helper `EscapeOldWebBoardUrl`.
- Clarify it is not a `thiscall` class method and has no direct caller route; it belongs to the old class family by state/charset/parser adjacency.
- Add the inline-clone relationship to `WebBoardDialogOld::HandleWebBoardResponse`.
- Do not add it to a class declaration as a normal virtual or instance method.

Update `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md`:

- Add a short note that the parser contains the live inline escape path using old guard/table/charsets and does not call [UID:000214].
- Link the helper name `EscapeOldWebBoardUrl` as the retained out-of-line clone/source helper.
- Preserve existing caller/cookie/navigation facts.

Update `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md`:

- Add comparison note only: active counterpart is high-probability `EscapeWebBoardUrl`, with active guard/table/charset refs and the same no-direct-caller retained-helper status.
- Do not force active-helper C++ from this 000214 callback unless the supervisor explicitly adds it; this report only proves the naming pattern needed for comparison.

Update `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`:

- Replace "final helper names unresolved" for the old pair with high-probability names:
  - active: `kWebBoardUrlReservedChars`, `kWebBoardUrlUnsafeChars`;
  - old: `kOldWebBoardUrlReservedChars`, `kOldWebBoardUrlUnsafeChars`.
- Keep active/old table split and exact bytes unchanged.
- Preserve the rejected shared-helper/Browser ownership notes.

Update `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`:

- Rename roles to `s_oldWebBoardUrlEscapeInitialized` and `s_oldWebBoardUrlEscapeTable`.
- Correct stale image-initialized `0xff` wording to BSS zero-initialized static storage. The section raw payload ends at `0x0067a800`; this state range is beyond raw bytes and within `.data` virtual size.
- Change cross-reference currently pointing to `BrowserAlertStrings` for URL escape character data to [UID:000278] `BrowserUrlEscapeCharacterSets` if still present during implementation.

Update `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md`:

- Optional mirror naming for active state: `s_webBoardUrlEscapeInitialized`, `s_webBoardUrlEscapeTable`.
- The current body already records zero-initialized storage; keep that direction.

Update `by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md`:

- Keep `%%%2X` literal; optionally add that both active and old URL helpers use this exact width-2 uppercase hex format via `_sprintf_s`.

Update `by-file/BoardDialogs.md`:

- Replace old raw-helper caveat with the resolved statement that `0x0046ee80-0x0046efda` is a retained WebBoardDialogOld file-local URL escape helper with no direct caller route but source-ready behavior.

No change recommended for `by-memory/-ignored.md`; both adjacent padding entries are already correct.

## Exact Coverage Row Text

Do not edit `by-memory/-coverage-report.md` during report review. If the supervisor accepts the target update, replace only the [UID:000214] row with:

```markdown
    - [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) 0x0046ee80-0x0046efda | raw file-local helper | WebBoardDialogOldUrlEscapeHelper : reconstructable : 88% : very strong : B006 2026-06-19 resolves the retained file-local `EscapeOldWebBoardUrl` helper: exact padding-bounded 346-byte raw/Ghidra function, no direct rel32 call/jump or VA pointer route, old response parser inline-clone relationship, BSS-zero old guard/table state at `0x0067acb0`/`0x0067acb8`, old character-set refs, `_sprintf_s` `%%%2X` bounded escape loop, null termination, and first-draft C++ ready under `WebBoardDialog.cpp`.
```

Placement context: keep it between the existing padding row for `0x0046ee7a-0x0046ee80` and the existing padding row for `0x0046efda-0x0046efe0`.

No coverage-row change is required for the padding rows. If the supervisor also updates old state wording, the existing [UID:0002AH] row can remain at `86% : strong`; its current coverage text does not explicitly repeat the stale `0xff` claim.

## IDA Rename, Type, And Comment Recommendations

These are recommendations only; no IDA edits were made.

- Create/force an IDA function at `0x0046ee80-0x0046efda` if IDA still lacks one.
- Rename function:
  - Preferred: `EscapeOldWebBoardUrl`.
  - Acceptable if IDA naming policy requires address suffix: `EscapeOldWebBoardUrl_0046EE80`.
- Apply type:

```cpp
char *__cdecl EscapeOldWebBoardUrl(const char *source,
                                   short sourceLength,
                                   char *dest,
                                   short destCapacity);
```

- Rename/comment globals:
  - `byte_67ACB0` -> `s_oldWebBoardUrlEscapeInitialized` (`bool` / `unsigned char` guard).
  - `byte_67ACB8` -> `s_oldWebBoardUrlEscapeTable` (`unsigned char[256]`).
  - `byte_66D44C` -> `kOldWebBoardUrlReservedChars`.
  - `byte_66D458` -> `kOldWebBoardUrlUnsafeChars`.
- Rename/comment active counterparts when touched:
  - `byte_67ABA8` -> `s_webBoardUrlEscapeInitialized`.
  - `byte_67ABB0` -> `s_webBoardUrlEscapeTable`.
  - `byte_66D430` -> `kWebBoardUrlReservedChars`.
  - `byte_66D43C` -> `kWebBoardUrlUnsafeChars`.
- Prefer `_sprintf_s` / `sprintf_s` for `sub_443A00`; the runtime-support docs and Ghidra export already support that role.
- Add function comment:
  - "Retained no-direct-caller old WebBoard URL escape helper; old response parser at `0x0046eaa0` duplicates/inlines this behavior. Uses BSS-zero old guard/table state and `%%%2X` `_sprintf_s` formatting."

## Rejected Alternatives

- `EscapeBoardInfo`: rejected as the final helper name because the function is generic over input pointer/length/destination/capacity and has no direct `boardinfo` ref. The boardinfo cookie path is the known semantic consumer, not the helper's whole type.
- Shared parameterized active/old helper: rejected for this by-memory target because active and old helpers are distinct emitted clone bodies with hard-coded state/charset addresses.
- `WebBoardDialogOld::EscapeOldWebBoardUrl` static class method: possible but not best-supported. There is no class `this`, no caller, no decorated-name evidence, and current docs consistently route raw URL helpers at file level.
- Browser-owned URL escape helper: rejected because all state/data/parser evidence is WebBoard-specific.
- Dead/no-code: rejected because the body is valid source-shaped project code, not padding or compiler glue. "No direct caller" should be documented as liveness state, not used to suppress C++.
- Zero-padding `%02X`: rejected because the exact format literal is `%%%2X`.
- State initialized to `0xff`: rejected as stale or non-BSS-aware evidence. PE section mapping shows active and old state blocks are loader-zeroed BSS, and the guard logic requires zero initialization.

## Implementation Checklist For Supervisor Callback

If accepted, implementation should:

1. Edit target `by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md`.
2. Apply metadata `88/90`, keep owner/emitter `0000P9`, keep reconstructable true.
3. Insert liveness conclusion, source name/signature, active/old split, state/charset names, `_sprintf_s` formatter role, BSS-zero initialization correction, and first-draft C++.
4. Update support docs listed above, especially `by-file/WebBoardDialog.md`, `by-class/WebBoardDialogOld.md`, old parser doc, charset doc, and old state doc.
5. Do not convert the helper into a `WebBoardDialogOld` instance method.
6. Do not edit `by-memory/-coverage-report.md` as an agent; supervisor applies the exact replacement row above.
7. Run scoped validator file mode after edits.

## Validation Commands

Recommended validation from `source-3/project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md](000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row:

> Executable block R002 was removed from this report and preserved verbatim in [000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md](000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result for each validator run: `ok: 1`; any reported unrelated stale registry item should be recorded but should not block this target if the edited file validates.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"000214"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000214-WebBoardDialogOldUrlEscapeHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000214"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
