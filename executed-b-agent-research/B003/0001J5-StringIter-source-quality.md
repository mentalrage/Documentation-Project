** TARGET-REPORT-UID:0001J5 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B003 Source-Quality Report: [UID:0001J5] StringIter

Status: FINISHED report-only. No by-* documentation files and no `by-memory/-coverage-report.md` edits were made.

## Target

- Primary target: `source-3/project-documentation/by-memory/0x00584d80-0x00584e9e.StringIter.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0001J5-StringIter-source-quality.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000OB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OB`
- Recommended target metadata: `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000OB`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OB`

## Executive Recommendation

[UID:0001J5] should no longer be blocked by the stale "90/90+" C++ policy. The active gate is cleared and this range has enough direct byte, vtable, caller, and support-document evidence for first-draft source C++.

Recommended source shape:

- `StringIter` is the final source-facing class name. This is supported by the preserved RTTI/vtable name in `.rdata`, existing class documentation, and live text-helper use.
- Use `m_data`, `m_length`, and `m_position` as the field names. These already match historical generated metadata and the class support page, and they fit the byte-level layout without implying ownership of a `SimpleUString` or `StringBase`.
- Keep [UID:0000OB] `StringUtil` as direct source file/emitter route. Do not move this to [UID:0000OA] `StringBase`, [UID:0000D9] `SimpleUString`, or [UID:0000KV] `LObject`.
- Treat `0x00584dc0`, `0x00584e00`, and `0x00584e30` as retained out-of-line source methods with no live direct call route in the current executable. They should be named and reconstructed, not left as passive raw blockers.
- Treat `0x00584e60` as compiler-generated scalar deleting destructor glue. Do not write a human source method for it. The source-authored item is `StringIter::~StringIter()`.

## Evidence Checked

Repository documents checked:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-project-structure/by-structure.md`
- `source-3/project-documentation/tools/leaser/inference_research.md`
- Target [UID:0001J5] `by-memory/0x00584d80-0x00584e9e.StringIter.md`
- [UID:0000E7] `by-class/StringIter.md`
- [UID:0000OB] `by-file/StringUtil.md`
- [UID:0000OA] `by-file/StringBase.md`
- [UID:0000D9] `by-class/SimpleUString.md`
- [UID:0001QS] `by-meta/client_string_handling.md`
- [UID:00016B] `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`
- [UID:00016C] `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
- [UID:0001JP] `by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md`
- [UID:0001JS] `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`
- [UID:00026L] `by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/project-documentation/auto-generated/NexusTK/util/StringUtil.cpp`

Binary evidence checked:

- Original executable: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- PE/Capstone disassembly over `0x00584d80-0x00584ea0`
- Raw rel32 call/jump scan for starts `0x00584d80`, `0x00584dc0`, `0x00584df0`, `0x00584e00`, `0x00584e30`, `0x00584e40`, and `0x00584e60`
- Raw VA/RVA dword pointer scan for those starts
- Absolute dword scan for `0x0062d5ec` StringIter vtable and `0x00650a24` RTTI-adjacent dword
- Caller snippets around `0x004ba904`, `0x004ba9e5`, `0x004bac55`, and `0x005948de`

## Exact Body And Padding Map

Recommended corrected half-open inventory:

| Range | Classification | Source-facing role |
| --- | --- | --- |
| `0x00584d7e-0x00584d80` | predecessor padding | Two `0xcc` bytes before this page, already owned by the predecessor string-buffer range. |
| `0x00584d80-0x00584db1` | promoted function | `StringIter::StringIter(const wchar_t *data, int length)`; calls `LObject` constructor, writes `m_data`, `m_length`, `m_position = 0`, and installs `StringIter` vtable. |
| `0x00584db1-0x00584dc0` | padding | Fifteen `0xcc` bytes. |
| `0x00584dc0-0x00584df0` | raw complete function | `StringIter::StringIter(const wchar_t *data, int length, int startPosition)`; same constructor shape with explicit `m_position = startPosition`; calls `LObject` constructor and installs vtable. |
| `0x00584df0-0x00584dfb` | promoted function | `StringIter::~StringIter()`; writes the class vtable and tail-jumps to `LObject` destruction. |
| `0x00584dfb-0x00584e00` | padding | Five `0xcc` bytes. |
| `0x00584e00-0x00584e23` | raw complete function | `StringIter::PeekCharAtOffset(int offset) const`; computes `index = m_position + offset`, returns `0` for `index >= m_length` or `index < 0`, otherwise returns `m_data[index]`. |
| `0x00584e23-0x00584e30` | padding | Thirteen `0xcc` bytes. The current target's `0x00584e00-0x00584e28` helper row over-includes five padding bytes. |
| `0x00584e30-0x00584e3d` | raw complete function | `StringIter::Advance(int count)`; adds signed `count` to `m_position` with no bounds check. |
| `0x00584e3d-0x00584e40` | padding | Three `0xcc` bytes. |
| `0x00584e40-0x00584e59` | promoted function | `StringIter::GetNextChar()`; returns `0` when `m_position >= m_length`, otherwise returns `m_data[m_position++]`. |
| `0x00584e59-0x00584e60` | padding | Seven `0xcc` bytes. |
| `0x00584e60-0x00584e9e` | promoted compiler glue | MSVC scalar deleting destructor; calls `LObject` destruction and delete helpers based on the deleting flag. Do not model as handwritten source. |
| `0x00584e9e-0x00584ea0` | successor padding | Two `0xcc` bytes before [UID:0001J6] `SystemMessagePanes`. |

Important range correction: the only body/range change needed inside the target is the peek helper endpoint. Use `0x00584e00-0x00584e23` for code and `0x00584e23-0x00584e30` for padding.

## Route And Liveness Findings

Rel32 code route scan results against the original executable:

| Target start | Rel32 references | Interpretation |
| --- | ---: | --- |
| `0x00584d80` | 4 direct calls | Live two-argument constructor. Call sites: `0x004ba904`, `0x004ba9e5`, `0x004bac55`, `0x005948de`. |
| `0x00584dc0` | 0 | Retained raw three-argument constructor body. No direct live route found. |
| `0x00584df0` | 8 rel32 refs | Live destructor body. Normal calls at `0x004ba975`, `0x004baa4b`, `0x004baca5`, `0x0059497a`; additional compiler/EH jmp refs at `0x005ff3c7`, `0x005ff3ea`, `0x005ff40d`, and `0x0060987a`. |
| `0x00584e00` | 0 | Retained raw peek helper. No direct live route found. |
| `0x00584e30` | 0 | Retained raw advance helper. No direct live route found. |
| `0x00584e40` | 12 direct calls | Live next-character iterator method. Call sites: `0x004ba913`, `0x004ba91e`, `0x004ba965`, `0x004ba9f4`, `0x004ba9ff`, `0x004baa3b`, `0x004bac64`, `0x004bac6f`, `0x004bac95`, `0x005948ed`, `0x005948f8`, `0x0059494f`. |
| `0x00584e60` | 0 code refs; one data ref | Compiler deleting destructor, referenced by `StringIter` vtable slot at `0x0062d5ec`. |

VA/RVA dword route scan:

- No VA or RVA dword hits were found for `0x00584d80`, `0x00584dc0`, `0x00584df0`, `0x00584e00`, `0x00584e30`, or `0x00584e40`.
- `0x00584e60` has one VA dword hit at `0x0062d5ec`, the first slot of the `StringIter` vtable.
- `0x0062d5ec` appears as immediate vtable stores in the source methods at instructions `0x00584d9d`, `0x00584de3`, `0x00584df0`, and `0x00584e66`.
- `0x00650a24` appears at `0x0062d5e8` as the RTTI-adjacent dword before the `StringIter` vtable.

Conclusion:

- The raw constructor, peek, and advance starts are not missed direct-call edges in the current executable. They are retained code bodies, likely emitted because the utility string object file retained out-of-line methods even if only `StringIter(text, length)` and `GetNextChar()` are used by current callers.
- These helpers should still be represented as source-level methods because the byte bodies are complete, padding-bounded, and class-shaped. Leaving them as anonymous raw blockers is now lower quality than assigning high-probability API names and reconstructing them.

## Source-Facing Names And Layout

Recommended class layout:

```cpp
class StringIter : public LObject
{
public:
    StringIter(const wchar_t *data, int length);
    StringIter(const wchar_t *data, int length, int startPosition);
    virtual ~StringIter();

    wchar_t PeekCharAtOffset(int offset) const;
    void Advance(int count);
    wchar_t GetNextChar();

private:
    const wchar_t *m_data;  // +0x04
    int m_length;           // +0x08
    int m_position;         // +0x0c
};
```

Name confidence:

- `StringIter`: high. The `.rdata` page records `??_7StringIter@@6B@` at `0x0062d5ec`, support docs consistently use the class name, and the methods install that vtable.
- `m_data`: medium-high. It is already used in historical generated metadata and the class page. `m_text` is also plausible from caller arguments, but `m_data` is more neutral and avoids suggesting ownership or a null-terminated text contract.
- `m_length`: high. The binary compares `m_position` against `this+0x08` in both peek and next-char.
- `m_position`: high. Constructors initialize `this+0x0c`; `Advance` adds to it; `GetNextChar` increments it after reading.
- `StringIter(const wchar_t *data, int length)`: high. Four live callers pass data and count and construct a 16-byte stack object.
- `StringIter(const wchar_t *data, int length, int startPosition)`: medium-high. The body is exact, but no direct route was found.
- `~StringIter()`: high. Direct destructor calls and EH cleanup refs exist; the source body is empty beyond base destruction/vtable mechanics.
- `PeekCharAtOffset(int offset) const`: medium-high. The exact name is heuristic, but the operation is unambiguous: relative indexed read from current position with negative and end guards.
- `Advance(int count)`: medium-high. The exact name is heuristic, but the signed relative move operation is unambiguous.
- `GetNextChar()`: high. Existing accepted GrafPort text-helper C++ uses this name, and all live callers use it as a pull-style iterator method returning a UTF-16 character or zero.

## Caller Text-Helper Semantics

The live caller set confirms a length-bounded UTF-16 iterator used for render/measure lookahead, not an owning string wrapper:

- [UID:00016B] `GrafPort::CountCharsFittingWidth` constructs a local `StringIter`, calls `GetNextChar()` twice to hold current and next glyphs, then advances one character at a time while measuring glyph widths through `g_pFontImageLib`.
- [UID:00016C] `GrafPort::GetTextWidth(const wchar_t *text, int charCount)` constructs a local `StringIter`, uses two-character lookahead, calls the glyph-measure helper, and destroys the iterator before returning the summed width.
- [UID:00016C] `GrafPort::DrawWideText(const wchar_t *text, int charCount)` constructs a local `StringIter`, uses current/next glyph lookahead, and calls the glyph drawing helper once per character.
- [UID:0001JS] `0x005948a0` TextEditPane wrap/measure helper constructs a local `StringIter`, uses two-character lookahead, measures glyphs, tracks consumed characters and remaining width, and destroys the iterator before returning.

This is important for ownership: the callers pass raw UTF-16 buffers and explicit lengths. They do not pass `SimpleUString` or `StringBase` receiver objects.

## Ownership And Source Placement

Recommended owner/emitter: keep [UID:0000OB] `StringUtil`.

Ranking:

1. [UID:0000OB] `StringUtil` - strongest. The class is a shared utility iterator used by GrafPort and TextEdit text helpers, physically adjacent to string utilities, already routed to `NexusTK/util/StringUtil.cpp`, and documented by the file page as part of shared client string infrastructure.
2. Possible future `StringIter.cpp` split - plausible but not actionable. A small standalone file could have existed, but current proposed tree and emission route already centralize small utility-string helpers in `StringUtil.cpp`. There is no separate source-path, caller, or build artifact proving a standalone file.
3. [UID:0000OA] `StringBase` - reject as direct owner. The predecessor `0x00582500-0x00584d7e` is ref-counted string-buffer code, but `StringIter` starts after padding at `0x00584d80`, has its own `StringIter` RTTI/vtable, and does not touch `StringBase` headers, refcounts, copy-on-write, sentinels, or pools.
4. [UID:0000D9] `SimpleUString` - reject as direct owner. The iterator has a 16-byte `LObject`-derived layout over caller-owned `wchar_t *` data. It is not the 24-byte SSO `SimpleUString` storage object and does not manage short-string inline data.
5. [UID:0000KV] `LObject` - reject as direct owner. `LObject` is only the runtime/base constructor/destructor dependency.
6. GrafPort/TextEditPane callers - reject as direct owners. They are consumers of a shared utility iterator, not source parents.

## Scalar Deleting Destructor Policy

`0x00584e60-0x00584e9e` should remain documented but not reconstructed as handwritten C++.

No-code proof:

- It has the standard deleting-destructor signature shape: `this` in `ecx`, deleting flag at `[ebp+8]`, returns `this`, and checks flag bits before calling delete helpers.
- It writes the `StringIter` vtable at instruction `0x00584e66`, calls base destruction at `0x00584e6c -> 0x004f4a90`, calls delete helper `0x004f4ac0` for the ordinary delete path, and calls `0x0041b6a0` with size `0x10` for the alternate delete path.
- It has no direct code refs and one data ref from the vtable slot at `0x0062d5ec`.
- It is generated from the virtual `StringIter::~StringIter()` and vtable, not from a source-authored member body.

Recommended by-memory C++ should include the empty destructor and a comment noting that the deleting destructor is compiler-generated. Do not add a fake `ScalarDeletingDestructor` method to source.

## Open Questions Rechecked And Resolved

| Question | Resolution |
| --- | --- |
| Are the raw helpers real code or padding/decompiler artifacts? | Real code. The three raw starts are complete, padding-bounded, decode cleanly, and match the class layout. Only the current peek helper endpoint is over-wide; code ends at `0x00584e23`. |
| Are the raw helpers live through direct calls or tables? | No route found. Rel32 call/jump and VA/RVA start-pointer scans found no hits for `0x00584dc0`, `0x00584e00`, or `0x00584e30`. Treat them as retained, currently uncalled out-of-line methods. |
| Should raw no-xref helpers block source names? | No. The method bodies are simple and class-shaped enough for high-probability source names. Keep uncertainty notes but do not leave raw `sub_` placeholders. |
| Is `GetNextChar` final enough? | Yes. Existing accepted text-helper C++ uses `GetNextChar`, the live caller pattern is pull-style next-character iteration, and the method mutates `m_position`. |
| Should `PeekCharAtOffset` be named `GetChar`, `Peek`, or `PeekCharAtOffset`? | Exact PDB/source name is unproven. `PeekCharAtOffset` is the best source-quality descriptive name because the method is relative to current position, allows negative offsets, and does not advance. If the project prefers shorter names, `PeekChar` is the only close alternative. |
| Should `Advance` be `Skip`, `Move`, or `Advance`? | Exact PDB/source name is unproven. `Advance` is best because it adds a signed count to `m_position` without reading or bounds checking. `Skip` would imply forward-only movement, which the code does not enforce. |
| Should formal C++ stay blank because of raw helpers? | No. The active code-entry gate is cleared, behavior is exact, raw helper names are high-confidence descriptive, and source C++ can represent retained out-of-line members cleanly. |
| Should formal C++ include scalar deleting destructor code? | No. Include the human destructor only; record deleting wrapper as compiler-generated no-code glue. |
| Is StringIter part of `StringBase` because of physical adjacency? | No. There is padding at `0x00584d7e-0x00584d80`, separate RTTI/vtable, and no `StringBase` storage/refcount behavior. |
| Is StringIter part of `SimpleUString` because it handles UTF-16? | No. It consumes caller-owned `wchar_t *` and length; it is not a `SimpleUString` object. |
| Does this need exact child-page split? | No immediate split is needed. The target is a compact exact class method cluster. A future split into individual method pages is optional, not required for source quality. |

## First-Draft C++

Recommended formal C++ for the by-memory target:

```cpp
StringIter::StringIter(const wchar_t *data, int length)
    : LObject(),
      m_data(data),
      m_length(length),
      m_position(0)
{
}

StringIter::StringIter(const wchar_t *data, int length, int startPosition)
    : LObject(),
      m_data(data),
      m_length(length),
      m_position(startPosition)
{
}

StringIter::~StringIter()
{
}

wchar_t StringIter::PeekCharAtOffset(int offset) const
{
    int index = m_position + offset;
    if (index >= m_length || index < 0)
        return 0;

    return m_data[index];
}

void StringIter::Advance(int count)
{
    m_position += count;
}

wchar_t StringIter::GetNextChar()
{
    if (m_position >= m_length)
        return 0;

    return m_data[m_position++];
}

// The scalar deleting destructor at 0x00584e60 is compiler-generated from
// StringIter::~StringIter() and the vtable; do not model it as a handwritten
// source method.
```

Recommended declaration for [UID:0000E7] `by-class/StringIter.md` if the supervisor wants class-level C++ to support the method definitions:

```cpp
class StringIter : public LObject
{
public:
    StringIter(const wchar_t *data, int length);
    StringIter(const wchar_t *data, int length, int startPosition);
    virtual ~StringIter();

    wchar_t PeekCharAtOffset(int offset) const;
    void Advance(int count);
    wchar_t GetNextChar();

private:
    const wchar_t *m_data;
    int m_length;
    int m_position;
};
```

## Exact Recommended Target Changes

For `by-memory/0x00584d80-0x00584e9e.StringIter.md`:

1. Change metadata:
   - `COMPLETION:85 -> 88`
   - `CONFIDENCE:86 -> 90`
   - Keep `CANONICAL_OWNER:0000OB`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:0000OB`

2. Populate the formal C++ block with the first-draft C++ above.

3. Replace the stale no-C++/autogen wording. Recommended wording:
   - `The active code-entry gate is cleared. Source C++ should model the two constructors, empty destructor, retained PeekCharAtOffset/Advance helpers, and GetNextChar. The scalar deleting destructor at 0x00584e60 is compiler-generated from the virtual destructor and vtable and should stay as documented no-code glue.`

4. Update the function table:
   - Keep `0x00584d80-0x00584db1` as `StringIter::StringIter(const wchar_t *data, int length)`.
   - Keep `0x00584dc0-0x00584df0` as `StringIter::StringIter(const wchar_t *data, int length, int startPosition)`.
   - Keep `0x00584df0-0x00584dfb` as `StringIter::~StringIter`.
   - Change peek row from `0x00584e00-0x00584e28` to `0x00584e00-0x00584e23`.
   - Add/merge padding row `0x00584e23-0x00584e30` as thirteen `0xcc` bytes.
   - Keep `0x00584e30-0x00584e3d` as `StringIter::Advance(int count)`.
   - Keep `0x00584e40-0x00584e59` as `StringIter::GetNextChar()`.
   - Keep `0x00584e60-0x00584e9e` as scalar deleting destructor, compiler-generated no-code.

5. Add route/liveness notes:
   - `0x00584d80` has 4 direct constructor call refs: `0x004ba904`, `0x004ba9e5`, `0x004bac55`, `0x005948de`.
   - `0x00584df0` has normal destructor calls at `0x004ba975`, `0x004baa4b`, `0x004baca5`, `0x0059497a` plus compiler/EH jmp refs at `0x005ff3c7`, `0x005ff3ea`, `0x005ff40d`, and `0x0060987a`.
   - `0x00584e40` has 12 direct calls from the GrafPort/TextEdit text-helper cluster.
   - `0x00584dc0`, `0x00584e00`, and `0x00584e30` have no direct rel32 calls/jumps and no VA/RVA start-pointer hits; they are retained no-xref class API bodies.
   - `0x00584e60` has no direct code refs and one vtable data ref at `0x0062d5ec`.

6. Add source-name/layout notes:
   - Class layout: `LObject` base/vtable at `+0x00`, `const wchar_t *m_data` at `+0x04`, `int m_length` at `+0x08`, `int m_position` at `+0x0c`; object size `0x10`.
   - `PeekCharAtOffset` returns zero for negative relative indexes and indexes at/after length.
   - `Advance` accepts signed counts and does not clamp.
   - `GetNextChar` is length-bounded but does not guard negative `m_position`; this matches the binary.

7. Add owner/source-placement notes:
   - Keep `StringUtil` as source file/emitter.
   - Reject `StringBase`, `SimpleUString`, `LObject`, GrafPort, and TextEditPane as direct owners for this range.

## Support Doc Updates Needed

### `by-class/StringIter.md`

Recommended changes:

- Raise to `COMPLETION:88`, `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000OB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OB`.
- Replace "Leave C++ blank" with: `The by-memory [UID:0001J5] target should emit method definitions; this class page should carry the final class/API inventory and may emit the class declaration only.`
- Add the class declaration from this report if class-page formal C++ declarations are allowed by supervisor policy.
- Add raw route evidence:
  - no rel32/VA/RVA hits for `0x00584dc0`, `0x00584e00`, `0x00584e30`;
  - live constructor/GetNextChar/destructor route counts;
  - scalar deleting destructor is vtable-only compiler glue.
- Add endpoint correction: `0x00584e00-0x00584e23` is the peek body and `0x00584e23-0x00584e30` is padding.
- Add final field names: `m_data`, `m_length`, `m_position`.

### `by-file/StringUtil.md`

Recommended documentation-only changes; no score change required.

- In the ownership map row for `StringIter`, replace the manual-boundary caveat with:
  - `[UID:0001J5] is a small LObject-derived UTF-16 iterator with final source-facing API names StringIter, constructors, PeekCharAtOffset, Advance, and GetNextChar. Raw helpers at 0x00584dc0/0x00584e00/0x00584e30 are confirmed complete retained no-xref out-of-line methods; by-memory target emits method definitions while the scalar deleting destructor remains compiler glue.`
- In recovered-output caveats, replace:
  - `Earlier StringIter recovery expects a constructor at 0x00584dc0, but IDA reports 0x00584dc0 is not a function. Treat it as a projected/manual boundary until raw disassembly confirms a real constructor slice.`
  with:
  - `Raw disassembly confirms the 0x00584dc0 StringIter constructor slice is real and complete, but no direct call/jump or VA/RVA start-pointer route was found. Treat 0x00584dc0, 0x00584e00, and 0x00584e30 as retained no-xref out-of-line StringIter API bodies, not padding.`
- Add a note that `StringIter` remains under `StringUtil.cpp`, not `StringBase.cpp`, because it iterates caller-owned UTF-16 buffers and does not use ref-counted buffer headers or `SimpleUString` SSO storage.

### `by-meta/client_string_handling.md`

Recommended documentation-only changes:

- Update the caveat that says the active output includes a projected constructor at `0x00584dc0` not defined as an IDA function:
  - `0x00584dc0` is now raw-confirmed as a complete three-argument `StringIter` constructor but remains no-xref/non-promoted in IDA.
  - Add that `0x00584e00` `PeekCharAtOffset` and `0x00584e30` `Advance` are also raw-confirmed retained no-xref methods.
- Add that live users consume `StringIter` through the two-argument constructor and `GetNextChar()` in GrafPort and TextEdit text measurement/drawing helpers.

### `by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md`

Recommended documentation-only changes:

- Keep the page non-reconstructable and non-emitting.
- Add that the `StringIter` vtable slot at `0x0062d5ec` points to the compiler-generated scalar deleting destructor at `0x00584e60`, while source reconstruction should provide only `virtual ~StringIter()`.
- Keep the current ownership statement: reconstruct the `StringIter` vtable through the `StringUtil`/`StringIter` declarations, not through this mixed `.rdata` island.

### `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`

No required score or C++ change. Optional note:

- The first-draft `GrafPort::CountCharsFittingWidth` C++ already uses `StringIter::GetNextChar()` correctly. Add a dependency note that [UID:0001J5] now recommends final source C++ for the iterator.

### `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`

No required score or C++ change. Optional note:

- The first-draft `GrafPort::GetTextWidth` and `GrafPort::DrawWideText` C++ already matches the live two-character `StringIter::GetNextChar()` lookahead pattern.

### `by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md`

No required score or C++ change. Optional note:

- The wrap/measure helper at `0x005948a0` constructs the two-argument `StringIter`, calls `GetNextChar()` three times in the same lookahead pattern, and destroys it at `0x0059497a`.

### `by-file/StringBase.md`

No required edit. The existing exclusion of `StringIter` from the `StringBase` owned range is correct. Do not broaden `StringBase` to include [UID:0001J5].

### `by-class/SimpleUString.md`

No required edit. Do not attach `StringIter` as a `SimpleUString` method; it is a separate `LObject`-derived iterator over caller-owned UTF-16 data.

## Exact Pending Coverage Row

Do not edit `by-memory/-coverage-report.md` directly. If supervisor accepts implementation, replace the current [UID:0001J5] row with:

```text
    - [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md) : reconstructable : 88% : very strong : Small `LObject`-derived UTF-16 iterator owned by StringUtil, with verified 16-byte layout (`m_data`, `m_length`, `m_position`), two source constructors, empty destructor, retained raw `PeekCharAtOffset`/`Advance` helpers with no direct rel32/VA/RVA route, live constructor/GetNextChar use from GrafPort and TextEdit text helpers, vtable/scalar-deleting-destructor no-code proof at `0x0062d5ec`, first-draft C++ readiness, exact padding including corrected `0x00584e23-0x00584e30`, and StringBase/SimpleUString ownership exclusions documented.
```

## Validation Commands For Future Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001J5-StringIter-source-quality-removed.md](0001J5-StringIter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional GrafPort/TextEdit support notes are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0001J5-StringIter-source-quality-removed.md](0001J5-StringIter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended after validators if C++ is added and generated output changes:

> Executable block R003 was removed from this report and preserved verbatim in [0001J5-StringIter-source-quality-removed.md](0001J5-StringIter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename, Type, And Comment Recommendations

Function creation/rename recommendations:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x00584d80` | `StringIter::StringIter(const wchar_t *data, int length)` | High |
| `0x00584dc0` | Create function and name `StringIter::StringIter(const wchar_t *data, int length, int startPosition)` or IDA-safe `StringIter_ctor_withPosition` | Medium-high |
| `0x00584df0` | `StringIter::~StringIter()` | High |
| `0x00584e00` | Create function and name `StringIter::PeekCharAtOffset(int offset) const` or IDA-safe `StringIter_PeekCharAtOffset` | Medium-high |
| `0x00584e30` | Create function and name `StringIter::Advance(int count)` or IDA-safe `StringIter_Advance` | Medium-high |
| `0x00584e40` | `StringIter::GetNextChar()` | High |
| `0x00584e60` | `StringIter_scalar_deleting_destructor` / MSVC scalar deleting destructor name; mark compiler-generated | High |

Type recommendations:

```cpp
struct StringIter : LObject {
    const wchar_t *m_data;  // +0x04
    int m_length;           // +0x08
    int m_position;         // +0x0c
};
```

Method prototypes:

```cpp
StringIter *__thiscall StringIter_ctor(StringIter *this, const wchar_t *data, int length);
StringIter *__thiscall StringIter_ctor_withPosition(StringIter *this, const wchar_t *data, int length, int startPosition);
void __thiscall StringIter_dtor(StringIter *this);
wchar_t __thiscall StringIter_PeekCharAtOffset(const StringIter *this, int offset);
void __thiscall StringIter_Advance(StringIter *this, int count);
wchar_t __thiscall StringIter_GetNextChar(StringIter *this);
void *__thiscall StringIter_scalar_deleting_destructor(StringIter *this, unsigned int flags);
```

IDA comments:

- At `0x00584dc0`: `Retained no-xref StringIter constructor overload; raw-confirmed complete body, no rel32 or VA/RVA start-pointer route found.`
- At `0x00584e00`: `Retained no-xref peek helper; reads m_data[m_position + offset] only when 0 <= index < m_length.`
- At `0x00584e30`: `Retained no-xref advance helper; signed position adjustment with no clamp.`
- At `0x00584e60`: `Compiler-generated scalar deleting destructor from virtual ~StringIter(); vtable slot at 0x0062d5ec; not source-authored.`
- At `0x0062d5ec`: `StringIter vtable slot 0 -> scalar deleting destructor; source emits virtual ~StringIter only.`

## Implementation Readiness

This target is ready for first-draft C++ implementation after supervisor acceptance.

Implementation should be low risk because:

- The byte-level behavior is exact for every source-authored method.
- The live caller route explains the public constructor and `GetNextChar`.
- The retained raw helpers have no discovered live route but have simple, complete, class-shaped behavior and high-probability source names.
- The scalar deleting destructor has target-specific no-code proof.
- Ownership and source-file routing are stronger for `StringUtil` than for all alternatives.

Residual uncertainty:

- Exact original spelling of `PeekCharAtOffset` and `Advance` is not PDB-proven. The recommended names are source-quality descriptive names with medium-high confidence, not hard symbol recoveries.
- Exact original file split between `StringUtil.cpp` and a possible standalone `StringIter.cpp` remains unproven. The current project emission route through `NexusTK/util/StringUtil.cpp` is still the best-supported route.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001J5-StringIter-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001J5"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001J5-StringIter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001J5-StringIter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001J5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
