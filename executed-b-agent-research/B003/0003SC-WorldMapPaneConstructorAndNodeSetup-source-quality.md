** TARGET-REPORT-UID:0003SC **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003SC WorldMapPaneConstructorAndNodeSetup Source-Quality Report

## Finalized Report / Current Recommendation

This report resolves and implements the exact `[0x005c2ac0,0x005c32aa)` `WorldMapPane` constructor as source-authored code in `NexusTK/map/WorldMapPane.cpp`. UID0003SC is now `92/94`, retaining canonical owner UID0000G9, emitter UID0000PB, `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:+4`, and exact formal Destination R1. No split or rename was required.

The complete source model is an eight-argument constructor after implicit `this`: map name, signed node count, signed current-node index, node positions, node names, destination map IDs, destination positions, and a copied `const std::vector<bool> &` directed adjacency matrix. It constructs `Pane(0)`, `FrameHandler`, and `Singleton<WorldMapPane>`; initializes five `EPFTileContext` members; copies all caller-owned node data into exact `0x94`-byte `WorldMapNode` records; copies adjacency; selects a current EPF/PAL or legacy EPD/PAD resource branch; centers and clamps the view; invalidates; builds reachability; schedules timer zero at 150 ms; and loads front/back boat assets. The binary intentionally duplicates common setup in both asset branches and performs no resource, count, or current-index validation.

Associated source debt is resolved rather than deferred. UID0000G9 now contains the complete `0x298` class declaration in R2, UID00029E is corrected from false `0xffffffff` initialized-data wording to loader-zero-filled singleton storage, and validator-issued UID0004T9 supplies the sole zero-initialized WorldMapPane-pointer definition in R7. UID00035H/UID00035I/UID00035J are non-reconstructable compiler/data children with blank formals because their vtables, literals, and constants arise naturally from the class and method source. UID0001O4 remains a non-emitting split index; UID000271 remains a parent-only read-only-data index.

Implementation callback state: C01-C20 and R0-R7 are applied or verified at same-or-greater detail. B003 changed the ten ordinary destinations listed in `Changed Files` through serial edit/validation, and validator command 14846 refreshed generated output. B003 did not manually edit coverage, generated, tracker, validator-state, audit, supervisor, goal, IDA, lifecycle, or archive files and did not run any report lifecycle command. Every acquired lease was released immediately after its scoped batch; none remains.

## Supporting Research

### Current Direct Documentation

| Destination | Accepted pre-callback state and SHA256 | Implemented current state and SHA256 |
| --- | --- | --- |
| UID0003SC target | `86/90`, true, owner 0000G9, emitter 0000PB, blank formal, `Nested:+4`; `C335A6FF38ADA69CAD5E606EA7853379DEF6127BADF5BAC93EEE0A7631CEFE03`, 6,036 bytes / 62 lines | `92/94`, same owner/emitter/true/blank position/`Nested:+4`, R1 and exhaustive evidence; `1736642696CA1451EFD3B6BCEF9D5E62320EA320AF06EE6B272E13D395BEABBA`, 17,933 / 226. |
| UID0001O4 aggregate | `88/91`, false, blank emitter/formal; `29EC30474D9A771F216B2903513E050F5B5601799F1071827EDA48CB76879E14`, 23,192 / 204 | `90/93`, same parent-only route and R0, complete constructor/padding/data disposition; `A0F962236C1ED3EBF85942DB58C4F5CB7464D3C31C21A1C381D82CB0FE2A5CEC`, 26,164 / 217. |
| UID0000G9 class | `90/93`, true, emitter 0000PB, blank formal; `689E113AD610EFC5C62322EDEDD785AD5B6E2CAF3A12C1FE9732D2EED7111F13`, 18,829 / 145 | `93/94`, same route, complete R2/`0x298` layout and class close before children; `C6C9666A02C70CCE666773CD8820D84F0DCF2151FAE72E1DEEA5E701577CDB95`, 26,738 / 277. |
| UID0000PB file | `91/92`, route `NexusTK/map/`; `CC6B2596659829856E9FCD5272FFC7BF0ACB3A207686B9ABF628D32BA2C6AB4A`, 18,388 / 147 | `92/93`, same route and full source/compiler/global union; `30684C5311DE628267EC3F96EA312EFD9255AE5AA0DEECE9E13AB27AF9EC6FFD`, 22,087 / 165. |
| UID000271 read-only parent | `90/93`, false, blank emitter/formal; `E8BC79F610A23BC3FC3AE6A3EEC36C4F00A705697B01BDA0DAF6C82A56545E26`, 12,603 / 126 | Same `90/93` metadata/range/R0-equivalent blank; child/source dispositions synchronized; `7E9498372D6BD89B67C562C29EBDF1C8D3035B7BCDE3D74AD950267FCC97F0DD`, 13,879 / 129. |
| UID00035H vtable | `86/91`, true/emitter 0000G9; `B9AF59774CFF75C3F288C83CF99F16E2E619704FEC46AB14668559F056D7F68C`, 5,735 / 70 | `92/94`, false, blank emitter/position/R3, `Nested:0`; `A69BCDFBE704A3B0DA29E2B6AB4B6D162E56B88A15EEC680829E45413B08BD91`, 7,223 / 75. |
| UID00035I strings | `86/91`, true/emitter 0000G9; `FA33950B7D7A8A5CBAB1575FBCC0B5540AFC14B152A533437F4905D23923DD86`, 4,859 / 66 | `91/94`, false, blank emitter/position/R4, `Nested:0`; `12B81AB110EEB8B6BC065777E3CE4A35926596806D6466346DF54A5C40965E2E`, 6,733 / 72. |
| UID00035J constants | `86/91`, true/emitter 0000G9; `F2B63B9808E354AEA4D525964555169FFAA89BD8FEAA01595FEF7C793801C83A`, 5,291 / 67 | `91/94`, false, blank emitter/position/R5, `Nested:0`; `ECCDCC5692EDFA56F46EF7EFF64BF66140EC8BBB34A9D94AFB49BCA8397025C9`, 6,691 / 72. |
| UID00029E physical singleton | `86/90`, stale initialized `0xffffffff`, emitter 0000PB; `5CA86C78FD3AE8A00818CFE28FA31B9ABB656F55238C02DF14666B5599F0C1DC`, 6,667 / 82 | `92/94`, owner/emitter UID0004T9, true, R6, loader-zero correction; `AE48882BF47A42D9204480529F3F7862EFAA6458E1B26730CBC2E5A8720ED133`, 8,545 / 88. |
| UID0004T9 semantic global | Absent; accepted provisional destination. | Validator-issued `92/94`, owner/emitter UID0000PB, true, blank position, exact R7; `D3EA696909BADB7CAD78C4322D5C9893D4B27FAF66732B0750C4B4992C24F420`, 5,016 / 73. |
| UID0003TP packet caller | `92/94`; `A1E2A58BC9ECF985FEA5E33BAA8D0404A52A18E748E75C0238DB44D2BB00BB32`, 21,901 / 385 | Verify-only; supplies exact eight-input contract and temporary-lifetime proof. |
| UID0003SR BFS | `92/94`; `5E4C926A35408940AA880C110F75E8DA44967BEBA1F03D5EF70AB6642A0A8C8E`, 12,641 / 155 | Verify-only; constructor invokes its exact unguarded directed BFS twice, one per branch. |
| UID0003SP clamp | current exact page `0E05C6C1C592293CF648369D6E65867CE6EC7EB33B6AB6F2BB0F9EF4D7C1C6D9`, 2,713 / 45 | Verify-only; source call is `ClampViewPosition(float *, float *)`. |
| UID0000G8 / UID0000GA | `FEE9CE5C28808BDCFA756B8D8AA2E3B637E64476DF666D2D8FDDE692ECE1F77A` / `15E157E04A69622CA915A7EE35C100C54ADAC9117813A8A3CD90E5870BF7E804` | Verify-only standard-container documentation facades; no custom source classes. |

### Historical Report Search

The exact terms `TARGET-REPORT-UID:0003SC`, `UID:0003SC`, `0003SC`, `0x005c2ac0`, `WorldMapPaneConstructorAndNodeSetup`, `WorldMapPane`, `WMSYMBOL.EPF`, `SYMBOLS.EPF`, `WorldMapNodeEntryVector`, and `BuildReachabilityData` were searched in all required roots: `tools/leaser/Agents/**`, `executed-b-agent-research/**`, `archived/**`, `tools/leaser/Agents/Older-Research/**`, and `tools/leaser/Agents/SpecialReports/**`.

- No prior direct exact-target report exists in any report root. The only active `TARGET-REPORT-UID:0003SC` match is this assignment's goal text, not research.
- Executed B001 `0001O4-worldmap-source-split-audit.md`, SHA256 `8386132B9F3B6083F1FA855A307505607ACB49A6AA35D9A3B9C250A114E10187`, 40,682 / 335, is valid range/function-family history but intentionally left UID0003SC source blockers open.
- Executed B001 `000271-WorldMapReadOnlyData.md`, SHA256 `2AF2410E5F2D28A1404170F08F2460F988892D762D44F8F515B0BC7E4DF1D574`, 12,887 / 160, is valid read-only split evidence, not constructor closure.
- Executed B001 `0003TP-MapPaneHandleObjectWorldMapCreationPacket-source-quality.md`, SHA256 `089014A525DD1EE3A4E945D54768416F8082157802924116278EE5587AAA6C62`, 124,989 / 1,118, supplies packet/caller/lifetime support and was independently revalidated here.
- Executed B004 `0003SR-WorldMapPaneBuildReachabilityData-source-quality.md`, SHA256 `91941C444B8897AFBC9BB2EBD4FCA7361DF6C2EDE0F6D7E2BA9E2F97823BDEFA`, 58,128 / 569, supplies the graph field and helper contract but not constructor resources/layout.
- Executed B003 `0003P9-SharedEpfSuffixString-current-source-routing.md`, SHA256 `A4314D276ABC8C61AAE44C4D16F3464B264CE03E7F5193ABC7F356D615FF9FCD`, 35,402 / 489, confirms shared `.EPF` use and non-ownership; it does not own R1.
- Older/special/archived matches contain naming or broad source-placement leads only. None has the complete target body, exact 0x298 class closure, or zero-filled singleton correction.

## Target

- UID: `0003SC`.
- Current path: `by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md`.
- Exact half-open range: `[0x005c2ac0,0x005c32aa)`.
- Exact size: `0x7ea` / 2,026 bytes.
- Current IDA name: `sub_5C2AC0`.
- Recommended source name: `WorldMapPane::WorldMapPane`.
- Recommended source file: `NexusTK/map/WorldMapPane.cpp`; declaration in `WorldMapPane.h` through UID0000G9.
- PE artifact: `E:/NTK/Resources/NexusTK/NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes.
- Raw file offset: `0x001c1ec0`.
- Exact target-byte SHA256: `B53A70576DE033CAEA511AF7F06B7499EBD47A0DEB556C5240D2087CE522E5C3`.
- Entry bytes: `55 8b ec 6a ff 68 ae bf 60 00 64 a1 00 00 00 00`.
- Final target bytes: `89 0d 00 00 00 00 59 5f 5e 5b 8b e5 5d c2 20 00`.
- Instruction count: 568.
- IDA compact analysis reports 43 CFG entries including external EH/cookie funclets; source-facing main constructor control is the two asset arms plus node loops and cleanup edges, not 43 handwritten blocks.

## Current Target State

UID0003SC is implemented at `92/94`, owner UID0000G9, emitter UID0000PB, reconstructable true, blank optional position, exact R1, and `Nested:+4`. The pre-callback `86/90` blank-formal/resource/private-declaration limitation is explicitly historical. Current ordinary documentation closes both branches, exact class layout, source API, global, containers, helper calls, compiler exclusions, complete managed C++, range/hash/ABI/callers, padding, no-check behavior, and score rationale.

Command 14831 (`2026-07-20T01:05:46-04:00`, SHA256 `363A84A8AD8495D6FE9A26F20E6BD58439529F3F0DEC445E1F796CE0CC606D3D`, 2,272 bytes / 56 lines) is retained only as the historical external pre-callback generated checkpoint with six relevant Empty Emitter Markers. B003's authorized waited validator command `000000014846`, refreshed `2026-07-20T01:45:47-04:00`, now produces `auto-generated/NexusTK/map/WorldMapPane.cpp` SHA256 `55085607B076C68BCC224F877176D360C7FF5EC40E5FAC8B35F22B9A862743D2`, 10,091 bytes / 266 lines. The class closes at generated line 85 before UID0004T9 at line 89, UID0003SC at line 93/constructor line 94, and UID0003SR at line 229/definition line 233. It contains one constructor, one BFS, one `g_pWorldMapPane = 0` definition, two total/two unique qualified `WorldMapPane` definitions, zero relevant or total Empty Emitter Markers, zero duplicate/wrong-range target, and no handwritten vtable/RTTI/string/constant array, EH/cookie, scalar/adjustor, or Dinkumware helper body.

Final callback read-only manual snapshots are: by-memory SHA256 `C8202C988A6C0AD282B4C43B4D4EBB4F72449EB2F0739F91E2B6431C39DD743E`, 1,815,323 bytes / 4,327 lines; by-class `862E9BE235064C33459EC225C96742B03829D18ECB39A53FF599ACCB2657F75B`, 235,871 / 623; by-file `6E32409881C7D5C8D11792F140B775AF022D3A3D01BE808FBD632CF58DFB367F`, 134,635 / 316; by-global `3F831C9FA2FB5CD22E1DD2796DFA0E73731B115FC03E33EC8D3744B886AB6238`, 90,147 / 212. These supersede the accepted report's earlier read-only hashes after unrelated external supervisor coverage updates. The WorldMap rows themselves remain exact stale pre-callback text: UID0001O4/0003SC now at lines 3716/3717, UID000271/35H/35I/35J at 4024-4027, UID00029E at 4229, UID0000G9 at 606, UID0000PB at 307, and no UID0004T9 row. Class/file/global anchors remain unchanged; only by-memory anchors shifted by thirteen lines. B003 did not edit any manual snapshot.

## Executive Recommendation

R1 is implemented as the sole constructor definition and R2 as the complete source-era declaration. Vtable stores, EH state, cleanup funclets, cookie checks, and standard-container implementation helpers remain outside human C++. Both resource branches remain duplicated source with their branch-local map-name copy, uppercase operation, node assignment, initial position, clamp, invalidation, BFS, timer scheduling, and boat loads. No binary-absent safety check was added.

Exactly one new semantic global page, UID0004T9 `by-global/g_pWorldMapPane.md`, was registered through the validator before dependent validation. The physical four-byte page remains address evidence and emits only a covered-storage comment through UID0004T9, while the semantic page owns the sole definition. No other new page, split, range change, or rename is warranted.

## Supervisor Active Recheck

At report finalization, live IDA database `9b0396a3` was enumerated by `idb_list`, `server_health` returned `status:ok`, auto-analysis/Hex-Rays/string cache ready, and bounded lookup, bytes, decompile, disassembly, caller analysis, and resource/global reads succeeded. The target still resolved as `sub_5C2AC0`, size `0x7ea`; target bytes and six successor `cc` bytes matched local PE evidence. This is evidence-collection provenance, not an indefinite assertion that the worker/session will remain active.

The callback used one ordinary lease at a time and released it immediately after the file's validator batch. The final current lease ledger has no active lease and no B003 lease. The report-only evidence-time ledger hash remains historical; it is not used to imply that no callback leases occurred.

## Inference Research Guidance Check

- Binary facts, caller contracts, data layout, RTTI PMDs, xrefs, literal bytes, resource frame indices, branch order, and exact storage are treated as direct evidence.
- `WorldMapPane`, `WorldMapNode`, `g_pWorldMapPane`, existing child names, `g_useEpfAssets`, `g_pEPFLib`, `g_pPaletteLib`, `g_pUserPane`, `SimpleUString`, `EPFTileContext`, `LivingSpriteConfig`, and `DLPalette` are corroborated project names.
- Private member spellings such as `m_navigationActive`, `m_mapImage`, and `m_boatBackImage` are source-facing inferred names. They are constrained by exact offsets, cross-method roles, and source-era style; their lexical uncertainty caps confidence at 94, but does not block behavior-complete C++.
- Direct base order and EBO are inferred from RTTI PMDs plus constructor order, not raw offset coincidence alone.
- The global source definition follows the mature project semantic-global/physical-storage pattern independently checked against `g_pMapTileImageLib`; it is not inferred solely from a generated marker.
- The constructor's raw EAX return is compiler ABI behavior. Source return is absent because constructors have no return type.

## Heuristic / Inference Reanalysis And Validation

### Constructor ABI And Inputs

The binary returns with `retn 0x20`, proving eight explicit 32-bit stack slots. Caller and callee data flow resolve them, after implicit `this`, as:

1. `const wchar_t *mapName`.
2. signed `short nodeCount` (passed in a 32-bit slot; callee sign-tests it).
3. signed `short currentNodeIndex` (passed in a 32-bit slot; sign-extended into the 32-bit hover field and stored as a 16-bit route origin).
4. `const MapPoint *nodePositions`.
5. `const wchar_t *const *nodeNames`.
6. `const unsigned short *destinationMapIds`.
7. `const MapPoint *destinationPositions`.
8. `const std::vector<bool> &adjacency` using the old-MSVC 16-byte vector-bool object.

UID0003TP obtains node count and current index from unsigned packet bytes, but the source ABI is signed because the constructor sign-tests count and sign-extends current index. Preserving `short` captures binary semantics without inventing packet validation.

### Exact Class Shape

RTTI rooted at COL `0x00654208` and CHD `0x0065421c` has eight base descriptors. PMDs place `WorldMapPane`, `Pane`, `GrafPort`, and `LObject` at zero; `EventHandler` at `+0xa0`; `TimerHandler` at `+0xa4`; direct `FrameHandler` at `+0xf8`; and empty `Singleton<WorldMapPane>` at `+0xfc`. Constructor lowering calls `Pane(0)`, constructs FrameHandler, then performs Singleton publication. The source direct-base order is therefore `Pane, FrameHandler, Singleton<WorldMapPane>`. Singleton is empty and overlaps the first member at `+0xfc` through MSVC EBO.

| Offset | Size | Source member / role |
| --- | ---: | --- |
| `+0x000..+0x0f7` | `0xf8` | `Pane` base, including inherited EventHandler and TimerHandler facets. |
| `+0x0f8..+0x0fb` | 4 | direct `FrameHandler` base. |
| `+0x0fc` | 0 by EBO | empty direct `Singleton<WorldMapPane>` base overlaps first member. |
| `+0x0fc..+0x123` | `0x28` | `EPFTileContext m_mapImage`. |
| `+0x124..+0x14b` | `0x28` | `EPFTileContext m_reachableNodeSymbol`. |
| `+0x14c..+0x173` | `0x28` | `EPFTileContext m_unreachableNodeSymbol`. |
| `+0x174..+0x19b` | `0x28` | `EPFTileContext m_boatBackImage`. |
| `+0x19c..+0x1c3` | `0x28` | `EPFTileContext m_boatFrontImage`. |
| `+0x1c4/+0x1c8` | 4 each | `DLPalette *m_boatPalette`, `DLPalette *m_mapPalette`. |
| `+0x1cc..+0x1d8` | 4 each | current X/Y and target X/Y floats. |
| `+0x1dc/+0x1dd` | 1 each | navigation/travel active and dragging-view booleans. |
| `+0x1de..+0x1df` | 2 | natural alignment, no source member. |
| `+0x1e0/+0x1e4` | 4 each | player column and row floats. |
| `+0x1e8` | 4 | `int m_hoveredNodeIndex`. |
| `+0x1ec` | 2 | `short m_currentNodeIndex`. |
| `+0x1ee..+0x1ef` | 2 | natural alignment. |
| `+0x1f0..+0x233` | `0x44` | `LivingSpriteConfig m_playerSpriteConfig`. |
| `+0x234/+0x238` | 4 each | route-progress/current-node and final travel target fields. |
| `+0x23c..+0x23f` | 4 | natural double alignment. |
| `+0x240` | 8 | travel heading/angle double. |
| `+0x248/+0x24c` | 4 each | drag-start screen X/Y. |
| `+0x250` | 4 | player animation frame. |
| `+0x254` | 4 | `SimpleUString m_mapName`. |
| `+0x258..+0x263` | 12 | `std::vector<WorldMapNode> m_nodes`. |
| `+0x264..+0x273` | 16 | `std::vector<bool> m_adjacency`. |
| `+0x274..+0x283` | 16 | `std::vector<bool> m_reachableNodes`. |
| `+0x284..+0x28f` | 12 | `std::vector<int> m_predecessors`. |
| `+0x290` | 1 | player-over-special-region boolean. |
| `+0x291..+0x297` | 7 | natural tail/alignment to exact `0x298`. |

The constructor does not initialize `+0x234`, `+0x238`, `+0x240`, `+0x248`, or `+0x24c`; R1 deliberately omits them from its initializer list. It writes byte 80 inside `LivingSpriteConfig` during default construction and then overwrites the complete config from `g_pUserPane` in each branch. R1 expresses normal member construction plus the full copy, not a raw guessed field write.

### Node And Container Model

`WorldMapNode` is exactly `0x94` bytes: `MapPoint position` at `+0x00`, `wchar_t name[64]` at `+0x08`, `unsigned short destinationMapId` at `+0x88`, natural two-byte padding at `+0x8a`, and `MapPoint destinationPosition` at `+0x8c`. The constructor calls the generated UID0003T7 vector assign helper to create `nodeCount` value-initialized records, then copies each position, bounded name, destination ID, and destination point. It stores no caller pointer. UID0000G8 remains a non-emitting documentation facade over `std::vector<WorldMapNode>`.

The adjacency argument is copied as an old-MSVC `std::vector<bool>`. Reachable flags are separately default constructed as `std::vector<bool>` and predecessors as `std::vector<int>`. UID0000GA remains a non-emitting documentation facade; no custom bitset class is source-authored.

### Callee And Source-API Factorization

| Binary callee | Source-facing operation | Ownership / emission decision |
| --- | --- | --- |
| `sub_544460` | `Pane(0)` | Shared Pane source; constructor base call only. |
| `sub_457A60` | default `EPFTileContext` initialization | Five member constructions; shared type source. |
| `sub_53A8C0` | `g_pUserPane->GetSpriteConfig` | Copies the complete 0x44 player sprite configuration. |
| `sub_582B20` | default `SimpleUString` construction | Member initialization, not a custom target helper. |
| `sub_582D20` | wide string assignment | `m_mapName = mapName`. |
| `sub_5830C0` | detach/make-exclusive | Existing source vocabulary `MakeExclusive()`. |
| `sub_583450` | string representation/length access | Supplies uppercase buffer count; represented by `length() + 1`. |
| `sub_582980` | in-place uppercase CRT wrapper | `_wcsupr_s` source expression. |
| `_memset` | zero/value-initialize one local 0x94-byte node | Compiler lowering for `WorldMapNode()`. |
| `sub_5C58C0` | old-MSVC vector assign | `m_nodes.assign(nodeCount, WorldMapNode())`; UID0003T7 remains no-code library support. |
| `_wcscpy_s` | bounded copy of 64-wide node name | Direct CRT source call. |
| `sub_421290` | old-MSVC `vector<bool>` copy construction | `m_adjacency(adjacency)`; no custom bitset source. |
| `sub_582A90` | `SimpleUString` temporary copy | Branch-local resource-name temporary. |
| `sub_584470` | append a four-wide suffix | `resourceName +=` the exact suffix. |
| `sub_584540` | wide string data accessor | `resourceName.c_str()`. |
| `sub_582B70` | temporary string destruction | Automatic lifetime, not explicit target helper. |
| `sub_4D02F0` | `g_pEPFLib->LookupLayoutEntry` | Shared resource API, exact names/frames in R1. |
| `sub_4B78F0` | `RectBounds::Offset` | Map-origin and symbol-anchor translations. |
| `sub_543D70` | `g_pPaletteLib->GetPaletteByName` | Returns borrowed library-owned `DLPalette *`; target does not delete palettes. |
| `sub_5C4740` | `ClampViewPosition` | Existing WorldMapPane child UID0003SP. |
| virtual slot at complete `+0x20` | `InvalidateRect(0)` | Inherited Pane invalidation; no new helper. |
| `sub_5C4BD0` | `BuildReachabilityData` | Existing sole UID0003SR definition. |
| `sub_5975E0` | `ScheduleTimer(0,150,0,0)` | Inherited TimerHandler API through `+0xa4` facet. |

### Lifetime, Ownership, And Exception Lowering

- The caller owns `mapName`, node arrays, name pointers, destination arrays, and the adjacency object for the call duration. R1 copies every persistent value. It stores no input address.
- `m_mapImage`, two symbol contexts, and two boat contexts are value members with normal construction/destruction. Map and boat palette pointers are borrowed from PaletteLib and are never deleted by this constructor.
- `m_playerSpriteConfig` is a value member. Its default construction seeds the observed byte 80 before both branches overwrite the complete structure from UserPane.
- The target has an MSVC SEH prologue and external cleanup/cookie funclets around `0x0060beeb`, `0x0060bf07`, `0x0060bf5a`, `0x0060bf73`, `0x0060bf8c`, `0x0060bfa5`, and `0x0060bfbb`. State changes cover initialized members and branch-local `SimpleUString` temporaries. On an exception the compiler unwinds constructed strings/vectors/tile contexts in reverse lifetime order and clears Singleton publication through compiler cleanup support; the enclosing `new` expression owns storage release for a failed construction.
- Those cleanup edges are consequences of automatic members/base classes and source temporaries. R1 must not contain an explicit `try`, `catch`, SEH record, cleanup label, vptr repair, cookie check, or raw singleton clear.
- Successful factory caller `sub_50F270` retains the complete pane, creates/owns the Layer relationship, and installs the pane; successful packet caller UID0003TP releases its parsing temporaries after construction. Neither caller changes target source ownership.

### Branch And Resource Validation

Both branches first copy player sprite configuration, copy and make the map-name string exclusive, uppercase it with `_wcsupr_s`, value-initialize/copy nodes, and then perform branch-specific asset setup. The common body is duplicated in the executable; source factorization into a new helper is rejected because no call boundary or shared helper exists.

Current mode (`g_useEpfAssets == 1`): map `mapName + L".EPF"`, `WMSYMBOL.EPF` frames 0 and 1, map palette `mapName + L".PAL"`, `BOAT.EPF` frame 0, `BOAT.PAL`, and `BOAT.EPF` frame 1. Legacy mode: map `mapName + L".EPD"`, `SYMBOLS.EPF` frames 36 and 72, map palette `mapName + L".PAD"`, `BBOAT.EPD` frame 0, `BOAT.PAD`, and `FBOAT.EPD` frame 0. Map-image bounds are translated by their negative left/top; both symbol bounds are translated by `(-6,-6)`.

The UTF-16 bytes were freshly read in the current session at `0x00631490-0x00631528`. Shared `.EPF`, `.PAL`, and `SYMBOLS.EPF` storage remains owned by its existing shared pages; R1 is a source use, not data ownership. There are no missing-resource branches, null checks, return tests, or exception catches in authored control flow.

| Address | Literal/global | Exact target role |
| --- | --- | --- |
| `0x0061a44c` | shared `.EPF` | Current map filename suffix. |
| `0x0061ea24` | shared `.PAL` | Current map palette suffix. |
| `0x00610ca4` | shared `SYMBOLS.EPF` | Legacy symbol frames 36 and 72. |
| `0x00631490` | `WMSYMBOL.EPF` | Current reachable/unreachable frames 0 and 1. |
| `0x006314ac` | `BOAT.EPF` | Current back/front boat frames 0 and 1. |
| `0x006314c0` | `BOAT.PAL` | Current boat palette. |
| `0x006314d4` | `.EPD` | Legacy map filename suffix. |
| `0x006314e0` | `.PAD` | Legacy map palette suffix. |
| `0x006314ec` | `BBOAT.EPD` | Legacy back boat frame 0. |
| `0x00631500` | `BOAT.PAD` | Legacy boat palette. |
| `0x00631514` | `FBOAT.EPD` | Legacy front boat frame 0. |
| `0x0066da94/0x0066da98` | `g_screenWidth/g_screenHeight` | Initial current/target view centers. |
| `0x0066da97` | `g_useEpfAssets` | Exact equality to one selects current assets. |
| `0x0067a744` | `g_pEPFLib` | Resource layout lookup provider. |
| `0x0067a7e0` | `g_pPaletteLib` | Borrowed palette lookup provider. |
| `0x0067a748` | `g_pUserPane` | Complete player sprite configuration source. |

### Initial State And Call Order

Screen width/height are halved into current and target views before branch processing. The current node record then overwrites player column/row and current/target view. Exact order in each branch is: initialize/copy data; load map/symbol/palette; derive current coordinates; clamp; invalidate with null region; build reachability; schedule timer zero for 150 ms with zero trailing arguments; load back boat; load boat palette; load front boat. No empty-node or index guard precedes current-record indexing.

## Evidence Standards Used

- Direct: current live MCP `idb_list`, health, bytes, function lookup, full decompile, disassembly total, compact analyses, caller analyses, xrefs, resource bytes, singleton bytes, and local PE hash/mapping.
- Corroborated: exact current by-* metadata, executed target-family reports, current generated output, manual rows, class/file source routes, and current ignored padding.
- Inferred but bounded: private identifier spellings and access sections; inference is constrained by exact layout, callers, child method uses, RTTI, and source-era conventions.
- Excluded: generated aliases as source names, raw vtable/RTTI arrays, explicit vptr stores, SEH state/cookie operations, cleanup funclets, Dinkumware helper bodies, decompiler labels, raw addresses, and synthetic validation/factoring.

## Evidence Checked

1. `idb_list` returned the adopted NexusTK IDB session `9b0396a3`; health was `ok` with analysis, Hex-Rays, and strings ready.
2. `lookup_funcs(0x005c2ac0)` returned `sub_5C2AC0`, size `0x7ea`.
3. Bounded `get_bytes` returned the exact entry bytes and six `cc` bytes at `0x005c32aa`.
4. `disasm` reported 568 total instructions and an MSVC SEH prologue.
5. Full `decompile` covered both branches and all 22 callees without target failure.
6. Compact analysis found exactly two call xrefs, at `0x0050f2fa`/fresh decompile endpoint `0x0050f2ff` and `0x005126f9`.
7. Caller `0x0050f270` allocates `0x298`, invokes the constructor, allocates an eight-byte Layer, installs full-screen bounds, and stores the pane.
8. Caller `0x00511db0` parses/copies packet data and frees temporary arrays after construction.
9. Resource bytes at `0x00631490` exactly decode all eight branch-local strings.
10. Current MCP bytes at `0x0069b454` are `00 00 00 00`. Local PE mapping gives image base `0x00400000`, RVA `0x0029b454`, `.data` RVA `0x0026d000`, virtual size `0x2fe24`, raw size `0xd800`, raw pointer `0x0026ac00`, and slot offset `0x2e454` within `.data`. The raw-backed section ends at RVA `0x0027a800`, while the virtual section ends at `0x0029ce24`; the slot is therefore loader-zero-filled and has no backing file bytes. Stale `ff ff ff ff` is an IDB/database artifact, not the load-time value.
11. RTTI PMDs and constructor stores were checked for Pane/EventHandler/TimerHandler/FrameHandler/Singleton inheritance and EBO.
12. Target, aggregate, class, file, read-only-data, vtable, string, constant, singleton, packet, BFS, clamp, helper classes, generated output, manual coverage, tracker, ignored padding, and lease ledger were reread read-only.

## Claim And Incorporation Ledger

| Claim | Action | Verification state | Exact destination | Implementation proof |
| --- | --- | --- | --- | --- |
| C01 | incorporate | applied | UID0003SC | Current `Exact Binary, ABI, And Boundary Evidence` records healthy evidence-time session `9b0396a3`, bounded lookup/bytes/decompile/disassembly/xref/caller/callee probes, PE SHA/path, exact target hash/bytes, 568 instructions, and 43 IDA CFG entries; validator 14837, exit 0/`ok:1`. |
| C02 | incorporate | applied | UID0003SC, UID0001O4 | Both pages preserve `[0x005c2ac0,0x005c32aa)`, `0x7ea`, predecessor `[0x005c2ab5,0x005c2ac0)`, six-byte successor pad `[0x005c32aa,0x005c32b0)`, destructor start, and no split; validators 14837/14838. |
| C03 | incorporate | applied | UID0003SC, UID0000G9 | Exact R1/R2 use eight explicit arguments with signed `short` count/index, typed arrays and `const std::vector<bool> &`; target ABI evidence preserves `retn 0x20`; validators 14837/14839. |
| C04 | incorporate | applied | UID0003SC, UID0000PB | Target/file sections preserve both callers, exact `0x298` allocation and Layer installation, UID0003TP temporary release, deep-copy semantics, and MapPane.cpp/WorldMapPane.cpp boundary; validators 14837/14840. |
| C05 | incorporate | applied | UID0003SC, UID0000G9, UID00035H | Target/class/vtable pages preserve Pane/FrameHandler/Singleton order, four views, publish/fallback lowering, eight-base RTTI PMDs and EBO; validators 14837/14839/14842. |
| C06 | incorporate | applied | UID0000G9 | R2 is byte-for-byte equal to the report (`45e498...19b3`); exhaustive `0x298` table, natural padding, member order/types, direct bases/access and class close at generated line 85 before children are current; validator 14839. |
| C07 | incorporate | applied | UID0003SC, UID0000G9; UID0000G8/UID0000GA verify-only | Target/class contain exact `0x94` node and standard containers; G8/GA hashes remain `FEE9CE...F77A`/`15E157...E804`; generated helper bodies remain excluded. |
| C08 | incorporate | applied | UID0003SC | Both R1 arms copy `mapName`, call `MakeExclusive`, then `_wcsupr_s` on the owned buffer; target prose rejects an invented helper; validator 14837. |
| C09 | incorporate | applied | UID0003SC, UID00035I | R1 and literal page preserve `<MAP>.EPF`, WMSYMBOL frames 0/1, `(-6,-6)`, `<MAP>.PAL`, BOAT frames 0/1 and BOAT.PAL order; validators 14837/14843. |
| C10 | incorporate | applied | UID0003SC, UID00035I | R1 and literal page preserve `<MAP>.EPD`, SYMBOLS.EPF 36/72, `<MAP>.PAD`, BBOAT.EPD/BOAT.PAD/FBOAT.EPD order; validators 14837/14843. |
| C11 | incorporate | applied | UID0003SC; UID0003SP/UID0003SR already present | R1 preserves half-screen defaults, current-node overwrite, Clamp/Invalidate/BFS/Timer order in both arms; SP/SR hashes remain `0E05C6...C6D9`/`5E4C92...8C8E`; generated BFS once. |
| C12 | incorporate | applied | UID0003SC, UID0000G9 | Current target/class explicitly retain no guards, no adjacency symmetrization, no resource fallback/error translation, no branch factoring, and intentional noninitialization of route/drag members; validators 14837/14839. |
| C13 | incorporate | applied | UID0003SC, UID0001O4, UID0000PB | Current pages exclude explicit vptr/singleton raw stores, EH/cookies, cleanup funclets, scalar/adjustor wrappers and allocator/Dinkumware bodies; generated command 14846 contains none. |
| C14 | incorporate | applied | UID0003SC | `92/94`, owner 0000G9, emitter 0000PB, true, blank position, `Nested:4`, exact Item Summary and R1 (`ba581b...c7bf`) are current; validator 14837. |
| C15 | incorporate | applied | UID0001O4, UID0000G9, UID0000PB | Current scores are `90/93`, `93/94`, `92/93`; R0 is blank, R2 complete, `NexusTK/map/` route/family history preserved; validators 14838-14840. |
| C16 | incorporate | applied | UID000271, UID00035H, UID00035I, UID00035J | Parent remains `90/93` false/blank; children are `92/94`, `91/94`, `91/94`, false/blank R3-R5 with exact tables/xrefs/source causes; validators 14841-14844. |
| C17 | incorporate | applied | UID00029E, UID0004T9 | Validator 14836 issued UID0004T9 first; UID00029E is `92/94`, owner/emitter 0004T9 with PE/MCP zero-fill and exact R6 (`8bdd97...5924`); global is `92/94`, owner/emitter 0000PB with exact R7 (`fced1d...1bc4`); validator 14845. No provisional token remains. |
| C18 | already-present | already-present | UID0003TP, UID0003SR, UID0003SP, UID0000G8, UID0000GA and named dependencies | Read-only hashes/scores remain exact: TP `A1E2A5...BB32` `92/94`, SR `5E4C92...8C8E` `92/94`, SP `0E05C6...C6D9` `86/90`, G8 `FEE9CE...F77A` `90/94`, GA `15E157...E804` `91/94`; siblings/API/global/type pages were not edited. |
| C19 | incorporate | applied | all ten ordinary destinations, UID0000PB/generated readback | Scoped commands 14836-14845 succeeded; waited command 14846, exit 0/`ok:1`, generated SHA `550856...43D2`, one R1 constructor, one R7 global, one existing BFS, class before definitions, zero marker/duplicate/raw compiler-data bodies. |
| C20 | incorporate | applied | this report/manual handoff/checklist | Report records issued UID, ten hashes, commands/timestamps/results/warnings/side effects, eight exact formal parity results, generated metrics/assertions, current stale manual rows and exact supervisor-owned handoff, 38 checked rows, and zero leases/prohibited lifecycle action. |

## Positive Evidence Summary

- Exact half-open target is a complete MSVC constructor with `retn 0x20`, two callers, 22 callees, and no internal foreign function starts.
- Both callers agree on a `0x298` `WorldMapPane` object and the eight-input ordering.
- Packet-side cleanup after construction proves all persistent arrays/strings/adjacency are copied.
- Five repeated 40-byte initializers map exactly to five `EPFTileContext` members.
- RTTI PMDs and constructor order jointly prove Pane, FrameHandler, Singleton direct inheritance and EBO.
- Cross-method uses distinguish hovered-node `int` from current-node `short` and close all container types.
- Exact literals, frame indices, suffixes, and palette calls close both resource branches.
- Current MCP and PE section mapping prove singleton zero initialization, correcting the stale page.
- Existing UID0003SR C++ and target calls align exactly with unguarded directed BFS setup.
- Every generated Empty Emitter Marker has a coherent source or no-code disposition after R1-R7.

## IDA MCP Facts

- Database/session at evidence collection: `9b0396a3`, `E:/NTK/Resources/NexusTK/NexusTK.exe.i64`.
- Health: `status:ok`; auto-analysis, Hex-Rays, strings ready; 2,067 cached strings.
- Target function: `sub_5C2AC0`, `0x7ea` bytes, 568 instructions.
- Raw prototype: `int __thiscall(int, const unsigned short *, short, int *, int, int, int, int, int)`; source constructor ABI is resolved above.
- Callers: `sub_50F270` and `sub_511DB0` only.
- Callees: `sub_5830C0`, `sub_584470`, `sub_544460`, `_memset`, `sub_582B20`, `sub_5C4740`, `sub_582980`, `sub_582A90`, `_wcscpy_s`, `sub_584540`, `sub_4D02F0`, `sub_421290`, `sub_5C4BD0`, `sub_583450`, `sub_5975E0`, `sub_4B78F0`, `sub_582B70`, `sub_457A60`, `sub_582D20`, `sub_543D70`, `sub_5C58C0`, and `sub_53A8C0`.
- Singleton bytes: `00 00 00 00` at `0x0069b454` in current memory.
- Resource bytes: complete UTF-16 band at `[0x00631490,0x00631528)` read successfully.

## Function / Child Inventory

| Range / symbol | Source-facing role | Disposition |
| --- | --- | --- |
| `0x005c2ac0-0x005c32aa` UID0003SC | `WorldMapPane::WorldMapPane` | Source-authored, R1. |
| `0x005c32aa-0x005c32b0` | six-byte `cc` alignment | Parent-only padding, not source. |
| `0x005c32b0-0x005c341e` UID0003SD | ordinary destructor | Existing sibling, verify-only. |
| `0x005c3420-0x005c346d` UID0003SE | `SetViewPosition(float,float)` | Existing sibling declaration. |
| `0x005c34c0-0x005c3508` UID0003SF | `StartViewAnimation(float,float)` | Existing sibling declaration. |
| `0x005c3540-0x005c3627` UID0003SG | `StartTravelToNode(int)` | Existing sibling declaration. |
| `0x005c3630-0x005c36c8` UID0003SH | `SendTravelPacket(int)` | Existing sibling declaration. |
| `0x005c36d0-0x005c37d6` UID0003SI | visible clip helper | Existing sibling; descriptive private name cap. |
| `0x005c37e0-0x005c38fd` UID0003SJ | `HitTestNode(int,int)` | Existing sibling declaration. |
| `0x005c3950-0x005c3e41` UID0003SK | draw override | Existing sibling declaration. |
| `0x005c3e50-0x005c402b` UID0003SL | key/text event override | Existing sibling declaration. |
| `0x005c40c0-0x005c4245` UID0003SM | pointer/mouse override | Existing sibling declaration. |
| `0x005c4250-0x005c46e9` UID0003SN | frame callback | Existing sibling declaration. |
| `0x005c46f0-0x005c4733` UID0003SO | timer callback | Existing sibling declaration. |
| `0x005c4740-0x005c484b` UID0003SP | `ClampViewPosition(float *,float *)` | Existing sibling, verify-only. |
| `0x005c48b0-0x005c4bd0` UID0003SQ | `DrawPlayerMarker(int,int)` | Existing sibling declaration. |
| `0x005c4bd0-0x005c5075` UID0003SR | `BuildReachabilityData()` | Existing emitted source, exactly once. |
| `0x005c5080-0x005c50e6` UID0003SS | hover update | Existing sibling declaration. |
| `0x005c50f0-0x005c5156` UID0003ST | strict hover update | Existing sibling declaration. |
| `0x005c5160-0x005c519c` UID0003SU | `FindPredecessorNode()` | Existing sibling declaration. |
| `0x005c51a0-0x005c51fb` UID0003SV | screen-point helper | Existing sibling declaration. |
| `0x005c5200-0x005c53d0` UID0003SW | special-region hit test | Existing sibling declaration. |
| vector/bool helpers after `0x005c53d0` | Dinkumware specialization bodies | Compiler/library no-code; declarations use standard containers. |
| scalar/adjustor/cleanup wrappers | compiler ABI lowering | No human declaration/body beyond ordinary virtual destructor. |

## Direct Xref / Caller Inventory

| Callsite | Containing function | Exact meaning |
| --- | --- | --- |
| `0x0050f2fa` (fresh decompile call completion `0x0050f2ff`) | `sub_50F270`, size `0x142` | Allocates `0x298`, passes the eight constructor values while dropping one wrapper-only argument, allocates an 8-byte Layer, registers it, installs full-screen bounds, activates/stores the pane. This is factory/client code, not constructor ownership. |
| `0x005126f9` | UID0003TP `sub_511DB0` | Packet opcode path parses map name, signed-source count/current byte values, positions, names, destination data, and packed directed adjacency, invokes constructor, then frees caller temporaries. |

No vtable or read-only-data pointer is a direct code caller. No third callsite, import-table route, tail call, callback entry, or stored raw constructor pointer was found.

## Documentation Evidence And IDA Status

Historical pre-callback documentation was structurally sound but stale at the exact source blockers this assignment targeted: UID0003SC called its formal unavailable, UID0000G9 disclaimed a complete declaration, UID00029E treated an unbacked `.data` virtual tail as `ff ff ff ff`, and UID00035H/I/J claimed marker-producing reconstructable emitter roles. Current ordinary pages explicitly historicalize and correct all four dispositions.

Command 14831 is explicitly historical pre-callback evidence: one UID0003SR definition and six WorldMap-family Empty Emitter Markers. The earlier command-14817 drafting epoch is older historical evidence. Current waited command 14846 satisfies the accepted structure: the complete class closes before all qualified definitions, one UID0003SC constructor and one UID0004T9 global definition emit, UID0003SR remains once, all six stale markers are absent, and no raw vtable/RTTI/string/constant body emits.

The final by-memory manual snapshot differs from the accepted checkpoint because unrelated external supervisor work inserted thirteen lines before the WorldMap rows. UID0001O4/0003SC/000271/00035H/00035I/00035J/00029E retain exact pre-callback text at current lines 3716/3717/4024-4027/4229. This report uses current `C8202C...743E` and does not treat the unrelated drift as B003 work.

## Ranked Ownership Analysis

1. **UID0000G9 WorldMapPane / UID0000PB WorldMapPane.cpp: accepted.** Constructor vtables, RTTI, private fields, every literal use, helper calls, and sibling methods converge on the class and `NexusTK/map/WorldMapPane.cpp`.
2. **UID00007Q/UID0000L3 MapPane: rejected for target ownership.** MapPane parses the packet and creates/installs the pane, but the target owns copied state and all later world-map behavior. The call boundary is a source-file boundary.
3. **UID0000G8/UID0000GA custom helper classes: rejected as source owners.** Their machine bodies are standard-container specializations regenerated by old MSVC/Dinkumware.
4. **Resource manager/ImageLib/PaletteLib: rejected for target ownership.** They own lookup APIs and global managers, not class-local filename choices or constructor state.
5. **Broad UID0001O4 aggregate: retained only as non-emitting index.** Emitting R1 there would duplicate the exact child and destroy source granularity.
6. **UID000271 read-only-data parent: rejected as emitter.** It indexes compiler/data children; it does not own constructor source.

## Source Placement

R1 and R2 route through UID0000PB at `NexusTK/map/WorldMapPane.cpp` / `WorldMapPane.h`. R7 is the source-global definition in the same `.cpp`. UID0003TP remains in MapPane.cpp. Shared `.EPF`, `.PAL`, screen dimensions, asset-mode flag, resource libraries, user pane, timer/frame infrastructure, palette manager, and rendering APIs remain dependencies at their current owners. UID00035H/I/J remain binary evidence children attached semantically to the class but do not emit standalone C++.

## Range / Split / Padding / Reclassification Analysis

- Keep target range exactly `[0x005c2ac0,0x005c32aa)`, size `0x7ea` / 2,026. One modeled function covers the whole range.
- Keep target `Nested:+4`. It is the first child after parent UID0001O4 in the address-sorted relative nesting scheme; no child insertion occurs within this executable range, so the delta remains correct.
- Preserve predecessor ignored alignment `[0x005c2ab5,0x005c2ac0)` as parent-only `cc` bytes.
- Preserve successor target-adjacent alignment `[0x005c32aa,0x005c32b0)` as six parent-only `cc` bytes before UID0003SD.
- Do not absorb destructor start `0x005c32b0`, resource `.rdata`, singleton storage, packet caller, or generated helper bodies.
- Reclassify only UID00035H/I/J from reconstructable marker-producing pages to false/blank no-code compiler/data evidence.
- Keep UID000271 parent-only and UID0001O4 parent-only; no range split/merge.
- Create only semantic by-global UID0004T9; it does not change physical address ranges.

## Negative Evidence Summary

- No original PDB/source/debug symbols survive; private spelling remains inferential and caps confidence.
- No third constructor caller or function-pointer route exists.
- No packet/caller allocation is retained; ownership transfer and borrowed-array models are rejected.
- No empty-node, negative-index, upper-bound, graph-size, null-input, resource-failure, or palette-failure branch exists.
- No adjacency symmetrization, undirected graph transform, weighting, or second graph exists.
- No source helper factors the duplicated EPF/legacy setup.
- No custom `WorldMapNodeEntryVector`, `WorldMapReachabilityBitSet`, or `Deque` source class is warranted.
- No explicit source vptr store, singleton raw store, EH cleanup state, cookie check, scalar flag, adjustor thunk, or raw RTTI/vtable array belongs in human C++.
- No evidence supports moving R1 to MapPane.cpp, ImageLib.cpp, PaletteLib.cpp, or the broad aggregate.
- No evidence supports `0xffffffff` as the load-time singleton initializer; fresh memory and section mapping prove zero.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_5C2AC0` to `WorldMapPane__WorldMapPane` in an IDA-only future annotation pass; no IDA mutation is performed here.
- Apply the eight-input prototype described above and a `WorldMapPane *this` type.
- Type `+0x258` as `std::vector<WorldMapNode>`, `+0x264/+0x274` as old-MSVC `std::vector<bool>`, and `+0x284` as `std::vector<int>`.
- Type `0x0069b454` as `WorldMapPane *g_pWorldMapPane` with zero initialization.
- Preserve existing canonical child names. Where original lexical evidence is absent, keep descriptive names and comments rather than asserting symbol recovery.
- Add comments for branch resource sets, current-node mirrored initialization, unguarded trusted-input precondition, five tile contexts, natural padding, and standard-container helper exclusion.

## First-Draft C++ Recommendation

### R0 - UID0001O4 Aggregate, Intentionally Blank

The broad executable page remains a non-emitting index; all source definitions belong to exact children.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R1 - UID0003SC Constructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WorldMapPane::WorldMapPane(
    const wchar_t *mapName,
    short nodeCount,
    short currentNodeIndex,
    const MapPoint *nodePositions,
    const wchar_t *const *nodeNames,
    const unsigned short *destinationMapIds,
    const MapPoint *destinationPositions,
    const std::vector<bool> &adjacency)
    : Pane(0),
      FrameHandler(),
      Singleton<WorldMapPane>(),
      m_mapImage(),
      m_reachableNodeSymbol(),
      m_unreachableNodeSymbol(),
      m_boatBackImage(),
      m_boatFrontImage(),
      m_currentViewX(static_cast<float>(g_screenWidth) * 0.5f),
      m_currentViewY(static_cast<float>(g_screenHeight) * 0.5f),
      m_targetViewX(static_cast<float>(g_screenWidth) * 0.5f),
      m_targetViewY(static_cast<float>(g_screenHeight) * 0.5f),
      m_navigationActive(false),
      m_draggingView(false),
      m_playerColumn(0.0f),
      m_playerRow(0.0f),
      m_hoveredNodeIndex(currentNodeIndex),
      m_currentNodeIndex(currentNodeIndex),
      m_playerSpriteConfig(),
      m_playerAnimationFrame(0),
      m_mapName(),
      m_nodes(),
      m_adjacency(adjacency),
      m_reachableNodes(),
      m_predecessors(),
      m_playerOverSpecialRegion(false)
{
    if (g_useEpfAssets == 1) {
        g_pUserPane->GetSpriteConfig(&m_playerSpriteConfig);

        m_mapName = mapName;
        m_mapName.MakeExclusive();
        _wcsupr_s(const_cast<wchar_t *>(m_mapName.c_str()),
                   m_mapName.length() + 1);

        m_nodes.assign(nodeCount, WorldMapNode());
        for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex) {
            m_nodes[nodeIndex].position = nodePositions[nodeIndex];
            wcscpy_s(m_nodes[nodeIndex].name, 64, nodeNames[nodeIndex]);
            m_nodes[nodeIndex].destinationMapId = destinationMapIds[nodeIndex];
            m_nodes[nodeIndex].destinationPosition = destinationPositions[nodeIndex];
        }

        SimpleUString resourceName(m_mapName);
        resourceName += L".EPF";
        g_pEPFLib->LookupLayoutEntry(resourceName.c_str(), 0, &m_mapImage);
        m_mapImage.bounds.Offset(-m_mapImage.bounds.left,
                                 -m_mapImage.bounds.top);

        g_pEPFLib->LookupLayoutEntry(L"WMSYMBOL.EPF", 0,
                                     &m_reachableNodeSymbol);
        g_pEPFLib->LookupLayoutEntry(L"WMSYMBOL.EPF", 1,
                                     &m_unreachableNodeSymbol);
        m_reachableNodeSymbol.bounds.Offset(-6, -6);
        m_unreachableNodeSymbol.bounds.Offset(-6, -6);

        resourceName = m_mapName;
        resourceName += L".PAL";
        m_mapPalette = g_pPaletteLib->GetPaletteByName(resourceName.c_str());

        const WorldMapNode &currentNode = m_nodes[m_currentNodeIndex];
        m_playerColumn = static_cast<float>(currentNode.position.column);
        m_playerRow = static_cast<float>(currentNode.position.row);
        m_currentViewX = m_playerColumn;
        m_currentViewY = m_playerRow;
        m_targetViewX = m_playerColumn;
        m_targetViewY = m_playerRow;
        ClampViewPosition(&m_currentViewX, &m_currentViewY);
        InvalidateRect(0);
        BuildReachabilityData();
        ScheduleTimer(0, 150, 0, 0);

        g_pEPFLib->LookupLayoutEntry(L"BOAT.EPF", 0, &m_boatBackImage);
        m_boatPalette = g_pPaletteLib->GetPaletteByName(L"BOAT.PAL");
        g_pEPFLib->LookupLayoutEntry(L"BOAT.EPF", 1, &m_boatFrontImage);
    } else {
        g_pUserPane->GetSpriteConfig(&m_playerSpriteConfig);

        m_mapName = mapName;
        m_mapName.MakeExclusive();
        _wcsupr_s(const_cast<wchar_t *>(m_mapName.c_str()),
                   m_mapName.length() + 1);

        m_nodes.assign(nodeCount, WorldMapNode());
        for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex) {
            m_nodes[nodeIndex].position = nodePositions[nodeIndex];
            wcscpy_s(m_nodes[nodeIndex].name, 64, nodeNames[nodeIndex]);
            m_nodes[nodeIndex].destinationMapId = destinationMapIds[nodeIndex];
            m_nodes[nodeIndex].destinationPosition = destinationPositions[nodeIndex];
        }

        SimpleUString resourceName(m_mapName);
        resourceName += L".EPD";
        g_pEPFLib->LookupLayoutEntry(resourceName.c_str(), 0, &m_mapImage);
        m_mapImage.bounds.Offset(-m_mapImage.bounds.left,
                                 -m_mapImage.bounds.top);

        g_pEPFLib->LookupLayoutEntry(L"SYMBOLS.EPF", 36,
                                     &m_reachableNodeSymbol);
        g_pEPFLib->LookupLayoutEntry(L"SYMBOLS.EPF", 72,
                                     &m_unreachableNodeSymbol);
        m_reachableNodeSymbol.bounds.Offset(-6, -6);
        m_unreachableNodeSymbol.bounds.Offset(-6, -6);

        resourceName = m_mapName;
        resourceName += L".PAD";
        m_mapPalette = g_pPaletteLib->GetPaletteByName(resourceName.c_str());

        const WorldMapNode &currentNode = m_nodes[m_currentNodeIndex];
        m_playerColumn = static_cast<float>(currentNode.position.column);
        m_playerRow = static_cast<float>(currentNode.position.row);
        m_currentViewX = m_playerColumn;
        m_currentViewY = m_playerRow;
        m_targetViewX = m_playerColumn;
        m_targetViewY = m_playerRow;
        ClampViewPosition(&m_currentViewX, &m_currentViewY);
        InvalidateRect(0);
        BuildReachabilityData();
        ScheduleTimer(0, 150, 0, 0);

        g_pEPFLib->LookupLayoutEntry(L"BBOAT.EPD", 0, &m_boatBackImage);
        m_boatPalette = g_pPaletteLib->GetPaletteByName(L"BOAT.PAD");
        g_pEPFLib->LookupLayoutEntry(L"FBOAT.EPD", 0, &m_boatFrontImage);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R2 - UID0000G9 Complete Class Declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <vector>

struct WorldMapNode {
    MapPoint position;
    wchar_t name[64];
    unsigned short destinationMapId;
    MapPoint destinationPosition;
};

class WorldMapPane;
extern WorldMapPane *g_pWorldMapPane;

class WorldMapPane : public Pane,
                     public FrameHandler,
                     public Singleton<WorldMapPane> {
public:
    WorldMapPane(const wchar_t *mapName,
                 short nodeCount,
                 short currentNodeIndex,
                 const MapPoint *nodePositions,
                 const wchar_t *const *nodeNames,
                 const unsigned short *destinationMapIds,
                 const MapPoint *destinationPositions,
                 const std::vector<bool> &adjacency);
    virtual ~WorldMapPane();

private:
    void SetViewPosition(float viewX, float viewY);
    void StartViewAnimation(float viewX, float viewY);
    void StartTravelToNode(int nodeIndex);
    void SendTravelPacket(int nodeIndex);
    RectBounds *ApplyVisibleClipRect(RectBounds *outBounds);
    int HitTestNode(int mouseX, int mouseY);
    virtual void OnDraw();
    virtual bool HandleKeyEvent(Event *event);
    virtual bool HandleMouseEvent(Event *event);
    virtual bool OnFrameUpdate(int elapsedTime);
    virtual bool OnTimerTick(int timerId, int userData, int flags);
    void ClampViewPosition(float *viewX, float *viewY);
    void DrawPlayerMarker(int screenX, int screenY);
    void BuildReachabilityData();
    void UpdateHoverFromMouse();
    void UpdateHoverFromMouseStrict();
    int FindPredecessorNode();
    void ScreenPointHelper(int *screenX, int *screenY);
    bool HitTestSpecialRegions(int screenX, int screenY);

    EPFTileContext m_mapImage;
    EPFTileContext m_reachableNodeSymbol;
    EPFTileContext m_unreachableNodeSymbol;
    EPFTileContext m_boatBackImage;
    EPFTileContext m_boatFrontImage;
    DLPalette *m_boatPalette;
    DLPalette *m_mapPalette;
    float m_currentViewX;
    float m_currentViewY;
    float m_targetViewX;
    float m_targetViewY;
    bool m_navigationActive;
    bool m_draggingView;
    float m_playerColumn;
    float m_playerRow;
    int m_hoveredNodeIndex;
    short m_currentNodeIndex;
    LivingSpriteConfig m_playerSpriteConfig;
    int m_currentRouteNode;
    int m_finalTravelTarget;
    double m_travelHeading;
    int m_dragStartScreenX;
    int m_dragStartScreenY;
    int m_playerAnimationFrame;
    SimpleUString m_mapName;
    std::vector<WorldMapNode> m_nodes;
    std::vector<bool> m_adjacency;
    std::vector<bool> m_reachableNodes;
    std::vector<int> m_predecessors;
    bool m_playerOverSpecialRegion;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R3 - UID00035H Vtable/RTTI Data, Intentionally Blank

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R4 - UID00035I Resource Data, Intentionally Blank

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R5 - UID00035J Numeric Data, Intentionally Blank

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R6 - UID00029E Physical Storage Coverage

UID0004T9 was issued by the validator before this dependent destination was validated.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source definition is emitted by UID 0004T9 g_pWorldMapPane.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R7 - UID0004T9 Semantic Global Definition

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WorldMapPane;
WorldMapPane *g_pWorldMapPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation

The bounded implementation callback for C01-C20 and R0-R7 is complete. It registered UID0004T9 `by-global/g_pWorldMapPane.md` first and uses that issued UID in every dependent destination. The target and class are complete source emitters; the physical singleton is covered storage; the vtable/string/constant pages are explicit no-code evidence; aggregate and read-only parents remain non-emitting. Every sibling, helper, source route, historical correction, exact byte/range, and negative finding is preserved.

The implemented target score `92/94` reflects complete behavior, ABI, resources, layout, callers, boundaries, and source C++; it remains below 95 because private lexical spellings and some helper declaration names are inferred rather than recovered from symbols. This is a lexical cap, not a source-shape or behavior blocker.

## Recommended Target Doc Changes

Applied to UID0003SC:

- `COMPLETION:92`, `CONFIDENCE:94` are current.
- Preserve `CANONICAL_OWNER:0000G9`, `EMITTER_UIDS:0000PB`, `RECONSTRUCTABLE:TRUE`, blank optional position, exact path/range, and `Nested:4`.
- The former blank managed formal is replaced by R1 exactly.
- Use this exact managed Item Summary:

`*** Item Summary: Complete WorldMapPane eight-input constructor with Pane/FrameHandler/Singleton base setup, five EPFTileContext members, deep-copied 0x94-byte nodes and directed adjacency, exact EPF/PAL and EPD/PAD resource branches, current view/clamp/invalidate/reachability/timer initialization, and UID0000G9/UID0000PB ownership. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`

- Complete MCP/PE/range/hash/instruction/CFG/ABI/caller/callee/vtable/singleton/layout/node/container/string/resource/helper/padding/compiler-exclusion evidence from C01-C14 is current.
- The old incomplete-resource/private-helper blocker is historicalized as the reason the page had been `86/90`/blank.
- No-check behavior, branch duplication, uninitialized route/drag fields, and all rejected alternatives are preserved.

## Recommended Support Doc Changes

### UID0001O4 Aggregate

Applied `88/91` to `90/93`; owner UID0000PB, false, blank emitter/position/formal R0, range and child order remain exact. The complete constructor disposition, target score, exact six-byte child pad, zero-filled singleton correction, and compiler/data child reclassification are current without sibling loss.

Exact managed Item Summary:

`*** Item Summary: Non-emitting WorldMapPane executable split index over exact source methods, complete UID0003SC constructor/setup, generated compiler/STL helpers, zero-filled singleton and read-only-data links, all internal padding, and the closed DirectDrawCreate successor boundary. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`

### UID0000G9 Class

Applied `90/93` to `93/94`; owner/emitter UID0000PB, true and blank position remain exact. R2 is installed exactly with the class closing before `[[CHILDREN]]`; the `0x298` table, RTTI PMDs, EBO, direct-base order, node layout, fields, declarations, lifetime/resource/access/lexical/compiler evidence are current. Existing Layer-client, BFS, packet, shared-string, frame-handler, child, and history detail is preserved.

### UID0000PB File

Applied `91/92` to `92/93`; path `NexusTK/map/`, file-root ownership and existing family content remain exact. R1/R2/R7 inventory, singleton definition, resources, constructor ownership, no-code compiler/data dispositions, and generated proof are current. UID0003TP remains in MapPane.cpp and every shared/helper boundary is preserved.

### UID000271 Read-Only Parent

Retained `90/93`, false, blank emitter/formal and exact range. Child scores/dispositions and R1/R2 source causes are synchronized; RTTI start, splits, Browser successor, tables/strings/constants, and history are preserved.

### UID00035H Vtable/RTTI

Current state is `92/94`, owner UID0000G9, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal R3, `Nested:0`; exact range, COL/CHD/base descriptors, four views, slots/xrefs/lifecycle/source cause are preserved. R2 and child definitions regenerate the data; no raw array emits.

Exact managed Item Summary:

`*** Item Summary: Exact non-emitting WorldMapPane RTTI/COL/base-descriptor and four-vtable-view data child, regenerated from the complete UID0000G9 class and virtual method source with all slot, constructor/destructor store, and boundary evidence preserved. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`

### UID00035I Resource Strings

Current state is `91/94`, owner UID0000G9, false, blank emitter/position/formal R4, `Nested:0`; all literal starts/interior aliases/xrefs/range are preserved. R1 owns every source expression and the standalone page emits no duplicate.

Exact managed Item Summary:

`*** Item Summary: Exact non-emitting WorldMapPane UTF-16 resource-literal data child for WMSYMBOL.EPF, BOAT resources, EPF/EPD/PAL/PAD suffixes and legacy boat files; all constructor xrefs and interior aliases are preserved while UID0003SC source emits the literals naturally. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`

### UID00035J Numeric Constants

Current state is `91/94`, owner UID0000G9, false, blank emitter/position/formal R5, `Nested:0`; every value/xref/padding/sentinel/successor fact is preserved. Method expressions regenerate constants and raw arrays are excluded.

Exact managed Item Summary:

`*** Item Summary: Exact non-emitting WorldMapPane numeric-constant data child preserving all viewport/animation values, xrefs, zero and 0x7fffffff sentinel padding, and Browser successor evidence; method source regenerates the constants without a raw array emitter. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`

### UID00029E And UID0004T9

Validator command 14836 registered UID0004T9 `by-global/g_pWorldMapPane.md` first at `92/94`, canonical owner/emitter UID0000PB, reconstructable true, blank position, R7, source route through WorldMapPane.cpp, exact lifecycle/six-xref/zero-fill evidence and physical-storage link.

UID00029E is now `92/94`, owner/emitter UID0004T9, true, blank position, R6, `Nested:0`. Its Item Summary/storage table record loader-zero-filled `00 00 00 00`; historical `ff ff ff ff` is superseded unbacked-tail provenance, and all publish/clear/read xrefs, neighboring-data separation, destructor/thunk evidence, and exact range remain.

Exact physical-page managed Item Summary after UID replacement:

`*** Item Summary: Exact loader-zero-filled four-byte WorldMapPane singleton storage covered by semantic source-global UID 0004T9, with constructor publication/fallback clear, destructor/compiler-cleanup clears, two live reads, adjacent-global separation, and the superseded unbacked-tail ff ff ff ff database artifact preserved historically. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`

### Verify-Only Support

UID0003TP, UID0003SR, UID0003SP, UID0000G8, UID0000GA, UID0003SD-SW, UID0003SY/T2/T3/T6, Pane, FrameHandler, TimerHandler, Singleton, EPFTileContext, LivingSpriteConfig, SimpleUString/StringBase, MapPoint, Event, RectBounds, resource/palette/user globals, screen dimensions, asset mode, packet producer, shared suffix/literal pages, and ignored padding were reread and preserved. No current contradiction required a verify-only edit.

## Score And Metadata Recommendation

| Destination | Baseline | Implemented | Metadata disposition and rationale |
| --- | ---: | ---: | --- |
| UID0003SC | 86/90 | 92/94 | Complete source body, ABI, layout, callers, resources, compiler exclusions; lexical cap. |
| UID0001O4 | 88/91 | 90/93 | Complete child/index/source/compiler inventory; broad parent remains blank. |
| UID0000G9 | 90/93 | 93/94 | Complete class declaration and exact 0x298 layout; private spelling cap. |
| UID0000PB | 91/92 | 92/93 | Complete source/header/global inventory and route; unrelated sibling debt remains. |
| UID000271 | 90/93 | 90/93 | Already complete parent-only index; only child current-state sync. |
| UID00035H | 86/91 | 92/94 | Exact RTTI/vtable proof plus coherent compiler no-code cause. |
| UID00035I | 86/91 | 91/94 | Exact literals/xrefs/source expressions; no standalone emitter. |
| UID00035J | 86/91 | 91/94 | Exact values/xrefs/source cause; no standalone emitter. |
| UID00029E | 86/90 | 92/94 | Exact zero-fill and lifecycle; source definition factored to semantic global. |
| UID0004T9 | newly registered | 92/94 | Sole source definition, exact physical slot/lifecycle and file route. |

Owner/emitter and relative nesting are preserved unless explicitly listed. No optional position is introduced. No score reaches 95 because exact private names, access labels for every helper, and original header spelling are not debug-symbol recovered.

## Open Questions With Attempted Resolution

| Question | Investigation | Resolution / score effect |
| --- | --- | --- |
| Is this one constructor or a mixed aggregate? | Function lookup, bytes, decompile, CFG, successor padding/destructor. | One constructor, no split. Closed. |
| What are the eight parameters? | Both callers, packet parser, stack cleanup, loop widths, field stores. | Exact signature in R1. Closed. |
| Signed count/index or unsigned packet bytes? | Callee sign-test/sign-extension versus caller bytes. | Source ABI `short`; packet origin remains unsigned byte. Closed. |
| Custom node/bitset classes? | Helper bodies, object sizes, old-MSVC layouts, executed reports. | Standard `std::vector` types; custom names are facades. Closed. |
| Exact node record? | 0x94 stride, copy offsets, `wcscpy_s` count 64. | Exact R2 struct with natural +0x8a padding. Closed. |
| Resource mode bodies factor to a helper? | Full CFG and call graph. | No source helper; retain duplicated arms. Closed. |
| What initializes g_pWorldMapPane? | MCP bytes, PE raw/virtual section mapping, singleton patterns. | Zero-initialized source global; stale `ff` rejected. Closed. |
| Should vtable/strings/constants emit source? | Source causality and generated marker behavior. | No standalone source; false/blank R3-R5. Closed. |
| Are route/drag members constructor-initialized? | Exact stores before branch and class cross-method use. | No; omit five members from initializer list. Closed. |
| Exact private spellings/access? | Child titles, cross-method roles, project style, no symbols. | Best descriptive private names; lexical uncertainty caps confidence at 94, not code readiness. |
| Error handling or guards? | Both complete branches and cleanup edges. | None in source behavior; adding any would be incorrect. Closed. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 does not edit manual coverage. The following is the exact no-loss supervisor handoff based on current rows and current neighboring order.

### by-memory/-coverage-report.md

Current snapshot: SHA256 `C8202C988A6C0AD282B4C43B4D4EBB4F72449EB2F0739F91E2B6431C39DD743E`, 1,815,323 bytes / 4,327 lines. Unrelated external additions shifted the WorldMap anchors by thirteen lines after the accepted checkpoint without changing any replacement source row.

Replace current line 3716 UID0001O4 with:

`    - [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) 0x005c2ac0-0x005c5c87 | class aggregate | WorldMapPane : ignored : 90% : very strong : Non-emitting WorldMapPane executable split index over exact source-bearing methods and compiler/runtime children; UID0003SC now supplies the complete eight-input constructor, exact 0x298 class/state/resource setup, deep-copied 0x94-byte nodes and directed adjacency, duplicated EPF/PAL versus EPD/PAD branches, initial clamp/invalidate/BFS/timer order, and zero-filled g_pWorldMapPane source-global factorization, while old-MSVC standard-container, vtable/RTTI, cleanup/thunk, and raw data children remain non-emitting.`

Replace current line 3717 UID0003SC with:

`        - [UID:0003SC][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md) 0x005c2ac0-0x005c32aa | constructor | WorldMapPane::WorldMapPane : reconstructable : 92% : very strong : Complete source-ready eight-input WorldMapPane constructor with Pane/FrameHandler/Singleton base order, five EPFTileContext members, exact 0x298 layout contract, deep-copied 0x94-byte WorldMapNode records, copied directed std::vector<bool> adjacency, map-name detach/uppercase, exact EPF/PAL and EPD/PAD resource branches, current-node view/player initialization, clamp/invalidate/reachability/timer order, trusted-input no-check behavior, two callers, exact range/hash/padding, and compiler-lowering exclusions.`

Replace current line 4024 UID000271 with the same score but synchronized child text:

`    - [UID:000271][0x006313fc-0x00631570.WorldMapReadOnlyData](by-memory/0x006313fc-0x00631570.WorldMapReadOnlyData.md) 0x006313fc-0x00631570 | vtable/string-data/constants | WorldMapReadOnlyData : not_reconstructable : 90% : very strong : Parent-blank non-emitting index over exact WorldMapPane RTTI/vtable, resource-string, and numeric-constant children; complete class and method source now explains all emitted data, while exact child ranges, RTTI/PMDs, literal starts/interior aliases, constants, padding, and Browser successor remain preserved.`

Replace lines 4025-4027 with:

`        - [UID:00035H][0x006313fc-0x00631490.WorldMapPaneVtableData](by-memory/0x006313fc-0x00631490.WorldMapPaneVtableData.md) 0x006313fc-0x00631490 | compiler vtable/RTTI data | WorldMapPaneVtableData : not_reconstructable : 92% : very strong : Exact WorldMapPane COL/CHD/eight-base RTTI and four vtable views with constructor/destructor stores and slot links; regenerated from the complete UID0000G9 class/virtual method source, with no handwritten arrays or standalone emitter.`

`        - [UID:00035I][0x00631490-0x00631528.WorldMapPaneResourceStrings](by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md) 0x00631490-0x00631528 | source literal data | WorldMapPaneResourceStrings : not_reconstructable : 91% : very strong : Exact WMSYMBOL.EPF, BOAT.EPF/PAL, .EPD/.PAD, BBOAT.EPD, BOAT.PAD, and FBOAT.EPD UTF-16 storage with constructor-only xrefs and interior aliases; literals are emitted naturally by UID0003SC source, not by a duplicate data body.`

`        - [UID:00035J][0x00631528-0x00631570.WorldMapPaneNumericConstants](by-memory/0x00631528-0x00631570.WorldMapPaneNumericConstants.md) 0x00631528-0x00631570 | source numeric/constant data | WorldMapPaneNumericConstants : not_reconstructable : 91% : very strong : Exact 0.05, 0.0001, 3.2, 20.0, 240.0, 320.0, 384.0, 512.0 and 0x7fffffff constant band with WorldMapPane-only xrefs, retained zero/sentinel padding and Browser successor; regenerated from method expressions without a raw array emitter.`

Replace current line 4229 UID00029E using the issued UID0004T9:

`    - [UID:00029E][0x0069b454-0x0069b458.g_pWorldMapPane](by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md) 0x0069b454-0x0069b458 | global pointer storage | g_pWorldMapPaneStorage : reconstructable : 92% : very strong : Exact loader-zero-filled four-byte WorldMapPane singleton storage, covered by semantic source-global [UID:0004T9][g_pWorldMapPane](by-global/g_pWorldMapPane.md); six lifecycle xrefs preserve constructor publish/fallback clear, destructor/compiler-cleanup clears, two reads, adjacent-global separation, and the superseded unbacked-tail ff ff ff ff database artifact.`

### by-class/-coverage-report.md

Current snapshot: SHA256 `862E9BE235064C33459EC225C96742B03829D18ECB39A53FF599ACCB2657F75B`, 235,871 bytes / 623 lines. The external epoch changed unrelated class rows; WorldMap lines and their union are unchanged. Preserve UID0000G8 line 605 and UID0000GA line 607 exactly. Replace UID0000G9 line 606 with:

`- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md) : reconstructable : 93% : very strong : Complete 0x298 WorldMapPane source declaration with Pane/FrameHandler/Singleton base order and EBO, five EPFTileContext members, exact WorldMapNode/container/layout fields and natural padding, all lifecycle/view/travel/draw/input/frame/timer/reachability declarations, class close before children, exact eight-input constructor/resource setup, zero-filled singleton extern, packet ownership boundary, trusted-input behavior, compiler/no-code exclusions, and preserved Layer/BFS/shared support history.`

### by-file/-coverage-report.md

Current snapshot: SHA256 `6E32409881C7D5C8D11792F140B775AF022D3A3D01BE808FBD632CF58DFB367F`, 134,635 bytes / 316 lines. The external epoch changed unrelated file rows; UID0000PB remains unchanged at line 307. Replace it with:

`- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) : reconstructable : 92% : very strong : NexusTK/map/WorldMapPane.cpp source module with complete WorldMapPane declaration/constructor and sole zero-initialized g_pWorldMapPane definition, exact EPF/PAL versus EPD/PAD resources, copied nodes/directed adjacency, current view/clamp/invalidate/BFS/timer setup, all existing child routes and BuildReachabilityData, MapPane packet/factory boundary, standard-container/compiler/vtable-data no-code dispositions, and preserved shared resource/frame/render dependencies.`

### by-global/-coverage-report.md

Current snapshot: SHA256 `3F831C9FA2FB5CD22E1DD2796DFA0E73731B115FC03E33EC8D3744B886AB6238`, 90,147 bytes / 212 lines. Unrelated external edits changed the file hash but not the insertion neighborhood; UID0004T9 remains absent. Insert after current `g_pVoteMenuPane` line 158 and before `g_pWebBoardDialog` line 159 using issued UID0004T9:

`- [UID:0004T9][g_pWorldMapPane](by-global/g_pWorldMapPane.md) : reconstructable : 92% : very strong : Sole zero-initialized WorldMapPane pointer definition in NexusTK/map/WorldMapPane.cpp, tied to zero-filled physical storage UID00029E, exact constructor publication/fallback clear, destructor and compiler-cleanup clears, two live reads, Singleton<WorldMapPane> source cause, complete class extern, and no duplicate physical-storage definition.`

No by-struct manual report exists or is required: `WorldMapNode` is emitted inside the complete class formal and no separate by-struct page is proposed.

## Follow-Up Actions

- The implementation callback, UID issuance, scoped ordinary validation, waited generated refresh, and report reconciliation are complete. No B003 implementation item remains.
- Manual coverage application and report validation/execution/path/count/move/archive state are external supervisor/validator-owned state; this artifact neither asserts nor directs a future lifecycle transition.
- B003 itself performs no `execute_report`, lifecycle, report move/archive, coverage edit, or generated-file edit.
- Current report truth records UID0004T9, exact validators/hashes/generated proof, eight formal parity results, no provisional token, and zero leases with archive-neutral wording.

## Confidence

- Target completion recommendation: 92.
- Target confidence recommendation: 94.
- Source behavior/ABI/layout/resources: very strong.
- Ownership/file placement/compiler exclusions: very strong.
- Private source spelling/access: strong, explicitly inferred.
- Singleton source model: very strong after live zero bytes, PE section proof, six xrefs, and project pattern comparison.

## Validator Results

All commands ran from canonical `source-3/project-documentation` with `--apply --queue-timeout 240`. Commands 14837-14846 emitted `ok:1`; registration command 14836 emitted no `ok` field but exited 0 and issued UID0004T9. Every command exited 0.

| Command | Timestamp | Scoped destination / role | Exit / ok | Relevant side effects and warnings |
| --- | --- | --- | --- | --- |
| `14836` | `2026-07-20T01:33:49-04:00` | `by-global/g_pWorldMapPane.md` registration/validation | 0 / not emitted | Issued UID0004T9; inserted UID/path, scores, owner/emitter/formal registry and four reverse refs; deferred generated refresh; no warning. |
| `14837` | `2026-07-20T01:36:57-04:00` | UID0003SC target | 0 / 1 | Applied `92/94` and R1 registry hash; one pre-existing `missing_ref_uid 0003SP`; deferred refresh. |
| `14838` | `2026-07-20T01:37:58-04:00` | UID0001O4 aggregate | 0 / 1 | Applied `90/93`; pre-existing missing refs 0003SD/SE/SW/SY/T2/T6/T3; deferred refresh. |
| `14839` | `2026-07-20T01:39:36-04:00` | UID0000G9 class | 0 / 1 | Applied `93/94` and R2 registry hash; pre-existing missing refs 0003SW/T3/SY/T2/T6/SK/SN (T3 reported twice); deferred refresh. |
| `14840` | `2026-07-20T01:40:34-04:00` | UID0000PB file | 0 / 1 | Applied `92/93`; pre-existing missing refs 0003SW/T3/SY/T2/T6/JG/JI/SK; deferred refresh. |
| `14841` | `2026-07-20T01:41:36-04:00` | UID000271 read-only parent | 0 / 1 | Added UID0003SC reverse ref; no warning; deferred refresh. |
| `14842` | `2026-07-20T01:42:27-04:00` | UID00035H vtable data | 0 / 1 | Applied `92/94`, true-to-false, emitter-to-blank; no warning; deferred refresh. |
| `14843` | `2026-07-20T01:43:16-04:00` | UID00035I resource strings | 0 / 1 | Applied `91/94`, true-to-false, emitter-to-blank; no warning; deferred refresh. |
| `14844` | `2026-07-20T01:44:09-04:00` | UID00035J numeric constants | 0 / 1 | Applied `91/94`, true-to-false, emitter-to-blank; no warning; deferred refresh. |
| `14845` | `2026-07-20T01:45:12-04:00` | UID00029E physical storage | 0 / 1 | Applied `92/94`, owner/emitter UID0004T9 and R6 hash; pre-existing 0003SY missing ref reported four times; deferred refresh. |
| `14846` | `2026-07-20T01:45:47-04:00` | final waited UID0000PB validation | 0 / 1 | Registry rebuild and generated metadata refresh completed; same eight pre-existing by-file missing refs plus unrelated project-wide marker/fallback/no-code diagnostics; generated refresh completed at command/header 14846. |

Formal parity after validation is exact: R0/R3/R4/R5 are empty-body SHA256 `e3b0c442...b855`; R1 is `ba581b6c...c7bf` (134 lines), R2 `45e49899...19b3` (80), R6 `8bdd97d0...5924` (1), and R7 `fced1d1d...1bc4` (2). Each destination body is byte-for-byte equal to its report block.

Generated `auto-generated/NexusTK/map/WorldMapPane.cpp` header is command 14846 / `2026-07-20T01:45:47-04:00`, SHA256 `55085607B076C68BCC224F877176D360C7FF5EC40E5FAC8B35F22B9A862743D2`, 10,091 bytes / 266 lines. The class closes at line 85; global/constructor/BFS definitions begin at lines 91/94/233. Counts are one UID0004T9/global, one UID0003SC/constructor, one UID0003SR/BFS, two total/two unique qualified `WorldMapPane` definitions, zero Empty Emitter Markers, zero duplicate/wrong-range body, zero handwritten vtable/RTTI/string/constant arrays, and zero EH/cookie/scalar/adjustor/Dinkumware bodies.

## Changed Files

- `by-global/g_pWorldMapPane.md`: new UID0004T9, SHA256 `D3EA696909BADB7CAD78C4322D5C9893D4B27FAF66732B0750C4B4992C24F420`, 5,016 bytes / 73 lines.
- `by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md`: SHA256 `1736642696CA1451EFD3B6BCEF9D5E62320EA320AF06EE6B272E13D395BEABBA`, 17,933 / 226.
- `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md`: SHA256 `A0F962236C1ED3EBF85942DB58C4F5CB7464D3C31C21A1C381D82CB0FE2A5CEC`, 26,164 / 217.
- `by-class/WorldMapPane.md`: SHA256 `C6C9666A02C70CCE666773CD8820D84F0DCF2151FAE72E1DEEA5E701577CDB95`, 26,738 / 277.
- `by-file/WorldMapPane.md`: SHA256 `30684C5311DE628267EC3F96EA312EFD9255AE5AA0DEECE9E13AB27AF9EC6FFD`, 22,087 / 165.
- `by-memory/0x006313fc-0x00631570.WorldMapReadOnlyData.md`: SHA256 `7E9498372D6BD89B67C562C29EBDF1C8D3035B7BCDE3D74AD950267FCC97F0DD`, 13,879 / 129.
- `by-memory/0x006313fc-0x00631490.WorldMapPaneVtableData.md`: SHA256 `A69BCDFBE704A3B0DA29E2B6AB4B6D162E56B88A15EEC680829E45413B08BD91`, 7,223 / 75.
- `by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md`: SHA256 `12B81AB110EEB8B6BC065777E3CE4A35926596806D6466346DF54A5C40965E2E`, 6,733 / 72.
- `by-memory/0x00631528-0x00631570.WorldMapPaneNumericConstants.md`: SHA256 `ECCDCC5692EDFA56F46EF7EFF64BF66140EC8BBB34A9D94AFB49BCA8397025C9`, 6,691 / 72.
- `by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md`: SHA256 `AE48882BF47A42D9204480529F3F7862EFAA6458E1B26730CBC2E5A8720ED133`, 8,545 / 88.
- This report was reconciled in place. Validator-generated outputs/reports and tool-owned metadata changed only as validator side effects; B003 did not edit them manually.
- Manual coverage/tracker/audit/supervisor/goal/lifecycle/archive/IDA files changed by B003: zero. The exact supervisor-owned coverage handoff remains in this artifact because current rows are still the accepted stale pre-callback rows.
- Lease operations: ten acquired/ten released across nine existing ordinary pages plus the final waited file batch; the new file followed the documented create-then-register workflow. No B003 lease remains.

## Implementation Tracking Checklist

### Report-Only Research

- [x] Supervisor Gate 1 confirmed exact provenance headers and target UID/path for accepted SHA `28D857...7BF49`.
- [x] Supervisor Gate 1 confirmed the report stands alone with all required literal headings.
- [x] Supervisor Gate 1 accepted session-at-evidence-time health and bounded target evidence.
- [x] Supervisor Gate 1 accepted exact PE identity, target hash, size, bytes, 568 instructions and boundaries.
- [x] Supervisor Gate 1 accepted both callers, all eight arguments, signedness, lifetime, and ownership.
- [x] Supervisor Gate 1 accepted complete `0x298` class and `0x94` node layout tables.
- [x] Supervisor Gate 1 accepted both complete resource branches and exact order/no-check behavior.
- [x] Supervisor Gate 1 accepted RTTI/EBO/base/source/compiler analysis and rejected alternatives.
- [x] Supervisor Gate 1 accepted score improvements and no-code child dispositions.
- [x] C01-C20 remain atomic/contiguous and now use legal terminal callback states with destination proof.
- [x] R0-R7 remain destination-specific managed blocks; all eight destination bodies have exact parity and no C++ exists outside them.
- [x] Exact manual no-loss rows/anchors/current hashes were reread and remain valid for external supervisor application.
- [x] The accepted Gate 1 artifact had all callback boxes unchecked; this callback checks each only after proof.
- [x] The report now has exactly one terminal readiness marker and zero prohibited actions/leases.

### Implementation Callback

- [x] Registered `by-global/g_pWorldMapPane.md` through validator command 14836; real UID is 0004T9.
- [x] Replaced every provisional global token with UID0004T9 before dependent validation; final search finds none.
- [x] Leased/reread/rebased UID0003SC, applied `92/94`, metadata/summary/evidence/history/R1, validated 14837, released.
- [x] Leased/reread/rebased UID0001O4, applied `90/93`, parent-only constructor/index/padding/compiler detail/R0, validated 14838, released.
- [x] Leased/reread/rebased UID0000G9, applied `93/94`, exact R2/layout/method/access/history union, validated 14839, released.
- [x] Leased/reread/rebased UID0000PB, applied `92/93`, source/global/compiler no-loss union, validated 14840, released.
- [x] Leased/reread/rebased UID000271, synchronized child dispositions without metadata/range/formal loss, validated 14841, released.
- [x] Leased/reread/rebased UID00035H, applied `92/94`, false/blank R3 and RTTI/vtable proof, validated 14842, released.
- [x] Leased/reread/rebased UID00035I, applied `91/94`, false/blank R4 and literal/source proof, validated 14843, released.
- [x] Leased/reread/rebased UID00035J, applied `91/94`, false/blank R5 and constant/source proof, validated 14844, released.
- [x] Leased/reread/rebased UID00029E, applied `92/94`, owner/emitter 0004T9, zero-fill/R6/history, validated 14845, released.
- [x] Populated UID0004T9 at `92/94` with owner/emitter 0000PB, exact evidence and R7; registration validation 14836 succeeded.
- [x] Verified UID0003TP, UID0003SR, UID0003SP, UID0000G8, UID0000GA and named sibling/API/global/type dependencies unchanged at same-or-greater detail.
- [x] Scoped-validated every changed/new ordinary destination; commands 14836-14845 and exact results/side effects are recorded.
- [x] Ran final waited UID0000PB validation 14846; generated header/hash/metrics are current.
- [x] Generated class closes at line 85 before all definitions; R2 appears once.
- [x] Generated output has one UID0003SC constructor, one UID0003SR BFS, one UID0004T9 R7 global, and no duplicate/wrong-range target.
- [x] Generated output has zero UID0000G9/35H/35I/35J/3SC/29E or other Empty Emitter Markers.
- [x] Generated output has no handwritten vtable/RTTI/string/constant array, EH/cookie, adjustor/scalar, or Dinkumware helper body.
- [x] Every C01-C20 row has one legal terminal action/state and claim-specific destination proof.
- [x] Current Target State, recommendations, Validator Results, Changed Files and checklist are reconciled to callback truth.
- [x] Exact supervisor-owned manual handoff is preserved; B003 did not edit coverage.
- [x] Current ordinary/formal hashes, generated counts, issued UID0004T9, and zero provisional tokens are confirmed.
- [x] All B003 leases are released; no prohibited/lifecycle action occurred.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000014852","destination_path":"executed-b-agent-research/B003/0003SC-WorldMapPaneConstructorAndNodeSetup-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003SC-WorldMapPaneConstructorAndNodeSetup-source-quality.md","timestamp":"2026-07-20T02:12:07-04:00","uid":"0003SC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
