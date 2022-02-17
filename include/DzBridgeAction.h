#pragma once
#include <dzaction.h>
#include <dznode.h>
#include <DzFileIOSettings.h>
#include <dzjsonwriter.h>
#include <dzimageproperty.h>
#include <dzweightmap.h>

#include "QtCore/qfile.h"
#include "QtCore/qtextstream.h"

#include "DzBridgeMorphSelectionDialog.h"

#undef DLLExport
#define DLLExport Q_DECL_IMPORT
#ifdef DZ_BRIDGE_SHARED
#undef DLLExport
#define DLLExport Q_DECL_EXPORT
#elif DZ_BRIDGE_STATIC
#undef DLLExport
#define DLLExport
#endif

class DzProgress;
class DzGeometry;

class DzBridgeSubdivisionDialog;
class DzBridgeMorphSelectionDialog;
class DzBridgeDialog;

// Struct to remember attachment info
struct AttachmentInfo
{
	DzNode* Parent;
	DzNode* Child;
};

class DLLExport DzBridgeAction : public DzAction {
	Q_OBJECT
	Q_PROPERTY(int nNonInteractiveMode READ getNonInteractiveMode WRITE setNonInteractiveMode)
	Q_PROPERTY(QString sAssetType READ getAssetType WRITE setAssetType)
	Q_PROPERTY(QString sExportFilename READ getExportFilename WRITE setExportFilename)
	Q_PROPERTY(QString sExportFolder READ getExportFolder WRITE setExportFolder)
	Q_PROPERTY(QString sRootFolder READ getRootFolder WRITE setRootFolder)
	Q_PROPERTY(QString sProductName READ getProductName WRITE setProductName)
	Q_PROPERTY(QString sProductComponentName READ getProductComponentName WRITE setProductComponentName)
	Q_PROPERTY(QStringList aMorphList READ getMorphList WRITE setMorphList)
	Q_PROPERTY(bool bUseRelativePaths READ getUseRelativePaths WRITE setUseRelativePaths)
	Q_PROPERTY(bool bUndoNormalMaps READ getUndoNormalMaps WRITE setUndoNormalMaps)
	Q_PROPERTY(QString sExportFbx READ getExportFbx WRITE setExportFbx)
	Q_PROPERTY(DzBasicDialog* wBridgeDialog READ getBridgeDialog WRITE setBridgeDialog)
	Q_PROPERTY(DzBasicDialog* wSubdivisionDialog READ getSubdivisionDialog WRITE setSubdivisionDialog)
	Q_PROPERTY(DzBasicDialog* wMorphSelectionDialog READ getMorphSelectionDialog WRITE setMorphSelectionDialog)
public:

	DzBridgeAction(const QString& text = QString::null, const QString& desc = QString::null);
	virtual ~DzBridgeAction();

	Q_INVOKABLE void resetToDefaults();
	Q_INVOKABLE QString cleanString(QString argString) { return argString.remove(QRegExp("[^A-Za-z0-9_]")); };
	Q_INVOKABLE QStringList getAvailableMorphs(DzNode* Node);
	Q_INVOKABLE QStringList getActiveMorphs(DzNode* Node);

public slots:
	// Normal Map Handling
	QImage makeNormalMapFromHeightMap(QString heightMapFilename, double normalStrength);
	// Pre-Process Scene data to workaround FbxExporter issues, called by Export() before FbxExport operation.
	bool preProcessScene(DzNode* parentNode = nullptr);
	// Undo changes made by preProcessScene(), called by Export() after FbxExport operation.
	bool undoPreProcessScene();
	bool renameDuplicateMaterial(DzMaterial* material, QList<QString>* existingMaterialNameList);
	bool undoRenameDuplicateMaterials();
	bool generateMissingNormalMap(DzMaterial* material);
	bool undoGenerateMissingNormalMaps();

protected:
	DzBridgeDialog* m_bridgeDialog;
	DzBridgeSubdivisionDialog* m_subdivisionDialog;
	DzBridgeMorphSelectionDialog* m_morphSelectionDialog;

	int NonInteractiveMode;
	QString CharacterName; // Exported filename without extension
	QString RootFolder; // The destination Root Folder
	QString DestinationPath; // Path to destination files: <RootFolder> + "/" + <CharacterName (folder)> + "/"
	QString CharacterFBX;
	//	 QString CharacterBaseFBX;
	//	 QString CharacterHDFBX;
	QString AssetType;
	QString MorphString;
	QString FBXVersion;
	QMap<QString, QString> MorphMapping;
	QList<QString> PoseList;
	QMap<DzImageProperty*, double> m_imgPropertyTable_NormalMapStrength;

	// Used only by script system
	QString ExportFolder; // over-rides bridge use of <CharacterName> for the destination folder
	QString ProductName; // Daz Store Product Name, can contain spaces and special characters
	QString ProductComponentName; // Friendly name of Component of Daz Store Product, can contain spaces and special characters
	QStringList ScriptOnly_MorphList; // overrides Morph Selection Dialog
	bool UseRelativePaths;
	bool m_bGenerateNormalMaps;
	bool m_bUndoNormalMaps;
	QString m_sExportFbx;

	bool ExportMorphs;
	bool ExportSubdivisions;
	bool ExportBaseMesh;
	bool ShowFbxDialog;
	bool ExportMaterialPropertiesCSV;
	DzNode* Selection;

	virtual QString getActionGroup() const { return tr("Bridges"); }
	virtual QString getDefaultMenuPath() const { return tr("&File/Send To"); }

	virtual void Export();
	virtual void ExportNode(DzNode* Node);

	virtual void WriteConfiguration() = 0;
	virtual void SetExportOptions(DzFileIOSettings& ExportOptions) = 0;
	virtual QString readGUIRootFolder() = 0;

	Q_INVOKABLE virtual void writeDTUHeader(DzJsonWriter& writer);

	Q_INVOKABLE virtual void writeAllMaterials(DzNode* Node, DzJsonWriter& Writer, QTextStream* CVSStream = nullptr, bool bRecursive = false);
	Q_INVOKABLE virtual void startMaterialBlock(DzNode* Node, DzJsonWriter& Writer, QTextStream* pCVSStream, DzMaterial* Material);
	Q_INVOKABLE virtual void finishMaterialBlock(DzJsonWriter& Writer);
	Q_INVOKABLE virtual void writeMaterialProperty(DzNode* Node, DzJsonWriter& Writer, QTextStream* pCVSStream, DzMaterial* Material, DzProperty* Property);

	Q_INVOKABLE virtual void writeAllMorphs(DzJsonWriter& Writer);
	Q_INVOKABLE virtual void writeMorphProperties(DzJsonWriter& writer, const QString& key, const QString& value);
	Q_INVOKABLE virtual void writeMorphJointLinkInfo(DzJsonWriter& writer, const JointLinkInfo& linkInfo);

	Q_INVOKABLE virtual void writeAllSubdivisions(DzJsonWriter& Writer);
	Q_INVOKABLE virtual void writeSubdivisionProperties(DzJsonWriter& writer, const QString& Name, int targetValue);

	Q_INVOKABLE virtual void writeAllDForceInfo(DzNode* Node, DzJsonWriter& Writer, QTextStream* pCVSStream = nullptr, bool bRecursive = false);
	Q_INVOKABLE virtual void writeDforceMaterialProperties(DzJsonWriter& Writer, DzMaterial* Material, DzShape* Shape);
	Q_INVOKABLE virtual void writeDforceModifiers(const QList<DzModifier*>& dforceModifierList, DzJsonWriter& Writer, DzShape* Shape);

	Q_INVOKABLE virtual void writeEnvironment(DzJsonWriter& writer);
	Q_INVOKABLE virtual void writeInstances(DzNode* Node, DzJsonWriter& Writer, QMap<QString, DzMatrix3>& WritenInstances, QList<DzGeometry*>& ExportedGeometry, QUuid ParentID = QUuid());
	Q_INVOKABLE virtual QUuid writeInstance(DzNode* Node, DzJsonWriter& Writer, QUuid ParentID);

	Q_INVOKABLE virtual void writeAllPoses(DzJsonWriter& writer);

	// Need to temporarily rename surfaces if there is a name collision
	void RenameDuplicateMaterials(DzNode* Node, QList<QString>& MaterialNames, QMap<DzMaterial*, QString>& OriginalMaterialNames);
	void UndoRenameDuplicateMaterials(DzNode* Node, QList<QString>& MaterialNames, QMap<DzMaterial*, QString>& OriginalMaterialNames);

	// Used to find all the unique props in a scene for Environment export
	void GetScenePropList(DzNode* Node, QMap<QString, DzNode*>& Types);

	// During Environment export props need to get disconnected as they are exported.
	void DisconnectNode(DzNode* Node, QList<AttachmentInfo>& AttachmentList);
	void ReconnectNodes(QList<AttachmentInfo>& AttachmentList);

	// During Skeletal Mesh Export Disconnect Override Controllers
	QList<QString> DisconnectOverrideControllers();
	void ReconnectOverrideControllers(QList<QString>& DisconnetedControllers);
	QList<QString> ControllersToDisconnect;

	// For Pose exports check if writing to the timeline will alter existing keys
	bool CheckIfPoseExportIsDestructive();

	// Need to be able to move asset instances to origin during environment export
	void UnlockTranform(DzNode* NodeToUnlock);

	// Getter/Setter methods
	Q_INVOKABLE DzBridgeDialog* getBridgeDialog() { return m_bridgeDialog; }
	Q_INVOKABLE bool setBridgeDialog(DzBasicDialog* arg_dlg);
	Q_INVOKABLE DzBridgeSubdivisionDialog* getSubdivisionDialog() { return m_subdivisionDialog; }
	Q_INVOKABLE bool setSubdivisionDialog(DzBasicDialog* arg_dlg);
	Q_INVOKABLE DzBridgeMorphSelectionDialog* getMorphSelectionDialog() { return m_morphSelectionDialog; }
	Q_INVOKABLE bool setMorphSelectionDialog(DzBasicDialog* arg_dlg);

	Q_INVOKABLE QString getAssetType() { return this->AssetType; };
	Q_INVOKABLE void setAssetType(QString arg_AssetType) { this->AssetType = arg_AssetType; };
	Q_INVOKABLE QString getExportFilename() { return this->CharacterName; };
	Q_INVOKABLE void setExportFilename(QString arg_Filename) { this->CharacterName = arg_Filename; };

	Q_INVOKABLE QString getExportFolder() { return this->ExportFolder; };
	Q_INVOKABLE void setExportFolder(QString arg_Folder) { this->ExportFolder = arg_Folder; };
	Q_INVOKABLE QString getRootFolder() { return this->RootFolder; };
	Q_INVOKABLE void setRootFolder(QString arg_Root) { this->RootFolder = arg_Root; };

	Q_INVOKABLE QString getProductName() { return this->ProductName; };
	Q_INVOKABLE void setProductName(QString arg_ProductName) { this->ProductName = arg_ProductName; };
	Q_INVOKABLE QString getProductComponentName() { return this->ProductComponentName; };
	Q_INVOKABLE void setProductComponentName(QString arg_ProductComponentName) { this->ProductComponentName = arg_ProductComponentName; };

	Q_INVOKABLE QStringList getMorphList() { return ScriptOnly_MorphList; };
	Q_INVOKABLE void setMorphList(QStringList arg_MorphList) { this->ScriptOnly_MorphList = arg_MorphList; };

	Q_INVOKABLE bool getUseRelativePaths() { return this->UseRelativePaths; };
	Q_INVOKABLE void setUseRelativePaths(bool arg_UseRelativePaths) { this->UseRelativePaths = arg_UseRelativePaths; };

	bool isTemporaryFile(QString sFilename);
	QString exportAssetWithDTU(QString sFilename, QString sAssetMaterialName = "");
	void writeJSON_Property_Texture(DzJsonWriter& Writer, QString sName, QString sValue, QString sType, QString sTexture);
	void writeJSON_Property_Texture(DzJsonWriter& Writer, QString sName, double dValue, QString sType, QString sTexture);
	QString makeUniqueFilename(QString sFilename);

	Q_INVOKABLE bool getUndoNormalMaps() { return this->m_bUndoNormalMaps; };
	Q_INVOKABLE void setUndoNormalMaps(bool arg_UndoNormalMaps) { this->m_bUndoNormalMaps = arg_UndoNormalMaps; };

	Q_INVOKABLE int getNonInteractiveMode() { return this->NonInteractiveMode; };
	Q_INVOKABLE void setNonInteractiveMode(int arg_Mode) { this->NonInteractiveMode = arg_Mode; };

	Q_INVOKABLE QString getExportFbx() { return this->m_sExportFbx; };
	Q_INVOKABLE void setExportFbx(QString arg_FbxName) { this->m_sExportFbx = arg_FbxName; };

	Q_INVOKABLE void readGUI(DzBridgeDialog*);
	Q_INVOKABLE void exportHD(DzProgress* exportProgress = nullptr);
	Q_INVOKABLE bool upgradeToHD(QString baseFilePath, QString hdFilePath, QString outFilePath, std::map<std::string, int>* pLookupTable);
	Q_INVOKABLE void WriteWeightMaps(DzNode* Node, DzJsonWriter& Stream);

	Q_INVOKABLE bool metaInvokeMethod(QObject* object, const char* methodSig, void** returnPtr);
	Q_INVOKABLE bool CopyFile(QFile* file, QString* dst, bool replace = true, bool compareFiles = true);
	Q_INVOKABLE QString GetMD5(const QString& path);

private:
	class MaterialGroupExportOrderMetaData
	{
	public:
		int materialIndex;
		int vertex_offset;
		int vertex_count;

		MaterialGroupExportOrderMetaData(int a_index, int a_offset)
		{
			materialIndex = a_index;
			vertex_offset = a_offset;
			vertex_count = -1;
		}

		bool operator< (MaterialGroupExportOrderMetaData b) const
		{
			if (vertex_offset < b.vertex_offset)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

	};

	// Undo data structures
	QMap<DzMaterial*, QString> m_undoTable_DuplicateMaterialRename;
	QMap<DzMaterial*, DzProperty*> m_undoTable_GenerateMissingNormalMap;

	// NormalMap utility methods
	double getPixelIntensity(const  QRgb& pixel);
	uint8_t getNormalMapComponent(double pX);
	int getIntClamp(int x, int low, int high);
	QRgb getSafePixel(const QImage& img, int x, int y);
	bool isNormalMapMissing(DzMaterial* material);
	bool isHeightMapPresent(DzMaterial* material);
	QString getHeightMapFilename(DzMaterial* material);
	double getHeightMapStrength(DzMaterial* material);

	DzWeightMapPtr getWeightMapPtr(DzNode* Node);

};
