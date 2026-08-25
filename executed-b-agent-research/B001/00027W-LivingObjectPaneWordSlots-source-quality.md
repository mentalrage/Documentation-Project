** TARGET-REPORT-UID:00027W **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00027W LivingObjectPaneWordSlots Source-Quality Reanalysis

## Finalized Report / Current Recommendation

- Current recommendation: do not carry forward `LivingObjectPaneWordSlots_66DECC`, `word_66DECC` through `word_66DED4`, or LivingObjectPane ownership as the final source shape.
- Final disposition: keep [UID:00027W] reconstructable and source-declared/generated-binary, but rename/reclassify it as a provisional OptionPane-neighborhood legacy size-word table, not a LivingObjectPane data object.
- Required action: rename the by-memory page to `by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md`, change owner/emitter to [UID:0000M7] `OptionPane`, update support docs to reject the stale LivingObjectPane placement, and update the stale coverage row.
- Score recommendation: `85/85 -> 87/86`. Completion improves from current raw PE route scans and source-shape reanalysis. Confidence stays below high-final because there are no reads of the table, no caller route into the two setter starts, and no proven original declaration grouping.
- Formal C++ recommendation: do not populate `RECONSTRUCTION_CPP CODE` yet. The code gate would be met after the recommended score/owner change, but the target-specific no-code proof below blocks final declaration entry.

## Target

- Target UID: [UID:00027W]
- Current path: `by-memory/0x0066decc-0x0066dee0.LivingObjectPaneWordSlots_66DECC.md`
- Recommended path: `by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, blank formal C++.
- Recommended metadata: `COMPLETION:87`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000M7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000M7`, blank formal C++ with explicit no-code proof.

## Evidence Checked

- Required B001/supervisor instructions: `Agent-B001/goal.md`, `Supervisor.md`, `Agent-B001/notes.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Target/support docs: [UID:00027W], [UID:0000KU] `LivingObjectPane`, [UID:00007B] `LivingObjectPane`, [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions`, [UID:00027V] `MusicControlDriveRootBuffers`, [UID:0001OM] `FriendNameListSyncEnabled`, [UID:00027X] `FriendNameOptionPalettePadding`, [UID:0001Z8] `DataSection`, [UID:0001DW] `NewOptionPane`, [UID:000097] `NewOptionPane`, [UID:0000M7] `OptionPane`, [UID:0001DX] `NewOptionPaneServerOptionHelpers`, and [UID:0001DY] `SendOptionPacket11B`.
- Existing reports/state: `by-memory/-coverage-report.md` row for [UID:00027W] is stale at `80%`; `project-level/-unresolved.md` still flags `sub_5A8C60` and `word_66DECC` through `word_66DED4` from this target.
- Raw binary: parsed `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` directly with a read-only PE/Capstone script. Sections observed: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2e00`.
- Live MCP status this turn: `http://127.0.0.1:13337/mcp` was unavailable. I used the target's existing 2026-06-14 live IDA MCP evidence plus fresh raw PE/Capstone verification instead of making new IDA DB claims.

## Raw PE / Disassembly Facts

- Bytes at `0x0066debc-0x0066dee8` are:
  `58 3a 5c 00 58 00 3a 00 00 00 00 00 50 00 00 00 50 00 50 00 50 00 50 00 50 00 28 00 28 00 28 00 28 00 28 00 01 00 00 00 64 12 62 00`.
- Target payload at `0x0066decc-0x0066dee0` is exactly five `0x0050` words followed by five `0x0028` words.
- Raw dword VA scan over the full PE found exactly two `.text` occurrences for each first-row word address:
  - `0x0066decc`: operands at `0x005a8bf9`, `0x005a8c3f`
  - `0x0066dece`: operands at `0x005a8bff`, `0x005a8c45`
  - `0x0066ded0`: operands at `0x005a8c05`, `0x005a8c4b`
  - `0x0066ded2`: operands at `0x005a8c0b`, `0x005a8c51`
  - `0x0066ded4`: operands at `0x005a8c11`, `0x005a8c57`
- Capstone decodes those as the ten expected stores:
  - `0x005a8bf7`, `0x005a8bfd`, `0x005a8c03`, `0x005a8c09`, `0x005a8c0f`
  - `0x005a8c3d`, `0x005a8c43`, `0x005a8c49`, `0x005a8c4f`, `0x005a8c55`
- Raw dword VA scan found zero full-PE occurrences for tail word addresses `0x0066ded6`, `0x0066ded8`, `0x0066deda`, `0x0066dedc`, and `0x0066dede`.
- Raw dword VA scan found the successor flag `0x0066dee0` at `0x00508b02`, `0x0051439f`, and `0x0053f8de`, matching the existing FriendName sync page and proving the hard end boundary.
- Raw dword VA scan found zero full-PE occurrences of setter start VAs `0x005a8b80`, `0x005a8c20`, and `0x005a8c60`.
- Raw dword RVA scan found zero occurrences of start RVAs `0x001a8b80`, `0x001a8c20`, and `0x001a8c60`.
- Direct branch/call scan over `.text` found zero `call`, `jmp`, rel8, or rel32 conditional branch routes to `0x005a8b80` or `0x005a8c20`.
- The same route scan found three direct calls to `0x005a8c60`: `0x00540a58`, `0x00540aa2`, and `0x00540ab4`.
- `0x005a8b80-0x005a8c16` is a prologue-shaped `__cdecl` raw helper. It selects a word in the `0x0043..0x004b` range from signed threshold checks on two stack arguments and writes the selected `ax` to all five first-row words.
- `0x005a8c20-0x005a8c5c` is a prologue-shaped `__cdecl` raw helper. It defaults to `0x0050`, or for `arg <= 5` computes `(0x10 - arg) * 5`, then writes that `ax` to all five first-row words.
- `0x005a8c60-0x005a8ce7` is a distinct live helper after `0xcc` padding. It writes packet bytes `0x1b`, `0x01`, selector, and `selector == 0`, then queues four bytes through `0x00574bb0` using `dword_67A7EC`.
- `0x00540910-0x00540d37` is documented as `NewOptionPane::OnMouseClick` in [UID:0001DW]/[UID:000097]. Its calls to `0x005a8c60` are option-entry cases with selectors `7`, `3`, and `1`. This contradicts the current [UID:00027W] wording that uses the successor `sub_5A8C60` as LivingObjectPane-local-player support evidence.
- `0x005a8ae0-0x005a8b6f`, immediately before the setters, is another packet-shaped no-caller helper: it normalizes an ASCII letter into an index, writes opcode byte `0x1c`, writes the index, terminates the local buffer, and queues two bytes through `0x00574bb0`. It is source-shaped option/protocol neighborhood evidence, not LivingObjectPane movement evidence.

## Heuristic / Inference Reanalysis And Validation

### Generated Names

- Current stale names rejected: `LivingObjectPaneWordSlots_66DECC`, `LivingObjectPaneSharedWordSlots`, `word_66DECC`, `word_66DECE`, `word_66DED0`, `word_66DED2`, `word_66DED4`.
- Reason: raw evidence proves the first row is a grouped array-like storage item, not five independent globals. The current LivingObjectPane prefix depends on the broad mixed [UID:0001KM] address neighborhood, and that neighborhood now contains proven non-Living OptionPane/NewOptionPane helper code.
- Best descriptive name: `OptionPaneLegacySizeWordTable_66DECC` for the by-memory filename/title, with source-facing candidate `s_optionPaneLegacySizeWords`.
- Confidence on name: medium-high as a descriptive source-quality name, not original-name proof. `OptionPane` is supported by the confirmed `NewOptionPane::OnMouseClick -> 0x005a8c60` route and adjacent option-packet helper shape; `LegacySizeWordTable` is supported by the two-row `0x0050`/`0x0028` pattern plus setter formulas, but no reader proves final semantics.

### Type And Layout

- Best type model: `uint16_t[2][5]` or two adjacent `uint16_t[5]` rows.
- Best documentation wording: row 0 is the write-referenced mutable size row initialized to `0x0050`; row 1 is a fixed/no-xref half-size row initialized to `0x0028`.
- Rejected "five independent globals": both setters write all five first-row elements with the same selected word, and the row is initialized uniformly.
- Rejected "tail padding": the tail is not zero/alignment padding; it is five repeated nonzero words, exactly matching the first row count and half the first row default.
- Rejected "tail proven live": full-PE address scans and existing IDA xrefs find no tail address references, no base indexed references, and no pointer to the tail row.
- Rejected "split into first-row child plus ignored tail now": the repeated 5+5 layout strongly suggests one source declaration or two sibling declarations. Splitting the tail now would create a no-owner/no-xref fragment without a separate owner or boundary xref.

### Raw Setter Roles

- `0x005a8b80-0x005a8c16`: best descriptive signature `static void __cdecl SetLegacyOptionSizeWordsFromThresholds(int primaryValue, int secondaryValue);`. It maps threshold bands to one `uint16_t` value and stores the value to row 0 indices `0..4`.
- `0x005a8c20-0x005a8c5c`: best descriptive signature `static void __cdecl SetLegacyOptionSizeWordsFromScaleLevel(unsigned int level);`. It maps levels `0..5` to a decreasing size word via `(0x10 - level) * 5`; other values keep default `0x0050`.
- Both helpers are source-shaped but currently no-route. They should not be promoted as live public helpers, member functions, or final C++ bodies until exact child pages are created and a caller/source-use route is found.
- Rejected "public LivingObjectPane helper": no rel32/pointer/raw route to either start; no `this` receiver; no calls from the LivingObjectPane movement/action/server-packet functions; no reads by LivingObjectPane state.
- Rejected "compiler-generated helper": both starts are handwritten-looking prologue/ret bodies with semantic threshold logic and source-data writes, not thunks, EH, security-cookie glue, padding, or CRT support.

### Reachability And Liveness

- First-row words are write-referenced, not read-referenced. Calling them "live word slots" without qualification overstates runtime liveness.
- Setter starts are not reached by direct call/jump/pointer route in the scanned PE. This makes them retained/orphan source-shaped helpers unless future indirect/dynamic evidence appears.
- `0x005a8c60` is live, but it is not a word-table consumer. It belongs to a NewOptionPane option-packet click path and should be used as exclusion evidence against the current LivingObjectPane source-placement rationale.
- The target remains reconstructable because the initialized table and source-shaped setters are NexusTK project artifacts that must be accounted for in a source rebuild. The lack of readers/callers blocks final declaration/code, not the data-range documentation itself.

### Owner / Source Placement

Ranked candidates:

1. [UID:0000M7] `OptionPane` / [UID:000097] `NewOptionPane` context: best current owner direction. Evidence: `0x005a8c60` is directly called from [UID:0001DW] `NewOptionPane::OnMouseClick` cases and sends an option packet; `0x005a8ae0` is a neighboring no-caller option/protocol packet helper; [UID:0000M7] already owns option-packet helpers and static option resource data near `0x0066dee4`. The table itself is file-static/global-shaped rather than a class field, so the direct owner should be the file page [UID:0000M7], not the class page [UID:000097].
2. [UID:0000KU] `LivingObjectPane`: rejected as current canonical owner. Evidence for LivingObjectPane was physical membership in [UID:0001KM], but [UID:0001KM] is an accepted mixed split index and now explicitly contains non-Living source families. The immediately following live helper is NewOptionPane-owned, not LivingObjectPane-owned. No LivingObjectPane function reads the table or calls the setters.
3. [UID:0000L3] `MapPane` / coordinate state: rejected. The `0x0050`/`0x0028` pair could superficially look like map/tile dimensions, but no MapPane calls, data reads, or map-coordinate function references touch the range.
4. Neighboring data owners [UID:00027V] MusicControl and [UID:0001OM] FriendName sync: rejected. Their pages have independent xrefs and boundaries; neither touches this range.
5. `CANONICAL_OWNER:NONE`: rejected as final recommendation but retained as a risk note. If the supervisor decides OptionPane adjacency is still too weak because the setters have no callers and the table has no readers, the fallback should be owner `NONE`, blank emitter, and score no higher than `86/84`. I do not recommend that as the primary outcome because the NewOptionPane successor route and option-packet neighborhood are stronger than the stale LivingObjectPane basis.

### Split / Rename / Reclassification Policy

- Rename, do not split. Recommended filename: `0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md`.
- Keep the range `0x0066decc-0x0066dee0`. Start and end boundaries remain proven by [UID:00027V] and [UID:0001OM].
- Keep `RECONSTRUCTABLE:TRUE` and `source-declared/generated-binary`.
- Change canonical owner and emitter from [UID:0000KU] to [UID:0000M7].
- Keep formal C++ blank with the no-code proof below.

## Open Questions Resolved Or Remaining

- Resolved: `sub_5A8C60` should not remain an unresolved blocker on [UID:00027W]. It is the live discontiguous NewOptionPane option-packet helper at `0x005a8c60-0x005a8ce7`, called from `0x00540910` at `0x00540a58`, `0x00540aa2`, and `0x00540ab4`.
- Resolved: the first five words are a grouped row, not independent `word_66DECC` globals.
- Resolved: the tail is not padding and should not be ignored; best inference is a second fixed/half-size row in the same legacy size table, but no direct use is proven.
- Resolved: the raw setters should not be treated as live public helpers. They are no-route, source-shaped private/orphan setters.
- Remaining blocker: no reader or caller proves what runtime feature consumed `s_optionPaneLegacySizeWords`. This blocks final C++ and keeps confidence at `86`.
- Remaining blocker: exact original declaration shape is not defensible. The binary is compatible with `uint16_t s_optionPaneLegacySizeWords[2][5]`, two sibling arrays, or a first-row array plus a second row of retained defaults.
- Remaining blocker: exact helper child pages for `0x005a8b80-0x005a8c16`, `0x005a8c20-0x005a8c5c`, and `0x005a8c60-0x005a8ce7` do not yet exist. This report provides source-facing signatures, but does not create by-memory children.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:00027W] now.

Target-specific no-code proof:

- The only references to row 0 are writes from no-route raw setter starts. There are no table reads, no tail-row references, and no route into either setter in the scanned PE.
- The row 1 `0x0028` words are a patterned source-data row, but no evidence proves whether they are part of one 2x5 declaration, a sibling array, or retained defaults.
- The best owner changes from LivingObjectPane to OptionPane only by source-neighborhood inference; it is strong enough to correct the stale owner, but not strong enough to freeze a final source declaration name in generated `OptionPane.cpp`.
- Entering formal C++ now would create a visible global declaration that no emitted code uses and would force a storage grouping that the binary does not yet prove.

For future use only, after exact helper/source-route work, the safest candidate declaration shape would be:

```cpp
// Candidate only. Do not populate formal C++ until the helper/source route is resolved.
static unsigned short s_optionPaneLegacySizeWords[2][5] = {
    { 0x0050, 0x0050, 0x0050, 0x0050, 0x0050 },
    { 0x0028, 0x0028, 0x0028, 0x0028, 0x0028 },
};
```

Candidate helper signatures for future exact child pages:

```cpp
static void __cdecl SetLegacyOptionSizeWordsFromThresholds(int primaryValue, int secondaryValue);
static void __cdecl SetLegacyOptionSizeWordsFromScaleLevel(unsigned int level);
```

## Exact Supervisor Changes Required

### Target [UID:00027W]

Rename:

```text
from: by-memory/0x0066decc-0x0066dee0.LivingObjectPaneWordSlots_66DECC.md
to:   by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md
```

Header replacement:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Title replacement:

```text
# 0x0066decc-0x0066dee0 OptionPane Legacy Size Word Table
```

Recommended summary replacement text:

```text
This range contains a ten-word source-declared/generated-binary data table. Row 0 (`0x0066decc-0x0066ded6`) is initialized to five `0x0050` words and is write-referenced only by two no-route raw setter helpers at `0x005a8b80-0x005a8c16` and `0x005a8c20-0x005a8c5c`. Row 1 (`0x0066ded6-0x0066dee0`) is initialized to five `0x0028` words and has no direct references in current IDA evidence or the fresh raw PE address scan.

The previous LivingObjectPane placement is superseded. The broad [UID:0001KM] neighborhood is a mixed split index, and the immediately following live helper `0x005a8c60-0x005a8ce7` is reached from [UID:0001DW] `NewOptionPane::OnMouseClick` and sends an option packet, not a LivingObjectPane movement packet. The best current source placement is [UID:0000M7] `OptionPane` as a file-static legacy option/size table, with formal C++ intentionally blank until readers, exact helper pages, or a final declaration shape are proven.
```

### [UID:0001KM] LivingObjectPaneLocalPlayerExtensions

Placement: in `## Deferred Child Candidates`, replace the current one-paragraph candidate list with the same list minus `0x005a8b80-0x005a8c5c` and `0x005a8c60-0x005a8ce7`, then add this paragraph immediately after it:

```text
The `0x005a8b80-0x005a8c5c` setter island and successor `0x005a8c60-0x005a8ce7` should no longer be treated as LivingObjectPane deferred candidates. A 2026-06-18 B001 raw PE reanalysis for [UID:00027W] found zero caller/pointer/rel32 routes into `0x005a8b80` or `0x005a8c20`, while `0x005a8c60` has direct calls only from [UID:0001DW] `NewOptionPane::OnMouseClick` at `0x00540a58`, `0x00540aa2`, and `0x00540ab4` and sends an option packet. Keep those ranges as OptionPane-neighborhood orphan/helper candidates, not LivingObjectPane movement or local-player packet code.
```

Replacement candidate list:

```text
The following B001 candidates were not promoted in this pass because B001 explicitly left their ownership, source naming, or vtable/caller evidence below exact-child quality: `0x005a3890-0x005a38c4`, `0x005a39a0-0x005a39d4`, `0x005a57a0-0x005a5811`, `0x005a5820-0x005a58bc`, `0x005a5990-0x005a59fa`, `0x005a5a80-0x005a5a85`, `0x005a89d0-0x005a8ad6`, `0x005a8fc0-0x005a94a4`, `0x005a95e0-0x005aa0c0`, `0x005aba80-0x005abb1a`, `0x005abc70-0x005abd99`, `0x005ac000-0x005ac061`, `0x005acf10-0x005acf5f`, and `0x005acfe0-0x005ad02c`.
```

### [UID:0000M7] OptionPane

Placement: in `## Proposed Contents`, add this row after the `NewOptionPane` row:

```text
| [UID:00027W] `0x0066decc-0x0066dee0` | first-row writes from no-route raw helpers `0x005a8b80` and `0x005a8c20`; neighboring live helper `0x005a8c60` is called by `NewOptionPane::OnMouseClick` and sends option packet `0x1b` | Provisional file-static legacy option/size word table. Keep formal C++ blank until exact helper pages and final table grouping are proven. |
```

Placement: in `## Boundaries`, add:

```text
- Treat `0x005a8b80-0x005a8c5c` and `0x005a8c60-0x005a8ce7` as discontiguous OptionPane-neighborhood helper candidates, not LivingObjectPane. The first two raw no-route helpers write [UID:00027W]'s first-row size words; `0x005a8c60` is directly called from `NewOptionPane::OnMouseClick` and sends a four-byte option packet beginning with `0x1b`.
```

### [UID:000097] NewOptionPane And [UID:0001DW] NewOptionPane

Placement: in `NewOptionPane.md` `## Under Review`, and in [UID:0001DW] near the `Discontiguous Related Code` or `Server/Packet Helper Recheck` area, add:

```text
- `0x005a8c60-0x005a8ce7` is a discontiguous option-packet helper used by `NewOptionPane::OnMouseClick` cases that pass selectors `7`, `3`, and `1`. Raw disassembly writes packet bytes `0x1b`, `0x01`, the selector byte, and a `selector == 0` byte, then queues four bytes through `0x00574bb0` using `dword_67A7EC`. This helper should be routed through OptionPane/NewOptionPane support and should not be used as LivingObjectPane-local-player evidence.
```

### Optional Future Child Pages

No child pages are required for this report to close [UID:00027W]. If the supervisor later wants exact helper docs, recommended child names/ranges are:

```text
0x005a8b80-0x005a8c16.OptionPaneSetLegacySizeWordsFromThresholds.md
0x005a8c20-0x005a8c5c.OptionPaneSetLegacySizeWordsFromScaleLevel.md
0x005a8c60-0x005a8ce7.NewOptionPaneSendOptionPacket1BSelector.md
```

The first two should stay no-formal-C++ until a caller/source-route policy is chosen. The third is live and likely eligible for normal OptionPane/NewOptionPane helper documentation after exact child creation.

## Coverage Report Replacement Text

Placement context: replace the current [UID:00027W] row in `by-memory/-coverage-report.md` under the `.data` child list, between [UID:00027V] `MusicControlDriveRootBuffers` and [UID:0001OM] `FriendNameListSyncEnabled`. Do not edit this shared report directly from B001.

Current stale row:

```text
    - [UID:00027W][0x0066decc-0x0066dee0.LivingObjectPaneWordSlots_66DECC](by-memory/0x0066decc-0x0066dee0.LivingObjectPaneWordSlots_66DECC.md) 0x0066decc-0x0066dee0 | mutable word slots | LivingObjectPaneSharedWordSlots : reconstructable : 80% : strong : Existing IDA evidence documents five live `0x0050` word slots with two writer routines, five provisional `0x0028` tail words with no direct xrefs, exact predecessor/successor boundaries, LivingObjectPane parent-gate rationale, source-declared/generated-binary rebuild handling, and concrete writer-split follow-up while A007 MCP refresh timed out after `tools/list`.
```

Replacement row:

```text
    - [UID:00027W][0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC](by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md) 0x0066decc-0x0066dee0 | legacy option size word table | OptionPaneLegacySizeWordTable : reconstructable : 87% : strong : Raw PE/Capstone reanalysis confirms a first row of five write-referenced `0x0050` words, a second row of five no-xref `0x0028` words, no reads or hidden VA/RVA/pointer/rel32 routes to the two setter starts, and hard predecessor/successor boundaries; stale LivingObjectPane ownership is rejected because successor `0x005a8c60` is a `NewOptionPane::OnMouseClick` option-packet helper, so [UID:0000M7] `OptionPane` is the best provisional source owner while formal C++ remains blocked by no-reader/no-caller table-shape uncertainty.
```

## Validator Results

- No validator command was run because this assignment is report-only and no by-* docs or coverage reports were edited.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00027W-LivingObjectPaneWordSlots-source-quality.md`
- Modified: none outside the B001 research folder.
- Leases used: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00027W-LivingObjectPaneWordSlots-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00027W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
