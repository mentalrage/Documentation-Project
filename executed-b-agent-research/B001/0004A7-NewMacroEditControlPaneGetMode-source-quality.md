** TARGET-REPORT-UID:0004A7 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0004A7 NewMacroEditControlPane GetMode Source Quality


## Finalized Report / Current Recommendation

- Current implementation: UID0004A7 remains the exact source-authored
  `NewMacroEditControlPane` accessor at `[0x0057f9c0,0x0057f9c7)` and was
  validator-aware UID-preservingly renamed from
  `NewMacroEditControlPaneGetMode` to
  `NewMacroEditControlPaneGetSpellMode`.
- Applied disposition: emit
  `unsigned char NewMacroEditControlPane::GetSpellMode() const`, returning the
  byte field `m_spellMode` at complete-object offset `+0x10e` unchanged.
- Applied metadata: UID0004A7 is `92/94` and retains
  `CANONICAL_OWNER:000095`, `RECONSTRUCTABLE:TRUE`,
  `EMITTER_UIDS:000095`, blank optional position, and `Nested:0`.
- Applied paired action: UID0004AB was validator-aware UID-preservingly renamed
  from `SetMode` to `SetSpellMode`, is `92/94`, and the row-control API,
  constructor, complete class declaration, paint/input bodies, and
  NewMacroDialog save/load calls now use the exact accepted `unsigned char`
  spell-mode contract and managed blocks below.
- No split, merge, new child, new owner, new source file, vtable body, explicit
  padding member, boolean narrowing, or compiler-wrapper source is required.
- The accepted callback is implementation-complete. Scoped validators and the
  final waited generated refresh passed, all B001 leases are released, manual
  coverage remains supervisor-owned, and B001 performed no report execution,
  lifecycle, count, move, or archive command.
- Confidence: very strong for binary behavior, ABI, field width and offset,
  caller and storage lifecycle, owner/emitter, source placement, and the
  `unsigned char` decision; strong for the inferred source-facing
  `GetSpellMode` / `SetSpellMode` / `m_spellMode` lexical family.

## Supporting Research

- Historical initial active-report roots checked with target UID, address,
  current name, historical name, class, storage, and source-family terms:
  - `tools/leaser/Agents/Agent-B001/research`
  - `tools/leaser/Agents/Agent-B002/research`
  - `tools/leaser/Agents/Agent-B003/research`
  - `tools/leaser/Agents/Agent-B004/research`
  - `tools/leaser/Agents/Agent-B005/research`
  - Initial duplicate/lease-preflight result: no direct target report and no
    active overlapping UID0004A7 assignment.
- Central executed reports searched and opened:
  - `executed-b-agent-research/B005/0004A6-NewMacroEditControlPaneGetKey-source-quality.md`,
    SHA256
    `AF8D895A270073F0EED4F4009AAD256F0AF9CABB515A11C553CB6858BCE283CB`:
    adjacent getter and complete key/compact-record lifecycle support. It
    treated UID0004A7 as verify-only and correctly preserved arbitrary byte
    behavior, but it was not a direct target pass and retained the generic
    `GetMode` / `SetMode` and `uint8_t` spelling.
  - `executed-b-agent-research/B005/0004A1-SpellMacroEditControlPaneGetSpellKey-source-quality.md`,
    archived SHA256
    `D6455A66556D1DF1463BE30286C16197DB16B4B46079CE2A39F5172438DF6C56`,
    70,066 bytes / 755 lines, supervisor execution command
    `000000014400`: final adjacent Spell-key support. It establishes
    `wchar_t GetSpellKey`, `wchar_t m_spellKey`, the complete Spell
    constructor/input/paint/save/persistence/runtime lifecycle, and the
    applied UID0004A1/by-class manual rows. It does not target or override the
    independently researched New-macro `+0x10e` mode byte.
  - `executed-b-agent-research/B001/0001IK-MacroEditControlPanes-empty-emitter-source-quality.md`,
    SHA256
    `C244E59CFAAF12EB893C0203F5CF26D45AE1B24152734713154CBA872A13CCE2`:
    direct split/range/owner support. It created the exact target child and
    padding inventory but used provisional generic mode names and type.
  - `executed-b-agent-research/B010/0001DR-MacroDialogs-source-quality.md`,
    SHA256
    `235179AA1101DFB7C57897327D028734DEF548624B9833A0D61934273FED34D6`:
    direct NewMacroDialog construction/save/load and compact-record support.
    Its generic key/mode vocabulary is historical lead material rather than a
    target-specific type/name conclusion.
  - `executed-b-agent-research/B003/0003UA-UserPaneDispatchConfiguredShortcutHotkey-source-quality.md`,
    SHA256
    `CBF904524713FA38CE76C5FC14D9DB65B74D05E96FEC337125746BEDBD31D86D`:
    authoritative current runtime support for
    `CompactShortcutRecord { wchar_t code; unsigned char isSpellMode; }`,
    natural tail alignment, and arbitrary nonzero spell/command routing.
  - `executed-b-agent-research/B013/00019T-ProfileLoadAndLegacyImport-source-quality.md`,
    SHA256
    `D9FA93641748A425CA5C008F5984150ABB365081C67282FC9D1B6631CD0EEC82`:
    profile default/load/migration support for the same record fields.
  - `executed-b-agent-research/B005/0001AV-SaveUserSettings-empty-emitter-source-quality.md`,
    SHA256
    `2375F3BA183C08E3F303E1E003DAB77E0700403C0D5D1A851791DFF6B124D468`:
    exact profile writer support, serializing nonzero as `S` and zero as `I`.
  - `executed-b-agent-research/B002/0001IM-NewMacroEditControlPaneTeardownHelper-empty-emitter-source-quality.md`,
    SHA256
    `08B6910D9EE9F02146F61C369A8A4F5907509457D43DE13EA47C07C7D5B11A6E`:
    class/compiler boundary support only.
  - `executed-b-agent-research/B003/0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality.md`,
    SHA256
    `B4AC2DAE09993331B3C5171ED4CC15577E7EFF747D66E17CE5B117C413252908`:
    vtable negative/support evidence; the target is not a virtual slot.
- `tools/leaser/Agents/Older-Research` and
  `tools/leaser/Agents/SpecialReports` were searched with
  `0004A7`, `UID0004A7`, `0x0057f9c0`, `NewMacroEditControlPaneGetMode`,
  `GetModifier`, `isSpellMode`, and `MacroDialogs`; neither root contained a
  relevant match.
- Explicit duplicate conclusion: no direct active, older, special, or central
  executed UID0004A7 report exists. The matching reports are parent, adjacent,
  storage, caller, persistence, compiler, or vtable support and do not
  substitute for this direct target report.
- Current executed-support and callback recheck:
  B005's adjacent UID0004A1 Spell-key work is a completed supervisor-executed
  artifact. The stable shared split parent and MacroDialogs file preserve
  the complete B005 union while incorporating UID0004A7. Their current
  ordinary hashes are
  `39527A4D4A09356F6EF872E970D4961533A0540F51C311EA2191D2B63BB325DF`
  for UID0001IK and
  `A0F16DC929FFF8867CF95C691CF1523B40F32BCC739E9251A3C8DEAA90188FE2`
  for UID0000KY. The added `wchar_t` Spell-key lifecycle is same-or-greater
  adjacent support and does not change this report's unsigned-byte
  spell-mode conclusion or callback scope.
- Current UID0004A7 callback state: B001 applied the accepted ordinary edits,
  two UID-preserving renames, short leases, scoped validators, and final waited
  generated refresh enumerated below. B001 did not edit manual coverage,
  generated output, tracker, audit, supervisor, validator-state, lifecycle,
  queue, lock, or IDA files manually and did not run `execute_report`, any
  report lifecycle/count command, move, or archive operation. Current report
  validation, coverage application, execution, count, path movement, and
  archive state remain external supervisor/validator-owned.

## Target

- Target UID: `0004A7`.
- Current target path:
  `by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md`.
- Historical pre-callback path:
  `by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetMode.md`;
  it no longer exists.
- Source queue: `auto-generated/-ag-research-tracker.md`, `## by-memory`,
  `### Not-Covered Files - Reconstructable`.
- Current tracker row: renamed target at `92/94`, reconstructable true.
- Current target SHA256:
  `71B7E202E354C4547A578C820736CAADD72284975C4FB69987AB15D9307D964C`.
- Exact address range: `[0x0057f9c0,0x0057f9c7)`, seven bytes.
- Current owner/emitter: UID000095 `NewMacroEditControlPane`.
- Split parent: UID0001IK `MacroEditControlPanes`.
- Source file owner: UID0000KY `MacroDialogs`,
  `NexusTK/ui/dialogs/MacroDialogs.cpp`.

## Current Target State

- Applied metadata:
  - `COMPLETION:92`
  - `CONFIDENCE:94`
  - `CANONICAL_OWNER:000095`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:000095`
  - blank `EMITTER_POSITION_OPTIONAL`
  - `Nested:0`
- Current formal source is Destination 1 exactly:
  `unsigned char NewMacroEditControlPane::GetSpellMode() const`, returning
  `m_spellMode`.
- The target page now contains exact boundary, PE mapping, bytes/hash,
  signature, CFG, ABI, caller, field liveness, no-bool/no-enum proof, naming
  ranking, padding hashes, vtable negatives, persistence/runtime lifecycle,
  source placement, negative evidence, and score rationale.
- Current support is coherent:
  - Config/runtime retain `unsigned char isSpellMode` with arbitrary
    zero/nonzero semantics.
  - UID000095, UID0004A8, UID0004AB, UID0004AD, UID0004AE, UID00049N, and
    UID00049O use the accepted `GetSpellMode` / `SetSpellMode` /
    `m_spellMode` vocabulary and exact managed bodies.
  - Historical generic mode/modifier names appear only as explicitly
    superseded evidence.
  - The current `SetRecordIndex` / `m_recordIndex` union remains intact for
    B003's separately serialized work; UID0004A9 was not edited.
- Current generated `MacroDialogs.cpp` carries external validator command
  `000000014433`, refreshed
  `2026-07-16T17:19:55-04:00`. Its SHA256 is
  `5B3D62C167BDDDAB5DF5814879173AD120F07AAAF43AAAC9E9CE098A9B6C2640`,
  34,914 bytes / 1,052 lines. The UID000095 region contains exactly one
  complete class, one UID0004A7 marker and getter definition, one UID0004AB
  marker and setter definition, one `wchar_t m_key`, one
  `unsigned char m_spellMode`, zero Empty Emitter Markers, zero current
  `GetMode`/`SetMode`/`m_mode` tokens, zero raw `+0x10e` source token, zero
  handwritten vptr/vtable/RTTI token, and address order UID0004A6, UID0004A7,
  UID0004A8, UID0004A9, UID0004AA, UID0004AB, UID0004AC, UID0004AD,
  UID0004AE, UID0004AF. Unrelated whole-file `GetMode`/`SetMode` uses belong
  only to the preserved `TextEditPane` union. B001's final waited command was
  `000000014428`; the later validator-owned refresh retained every target and
  executed-B005 assertion.
- The source-quality and cross-document coherence blockers are resolved. No
  B001 implementation work remains.

## Executive Recommendation

- Keep the target as an ordinary nonvirtual public const member of
  `NewMacroEditControlPane`.
- Rename the target source identity and page to `GetSpellMode`; rename the
  paired UID0004AB setter/page to `SetSpellMode`; use `m_spellMode` for the
  complete-object `+0x10e` field.
- Use `unsigned char`, not `bool`, because constructor and load callers
  zero-extend and pass the stored byte unchanged, the setter stores it
  unchanged, the getter returns it unchanged, save stores AL unchanged, and
  consumers test zero/nonzero.
- Use `unsigned char`, not plain `char`, because the storage contract is
  explicitly unsigned and no signed interpretation exists.
- Use `unsigned char`, not `uint8_t`, because the exact project-era storage
  declaration and neighboring byte APIs use the fundamental spelling, while
  `uint8_t` adds no behavioral information.
- Reject a C++ enum because the binary preserves arbitrary one-byte values,
  uses no enum-range comparison, and pre-C++11 MSVC enum storage would
  ordinarily be `int` without a nonportable packing decision.
- Raise the target and paired setter to `92/94`; raise the fully audited
  constructor to `91/94`; retain all other listed support scores unless the
  later authorized implementation discovers a direct current contradiction.

## Supervisor Active Recheck

- Historical triggering instruction: perform a fresh report-only
  source-quality pass on UID0004A7 with mandatory healthy IDA MCP and resolve
  every score, C++, type, value-domain, name, caller, and source-placement
  blocker.
- Split repair: not required. UID0004A7 is already an exact seven-byte child
  inside the correct non-emitting UID0001IK split index.
- Source-bearing inventory: the target, constructor, setter, paint, input,
  NewMacroDialog save, and NewMacroDialog load all have exact existing child
  pages. No child is missing.
- Compiler support inventory: UID0001IM, UID0004AV, UID0001IN, UID0003DB, and
  UID0001Y1 already separate complete-object destructor glue, scalar wrapper,
  adjustor thunks, vtable data, and type-level vtable evidence from source
  methods.
- Padding inventory: both target-adjacent spans already appear in
  `by-memory/-ignored.md`; no new ignored row is needed.
- Current lifecycle recheck:
  B005 UID0004A1 remains executed at supervisor command `000000014400`.
  UID0004A7 implementation is complete and validated as enumerated below.
  B001 itself performed no manual coverage, execute, lifecycle, count, move,
  or archive action; those states remain external supervisor/validator-owned.

## Inference Research Guidance Check

- Binary facts, current documentation, and source inference are separated
  throughout this report.
- Existing `GetMode`, `SetMode`, `m_mode`, `uint8_t`, and historical
  `GetModifier` / `SetModifier` were treated as hypotheses rather than
  authority.
- The source-type decision uses caller code generation, raw byte transport,
  persistence and runtime behavior, and the current complete Config
  declaration, not only the seven-byte target body.
- The source-name decision uses the full item/inventory versus spell/command
  lifecycle and rejects both keyboard-modifier wording and generic inherited
  Pane mode wording.
- Existing generated C++ is treated as a current documentation projection.
  IDA MCP and raw PE bytes are the binary authority.
- Stale Wave2/Wave3 traces were encountered only in
  `by-memory/-report.old.md` and `traces_loaded.wave2_annotated.txt`. Their
  `GetModifier` / `SetModifier` labels are explicitly rejected as current
  authority because those systems are stale and the semantic field is not an
  Event key-modifier byte.

## Heuristic / Inference Reanalysis And Validation

1. Exact function identity is closed. IDA models `sub_57F9C0` at
   `0x0057f9c0`, size `0x7`, ending at `0x0057f9c7`.
2. Exact body is closed. The seven bytes are
   `8A 81 0E 01 00 00 C3`; SHA256 is
   `49FF53A81E86CCC1D7CFFD9851D443C0141A871919E85F42812ABBDDB81BCFF6`.
3. CFG is closed. The body has one basic block, two instructions, complexity
   one, no stack locals beyond the return address, no callees, no strings, and
   no constants.
4. ABI is closed. ECX is the x86 `this` receiver, there are no stack
   arguments, and the byte is returned through AL. IDA's `char` result is a
   width observation, not signed-source proof.
5. Field offset is closed. `mov al,[ecx+0x10e]` reads the complete-object byte
   after `int m_recordIndex` at `+0x108` and `wchar_t m_key` at `+0x10c`.
6. Caller inventory is closed. The sole target xref is code call
   `0x0053f1e0` inside `sub_53F180`, current source role
   `NewMacroDialog::SaveMacroEntries`.
7. Save behavior is closed. After the call, `mov [esi+0x28f296],al` stores the
   exact returned byte into the selected
   `CompactShortcutRecord::isSpellMode`. There is no compare, mask,
   conversion, or normalization.
8. Constructor transport is closed. At `0x0053ef20`, the caller performs
   `movzx eax,byte ptr [edx+2]`, pushes that value, and calls the row
   constructor at `0x0053ef2c`. A source `bool` conversion would require
   semantic normalization; the observed path preserves the byte value.
9. Constructor storage is closed. UID0004A8 loads only the low byte from its
   third argument home and stores it directly to `+0x10e`. Its exact
   91-byte body SHA256 is
   `8CEA15F59FD3F3DB9AC299D2884411491AF967ABB156DA6292680AD43B42F6F9`.
10. Load transport is closed. UID00049O executes
    `movzx eax,byte ptr [esi+0x28f29e]`, pushes it, and calls UID0004AB at
    `0x0053f28d`. No boolean conversion appears.
11. Setter behavior is closed. UID0004AB is `[0x0057fa60,0x0057fa70)`,
    bytes `55 8B EC 8A 45 08 88 81 0E 01 00 00 5D C2 04 00`, SHA256
    `B35EC9AA6370F008E9A91060AE79FDF1E41E12E2BCA4BCE4CF4AF90F788D1F85`.
    It stores the low input byte unchanged and has one direct load-page caller.
12. Input mutation is closed. UID0004AE writes `setz al` from
    `activeChild == 3` and stores AL to the adjusted receiver field
    corresponding to complete-object `+0x10e`; this writer produces canonical
    zero or one but does not narrow values supplied by constructor/load.
13. Paint semantics are closed. UID0004AD tests the field for zero/nonzero
    both when selecting the item-inventory versus spell record and when
    drawing literal `Item` versus `Spell`. It does not compare specifically
    with one.
14. Persistence semantics are closed. Defaults and profile load commonly
    produce zero/one; save serializes any nonzero byte as `S` and zero as `I`.
15. Runtime semantics are closed. UID0003UA tests
    `shortcut.isSpellMode != 0`; nonzero routes to `UseCommandSlot`, zero to
    `UseInventorySlot`.
16. Value domain is therefore a raw unsigned byte with semantic zero/nonzero
    interpretation. Canonical writers usually produce zero/one, but the UI
    constructor/load/getter/setter/save chain preserves a noncanonical nonzero
    byte unchanged.
17. `bool` is rejected because it would express and normally enforce a
    canonical logical value at API boundaries, contradicting the observed raw
    pass-through and current Config no-bool conclusion.
18. Plain `char` is rejected because no signed operation exists and the
    source record is explicitly unsigned.
19. `uint8_t` is ABI-compatible but rejected as the strongest source spelling
    because current source-family declarations use `unsigned char`, the
    original code era does not require a fixed-width typedef here, and the
    typedef does not clarify semantics.
20. An enum is rejected because there is no exact-one test or range dispatch,
    arbitrary nonzero values survive, and a one-byte pre-C++11 enum would
    require an unsupported packing/underlying-type assumption.
21. `GetModifier` / `SetModifier` is rejected. Event key modifiers reside in
    the Event payload and are only an input to key narrowing; the target byte
    is selected from active inventory/spell tabs and persisted as
    `isSpellMode`.
22. Generic `GetMode` / `SetMode` / `m_mode` is source-legal but weaker. It
    obscures the item/spell role and the setter hides inherited
    `Pane::SetMode(unsigned char)`, which controls Pane rendering state at a
    different offset.
23. `IsSpellMode` is semantically clear but weaker as an accessor name because
    the exact return type is an arbitrary unsigned byte, not a guaranteed
    source bool.
24. `GetSpellMode` / `SetSpellMode` / `m_spellMode` is the strongest balanced
    source-facing family: it states the domain, preserves byte transport, and
    avoids the inherited Pane mode collision.
25. Ownership is closed. The receiver field, constructor, paired setter,
    paint/input methods, class vtables, and exact class declaration all belong
    to UID000095.
26. Source placement is closed. The class and its NewMacroDialog callers
    already emit through UID0000KY `MacroDialogs`; Config, ProfileStorage, and
    UserPane are storage/persistence/runtime consumers, not owners.
27. Vtable disposition is closed. The target has no data/vtable xref and is
    not one of the New primary/secondary/tertiary virtual cells. UID0003DB and
    UID0001Y1 remain compiler/source-declaration support only.
28. Range and padding are closed. No split or endpoint repair is needed.
29. Generated-source blocker is closed. Current output has one target body and
    no empty marker; a later authorized implementation would replace stale
    type/name tokens without adding a second body.
30. Score blockers are closed. Exact bytes, ABI, caller, type, value domain,
    field, names, owner, emitter, source placement, range, C++, negatives, and
    manual coverage handoff are all implementation-ready.

## Evidence Standards Used

- Direct IDA MCP evidence:
  `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `disasm`,
  `decompile`, `analyze_function`, `xrefs_to`, `callees`, `stack_frame`,
  `make_signature`, `search_text`, and `find_bytes`.
- Independent raw PE evidence:
  read-only bytes from
  `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, size `2,679,296`,
  SHA256
  `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Documentation evidence:
  target, class, file, split parent, constructor, setter, paint, input,
  NewMacroDialog caller pages, Config class/file, profile-layout type,
  runtime dispatcher, vtable pages, ignored padding, generated source,
  manual coverage, tracker, and matching executed reports.
- Negative evidence:
  no second target caller, no target data/vtable refs, no end-address ref, no
  target callees/strings/constants, no bool normalization, no enum dispatch,
  no independent tail-byte lifecycle, no new source-file need, and no split
  need.
- Evidence ladder:
  exact bytes/instructions and direct caller code generation outrank IDA
  inferred signedness; complete current storage/runtime documentation
  outranks stale Wave2 names; source-era naming inference is used only after
  behavior, width, and placement are closed.
- Remaining uncertainty is lexical only. No remaining uncertainty changes
  behavior, ABI, layout, route, or compilability.

## Evidence Checked

- MCP discovery and health:
  - Streamable MCP endpoint `http://127.0.0.1:13337/mcp`.
  - `initialize` returned server `ida-pro-mcp 1.0.0`.
  - `idb_list` returned one active NexusTK worker session `64c11373`, worker
    PID `21508`, `is_analyzing:false`.
  - Valid `server_health(database=64c11373)` returned `status:ok`,
    `auto_analysis_ready:true`, `hexrays_ready:true`,
    `strings_cache_ready:true`, imagebase `0x00400000`.
- Target MCP checks:
  - `lookup_funcs`:
    target `0x0057f9c0` size `0x7`; GetKey `0x0057f9b0` size `0x8`;
    constructor `0x0057f9d0` size `0x5b`; setter `0x0057fa60` size `0x10`;
    paint `0x0057faa0` size `0x1d6`; input `0x0057fc80` size `0x7f`;
    save `0x0053f180` size `0x83`; load `0x0053f210` size `0xa6`.
  - `get_bytes(0x0057f9a0,208)` captured target, both adjacent getters,
    constructor, setter, and alignment.
  - `disasm` target: `mov al,[ecx+10Eh]`; `retn`; two instructions total.
  - `decompile` target: byte element `this[270]`.
  - `analyze_function` target: one block, complexity one, no callees,
    caller `sub_53F180`, code xref `0x0053f1e0`.
  - `xrefs_to`: one target code xref; zero xrefs to `0x0057f9c7`; one setter
    code xref at `0x0053f28d`.
  - `make_signature` returned exact unique signature
    `8A 81 0E 01 00 00`.
  - `find_bytes` returned the complete seven-byte target pattern exactly once.
  - bounded `search_text` across `[0x0057f750,0x005807c5)` found complete
    `+0x10e` direct accesses at getter, constructor, setter, and two paint
    reads; the adjusted EventHandler store is separately confirmed by
    decompile/disassembly.
- Caller MCP checks:
  - NewMacroDialog constructor callsite `0x0053ef20-0x0053ef2c` performs raw
    byte zero-extension and push.
  - save callsite `0x0053f1e0` stores AL at `0x0053f1ea`.
  - load callsite `0x0053f283-0x0053f28d` performs raw byte zero-extension and
    push.
  - input writer uses `setz al` then stores to the adjusted field.
  - paint uses two zero/nonzero reads and the `Item` / `Spell` literals.
- Raw PE checks:
  - target RVA `0x17f9c0`, raw file offset `0x17edc0`;
  - exact target bytes/hash match MCP;
  - `[0x0057f9b8,0x0057f9c0)` is eight `0xcc`, SHA256
    `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`;
  - `[0x0057f9c7,0x0057f9d0)` is nine `0xcc`, SHA256
    `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`;
  - setter and constructor hashes match the values recorded above.
- Historical initial report-only ordinary docs opened:
  UID0004A7, UID0004AB, UID0004A8, UID000095, UID0000KY, UID0001IK,
  UID00049J, UID00049N, UID00049O, UID0004AD, UID0004AE, UID0001VR,
  Config class/file, UID0003UA, UID0001Y1, UID0003DB, and
  `by-memory/-ignored.md`.
  - The final pre-callback read-only current-union recheck after B005 execution
    confirmed the evidence-time
    UID0001IK SHA256
    `543C25D41D95F4C61B48006CF9BD5CF7D970DADD92039B121DDDCC44AB99F3E7`
    and UID0000KY SHA256
    `88BA4D31E430DE47374C90102116FA89E715A9420BE57962EAE20B31458BF105`.
    B005's executed additions closed only the adjacent Spell-key source type as
    `wchar_t`; at that pre-callback time the shared docs still left New
    `GetMode` / `SetMode` and `uint8_t` current. The later callback resolved
    those defects as recorded in current-state sections.
- Historical initial generated source baseline opened read-only:
  `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`.
  - Latest evidence-time provenance:
    supervisor waited verification command `000000014399`; embedded generated
    header command `000000014395`, refreshed
    `2026-07-16T16:48:26-04:00`; SHA256
    `BD3BDD5AB8A7B984F55A4BE8EDB9429A4F334E0A8EDF13E693B3332AB8434A3C`,
    34,748 bytes / 1,048 lines.
  - This was the pre-callback baseline. The later B001 callback and current
    external validator refreshes are recorded under Validator Results.
- Historical initial manual coverage baseline opened read-only:
  `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`,
  `by-file/-coverage-report.md`, and
  `by-type/by-struct/-coverage-report.md`.
  - Supervisor commands `000000014397` and `000000014398` applied and
    validated B005's UID0004A1 by-memory row and UID0000DQ by-class row.
  - Evidence-time hashes were by-memory
    `9BDD57D6A8C1F5849E266E134A28BDDA2714E493961A4811DC3C41A046EEA1CC`,
    by-class
    `CB0FAFE2951D401180E105D419F7CF46B19092ABA2BC024CDF9762A93223DF8F`,
    by-file
    `280C5E3D281D8166B3950851F0E450F841A54623A20D02C7514FE221C4E14E57`,
    and by-struct
    `1B794F9B0E9AD32D6A0901FC69E9CA99C6F335B26D50E12881DEDFAC4C6F80A6`.
- Historical initial tracker baseline opened read-only:
  `auto-generated/-ag-research-tracker.md`.
  - Latest evidence-time snapshot:
    SHA256
    `3F0D8388EE5C904E0E7A7EFBAB4C3199F002EF901ADA90F4020BF7CEED11D6AA`,
    1,508,722 bytes / 6,131 lines.
  - UID0004A7 was `86/90`, reconstructable true, direct report count zero, at
    the original target path before callback.
  - UID0004A1 now appears at `92/94` with one executed B005 report, confirming
    the adjacent report's completed lifecycle without changing UID0004A7.
- Tool-call limitations recorded honestly:
  - The first PowerShell `Invoke-WebRequest` attempt lacked
    `-UseBasicParsing` and failed in the local PowerShell 5.1 client before an
    MCP request was parsed.
  - The first helper function used PowerShell's automatic `$args` name and
    accidentally omitted tool arguments, producing `database is required`.
    This was a malformed client request, not worker loss.
  - The helper was corrected to `$toolArgs`; all subsequent bounded valid
    calls against database `64c11373` succeeded.
- Phase-qualified action boundary:
  during the initial report-only evidence pass, IDA mutation, broad
  whole-program searches, validators, generated refresh, leases, ordinary
  edits, coverage edits, report lifecycle commands, and report execution were
  intentionally not performed. During the accepted implementation callback,
  the ordinary edits, short leases, scoped validators, and final generated
  refresh enumerated later were performed. IDA mutation, manual coverage
  edits, report execution, lifecycle/count commands, move, and archive
  operations remained unperformed by B001.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C4A7-001 | UID0004A7 is exactly `[0x0057f9c0,0x0057f9c7)`, size seven. | Very strong | MCP lookup/disasm/raw PE | UID0004A7 status/evidence | incorporate | applied |
| C4A7-002 | Exact bytes are `8A 81 0E 01 00 00 C3`, SHA256 `49FF53...BCFF6`. | Very strong | MCP get_bytes and raw PE | UID0004A7 binary evidence | incorporate | applied |
| C4A7-003 | Target is PE `.text` at RVA `0x17f9c0`, raw offset `0x17edc0`. | Very strong | Imagebase and raw PE | UID0004A7 binary evidence | incorporate | applied |
| C4A7-004 | Exact complete pattern occurs once and needs no wildcard. | Very strong | make_signature/find_bytes | UID0004A7 signature evidence | incorporate | applied |
| C4A7-005 | Body has one block, two instructions, complexity one. | Very strong | disasm/analyze_function | UID0004A7 CFG evidence | incorporate | applied |
| C4A7-006 | ABI is ordinary x86 thiscall, ECX receiver, no stack arguments. | Very strong | disasm/stack_frame | UID0004A7 ABI evidence | incorporate | applied |
| C4A7-007 | Result is one byte in AL; IDA `char` does not prove signed source. | Very strong | exact instructions/caller use | UID0004A7 type evidence | incorporate | applied |
| C4A7-008 | Getter reads complete-object field `+0x10e` unchanged. | Very strong | `mov al,[ecx+10e]` | UID0004A7/class/layout | incorporate | applied |
| C4A7-009 | Sole direct target caller is save callsite `0x0053f1e0`. | Very strong | xrefs_to/analyze_function | UID0004A7/UID00049N | incorporate | applied |
| C4A7-010 | Save stores returned AL unchanged into `record.isSpellMode`. | Very strong | save disassembly | UID0004A7/UID00049N | incorporate | applied |
| C4A7-011 | Target has zero data/vtable refs, zero end refs, and no second caller. | Very strong | xrefs_to/negative scan | UID0004A7/class negatives | incorporate | applied |
| C4A7-012 | Target has no callees, strings, constants, or side effects. | Very strong | analyze_function | UID0004A7 negatives | incorporate | applied |
| C4A7-013 | Predecessor gap `[0x0057f9b8,0x0057f9c0)` is eight `0xcc` bytes with recorded hash. | Very strong | raw PE/current ignored doc | UID0004A7/UID0001IK/ignored | already-present | already-present |
| C4A7-014 | Successor gap `[0x0057f9c7,0x0057f9d0)` is nine `0xcc` bytes with recorded hash. | Very strong | raw PE/current ignored doc | UID0004A7/UID0001IK/ignored | already-present | already-present |
| C4A7-015 | Source order is GetKey, GetSpellMode, constructor. | Very strong | addresses/current generated | UID000095/UID0000KY | incorporate | applied |
| C4A7-016 | UID0004A8 has one NewMacroDialog constructor caller at `0x0053ef2c`. | Very strong | analyze_function | UID0004A8 | incorporate | applied |
| C4A7-017 | Constructor caller zero-extends and passes raw `isSpellMode` with no bool normalization. | Very strong | selected caller disassembly | UID0004A8/type proof | incorporate | applied |
| C4A7-018 | Constructor stores record index/key/spell-mode at `+0x108/+0x10c/+0x10e`, then installs three vtables and selectable state. | Very strong | decompile/disasm | UID0004A8/class | incorporate | applied |
| C4A7-019 | UID0004AB exact bytes/hash and one-block direct store are closed. | Very strong | raw PE/MCP | UID0004AB | incorporate | applied |
| C4A7-020 | UID0004AB has one load-page caller at `0x0053f28d`. | Very strong | xrefs_to/analyze_function | UID0004AB/UID00049O | incorporate | applied |
| C4A7-021 | Load zero-extends and passes the raw record byte with no bool conversion. | Very strong | selected load disassembly | UID0004AB/UID00049O | incorporate | applied |
| C4A7-022 | Event input writes canonical zero/one using `activeChild == 3`. | Very strong | UID0004AE disasm/decompile | UID0004AE/class | incorporate | applied |
| C4A7-023 | Paint treats zero as item/inventory and any nonzero as spell. | Very strong | UID0004AD decompile/strings | UID0004AD/class | incorporate | applied |
| C4A7-024 | Runtime dispatch treats zero as inventory and nonzero as command/spell. | Very strong | UID0003UA current source/evidence | Config/type/runtime support | already-present | already-present |
| C4A7-025 | Profile writer serializes nonzero as `S` and zero as `I`. | Very strong | ProfileStorage/SaveUserSettings | persistence support | already-present | already-present |
| C4A7-026 | Defaults/load/migration usually produce zero/one but do not redefine API width. | Strong | Config/ProfileStorage reports/docs | lifecycle support | already-present | already-present |
| C4A7-027 | Constructor/load/getter/setter/save preserve a noncanonical nonzero byte unchanged. | Very strong | cumulative machine path | target/class/callers | incorporate | applied |
| C4A7-028 | Strongest source type is `unsigned char`. | Very strong | width, raw transport, current record type | all formal destinations | incorporate | applied |
| C4A7-029 | `bool` is rejected because no API-boundary normalization exists. | Very strong | constructor/load machine calls | target/class negatives | reject-invalid | applied |
| C4A7-030 | Plain `char` is rejected because no signed semantics exist. | Strong | storage contract and uses | target/class negatives | reject-invalid | applied |
| C4A7-031 | `uint8_t` is ABI-compatible but weaker than project-era `unsigned char`. | Strong | current Config/source style | target/class history | reject-stale | applied |
| C4A7-032 | Enum type is rejected because arbitrary byte values survive and no one-byte enum proof exists. | Strong | value-domain and compiler-era reasoning | target/class negatives | reject-invalid | applied |
| C4A7-033 | Best accessor name is `GetSpellMode`. | Strong | full semantic lifecycle and naming ranking | UID0004A7/class/callers | incorporate | applied |
| C4A7-034 | Best paired names are `SetSpellMode` and `m_spellMode`. | Strong | source coherence and inherited-mode distinction | UID0004AB/class/formals | incorporate | applied |
| C4A7-035 | Generic `GetMode`/`SetMode`/`m_mode` is historicalized as semantically weak and collision-prone. | Strong | Pane mode support/current class | affected docs history | historicalize | applied |
| C4A7-036 | Historical `GetModifier`/`SetModifier` is rejected because Event modifiers are separate input state. | Very strong | input body/storage lifecycle | affected docs history | reject-stale | applied |
| C4A7-037 | Direct canonical owner and emitter remain UID000095. | Very strong | receiver/layout/class/vtables | target metadata | already-present | already-present |
| C4A7-038 | Source file remains UID0000KY MacroDialogs. | Very strong | class/caller/address/source union | source placement | already-present | already-present |
| C4A7-039 | UID0001IK remains a non-emitting split index, not a body owner. | Very strong | current parent disposition | parent support | already-present | already-present |
| C4A7-040 | No split, merge, range repair, new child, or new ignored row is required. | Very strong | exact boundaries/current docs | range analysis | not-applicable | excluded-with-reason |
| C4A7-041 | Vtable/RTTI/thunk/destructor support remains compiler-generated and unchanged. | Very strong | UID0001Y1/UID0003DB/UID0001IM | compiler support | already-present | already-present |
| C4A7-042 | Rename UID0004A7 path/title while preserving the validator-issued UID. | Strong | source-name decision | target path/title | incorporate | applied |
| C4A7-043 | Rename UID0004AB path/title while preserving the validator-issued UID. | Strong | paired API decision | setter path/title | incorporate | applied |
| C4A7-044 | Raise UID0004A7 from `86/90` to `92/94`. | Very strong | closed blocker audit | target metadata | incorporate | applied |
| C4A7-045 | Raise UID0004AB from `86/90` to `92/94`. | Very strong | exact paired setter audit | setter metadata | incorporate | applied |
| C4A7-046 | Raise UID0004A8 from `87/90` to `91/94`. | Strong | complete constructor/caller/layout audit | constructor metadata | incorporate | applied |
| C4A7-047 | Preserve UID000095 at `92/94`, position 50, owner/emitter UID0000KY. | Very strong | complete current class union | class metadata | already-present | already-present |
| C4A7-048 | Update UID00049N and UID00049O calls to the accepted names; preserve their scores/routes. | Very strong | exact caller bodies | save/load formals/prose | incorporate | applied |
| C4A7-049 | Synchronize UID0004AD field token and item/spell semantics; preserve its score/route and all unrelated body detail. | Strong | exact paint behavior | OnPaint formal/prose | incorporate | applied |
| C4A7-050 | Synchronize UID0004AE field token and preserve canonical setcc behavior, score, route, and unrelated detail. | Very strong | exact input behavior | input formal/prose | incorporate | applied |
| C4A7-051 | Config class/file, UID0001VR, and UID0003UA already contain the exact unsigned-byte record/runtime contract. | Very strong | current docs/formals | verify-only support | already-present | already-present |
| C4A7-052 | Supply exact manual coverage target/setter/constructor insertions and class/file/save/load replacements; B001 must not apply them. | Strong | current manual rows | coverage handoff | incorporate | applied |
| C4A7-053 | Callback must use short leases, scoped validators for every changed ordinary page, then one waited target refresh and generated readback. | Very strong | workflow/affected destinations | implementation proof | incorporate | applied |
| C4A7-054 | B001 performed no ordinary edit, validator, lease, coverage edit, generated edit, IDA mutation, execute, lifecycle, move, or archive action in report-only phase. | Very strong | command/write audit | report lifecycle | incorporate | applied |

### Callback Claim Verification Notes

| Claim ID | Terminal proof |
| --- | --- |
| `C4A7-001` | Renamed UID0004A7 page retains exact `[0x0057f9c0,0x0057f9c7)` status; validator command `000000014401` preserved UID0004A7 and passed `ok:1`. |
| `C4A7-002` | UID0004A7 exact bytes and full SHA256 remain in the applied target evidence; final page SHA256 is `71B7E202...964C`. |
| `C4A7-003` | Applied target evidence retains `.text`, RVA `0x17f9c0`, and raw offset `0x17edc0`; no range/path mutation occurred beyond the semantic rename. |
| `C4A7-004` | Applied target signature section retains the unique complete seven-byte pattern and no-wildcard result. |
| `C4A7-005` | Applied target CFG section retains one block, two instructions, and complexity one. |
| `C4A7-006` | Applied target ABI section retains ordinary x86 thiscall, ECX receiver, and no stack arguments. |
| `C4A7-007` | Applied target type section records the exact AL result and rejects IDA `char` as signed-source proof. |
| `C4A7-008` | Destination 1 returns `m_spellMode`; current class/constructor/getter/setter union maps it to complete-object `+0x10e`. |
| `C4A7-009` | Applied target and UID00049N evidence retain sole callsite `0x0053f1e0`. |
| `C4A7-010` | Destination 7 stores `GetSpellMode()` directly into `record.isSpellMode`; command `000000014407` passed. |
| `C4A7-011` | Applied target negative evidence retains zero data/vtable refs, zero end refs, and no second caller. |
| `C4A7-012` | Applied target negative evidence retains no callees, strings, constants, branches, writes, or side effects beyond the field return. |
| `C4A7-013` | `by-memory/-ignored.md` remained unchanged at SHA256 `C4875C9D...DFE9`; the eight-byte predecessor alignment remains present. |
| `C4A7-014` | The same unchanged ignored page retains the nine-byte successor alignment; no duplicate row was added. |
| `C4A7-015` | Final generated UID000095 region orders UID0004A6, UID0004A7, UID0004A8 exactly; B001 command `000000014428` established it and current external command `000000014433` retains it. |
| `C4A7-016` | UID0004A8 page retains the one constructor caller at `0x0053ef2c`; command `000000014404` passed. |
| `C4A7-017` | UID00049J and UID0004A8 now record raw zero-extension/no-bool transport; commands `000000014412` and `000000014404` passed. |
| `C4A7-018` | Destination 3 and constructor prose retain `+0x108/+0x10c/+0x10e`, three compiler vptr stores, and selectable state without emitting compiler mechanics. |
| `C4A7-019` | Renamed UID0004AB retains exact bytes/hash, one-block low-byte store, and source-void conclusion; command `000000014402` passed. |
| `C4A7-020` | UID0004AB and UID00049O retain sole load-page callsite `0x0053f28d`; command `000000014408` passed. |
| `C4A7-021` | Destination 8 calls `SetSpellMode(record.isSpellMode)` after raw zero-extension; load prose records no bool conversion. |
| `C4A7-022` | Destination 6 preserves `m_spellMode = activeChild == 3`; UID0004AE records the exact `setz` zero/one writer and command `000000014406` passed. |
| `C4A7-023` | Destination 5 tests `m_spellMode != 0` in both item/spell selections; command `000000014405` passed. |
| `C4A7-024` | UID0003UA verify-only page remained current at SHA256 `A5E27EDD...92B2` with arbitrary nonzero runtime semantics. |
| `C4A7-025` | Existing persistence evidence remained unchanged; manual/source support continues to state nonzero `S`, zero `I`. |
| `C4A7-026` | Config/profile verify-only union remained unchanged; canonical writers may produce zero/one without narrowing the API. |
| `C4A7-027` | Destinations 1, 3, 4, 7, and 8 now preserve raw constructor/load/getter/setter/save byte transport; generated readback matches all five. |
| `C4A7-028` | All accepted target API/formal destinations use `unsigned char`; final generated UID000095 region contains one `unsigned char m_spellMode`. |
| `C4A7-029` | Target/class/caller negative sections now explicitly reject `bool`; generated source contains no bool boundary conversion for this state. |
| `C4A7-030` | Target/class history rejects plain `char`; no signed operation or declaration was introduced. |
| `C4A7-031` | Historical `uint8_t` wording is retained only as superseded evidence; current generated New row union has no `uint8_t mode`. |
| `C4A7-032` | Target/class negative evidence rejects enum storage; no enum declaration, switch, or range guard was introduced. |
| `C4A7-033` | UID0004A7 validator-preserved path/title and Destination 1 use `GetSpellMode`; old path is absent. |
| `C4A7-034` | UID0004AB, UID000095, constructor, paint, input, save, and load use `SetSpellMode` / `m_spellMode`; old setter path is absent. |
| `C4A7-035` | Generic names are historicalized in affected docs; final generated UID000095 region has zero `GetMode`, `SetMode`, or `m_mode` tokens. |
| `C4A7-036` | Modifier aliases are explicitly rejected in target/class/support history; Event modifiers remain separate input state. |
| `C4A7-037` | UID0004A7 metadata retains owner/emitter UID000095 and reconstructable true after command `000000014401`. |
| `C4A7-038` | UID0000KY remains the file root at `92/92`; final file SHA256 is `A0F16DC9...8FE2`. |
| `C4A7-039` | UID0001IK remains `91/93`, false, non-emitting, blank formal, `Nested:-4`; final SHA256 is `39527A4D...25DF`. |
| `C4A7-040` | No split/merge/new child/range repair/ignored row was created; existing target and setter UIDs were preserved. |
| `C4A7-041` | UID0001Y1, UID0003DB, UID0001IM, UID0004AV, and UID0001IN hashes were read back unchanged; generated UID000095 region has no handwritten vptr/vtable/RTTI token. |
| `C4A7-042` | Command `000000014401` performed the UID-preserving target path update and propagated six reference links. |
| `C4A7-043` | Command `000000014402` performed the UID-preserving setter path update and propagated six reference links. |
| `C4A7-044` | UID0004A7 current header is `92/94`; command `000000014401` recorded both score updates. |
| `C4A7-045` | UID0004AB current header is `92/94`; command `000000014402` recorded both score updates. |
| `C4A7-046` | UID0004A8 current header is `91/94`; command `000000014404` recorded both score updates. |
| `C4A7-047` | UID000095 remains `92/94`, owner/emitter UID0000KY, position 50, complete class closure before `[[CHILDREN]]`; command `000000014403` passed. |
| `C4A7-048` | UID00049N/UID00049O exact formals call `GetSpellMode`/`SetSpellMode`, retain `89/92`, and passed commands `000000014407`/`000000014408`. |
| `C4A7-049` | UID0004AD uses `m_spellMode` in both zero/nonzero branches, retains `88/91`, and passed command `000000014405`. |
| `C4A7-050` | UID0004AE uses `m_spellMode`, preserves setcc behavior and `90/93`, and passed command `000000014406`. |
| `C4A7-051` | Config class/file and UID0001VR hashes are unchanged at `9ECA9979...B473`, `91984E67...D577`, and `3A449A0C...3AB8`; UID0003UA remains `A5E27EDD...92B2`. |
| `C4A7-052` | Exact supervisor-owned insert/replace text remains below; current manual rows are still absent/stale and B001 changed no coverage file. |
| `C4A7-053` | Short leases were released after scoped commands `000000014401-000000014408`, `000000014412`, `000000014420`, `000000014424-000000014425`, and `000000014427`; final waited command `000000014428` passed with current generated assertions. |
| `C4A7-054` | The initial report-only no-action claim remains historically true; callback actions are separately enumerated, while B001 still performed no IDA mutation, manual coverage edit, execute, lifecycle/count, move, or archive command. |

## Positive Evidence Summary

- The exact target body directly returns the complete-object byte at `+0x10e`.
- The sole save caller writes the returned byte unchanged to
  `CompactShortcutRecord::isSpellMode`.
- Constructor and load callers pass the stored byte unchanged; the paired
  constructor and setter store it unchanged.
- Input produces zero/one with `setz`, while paint, persistence, and runtime
  use zero/nonzero semantics.
- Current Config/type/runtime documentation independently agrees on
  `unsigned char isSpellMode` and rejects `bool`.
- Class allocation, field order, vtable stores, direct callers, and generated
  source order converge on UID000095 and UID0000KY.
- Exact predecessor/successor padding and zero vtable/data refs exclude range
  or virtual-method ambiguity.
- The combined evidence resolves behavior, type, value domain, name, owner,
  emitter, source placement, range, and C++ without fallback-only inference.

## IDA MCP Facts

- Database: `64c11373`.
- Health: `status:ok`; analysis, Hex-Rays, and strings cache ready.
- Target function: `sub_57F9C0`, address `0x0057f9c0`, size `0x7`.
- Target instructions:
  - `0x0057f9c0`: load AL from receiver `+0x10e`.
  - `0x0057f9c6`: return.
- Target prototype currently inferred by IDA:
  `char __thiscall(_BYTE *this)`.
- Target caller: `sub_53F180`, callsite `0x0053f1e0`.
- Target xrefs: one code, zero data; end address has zero xrefs.
- Target callees: none.
- Target CFG: one block, complexity one.
- Exact pattern: unique complete seven-byte pattern at `0x0057f9c0`.
- Direct `+0x10e` accesses in the bounded class island:
  getter read, constructor write, setter write, and two paint reads.
- Constructor: `0x0057f9d0`, size `0x5b`, one caller at `0x0053ef2c`.
- Setter: `0x0057fa60`, size `0x10`, one caller at `0x0053f28d`.
- Paint: `0x0057faa0`, size `0x1d6`, vtable data xref only.
- Input: `0x0057fc80`, size `0x7f`, secondary vtable data xref only.
- New class vtable heads remain `0x0062d288`, `0x0062d2f0`, and
  `0x0062d320`; their refs are constructor, complete-object destructor glue,
  and scalar deleting wrapper stores, not target refs.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0057f9b0-0x0057f9b8` | UID0004A6 GetKey | Exact wchar key getter | true | UID000095 | `92/94` | Already present; predecessor source method |
| `0x0057f9b8-0x0057f9c0` | ignored padding | Eight `0xcc` bytes | no | UID0001IK context | `100` | Already registered |
| `0x0057f9c0-0x0057f9c7` | UID0004A7 target | Unsigned-byte spell-mode getter | true | UID000095 | current `92/94` | UID-preserving rename and Destination 1 implemented/validated |
| `0x0057f9c7-0x0057f9d0` | ignored padding | Nine `0xcc` bytes | no | UID0001IK context | `100` | Already registered |
| `0x0057f9d0-0x0057fa2b` | UID0004A8 constructor | Builds exact 0x110 row | true | UID000095 | current `91/94` | Destination 3 implemented/validated |
| `0x0057fa30-0x0057fa40` | UID0004A9 | Record-index setter | true | UID000095 | `86/90` | Verify-only |
| `0x0057fa40-0x0057fa52` | UID0004AA | Wchar key setter | true | UID000095 | `86/90` | Verify-only |
| `0x0057fa60-0x0057fa70` | UID0004AB | Unsigned-byte spell-mode setter | true | UID000095 | current `92/94` | UID-preserving rename and Destination 4 implemented/validated |
| `0x0057fa70-0x0057fa7a` | UID0004AC | Refresh helper | true | UID000095 | `86/90` | Verify-only |
| `0x0057fa80-0x0057fa9e` | UID0001IM | Compiler complete-object destructor glue | false | UID000095 | `88/92` | No-code, unchanged |
| `0x0057faa0-0x0057fc76` | UID0004AD | Paint and item/spell branch | true | UID000095 | `88/91` | Destination 5 implemented/validated; score unchanged |
| `0x0057fc80-0x0057fcff` | UID0004AE | Key/text input and zero/one writer | true | UID000095 | `90/93` | Destination 6 implemented/validated; score unchanged |
| `0x0057fd00-0x0057fd05` | UID0004AF | Pointer/mouse true override | true | UID000095 | `91/94` | Verify-only |
| New class declaration | UID000095 | Exact 0x110 source class | true | UID0000KY | `92/94` | Destination 2 implemented/validated; score unchanged |
| NewMacroDialog save | UID00049N | Getter consumer/storage writer | true | UID000094 | `89/92` | Destination 7 implemented/validated; score unchanged |
| NewMacroDialog load | UID00049O | Storage reader/setter caller | true | UID000094 | `89/92` | Destination 8 implemented/validated; score unchanged |
| MacroEditControlPanes | UID0001IK | Non-emitting split index | false | UID0000KY source family | `91/93` | Link/prose sync implemented/validated |
| MacroDialogs | UID0000KY | Source file/root | true | file root | `92/92` | Prose/source-order/generated expectations implemented/validated |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053f1e0` | UID00049N -> UID0004A7 | Sole target call; AL is stored unchanged to `record.isSpellMode`. |
| `0x0053ef20-0x0053ef2c` | UID00049J -> UID0004A8 | Raw record byte is zero-extended, pushed, and stored at row `+0x10e`. |
| `0x0053f283-0x0053f28d` | UID00049O -> UID0004AB | Raw record byte is zero-extended and pushed with no bool normalization. |
| `0x0057fcef` | UID0004AE internal store | `setz al` supplies canonical zero/one after active-child comparison. |
| `0x0057fac8` | UID0004AD field test | Zero/nonzero selects spell versus inventory record. |
| `0x0057fbde-0x0057fc01` | UID0004AD field read | Zero/nonzero selects literal `Item` versus `Spell` and exact length. |
| target data/vtable refs | none | Ordinary nonvirtual public accessor. |
| target end refs | none | Exact endpoint, no tail entry. |
| target callees | none | Pure field accessor. |

## Documentation Evidence And IDA Status

- UID0004A7 now emits Destination 1 through the renamed path at `92/94` with
  complete binary, ABI, caller, type, naming, lifecycle, negative, placement,
  and score evidence.
- UID0004AB now emits Destination 4 through the renamed path at `92/94` with
  complete exact-store, caller, type, negative, and source-void evidence.
- UID0004A8 is `91/94` and uses `unsigned char spellMode` /
  `m_spellMode` while preserving the executed B005 `wchar_t` key union,
  exact field order, caller provenance, three vptr stores as compiler evidence,
  selectable state, and natural `0x110` layout.
- UID000095 remains structurally complete at `92/94`; its current declaration
  uses `GetSpellMode`, `SetSpellMode`, and `unsigned char m_spellMode`, closes
  before `[[CHILDREN]]`, and preserves current `SetRecordIndex` /
  `m_recordIndex`.
- UID00049N and UID00049O now call the accepted accessor/setter names and
  preserve raw byte storage order.
- UID0004AD and UID0004AE now use `m_spellMode` while preserving their exact
  zero/nonzero and setcc behavior.
- UID0000KY and UID0001IK have current target/setter paths, source inventory,
  spell-mode prose, and complete prior cross-agent union.
- Config class/file, UID0001VR, and UID0003UA already contain the exact
  `unsigned char isSpellMode`, natural tail, and zero/nonzero contract at
  same-or-greater detail. They are verify-only.
- UID0001Y1, UID0003DB, UID0001IM, UID0004AV, and UID0001IN already contain the
  correct compiler/source boundary and do not need formal C++ changes.
- `by-memory/-ignored.md` already lists both adjacent target gaps exactly.
- Current generated MacroDialogs output at external command
  `000000014433` has SHA256
  `5B3D62C167BDDDAB5DF5814879173AD120F07AAAF43AAAC9E9CE098A9B6C2640`,
  34,914 bytes / 1,052 lines. Its UID000095 region contains one class, one
  UID0004A7 getter, one UID0004AB setter, one save call, one load call, one
  `m_spellMode` field, zero target empty markers, and zero stale
  `GetMode`/`SetMode`/`m_mode` tokens. The executed B005 `wchar_t` Spell-key
  union remains present once. The implementation is a coherent rename/type
  refresh with no duplicate emission.

## Ranked Ownership Analysis

### 1. UID000095 NewMacroEditControlPane

- Evidence for:
  direct ECX field read, exact constructor and setter writes to the same
  complete-object offset, class allocation and layout, direct NewMacroDialog
  row use, class-local paint/input consumers, and coherent vtable family.
- Evidence against:
  none.
- Decision:
  retain as canonical owner and emitter.

### 2. UID0000KY MacroDialogs source file

- Evidence for:
  NewMacroDialog constructs and calls the class, address clustering, current
  class position 50, full macro-dialog source family, current generated source,
  and exact vtable-data source route.
- Evidence against:
  original physical source grouping is inferred rather than PDB-proven.
- Decision:
  retain as source file/root; the physical-file caveat remains only a
  confidence note.

### 3. UID000094 NewMacroDialog

- Evidence for:
  sole getter caller and sole setter/constructor callers; owns page save/load.
- Evidence against:
  it operates through a separate row-control object and does not own `+0x10e`.
- Decision:
  consumer only, not target owner.

### 4. UID000031 Config / UID0001VR compact-record storage

- Evidence for:
  stores the corresponding persisted byte and defines its unsigned type.
- Evidence against:
  target receives a `NewMacroEditControlPane` object and reads a class-local
  copy, not Config storage directly.
- Decision:
  type/lifecycle support only.

### 5. ProfileStorage or UserPane

- Evidence for:
  persistence and runtime consume the same semantic field.
- Evidence against:
  neither calls the target or owns the row-control receiver.
- Decision:
  downstream support only.

### Proposed new file/grouping, if applicable

- Not applicable. `MacroDialogs.cpp` already contains the complete class,
  callers, source children, source order, and compiler-support route.

## Source Placement

- Recommended placement:
  UID000095 class declaration at existing file position 50 in
  `NexusTK/ui/dialogs/MacroDialogs.cpp`; UID0004A7 remains the qualified
  namespace-scope definition after UID0004A6 and before UID0004A8.
- Paired UID0004AB remains after UID0004AA and before UID0004AC by address
  order.
- Why:
  direct caller/callee clustering, class receiver, current source file, class
  position, generated order, and vtable-data ownership all agree.
- Rejected placements:
  Config method, NewMacroDialog member, ProfileStorage helper, UserPane
  helper, Pane method, free macro utility, or a new file.
- Remaining placement uncertainty:
  only the historical possibility that original developers split some macro
  classes into multiple physical files. Current project structure and emitted
  source remain coherent and no alternative has stronger evidence.

## Range / Split / Padding / Reclassification Analysis

- Target range remains `[0x0057f9c0,0x0057f9c7)`.
- Predecessor UID0004A6 ends at `0x0057f9b8`.
- `[0x0057f9b8,0x0057f9c0)` is exact eight-byte alignment.
- `[0x0057f9c7,0x0057f9d0)` is exact nine-byte alignment.
- Successor UID0004A8 begins at `0x0057f9d0`.
- No instruction, xref, fallthrough, data item, switch table, thunk, or shared
  tail crosses either boundary.
- No split, merge, new child, ignored-row addition, reconstruction
  reclassification, owner change, emitter change, position change, or Nested
  change is required.
- Required structural action is only validator-aware UID-preserving path/title
  rename for UID0004A7 and UID0004AB.

## Negative Evidence Summary

- No second target caller.
- No target data xref.
- No target vtable slot.
- No target end-address xref.
- No target callee, string, constant, branch, stack argument, or write.
- No boolean normalization in constructor or load callers.
- No exact-one comparison in paint, persistence, or runtime dispatch.
- No signed use of the target result or field.
- No enum switch, range check, or one-byte enum metadata.
- No relationship to Event key-modifier storage beyond the separate key
  narrowing input.
- No relationship to inherited Pane render-mode storage at `+0xb5`.
- No independent source lifecycle for the natural tail byte at `+0x10f`.
- No evidence for a new source file, Config ownership, NewMacroDialog
  ownership, ProfileStorage ownership, or UserPane ownership.
- No evidence for handwritten vtable, RTTI, vptr, adjustor, scalar-delete, or
  complete-object destructor code.
- No missing target child and no range gap.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name:
  `NewMacroEditControlPane::GetSpellMode`.
- Source-facing paired setter:
  `NewMacroEditControlPane::SetSpellMode`.
- Source-facing field:
  `m_spellMode`.
- Source-facing type:
  `unsigned char` for getter return, setter parameter, constructor parameter,
  and field.
- Source-facing value domain:
  zero means item/inventory; any nonzero value means spell/command. Do not
  normalize at the class API boundary.
- Path/title renames:
  - UID0004A7:
    `0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md`.
  - UID0004AB:
    `0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode.md`.
- Historical names to preserve only in explicit superseded history:
  `GetModifier`, `SetModifier`, `GetMode`, `SetMode`, `m_mode`.
- IDA DB mutation:
  not requested and not performed. Source-facing documentation renames do not
  require B001 to mutate IDA.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target and every source-bearing dependent
  token are behavior-complete.
- Formal block count: eight.
- The blocks below are complete destination-specific insertion shapes. No
  body-only or prose-only C++ recommendation exists elsewhere in this report.

Destination 1:
`by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned char NewMacroEditControlPane::GetSpellMode() const
{
    return m_spellMode;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2: `by-class/NewMacroEditControlPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct Rect;

class NewMacroEditControlPane : public ControlPane
{
public:
    NewMacroEditControlPane(wchar_t key, int recordIndex, unsigned char spellMode, const Rect &bounds);

    wchar_t GetKey() const;
    unsigned char GetSpellMode() const;
    void SetRecordIndex(int recordIndex);
    void SetKey(wchar_t key);
    void SetSpellMode(unsigned char spellMode);
    void Refresh();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    int m_recordIndex;
    wchar_t m_key;
    unsigned char m_spellMode;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3:
`by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewMacroEditControlPane::NewMacroEditControlPane(
    wchar_t key,
    int recordIndex,
    unsigned char spellMode,
    const Rect &bounds)
    : ControlPane(8, bounds),
      m_recordIndex(recordIndex),
      m_key(key),
      m_spellMode(spellMode)
{
    SetSelectable(true);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4:
`by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroEditControlPane::SetSpellMode(unsigned char spellMode)
{
    m_spellMode = spellMode;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 5:
`by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroEditControlPane::OnPaint()
{
    const Rect row = GetClientRect();
    BeginMacroRowPaint();

    const uint16_t normalizedKey = NormalizeSpellKey(m_key);
    const wchar_t *entryName = nullptr;
    if (m_spellMode != 0)
        entryName = g_spellRecords[normalizedKey].displayName;
    else
        entryName = GetLocalInventorySlot(normalizedKey)->displayName;

    const int centerY = (row.Height() + row.top + 12) / 2;
    if (m_recordIndex >= 10)
        DrawMacroRowText(row.left, centerY, FormatShortcutNumber(L"Ctrl+%d", m_recordIndex == 19 ? 0 : m_recordIndex - 9));
    else
        DrawMacroRowText(row.left + 18, centerY, FormatShortcutNumber(L"%d", m_recordIndex == 9 ? 0 : m_recordIndex + 1));

    DrawMacroRowText(row.left + 48, centerY, m_spellMode != 0 ? L"Spell" : L"Item");
    DrawMacroRowText(row.left + 90, centerY, entryName);

    if (IsFocused())
        DrawMacroRowFocus(row);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 6:
`by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewMacroEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        const int activeChild = g_pGeneralPurposePanel->GetActiveChildIndex();
        if (activeChild == 2 || activeChild == 3)
        {
            const unsigned char key = NarrowInputKey(
                event->m_payload.m_key.m_key,
                event->m_payload.m_key.m_modifiers);

            if ((key < 'a' || key > 'z') &&
                (key < 'A' || key > 'Z'))
                return false;

            m_key = key;
            m_spellMode = activeChild == 3;
            InvalidateRect(NULL);
        }

        return true;
    }

    return event->m_type == kEventTextInput;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 7:
`by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroDialog::SaveMacroEntries()
{
    const int baseIndex = m_currentPage * 10;

    for (int row = 0; row < 10; ++row)
    {
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[baseIndex + row];

        record.code = edit->GetKey();
        record.isSpellMode = edit->GetSpellMode();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 8:
`by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewMacroDialog::LoadMacroPage(int page)
{
    if (m_currentPage == page)
        return;

    m_currentPage = page;

    const int baseIndex = page * 10;
    for (int row = 0; row < 10; ++row)
    {
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        const CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[baseIndex + row];

        edit->SetRecordIndex(baseIndex + row);
        edit->SetKey(record.code);
        edit->SetSpellMode(record.isSpellMode);
        edit->Refresh();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact-behavior reason:
  all blocks preserve raw byte transport, zero/nonzero tests, caller order,
  field layout, and source/compiler boundaries.
- Source-shape reason:
  the blocks use ordinary class methods, fundamental source-era byte types,
  semantic field/method names, and existing class/file organization rather
  than offsets, decompiler names, casts, wrappers, or compiler artifacts.
- Third-party import directive:
  not applicable.
- No-code proof:
  not applicable to UID0004A7; the target is source-authored and directly
  called. Compiler support pages remain no-code under their existing proofs.

## Final Recommendation

- UID0004A7 is UID-preservingly renamed to `GetSpellMode`; Destination 1 and
  `92/94` are applied.
- UID0004AB is UID-preservingly renamed to `SetSpellMode`; Destination 4 and
  `92/94` are applied.
- Destination 2 is applied to the complete UID000095 declaration without loss
  of any
  current method, base, access section, class closure, or `[[CHILDREN]]`.
- Destination 3 is applied and UID0004A8 is `91/94`.
- Destinations 5 and 6 are applied as exact field-token synchronizations while
  preserving their existing behavior, metadata, and unrelated source.
- Destinations 7 and 8 are applied as exact call-name synchronizations while
  preserving their existing behavior, metadata, scores, and storage order.
- UID0000KY, UID0001IK, UID00049J, and bounded affected prose/history are
  synchronized with
  the exact unsigned-byte spell-mode contract and renamed links.
- Preserve Config class/file, UID0001VR, UID0003UA, vtable/compiler support,
  ignored padding, NewMacroDialog class, and UID0004A9 at same-or-greater
  detail; verification confirms this preservation.
- No target-specific research or B001 implementation blocker remains. Any
  original lexical
  uncertainty is explicitly confidence-capped and does not block source.

## Recommended Target Doc Changes

- Current applied target:
  `by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md`.
- Historical pre-callback target:
  `by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetMode.md`;
  command `000000014401` removed this path while preserving UID0004A7.
- Applied metadata:
  `92/94`; owner/emitter UID000095 unchanged; true; blank position;
  `Nested:0`.
- Applied formal C++:
  Destination 1 exactly.
- Applied Item Summary:
  exact summary covering seven-byte
  body/hash, AL return from `+0x10e`, sole save caller, raw
  `isSpellMode` lifecycle, unsigned-byte/no-bool decision, no vtable/data
  route, and MacroDialogs source placement.
- Applied body detail:
  exact boundary, PE mapping, bytes/hash/signature, CFG, ABI, caller,
  no-callee/no-data/no-vtable facts, constructor/setter/input/paint/save/load/
  persistence/runtime lifecycle, type/name ranking, rejected alternatives,
  padding hashes, source placement, and score rationale.
- Historicalized:
  pre-callback `uint8_t GetMode`, `m_mode`, and `GetModifier` claims.

## Recommended Support Doc Changes

- UID0004AB current applied path:
  `by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode.md`.
  - Command `000000014402` UID-preservingly removed the historical
    `SetMode` path.
  - Destination 4 and `92/94` are applied.
  - Exact bytes/hash, one load caller, raw byte store, no bool
    normalization, source-void return reasoning, negatives, and history.
- UID0004A8 constructor:
  - Destination 3 and `91/94` are applied.
  - Exact body hash, raw byte caller transport, `unsigned char spellMode`,
    `m_spellMode`, no-bool proof, complete layout, and source order.
- UID000095 class:
  - Destination 2 is applied; `92/94`, UID0000KY route, position 50,
    complete method union, class closure, and `[[CHILDREN]]`.
  - Modifier/generic-mode current prose is replaced with exact unsigned-byte
    spell-mode lifecycle and historicalized aliases.
  - Links use renamed UID0004A7 and UID0004AB pages.
- UID0004AD OnPaint:
  - Destination 5 is applied exactly.
  - Preserve `88/91`, owner/emitter, vtable route, all helper behavior,
    strings, branches, and history.
  - Add explicit arbitrary nonzero semantics for `m_spellMode`.
- UID0004AE input:
  - Destination 6 is applied exactly.
  - Preserve `90/93`, owner/emitter, EventHandler slot, returns, and history.
  - Record setcc zero/one as one writer without claiming bool storage.
- UID00049N save:
  - Destination 7 is applied exactly.
  - Preserve `89/92`, page/loop/child/storage order, direct Config storage, and
    no MacroHotkeyRecord conflation.
  - Replace stale historical aliases in evidence.
- UID00049O load:
  - Destination 8 is applied exactly.
  - Preserve `89/92`, early return, setter order, direct Config storage, and
    no MacroHotkeyRecord conflation.
- UID00049J NewMacroDialog constructor:
  - No formal body change required.
  - The page now records that the raw unsigned byte is zero-extended and
    passed unchanged to the
    now-typed constructor, with no bool conversion.
  - Preserve `90/93`, all resource/control/layout behavior, and the
    no-direct-constructor-xref caveat.
- UID0001IK split parent:
  - Target/setter links and inventory descriptions are updated.
  - Preserve non-emitting `91/93`, all children, compiler support, `Nested:-4`,
    and padding evidence.
- UID0000KY MacroDialogs:
  - Target/setter links, complete class vocabulary, source order, and
    current generated expectations.
  - Preserve `92/92`, complete current cross-agent union, blank file formal,
    all unrelated class/source/compiler detail, and physical-file caveat.
- Verify-only results:
  - UID000094 NewMacroDialog class.
  - Config class/file.
  - UID0001VR RegistryConfigUserProfileBlock.
  - UID0003UA UserPane runtime dispatcher.
  - UID0001Y1 MacroDialogFamilyVtables.
  - UID0003DB MacroEditControlPaneVtableData.
  - UID0001IM complete-object destructor glue.
  - UID0004AV scalar deleting wrapper.
  - UID0001IN thunk island.
  - `by-memory/-ignored.md`.
  - All remained unchanged. UID0004A6 alone required a bounded current-facing
    neighboring-name correction after rename propagation; UID0004AA received
    validator-owned link propagation and a final scoped verification.

## Score And Metadata Recommendation

- UID0004A7 historical baseline:
  `86/90`, owner/emitter UID000095, true, blank position, `Nested:0`.
- UID0004A7 current applied:
  `92/94`; all non-score metadata unchanged; validator-aware path/title rename
  complete.
- Completion rationale:
  exact binary, ABI, caller, field, lifecycle, type, value domain, naming,
  range, placement, formal C++, negatives, support plan, and coverage handoff
  are complete.
- Confidence rationale:
  behavior and structure are exact; the source name is inferred but strongly
  constrained. `94` matches the accepted adjacent UID0004A6 and complete
  UID000095 class evidence.
- Reason not higher:
  original decorated method and private-field spellings do not survive.
- UID0004AB:
  current `92/94`, same owner/emitter/true/blank position/`Nested:0`, paired
  path rename complete from historical `86/90`.
- UID0004A8:
  current `91/94`, same owner/emitter/true/blank position/`Nested:0`, raised
  from historical `87/90`.
  Completion stays below 92 because several base/helper lexical names in the
  broader constructor source remain inferred, while exact behavior and ABI are
  closed.
- UID000095:
  retain `92/94`, UID0000KY owner/emitter, position 50, true.
- UID0004AD:
  retain `88/91`.
- UID0004AE:
  retain `90/93`.
- UID00049N and UID00049O:
  retain `89/92`.
- UID0000KY:
  retain `92/92`.
- UID0001IK:
  retain current `91/93`, false/non-emitting split-index state.
- Score-improvement audit:
  - bytes/boundary blocker: resolved with MCP and raw PE.
  - ABI/return blocker: resolved with disasm, stack frame, and caller store.
  - field/type blocker: resolved through raw transport and current record type.
  - bool versus byte blocker: resolved by absence of caller normalization.
  - value-domain blocker: resolved through UI, persistence, and runtime.
  - caller blocker: sole caller recovered and audited.
  - name blocker: ranked and resolved to spell-mode vocabulary.
  - owner/emitter blocker: resolved to UID000095/UID0000KY.
  - source-placement blocker: resolved to existing MacroDialogs order.
  - range/padding blocker: exact and already registered.
  - C++ blocker: eight complete managed blocks supplied.
  - generated blocker: resolved by B001 final waited command
    `000000014428`; current external command `000000014433` retains the exact
    assertions below.
  - coverage blocker: implementation handoff is exact and current manual rows
    remain supervisor-owned/unapplied.

## Open Questions With Attempted Resolution

- What is the exact function body?
  - Resolved: seven bytes, two instructions, one block, exact hash.
- Is the return signed?
  - Resolved for source: no signed use exists; current storage contract makes
    `unsigned char` strongest.
- Is the field a bool?
  - Resolved: no. Raw constructor/load/getter/setter/save transport preserves
    arbitrary byte values without normalization.
- Is it an enum?
  - Resolved: no defensible one-byte enum/source dispatch evidence.
- What values exist?
  - Resolved: canonical writers produce zero/one; source semantics are zero
    item/inventory and nonzero spell/command; raw noncanonical values survive.
- What is the strongest method name?
  - Resolved: `GetSpellMode`; `GetMode` is generic and collides with Pane mode
    vocabulary, `GetModifier` is semantically wrong, and `IsSpellMode` implies
    bool.
- What is the paired setter/field name?
  - Resolved: `SetSpellMode` and `m_spellMode`.
- Who calls it?
  - Resolved: only NewMacroDialog save at `0x0053f1e0`.
- Is it virtual?
  - Resolved: no data/vtable ref.
- Does it belong in Config/ProfileStorage/UserPane?
  - Resolved: no; those own storage/persistence/runtime, not receiver state.
- Does it need a split or new file?
  - Resolved: no.
- Does current generated output prove correctness?
  - Resolved: it proves current emission shape only; MCP/raw bytes prove
    behavior, and the report supplies the source-quality correction.
- Remaining questions:
  - Exact original lexical spelling is unavailable. This is a confidence cap,
    not a behavior, type, C++, score-improvement, or implementation blocker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current post-callback manual snapshots inspected read-only:
  - `by-memory/-coverage-report.md`, SHA256
    `6DEF1A277ECC95CFEDBFC95DD8DD1081AEF00D5856046E7949884EEE07B20D56`,
    1,788,624 bytes / 4,276 lines.
  - `by-class/-coverage-report.md`, SHA256
    `CEF7789F454B1D9004DCB9D161215D07EA0D5651B5FDDB0486CFE21095346713`,
    231,113 bytes / 622 lines.
  - `by-file/-coverage-report.md`, SHA256
    `147077FED5BD2058174DC029E16668AB772762ABE58C229D6FD1035CFF5AD00D`,
    132,779 bytes / 316 lines.
  - `by-type/by-struct/-coverage-report.md`, SHA256
    `A59DA1DB4C5D4FFA760A2BDD8EA84D49D412D559AD428FCDE03523096EFE9C0C`,
    57,240 bytes / 137 lines.
- Current findings:
  - UID0004A1 now has the applied `92%` `wchar_t` by-memory row, and UID0000DQ
    now has the applied `92%` `wchar_t` by-class row. These supervisor-applied
    adjacent rows are complete and require no UID0004A7 handoff change.
  - UID0004A7, UID0004A8, and UID0004AB still have no manual by-memory rows.
  - UID00049N and UID00049O rows exist but use generic key/mode wording.
  - UID000095 and UID0000KY rows exist and use generic mode vocabulary.
  - UID0001VR already states the exact unsigned-byte no-bool contract and
    needs no replacement.
  - No manual tracker edit is authorized. The generated research tracker is
    validator-owned.
- Supervisor insertion in `by-memory/-coverage-report.md`, immediately after
  UID0004A6 and before UID0004AE, preserving address order:

```text
        - [UID:0004A7][0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode](by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md) 0x0057f9c0-0x0057f9c7 | method | NewMacroEditControlPaneGetSpellMode : reconstructable : 92% : very-strong : Exact seven-byte unsigned-char spell-mode getter returning the complete-object +0x10e byte unchanged through AL, with exact bytes/hash/unique signature, sole NewMacroDialog save caller, raw CompactShortcutRecord isSpellMode transport, zero data/vtable refs, exact surrounding padding, no-bool/no-enum proof, UID000095 ownership, MacroDialogs emission, and complete source C++.
        - [UID:0004A8][0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor](by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md) 0x0057f9d0-0x0057fa2b | constructor | NewMacroEditControlPaneConstructor : reconstructable : 91% : very-strong : Exact 0x5b-byte constructor with one NewMacroDialog caller, ControlPane base construction, raw CompactShortcutRecord wchar_t code/unsigned-char isSpellMode transport, record-index/key/spell-mode stores at +0x108/+0x10c/+0x10e, three compiler vptr stores, selectable state, natural 0x110 layout, no-bool normalization, and complete source C++.
        - [UID:0004AB][0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode](by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode.md) 0x0057fa60-0x0057fa70 | method | NewMacroEditControlPaneSetSpellMode : reconstructable : 92% : very-strong : Exact 16-byte unsigned-char spell-mode setter storing the low argument byte unchanged at complete-object +0x10e, with exact bytes/hash, sole NewMacroDialog load caller, raw noncanonical nonzero preservation, paired GetSpellMode source contract, no-bool/no-enum proof, UID000095 ownership, MacroDialogs emission, and complete source C++.
```

- Supervisor replacement for UID00049N:

```text
        - [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md) 0x0053f180-0x0053f203 | method | NewMacroDialogSaveMacroEntries : reconstructable : 89% : very-strong : Exact current-page ten-row save helper copying NewMacroEditControlPane GetKey/GetSpellMode results into direct Config CompactShortcutRecord code/isSpellMode fields, preserving the raw unsigned spell-mode byte, with complete source C++ and no MacroHotkeyRecord conflation.
```

- Supervisor replacement for UID00049O:

```text
        - [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) 0x0053f210-0x0053f2b6 | method | NewMacroDialogLoadMacroPage : reconstructable : 89% : very-strong : Exact page-change and ten-row load helper copying direct Config CompactShortcutRecord code/isSpellMode into NewMacroEditControlPane record index, key, and SetSpellMode before refresh, preserving the raw unsigned spell-mode byte, corrected endpoint, and complete source C++.
```

- Supervisor replacement for UID000095 in `by-class/-coverage-report.md`:

```text
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md) : reconstructable : 92% : very-strong : Complete natural 0x110 ControlPane-derived new macro row declaration at position 50 with int record index at +0x108, wchar_t key/API at +0x10c, unsigned-char m_spellMode at +0x10e, GetSpellMode/SetSpellMode raw-byte API, constructor, record/key setters, refresh, paint, canonical pointer/key EventHandler overrides, exact CompactShortcutRecord code/isSpellMode constructor/save/load/persistence/runtime lifecycle, zero/nonzero item-inventory versus spell-command semantics without bool narrowing, vtable routes, implicit virtual destructor source cause, compiler helper/scalar/thunk separation, and MacroDialogs ownership.
```

- Supervisor replacement for UID0000KY in `by-file/-coverage-report.md`:

```text
- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) : reconstructable : 92% : very strong : Macro dialog/edit-control source family with exact Macro/Spell/New/Integrate split inventories, complete six-position Macro/Integrate-dialog/Integrate-edit/New-dialog/New-edit/Spell declarations at 10/20/30/40/50/60 plus complete source-local Spell edit class, canonical OnControlCommand and SetHoverControl contracts, corrected constructor calls and TextEditPane editor type, exact NewMacroEditControlPane unsigned-char GetSpellMode/SetSpellMode/m_spellMode lifecycle mapped to CompactShortcutRecord isSpellMode without bool narrowing, registry/profile/runtime storage distinctions, explicit/implicit/source/compiler destructor separation, vtable coverage, historical stale-name corrections, and retained physical-file grouping caveat.
```

- UID0001VR row:
  no change. It already contains exact unsigned-char `isSpellMode`, natural
  tail, full lifecycle, and no duplicate aggregate conclusion.
- Reason B001 must not apply:
  all manual `-coverage-report.md` files are supervisor-owned. This report
  supplies exact text only.

## Follow-Up Actions

- B001 callback action:
  implementation, scoped validation, generated readback, report
  reconciliation, and lease release are complete; no further B001 work
  remains.
- External lifecycle boundary:
  report validation, manual coverage application, execution, count, path
  movement, and archive state are supervisor/validator-owned. Current manual
  rows remain unapplied as proven above. This artifact neither asserts nor
  directs a future lifecycle outcome.
- A-agent actions:
  none.

## Confidence

- Recommendation confidence:
  very strong.
- Score confidence:
  very strong for UID0004A7 and UID0004AB; strong for the bounded UID0004A8
  increase.
- Binary behavior uncertainty:
  none.
- ABI/layout uncertainty:
  none.
- Type/value-domain uncertainty:
  none.
- Owner/emitter/source-placement uncertainty:
  no blocking uncertainty.
- Remaining uncertainty:
  original private lexical spelling only. The recommended names are
  descriptive, project-consistent, and implementation-ready.

## Validator Results

- All listed scoped commands returned exit code `0` and `ok:1`.

| Command ID | Timestamp | Scoped file / purpose | Result and side effects |
| --- | --- | --- | --- |
| `000000014401` | `2026-07-16T17:01:25-04:00` | UID0004A7 validator-aware rename and target implementation | Passed; path update `GetMode -> GetSpellMode`, score `92/94`, six UID link updates, generated refresh deferred. |
| `000000014402` | `2026-07-16T17:02:18-04:00` | UID0004AB validator-aware rename and setter implementation | Passed; path update `SetMode -> SetSpellMode`, score `92/94`, six UID link updates, generated refresh deferred. |
| `000000014403` | `2026-07-16T17:03:45-04:00` | UID000095 class | Passed; complete Destination 2/current union retained, generated refresh deferred. |
| `000000014404` | `2026-07-16T17:05:54-04:00` | UID0004A8 constructor | Passed; completion/confidence updated to `91/94`, generated refresh deferred. |
| `000000014405` | `2026-07-16T17:06:56-04:00` | UID0004AD OnPaint | Passed; validator inserted the missing UID0003U9 link and refreshed reference index; generated refresh deferred. |
| `000000014406` | `2026-07-16T17:07:26-04:00` | UID0004AE input handler | Passed; generated refresh deferred. |
| `000000014407` | `2026-07-16T17:08:03-04:00` | UID00049N save | Passed; UID0004A7 reference-index entry added, generated refresh deferred. |
| `000000014408` | `2026-07-16T17:08:37-04:00` | UID00049O load | Passed; UID0004AB reference-index entry added, generated refresh deferred. |
| `000000014412` | `2026-07-16T17:09:24-04:00` | UID00049J constructor caller | Passed; UID0004A8 reference-index entry added, generated refresh deferred. |
| `000000014420` | `2026-07-16T17:10:22-04:00` | UID0001IK split parent | Passed; generated refresh deferred. |
| `000000014424` | `2026-07-16T17:12:06-04:00` | UID0000KY MacroDialogs file | Passed; generated refresh deferred. |
| `000000014425` | `2026-07-16T17:13:58-04:00` | UID0004A6 bounded neighboring-name correction | Passed; no metadata change, generated refresh deferred. |
| `000000014427` | `2026-07-16T17:15:22-04:00` | UID0004AA validator-owned rename-link readback | Passed; no source or metadata change, generated refresh deferred. |
| `000000014426` | `2026-07-16T17:14:12-04:00` | First waited MacroDialogs readback after source edits | Passed; superseded as terminal freshness proof by command `000000014428` after final reference-page verification. |
| `000000014428` | `2026-07-16T17:15:40-04:00` | Final authorized `by-file/MacroDialogs.md --wait-generated` | Passed; generated refresh completed and established the terminal B001 source assertions. |

- Command-number gaps are concurrent external validator traffic and are not
  B001 commands.
- Scoped validator side effects were validator-owned registry/reference index,
  projected stats, and deferred/generated metadata refreshes. B001 did not
  edit validator state, generated output, tracker, or project stats manually.
- Waited commands reported pre-existing project-wide warnings:
  `autogen_children_fallback_insert:13`,
  `autogen_children_marker_missing:85`, and
  `autogen_emitter_has_no_code:142`. None names a UID0004A7 callback
  destination or represents a target-specific failure.
- Current generated source:
  `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`, external validator
  command `000000014433`, refreshed `2026-07-16T17:19:55-04:00`, SHA256
  `5B3D62C167BDDDAB5DF5814879173AD120F07AAAF43AAAC9E9CE098A9B6C2640`,
  34,914 bytes / 1,052 lines.
- The current external refresh occurred after B001's final waited command
  `000000014428`. Readback confirms all target and B005-union assertions are
  unchanged; B001 does not claim command `000000014433`.
- Current generated assertions:
  - one complete UID000095 class;
  - one UID0004A7 marker and one
    `unsigned char NewMacroEditControlPane::GetSpellMode() const`;
  - one UID0004AB marker and one
    `void NewMacroEditControlPane::SetSpellMode(unsigned char spellMode)`;
  - zero UID0004A7 Empty Emitter Markers;
  - one `wchar_t m_key` and one `unsigned char m_spellMode`;
  - zero target-region `GetMode`, `SetMode`, or `m_mode`;
  - one save `GetSpellMode` call and one load `SetSpellMode` call;
  - address order UID0004A6/A7/A8/A9/AA/AB/AC/AD/AE/AF;
  - preserved `SetRecordIndex` / `m_recordIndex`;
  - one SpellMacroEditControlPane class, one `wchar_t m_spellKey`, and one
    UID0004A1 getter, preserving the executed B005 union;
  - no raw `+0x10e` source token, target duplicate, aggregate body, or
    handwritten vptr/vtable/RTTI/compiler-glue body.
- Current manual coverage, tracker, and verify-only support were read only.
- MCP calls remain research evidence, not validator commands.

## Changed Files

- Same report updated in place:
  `tools/leaser/Agents/Agent-B001/research/0004A7-NewMacroEditControlPaneGetMode-source-quality.md`.
- UID-preserving renames:
  - historical
    `by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetMode.md`
    -> current
    `by-memory/0x0057f9c0-0x0057f9c7.NewMacroEditControlPaneGetSpellMode.md`;
    old path absent, current SHA256
    `71B7E202E354C4547A578C820736CAADD72284975C4FB69987AB15D9307D964C`.
  - historical
    `by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetMode.md`
    -> current
    `by-memory/0x0057fa60-0x0057fa70.NewMacroEditControlPaneSetSpellMode.md`;
    old path absent, current SHA256
    `7AB5F71D35D0AA651BA85A1C638B4162AE8426191E1E5FC18540B503633F57B9`.
- Other changed ordinary pages:

| Path | Current SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-class/NewMacroEditControlPane.md` | `5D036757CC6D31D27295CD25B2510CC7140847A2A6C02D7A6722B0AFF330DB96` | 32,497 / 222 |
| `by-memory/0x0057f9d0-0x0057fa2b.NewMacroEditControlPaneConstructor.md` | `58F41F79311DAC323FB414208C8271F8E88D2A92F78593E6633BE703C9F7346A` | 8,859 / 119 |
| `by-memory/0x0057faa0-0x0057fc76.NewMacroEditControlPaneOnPaint.md` | `7F1515A1AA9FCF75BFB62C7CE1C2C49A5328027A6B26FAB3D86FD67B63627C60` | 5,576 / 97 |
| `by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent.md` | `BFDD4690C6C584CEA2E323C07C3BB9BAA776E0850EF957F3486C0C388181FFC3` | 6,351 / 102 |
| `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md` | `B9D08D91F2CE61256BEB0AF43B6F24697D55A7CDE67AFA5A0C4385A4CF74DDC6` | 6,419 / 95 |
| `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md` | `AFB5FAAB04F560D3EA5F3C3D8DE3C84593A1A02F408A602CF7F94D981DA35CCC` | 6,614 / 102 |
| `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md` | `82DC45E7CFD6892D5728A81933DF6C158236DC4335B8E384485A23EFA7ECB938` | 8,772 / 119 |
| `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md` | `39527A4D4A09356F6EF872E970D4961533A0540F51C311EA2191D2B63BB325DF` | 43,071 / 209 |
| `by-file/MacroDialogs.md` | `A0F16DC929FFF8867CF95C691CF1523B40F32BCC739E9251A3C8DEAA90188FE2` | 85,547 / 295 |
| `by-memory/0x0057f9b0-0x0057f9b8.NewMacroEditControlPaneGetKey.md` | `D1D1F191C168C3E05A29B64F8F404E7EF8B94637E41C8167DE1AA287D94E4733` | 9,905 / 96 |
| `by-memory/0x0057fa40-0x0057fa52.NewMacroEditControlPaneSetKey.md` | `44C898AF090511632D260278D6621ED598043A998B1EFA1BB71E93FB87B5A0C6` | 4,750 / 53 |

- UID0004A6 received only the bounded neighboring-name correction required by
  the accepted rename; all executed B005 key evidence/formal/score remained.
  UID0004AA changed only through validator-owned rename link propagation and
  final readback.
- Verify-only pages remained unchanged, including:
  UID0004A9 SHA256 `7F558CBB...D4CB`, ignored SHA256
  `C4875C9D...DFE9`, UID0001Y1 `0D6E643E...97E0`, UID0003DB
  `D5D87A8A...00C0`, UID0001IM `782E2E53...BC9A`, UID0004AV
  `C1C60B4B...C101`, UID0001IN `724FC0C3...B717`, and NewMacroDialog class
  `49553430...853E`.
- Manual coverage changed by B001:
  zero. Current hashes and exact still-pending rows are recorded above.
- Generated files changed manually by B001:
  zero. B001 validator command `000000014428` refreshed generated output;
  current external validator command `000000014433` later refreshed the
  shared generated artifact without changing target assertions.
- Tracker/audit/supervisor/validator-state/IDA/lifecycle/archive files changed
  manually by B001:
  zero. Current tracker SHA256 is
  `2A675847CD5D58D6AF3ED1C0054D2B8B6C9CFAC506B953EAF77DFFF33791E296`,
  1,508,875 bytes / 6,131 lines.
- External B005 lifecycle evidence remains the archived report
  `executed-b-agent-research/B005/0004A1-SpellMacroEditControlPaneGetSpellKey-source-quality.md`,
  SHA256
  `D6455A66556D1DF1463BE30286C16197DB16B4B46079CE2A39F5172438DF6C56`,
  supervisor command `000000014400`.
- Every ordinary lease was released immediately after its scoped batch; final
  `current_leases.md` has zero B001 rows.
- B001 did not run `execute_report`, any report lifecycle/probe/count command,
  move, or archive operation.

## Implementation Tracking Checklist

Initial report-only pass and supervisor review:

- [x] Supervisor exact-artifact validation required before any ordinary edit.
- [x] Confirm C4A7-001 through C4A7-054 are accepted, rejected, or bounded
  explicitly without compression.
- [x] Re-read every destination immediately before any callback edit.
- [x] Confirm no overlapping lease before each ordinary edit.

Target and paired API:

- [x] Validator-aware UID-preserving rename UID0004A7 to the exact
  `NewMacroEditControlPaneGetSpellMode` path/title.
- [x] Apply UID0004A7 `92/94`, unchanged owner/emitter/true/blank
  position/`Nested:0`.
- [x] Apply Destination 1 exactly and complete target evidence/history.
- [x] Validator-aware UID-preserving rename UID0004AB to the exact
  `NewMacroEditControlPaneSetSpellMode` path/title.
- [x] Apply UID0004AB `92/94`, unchanged owner/emitter/true/blank
  position/`Nested:0`.
- [x] Apply Destination 4 exactly and complete setter evidence/history.

Class and source bodies:

- [x] Apply Destination 2 to UID000095 without losing any current method,
  base, access section, class closure, `[[CHILDREN]]`, score, route, or
  unrelated history.
- [x] Apply Destination 3 to UID0004A8 and raise it to `91/94`.
- [x] Apply Destination 5 to UID0004AD with score/route unchanged.
- [x] Apply Destination 6 to UID0004AE with score/route unchanged.
- [x] Apply Destination 7 to UID00049N with score/route unchanged.
- [x] Apply Destination 8 to UID00049O with score/route unchanged.
- [x] Synchronize UID00049J raw unsigned-byte constructor argument evidence
  without changing its formal body or score.
- [x] Synchronize UID0001IK links/inventory/history while preserving the
  complete current child/compiler/padding union and non-emitting state.
- [x] Synchronize UID0000KY links/source-order/type/name/history while
  preserving its complete current cross-agent union and blank file formal.

Type, value domain, names, and history:

- [x] Use `unsigned char` consistently across the target API and field.
- [x] Preserve raw noncanonical nonzero transport; do not normalize to bool.
- [x] Preserve zero item/inventory and nonzero spell/command semantics.
- [x] Historicalize `GetMode`/`SetMode`/`m_mode` as superseded generic names.
- [x] Reject `GetModifier`/`SetModifier` as stale keyboard-modifier wording.
- [x] Preserve rejected bool/plain-char/enum/uint8_t rationale at
  report-level detail.
- [x] Preserve exact bytes, hashes, PE mapping, CFG, ABI, callers, field
  accesses, negatives, padding, vtables, and source/compiler boundary.

Verify-only support:

- [x] Verify UID000094 NewMacroDialog class unchanged.
- [x] Verify Config class/file and UID0001VR retain exact unsigned-byte record
  contract and natural tail.
- [x] Verify UID0003UA retains arbitrary nonzero runtime semantics.
- [x] Verify UID0001Y1/UID0003DB/UID0001IM/UID0004AV/UID0001IN compiler
  support unchanged.
- [x] Verify `by-memory/-ignored.md` already contains both exact target gaps
  and do not edit it.

Leases and validation:

- [x] Lease only the one ordinary file immediately before editing.
- [x] Run that file's scoped validator while the lease is held.
- [x] Record command, command ID, timestamp, exit, ok count, warnings, and
  side effects for every changed ordinary page.
- [x] Release each lease immediately after its edit/validator batch.
- [x] After all ordinary pages pass, run one final authorized
  `by-file/MacroDialogs.md --wait-generated` validation.
- [x] Verify every generated assertion listed under Validator Results.
- [x] Confirm all stale target/setter path and source tokens are absent.
- [x] Confirm all unrelated MacroDialogs source remains singular and intact.

Manual coverage and lifecycle boundary:

- [x] Preserve the exact manual coverage handoff text above.
- [x] B001 must not edit any manual `-coverage-report.md` file.
- [x] Record supervisor-owned coverage state only from current external files;
  never claim B001 applied it.
- [x] Do not edit generated, tracker, audit, supervisor, validator-state,
  lifecycle, archive, queue, lock, or IDA files manually.
- [x] Do not run or probe `execute_report`.
- [x] Do not run report lifecycle/count/move/archive commands.
- [x] Update the ledger to legal callback states only after independent
  destination proof exists.
- [x] Update Validator Results, Changed Files, current-state wording, hashes,
  and checklist truth after any accepted callback.
- [x] Confirm zero B001 leases remain before callback return.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000014451","destination_path":"executed-b-agent-research/B001/0004A7-NewMacroEditControlPaneGetMode-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0004A7-NewMacroEditControlPaneGetMode-source-quality.md","timestamp":"2026-07-16T17:35:54-04:00","uid":"0004A7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
