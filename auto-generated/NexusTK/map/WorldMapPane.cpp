// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000PB
// Source by-file doc: by-file/WorldMapPane.md
// UID:0000G9 | by-class/WorldMapPane.md | Completion:93 | Confidence:94
#include "../ui/core/FrameMgr.h"
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
    virtual void OnFrameUpdate(const FrameUpdateContext *context);
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

[[No Children Attached]]

// UID:0004T9 | by-global/g_pWorldMapPane.md | Completion:92 | Confidence:94
class WorldMapPane;
WorldMapPane *g_pWorldMapPane = 0;

// UID:0003SC | by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md | Completion:92 | Confidence:94
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















// UID:0003SR | by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md | Completion:92 | Confidence:94
#include <deque>
#include <vector>

void WorldMapPane::BuildReachabilityData()
{
    const int nodeCount = static_cast<int>(m_nodes.size());

    m_reachableNodes.assign(nodeCount, false);
    m_predecessors.assign(nodeCount, -1);

    std::vector<bool> visitedNodes(nodeCount, false);
    std::deque<int> pendingNodes;

    pendingNodes.push_back(m_currentNodeIndex);
    visitedNodes[m_currentNodeIndex] = true;
    m_reachableNodes[m_currentNodeIndex] = true;

    while (!pendingNodes.empty())
    {
        const int currentNode = pendingNodes.front();

        for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex)
        {
            if (!visitedNodes[nodeIndex] &&
                m_adjacency[currentNode * nodeCount + nodeIndex] &&
                currentNode != nodeIndex)
            {
                visitedNodes[nodeIndex] = true;
                m_reachableNodes[nodeIndex] = true;
                m_predecessors[nodeIndex] = currentNode;
                pendingNodes.push_back(nodeIndex);
            }
        }

        pendingNodes.pop_front();
    }
}

// UID:0003SS | by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md | Completion:93 | Confidence:94
void WorldMapPane::UpdateHoverFromMouse()
{
    Point cursorPosition;
    g_pEventMan->GetCursorPosition(&cursorPosition);

    const int nodeIndex =
        HitTestNode(cursorPosition.x, cursorPosition.y);

    if ((nodeIndex == -1 || m_reachableNodes[nodeIndex]) &&
        m_hoveredNodeIndex != nodeIndex)
    {
        m_hoveredNodeIndex = nodeIndex;
        InvalidateRect(0);
    }
}






// UID:0003P9 | by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md | Completion:87 | Confidence:92
// The shared .EPF suffix literal is emitted inline at each proven source use.

// UID:0003SD | by-memory\0x005c32b0-0x005c341e.WorldMapPaneNonDeletingDestructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003SE | by-memory\0x005c3420-0x005c346d.WorldMapPaneSetViewPosition.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003SF | by-memory\0x005c34c0-0x005c3508.WorldMapPaneStartViewAnimation.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003SG | by-memory\0x005c3540-0x005c3627.WorldMapPaneStartTravelToNode.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003SH | by-memory\0x005c3630-0x005c36c8.WorldMapPaneSendTravelPacket.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003SI | by-memory\0x005c36d0-0x005c37d6.WorldMapPaneApplyVisibleClipRect.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0003SJ | by-memory\0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003SK | by-memory\0x005c3950-0x005c3e41.WorldMapPaneOnDraw.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003SL | by-memory\0x005c3e50-0x005c402b.WorldMapPaneHandleKeyEvent.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003SM | by-memory\0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003SN | by-memory\0x005c4250-0x005c46e9.WorldMapPaneOnFrameUpdate.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003SO | by-memory\0x005c46f0-0x005c4733.WorldMapPaneOnTimerTick.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003SP | by-memory\0x005c4740-0x005c484b.WorldMapPaneClampViewPosition.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003SQ | by-memory\0x005c48b0-0x005c4bd0.WorldMapPaneDrawPlayerMarker.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003ST | by-memory\0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003SU | by-memory\0x005c5160-0x005c519c.WorldMapPaneFindPredecessorNode.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003SV | by-memory\0x005c51a0-0x005c51fb.WorldMapPaneScreenPointHelper.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003SW | by-memory\0x005c5200-0x005c53d0.WorldMapPaneHitTestSpecialRegions.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003T3 | by-memory\0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0003JG | by-memory\0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md | Completion:87 | Confidence:93 | Empty Emitter Marker

// UID:0003JI | by-memory\0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md | Completion:87 | Confidence:93 | Empty Emitter Marker
